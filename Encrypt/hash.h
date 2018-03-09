
#ifndef _SHA_H
#define _SHA_H


# ifdef  __cplusplus
extern "C" {
# endif

typedef unsigned long ULONG;
typedef unsigned char UCHAR;

typedef struct
{
	ULONG flag;
	UCHAR hash[20];
	ULONG state[5];
	ULONG count[2];
	UCHAR buffer[64];
} A_SHA_CTX;

void __stdcall A_SHAInit(
     A_SHA_CTX *Context
);

void __stdcall A_SHAUpdate(
    A_SHA_CTX *Context,
    UCHAR *Input,
    ULONG Length
);

void __stdcall A_SHAFinal(
    A_SHA_CTX *Context,
    UCHAR *Hash
);




# ifdef  __cplusplus
}
# endif


#endif    
 
