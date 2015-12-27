
#include "CheckInpFile.h"

//-------------------------------------------------------------------------}
//Проверка форматов файлов "input.txt" и "add.txt"
void FormatFileProduct(FILE *F, char *FileName, int *nf,
                           int Nmax, ProductAr *Prod)
{       
	ProductType Product;
	char  k,k1,k2,n,Cond;
	char *p;
	int  i,Code;
	string80 Sa,Sb;

	ReadAndCheckSpaces(F,FileName,nf,Nmax);
  if (FatalError) return;
  for (i=0; i<(*nf); i++)
	{
    strcpy(Sa,(*Sf)[i]);
		k=strlen(Sa);
		if (Sa[k-1]==10) Sa[k-1]='\0';
    Cond=1; k2=-1; k=0;
    while (Cond)
		{
      k1=NotSpace(Sa,k2+1);
      if (k1==-1)
        Cond=0;
      else
			{
        k2=Space(Sa,k1+1);
        if (k2==-1) { k2=strlen(Sa)+1; Cond=0; }
        k++;
        if (k>8)
				{
          FatalError=1;
          sprintf(Sr,"Файл %s : в строке %d свыше 8 элементов\n",FileName,i+1);
          fwrite(Sr,sizeof(string80),1,FileError);
				}
				n=k2-k1;								//длина текущего слова
				strncpy(Sb,&Sa[k1],n);//копируем текущее слово в Sb
				Sb[n]='\0';           //и добавляем символ '\0'.
        switch (k) 
				{
		          case 1: Product.Kod=strtol(Sb,&p,10);  break;
				  case 2:
                if (strlen(Sb)>15)
								{ FatalError=1;
									sprintf(Sr,
										"Файл %s : в строке %d  длина элемента 3 свыше 15 символов\n",
										FileName,i+1);
				          fwrite(Sr,sizeof(string80),1,FileError);
								}
								strncpy(Product.Family,&Sb[0],n);
								Product.Family[n]='\0'; 
								FillString(Product.Family,15,1);								break;
					case 3: if (strlen(Sb)>15)
								{ FatalError=1;
									sprintf(Sr,
										"Файл %s : в строке %d  длина элемента 3 свыше 20 символов\n",
										FileName,i+1);
				          fwrite(Sr,sizeof(string80),1,FileError);
								}
								strncpy(Product.Adress,&Sb[0],n);
								Product.Adress[n]='\0'; 
								FillString(Product.Adress,15,1);								break;
					case 4:  if (strlen(Sb)>10)
								{ FatalError=1;
									sprintf(Sr,
										"Файл %s : в строке %d  длина элемента 4 свыше 20 символов\n",
										FileName,i+1);
				          fwrite(Sr,sizeof(string80),1,FileError);
								}
								strncpy(Product.Remont,&Sb[0],n);
								Product.Remont[n]='\0'; 
								FillString(Product.Remont,10,1);		break;
					case 5:Product.Data1=strtol(Sb,&p,10);         		break;
					case 6:Product.Data2=strtol(Sb,&p,10);    	        break;
					case 7:Product.Data3=strtol(Sb,&p,10);  	        break;
					case 8:Product.Data4=strtol(Sb,&p,10);  	        break;
				}
		if((*p)&&((k==5) || (k==6) || (k==7)|| (k==8)|| (k==1)))
			{
				FatalError=1;
          sprintf(Sr,
						"Файл %s : в строке %d неправильный формат элемента %d (%s)\n",
						FileName,i+1,k,Sb);
          fwrite(Sr,sizeof(string80),1,FileError);
				}
			}
		}
    if (k<8)
		{
      FatalError=1;
     sprintf(Sr,"Файл %s : в строке %d меньше 8 элементов\n",FileName,i+1);
     fwrite(Sr,sizeof(string80),1,FileError);
		}
    (*Prod)[i]=Product;
	}
}   // FormatFileProduct };
//-------------------------------------------------------------------------
//Проверка наличия и ввод текстового файла, контроль количества
//строк, и удаление в нем пустых строк 
void ReadAndCheckSpaces(FILE *F, char *FileName, int *nf,
                            int Nmax)
{
	char  i,j,k;
	char  SignSpace;      //{ признак пустой строки в файле }
	string80 sw;
//{ Проверка наличия файла F с именем FileName }
	if((F=fopen(FileName,"rt"))==NULL)
		{
		 sprintf(Sr,"Отсутствует исходный файл %s\n",FileName);
		 FatalError=1;
		 fwrite(Sr,sizeof(string80),1,FileError);
		 return;
		}

//{ Чтение текстового файла }
  *nf=0;
  while (fgets(sw,80,F)!=NULL) 
	{
		if ((*nf)<200)
			strcpy((*Sf)[*nf],sw);
		(*nf)++;
	}
  fclose(F);


//{ Проверка: является ли файл F пустым }
  if (*nf==0) 
	{
     FatalError=1;
     sprintf(Sr,"Исходный файл  %s   пустой\n",FileName);
		 fwrite(Sr,sizeof(string80),1,FileError);
     return;
	}

//{ Проверка: превышает ли кол-во строк макс.значение }
  if (*nf>NfMax)
	{
      FatalError=1;
			sprintf(Sr,"В исходном файле  %s  свыше  %d  строк (%d)\n",FileName,NfMax,*nf);
			fwrite(Sr,sizeof(string80),1,FileError);
      return;
	}

//{ Удаление пустых строк из состава файла F }
  SignSpace=0;
  i=0;
  while (i<(*nf))
	{
      k=NotSpace((*Sf)[i],0);
      if ((k==-1) || ((*Sf)[i][k]==10))
			{
          for (j=i; j<(*nf)-1; j++)
            strcpy((*Sf)[j],(*Sf)[j+1]);
          (*nf)--;
          SignSpace=1;
			}
      else
        i++;
	}
  if (SignSpace)
	{
		if((F=fopen(FileName,"wt"))==NULL)
		{
		 sprintf(Sr,"Не удалось создать файл %s для удаления пустых строк\n",FileName);
		 FatalError=1;
		 fwrite(Sr,sizeof(string80),1,FileError);
		 return;
		}
    for (i=0; i<(*nf);i++)
		 fputs((*Sf)[i],F);
    fclose(F);
	}

}     // ReadAndCheckSpaces };
//-------------------------------------------------------------------------}
//Проверка форматов файла "Kodif.txt"
void  FormatFileKodif()
{              
	char k,k1,k2,n,Cond;
	int i, Code;
  string80 Sa,Sb,S1;
	
	ReadAndCheckSpaces(fKodif,fKodifName,&nk,NfMax);
  if (FatalError) return;
  for (i=0; i<nk; i++)
	{
    strcpy(Sa,(*Sf)[i]);
 		k=strlen(Sa);
		if (Sa[k-1]==10) Sa[k-1]='\0';
    Cond=1; k2=-1; k=0;
    while (Cond)
		{
      k1=NotSpace(Sa,k2+1);
      if (k1==-1) Cond=0;
      else
			{
        k2=Space(Sa,k1+1);
				if (k2==-1) {k2=strlen(Sa)+1; Cond=0;}
        k++;
        if (k>3) 
				{
          FatalError=1;
					sprintf(Sr,"Файл Kodif.txt : в строке %d свыше 2 элементов\n",i+1);
          fwrite(Sr,sizeof(string80),1,FileError);
				}
				n=k2-k1;							//длина текущего слова
				strncpy(Sb,&Sa[k1],n);//копируем текущее слово в Sb
				Sb[n]='\0';           //и добавляем символ '\0'.
        switch (k)
				{
				  case 1:Code=sscanf_s(Sb,"%d",&Kodif.Kod);	
           if (Code<1)
						{
              FatalError=1;
		          sprintf(Sr,
					    "Файл Kodif.txt : в строке %d неправильный формат элемента 1 (%s)\n",
								i+1,Sb);
		          fwrite(Sr,sizeof(string80),1,FileError);
						}																						break;
          case 2: 
            if (strlen(Sb)>35) 
						{
              FatalError=1;
							sprintf(Sr,
							"Файл Kodif.txt : в строке %d длина элемента 2 свыше 35 символов\n",
								i+1);
							fwrite(Sr,sizeof(string80),1,FileError);
						}
						strncpy(Kodif.Name,&Sb[0],n);   //strlen(Sb)); 
									Kodif.Name[n]=' '; Kodif.Name[n+1]='\0'; break;
						
          case 3: sprintf(S1,"%s%s%s",Kodif.Name," ",Sb);
            if (strlen(S1)>35)
						{
              FatalError=1;
							sprintf(Sr,
							"Файл Kodif.txt : в строке %d длина элемента 2 свыше 35 символов\n",
								i+1);
							fwrite(Sr,sizeof(string80),1,FileError);
						}
            strcpy(Kodif.Name,S1); FillString(Kodif.Name,35,1); break;
				}
			}
		}
    if (k<2)
		{
      FatalError=1;
			sprintf(Sr,"Файл Kodif.txt : в строке %d меньше 2 элементов\n",i+1);
      fwrite(Sr,sizeof(string80),1,FileError);
		}
     
    Kodifs[i]=Kodif;
	}
}   // FormatFileKodif };
//{-------------------------------------------------------------------------}
//Проверка параметров записей в файлах "input.txt" и "add.txt"
void ProdParameters(ProductAr *Prod, int n, char *FileName)
{     
	const char Measurs[2][5] = {{"шт. "},{"кг  "}};
int  i,j,k,Kod,Cond;
char Meas[5];
//{ Проверка дублирования параметра KodProduct }
  for (i=0; i<n-1; i++)
	{
    Kod=(*Prod)[i].Kod;
    for (j=i+1; j<n; j++)
      if (Kod==(*Prod)[j].Kod)
			{
        FatalError=1;
				sprintf(Sr,
					"Файл %s : равные значения KodProduct в строках %d и %d (%d)\n",
					FileName,i+1,j+1,Kod);
				fwrite(Sr,sizeof(string80),1,FileError);
			}
	}

// { Проверка наличия параметра KodProduct в кодификаторе }
  for (i=0; i<n; i++)
	{
    Kod=(*Prod)[i].Kod;
    k=SearchKodif(Kod,nk);
    if (k==-1) 
		{
      FatalError=1;
			sprintf(Sr,
					"Файл %s : код изделия %d (строка %d) отсутствует в кодификаторе\n",
					FileName,Kod,i+1);
			fwrite(Sr,sizeof(string80),1,FileError);
		}
	}

//{ Проверка единиц размерности }
/*  for (i=0; i<n; i++)
	{
    strcpy(Meas,(*Prod)[i].Family);
    Cond=0;
    for (j=0; j<2; j++)
      if (strcmp(Meas,Measurs[j])==0)
        Cond=1;
    if (! Cond) 
		{
      FatalError=1;
			sprintf(Sr,
					"Файл %s : в строке %d неправильная ед.разм. (%s) \n",
					FileName,i+1,Meas);
			fwrite(Sr,sizeof(string80),1,FileError);
		}
	}*/

}  //  End { ProdParameters };
//{-------------------------------------------------------------------------}
//Проверка дублирования параметра KodProduct в файле "Kodif.txt"
void KodifParameters()
{          
int  i,j,Kod;
  for (i=0; i<nk-1; i++)
	{
    Kod=Kodifs[i].Kod;
    for (j=i+1; j<nk; j++)
      if (Kod==Kodifs[j].Kod)
			{
        FatalError=1;
				sprintf(Sr,
				"Файл Kodif.txt: равные значения KodProduct в строках %d и %d (%d)\n",
				i+1,j+1,Kod);
				fwrite(Sr,sizeof(string80),1,FileError);
			}
	}
}    //End { KodifParameters };
//{-------------------------------------------------------------------------}
//Чтение и вывод на экран протокола контроля текстовых файлов 
void ReadFileError()
{             
	char i=1;
  rewind(FileError);
	while (i!=EOF)	
	{
		i=fread(Sr,sizeof(string80),1,FileError);
			if (i<1) i = EOF;
			else printf("%s",Sr);
	}
	wait_press_key("\nДля продолжения нажмите любую клавишу\n");
}                //ReadFileError 

void CheckFiles()
{			

ProductArPtr   Products,
							 AddProducts;

	SetConsoleOutputCP(1251);//Использует для вывода кодовую таблицу 1251
	SetConsoleCP(1251);  
	if((FileError=fopen(FileErrorName,"wb+"))==NULL)
		{
		 printf("\nФаил %s не найден\n",FileErrorName);
		 wait_press_key("\nДля завершения программы нажмите любую клавишу\n");
		 exit(0);
		}

	sprintf(Sr,"\n         ПРОТОКОЛ КОНТРОЛЯ ТЕКСТОВЫХ ФАЙЛОВ\n");
	fwrite(Sr,sizeof(string80),1,FileError);
  FatalError=0;
	Sf=(FileStringAr *)malloc(sizeof(FileStringAr));  
  Products=(ProductAr *)malloc(sizeof(ProductAr));  
	AddProducts=(ProductAr *)malloc(sizeof(ProductAr));  
    
	FormatFileProduct(fArTxt,fArTxtName,&np,NfMax,
                    Products);
  FormatFileProduct(fAddTxt,fAddTxtName,&nd,NfMax,
                    AddProducts);
  FormatFileKodif();
/*  if (FatalError==0)
	{
    CheckProdDiapason(fArTxtName,np,Products);
    CheckProdDiapason(fAddTxtName,nd,AddProducts);
    CheckKodifDiapason();
	}
*/
  if (! FatalError)
	{
		KodifParameters();
		SortKodif(nk);
    ProdParameters(Products,np,fArTxtName);
    ProdParameters(AddProducts,nd,fAddTxtName);
    
	}
	if (FatalError)
    sprintf(Sr,"\nСкорректируйте исходные файлы\n");
  else
    sprintf(Sr,"\nВ исходных файлах ошибок не обнаружено\n");
	fwrite(Sr,sizeof(string80),1,FileError);

	ReadFileError();
  free(Sf); Sf=NULL;
  free(Products);    Products=NULL;
  free(AddProducts); AddProducts=NULL;
  fclose(FileError);
}             // CheckFiles
