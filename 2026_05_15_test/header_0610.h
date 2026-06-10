#pragma once

#include <iostream>
#include <string>



float Calculator();

template <typename STK>
class Stack
{
	STK* Data;
	int CurrentIndex;
	int StackSize;

public:

	Stack() {
		StackSize = 10;
		Data = new STK[StackSize];
		CurrentIndex = -1;
	}

	void Push_Stack(const STK& input)
	{
		
		if (CurrentIndex == StackSize)
		{
			printf("\n스택에 값을 더 넣을 수 없습니다.");
			return;
		}
		else
		{			
			Data[CurrentIndex + 1] = input;
			CurrentIndex++;
			// Data[++CurrentIndex] = input; 이 더 일반적
			printf("\n스택에 [%c] 값을 추가했습니다.",Data[CurrentIndex]);
		}
		
	}

	void Pop_Stack()
	{
		if (CurrentIndex == -1)
		{
			printf("\n스택에 남아있는 값이 없어 뺄 수 없습니다.");
			return;
		}
		else
		{
			printf("\n최근 스택에서 값을 하나 뺍니다.");			
			Data[CurrentIndex] = NULL;
			CurrentIndex--;			
		}

	}

	void Top_Stack()
	{
		if (CurrentIndex == -1)
		{
			printf("\n스택이 비어있어 출력할 값이 없습니다.");
			return;
		}
		else
		{
			printf("\n현재 가장 위에 있는 값은 : [%c]", Data[CurrentIndex]);
		}
	}

	~Stack()
	{
		delete[] Data;
	}

};

//template <typename LKL>
//class LinkedList
//{
//	LKL* Data;
//	int LastIndex;
//	int Pointer;
//
//public:
//
//	int SelectLocation = 0;
//
//	LinkedList()
//	{
//		
//		Data = new LKL[Pointer];
//	}	
//
//	void AddList(const LKL& input)
//	{
//		if (Pointer == 10)
//		{
//			printf("\n리스트 용량 초과");
//			return;
//		}
//		else
//		{
//			Data[++Pointer] = input;
//			printf("\n%c", Data[Pointer]);
//		}4
//	}
//
//	void MinusList(int Location)
//	{
//		if (Location <0 || Location >9)
//		{
//			printf("\n지정된 값이 리스트 용량 값을 벗어남");
//		}
//		else
//		{
//			Data[Location] = NULL;
//			printf("\n%c 값을 지웠습니다.", Data[Pointer]);
//
//		}
//	}
//};











// Stack<char> TestStack;
	// 
	// char quit = 'a';
	// 
	// printf("스택 테스트\n\n1.스택에 값 넣기\n2.스택에서 값 빼기\n3.가장 나중에 넣은 값 출력\n4.종료\n");
	// 
	// while (quit != '4')
	// {
	// 	quit = _getch();
	// 	if (quit == '1')
	// 	{
	// 		printf("\n스택에 넣을 값 입력 : ");
	// 		TestStack.Push_Stack(_getch());
	// 	}
	// 	else if (quit == '2')
	// 	{
	// 		TestStack.Pop_Stack();
	// 	}
	// 	else if (quit == '3')
	// 	{
	// 		TestStack.Top_Stack();
	// 	}
	// 	else if (quit == '4')
	// 	{
	// 		break;
	// 	}
	// }

	//LinkedList<char> TestList;
	//
	//std::string Inputword;
	//
	//char quit = 'a';
	//
	//printf("리스트 테스트\n\n1.리스트에 값 넣기\n2.리스트에서 위치 지정하여 값 빼기\n3.특정 위치 값 출력\n4.종료\n");
	//
	//while (quit != '4')
	//{
	//	quit = _getch();
	//	if (quit == '1')
	//	{
	//		printf("\n리스트에 넣을 값 입력 : ");
	//		TestList.AddList(_getch());
	//	}
	//	else if (quit == '2')
	//	{
	//		TestList.MinusList(_getch());
	//	}
	//	else if (quit == '3')
	//	{
	//		
	//	}
	//	else if (quit == '4')
	//	{
	//		break;
	//	}
	//}