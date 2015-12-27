#include "desunit.h"
//-----------------------------------------------------------
extern unsigned char SignArchive;
//-------------------------------------------------------- 
//baseunit
extern void wait_press_key(char *msg);
extern double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2);
//SortArchive
extern int ReadFileOut(int *np, DynProduct **L, DynProduct **R);
extern int WriteFileOut(DynProduct *L);
extern void DisposeProduct(DynProduct *L);
//-------------------------------------------------------- 
int DeleteArchive();
