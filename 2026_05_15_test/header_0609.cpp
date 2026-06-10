#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>
#include <windows.h>
#include "header_0609.h"

void MainQueue()
{
	char InputCommand = '0';
	int QueueSize = 0;		
	int EntryPoint = -1;

	std::vector<char> QueueArray = {0, };
	
	printf("큐 크기를 입력: ");	
		
	std::cin >> QueueSize;
	std::cin.clear();
	std::cin.ignore(10000,'\n');

	if (QueueSize <= 0)
	{
		printf("\nError");
		return;
	}
	
	QueueArray.reserve(QueueSize);
	QueueArray.resize(QueueSize);

	printf("\n크기를 지정한 큐에 들어갈 문자 입력: ");

	for (int i = 0; i < QueueSize; i++)
	{
		QueueArray[i] = _getch();
		EntryPoint++;		
	}

	

	while (InputCommand != '3')
	{
		system("cls");

		printf("현재 큐에 들어간 요소는 : \n");
		for (int i = 0; i < EntryPoint+1; i++)
		{
			printf("[%c] ", QueueArray[i]);
		}

		printf("\n\n큐의 사이즈는 : %d", EntryPoint+1);
		// printf("\n진입점(확인용) : [%d]", EntryPoint);

		printf("\n\n수행할 작업 입력 : \n\n1. 큐에서 값 빼기\n2. 큐에 값 넣기\n3. 나가기 (.)\n입력 :");
		std::cin >> InputCommand;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		if (InputCommand == '1') // 큐에서 값 빼기
		{
			if (EntryPoint > 0)
			{
				for (int i = 0; i < EntryPoint; i++)
				{
					QueueArray[i] = QueueArray[i + 1];
					QueueArray[i + 1] = NULL;
				}
				EntryPoint--;
			}
			else if (EntryPoint == 0)
			{
				QueueArray[0] = NULL;
				EntryPoint = -1;
				printf("\n큐에 값이 전부 비워졌습니다.");
				_getch();
			}
			else if (EntryPoint < 0)
			{
				printf("\n큐에 값이 하나도 없어 뺄 수 없습니다.");
				_getch();
			}
		}
		else if (InputCommand == '2') // 큐에 값 넣기
		{
			printf("\n큐에 들어갈 값 입력 : ");
			QueueArray.resize(EntryPoint+2);
			QueueArray[EntryPoint + 1] = _getch();
			EntryPoint++;
		}		
	}

}

void MainStack()
{
}

