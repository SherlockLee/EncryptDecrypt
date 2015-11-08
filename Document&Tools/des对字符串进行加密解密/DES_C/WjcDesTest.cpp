// tripple-Des test

#include "WjcDes.h"
#include "stdio.h"
#include "string.h"
#include "memory.h"
/*BCD转换为ascii */
void HEXToDSP(char *strHex, char *strDsp, int nCount)
{
	int i;
	char cTemp;
	for (i = 0; i < nCount; i++)
	{
		cTemp = (strHex[i] &0xf0) >> 4;
		strDsp[i *2] = (cTemp > 9) ? cTemp + 0x41 - 10: cTemp + 0x30;//0X41  'A'  0X30  '0'
		cTemp = strHex[i] &0xf;
		strDsp[i *2+1] = (cTemp > 9) ? cTemp + 0x41 - 10: cTemp + 0x30;
	}
}
/*ascii转换为BCD*/
void DSPToHEX(char *strDsp, char *strHex, int nCount)
{
	int i;
	char cTemp;
	for (i = 0; i < nCount; i++)
	{
		cTemp = strDsp[i *2];
		if (cTemp >= 'A' && cTemp <= 'F')
			cTemp = cTemp - 'A' + 10;
		else if (cTemp >= 'a' && cTemp <= 'f')
			cTemp = cTemp - 'a' + 10;
		else
			cTemp &= 0x0f;
		strHex[i] = cTemp << 4;
		cTemp = strDsp[i *2+1];
		if (cTemp >= 'A' && cTemp <= 'F')
			cTemp = cTemp - 'A' + 10;
		else if (cTemp >= 'a' && cTemp <= 'f')
			cTemp = cTemp - 'a' + 10;
		else
			cTemp &= 0x0f;
		strHex[i] += cTemp;
	}
}
void main()
{
	char buf[255];
	char key[]={"3016745AB289EFCDBADCFE0325476981"};
	char str[]={"020019621200010100000308830000002061023240114210020019621200010100000308830000002061023240114210020019621200010100000308830000002061023240114210020019621200010100000308830000002061023240114210"};
	
	//重置buf 初始化为0
	memset(buf, 0, sizeof(buf));
	strcpy(buf, str);
	puts("\nBefore encrypting");
	puts(buf);
	
	
	//加密
	Des_Go(buf, buf, sizeof(str), key, sizeof(key), ENCRYPT);
	puts("\nAfter encrypting");
	puts(buf);

	
	
	


//解密
Des_Go(buf, buf, sizeof(str), key, sizeof(key), DECRYPT);
puts("\nAfter decrypting");
puts(buf);
getchar();



// 	/*
// 	int i =0;
//     char buf[256],out[256];
//     char key[]={"4A8A86D5FB613851450249CB4A195DDC"};
// 	char str[]={"293E54D39EEAD03880B53897646498CE"};
// 	char strDsp[17],mkey[17];
// 	memset(strDsp,0x00,sizeof(strDsp));
// 
//     DSPToHEX(str, strDsp,16);
// 	DSPToHEX(key, mkey,16);
// 
// 	puts(strDsp);
// 	puts("\n\n");
// /*
// 
// //	strcpy(buf,str);
// 	for (i=0;key[i];i++)
// 	{
// 		printf("%c",key[i]);
// 		printf("%c",key[++i]);
//         printf (" ");
// 	}
// 	puts("\n\n");
// 	for (i=0;str[i];i++)
// 	{
// 		printf("%c",str[i]);
// 		printf("%c",str[++i]);
//         printf (" ");
// 	}
// 		puts("\n\n");
// 	//重置buf 初始化为0
// 	memset(buf, 0x00, sizeof(buf));
// 	memset(out,0x00,sizeof(out));
// 
// 
// 
// 	//加密
// 	Des_Go(out, buf, strlen(str), key, strlen(key),ENCRYPT);
// 
// 	puts("\njia mi  after  \n");
// 
// 	for (i=0;out[i];i++)
// 	{
// 		printf("%c",out[i]);
// 		printf("%c",out[++i]);
//         printf (" ");
//     	
// 	}
// 
// 	memset(buf, 0x00, sizeof(buf));
// 	memset(out,0x00,sizeof(out));
// 	*/
//     //解密
// 	memset(buf,0x00,sizeof(buf));
// //	Des_Go(out, strDsp, strlen(strDsp), mkey, strlen(mkey), DECRYPT);
// 	Des_Go(out, strDsp, 16, mkey, 16, DECRYPT);
//     HEXToDSP(out,buf,16);
// 
//     puts("\n\njie mi  after  \n");
// 
// 	puts(buf);
// 	puts("\n\n");
// 	/*
// 	for (i=0;out[i];i++)
// 	{
// 		printf("%c",out[i]);
// 		printf("%c",out[++i]);
//         printf (" ");
// 		
// 	}
// 	*/
// 	puts("\n\n\n");

}
