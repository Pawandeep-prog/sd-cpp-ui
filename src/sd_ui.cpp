#include "imgui.h"
#include "sd_ui.h"
#include <iostream>
#include "sd_utility.cpp"
#include "utils.cpp"
#include <future>

namespace StableDiffUI{
    char positive_prompt[500], negative_prompt[500], model_path[500], image_path[500]="";
    bool show_preview = false;

    void thread_generate(){
        generate_image(positive_prompt, negative_prompt);
        show_preview = true;
        Utils::texture_loaded = false;
    }
    

    void showUI(){
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        ImGui::Begin("load model");
        ImGui::InputText("model path", model_path, sizeof(model_path));
        ImGui::SameLine();
        if(ImGui::Button("load model")){
            set_model_path(model_path);
        }
        ImGui::End();

        ImGui::Begin("text2Img");
        ImGui::InputText("positive prompt", positive_prompt, sizeof(positive_prompt));
        ImGui::InputText("negative prompt", negative_prompt, sizeof(negative_prompt));
        if(ImGui::Button("Generate")){
            thread_generate();
        }
        ImGui::End();

        
        if(show_preview){
            Utils::show_image_preview();
        }
        
    }
}