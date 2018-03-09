
#ifndef _MD5_H
#define _MD5_H


//CryptCreateHash
//https ://msdn.microsoft.com/en-us/library/windows/desktop/aa380256(v=vs.85).aspx

# ifdef  __cplusplus
extern "C" {
# endif


typedef unsigned long ULONG;
typedef unsigned char UCHAR;



#pragma pack(push,1)
/*
https://tools.ietf.org/html/rfc1321
typedef struct {
	UINT4 state[4];                 state (ABCD) 
	UINT4 count[2];					number of bits, modulo 2^64 (lsb first) 
	unsigned char buffer[64];       input buffer 
} MD5_CTX;
	
*/

//https://processhacker.sourceforge.io/doc/phlib_2include_2md5_8h_source.html
typedef struct MD5state_st
{
	ULONG i[2];
	ULONG buf[4];
	UCHAR in[64];
	UCHAR digest[16];
} MD5_CTX;
#pragma pack(pop)

/*
VOID MD5Init(_Out_ MD5_CTX *Context);
VOID MD5Update(_Inout_ MD5_CTX *Context, _In_reads_bytes_(Length) UCHAR *Input, _In_ ULONG Length);
VOID MD5Final(_Inout_ MD5_CTX *Context);
*/

void __stdcall MD5Init(MD5_CTX *);
void __stdcall MD5Update(MD5_CTX *, void *, ULONG);
void __stdcall MD5Final( MD5_CTX *);

# ifdef  __cplusplus
}
# endif


#endif
