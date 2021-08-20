#pragma once
#include "GuiData.hpp"

namespace ImGuiForDesktop
{
    void gui::main()
    {
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar
        | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoBringToFrontOnFocus;

        ImGuiStyle& style = ImGui::GetStyle();

        // turns off window border
        style.WindowBorderSize = 0.0f;
        ImGui::Begin("Desktop Imgui", nullptr, window_flags);
        
        // enables window border for other windows
        style.WindowBorderSize = 1.0f;

        //Updates The Main Gui Window To The Size Of The Window
        ImGui::SetWindowSize(ImVec2(WindowSize::x, WindowSize::y));
        //Sets The Positon To 0 To Keep The Gui At The Top Corner Of the Screen
        ImGui::SetWindowPos(ImVec2(0, 0));

        // CatOffset stands for (category offset)
        // CatSize stands for Category size
        
        // If You Want To Add Categories, Add The
        // The Category Name To The (TABS) Enum Inside Of
        // GuiData.hpp And Add Make A Function For It In Children
        ImGui::Columns(3, "tabs", false);
        ImGui::SetColumnWidth(0, CatOffset);
        {
            // Updates TAB Variable To The Chosen Category

            if (ImGui::Button("main", CatButtonSize))
                tab = tabs::main;
            
            if (ImGui::Button("example", CatButtonSize))
                tab = tabs::example;
        }
        ImGui::NextColumn();

        // Check's Which Tab Was Selected ^^
        switch (tab)
        {
        case tabs::main:
            children::main();
            break;
        case tabs::example:
            children::example();
            break;
        //If None Were Chosen, Load Main
            // At Launch, There Are No Selected Categories
            //so By Defualt, It Will Load (children::main()) 
        default:
            children::main();
            break;
        }
    }

    // Children Declerations Are Found In GuiData.hpp

    void children::main()
    {
        ImGui::Text("main");
    }

    void children::example()
    {
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::ShowDemoWindow();

        ImGui::Text("example");
    }
}