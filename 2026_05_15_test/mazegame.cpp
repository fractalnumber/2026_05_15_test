#include <iostream>
#include <string>
#include "mazegame.h"

void mazegame()
{

	const int MazeHsize = 20;
	const int MazeVsize = 10;

	int arraymaze[MazeVsize][MazeHsize] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
		{1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,0,0,1},
		{1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
		{1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1},
		{1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,3},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	// 위치관련 변수
	int startVpos = 0;
	int startHpos = 0;
	int endVpos = 0;
	int endHpos = 0;
	int playerVpos = 0;
	int playerHpos = 0;

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
	const int minigame_percent = 10; // 몬스터 전투 미니게임 출현확률 (%)

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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
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
					minigame_result = MonsterBattle();
				}				
				else
				{
				}
			}



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

void mazegame_pause()
{
	int dummyinput = 0;
	std::cin >> dummyinput;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

}

int MonsterBattle()
{
	int BattleResult = 0;
	int MonsterRandGen = 0;
	Player* MyPlayer = new Player("플레이어",150,10);
	
	int Criti_Multiplier = 1;
	int PlayerDamage = 0;
	int MonsterDamage = 0;
	int Player_CausedDamage = 0;
	int Monster_CasuedDamage = 0;
		
	Monster* pMonster = new Monster("기본값", 100, 5);


	Troll* MyTroll = new Troll("트롤",80,5);
	Goblin* MyGoblin = new Goblin("고블린",50,5);
	Orc* MyOrc = new Orc("오크",100,8);

	


	MonsterRandGen = RandNumGen();

	if (MonsterRandGen == 1)
	{
		pMonster = MyTroll;
	}
	else if (MonsterRandGen == 2)
	{
		pMonster = MyGoblin;
	}
	else if (MonsterRandGen == 3)
	{
		pMonster = MyOrc;
	}

	int CurrentTurn = 0;
	bool Attacked = false;

	while (BattleResult == 0)
	{
		// 메인 프롬프트


		system("cls");

		printf("\n앗! 야생의 [%s](이)가 나타났다. 전투를 시작한다!\n\n", pMonster->ActorName.c_str());

		CurrentTurn += 1;

		printf("---------------[%d]번째 턴---------------\n\n\n", CurrentTurn);

		if (Attacked == true)
		{
			printf("이전 턴에서 나는 [%d]의 데미지를 [%s]에게 입히고 [%s](은)는 나에게 [%d]의 데미지를 입혔다.\n\n", Player_CausedDamage, pMonster->ActorName.c_str(), pMonster->ActorName.c_str(), Monster_CasuedDamage);
		}


		printf("내 체력 = [%d] // 몬스터의 체력 = [%d]\n\n\n\n\n", MyPlayer->HealthPoint, pMonster->HealthPoint);
		printf("아무 키나 입력하면 공격을 1회 주고받습니다. 데미지는 5~15 사이로 결정되며 10%% 확률로 2배의 데미지를 입힙니다.\n");


		mazegame_pause();


		// 데미지 계산 (플레이어)

		PlayerDamage = (MyPlayer->AttackPower + ((rand() % 3 + 1)) * Criti_Multiplier);
		Player_CausedDamage = PlayerDamage;

		// 크리티컬 처리부분

		if ((rand() % 10 + 1) == 1)
		{
			Criti_Multiplier = 2;
		}
		else
		{
			Criti_Multiplier = 1;
		}


		MonsterDamage = (pMonster->AttackPower + ((rand() % 3 + 1)) * Criti_Multiplier);
		Monster_CasuedDamage = MonsterDamage;


		// 크리티컬 처리부분 (몬스터)

		if ((rand() % 10 + 1) == 1)
		{
			Criti_Multiplier = 2;
		}
		else
		{
			Criti_Multiplier = 1;
		}

		MyPlayer->HealthPoint -= MonsterDamage;
		pMonster->HealthPoint -= PlayerDamage;

		
		

		Criti_Multiplier = 1;

		Attacked = true;

		if ((MyPlayer->HealthPoint > 0) && (pMonster->HealthPoint > 0)) // 둘다 체력 1이상이면 전투 속행
		{
			system("cls");
		}
		else if ((MyPlayer->HealthPoint > 0) && (pMonster->HealthPoint <= 0)) // 몬스터 체력이 0이하가 되면
		{
			pMonster->HealthPoint = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 [%s]에게 입히고 [%s]는 나에게 [%d]의 데미지를 입혔다.", Player_CausedDamage, pMonster->ActorName.c_str(), pMonster->ActorName.c_str(), Monster_CasuedDamage);
			printf("\n\n내 체력 = [%d] // [%s]의 체력 = [%d]", MyPlayer->HealthPoint, pMonster->ActorName.c_str(), pMonster->HealthPoint);
			printf("\n\n[%s] 체력이 0 이하가 되어 내가 승리하였다. 계속하려면 아무 키나 입력하세요", pMonster->ActorName.c_str());

			BattleResult = 1;

			mazegame_pause();

		}
		else if ((MyPlayer->HealthPoint <= 0) && (pMonster->HealthPoint > 0)) // 내 체력이 0이하가 되면
		{
			MyPlayer->HealthPoint = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 상대에게 입히고 [%s]는 나에게 [%d]의 데미지를 입혔다.", Player_CausedDamage, pMonster->ActorName.c_str(), Monster_CasuedDamage);
			printf("\n\n내 체력 = [%d] // [%s]의 체력 = [%d]", MyPlayer->HealthPoint, pMonster->ActorName.c_str(), pMonster->HealthPoint);
			printf("\n\n내 체력이 0 이하가 되어 패배하였다. 계속하려면 아무 키나 입력하세요");

			BattleResult = 2;

			mazegame_pause();

		}
		else if ((MyPlayer->HealthPoint <= 0) && (pMonster->HealthPoint <= 0)) // 내 체력과 몬스터 체력이 동시에 0 이하가 되면
		{
			MyPlayer->HealthPoint = 0; // 체력이 음수로 보이는 현상 방지
			pMonster->HealthPoint = 0; // 체력이 음수로 보이는 현상 방지

			printf("\n\n나는 [%d]의 데미지를 상대에게 입히고 [%s]는 나에게 [%d]의 데미지를 입혔다.", Player_CausedDamage, pMonster->ActorName.c_str(), Monster_CasuedDamage);
			printf("\n\n내 체력 = [%d] // [%s]의 체력 = [%d]", MyPlayer->HealthPoint,pMonster->ActorName.c_str(), pMonster->HealthPoint);
			printf("\n\n서로 더 이상 움직일 수 없을 정도로 치열하게 싸워 동시에 쓰러졌다. 계속하려면 아무 키나 입력하세요");

			BattleResult = 3;

			mazegame_pause();

		}
	}

	delete MyPlayer;
	delete pMonster;

	return 0;
}
int RandNumGen()
{
	int InResult = 0;
	InResult = (rand() % 3 + 1);

	return InResult;
}
