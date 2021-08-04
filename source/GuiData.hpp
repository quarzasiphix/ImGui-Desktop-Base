#pragma once
#include "common.hpp"

extern HWND hwnd;
extern ID3D11Device* g_pd3dDevice;
extern ID3D11DeviceContext* g_pd3dDeviceContext;
extern IDXGISwapChain* g_pSwapChain;
extern ID3D11RenderTargetView* g_mainRenderTargetView;

// Grabs WindowSize Namespace From Main.cpp
// So ImGui Can Update It In gui.render()
// This Is Used For Keeping The Main ImGui Window
// The Same size As The Actual Window

namespace WindowSize
{
	extern float x, y;
}

namespace ImGuiForDesktop
{
	class children
	{
	protected:
		void main();

		void example();
	};

	class gui : children
	{
		RECT rc;

		// Used For Category Stuff
		ImVec2 spacing;
		ImVec2 padding;
		ImVec2 CatButtonSize;
		ImVec2 SideBarSize;
		float CatOffset = 96;

		enum class tabs
		{
			main,
			example
		};

		// Category Variable (Modified In gui.cpp)
		tabs tab;

		void main();

		void style();

	public:

		bool intialised = false;

		gui();

		~gui();

		void initialise();

		void render();
	};
}