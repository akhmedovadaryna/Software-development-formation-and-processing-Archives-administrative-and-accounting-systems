#include "desunit.h"
//-----------------------------------------------------------
extern FILE *fArTxt;
extern FILE *fArBin;
extern FILE *fAddTxt;
extern FILE *fKodif;
extern FILE *fRes;
extern unsigned char SignArchive;
extern KodifType	Kodif,        //компонент кодификатора
					Kodifs[50];						//массив компонентов кодификатора
extern int nk;									// кол-во компонентов кодификатора 
//----------------------------------------------------------- 
//baseunit
extern void wait_press_key(char *msg);
extern int Space(char *s, int k);
extern int NotSpace(char *s, int k);
extern char *FillString(char *S, unsigned char len, unsigned char pk);
extern void WritelnString(char S[80]);
extern void SortKodif(int nk);
//----------------------------------------------------------- 
int ReadProduct(FILE *f, ProductType *Product);
void CreateArchive();
int PrintArchive();
void MakeKodifs(int *nk);

int PrintKodif(int nk);
