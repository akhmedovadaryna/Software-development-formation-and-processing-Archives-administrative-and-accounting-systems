#include "DeleteArchiv.h"

//-----------------------------------------------
//�������� ���������� �� ������ �������. �������� ���� ����� �������
int DeleteArchive()
{											
int Kod,KodPr;
unsigned char Cond;
DynProduct *L, *R;		// ����� � ������ ��������� ���� 
DynProduct  *Del;			// ��������� �� ��������� ������� �� ���� ������
DynProduct  *Run;     // ������� ��������� ���� ������ 
int np;
char Sr[80]="";
  if ( ! SignArchive )
  {
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 1;
	}
  ReadFileOut(&np,&L,&R);
  printf("\n������� ��� ���������� ���������� : ");
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
    printf("\n�������� ���������� �� ������ ���������");
	}
  else
		printf("\n� ������ ��� ���������� � ����� %6d",KodPr);
	wait_press_key("\n��� ����������� ������� ����� �������\n");
	return 0;
}         //DeleteArchive
//-----------------------------------------------
