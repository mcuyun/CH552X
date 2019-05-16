
/********************************** (C) COPYRIGHT *******************************
* File Name          : Main.C
* Author             : WCH
* Version            : V1.0
* Date               : 2017/01/20
* Description        : CH554 DataFlash�ֽڶ�д��ʾʾ��
                       д DataFlash ����������Ŀ���ַд�뵥�ֽ�����
                       �� DataFlash �������򣬴�Ŀ���ַ��ȡ���ֽ�����		   									
*******************************************************************************/

#include "..\Public\CH554.H"                                                   
#include "..\Public\Debug.H"
#include "DataFlash.H"
#include "stdio.h"
#include <string.h>

void main( ) 
{
    UINT8 i,m,len;
    UINT16 j = 0;
    CfgFsys( );                                                                //CH554ʱ��ѡ������   
    mDelaymS(20);
    mInitSTDIO( );                                                             //����0��ʼ��
    printf("start ...\n"); 
    
    while(1){
      for(i=0;i<128;i++){	                                                     //ѭ��д��128�ֽ�		
        len = WriteDataFlash(i,&i,1);                                          //��DataFlash����ƫ�Ƶ�ַiд��i
        if(len != 1){
          printf("Write Err �� = %02x,m = %02x\n",j,(UINT16)m);                //д������ӡ				
        }
      }
      for(i=0;i<128;i++){                                                      //��DataFlash����ƫ�Ƶ�ַi��У��
        len = ReadDataFlash(i,1,&m);
        if((len != 1) ||(m != i)){
          printf("Read Err �� = %02x, = %02x,addr =%02x ,ֵ= %02x\n",j,(UINT16)(i*2),(UINT16)ROM_DATA_L,(UINT16)m);				
        }                                                                      //��У�������ӡ
      }  
      printf("$$OK %02x \n",j);			
      j++;
      mDelaymS(100);			
    }
}