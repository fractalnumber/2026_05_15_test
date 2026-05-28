#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "header_0528.h"

using namespace std;


void CMaze()
{
	const string FilePath = ".\\data\\Maze.txt";	// .은 현재 워킹 폴더(기본적으로 파일이 실행되는 곳)
	std::ifstream InputFile(FilePath);	// 입력용 파일스트림 만들기
	if (InputFile.is_open())
	{
		std::string FileTexts(
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);
		//printf("파일 내용 : \n\n%s\n", FileTexts.c_str());
		
		const int mazeHsize = atoi(FileTexts.c_str());
		const int mazeVsize = atoi((FileTexts.c_str() + 3));
		
			

		printf("이 미로의 가로 길이는 : %d", mazeHsize);
		printf("\n");
		printf("이 미로의 세로 길이는 : %d", mazeVsize);

		printf("\n\n\n");
		
		int* Array = new int[mazeVsize*mazeHsize]{0,};

		
		for (int e = 0; e < mazeVsize; e++)
		{
			for (int f = 0; f < mazeHsize; f++)
			{
				Array[(e * 20) + (f * 1)] = atoi((FileTexts.c_str() + 6 + (e * 40) + (f * 2)));
				
				printf("%2d", Array[(e * 20) + (f * 1)]);
			}
			printf("\n");
		}

		
		InputFile.close();
	}
	else
	{
		// 파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.\n");

	}


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
		

				
		printf("\n앗! 야생의 몬스터(이)가 나타났다. 전투를 시작한다!\n\n");

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


int castmonster()

{
	mazeMonster Goblin;
	mazeMonster Orge;
	mazeMonster Troll;

	Goblin.Name = "고블린";
	Goblin.Health = 50;
	Orge.Name = "오우거";
	Orge.Health = 80;
	Troll.Name = "트롤";
	Troll.Health = 70;
}



