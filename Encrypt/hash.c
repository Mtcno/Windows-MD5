

#include <windows.h>
#include <tchar.h>






typedef struct
{
	ULONG flag;
	UCHAR hash[20];
	ULONG state[5];
	ULONG count[2];
	UCHAR buffer[64];
} A_SHA_CTX;



typedef void (__stdcall *PA_SHAInit) (_Out_ A_SHA_CTX *Context);
typedef void (__stdcall *PA_SHAUpdate) (_Inout_ A_SHA_CTX *Context, _In_reads_bytes_(Length) UCHAR *Input, _In_ ULONG Length);
typedef void (__stdcall *PA_SHAFinal) (_Inout_ A_SHA_CTX *Context, _Out_writes_bytes_(20) UCHAR *Hash);

__declspec(dllexport)
void __stdcall A_SHAInit(_Out_ A_SHA_CTX *Context) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PA_SHAInit ntdll_A_SHAInit = (PA_SHAInit)GetProcAddress(ntdll, "A_SHAInit");
	ntdll_A_SHAInit(Context);
}


__declspec(dllexport)
void __stdcall A_SHAUpdate(_Inout_ A_SHA_CTX *Context, _In_reads_bytes_(Length) UCHAR *Input, _In_ ULONG Length) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PA_SHAUpdate ntdll_A_SHAUpdate = (PA_SHAUpdate)GetProcAddress(ntdll, "A_SHAUpdate");
	ntdll_A_SHAUpdate(Context, Input, Length);
}

__declspec(dllexport)
void __stdcall A_SHAFinal(_Inout_ A_SHA_CTX *Context, _Out_writes_bytes_(20) UCHAR *Hash) {
	HMODULE ntdll = GetModuleHandle(_T("ntdll.dll"));
	if (!ntdll)return;
	PA_SHAFinal ntdll_A_SHAFinal = (PA_SHAFinal)GetProcAddress(ntdll, "A_SHAFinal");
	ntdll_A_SHAFinal(Context, Hash);

}