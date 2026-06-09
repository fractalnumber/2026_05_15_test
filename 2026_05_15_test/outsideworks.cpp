// 2026_05_15_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
// #include <vector>
#include <random>
#include <conio.h>
#include <stack>
#include "header_0609.h"

using namespace std;


int main()
{
	srand(time(NULL));


	// TestVarious();
	// mazegame();

	// std::stack<char> Array;
	
	// printf("7개의 값을 입력합니다.");
	 
	// Array.push(_getch());
	// Array.push(_getch());
	// Array.push(_getch());
	// Array.push(_getch());
	// Array.push(_getch());
	// Array.push(_getch());
	// Array.push(_getch());
	
	// printf("스택의 현재 크기는[%llu] 입니다.", Array.size());
	// printf("\n\n현재 스택의 마지막 값은 [%c]", Array.top());
 
	// Array.pop();
	
	// printf("\n\npop을 한번 실행한 스택의 마지막 값은 [%c]", Array.top());
	
	// 스택에서 역순출력 할 때는 출력후 (size-1)번 만큼 pop을 하는 것을 반복한다. 데이터를 보존해야 한다면 pop 전에 다른 배열이라던지 보관한다.


	// for (int i = Array.size() - 1; i >= 0; i--) // Array의 첫번째까지 출력? 첫번째 값을 확인하고 싶으면 *.size() 에서 -1 을 빼서 확인하면 된다.
	// {
	// 	printf("[%c] ", Array[i]);
	// }

	// printf("\n\n위 부분은 역순 출력됨");
	
	// 이하 테스트중
	
	// printf("\n현재 vector의 capacity 크기는 [%llu]", Array.capacity());
	
	// Array.reserve(10);

	// printf("\n현재 vector의 크기는 [%llu]", Array.capacity());

	// printf("\n Array의 특정 주소의 실제 값은 : %d", Array[6]); // reserve를 통해 메모리 공간 할당은 받았으나 실제 값이 들어가기 전까지 해당 주소로 접근은 불가능함.

	// Array.pop();
	


	// printf("\n\npop_back을 한번 실행한 현재 vector의 size 값은 [%llu]", Array.size());
	// printf("\n\npop_back을 한번 실행한 현재 vector의 마지막 주소의 값은 [%c]", Array[Array.size()-1]);

	// Array.insert(Array.begin(), 'X');
	 
	// printf("\n\nInsert Test입니다. Array 맨 처음에 들어간 값은 %c", Array[0]);



	MainQueue();


}

 