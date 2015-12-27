#include "desunit.h"
//-----------------------------------------------------------
extern FILE *fArBin;
extern unsigned char SignArchive;
//----------------------------------------------------------- 
//-------------------------------------------------------- 
//baseunit
extern void wait_press_key(char *msg);
//-------------------------------------------------------- 
int SortArchive();
int ReadFileOut(int *np, DynProduct **L, DynProduct **R);
int WriteFileOut(DynProduct *L);
void DisposeProduct(DynProduct *L);
//-----------------------------------------------
