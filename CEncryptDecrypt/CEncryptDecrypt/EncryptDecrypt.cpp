#include "StdAfx.h"
#include "EncryptDecrypt.h"

CEncryptDecrypt::CEncryptDecrypt(void)
{
}

CEncryptDecrypt::~CEncryptDecrypt(void)
{
}

CString CEncryptDecrypt::Encrypt(CString csInputBuffer)
{
	CString csOutputBuffer(_T(""));
	if (csInputBuffer.GetLength() == 0)
	{
		return csOutputBuffer;
	}
	
	for(int i = 0; i < csInputBuffer.GetLength(); i++)
	{
		csOutputBuffer.AppendChar(csInputBuffer.GetAt(i) + i + 10);
	}
	csOutputBuffer.AppendChar('\0');

	return csOutputBuffer;
}

CString CEncryptDecrypt::Decrypt(CString csInputBuffer)
{
	CString csOutputBuffer(_T(""));
	if (csInputBuffer.GetLength() == 0)
	{
		return csOutputBuffer;
	}

	for(int i = 0; i < csInputBuffer.GetLength(); i++)
	{
		csOutputBuffer.AppendChar(csInputBuffer.GetAt(i) - i - 10);
	}
	csOutputBuffer.AppendChar('\0');
	return csOutputBuffer;
}