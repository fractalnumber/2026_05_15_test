#include <iostream>
#include <stack>
#include "header_0610.h"

float Calculator()
{
	float Num1 = 0;
	float Num2 = 0;

	float returnNum = 0;

	printf("첫번째 수를 입력하세요 : ");
	std::cin >> Num1;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	printf("두번째 수를 입력하세요 : ");
	std::cin >> Num2;
	std::cin.clear();
	std::cin.ignore(10000, '\n');	
	
	int Mathtype = 0;
	// Mathtype 1 = 더하기 연산
	// Mathtype 2 = 빼기 연산
	// Mathtype 3 = 곱하기 연산
	// Mathtype 4 = 나누기 연산

	

	printf("\n연산 종류를 입력\n1.더하기\n2.빼기\n3.곱하기\n4.나누기 : ");
	std::cin >> Mathtype;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	if (Mathtype == 1)
	{
		returnNum = Num1 + Num2;
	}
	else if (Mathtype == 2)
	{
		returnNum = Num1 - Num2;
	}
	else if (Mathtype == 3)
	{
		returnNum = Num1 * Num2;
	}
	else if (Mathtype == 4)
	{
		if (Num2 == 0)
		{
			printf("\n0으로 나눌 수 없습니다.");
		}
		else
		{
			returnNum = Num1 / Num2;
		}
	}

	if (std::floor(returnNum) == returnNum) // 결과가 정수면
	{		
		printf("계산 결과는 %d 입니다.", static_cast<int>(returnNum));
	}
	else
	{
		printf("계산 결과는 %f 입니다.", returnNum);
	}
		

	return returnNum;
}
