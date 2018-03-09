#include "md5.h"
#include "hash.h"
#include <windows.h>

void EncryptSha1(void* pBufSha, void* pBufData, unsigned int length) {
	A_SHA_CTX shactx = { 0 };
	A_SHAInit(&shactx);
	A_SHAUpdate(&shactx, (unsigned char*)pBufData, length);
	A_SHAFinal(&shactx, (unsigned char*)pBufSha);
}

void EncryptMd5(void* pBufMd5, void* pBufData, unsigned int length) {
	MD5_CTX md5ctx = { 0 };
	MD5Init(&md5ctx);
	MD5Update(&md5ctx, pBufData, length);
	MD5Final(&md5ctx);
	memcpy(pBufMd5, &md5ctx.digest, 16);
}



/*
unsigned int md5UpdateProc(void* ppdata) {
	return 0;
}
*/

void EncryptMd5Large(void* pBufMd5, unsigned int pUpdateProc(void* pdata)) {

	MD5_CTX md5ctx = { 0 };
	MD5Init(&md5ctx);

	UCHAR data[4096];
	int length;
	while ( 0!=(length = pUpdateProc(data)))
	{
		MD5Update(&md5ctx, data, length);
	}	

	MD5Final(&md5ctx);

	memcpy(pBufMd5, &md5ctx.digest, 16);
}


void EncryptSha1Large(void* pBufSha1, unsigned int pUpdateProc(void* pdata)) {
	A_SHA_CTX shactx = { 0 };
	A_SHAInit(&shactx);

	UCHAR data[4096];
	int length;
	while (0 != (length = pUpdateProc(data)))
	{
		A_SHAUpdate(&shactx, data, length);
	}
	A_SHAFinal(&shactx, (unsigned char*)pBufSha1);
}





