#include "pch.h"
#include "application.h"
#include "window_util.h"

#include "process.h"

/*
application* application::_instance;

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

void application::init() {
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		AllocConsole();
	}
	freopen_s(&this->out, "CONOUT$", "w", stdout);
	freopen_s(&this->err, "CONOUT$", "w", stderr);
	freopen_s(&this->in, "CONIN$", "r", stdin);

	std::cout << "initialize.\n";
}

void application::run() {
	std::cout << "running.\n";

	//if (!t_start_powershell()) return;


	system("pause");
}

void application::fin() {
	std::cout << "finalize.\n";
	fclose(this->out);
	fclose(this->err);
	fclose(this->in);
	FreeConsole();
}

void application::set_last_error(DWORD error_code) {
	this->_last_error = error_code;
}

DWORD application::get_last_error() {
	return this->_last_error;
}

void application::write_error_message(DWORD error_code) {
	LPSTR lp_message_buffer = nullptr;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, error_code, LANG_USER_DEFAULT,
		reinterpret_cast<LPSTR>(&lp_message_buffer), 0, nullptr);
	std::cerr << std::hex << error_code << " : " << lp_message_buffer << "\n";
	LocalFree(lp_message_buffer);
}

const int application::exit_code() const {
	return this->_exit_code;
}

HINSTANCE application::app_instance() const {
	return this->_app_instance;
}
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//application app(hInstance);
	//app.init();
	//app.run();
	//app.fin();
	//return app.exit_code();
}
