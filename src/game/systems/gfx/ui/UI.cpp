#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "UI.h"
#include "../../../../vendor/imgui/imgui.h"
#include "../../../../vendor/imgui/imgui_impl_glfw.h"
#include "../../../../vendor/imgui/imgui_impl_opengl3.h"
#include "../../../VoxelGame.h"

std::vector<float> deltaTime;

void UI::init(GLFWwindow * glfWwindow)
{
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(glfWwindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void UI::preloop() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UI::loop() {
    double dt = VoxelGame::deltaTime;
    deltaTime.push_back(dt);
    std::string dts = "Delta T: ";
    dts += dt;
    if(ImGui::Begin("-- PERF DAT -- ")) {
        ImGui::SetWindowFontScale(1.5);
        ImGui::Text("Delta Time: %f ms", dt * 1000);
        ImGui::SetWindowFontScale(3);
        ImGui::PlotHistogram("", &deltaTime[0], deltaTime.size());
        ImGui::SetWindowFontScale(1.5);
        ImGui::Text("Time: %f ", glfwGetTime());
        ImGui::Text("x,y,z: %f %f %f", Camera::getInstance()->getX(),Camera::getInstance()->getY(),Camera::getInstance()->getZ());
        ImGui::End();
        ImGui::Render();
    }
}

void UI::postloop() {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

