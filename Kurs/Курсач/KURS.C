#include "kurs.h"
//-----------------------------------------------------------
int main()
{	
	int KeyRegime;									// ключ выбора режима работы

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);      

	UsesDevice();
  if (Device==1)
		if((fRes=fopen(fResName,"wt"))==NULL)
		{
		 printf("\nФаил %s не создан\n",fResName);
		 wait_press_key("\nДля завершения программы нажмите любую клавишу\n");
		 exit(0);
		}


	SignArchive=0;
  do
	{
    printf("\n      Укажите режим работы программы:");
    printf("\n      0 - конец работы;");
    printf("\n      1 - контроль текстовых файлов;");
    printf("\n      2 - создание архива изделий;");
    printf("\n      3 - сортировка компонент архива;");
    printf("\n      4 - печать архива изделий;");
    printf("\n      5 - печать кодификатора изделий;");
    printf("\n      6 - добавление компонент в архив;");
    printf("\n      7 - удаление компоненты из архива;");
    printf("\n      8 - изменение компоненты в архиве;");
    printf("\n      9 - обработка архива \n");
    fflush(stdin);
	  KeyRegime=(int)ceil(GetNumber(0,9,1,0,1,0));
		switch (KeyRegime) 
    {
			case 0 : ;                 break;
			case 1 : CheckFiles();		 break;
			case 2 : CreateArchive();   break;
	        case 3 : SortArchive();    break;
			case 4 : PrintArchive();    break;
			case 5 : PrintKodif(nk);   break;
	    	case 6 : AddArchive();     break;
			case 7 : DeleteArchive();  break;
			case 8 : ChangeArchive();  break;
			case 9 : WorkUpArchive();	 break;

		}
	} 
  while (KeyRegime!=0);
  if (Device==1)
    fclose(fRes);


wait_press_key("\n	Выход");
	return 0;
}

