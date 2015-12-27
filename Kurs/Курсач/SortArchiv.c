#include "SortArchiv.h"
//-----------------------------------------------
//���������� ������ �� ����������� ���� �������. �������� ���� 
//� ����� ������� � ���������� �� �������� "��������" �������. 
//��� ��������� ���� � ������ ������� ���������� ����� �� �����������
int SortArchive()
{							
int np,i,j;
ProductType Product;
DynProduct *Runi;
DynProduct *Runj;				// ������� ��������� ���� ������ 
DynProduct *L,*R;			// ����� � ������ ��������� ���� 
  if ( ! SignArchive )
  {
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 1;
	}
  
	
	ReadFileOut(&np,&L,&R);
	
	
	for ( Runi=L; Runi!=NULL; Runi=Runi->Next )
		for ( Runj=L; Runj!=NULL; Runj=Runj->Next )
			if ( Runi->Inf.Kod < Runj->Inf.Kod )
			{
        Product=Runi->Inf; Runi->Inf=Runj->Inf;
          Runj->Inf=Product;
			}
	WriteFileOut(L);
	
	printf("\n���������� ������ ���������.\n");
	wait_press_key("\n��� ����������� ������� ����� �������\n");
	return 0;
	
}            //SortArchive
//-----------------------------------------------
//������ �� ��������� ����� ������ � ������������ ���� ������� 
//��������� ��������� � ��� ������������ � ����� ������� 
int ReadFileOut(int *np, DynProduct **L, DynProduct **R)//, DynProduct **Rp)
{            
	ProductType Product;
	DynProduct *Run;								// ������� ��������� ���� ������ 
	int p;
	if (SignArchive==0)
	{
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 1;
	}
	if((fArBin=fopen(fArBinName,"rb"))==NULL)
	{
		 printf("\n���� %s �� ������. ����� ����������.\n",fArBinName);
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 SignArchive=0;
		 return 1;
	}
  *np=0;
  *L = NULL; *R=NULL;
 	if( p=fread(&Product,sizeof(ProductType),1,fArBin)<1) p=EOF;
  while (p!=EOF)
	{
			Run=(DynProduct *)malloc(sizeof(DynProduct));
			(*np)++;
      Run->Inf=Product;         
	  Run->Next=*L;
	  *L=Run;
	  if (*R==NULL)
		  *R=*L;
	  
	   

	  

	  	if( p=fread(&Product,sizeof(ProductType),1,fArBin)<1) p=EOF;
	}
  fclose(fArBin);
  return 0;
	return 0;
}   //ReadFileOut 
//-----------------------------------------------
//��������� ������� �� ���� � �������� ���� ������
//�������� � ������ ������� � ����������� ��������� ���� 
int WriteFileOut(DynProduct *L)
{           
	ProductType Product;
	DynProduct *Run;								// ������� ��������� ���� ������ 
	if((fArBin=fopen(fArBinName,"wb"))==NULL)
		{
		 printf("\n���� %s �� ������\n",fArBinName);
		 wait_press_key("\n��� ���������� ��������� ������� ����� �������\n");
		 exit(0);
		}
  Run=L;
  while ( Run != NULL)
	{
			Product=Run->Inf;
      fwrite(&Product,sizeof(ProductType),1,fArBin);
	  Run=Run->Next;
	} 
  fclose(fArBin);
  DisposeProduct(L);
	return 0;
}     //WriteFileOut 
//-----------------------------------------------
//�������� ���� ������� � ������ ������� 
void DisposeProduct(DynProduct *L)
{            
	DynProduct *Run;								// ������� ��������� ���� ������ 
  while (L != NULL)
  {
      Run=L;
	  L=L->Next;
      free(Run);
	}
}           //DisposeProduct 
//-----------------------------------------------


