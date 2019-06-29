#pragma once

#include "error_code.h"

/// <summary>
/// �A�v���P�[�V�����N���X
/// </summary>
class application final {
/*

#pragma region	Private Field
	/// <summary>
	/// �V���O���g���C���X�^���X
	/// </summary>	
	static application* _instance;
	/// <summary>
	/// �A�v���P�[�V�����̏I���R�[�h
	/// </summary>
	int _exit_code = 0;
	
	/// <summary>
	/// �Ō�ɋN�����G���[
	/// </summary>
	DWORD _last_error = 0;

	/// <summary>
	/// �A�v���P�[�V�����̃C���X�^���X�n���h��
	/// </summary>
	HINSTANCE _app_instance = nullptr;
	/// <summary>
	/// PowerShell�̃v���Z�Xid
	/// </summary>
	DWORD ps_process_id = 0;
	/// <summary>
	/// PowerShell�̃E�B���h�E�n���h��
	/// </summary>
	HWND ps_process_hwnd = nullptr;
	/// <summary>
	/// �W���o�͂̃t�@�C���|�C���^
	/// </summary>
	FILE *out = nullptr, *err = nullptr, *in = nullptr;
#pragma endregion
	
	/// <summary>
	/// �e�X�g:PowerShell���N��
	/// </summary>
	/// <returns>���������ꍇtrue</returns>
	bool t_start_powershell();

public :
	/// <summary>
	/// �V���O���g���C���X�^���X�|�C���^��Ԃ��܂��B
	/// </summary>
	/// <returns>�V���O���g���̃C���X�^���X�|�C���^</returns>
	static application* instance() {
		return _instance;
	}
	
	/// <summary>
	/// <see cref="application"/>�N���X���C���X�^���X�����܂�.
	/// </summary>
	/// <param name="h_instance">�A�v���P�[�V�����̃C���X�^���X�n���h��</param>
	explicit application(HINSTANCE h_instance) : _app_instance(h_instance) {
		this->_instance = this;
		this->_last_error = 0;
	}
	
	/// <summary>
	/// �A�v���P�[�V���������������܂��B
	/// </summary>
	void init();
	
	/// <summary>
	/// �A�v���P�[�V�������N��
	/// </summary>
	void run();
	
	/// <summary>
	/// �A�v���P�[�V�����̏I������
	/// </summary>
	void fin();
		
	/// <summary>
	/// �����G���[�̐ݒ�
	/// </summary>
	/// <param name="error_code">�ݒ肷��G���[�R�[�h</param>
	void set_last_error(DWORD error_code);
	
	/// <summary>
	/// �Ō�ɋN�����G���[�R�[�h�̎擾
	/// </summary>
	/// <returns></returns>
	DWORD get_last_error();

	/// <summary>
	/// �G���[�R�[�h����G���[���b�Z�[�W���o�͂��܂��B
	/// </summary>
	/// <param name="error_code">�G���[�R�[�h</param>
	static void write_error_message(DWORD error_code);
		
	/// <summary>
	/// �I���R�[�h
	/// </summary>
	/// <returns></returns>
	const int exit_code() const;
	
	/// <summary>
	/// �A�v���P�[�V�����̃C���X�^���X�n���h��
	/// </summary>
	/// <returns></returns>
	HINSTANCE app_instance() const;
*/
};