#include "desunit.h"
//-----------------------------------------------------------
extern unsigned char SignArchive;
extern DynProduct   *L,*R;      // левый и правый указатели дека 
//----------------------------------------------------------- 
//------------------------------------------------------ 
//baseunit
extern void wait_press_key(char *msg);
extern int Space(char *s, int k);
extern int NotSpace(char *s, int k);
extern char *FillString(char *S, unsigned char len, unsigned char pk);
extern double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2);
//SortArchive
extern int ReadFileOut(int *np, DynProduct **L, DynProduct **R);
extern int WriteFileOut(DynProduct *L);
extern void DisposeProduct(DynProduct *L);

//------------------------------------------------------ 
int ChangeArchive();
void MakeComponent(ProductType *Product);

