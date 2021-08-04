#pragma once
#include "GuiData.hpp"

namespace ImGuiForDesktop
{
    void gui::main()
    {
        bool p_open = true;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar
        | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoBringToFrontOnFocus;

        ImGui::Begin("Desktop Imgui", &p_open, window_flags);
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
        ImGui::Text("example");
    }
}