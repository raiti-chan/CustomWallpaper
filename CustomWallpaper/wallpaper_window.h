#pragma once
/// <summary>
/// 壁紙ウィンドウ
/// </summary>
class wallpaper_window {
	static const char WINDOW_CLASS_NAME[];
	/// <summary>
	/// このウィンドウのウィンドウクラスが登録されていればtrue
	/// </summary>
	static bool IS_REGISTERD_WINDOWCLASS;
public:

	static bool init_wallpaper_window();
	static void final_wallpaper_window();

	wallpaper_window();
	~wallpaper_window();

	static LRESULT CALLBACK window_proc(HWND h_window, UINT param ,WPARAM w_param, LPARAM l_param);
};

