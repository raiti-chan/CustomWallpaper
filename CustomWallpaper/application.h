#pragma once

class application final {

	static application* _instance;

	int _exit_code = 0;
	HINSTANCE _app_instance;

	DWORD ps_process_id = 0;

	FILE *out = nullptr, *err = nullptr, *in = nullptr;
public :

	static application* instance() {
		return _instance;
	}

	explicit application(HINSTANCE h_instance) : _app_instance(h_instance) {
		_instance = this;
	}

	void init();

	void run();

	void fin() const;

	static void write_error_message(DWORD error_code);

	int exit_code() const {
		return this->_exit_code;
	}

	HINSTANCE app_instance() const {
		return this->_app_instance;
	}
};