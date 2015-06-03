#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>

using namespace std;

void output(vector<double>&Vector)
{
	assert(value != NULL);
	for (vector<double>::iterator it = Vector.begin(); it != Vector.end(); ++it)
	{
		cout << (round(*it * 1000) / 1000) << " ";
	}
}

void del2max(vector<double>&Vector)
{
	assert(value != NULL);
	double largest = *max_element(Vector.begin(), Vector.end());
	largest /= 2;
	transform(Vector.begin(), Vector.end(), Vector.begin(), bind2nd(divides<double>(), largest));
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Wrong amount of arguments\n");
		return 1;
	}
	int i;
	double temp;
	
	for (i = 1; argv[i] != NULL; i++)
	{
		temp = atof(argv[i]);
		if (!temp)
		{
			printf("Wrong arguments\n");
			return 1;
		}
	}
	
	vector<double>myVector;
	for (i = 1; argv[i] != NULL; i++)
	{
		myVector.push_back(atof(argv[i]));
	}

	del2max(myVector);

	sort(myVector.begin(), myVector.end());

	output(myVector);

	return 0;
}

