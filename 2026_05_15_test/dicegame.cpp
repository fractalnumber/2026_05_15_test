#include <iostream>
#include <time.h>
#include "dicegame.h"


int randdice()
{
	
	int num1 = (rand() % 6) + 1;

	
	return num1;
}

int PlyBetValue()
{
	int bValue = 0;
	std::cin >> bValue;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	return bValue;
}


int MaxComBetValue(int com)
{
	int val = ((rand() % com) + 1);

	return val;
}



