#pragma once

namespace environment {	
	/// <summary>
	/// システム標準のエラー
	/// </summary>
	constexpr unsigned long long SYSTEM_ERROR = 0x0000000000000000;	
	/// <summary>
	/// アプリケーション定義のエラー
	/// </summary>
	constexpr unsigned long long APPLICATION_ERROR = 0x0100000000000000;
	
	using error_struct = struct _error_struct {
		DWORD error_category;
		DWORD error_code;
	};
	
	using error_code = union _error_code {
		unsigned long long raw_code;
		error_struct split_code;
	};
}