#include "pch.h"
#include "process.h"


process::process(const char* file) {

	size_t file_len = strlen(file);
	this->_file_name = new char[file_len + 1];
	memcpy(_file_name, file, file_len);
	this->_file_name[file_len] = 0;

	ZeroMemory(&this->_info, sizeof(SHELLEXECUTEINFO));
	this->_info.cbSize = sizeof(SHELLEXECUTEINFO);
	this->_info.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_WAITFORINPUTIDLE | SEE_MASK_FLAG_DDEWAIT;
	this->_info.nShow = SW_SHOW;
	this->_info.lpFile = this->_file_name;
	this->_info.lpVerb = nullptr;
	this->_info.lpParameters = nullptr;
	this->_info.lpDirectory = nullptr;
}


process::~process() {
	delete[] this->_file_name;
}

ATOM process::start() {
	return ShellExecuteEx(&this->_info);
}
