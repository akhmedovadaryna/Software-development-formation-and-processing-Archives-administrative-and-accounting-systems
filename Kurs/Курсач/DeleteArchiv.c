#include "DeleteArchiv.h"

//-----------------------------------------------
//Удаление компонента из архива изделий. Просмотр дека слева направо
int DeleteArchive()
{											
int Kod,KodPr;
unsigned char Cond;
DynProduct *L, *R;		// левый и правый указатели дека 
DynProduct  *Del;			// указатель на удаляемый элемент из дека архива
DynProduct  *Run;     // текущий указатель дека архива 
int np;
char Sr[80]="";
  if ( ! SignArchive )
  {
		 printf("\nАрхив не создан. Режим отменяется.\n");
		 wait_press_key("\nДля продолжения нажмите любую клавишу\n");
		 return 1;
	}
  ReadFileOut(&np,&L,&R);
  printf("\nУкажите код удаляемого компонента : ");
  Kod=(int)ceil(GetNumber(0,999999,1,0,6,0));
	Cond=0; KodPr=Kod;
  if ( Kod == L->Inf.Kod)
	{ 
      Cond=1;
      Del=L; L=L->Next;
      free(Del);
	}
  else
	{
		Run=L;
    while ( Run->Next != NULL ) 
    {
      if ( Kod == Run->Next->Inf.Kod )
			{
				Cond=1;
				Del=Run->Next;
				if (Run->Next->Next == NULL )
					{Run->Next=NULL;}
				else
					{Run->Next=Run->Next->Next;}
				free(Del);
				break;
			}
			Run=Run->Next;
		}
	}
  if( Cond == 1 ) 
  {  
    np--;
    WriteFileOut(L);
    printf("\nУдаление компонента из архива закончено");
	}
  else
		printf("\nВ архиве нет компонента с кодом %6d",KodPr);
	wait_press_key("\nДля продолжения нажмите любую клавишу\n");
	return 0;
}         //DeleteArchive
//-----------------------------------------------
