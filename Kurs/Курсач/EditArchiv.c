#include "EditArchiv.h"
//-----------------------------------------------
// ��������� ���������� � ������ ������� 
// �������� ���� ������ ������
int ChangeArchive()
{            
int Kod,Kod1,np;
unsigned char Cond=0;
ProductType Product;
DynProduct *L,*R;				// ����� � ������ ��������� ������� 
DynProduct *Run;         // ������� ��������� ������� ������ 
  if ( ! SignArchive )
  {
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 1;
	}
  ReadFileOut(&np,&L,&R);
  printf("\n������� ��� ������� ����������� ���������� :");
  Kod=(int)ceil(GetNumber(0,999999,1,0,6,0));
  Kod1=Kod; printf("Kod = %2d",Kod1);
	Run=L; Cond=0;
  while (Run!=NULL)
  {
      if (Kod==Run->Inf.Kod)
			{
          Cond=1;
          Product=Run->Inf;
          printf("\n          ������� ��������� ��������� :\n");
					printf("           ����-1    ����-2    ����-1    ����-2\n");
          MakeComponent(&Product);
          Run->Inf=Product;
          WriteFileOut(L);
          printf("��������� ���������� � ������ ���������\n");
          break;
			} 
      Run=Run->Next;
	}
  if (! Cond )
    printf("\n� ������ ��� ���������� � ����� %d\n",Kod1);
	wait_press_key("\n��� ����������� ������� ����� �������\n");
	return 0;
}				//�hangeArchive 
//-----------------------------------------------
// ������������ ����������� ���������� 
void MakeComponent(ProductType *Product)
{                    
unsigned char k,n,Cond;
int k1,k2;
char Sa[80],Sb[80];
			printf("���.��.   %8d  %8d  %8d  %8d\n",
							Product->Data1,Product->Data2,Product->Data3,Product->Data4);
			fflush(stdin);
      gets(Sa);
      Cond=1; k2=-1; k=0;
      while (Cond==1)
      {
				k1=NotSpace(Sa,k2+1);
        if (k1==-1) Cond=0;
        else
        {  
          k2=Space(Sa,k1+1);
					if (k2==-1) { k2=strlen(Sa)+1; Cond=0; }
          k++; n=k2-k1;
					strncpy(Sb,&Sa[k1],n);//�������� ������� ����� � Sb
					Sb[n]='\0';            //� ��������� ������ '\0'.
          switch ( k )
					{
					 case 1:sscanf_s(Sb,"%d",&Product->Data1);		break;
					 case 2:sscanf_s(Sb,"%d",&Product->Data2);		break;
					 case 3:sscanf_s(Sb,"%d",&Product->Data3);		break;
					 case 4:sscanf_s(Sb,"%d",&Product->Data4);		break;

           
					}
				}
			}
}      // MakeComponent
//-----------------------------------------------
