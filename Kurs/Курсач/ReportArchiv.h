#include "desunit.h"
//-----------------------------------------------------------
extern unsigned char SignArchive;
extern unsigned char nk;        // кол-во компонентов кодификатора 
extern KodifType	Kodifs[50];  //массив компонентов кодификатора
//----------------------------------------------------------- 
//------------------------------------------------------ 
//baseunit
extern void wait_press_key(char *msg);
extern double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2);
extern void WritelnString(char S[80]);
extern int SearchKodif(int Kod, unsigned char nk);
//SortArchive
extern int ReadFileOut(int *np, DynProduct **Beg);
extern void DisposeProduct(DynProduct *Beg);
//------------------------------------------------------ 
void WorkUpArchive();

