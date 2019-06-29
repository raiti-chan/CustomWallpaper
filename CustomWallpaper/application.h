#pragma once
#include "wallpaper_window.h"

/// <summary>
/// アプリケーションクラス
/// </summary>
class application final {

	/// <summary>
	/// このアプリケーションのインスタンス
	/// </summary>
	static application* _instance;

	/// <summary>
	/// アプリケーション終了コード
	/// </summary>
	int _exit_code = 0;

	/// <summary>
	/// インスタンスハンドル
	/// </summary>
	HINSTANCE _app_instance;

	/// <summary>
	/// PowerShell プロセスID
	/// </summary>
	DWORD _ps_process_id = 0;

	/// <summary>
	/// 標準出力のファイルインスタンスへのポインタ
	/// </summary>
	FILE *_out = nullptr, *_err = nullptr, *_in = nullptr;

	/// <summary>
	/// WorkerW ウィンドウハンドル
	/// </summary>
	HWND _h_workerw_window = nullptr;

	/// <summary>
	/// 壁紙ウィンドウ
	/// </summary>
	wallpaper_window* _wallpaper_window = nullptr;

	/// <summary>
	/// アプリケーションへのメッセージ
	/// </summary>
	MSG _message = { nullptr };

public :

	/// <summary>
	/// このアプリケーションのインスタンス
	/// </summary>
	/// <returns>インスタンスへのポインタ</returns>
	static application* instance() {
		return _instance;
	}

	/// <summary>
	/// アプリケーション
	/// </summary>
	/// <param name="h_instance">インスタンスハンドル</param>
	explicit application(HINSTANCE h_instance) : _app_instance(h_instance) {
		_instance = this;
	}

	~application() {
		delete _wallpaper_window;
	}

	/// <summary>
	/// 初期化、エラーが発生した場合 exit_codeにエラーコードが返ります。
	/// </summary>
	///	<returns>win32APIでエラーが発生した場合falseが返ります</returns>
	bool init();

	/// <summary>
	/// 実行
	/// </summary>
	void run();
	
	/// <summary>
	/// 終了処理
	/// </summary>
	void fin() const;

	/// <summary>
	/// エラーコードを出力します。
	/// </summary>
	/// <param name="error_code">エラーコード</param>
	static void write_error_message(DWORD error_code);

	/// <summary>
	/// WorkerWウィンドウ
	/// </summary>
	/// <returns></returns>
	static HWND find_workerw_window();

	/// <summary>
	/// 終了コードを取得
	/// </summary>
	/// <returns>終了コード</returns>
	int exit_code() const {
		return this->_exit_code;
	}

	/// <summary>
	/// インスタンスハンドルを取得
	/// </summary>
	/// <returns>インスタンスハンドル</returns>
	HINSTANCE app_instance() const {
		return this->_app_instance;
	}
};