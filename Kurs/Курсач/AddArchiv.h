#include "desunit.h"

//-----------------------------------------------------------
extern FILE *fArTxt;
extern FILE *fAddTxt;
extern unsigned char SignArchive;
extern DynProduct *Beg;
//----------------------------------------------------------- 
//Baseunit
extern void wait_press_key(char *msg);
//SortArchive
extern int ReadFileOut(int *np, DynProduct **L, DynProduct **R);
extern int WriteFileOut(DynProduct *L);
extern void DisposeProduct(DynProduct *L);
//CreateArchKodif
extern int ReadProduct(FILE *f, ProductType *Product);
//-------------------------------------------------------- 
int AddArchive();
