#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h> 
#include<windows.h>

#define fArTxtName "input.txt"
#define fArBinName "arhiv.bin"
#define fAddTxtName  "add.txt"
#define fResName     "res.txt"
#define fKodifName "kodif.txt"

typedef struct  {			
										
										int		Kod ;
										char	Family[15] ;   // ���
										char    Adress[15];
										char	Remont[10]; 
										int     Data1;
										int     Data2;
										int     Data3; 
										int     Data4; 
									
										} ProductType;

typedef struct  {     //��� ���������� ������������ ������� 
      int  Kod;								// ��� ������� 
      char Name[15];					 
			} KodifType;// ������������ �������

typedef struct DynProd { 
        ProductType  Inf;
        struct DynProd *Next;
									} DynProduct;
