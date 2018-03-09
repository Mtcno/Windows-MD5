#ifndef _ENCRYPT_H
#define _ENCRYPT_H


#include "hash.h"
#include "md5.h"


#ifdef __cplusplus
extern "C" {
#endif

void EncryptSha1(void* pBufSha, void* pBufData, unsigned int length);
void EncryptMd5(void* pBufMd5, void* pBufData, unsigned int length);
void EncryptMd5Large(void* pBufMd5, unsigned int pUpdateProc(void* pdata));
void EncryptSha1Large(void* pBufSha1, unsigned int pUpdateProc(void* pdata));



#ifdef __cplusplus
}
#endif
#endif