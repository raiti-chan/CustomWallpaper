#pragma once

/// <summary>
/// ウィンドウ関連の関数をサポートします
/// </summary>
namespace window_util {
		
	/// <summary>
	/// プロセスIDからそのプロセスのメインハンドルを取得します。
	/// 存在しない場合は<code>nullptr</code>が返ります。
	/// </summary>
	/// <param name="processid">ターゲットプロセスID</param>
	/// <returns>メインウィンドウハンドル、存在しなければnullptr</returns>
	HWND find_mainwindow_by_processid(const DWORD processid);
}