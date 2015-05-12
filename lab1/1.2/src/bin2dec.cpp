#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Wrong amount of arguments\n");
		return 1;
	}
	bool err;
	int counter = 0;
	int binary = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not binary number\n");
		return 1;
	}
	int binary2 = binary;
	int digit = 1;
	while (binary2 >= 1 && digit <= 1)
	{
		digit = binary2 % 10;
		binary2 /= 10;
		counter += 1;
	}
	int two = 1;
	int decimal = 0;
	binary2 = binary;
	if (digit > 1)
	{
		printf("It's not binary number!\n");
		return 1;
	}
	else
	{
		while (counter > 0)
		{
			digit = binary2 % 10;
			binary2 /= 10;
			decimal = decimal + digit * two;
			two *= 2;
			counter -= 1;
		}
		cout << decimal << endl;
	}
	return 0;
}
