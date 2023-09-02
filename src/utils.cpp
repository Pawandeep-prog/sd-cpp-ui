#define STB_IMAGE_IMPLEMENTATION
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"
#include "imgui_impl_opengl3_loader.h"

namespace Utils{
    GLuint my_image_texture = 0;
    int my_image_width = 0;
    int my_image_height = 0;
    char* image_path = "./output.png";
    bool texture_loaded = false;


    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
    {
        // Load from file
        int image_width = 0;
        int image_height = 0;
        unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
        if (image_data == NULL)
            return false;

        // Create a OpenGL texture identifier
        GLuint image_texture;
        glGenTextures(1, &image_texture);
        glBindTexture(GL_TEXTURE_2D, image_texture);

        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Upload pixels into texture
    #if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    #endif
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
        stbi_image_free(image_data);

        *out_texture = image_texture;
        *out_width = image_width;
        *out_height = image_height;

        return true;
    }



    void loadTexture(char* path){
        bool ret = LoadTextureFromFile(path, &my_image_texture, &my_image_width, &my_image_height);
        IM_ASSERT(ret);
    }

    void show_image_preview(){

        if(!texture_loaded){
            loadTexture(image_path);
            texture_loaded=true;
        }

        ImGui::Begin("Image Preview");
        auto size = ImGui::GetContentRegionAvail();
        ImGui::Image((void*)(intptr_t)my_image_texture, size);
        ImGui::End();
    }
}