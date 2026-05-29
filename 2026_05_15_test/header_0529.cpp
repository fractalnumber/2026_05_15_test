#include "header_0529.h"


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include "header_0529.h"


void TestVarious()

{

	const int MazeHsize = 20;
	const int MazeVsize = 10;

	int arraymaze[MazeVsize][MazeHsize] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	// 위치관련 변수
	int startVpos = 0;
	int startHpos = 0;
	int endVpos = 0;
	int endHpos = 0;
	int playerVpos = 0;
	int playerHpos = 0;
	int PlayerRealVpos = playerVpos + 1;
	int PlayerRealHpos = playerHpos + 1;
	int FirstPosition_H = 0;
	int FirstPosition_V = 0;
	int SecondPosition_H = 0;
	int SecondPosition_V = 0;	



	// 이동관련 변수
	int inputmove = 0;
	bool canmoveW = 0;
	bool canmoveA = 0;
	bool canmoveS = 0;
	bool canmoveD = 0;
	bool moveflag = 0; // 중복이동 방지용

	// 겉보기 치환용
	char pathway = '.';
	char wall = '#';
	char startpoint = 'S';
	char exitpoint = 'E';
	char playerpoint = 'P';

	int minigame_result = 0; // 미니게임 결과에 따라 미로 통과 도중 중단
	const int minigame_percent = 0; // 몬스터 전투 미니게임 출현확률 (%)

	int randomencounter = 0;


	// 시작점 구하는 부분
	for (int e = 0; e < MazeVsize; e++)
	{
		for (int f = 0; f < MazeHsize; f++)
		{
			if (arraymaze[e][f] == 2)
			{
				startVpos = e;
				startHpos = f;
			}
		};
	}

	// 끝점 구하는 부분
	for (int e = 0; e < MazeVsize; e++)
	{
		for (int f = 0; f < MazeHsize; f++)
		{
			if (arraymaze[e][f] == 3)
			{
				endVpos = e;
				endHpos = f;
			}
		};
	}


	// 시작부분에 플레이어 놓기
	playerVpos = startVpos;
	playerHpos = startHpos;
	arraymaze[playerVpos][playerHpos] = playerpoint;





	// 반복부

	while ((arraymaze[endVpos][endHpos] != arraymaze[playerVpos][playerHpos]) && ((minigame_result == 0) || (minigame_result == 1)))
	{

		printf("------미로 탈출------\n");

		// 1. 미로 출력 (선치환 후출력)

		// 미로 구성요소 문자변환
		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == 0)
				{
					arraymaze[e][f] = pathway;
				}
			};
		}

		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == 1)
				{
					arraymaze[e][f] = wall;
				}
			};
		}

		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == 2)
				{
					arraymaze[e][f] = startpoint;
				}
			};
		}

		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == 3)
				{
					arraymaze[e][f] = exitpoint;
				}
			};
		}

		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == 4)
				{
					arraymaze[e][f] = playerpoint;
				}
			};
		}

		for (int e = 0; e < MazeVsize; e++)
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				printf("%2c", arraymaze[e][f]);
			};
			printf("\n");
		}


		// 2. 상하좌우에 따라 이동변수 제어

		if ((playerVpos != 0)) // 수직부가 제일 위가 아닐때 위쪽으로 이동가능여부 기록
		{
			if (arraymaze[playerVpos - 1][playerHpos] != wall) // 내 위쪽이 벽이 아니면?
			{
				canmoveW = true;
			}
			else
			{
				canmoveW = false;
			}
		}

		if ((playerVpos != (MazeVsize - 1))) // 수직부가 제일 아래가 아닐때 아래쪽으로 이동가능여부 기록
		{
			if (arraymaze[playerVpos + 1][playerHpos] != wall) // 내 아래쪽이 벽이 아니면?
			{
				canmoveS = true;
			}
			else
			{
				canmoveS = false;
			}
		}

		if ((playerHpos != 0)) // 수평부가 제일 왼쪽이 아닐때 왼쪽으로 이동가능여부 기록
		{
			if (arraymaze[playerVpos][playerHpos - 1] != wall) // 내 왼쪽이 벽이 아니면?
			{
				canmoveA = true;
			}
			else
			{
				canmoveA = false;
			}
		}

		if ((playerHpos != (MazeHsize))) // 수평부가 제일 오른쪽이 아닐때 오른쪽으로 이동가능여부 기록
		{
			if (arraymaze[playerVpos][playerHpos + 1] != wall) // 내 오른쪽이 벽이 아니면?
			{
				canmoveD = true;
			}
			else
			{
				canmoveD = false;
			}
		}

		// 3. 이동가능여부를 출력하고 이동방향 입력하기
		if (canmoveW == true)
		{
			printf("위쪽으로 이동-(1 입력) ,");
		}
		if (canmoveS == true)
		{
			printf("아래쪽으로 이동-(2 입력) ");
		}
		if (canmoveA == true)
		{
			printf("왼쪽으로 이동-(3 입력) ");
		}
		if (canmoveD == true)
		{
			printf("오른쪽으로 이동-(4 입력)");
		}

		PlayerRealVpos = playerVpos + 1;
		PlayerRealHpos = playerHpos + 1;
		printf("\n\n플레이어의 현재 좌표 : X:[%d], Y:[%d]", PlayerRealHpos, PlayerRealVpos);
		printf("\n\n첫번째 좌표를 입력하려면 6, 두번째 좌표를 입력하려면 7 누름");

		printf("\n\n첫번째 기록된 좌표 = X:[%d], Y:[%d] , 좌표의 차 = X:[%d], Y:[%d]", FirstPosition_H, FirstPosition_V, SecondPosition_H, SecondPosition_V);
		
		printf("\n좌표의 합 = X:[%d], Y:[%d] , 좌표의 차 = X:[%d], Y:[%d]", (FirstPosition_H + SecondPosition_H), (FirstPosition_V + SecondPosition_V),
				(FirstPosition_H - SecondPosition_H), (FirstPosition_V - SecondPosition_V));

		

		std::cin >> inputmove;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		


		// 4. 이동 처리

		for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
		{
			for (int f = 0; f < MazeHsize; f++)
			{
				if (arraymaze[e][f] == playerpoint)
				{
					playerVpos = e;
					playerHpos = f;
				}
			};
		}

		moveflag = true;

		if ((canmoveW == true) && (moveflag == true) && (inputmove == 1)) // 위쪽이동 처리
		{
			if (arraymaze[playerVpos - 1][playerHpos] == arraymaze[startVpos][startHpos]) // 이동할 목표지점이 스타트 포인트일때
			{
				arraymaze[playerVpos - 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveW = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos] == arraymaze[startVpos][startHpos]) // 이동 시작점이 스타트 포인트일때
			{
				arraymaze[playerVpos - 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = startpoint;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveW = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos - 1][playerHpos] == arraymaze[endVpos][endHpos]) // 이동할 목표지점이 종료 포인트일때 (이동 시작점이 종료 포인트인 경우는 그대로 종료하므로 처리하지 않음.)
			{
				arraymaze[playerVpos - 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveW = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else // 길에서 길로 이동할 때
			{
				arraymaze[playerVpos - 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;
				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveW = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
		}
		else if ((canmoveS == true) && (moveflag == true) && (inputmove == 2)) // 아래쪽이동 처리
		{
			if (arraymaze[playerVpos + 1][playerHpos] == arraymaze[startVpos][startHpos]) // 이동할 목표지점이 스타트 포인트일때
			{
				arraymaze[playerVpos + 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveS = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos] == arraymaze[startVpos][startHpos]) // 이동 시작점이 스타트 포인트일때
			{
				arraymaze[playerVpos + 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = startpoint;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveS = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos + 1][playerHpos] == arraymaze[endVpos][endHpos]) // 이동할 목표지점이 종료 포인트일때 (이동 시작점이 종료 포인트인 경우는 그대로 종료하므로 처리하지 않음.)
			{
				arraymaze[playerVpos + 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveS = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else // 길에서 길로 이동할 때
			{
				arraymaze[playerVpos + 1][playerHpos] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;
				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveS = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
		}
		else if ((canmoveA == true) && (moveflag == true) && (inputmove == 3)) // 왼쪽이동 처리
		{
			if (arraymaze[playerVpos][playerHpos - 1] == arraymaze[startVpos][startHpos]) // 이동할 목표지점이 스타트 포인트일때
			{
				arraymaze[playerVpos][playerHpos - 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveA = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos] == arraymaze[startVpos][startHpos]) // 이동 시작점이 스타트 포인트일때
			{
				arraymaze[playerVpos][playerHpos - 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = startpoint;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveA = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos - 1] == arraymaze[endVpos][endHpos]) // 이동할 목표지점이 종료 포인트일때 (이동 시작점이 종료 포인트인 경우는 그대로 종료하므로 처리하지 않음.)
			{
				arraymaze[playerVpos][playerHpos - 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveA = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else // 길에서 길로 이동할 때
			{
				arraymaze[playerVpos][playerHpos - 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;
				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveA = false;
				moveflag = false;
				inputmove = 0;

				if (((rand() % 100) + 1) <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
			}
		}
		else if ((canmoveD == true) && (moveflag == true) && (inputmove == 4)) // 오른쪽이동 처리
		{
			if (arraymaze[playerVpos][playerHpos + 1] == arraymaze[startVpos][startHpos]) // 이동할 목표지점이 스타트 포인트일때
			{
				arraymaze[playerVpos][playerHpos + 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveD = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos] == arraymaze[startVpos][startHpos]) // 이동 시작점이 스타트 포인트일때
			{
				arraymaze[playerVpos][playerHpos + 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = startpoint;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveD = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}
			else if (arraymaze[playerVpos][playerHpos + 1] == arraymaze[endVpos][endHpos]) // 이동할 목표지점이 종료 포인트일때 (이동 시작점이 종료 포인트인 경우는 그대로 종료하므로 처리하지 않음.)
			{
				arraymaze[playerVpos][playerHpos + 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;

				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveD = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{
					
				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{
					
				}
				else
				{
				}

			}
			else // 길에서 길로 이동할 때
			{
				arraymaze[playerVpos][playerHpos + 1] = playerpoint;
				arraymaze[playerVpos][playerHpos] = pathway;
				for (int e = 0; e < MazeVsize; e++) // 플레이어의 위치 구하는 부분
				{
					for (int f = 0; f < MazeHsize; f++)
					{
						if (arraymaze[e][f] == playerpoint)
						{
							playerVpos = e;
							playerHpos = f;
						}
					}
				}
				canmoveD = false;
				moveflag = false;
				inputmove = 0;

				randomencounter = (((rand() % 100) + 1));

				if (randomencounter <= minigame_percent)
				{
					minigame_result = Homework05_Battle();
				}
				else if ((randomencounter > minigame_percent) && (randomencounter <= 4))
				{

				}
				else if ((randomencounter > 4) && (randomencounter <= 6))
				{

				}
				else
				{
				}
			}



		}
		else if(inputmove == 6)
		{
			FirstPosition_H = PlayerRealHpos;
			FirstPosition_V = PlayerRealVpos;
		}
		else if (inputmove == 7)
		{
			SecondPosition_H = PlayerRealHpos;
			SecondPosition_V = PlayerRealVpos;
		}

		system("cls");

	}

	if (((minigame_result == 0) || (minigame_result == 1)) && (arraymaze[playerVpos][playerHpos] == arraymaze[endVpos][endHpos]))
	{
		printf("\n ★★★★★ 미로를 탈출하였습니다 ★★★★★\n\n\n");

	}
	else if ((minigame_result == 2) || (minigame_result == 3))
	{
		printf("\n ★★★★★ 몬스터로 인해 체력이 고갈되어 미로 탈출에 실패하였습니다 ★★★★★\n\n\n");

	}

	return;
}



int Homework05_Battle()
{


	int p_health = 100;
	int m_health = 80;
	int p_criti_multiplier = 1;
	int m_criti_multiplier = 1;

	bool attacked = false;

	int caused_p_damage = 0;
	int caused_m_damage = 0;

	int currentTurn = 0;

	int battleresult = 0;	// 1은 승리, 2는 패배, 3은 무승부



	while (battleresult == 0)
	{
		// 메인 프롬프트

		system("cls");

		printf("\n앗! 야생의 몬스터가 나타났다. 전투를 시작한다!\n\n");

		currentTurn += 1;

		printf("----------[%d]번째 턴----------\n\n\n", currentTurn);

		if (attacked == true)
		{
			printf("이전 턴에서 나는 [%d]의 데미지를 상대에게 입히고 몬스터는 나에게 [%d]의 데미지를 입혔다.\n\n", caused_p_damage, caused_m_damage);
		}


		printf("내 체력 = [%d] // 몬스터의 체력 = [%d]\n\n\n\n\n", p_health, m_health);
		printf("아무 키나 입력하면 공격을 1회 주고받습니다. 데미지는 5~15 사이로 결정되며 10%% 확률로 2배의 데미지를 입힙니다.\n");


		Homework05_Battle_Pause();


		// 크리티컬 처리부분

		if ((rand() % 10 + 1) == 1)
		{
			p_criti_multiplier = 2;
		}
		else
		{
			p_criti_multiplier = 1;
		}

		if ((rand() % 10 + 1) == 1)
		{
			m_criti_multiplier = 2;
		}
		else
		{
			m_criti_multiplier = 1;
		}

		// 데미지 계산

		caused_p_damage = ((rand() % 11 + 5) * p_criti_multiplier);
		caused_m_damage = ((rand() % 11 + 5) * m_criti_multiplier);

		p_health = p_health - caused_m_damage;
		m_health = m_health - caused_p_damage;

		p_criti_multiplier = 1;
		m_criti_multiplier = 1;

		attacked = true;

		if ((p_health > 0) && (m_health > 0)) // 둘다 체력 1이상이면 전투 속행
		{
			system("cls");
		}
		else if ((p_health > 0) && (m_health <= 0)) // 몬스터 체력이 0이하가 되면
		{
			m_health = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 상대에게 입히고 몬스터는 나에게 [%d]의 데미지를 입혔다.", caused_p_damage, caused_m_damage);
			printf("\n\n내 체력 = [%d] // 몬스터의 체력 = [%d]", p_health, m_health);
			printf("\n\n몬스터 체력이 0 이하가 되어 내가 승리하였다. 계속하려면 아무 키나 입력하세요");

			battleresult = 1;

			Homework05_Battle_Pause();

		}
		else if ((p_health <= 0) && (m_health > 0)) // 내 체력이 0이하가 되면
		{
			p_health = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 상대에게 입히고 몬스터는 나에게 [%d]의 데미지를 입혔다.", caused_p_damage, caused_m_damage);
			printf("\n\n내 체력 = [%d] // 몬스터의 체력 = [%d]", p_health, m_health);
			printf("\n\n내 체력이 0 이하가 되어 패배하였다. 계속하려면 아무 키나 입력하세요");

			battleresult = 2;

			Homework05_Battle_Pause();

		}
		else if ((p_health <= 0) && (m_health <= 0)) // 내 체력과 몬스터 체력이 동시에 0 이하가 되면
		{
			p_health = 0; // 체력이 음수로 보이는 현상 방지
			m_health = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 상대에게 입히고 몬스터는 나에게 [%d]의 데미지를 입혔다.", caused_p_damage, caused_m_damage);
			printf("\n\n내 체력 = [%d] // 몬스터의 체력 = [%d]", p_health, m_health);
			printf("\n\n서로 더 이상 움직일 수 없을 정도로 치열하게 싸워 동시에 쓰러졌다. 계속하려면 아무 키나 입력하세요");

			battleresult = 3;

			Homework05_Battle_Pause();

		}

	}
	return battleresult;
}

void Homework05_test01() // 죽은 함수
{
	system("cls");
	printf("상점에 들어왔습니다. 테스트용이므로 구현한 것은 없습니다.");
	Homework05_Battle_Pause();
}


void Homework05_test02() // 죽은 함수 2
{
	system("cls");
	printf("건물에 들어왔습니다. 테스트용이므로 구현한 것은 없습니다.\n\n\n\n건물에 들어왔습니다. 테스트용이므로 구현한 것은 없습니다.");
	Homework05_Battle_Pause();
}


void Homework05_Battle_Pause() // 죽은 함수 3
{
	int dummyinput = 0;

	std::cin >> dummyinput;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}