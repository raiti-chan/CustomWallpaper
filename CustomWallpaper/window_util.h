#pragma once

/// <summary>
/// �E�B���h�E�֘A�̊֐����T�|�[�g���܂�
/// </summary>
namespace window_util {
		
	/// <summary>
	/// �v���Z�XID���炻�̃v���Z�X�̃��C���n���h�����擾���܂��B
	/// ���݂��Ȃ��ꍇ��<code>nullptr</code>���Ԃ�܂��B
	/// </summary>
	/// <param name="processid">�^�[�Q�b�g�v���Z�XID</param>
	/// <returns>���C���E�B���h�E�n���h���A���݂��Ȃ����nullptr</returns>
	HWND find_mainwindow_by_processid(const DWORD processid);
}