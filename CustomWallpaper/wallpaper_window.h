#pragma once

/// <summary>
/// 壁紙ウィンドウ
/// </summary>
class wallpaper_window final {

	HWND _window_handle = nullptr;

	static LRESULT window_proc(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param);

public:

	/// <summary>
	/// ウィンドウクラス名
	/// </summary>
	static const char* const class_name;

	/// <summary>
	/// ウィンドウクラスを登録します
	/// </summary>
	/// <param name="h_instance">インスタンスハンドル</param>
	/// <returns>成功した場合trueが返ります</returns>
	static bool register_window(HINSTANCE h_instance);

	/// <summary>
	/// ウィンドウクラスを登録解除します
	/// </summary>
	/// <param name="h_instance">インスタンスハンドル</param>
	/// <returns>成功した場合trueが返ります</returns>
	static bool un_register_window(HINSTANCE h_instance);

	/// <summary>
	/// ウィンドウを生成します
	/// </summary>
	/// <param name="h_instance">インスタンスハンドル</param>
	/// <param name="workerw">WorkerWウィンドウ</param>
	/// <param name="result">成功した場合trueが返ります</param>
	explicit wallpaper_window(HINSTANCE h_instance, HWND workerw, bool& result);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~wallpaper_window() = default;

	/// <summary>
	/// ウィンドウを表示します。
	/// </summary>
	/// <returns></returns>
	void show_window() const;

	/// <summary>
	/// ウィンドウを隠します
	/// </summary>
	void hide_window() const;

	/// <summary>
	/// ウィンドウをアクティブ化(操作可能な状態)にします。
	/// </summary>
	void activate_window() const;

	/// <summary>
	/// ウィンドウを非アクティブ化(操作不可な状態)にします。
	/// </summary>
	void deactivate_window() const;


};

