#include "AddArchiv.h"
//-----------------------------------------------
//���������� ��������� � ����� �������
int AddArchive()
{                      
ProductType Product;
DynProduct *Run;			// ������� ��������� ���� ������ 
DynProduct *L,*R;		// ����� � ������ ��������� ���� 
unsigned char Cond;
int Sr, np;
	if (SignArchive==0)
	{
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 1;
	}
	if((fAddTxt=fopen(fAddTxtName,"rt"))==NULL)
	{
		 printf("\n���� %s �� ������. ����� ����������.\n",fAddTxtName);
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 SignArchive=0;
		 return 1;
	}
	if ( ReadFileOut(&np,&L,&R) == 1) {fclose(fAddTxt); return 1;}
	do
	{  
		if (ReadProduct(fArTxt, &Product)==0)
		{	
			Sr=Product.Kod;
			Run=L; Cond=0;
      while (Run!=NULL) 
			{
				if (Run->Inf.Kod==Product.Kod) 
					{ Cond=1; break;}
				Run=Run->Next;
			}
      if (Cond == 0 ) 
			{
  			Run=(DynProduct *)malloc(sizeof(DynProduct));
	      Run->Inf=Product; 
		  R->Next=Run;
		  Run->Next=NULL;
		  R=Run;
			}
      else
        printf("\n� ������ ��� ���� ������� � ����� %6d",Sr);

		}
	}
	while ( ! feof(fAddTxt) );
	fclose(fAddTxt);

  WriteFileOut(L);
  printf("\n���������� ������ ���������\n");
	wait_press_key("\n��� ����������� ������� ����� �������\n");
	return 0;
}         //End AddArchive 
//-----------------------------------------------
