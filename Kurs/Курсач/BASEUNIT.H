#include "desunit.h"
//-----------------------------------------------------------

FILE *fArTxt;
FILE *fArBin;
FILE *fAddTxt;
FILE *fKodif;
FILE *fRes;
KodifType	Kodif,       //��������� ������������
					Kodifs[50];  //������ ����������� ������������

DynProduct *PointerProduct ;
unsigned char SignArchive=0;  //������� �������� ������
int Device;
int nk=0;						            // ���-�� ����������� ������������ 
//----------------------------------------------------------- 
void wait_press_key(char *msg);
void WritelnString(char S[80]);
int Space(char *s, int k);
int NotSpace(char *s, int k);
char *FillString(char *S, unsigned char len, unsigned char pk);
double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2);

void UsesDevice();
int SearchKodif(int Kod, int nk);
void SortKodif(int nk);
