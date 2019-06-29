#pragma once
#include "wallpaper_window.h"

/// <summary>
/// �A�v���P�[�V�����N���X
/// </summary>
class application final {

	/// <summary>
	/// ���̃A�v���P�[�V�����̃C���X�^���X
	/// </summary>
	static application* _instance;

	/// <summary>
	/// �A�v���P�[�V�����I���R�[�h
	/// </summary>
	int _exit_code = 0;

	/// <summary>
	/// �C���X�^���X�n���h��
	/// </summary>
	HINSTANCE _app_instance;

	/// <summary>
	/// PowerShell �v���Z�XID
	/// </summary>
	DWORD _ps_process_id = 0;

	/// <summary>
	/// �W���o�͂̃t�@�C���C���X�^���X�ւ̃|�C���^
	/// </summary>
	FILE *_out = nullptr, *_err = nullptr, *_in = nullptr;

	/// <summary>
	/// WorkerW �E�B���h�E�n���h��
	/// </summary>
	HWND _h_workerw_window = nullptr;

	/// <summary>
	/// �ǎ��E�B���h�E
	/// </summary>
	wallpaper_window* _wallpaper_window = nullptr;

	/// <summary>
	/// �A�v���P�[�V�����ւ̃��b�Z�[�W
	/// </summary>
	MSG _message = { nullptr };

public :

	/// <summary>
	/// ���̃A�v���P�[�V�����̃C���X�^���X
	/// </summary>
	/// <returns>�C���X�^���X�ւ̃|�C���^</returns>
	static application* instance() {
		return _instance;
	}

	/// <summary>
	/// �A�v���P�[�V����
	/// </summary>
	/// <param name="h_instance">�C���X�^���X�n���h��</param>
	explicit application(HINSTANCE h_instance) : _app_instance(h_instance) {
		_instance = this;
	}

	~application() {
		delete _wallpaper_window;
	}

	/// <summary>
	/// �������A�G���[�����������ꍇ exit_code�ɃG���[�R�[�h���Ԃ�܂��B
	/// </summary>
	///	<returns>win32API�ŃG���[�����������ꍇfalse���Ԃ�܂�</returns>
	bool init();

	/// <summary>
	/// ���s
	/// </summary>
	void run();
	
	/// <summary>
	/// �I������
	/// </summary>
	void fin() const;

	/// <summary>
	/// �G���[�R�[�h���o�͂��܂��B
	/// </summary>
	/// <param name="error_code">�G���[�R�[�h</param>
	static void write_error_message(DWORD error_code);

	/// <summary>
	/// WorkerW�E�B���h�E
	/// </summary>
	/// <returns></returns>
	static HWND find_workerw_window();

	/// <summary>
	/// �I���R�[�h���擾
	/// </summary>
	/// <returns>�I���R�[�h</returns>
	int exit_code() const {
		return this->_exit_code;
	}

	/// <summary>
	/// �C���X�^���X�n���h�����擾
	/// </summary>
	/// <returns>�C���X�^���X�n���h��</returns>
	HINSTANCE app_instance() const {
		return this->_app_instance;
	}
};