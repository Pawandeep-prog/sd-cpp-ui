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

// get_num_physical_cores is copy from
// https://github.com/ggerganov/llama.cpp/blob/master/examples/common.cpp
// LICENSE: https://github.com/ggerganov/llama.cpp/blob/master/LICENSE
int32_t get_num_physical_cores() {
#ifdef __linux__
    // enumerate the set of thread siblings, num entries is num cores
    std::unordered_set<std::string> siblings;
    for (uint32_t cpu = 0; cpu < UINT32_MAX; ++cpu) {
        std::ifstream thread_siblings("/sys/devices/system/cpu" + std::to_string(cpu) + "/topology/thread_siblings");
        if (!thread_siblings.is_open()) {
            break;  // no more cpus
        }
        std::string line;
        if (std::getline(thread_siblings, line)) {
            siblings.insert(line);
        }
    }
    if (siblings.size() > 0) {
        return static_cast<int32_t>(siblings.size());
    }
#elif defined(__APPLE__) && defined(__MACH__)
    int32_t num_physical_cores;
    size_t len = sizeof(num_physical_cores);
    int result = sysctlbyname("hw.perflevel0.physicalcpu", &num_physical_cores, &len, NULL, 0);
    if (result == 0) {
        return num_physical_cores;
    }
    result = sysctlbyname("hw.physicalcpu", &num_physical_cores, &len, NULL, 0);
    if (result == 0) {
        return num_physical_cores;
    }
#elif defined(_WIN32)
    // TODO: Implement
#endif
    unsigned int n_threads = std::thread::hardware_concurrency();
    return n_threads > 0 ? (n_threads <= 4 ? n_threads : n_threads / 2) : 4;
}

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
        printf("    model_path:      %s\n", model_path.c_str());
        printf("    output_path:     %s\n", output_path.c_str());
        printf("    init_img:        %s\n", init_img.c_str());
        printf("    prompt:          %s\n", prompt.c_str());
        printf("    negative_prompt: %s\n", negative_prompt.c_str());
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
StableDiffusion sd(opt.n_threads, vae_decode_only, true);
bool load_model(char* path){
    // char* model_path = "/Users/pawandeepsingh/Documents/Development/sd/stable-diffusion.cpp/models/realistic.bin";
    if (!sd.load_from_file(path)) {
        return false;
    }
    opt.print();
    return true;
}
int generate_image(char* positive, char* negative) {
    
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