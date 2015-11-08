#ifndef _ENCRYPT_DECRYPT_H
#define _ENCRYPT_DECRYPT_H

#include <stdio.h>
#include <string.h>

bool Encrypt(const char szText[],unsigned int nTextLen,char szOutString[],unsigned int nOutLen)
{
	if(nTextLen<=0||nOutLen<nTextLen)
	{
		return false;
	}
	char chLetter;

	int i=0;
	for(;i<nTextLen-1;i++)
	{
		chLetter=szText[i]+i+10;
		szOutString[i]=chLetter;
	}
	szOutString[i]='\0';
	return true;
}

bool Decrypt(const char szText[],unsigned int nTextLen,char szOutString[],unsigned int nOutLen)
{
	if(nTextLen<=0||nOutLen<nTextLen)
	{
		return false;
	}
	char chLetter;

	int i=0;
	for(;i<nTextLen-1;i++)
	{
		chLetter=szText[i]-i-10;
		szOutString[i]=chLetter;
	}
	szOutString[i]='\0';
	return true;
}


#define  THE_STRING_LENGTH			1024
int main()
{
	char SourceString[THE_STRING_LENGTH] = "¡££¬¡¢£»£º£¿£¡¡­¡ª¡¤¡¥¡§0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789¡®¡¯¡°¡±¡©¡«¡¬¡Ã£¢¡Ã£§£à£ü¡¨¡²¡³¡´¡µ¡¶¡·¡¸¡¹¡º¡»£®¡¼¡½¡¾¡¿£¨£©£Û£Ý£û£ý";
	char TargetString[THE_STRING_LENGTH];
	printf("The Source String:%s\r\n", SourceString);

	Encrypt(SourceString, strlen(SourceString)+1, TargetString, strlen(SourceString)+1);
	printf("The Encrypt String:%s\r\n", TargetString);

	memset(SourceString, 0, sizeof(char)*THE_STRING_LENGTH);

	Decrypt(TargetString, strlen(TargetString)+1, SourceString, strlen(TargetString)+1);
	printf("The Decrypt Strng:%s\r\n", SourceString);
	getchar();


	return 0;
}























#endif