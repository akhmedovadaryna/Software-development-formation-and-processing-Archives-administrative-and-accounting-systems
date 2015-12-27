#include "AddArchiv.h"
//-----------------------------------------------
//Добавление компонент в архив изделий
int AddArchive()
{                      
ProductType Product;
DynProduct *Run;			// текущий указатель дека архива 
DynProduct *L,*R;		// левый и правый указатели дека 
unsigned char Cond;
int Sr, np;
	if (SignArchive==0)
	{
		 printf("\nАрхив не создан. Режим отменяется.\n");
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
		 return 1;
	}
	if((fAddTxt=fopen(fAddTxtName,"rt"))==NULL)
	{
		 printf("\nФаил %s не найден. Режим отменяется.\n",fAddTxtName);
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
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
        printf("\nВ архиве уже есть изделие с кодом %6d",Sr);

		}
	}
	while ( ! feof(fAddTxt) );
	fclose(fAddTxt);

  WriteFileOut(L);
  printf("\nДополнение архива закончено\n");
	wait_press_key("\nДля продолжения нажмите любую клавишу\n");
	return 0;
}         //End AddArchive 
//-----------------------------------------------
