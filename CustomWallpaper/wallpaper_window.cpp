#include "pch.h"
#include "wallpaper_window.h"
/*
const char wallpaper_window::WINDOW_CLASS_NAME[] = "WALLPAPER_WINDOW";

bool wallpaper_window::IS_REGISTERD_WINDOWCLASS = false;

bool wallpaper_window::init_wallpaper_window() {
	if (!IS_REGISTERD_WINDOWCLASS) {
		WNDCLASSEX window_class;
		ZeroMemory(&window_class, sizeof(WNDCLASSEX));
		window_class.cbSize = sizeof(WNDCLASSEX);
		window_class.style = CS_HREDRAW | CS_VREDRAW;
		window_class.lpfnWndProc = window_proc;
		window_class.hInstance = nullptr;
		window_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
		window_class.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND + 1);
		window_class.lpszMenuName = nullptr;
		window_class.lpszClassName = WINDOW_CLASS_NAME;
		window_class.hIconSm = nullptr;
		RegisterClassEx(&window_class);
	}
}

void wallpaper_window::final_wallpaper_window() {
	//UnregisterClass();
}

wallpaper_window::wallpaper_window() {

}


wallpaper_window::~wallpaper_window() {
}

LRESULT CALLBACK wallpaper_window::window_proc(HWND h_window, UINT param, WPARAM w_param, LPARAM l_param) {
	return DefWindowProc(h_window, param, w_param, l_param);
}
*/