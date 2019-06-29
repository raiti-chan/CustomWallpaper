#include "pch.h"
#include "wallpaper_window.h"


const char* const wallpaper_window::class_name = "wallpaper_window";


LRESULT wallpaper_window::window_proc(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param) {
	switch (msg) {
	case WM_DESTROY:
	{
		std::cout << "wallpaper_window closed.\n";
		PostQuitMessage(0);
		return 0;
	}
	case WM_NULL:
	{
		return 0;
	}
	default:
		return DefWindowProc(h_wnd, msg, w_param, l_param);
	}

}

bool wallpaper_window::register_window(HINSTANCE h_instance) {
	WNDCLASS window_class{
		CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		window_proc,
		0,
		0,
		h_instance,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)),
		nullptr,
		class_name
	};
	std::cout << "Register wallpaper_window class.\n";
	return RegisterClass(&window_class);
}

bool wallpaper_window::un_register_window(HINSTANCE h_instance) {
	std::cout << "UnRegister wallpaper_window class.\n";
	return UnregisterClass(class_name, h_instance);
}

wallpaper_window::wallpaper_window(HINSTANCE h_instance, HWND workerw, bool& result) {
	RECT primary_monitor_rect;
	if (!SystemParametersInfo(SPI_GETWORKAREA, 0, &primary_monitor_rect, 0)) {
		result = false;
		return;
	}
	this->_window_handle = CreateWindow(class_name, class_name, WS_CHILD, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
										workerw, nullptr, h_instance, nullptr);
	if (this->_window_handle == nullptr) {
		result = false;
		return;
	}

}

void wallpaper_window::show_window() const {
	ShowWindow(this->_window_handle, SW_SHOWNA);
}

void wallpaper_window::hide_window() const {
	ShowWindow(this->_window_handle, SW_HIDE);
}

void wallpaper_window::activate_window() const {
	SetWindowPos(this->_window_handle, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
}

void wallpaper_window::deactivate_window() const {
	SetWindowPos(this->_window_handle, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
}


