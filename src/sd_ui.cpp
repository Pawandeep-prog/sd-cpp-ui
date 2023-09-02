#include "imgui.h"
#include "sd_ui.h"
#include <iostream>
#include "sd_utility.cpp"

namespace StableDiffUI{
    char positive_prompt[500], negative_prompt[500], model_path[500];

    void showUI(){
    
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        ImGui::Begin("load model");
        ImGui::InputText("model path", model_path, sizeof(model_path));
        ImGui::SameLine();
        if(ImGui::Button("load model")){
            load_model(model_path);
        }
        ImGui::End();

        ImGui::Begin("Stable Diffusion UI");
        ImGui::InputText("positive prompt", positive_prompt, sizeof(positive_prompt));
        ImGui::InputText("negative prompt", negative_prompt, sizeof(negative_prompt));
        if(ImGui::Button("Generate")){
            std::cout<<"generating images ....";
            std::cout<<generate_image(positive_prompt, negative_prompt);
        }
        ImGui::End();

    }
}