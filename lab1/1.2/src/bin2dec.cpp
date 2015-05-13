#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Wrong amount of arguments\n");
		return 1;
	}
	char *binary = argv[1];
	char digit;
	int counter;
	int decimal = 0;
	int i;
	int two = 0;
	for (i = 0; i < strlen(binary); i++)
	{
		if ((binary[i] < '0') || (binary[i] > '1'))
		{
			printf("It's not binary number!\n");
			return 1;
		}
		two = two * 2;
		two = two + binary[i] - '0';
	}
	decimal = two;
	printf("%d", decimal);
	return 0;
}
