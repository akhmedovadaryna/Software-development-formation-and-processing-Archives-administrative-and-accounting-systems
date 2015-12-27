#include "desunit.h"
//-----------------------------------------------------------
extern FILE *fArTxt;
extern FILE *fArBin;
extern FILE *fAddTxt;
extern FILE *fKodif;
extern FILE *fRes;
extern KodifType	Kodif,       //��������� ������������
					Kodifs[180];  //������ ����������� ������������


	typedef char string80[180];
	typedef string80 FileStringAr[200];
  typedef FileStringAr *FileStringArPtr;
  typedef ProductType  ProductAr[200];
  typedef ProductAr *ProductArPtr;
FILE *FileError;          // ���� ��������� �������� }
char *FileErrorName="Error.dat";
//----------------------------------------------------------- 
int const  NfMax = 200;       // ����.���-�� ����� � ��������� ����� 
int 
	 np,                   // ���-�� ����� � ����� FileProductInput }
   nd,                   // ���-�� ����� � ����� FileAddProduct }
   nk,				           // ���-�� ����� � ����� FileKodifProduct }
   FatalError;           // ������� ������ � �������� ������ }

string80	Sr;						 // ��������� �� ������ }
FileStringArPtr Sf;      // ������ ����� ���������� ����� }
//--------------------------------------------------
//baseunit
extern void wait_press_key(char *msg);
extern int Space(char *s, int k);
extern int NotSpace(char *s, int k);
extern void SortKodif(unsigned char nk);
extern char *FillString(char *S, unsigned char len, unsigned char pk);
extern int SearchKodif(int Kod, unsigned char nk);
//--------------------------------------------------
void ReadAndCheckSpaces(FILE *F, char *FileName, int *nf,
												int Nmax);
void FormatFileProduct(FILE *F, char *FileName, int *nf,
												int Nmax, ProductAr *Prod);
void FormatFileKodif();
void ReportError1(char *FileName, int i, int k, int d1,int d2);
void ReportError2(char *FileName, int i, int k, double d1, double d2);
void CheckProdDiapason(char *FileName, int nf, ProductAr *Prod);
void CheckKodifDiapason();
void ProdParameters(ProductAr *Prod, int n, char *FileName);

void KodifParameters();
void ReadFileError();
void CheckFiles();

