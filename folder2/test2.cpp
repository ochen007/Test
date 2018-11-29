#include <iostream>
#include <cstring>
#include <ctime>
#include <direct.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <io.h>
#include <stdio.h>

using namespace std;
 
int  main()
{
  //файл, куда будет выводится инфа
	FILE* rslt = _fsopen("E:\\TEST\\rslt.txt", "w", _SH_DENYNO);
  	for(int i = 0; i < 1000; i ++)
	{
		//лепим имя файла
		char fp[256] = {0};

		if (i < 9)
			strcpy_s(fp,256,"E:\\TEST\\det\\Untitled00");
		else if (i < 99)
			strcpy_s(fp,256,"E:\\TEST\\det\\Untitled0");
		else
			strcpy_s(fp,256,"E:\\TEST\\det\\Untitled");


		char buf[256] = {0};
		_itoa_s(i+1, buf, 256, 10);
		strcat_s(fp,256,buf);
		strcat_s(fp,256,".pdf\0");
		//на выходе имеем путь к файлу вида "E:\\TEST\\det\\Untitled001.pdf"
		
		//открываем файл
		FILE* fn = _fsopen(fp, "r", _SH_DENYNO);
		
		//пытаемся определить его объём - количество символов файла
		int a = _fileno(fn); //именно тут происходим какая-то ошибка с памятью
		long size = _filelength(_fileno(fn));
		
                //переводим все содержимое файла в буфер
		char* buffer = new char [size];
		fgets(buffer, size, _fsopen(fp, "r", _SH_DENYNO));
		
		for (int j = 0; j < 1000; j ++)
		{
			//формируем искомую подстроку
			char numb[10] = {0};
			_itoa_s(j+1, numb, 256, 10);
			char name[256] = {0};
			strcat_s(name, 256, "I-А-");
			strcat_s(name, 256, numb);
			//на выходе имеем строку вида "I-А-1"

			//находим вхождение искомой строки в буфферном массиве и если есть - записываем в файл соответствие 
			if (strstr(buffer, name) != NULL)
			{
				char temp[256] = {0};
				strcat_s(temp, 256, name);
				strcat_s(temp, 256, "\t");
				strcat_s(temp, 256, fp);
				fputs(temp, rslt);
			}
		}
		fclose(fn);
	}
	_fcloseall();
  return 0;
}

