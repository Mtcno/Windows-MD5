
#include <windows.h>
#include <tchar.h>


#pragma pack(push,1)
typedef struct MD5state_st
{
	ULONG i[2];
	ULONG buf[4];
	UCHAR in[64];
	UCHAR digest[16];
} MD5_CTX;
#pragma pack(pop)

typedef void (__stdcall *PMD5Init)(MD5_CTX *);
typedef void (__stdcall *PMD5Update)(MD5_CTX *, void*, ULONG);
typedef void (__stdcall *PMD5Final)( MD5_CTX *);

__declspec(dllexport)
void __stdcall MD5Init(MD5_CTX *c) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PMD5Init ntdll_MD5_Init = (PMD5Init)GetProcAddress(ntdll, "MD5Init");
	ntdll_MD5_Init(c);
}

__declspec(dllexport)
void __stdcall MD5Update(MD5_CTX *c, void * data, ULONG len) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PMD5Update ntdll_MD5_Update = (PMD5Update)GetProcAddress(ntdll, "MD5Update");
	ntdll_MD5_Update(c, data,len);
}


__declspec(dllexport)
void __stdcall MD5Final( MD5_CTX *c) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PMD5Final ntdll_MD5_Final = (PMD5Final)GetProcAddress(ntdll, "MD5Final");
	ntdll_MD5_Final(c);
}
