#include <iostream>
#include <math.h>
#include <ctime>
#include "pthread.h"
#include <fstream>

using namespace std;

#define THREADS_COUNT 8


void task(int n)
{
	
	fstream fout;
	fout.open("output.txt", std::ofstream::out | std::ofstream::app);
	int div = 2;
	fout << "N = ";
	fout << n << " = 1";
	while (n > 1)
	{
		while (n % div == 0)
		{
			fout << " * " << div;
			n = n / div;
		}
		div++;
	}
	fout << "\n";
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	pthread_t t[THREADS_COUNT];
	int a;
	ifstream fin;
	fin.open("input.txt");
	int ch;

	for (int i = 0; i < THREADS_COUNT; i++)
	{
		pthread_create(&t[i], NULL, print, &s[i]);
	}

	while (fin >> ch)
	{
		task(ch);
	}
	
	for (int j = 0; j < THREADS_COUNT; j++)
	{
		double* result;
		pthread_join(t[j], (void**)& result);
		sum += *result;
	}
	return 0;
}