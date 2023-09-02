#include <stdio.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <unordered_set>

#include "stable-diffusion.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include "stb_image_write.h"

#if defined(__APPLE__) && defined(__MACH__)
#include <sys/sysctl.h>
#include <sys/types.h>
#endif

#if !defined(_WIN32)
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#define TXT2IMG "txt2img"
#define IMG2IMG "img2img"

struct Option {
    int n_threads = -1;
    std::string mode = TXT2IMG;
    std::string model_path;
    std::string output_path = "output.png";
    std::string init_img;
    std::string prompt;
    std::string negative_prompt;
    float cfg_scale = 7.0f;
    int w = 512;
    int h = 512;
    SampleMethod sample_method = EULAR_A;
    int sample_steps = 20;
    float strength = 0.75f;
    int seed = 42;
    bool verbose = false;

    void print() {
        printf("Option: \n");
        printf("    n_threads:       %d\n", n_threads);
        printf("    mode:            %s\n", mode.c_str());
        printf("    output_path:     %s\n", output_path.c_str());
        printf("    cfg_scale:       %.2f\n", cfg_scale);
        printf("    width:           %d\n", w);
        printf("    height:          %d\n", h);
        printf("    sample_method:   %s\n", "eular a");
        printf("    sample_steps:    %d\n", sample_steps);
        printf("    strength:        %.2f\n", strength);
        printf("    seed:            %d\n", seed);
    }
};



Option opt;
bool vae_decode_only = true;
std::string model_path = "";


void set_model_path(char* path){
    model_path = path;
}

// char* model_path = "/Users/pawandeepsingh/Documents/Development/sd/stable-diffusion.cpp/models/realistic.bin";
    
int generate_image(char* positive, char* negative) {
    
    StableDiffusion sd(opt.n_threads, vae_decode_only, true);

    if (!sd.load_from_file(model_path)) {
        return false;
    }

    opt.print();

    std::vector<uint8_t> init_img;

    if (opt.mode == IMG2IMG) {
        vae_decode_only = false;

        int c = 0;
        unsigned char* img_data = stbi_load(opt.init_img.c_str(), &opt.w, &opt.h, &c, 3);
        if (img_data == NULL) {
            fprintf(stderr, "load image from '%s' failed\n", opt.init_img.c_str());
            return 1;
        }
        if (c != 3) {
            fprintf(stderr, "input image must be a 3 channels RGB image, but got %d channels\n", c);
            free(img_data);
            return 1;
        }
        if (opt.w <= 0 || opt.w % 32 != 0) {
            fprintf(stderr, "error: the width of image must be a multiple of 32\n");
            free(img_data);
            return 1;
        }
        if (opt.h <= 0 || opt.h % 32 != 0) {
            fprintf(stderr, "error: the height of image must be a multiple of 32\n");
            free(img_data);
            return 1;
        }
        init_img.assign(img_data, img_data + (opt.w * opt.h * c));
    }

    
    std::vector<uint8_t> img;
    if (opt.mode == TXT2IMG) {

        img = sd.txt2img(positive,
                         negative,
                         opt.cfg_scale,
                         opt.w,
                         opt.h,
                         opt.sample_method,
                         opt.sample_steps,
                         opt.seed);

    } else {
        img = sd.img2img(init_img,
                         positive,
                         negative,
                         opt.cfg_scale,
                         opt.w,
                         opt.h,
                         opt.sample_method,
                         opt.sample_steps,
                         opt.strength,
                         opt.seed);
    }

    if (img.size() == 0) {
        fprintf(stderr, "generate failed\n");
        return 1;
    }

    stbi_write_png(opt.output_path.c_str(), opt.w, opt.h, 3, img.data(), 0);
    printf("save result image to '%s'\n", opt.output_path.c_str());

    return 0;
}