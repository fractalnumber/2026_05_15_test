#include <iostream>
#include <time.h>
#include <stdio.h>
#include "addheader.h"

int diceRresult(int* DiceArray, int maxrollcount)
{
	srand(time(0));

		int cdicenum = 0;

			
	for (int i = 0; i < maxrollcount; i++)
	{
		cdicenum = (rand()%6+1);
		if (cdicenum == 1)
		{
			DiceArray[0] = (DiceArray[0] + 1);
		}
		else if (cdicenum == 2)
		{
			DiceArray[1] = (DiceArray[1] + 1);
		}
		else if (cdicenum == 3)
		{
			DiceArray[2] = (DiceArray[2] + 1);
		}
		else if (cdicenum == 4)
		{
			DiceArray[3] = (DiceArray[3] + 1);
		}
		else if (cdicenum == 5)
		{
			DiceArray[4] = (DiceArray[4] + 1);
		}
		else if (cdicenum == 6)
		{
			DiceArray[5] = (DiceArray[5] + 1);
		}
	}
	
	return DiceArray[0], DiceArray[1], DiceArray[2], DiceArray[3],DiceArray[4], DiceArray[5];
}

int arrayinv(int* array, int size)
{
	
	printf("원래 배열은 : ");
	
	for (int i = 0; i < size; i++)
	{
		printf("[%d] ", array[i]);
	}

	printf("\n");
	
	
	int temp1 = 0;
	int temp2 = 0;

	for (int i = 0; i < (size/2); i++)
	{
		temp1 = array[i];
		temp2 = array[(size-1)-i];

		array[i] = temp2;
		array[(size-1) - i] = temp1;
	}

	printf("바뀐 배열은 : ");
	
	for (int i = 0; i < size; i++)
	{
		printf("[%d] ", array[i]);
	}
	
	return 0;
}

int arraylotto(int* array, int size)
{
	int randtemp = 0;
	int tempnum1 = 0;
	int tempnum2 = 0;
	
	for (int i = 0; i < 6; i++)
	{
		tempnum1 = array[size-(i+1)];				// 마지막부분
		randtemp = (rand() % (tempnum1-1));		
		tempnum2 = array[randtemp];					// 마지막부분을 제외하고 선택하는 부분

		array[(size - (i+1))] = tempnum2;
		array[randtemp] = tempnum1;

	}

	printf("[%d] [%d] [%d] [%d] [%d] [%d]", array[size - 1], array[size - 2], array[size - 3], array[size - 4], array[size - 5], array[size - 6]);

	return array[size-1], array[size-2], array[size-3], array[size-4], array[size-5], array[size-6];
}
