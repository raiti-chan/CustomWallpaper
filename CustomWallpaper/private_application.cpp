#include "pch.h"
#include "application.h"
#include "process.h"
#include "window_util.h"

bool application::t_start_powershell() {
	process power_shell("powershell.exe");
	ATOM result = power_shell.start();
	if (!result) {
		write_error_message(GetLastError());
		system("pause");
		this->_exit_code = GetLastError();
		return false;
	}
	this->ps_process_id = GetProcessId(power_shell.info().hProcess);
	while (this->ps_process_hwnd == nullptr) {
		this->ps_process_hwnd = window_util::find_mainwindow_by_processid(this->ps_process_id);
	}
	return true;
}