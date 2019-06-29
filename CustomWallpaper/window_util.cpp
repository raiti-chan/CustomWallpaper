#include "pch.h"
#include "window_util.h"

#include <tuple>
namespace window_util {
	

	HWND find_mainwindow_by_processid(const DWORD processid) {
		using type_enum_window_lparam = std::tuple<DWORD, HWND*>;
		
		HWND h_mainwindow = nullptr;
		type_enum_window_lparam lparam_value = {processid, &h_mainwindow};
		
		EnumWindows([](HWND h_window, LPARAM lparam)->BOOL {
			auto [lv_target_processid, lv_p_result_h_mainwindow] = *(reinterpret_cast<type_enum_window_lparam*>(lparam));
			
			DWORD lv_process_id = 0;
			GetWindowThreadProcessId(h_window, &lv_process_id);
			if (lv_process_id == lv_target_processid) {
				std::cout << std::hex << h_window << "\n";
				*lv_p_result_h_mainwindow = h_window;
			}
			return true;
		}, reinterpret_cast<LPARAM>(&lparam_value));

		return h_mainwindow;
	}
}