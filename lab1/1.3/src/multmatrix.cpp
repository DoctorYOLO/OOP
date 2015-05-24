#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

const int n = 3;

void inversion(double **old_matrix)
{
	double temp;
	double **matrix = new double *[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0.0;
			if (i == j)
			{
				matrix[i][j] = 1.0;
			}
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		temp = old_matrix[k][k];
		for (int j = 0; j < n; j++)
		{
			old_matrix[k][j] /= temp;
			matrix[k][j] /= temp;
		}
		for (int i = k + 1; i < n; i++)
		{
			temp = old_matrix[i][k];
			for (int j = 0; j < n; j++)
			{
				old_matrix[i][j] -= old_matrix[k][j] * temp;
				matrix[i][j] -= matrix[k][j] * temp;
			}
		}
	}

	for (int k = n - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = old_matrix[i][k];
			for (int j = 0; j < n; j++)
			{
				old_matrix[i][j] -= old_matrix[k][j] * temp;
				matrix[i][j] -= matrix[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			old_matrix[i][j] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Wrong amount of arguments\n");
		return 1;
	}
	FILE *pFile;
	pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{
		printf("File opening error\n");
		pFile = NULL;
		return 1;
	}
	
	int i, j;
	double **matrix = new double *[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(pFile, "%lf", &matrix[i][j]);
		}
	}
	
	inversion(matrix);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << (round(matrix[i][j] * 1000) / 1000) << "	";
		}
		cout << endl;
	}
	
	fclose(pFile);
	pFile = NULL;
	
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}

	




