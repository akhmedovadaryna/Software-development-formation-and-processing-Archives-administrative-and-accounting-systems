#include "baseunit.h"
//-----------------------------------------------------------
//Вывод сообщения на экран и ожидание нажатия клавиши
void wait_press_key(char *msg)
{
	fflush(stdin);
	printf(msg);
	getch();
}
//-----------------------------------------------
//Вывод строки S на экран, и в файл
void WritelnString(char S[80])
{                
  printf("%s\n",S);
	if (Device==1)
   fprintf(fRes,"%s\n",S);
	
}      // WritelnString 
//-----------------------------------------------
//Поиск в строке s пробела, начиная с позиции k
//Функция возвращает -1, если пробел не найден
int Space(char *s, int k)
{ int i=k, pos=-1;
	while(i<strlen(s) && s[i]!=' ')i++;
	if (i<strlen(s)) pos=i;
	return pos;
}
//-----------------------------------------------
//Поиск в строке s символа, отличного от пробела, с позиции k
//Функция возвращает -1, если такой символ не найден
int NotSpace(char *s, int k)
{ int i=k, pos=-1;
	while(i<strlen(s) && s[i]==' ')i++;
	if (i<strlen(s)) pos=i;
	return pos;
}
//-----------------------------------------------
// Дополнение строки S до длины len пробелами слева 
// (pk=0)  или справа (pk=1) 
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
// Ввод числа с клавиатуры; MinNumber,MaxNumber - допустимый 
// диапазон; m1,n1,m2,n2 - формат сообщения о диапазоне      
double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2)
{
int k;
double Number;
unsigned char Cond=0;
char Format[80]="от %",s[10]="";
	sprintf(s,"%d",m1);strcat(Format,s);strcat(Format,".");
	sprintf(s,"%d",n1);strcat(Format,s);strcat(Format,"f до %");
	sprintf(s,"%d",m2);strcat(Format,s);strcat(Format,".");
	sprintf(s,"%d",n2);strcat(Format,s);strcat(Format,"f.");
  do
	{
    Cond=1;
		scanf("%lf",&Number);
		k=0;
    if (k!=0) 
      {
        printf("\nНеправильный формат числа");
        printf("\nПовторите ввод\n");
        Cond=0;
			}
    else
      if ((Number<MinNumber) || (Number>MaxNumber)) 
				{
          printf("Число должно быть в диапазоне ");
          printf(Format, MinNumber,MaxNumber);
          printf("\nПовторите ввод\n");
          Cond=0;
				}
	}
	while (Cond==0);
  return Number;
}    //GetNumber
//-----------------------------------------------
//Запрос об устройстве для вывода результатов 
void UsesDevice()
{          
  printf("Укажите устройство для вывода результатов: \n");
  printf("   0 - только экран\n");
  printf("   1 - экран и текстовый файл\n");
  Device=(int)ceil(GetNumber(0,1,1,0,1,0));
}            //UsesDevice 
//-----------------------------------------------
//Двоичный поиск в массиве кодификатора KodifProducts
//элемента с кодом Kod
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
//Сортировка кодификатора "школьным" методом 
//по возрастанию кода продукта
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
