#include "encoding.h"

#include <windows.h>
#include <mbctype.h>

std::string utf8_to_ansi(const std::string& utf8)   
{   
	int nLen = MultiByteToWideChar( CP_UTF8, 0, utf8.c_str(), -1, NULL, 0 );   

	wchar_t* pwszGB2312 = new wchar_t[ nLen + 1 ];   
	RtlZeroMemory( pwszGB2312, nLen * 2 + 2 );   

	MultiByteToWideChar( CP_UTF8, 0, utf8.c_str(), -1, pwszGB2312, nLen );   

	nLen = WideCharToMultiByte( CP_ACP, 0, pwszGB2312, -1, NULL, 0, NULL, NULL );   

	CHAR* pszGB2312 = new CHAR[ nLen + 1 ];   
	RtlZeroMemory( pszGB2312, nLen + 1 );   

	WideCharToMultiByte( CP_ACP, 0, pwszGB2312, -1, pszGB2312, nLen, NULL, NULL );   

	std::string gb2312 = pszGB2312;   

	delete [] pszGB2312;   
	delete [] pwszGB2312;   
	return gb2312;
}

std::string ansi_to_utf8(const std::string& gb2312)   
{   
	int nLen = MultiByteToWideChar( CP_ACP, 0, gb2312.c_str(), -1, NULL, 0 );   

	wchar_t* pwszUTF8 = new wchar_t[ nLen + 1 ];   
	RtlZeroMemory( pwszUTF8, nLen * 2 + 2 );   

	MultiByteToWideChar( CP_ACP, 0, gb2312.c_str(), -1, pwszUTF8, nLen );   

	nLen = WideCharToMultiByte( CP_UTF8, 0, pwszUTF8, -1, NULL, 0, NULL, NULL );   

	CHAR* pszUTF8 = new CHAR[ nLen + 1 ];   
	RtlZeroMemory( pszUTF8, nLen + 1 );   

	WideCharToMultiByte( CP_UTF8, 0, pwszUTF8, -1, pszUTF8, nLen, NULL, NULL );   

	std::string utf8 = pszUTF8;   

	delete [] pszUTF8;   
	delete [] pwszUTF8;   
	return utf8;
}