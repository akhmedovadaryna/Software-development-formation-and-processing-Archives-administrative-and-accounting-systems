#include "baseunit.h"
//-----------------------------------------------------------
//����� ��������� �� ����� � �������� ������� �������
void wait_press_key(char *msg)
{
	fflush(stdin);
	printf(msg);
	getch();
}
//-----------------------------------------------
//����� ������ S �� �����, � � ����
void WritelnString(char S[80])
{                
  printf("%s\n",S);
	if (Device==1)
   fprintf(fRes,"%s\n",S);
	
}      // WritelnString 
//-----------------------------------------------
//����� � ������ s �������, ������� � ������� k
//������� ���������� -1, ���� ������ �� ������
int Space(char *s, int k)
{ int i=k, pos=-1;
	while(i<strlen(s) && s[i]!=' ')i++;
	if (i<strlen(s)) pos=i;
	return pos;
}
//-----------------------------------------------
//����� � ������ s �������, ��������� �� �������, � ������� k
//������� ���������� -1, ���� ����� ������ �� ������
int NotSpace(char *s, int k)
{ int i=k, pos=-1;
	while(i<strlen(s) && s[i]==' ')i++;
	if (i<strlen(s)) pos=i;
	return pos;
}
//-----------------------------------------------
// ���������� ������ S �� ����� len ��������� ����� 
// (pk=0)  ��� ������ (pk=1) 
char *FillString(char *S, unsigned char len, unsigned char pk)
{
	unsigned char i, n=strlen(S);
	char St[35]="";
	if (S[n-1]==' ') S[n-1]='\0';
	n=strlen(S);
  if (n<len) 
	{
		for (i=1; i<len-n; i++ )
      if (pk==0) 
        strcat(St," ");
      else
				strcat(S," ");
	}
	if (pk==0) {strcat(St,S); strncpy(S,&St[0],strlen(St));}
  return S;
} // FillString 
//-----------------------------------------------
// ���� ����� � ����������; MinNumber,MaxNumber - ���������� 
// ��������; m1,n1,m2,n2 - ������ ��������� � ���������      
double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2)
{
int k;
double Number;
unsigned char Cond=0;
char Format[80]="�� %",s[10]="";
	sprintf(s,"%d",m1);strcat(Format,s);strcat(Format,".");
	sprintf(s,"%d",n1);strcat(Format,s);strcat(Format,"f �� %");
	sprintf(s,"%d",m2);strcat(Format,s);strcat(Format,".");
	sprintf(s,"%d",n2);strcat(Format,s);strcat(Format,"f.");
  do
	{
    Cond=1;
		scanf("%lf",&Number);
		k=0;
    if (k!=0) 
      {
        printf("\n������������ ������ �����");
        printf("\n��������� ����\n");
        Cond=0;
			}
    else
      if ((Number<MinNumber) || (Number>MaxNumber)) 
				{
          printf("����� ������ ���� � ��������� ");
          printf(Format, MinNumber,MaxNumber);
          printf("\n��������� ����\n");
          Cond=0;
				}
	}
	while (Cond==0);
  return Number;
}    //GetNumber
//-----------------------------------------------
//������ �� ���������� ��� ������ ����������� 
void UsesDevice()
{          
  printf("������� ���������� ��� ������ �����������: \n");
  printf("   0 - ������ �����\n");
  printf("   1 - ����� � ��������� ����\n");
  Device=(int)ceil(GetNumber(0,1,1,0,1,0));
}            //UsesDevice 
//-----------------------------------------------
//�������� ����� � ������� ������������ KodifProducts
//�������� � ����� Kod
int SearchKodif(int Kod, int nk)
{ 
int  i1,i2,m;
int SearchKod=-1;
	i1=0; i2=nk-1;
  while (i1<=i2) 
	{
    m=(i1+i2)/2;
    if (Kod==Kodifs[m].Kod)
		{
			SearchKod=m; break;
		}
    else
      if (Kod>Kodifs[m].Kod)
        i1=m+1;
      else
        i2=m-1;
	}
	return SearchKod;
}   // SearchKodif 
//-----------------------------------------------
//-----------------------------------------------
//���������� ������������ "��������" ������� 
//�� ����������� ���� ��������
void SortKodif(int nk)
{ 
  unsigned char i,j;
  int Kod;
  for (i=0; i<nk; i++)
	{
		for (j=0; j<nk; j++)
			if (Kodifs[i].Kod<Kodifs[j].Kod) 
			{
				Kodif=Kodifs[i];
				Kodifs[i]=Kodifs[j];
				Kodifs[j]=Kodif;
			}
		}
}     //SortKodif 
