#pragma once
#include "pch.h"

/// <summary>
/// アプリケーションクラス
/// </summary>
class application final {

	/// <summary>
	/// シングルトンインスタンス
	/// </summary>	
	static application* _instance;

	/// <summary>
	/// アプリケーションの終了コード
	/// </summary>
	int exit_code;

	/// <summary>
	/// 最後に起きたエラー
	/// </summary>
	DWORD last_error;

/*

#pragma region	Private Field
	/// <summary>
	/// アプリケーションの終了コード
	/// </summary>
	int _exit_code = 0;
	
	/// <summary>
	/// 最後に起きたエラー
	/// </summary>
	DWORD _last_error = 0;

	/// <summary>
	/// アプリケーションのインスタンスハンドル
	/// </summary>
	HINSTANCE _app_instance = nullptr;
	/// <summary>
	/// PowerShellのプロセスid
	/// </summary>
	DWORD ps_process_id = 0;
	/// <summary>
	/// PowerShellのウィンドウハンドル
	/// </summary>
	HWND ps_process_hwnd = nullptr;
	/// <summary>
	/// 標準出力のファイルポインタ
	/// </summary>
	FILE *out = nullptr, *err = nullptr, *in = nullptr;
#pragma endregion
	
	/// <summary>
	/// テスト:PowerShellを起動
	/// </summary>
	/// <returns>成功した場合true</returns>
	bool t_start_powershell();

public :
	/// <summary>
	/// シングルトンインスタンスポインタを返します。
	/// </summary>
	/// <returns>シングルトンのインスタンスポインタ</returns>
	static application* instance() {
		return _instance;
	}
	
	/// <summary>
	/// <see cref="application"/>クラスをインスタンス化します.
	/// </summary>
	/// <param name="h_instance">アプリケーションのインスタンスハンドル</param>
	explicit application(HINSTANCE h_instance) : _app_instance(h_instance) {
		this->_instance = this;
		this->_last_error = 0;
	}
	
	/// <summary>
	/// アプリケーションを初期化します。
	/// </summary>
	void init();
	
	/// <summary>
	/// アプリケーションを起動
	/// </summary>
	void run();
	
	/// <summary>
	/// アプリケーションの終了処理
	/// </summary>
	void fin();
		
	/// <summary>
	/// 発生エラーの設定
	/// </summary>
	/// <param name="error_code">設定するエラーコード</param>
	void set_last_error(DWORD error_code);
	
	/// <summary>
	/// 最後に起きたエラーコードの取得
	/// </summary>
	/// <returns></returns>
	DWORD get_last_error();

	/// <summary>
	/// エラーコードからエラーメッセージを出力します。
	/// </summary>
	/// <param name="error_code">エラーコード</param>
	static void write_error_message(DWORD error_code);
		
	/// <summary>
	/// 終了コード
	/// </summary>
	/// <returns></returns>
	const int exit_code() const;
	
	/// <summary>
	/// アプリケーションのインスタンスハンドル
	/// </summary>
	/// <returns></returns>
	HINSTANCE app_instance() const;
*/
};