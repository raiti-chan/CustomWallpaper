#include "pch.h"
#include "application.h"

application* application::_instance;

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
	PROCESS_INFORMATION process_information = { 0 };
	STARTUPINFO startup_info = { sizeof(STARTUPINFO) };
	char cmd_line[] = "conhost.exe powershell.exe";
	bool result = CreateProcess(nullptr, cmd_line, nullptr, nullptr, false,
				  NORMAL_PRIORITY_CLASS, nullptr, nullptr, &startup_info, &process_information);
	if (!result) {
		write_error_message(GetLastError());
		system("pause");
		this->_exit_code = GetLastError();
		return;
;	}

	this->ps_process_id = process_information.dwProcessId;

	system("pause");
}

void application::fin() const {
	std::cout << "finalize.\n";
	fclose(this->out);
	fclose(this->err);
	fclose(this->in);
	FreeConsole();
}

void application::write_error_message(DWORD error_code) {
	LPSTR lp_message_buffer = nullptr;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, error_code, LANG_USER_DEFAULT, 
				  reinterpret_cast<LPSTR>(&lp_message_buffer), 0, nullptr);
	std::cerr << error_code << " : " << lp_message_buffer << "\n";
	LocalFree(lp_message_buffer);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/) {
	application app(hInstance);
	app.init();
	app.run();
	app.fin();
	app.exit_code();
}

