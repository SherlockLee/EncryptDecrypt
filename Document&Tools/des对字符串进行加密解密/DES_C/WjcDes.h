//////////////////////////////////////////////////////////////////////////
/*
    
*/
//////////////////////////////////////////////////////////////////////////

enum    {ENCRYPT,DECRYPT};
//enum    bool{false,true}; // if bool is not supported,use this or just replace with char
                            // and use 1 for true,0 for false;
//////////////////////////////////////////////////////////////////////////

// Type��ENCRYPT:����,DECRYPT:����
// ���������(Out)�ĳ��� >= ((datalen+7)/8)*8,����datalen�������8�ı�������С������
// In ����= Out,��ʱ��/���ܺ󽫸������뻺����(In)������
// ��keylen>8ʱϵͳ�Զ�ʹ��3��DES��/����,����ʹ�ñ�׼DES��/����.����16�ֽں�ֻȡǰ16�ֽ�

/**************************************************************************
*  ����ԭ�� :	Des_Go(char *Out,char *In,long datalen,const char *Key,int keylen,bool Type = ENCRYPT)
*  ��    �� :	LIUBC
*  ˵    �� :	
*  ������� :	char *Out		        --- ����������ĳ���
				char *In	            --- ���뻺����(In)������
				long datalen	        --- (datalen+7)/8)*8
                const char *Key         ---
                int keylen              --- keylen>8ʱϵͳ�Զ�ʹ��3��DES��/����
                bool Type = ENCRYPT     --- 
*  ������� :	
*  �� �� ֵ :		                    --- 
*  ʹ�÷��� :
					
* -----------------------------------------------------------------*/

bool Des_Go(char *Out,char *In,long datalen,const char *Key,int keylen,bool Type = ENCRYPT);

//////////////////////////////////////////////////////////////////////////

