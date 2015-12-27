#include "SortArchiv.h"
//-----------------------------------------------
//Сортировка архива по возрастанию кода изделия. Просмотр дека 
//с левой стороны и сортировка по убыванию "школьным" методом. 
//При просмотре дека с правой стороны сортировка будет по возрастанию
int SortArchive()
{							
int np,i,j;
ProductType Product;
DynProduct *Runi;
DynProduct *Runj;				// текущие указатели дека архива 
DynProduct *L,*R;			// левый и правый указатели дека 
  if ( ! SignArchive )
  {
		 printf("\nАрхив не создан. Режим отменяется.\n");
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
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
	
	printf("\nСортировка архива закончена.\n");
	wait_press_key("\nДля продолжения нажмите любую клавишу\n");
	return 0;
	
}            //SortArchive
//-----------------------------------------------
//Чтение из бинарного файла архива и формирование дека записей 
//Включение элементов в дек производится с левой стороны 
int ReadFileOut(int *np, DynProduct **L, DynProduct **R)//, DynProduct **Rp)
{            
	ProductType Product;
	DynProduct *Run;								// текущий указатель дека архива 
	int p;
	if (SignArchive==0)
	{
		 printf("\nАрхив не создан. Режим отменяется.\n");
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
		 return 1;
	}
	if((fArBin=fopen(fArBinName,"rb"))==NULL)
	{
		 printf("\nФаил %s не найден. Режим отменяется.\n",fArBinName);
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
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
//Пересылка записей из дека в бинарный файл архива
//Просмотр с правой стороны с последующим удалением дека 
int WriteFileOut(DynProduct *L)
{           
	ProductType Product;
	DynProduct *Run;								// текущий указатель дека архива 
	if((fArBin=fopen(fArBinName,"wb"))==NULL)
		{
		 printf("\nФаил %s не создан\n",fArBinName);
		 wait_press_key("\nДля завершения программы нажмите любую клавишу\n");
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
//Удаление дека изделий с правой стороны 
void DisposeProduct(DynProduct *L)
{            
	DynProduct *Run;								// текущий указатель дека архива 
  while (L != NULL)
  {
      Run=L;
	  L=L->Next;
      free(Run);
	}
}           //DisposeProduct 
//-----------------------------------------------


