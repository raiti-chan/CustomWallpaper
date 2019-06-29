#include "pch.h"
#include "application.h"

#define WIN32_ERROR_RETURN(result) if(!(result)) return result;

application* application::_instance;

bool application::init() {
	if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
		AllocConsole();
	}
	freopen_s(&this->_out, "CONOUT$", "w", stdout);
	freopen_s(&this->_err, "CONOUT$", "w", stderr);
	freopen_s(&this->_in, "CONIN$", "r", stdin);

	std::cout << "initialize.\n"
		<< "start-up WorkerW.\n";
	bool result = this->_h_workerw_window = find_workerw_window();
	WIN32_ERROR_RETURN(result);
	result = wallpaper_window::register_window(this->_app_instance);
	WIN32_ERROR_RETURN(result);
	this->_wallpaper_window = new wallpaper_window(this->_app_instance, this->_h_workerw_window, result);
	WIN32_ERROR_RETURN(result);

	return true;
}

void application::run() {
	std::cout << "running.\n";
	PROCESS_INFORMATION process_information = { nullptr };
	STARTUPINFO startup_info = { sizeof(STARTUPINFO) };
	char cmd_line[] = "conhost.exe powershell.exe";
	bool result = CreateProcess(nullptr, cmd_line, nullptr, nullptr, false,
				  NORMAL_PRIORITY_CLASS, nullptr, nullptr, &startup_info, &process_information);
	if (!result) {
		write_error_message(GetLastError());
		system("pause");
		this->_exit_code = GetLastError();
		return;
	}

	this->_ps_process_id = process_information.dwProcessId;

	this->_wallpaper_window->show_window();

	while(GetMessage(&this->_message, nullptr, 0, 0)) {
		TranslateMessage(&this->_message);
		DispatchMessage(&this->_message);
	}

	this->_exit_code = this->_message.lParam;
}

void application::fin() const {
	std::cout << "finalize.\n"
		<< "UnRegister wallpaper_window.\n";

	bool result = wallpaper_window::un_register_window(this->_app_instance);
	if (!result) write_error_message(GetLastError());

	system("pause");

	fclose(this->_out);
	fclose(this->_err);
	fclose(this->_in);
	FreeConsole();
}

void application::write_error_message(DWORD error_code) {
	LPSTR lp_message_buffer = nullptr;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, error_code, LANG_USER_DEFAULT, 
				  reinterpret_cast<LPSTR>(&lp_message_buffer), 0, nullptr);
	std::cerr << error_code << " : " << lp_message_buffer << '\n';
	LocalFree(lp_message_buffer);
}

HWND application::find_workerw_window() {
	std::cout << "Find Wallpaper window.\n";
	HWND wallpaper_window = nullptr;
	callback_parameter<LPARAM, HWND> call_param([&wallpaper_window](LPARAM, HWND h_wnd) -> BOOL {
		HWND shell = FindWindowEx(h_wnd, nullptr, "SHELLDLL_DefView", nullptr);
		if (shell != nullptr) {
			wallpaper_window = h_wnd;
		}
		return true;
	});

	EnumWindows(callback_parameter<LPARAM, HWND>::callback_invoke_lambda, reinterpret_cast<LPARAM>(&call_param));
	std::cout << "wallpaper window [WorkerW] : " << std::hex << wallpaper_window << '\n';
	return wallpaper_window;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/) {
	application* app = new application(hInstance);
	if (!app->init()) {
		DWORD error = GetLastError();
		application::write_error_message(error);
	}
	app->run();
	app->fin();
	int exit_code = app->exit_code();
	delete app;
	return exit_code;
}

