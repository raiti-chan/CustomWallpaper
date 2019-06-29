#pragma once
#include "non_copyable.h"

class process : non_copyable {
	char* _file_name;
	SHELLEXECUTEINFO _info;

public:
	process(const char* file);
	~process();

	ATOM start();

	const SHELLEXECUTEINFO& info() {
		return this->_info;
	}

	char const* file_name() {
		return this->_file_name;
	}
};

