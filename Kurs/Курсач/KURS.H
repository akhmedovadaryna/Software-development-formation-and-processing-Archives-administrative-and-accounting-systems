#include "desunit.h"
//-----------------------------------------------------------
extern FILE *fRes;
extern int nk;             // кол-во компонентов кодификатора 
extern unsigned char SignArchive;
extern int Device;

//----------------------------------------------------------- 
//baseunit
extern void wait_press_key(char *msg);
extern void UsesDevice();
extern double GetNumber(double MinNumber, double MaxNumber, 
                   char m1,char n1,char m2,char n2);
//CreateArchKodif
extern void CreateArchive();
extern int SortArchive();
extern int PrintArchive();
extern int PrintKodif(int nk);
extern void CheckFiles();
extern int AddArchive();
extern int DeleteArchive();
extern int ChangeArchive();
extern void WorkUpArchive();
