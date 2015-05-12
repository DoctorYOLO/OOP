#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
       {
             cout << "Not enough arguments" <<endl;
			 return 1;
       } 
	FILE *pFile;
	FILE *pFile1;
	pFile = fopen(argv[1], "rb");
	if (pFile == NULL)
	{
		printf("File opening error\n");
		fclose(pFile);
		pFile = NULL;
		return 1;
	}
	pFile1 = fopen(argv[2], "wt");
	if (pFile1 == NULL)
	{
		printf("File opening error\n");
		fclose(pFile1);
		pFile1 = NULL;
		return 1;
	}
	int ch;
	while ((ch = fgetc(pFile)) != EOF)
	{
		putchar(ch);
		fputc(ch, pFile1);
	}

	fclose(pFile);
	fclose(pFile1);
	pFile = NULL;
	pFile1 = NULL;
	return 0;
}

