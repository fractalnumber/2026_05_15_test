// 2026_05_15_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <random>
#include "mazegame.h"

using namespace std;


int main()
{
	srand(time(NULL));


	// TestVarious();
	// mazegame();

	std::vector<int> Array;

	Array.push_back(5);
	Array.push_back(6);
	Array.push_back(7);
	Array.push_back(8);
	Array.push_back(9);
	Array.push_back(10);

	

	for (int i = 0; i < Array.size(); i++) // Array의 마지막까지 출력?
	{
		printf("[%d] ", Array[i]);
	}
	
	// 이하 테스트중
	
	 printf("\n현재 vector의 capacity 크기는 [%llu]", Array.capacity());
	
	 Array.reserve(10);

	 printf("\n현재 vector의 크기는 [%llu]", Array.capacity());

	// printf("\n Array의 특정 주소의 실제 값은 : %d", Array[6]); // reserve를 통해 메모리 공간 할당은 받았으나 실제 값이 들어가기 전까지 해당 주소로 접근은 불가능함.

	 Array.pop_back();
	


	 printf("\npop_back을 한번 실행한 현재 vector의 size 값은 [%llu]", Array.size());
	 printf("\npop_back을 한번 실행한 현재 vector의 마지막 주소의 값은 [%d]", Array[Array.size()-1]);

	 Array.insert(Array.begin(), 1);
	 
	 printf("\n%d", Array[0]);
	
}

 