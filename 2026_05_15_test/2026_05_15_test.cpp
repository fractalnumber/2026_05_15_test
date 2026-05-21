// 2026_05_15_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "dicegame.h"
//#include <random>

int main()

{
	printf("1. 주사위 베팅\n\n\n");

	srand(time(0));

	//srand(static_cast<unsigned int>(time(NULL)));

	int playervalue = 10000; // 내 금액
	int comvalue = 10000; // 컴퓨터 금액

	int playerrole1 = 0; // 내 주사위 처음 눈
	int comrole1 = 0; // 컴퓨터 주사위 처음 눈
	int playerrole2 = 0; // 내 주사위 두번째 눈
	int comrole2 = 0; // 컴퓨터 주사위 두번째 눈

	int betvalue = 0; // 베팅금액
	int bets = 0; // 베팅하는쪽 (1: 플레이어, 2: 컴퓨터)
	int round = 1; // 현재 라운드

	// 주사위 굴리기

	while ((playervalue > 0) && (comvalue > 0))
	{
		printf("------------------[라운드 %d]------------------", round);

		playerrole1 = randdice();
		comrole1 = randdice();

		while ((playerrole1 == comrole1) || (playerrole2 == comrole2) || ((playerrole1 + playerrole2) == (comrole1 + comrole2)))  // 중복조건 제거
		{
			playerrole1 = randdice();
			comrole1 = randdice();
			playerrole2 = randdice();
			comrole2 = randdice();
		}

		printf("\n첫번째 플레이어 주사위의 눈은 %d, 컴퓨터 주사위의 눈은 %d 입니다.\n\n", playerrole1, comrole1);

		if (playerrole1 > comrole1)
		{
			printf("\n플레이어 주사위의 눈이 컴퓨터 주사위의 눈보다 크므로 컴퓨터가 베팅을 진행합니다.\n\n");
			bets = 2;
		}
		else
		{
			printf("\n컴퓨터 주사위의 눈이 플레이어 주사위의 눈보다 크므로 플레이어가 베팅을 진행합니다.\n");
			bets = 1;
		}

		// 베팅하기



		if (bets == 1) // 플레이어가 진행
		{
			
			printf("베팅할 금액을 입력하세요 : (소지금 : %d)", playervalue);

			betvalue = PlyBetValue();
			
			while ((betvalue > playervalue) || (betvalue > comvalue))
			{
				printf("베팅금액이 어느 한 쪽의 소지금액보다 큽니다. 다시 입력해주세요.\n");

				printf("플레이어의 소지금 : %d\n", playervalue);
				printf("컴퓨터의 소지금 : %d\n", comvalue);

				betvalue = PlyBetValue();

			}

			printf("플레이어가 %d 금액을 베팅하였습니다.\n", betvalue);

			playervalue = playervalue - betvalue;
			comvalue = comvalue - betvalue;
			
		}
		else if (bets == 2) // 컴퓨터가 진행
		{
			betvalue = MaxComBetValue(comvalue);

			while ((betvalue > playervalue) || (betvalue > comvalue))
			{
				betvalue = MaxComBetValue(comvalue);
			}
			
			playervalue = playervalue - betvalue;
			comvalue = comvalue - betvalue;

			printf("컴퓨터가 %d 금액을 베팅하였습니다. (컴퓨터의 남은 소지금 : %d)\n\n", betvalue, comvalue);
		}


		// 두번째 주사위 굴리기 (처음에서 이미 돌림)

		printf("두번째 플레이어 주사위의 눈은 %d, 컴퓨터 주사위의 눈은 %d 입니다.\n\n", playerrole2, comrole2);

		// 첫번째와 두번째의 주사위의 합 비교

		if ((playerrole1 + playerrole2) > (comrole1 + comrole2))
		{
			printf("플레이어 주사위 눈의 합은 %d, 컴퓨터 주사위 눈의 합은 %d 입니다\n", (playerrole1 + playerrole2), (comrole1 + comrole2));
			printf("플레이어가 승리하였으므로 베팅 금액을 모두 가져갑니다.\n\n");

			playervalue = playervalue + (betvalue * 2);
		}
		else if ((playerrole1 + playerrole2) < (comrole1 + comrole2))
		{
			printf("플레이어 주사위 눈의 합은 %d, 컴퓨터 주사위 눈의 합은 %d 입니다\n", (playerrole1 + playerrole2), (comrole1 + comrole2));
			printf("컴퓨터가 승리하였으므로 컴퓨터가 베팅 금액을 모두 가져갑니다.\n\n");

			comvalue = comvalue + (betvalue * 2);
		}

		round = (round + 1);
	}

	if (playervalue <= 0)
	{
		printf("플레이어의 소지금이 부족하여 게임을 종료합니다.\n");
	}
	else if (comvalue <= 0)
	{
		printf("컴퓨터의 소지금이 부족하여 게임을 종료합니다.\n");
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
 