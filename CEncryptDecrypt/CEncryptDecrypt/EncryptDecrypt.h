#pragma once

class CEncryptDecrypt
{
public:
	CEncryptDecrypt(void);
	~CEncryptDecrypt(void);

	CString Encrypt(CString csInputBuffer);
	CString Decrypt(CString csInputBuffer);
};
