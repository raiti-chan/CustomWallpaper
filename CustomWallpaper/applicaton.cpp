#include "pch.h"
#include "application.h"
#include "window_util.h"

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

void application::write_error_message(environment::error_code error_code) {
	LPSTR lp_message_buffer = nullptr;
	if (error_code.raw_code & environment::APPLICATION_ERROR) {
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_FROM_HMODULE, nullptr, error_code.split_code.error_code, 
			LANG_USER_DEFAULT, reinterpret_cast<LPSTR>(&lp_message_buffer), 0, nullptr);

	} else {
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, error_code.split_code.error_code, LANG_USER_DEFAULT,
			reinterpret_cast<LPSTR>(&lp_message_buffer), 0, nullptr);
	}
	std::cerr << std::hex << error_code.raw_code << " : " << lp_message_buffer << "\n";
	LocalFree(lp_message_buffer);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/) {
	application app(hInstance);
	app.init();
	app.run();
	app.fin();
	return app.exit_code();
}

