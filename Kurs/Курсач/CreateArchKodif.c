#include "CreateArchKodif.h"
//---------------------------------------------
//����������� ������ �� ���������� �����, ������������ �� ������
//� ������������ ��������� Product. ���������� 0
//���� ������ ����� ����� - ���������� 1
int ReadProduct(FILE *f,ProductType *Product)
{
	char sIn[80];
	char slovo[80];
	unsigned char Cond=0;
	int k1,k2,k,i,n;
	if ( fgets(sIn, 80, f) != NULL )
			{	
				k=strlen(sIn);
				if (sIn[k-1]==10) sIn[k-1]='\0';
				i=0; k=0; Cond=1; k2=-1;
				while(Cond)
				{
					k1=NotSpace(sIn,k2+1); //���������� ������� ������ �����
//���� k1>-1, ������� ������ �����, ����� ������ ������ ��� ������������� ���������
					if(k1==-1) Cond = 0;   
					else
					{
						k2=Space(sIn,k1+1);
						if (k2==-1) {k2=strlen(sIn); Cond = 0;}
						n=k2-k1;											//����� �������� �����
						strncpy(slovo,&sIn[k1],n);	//�������� ������� ����� � slovo
						slovo[n]='\0';							//� ��������� ������ '\0'.
						k++;                        //k-����� ���������� �����
						switch ( k )
							{
							 case 1:sscanf_s(slovo,"%d",&Product->Kod);	break;
							 case 2:strncpy(Product->Family,&slovo[0],n);
											Product->Family[n]='\0'; 
											FillString(Product->Family,15,1)	;			break;
							 case 3:strncpy(Product->Adress,&slovo[0],n);
											Product->Adress[n]='\0'; 
											FillString(Product->Adress,20,1);						break;
							 case 4:strncpy(Product->Remont,&slovo[0],n);
											Product->Remont[n]='\0'; 
											FillString(Product->Remont,10,1);			break;
							 case 5:sscanf_s(slovo,"%d",&Product->Data1);		break;
							 case 6:sscanf_s(slovo,"%d",&Product->Data2);		break;
							 case 7:sscanf_s(slovo,"%d",&Product->Data3);		break;
							 case 8:sscanf_s(slovo,"%d",&Product->Data4);		break;
							}
					}
				}
				return 0;
			}
	else return 1;
}
//-----------------------------------------------
//����������� ������ �������� �������� �� ���������� �����
//����������� �������� ���� ������. �� ���������� ����� �����������
//����������� � ������������ � ������. ������ ����������� � �����������
//�� �������� ����������. nk - ���������� ��������� � ������� 
void CreateArchive()
{
	ProductType Product;

	if((fArTxt=fopen(fArTxtName,"rt"))==NULL)
		{
		 printf("\n���� %s �� ������\n",fArTxtName);
		 wait_press_key("\n��� ���������� ��������� ������� ����� �������\n");
		 exit(0);
		}
	if((fArBin=fopen(fArBinName,"wb"))==NULL)
		{
		 printf("\n���� %s �� ������\n",fArTxtName);
		 wait_press_key("\n��� ���������� ��������� ������� ����� �������\n");
		 exit(0);
		}
	do
	{  
		if (ReadProduct(fArTxt,&Product)==0)
			fwrite(&Product,sizeof(ProductType),1,fArBin);
	}
	while ( ! feof(fArTxt) );
	fclose(fArTxt);
	fclose(fArBin);
	MakeKodifs(&nk);
	SortKodif(nk);

	SignArchive=1;
	printf("\n	����� ������\n");
	wait_press_key("\n��� ����������� ������� ����� �������\n");

}
//-----------------------------------------------
//�� ��������� ����� ����������� ����� � ���������� �� ������, � ���� 
int PrintArchive()
{
	ProductType Product;
	int i,p=1;
	char s[80];
	char slovo[80]="";
	if (SignArchive==0)
	{
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 0;
	}
	if((fArBin=fopen(fArBinName,"rb"))==NULL)
	{
		 printf("\n���� %s �� ������. ����� ����������.\n",fArBinName);
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 SignArchive=0;
		 return 0;
	}

	WritelnString("\n              ����� �������� � ����������� ���������");
  WritelnString(" ----------------------------------------------------------------------------");
  WritelnString("|� |    �.�.�    |    �����    |���|     |     ����        |       ����      |");
  WritelnString("|� |             |             |���|     |-----------------|-----------------|");
  WritelnString("|� |             |             |   |     |    1   |   2    |   1    |    2   |");
  WritelnString("|----------------------------------------------------------------------------|");

	i=0;
	if( p=fread(&Product,sizeof(ProductType),1,fArBin)<1) p=EOF;
  while (p!=EOF)
    {
     i++; s[0]='|';s[1]='\0';
		//	sprintf(slovo,"%3d",i);strcat(s,slovo);strcat(s,". ");
			sprintf(slovo,"%2d",Product.Kod);strcat(s,slovo);strcat(s," ");	
			strcat(s,Product.Family);
			strcat(s,Product.Adress);
			sprintf(slovo,"%8d",Product.Data1);strcat(s,slovo);strcat(s," ");	
			sprintf(slovo,"%8d",Product.Data2);strcat(s,slovo);strcat(s," ");	
			sprintf(slovo,"%8d",Product.Data3);strcat(s,slovo);strcat(s," ");	
			sprintf(slovo,"%8d",Product.Data4);strcat(s,slovo);strcat(s,"|");	
		  WritelnString(s);
			if( p=fread(&Product,sizeof(ProductType),1,fArBin)<1) p=EOF;
		}
		WritelnString("|____________________________________________________________________________|\n");
  	fclose(fArBin);
		wait_press_key("\n��� ����������� ������� ����� �������\n");

	return 0;

}
//-----------------------------------------------
// ������ ����� "Kodif.txt" � ������������ ������� Kodifs 
void MakeKodifs(int *nk)
{ 
	char Sa[80],Sb[80];
	unsigned char  n,k,Cond;
	int k1,k2;

	if((fKodif=fopen(fKodifName,"rt"))==NULL)
		{
		 printf("\n���� %s �� ������\n",fArTxtName);
		 wait_press_key("\n��� ���������� ��������� ������� ����� �������\n");
		 exit(0);
		}
  
  *nk=0;
  while (fgets(Sa,80,fKodif)!=NULL) 
	{
		n=strlen(Sa);
		if (Sa[n-1]==10) 	Sa[n-1]='\0'; 
		Cond=1; k2=-1; k=0;
    while (Cond) 
			{
				k1=NotSpace(Sa,k2+1);
				if (k1==-1) Cond=0;
				else
				{
					k2=Space(Sa,k1+1);
					if (k2==-1) { k2=strlen(Sa); Cond=0; }
					k++;
					n=k2-k1;
					strncpy(Sb,&Sa[k1],n);//�������� ������� ����� � Sb
					Sb[n]='\0';            //� ��������� ������ '\0'.
					switch ( k)
					{
						case 1:sscanf_s(Sb,"%d",&Kodif.Kod);	break;
						case 2:strncpy(Kodif.Name,&Sb[0],n);  
									Kodif.Name[n]=' '; Kodif.Name[n+1]='\0'; break;
						case 3:strcat(Kodif.Name,Sb); break;
					}
				}
			}
			k=strlen(Kodif.Name);
			if ( Kodif.Name[k-1]==10 ) Kodif.Name[k-1]='\0';
			FillString(Kodif.Name,15,1);
			Kodifs[*nk]=Kodif;
      (*nk)++;
	}
  fclose(fKodif);
}								// MakeKodifs 
//-----------------------------------------------
// ����� ������������ ������� �� �����, � ���� 
int PrintKodif(int nk)
{
	char s[80];
	char slovo[80]="";
	unsigned char i,j=0;
  if (SignArchive==0)
	{
		 printf("\n����� �� ������. ����� ����������.\n");
		 wait_press_key("\n��� ����������� ������� ����� �������\n");
		 return 0;
	}
  WritelnString("\n                ����������� ����������� ���������");
  WritelnString(" ----------------------------------------- ");
  WritelnString("| N�/� |    ���    |    ����� ��������   |");
  WritelnString(" -----------------------------------------");
  j=0;
  for ( i=0; i<nk; i++ )
	{
		Kodif=Kodifs[i];
      j++; s[0]='|';s[1]='\0';
			sprintf(slovo,"%4d",j);strcat(s,slovo);strcat(s,".   ");
			sprintf(slovo,"%6d",Kodif.Kod);strcat(s,slovo);strcat(s,"          ");	
			strcat(s,Kodif.Name);
			strcat(s,"  |");	
		  WritelnString(s);
	}
  WritelnString(" ----------------------------------------- ");
	wait_press_key("\n��� ����������� ������� ����� �������\n");
	return 0;
}     //PrintKodif 
//-----------------------------------------------
