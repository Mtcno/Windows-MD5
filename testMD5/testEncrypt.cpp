

#include <windows.h>
#include <stdio.h>
#include "..\Encrypt\Encrypt.h"

//²âÊÔ´óÎÄ¼þ
//char* filename = "cn_windows_7_ultimate_with_sp1_x64_dvd_u_677408.iso";
char* filename = NULL;

FILE* pFile;

unsigned int UpdateProc(void* pdata) {


	unsigned int szRd;
	szRd = fread(pdata, 1, 4096 , pFile);
	return szRd;
}



int main() {

	char* md5str[] = { "",
	 "a",
	 "abc",
	 "message digest",
	 "abcdefghijklmnopqrstuvwxyz",
	 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
	 "12345678901234567890123456789012345678901234567890123456789012345678901234567890" ,
	};

	unsigned char outmd5[16] = { 0 };

	for (size_t i = 0; i < 7; i++)
	{
		printf("String : %s \n", md5str[i]);

		EncryptMd5(outmd5, md5str[i], strlen(md5str[i]));

		printf("md5 : ");
		for (int j = 0; j < 16; j++)
		{
			printf("%02X", outmd5[j]);

		}

		printf("\n\n");
	}


	//SHA-1
	char* sha1str = "123456789";

	unsigned char OutSha1[20] = { 0 };

	EncryptSha1(OutSha1, sha1str, strlen(sha1str));

	printf("String : %s \n", sha1str);
	printf("Sha1: ", sha1str);
	for (int j = 0; j < 20; j++)
	{
		printf("%02X", OutSha1[j]);
	}

	printf("\n\n");


	//
	if (filename != NULL)
	{
		pFile = fopen(filename, "rb");
	}
	if (pFile == NULL)return 1;

	EncryptMd5Large(outmd5, UpdateProc);


	printf("Large md5 : ");

	for (int j = 0; j < 16; j++)
	{
		printf("%02X", outmd5[j]);

	}

	printf("\n");
	
	fseek(pFile, 0, SEEK_SET);

	EncryptSha1Large(OutSha1, UpdateProc);

	printf("Large Sha1: ", OutSha1);

	for (int j = 0; j < 20; j++)
	{
		printf("%02X", OutSha1[j]);
	}




	fclose(pFile);



	return 0;

}