#pragma once

/// <summary>
/// �ǎ��E�B���h�E
/// </summary>
class wallpaper_window final {

	HWND _window_handle = nullptr;

	static LRESULT window_proc(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param);

public:

	/// <summary>
	/// �E�B���h�E�N���X��
	/// </summary>
	static const char* const class_name;

	/// <summary>
	/// �E�B���h�E�N���X��o�^���܂�
	/// </summary>
	/// <param name="h_instance">�C���X�^���X�n���h��</param>
	/// <returns>���������ꍇtrue���Ԃ�܂�</returns>
	static bool register_window(HINSTANCE h_instance);

	/// <summary>
	/// �E�B���h�E�N���X��o�^�������܂�
	/// </summary>
	/// <param name="h_instance">�C���X�^���X�n���h��</param>
	/// <returns>���������ꍇtrue���Ԃ�܂�</returns>
	static bool un_register_window(HINSTANCE h_instance);

	/// <summary>
	/// �E�B���h�E�𐶐����܂�
	/// </summary>
	/// <param name="h_instance">�C���X�^���X�n���h��</param>
	/// <param name="workerw">WorkerW�E�B���h�E</param>
	/// <param name="result">���������ꍇtrue���Ԃ�܂�</param>
	explicit wallpaper_window(HINSTANCE h_instance, HWND workerw, bool& result);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~wallpaper_window() = default;

	/// <summary>
	/// �E�B���h�E��\�����܂��B
	/// </summary>
	/// <returns></returns>
	void show_window() const;

	/// <summary>
	/// �E�B���h�E���B���܂�
	/// </summary>
	void hide_window() const;

	/// <summary>
	/// �E�B���h�E���A�N�e�B�u��(����\�ȏ��)�ɂ��܂��B
	/// </summary>
	void activate_window() const;

	/// <summary>
	/// �E�B���h�E���A�N�e�B�u��(����s�ȏ��)�ɂ��܂��B
	/// </summary>
	void deactivate_window() const;


};

