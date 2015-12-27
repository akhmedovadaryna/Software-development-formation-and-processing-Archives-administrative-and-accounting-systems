#include "ReportArchiv.h"
// ��������� ������ ������� � ������������ �������
void WorkUpArchive()
{           
unsigned char Kodik;              //{ ����� ���� }
int j,k=-1,m,np;
int Kod;												 //{ ��� ������� }
double	PlanSt1,PlanSt2,PlanGod, //{ ��������� �������� ���������� }
	FactSt1,FactSt2,FactGod, //{ ��������� ����������� ���������� }
		    ProcSt1,ProcSt2,ProcGod, //{ ������� ���������� ����� }
				BufSt;                   //{ �������� ���������� }
char St[80],Sw[80];
DynProduct *Beg;				// ����� � ������ ��������� ���� 
DynProduct *Run;          // ������� ��������� ���� ������ 
  if ( ! SignArchive )
	{
      printf("�������� ���� �� ������. ����� ����������");
      return;
	}
  ReadFileOut(&np,&Beg);
  printf("\n������� ����� ����  ");
  Kodik=(unsigned char)ceil(GetNumber(1,99,1,0,2,0));
  PlanSt1=0; PlanSt2=0;
  FactSt1=0; FactSt2=0;
  k=0; Run=Beg;
  while (Run!=NULL) 
{
    if (Kodik==Run->Inf.Kod)
				{
      k++;
      BufSt=Run->Inf.Data2/Run->Inf.Data1;
      PlanSt1+=BufSt;
      BufSt=Run->Inf.Data4/Run->Inf.Data3;
      PlanSt2+=BufSt;
      BufSt=Run->Inf.Data2/Run->Inf.Data1;
      FactSt1+=BufSt;
      BufSt=Run->Inf.Data4/Run->Inf.Data3;
      FactSt2+=BufSt;
			}
    Run=Run->Next;
	}
  if (k==0)
    printf("� ������ ��� �������� � ���� %d",Kodik);
  else
	{
    PlanGod=PlanSt1+PlanSt2;
    FactGod=FactSt1+FactSt2;
    ProcSt1=100*FactSt1/PlanSt1;
    ProcSt2=100*FactSt2/PlanSt2;
    ProcGod=100*FactGod/PlanGod;
		sprintf(St,"             �������� � ���������� ����� �� ���� ");
		sprintf(Sw,"%2d",Kodik); strcat(St,Sw);
    WritelnString(St);
    WritelnString(" ---------------------------------------------------------------- ");
    WritelnString("|                    |         ���������           |     ��      |");
    WritelnString("|                    |-----------------------------|     ���     |");
    WritelnString("|                    |       1      |      2       |             |");
    WritelnString(" ---------------------------------------------------------------- ");
    sprintf(St,"| ���� �������       |  ");
		sprintf(Sw,"%10.2f",PlanSt1); strcat(St,Sw); strcat(St,"  |  ");
		sprintf(Sw,"%10.2f",PlanSt2); strcat(St,Sw); strcat(St,"  |  ");
 		sprintf(Sw,"%10.2f",PlanGod); strcat(St,Sw); strcat(St," |");
    WritelnString(St);

    sprintf(St,"| ����������� ������ |  ");
		sprintf(Sw,"%10.2f",FactSt1); strcat(St,Sw); strcat(St,"  |  ");
		sprintf(Sw,"%10.2f",FactSt2); strcat(St,Sw); strcat(St,"  |  ");
 		sprintf(Sw,"%10.2f",FactGod); strcat(St,Sw); strcat(St," |");
    WritelnString(St);

    sprintf(St,"| ������� ���������� |  ");
		sprintf(Sw,"%10.2f",ProcSt1); strcat(St,Sw); strcat(St,"  |  ");
		sprintf(Sw,"%10.2f",ProcSt2); strcat(St,Sw); strcat(St,"  |  ");
 		sprintf(Sw,"%10.2f",ProcGod); strcat(St,Sw); strcat(St," |");
    WritelnString(St);

    WritelnString(" ---------------------------------------------------------------- ");
 }
	/*wait_press_key("\n��� ����������� ������� ����� �������\n");

	WritelnString("\n ������ �������, �� ������� �� �������� ������� ���� ������������");
  WritelnString(" --------------------------------------------------------------- ");
  WritelnString("|N �/�|   ���    |       ������������ �������        |����������|");
  WritelnString("|     | �������  |                                   | �����, % |");
  WritelnString(" --------------------------------------------------------------- ");

	j=6; m=0;k=-2;
  Run=Rp;
  while ( Run != NULL)
	{
	  ProcGod=100*(Run->Inf.Fact[0]+Run->Inf.Fact[1])/
                (Run->Inf.Plan[0]+Run->Inf.Plan[1]);
		if (ProcGod<100) 
		{
			m++;
			Kod=Run->Inf.Kod;
	    sprintf(St,"|  ");
			sprintf(Sw,"%2d",m); strcat(St,Sw); strcat(St," |  ");
			sprintf(Sw,"%6d",Kod); strcat(St,Sw); strcat(St,"  | ");
			k=SearchKodif(Kod,nk);
			if (k>-1) 
				sprintf(Sw,"%s",Kodifs[k].Name);
			else
				sprintf(Sw,"                                  ");
	 		strcat(St,Sw); strcat(St,"|");
			sprintf(Sw,"%8.2f",ProcGod); strcat(St,Sw); strcat(St,"  |");

			WritelnString(St);
		}
   Run=Run->Prev;
	}
  WritelnString(" --------------------------------------------------------------- ");*/
	DisposeProduct(Beg);
	printf("\n��������� ������ ���������");

	wait_press_key("\n��� ����������� ������� ����� �������\n");
}      //WorkUpArchive 
