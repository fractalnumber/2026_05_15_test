#pragma once
// printf("2026-05-18 실습 1\n\n");
// 
// printf("1. 값 바꾸기\n\n");
// 
// int abcd = 50;
// int efgh = 20;
// 
// printf("abcd: %d\n", abcd);
// printf("efgh: %d\n\n", efgh);
// 
// printf("변수 1개 새로 선언 후 임시저장\n\n");
// 
// int ijkl = 0;
// 
// ijkl = efgh;
// efgh = abcd;
// abcd = ijkl;
// 
// printf("abcd: %d\n", abcd);
// printf("efgh: %d\n\n", efgh);
// 
// 
// printf("2. 값 합치기\n\n");
// 
// abcd = 50;
// efgh = 20;
// 
// ijkl = abcd + efgh;
// printf("efgh: %d\n\n", ijkl);
// 
// printf("3. 가로세로 곱해서 넓이 출력하기\n\n");
// 
// // abcd 와 efgh 곱하면 1000임
// ijkl = abcd * efgh;
// printf("넓이: %dm²\n\n", ijkl);
// 
// 
// printf("4. 나머지 출력하기\n\n");
// 
// printf("4-1 %연산자 사용\n\n");
// abcd = 50;
// efgh = 20;
// 
// ijkl = abcd % efgh;
// 
// printf("나머지는: %d\n\n", ijkl);
// 
// printf("4-2 %연산자 미사용\n\n");
// 
// ijkl = abcd / efgh;
// 
// printf("나머지는: %d\n\n", ijkl);
// 
// 
// 
// 
// 
// printf("2026-05-18 실습 2\n\n");
// 
// printf("1. 섭씨->화씨 \n\n");
// int ctemp = 0;
// int ktemp = 0;
// 
// printf("확인할 온도 입력 : ");
// std::cin >> ctemp;
// 
// 
// ktemp = ctemp * 9 / 5 + 32;
// 
// printf("섭씨 온도가 %d도 면 ", ctemp);
// printf("화씨 온도가 %d도 이다 \n\n\n", ktemp);
// 
// 
// printf("2. 시간 출력하기 \n\n");
// 
// int sectime = 0;
// int mintime = 0;
// int hourtime = 0;
// 
// printf("확인할 시간 입력 : ");
// std::cin >> sectime;
// 
// printf("%d초 를 변환하면 \n", sectime);
// 
// mintime = sectime / 60 % 60;
// hourtime = sectime / 3600;
// sectime = sectime % 60;
// 
// printf("%d 시간 ", hourtime);
// printf("%d 분 ", mintime);
// printf("%d 초\n\n\n", sectime);
// 
// 
// printf("3. 동전계산 \n\n");
// 
// int money = 0;
// 
// printf("금액 입력 : ");
// std::cin >> money;
// 
// printf("%d원이 있을때 \n", money);
// 
// int money_500 = 0;
// int money_100 = 0;
// int money_50 = 0;
// int money_10 = 0;
// 
// money_500 = money / 500;
// money_100 = money % 500 / 100;
// money_50 = money % 100 / 50;
// money_10 = money % 50 / 10;
// 
// printf("필요한 동전의 갯수는 각각 ");
// printf("500원 %d개, ", money_500);
// printf("100원 %d개, ", money_100);
// printf("50원 %d개, ", money_50);
// printf("10원 %d개가 된다.\n\n\n", money_10);
// 
// 
// printf("4. 자리수 분리 \n\n");
// 
// int placenumbers = 0;
// int place3 = 0;
// int place2 = 0;
// int place1 = 0;
// int placeplus = 0;
// 
// printf("확인할 자리수 입력(3자리 제한) : ");
// std::cin >> placenumbers;
// 
// printf("%d 라는 수가 있을때\n\n", placenumbers);
// 
// place3 = placenumbers / 100;
// place2 = (placenumbers - (place3 * 100)) / 10;
// place1 = placenumbers - (place3 * 100) - (place2 * 10);
// 
// printf("각 자리의 수는 ");
// printf("100자리 수는 %d, ", place3);
// printf("10자리 수는 %d, ", place2);
// printf("1자리 수는 %d\n", place1);
// 
// placeplus = place3 + place2 + place1;
// printf("각 자리의 수의 합은 %d\n\n\n", placeplus);
// 
// 
// printf("5. 파일용량 계산 \n\n");
// 
// int filesize = 0;
// int filesizekb = 0;
// int filesizeb = 0;
// 
// printf("확인할 파일용량 입력 : ");
// std::cin >> filesize;
// 
// filesizekb = filesize * 1024;
// filesizeb = filesizekb * 1024;
// 
// printf("파일 용량이 %d MB 일때\n", filesize);
// printf("이 파일 의 KB환산 용량은 %d KB 이고 ", filesizekb);
// printf("이 파일 의 Byte환산 용량은 %d Byte 이다 \n\n\n", filesizeb);
// 
// 
// printf("6. 타일 필요한 개수 구하기 \n\n");
// 
// int horizontalsize = 0;
// int verticalsize = 0;
// int tiles = 0;
// 
// printf("가로길이 입력 : ");
// std::cin >> horizontalsize;
// printf("세로길이 입력 : ");
// std::cin >> verticalsize;
// 
// printf("가로가 %d cm, 세로가 %d cm 인 방을 30cmx30cm 의 타일로 채우려면 \n", horizontalsize, verticalsize);
// tiles = ((horizontalsize + 30 - 1) / 30) * ((verticalsize + 30 - 1) / 30);
// printf("최소 %d 개의 타일이 필요하다\n\n\n\n\n\n\n\n", tiles);




// printf("2026-05-19 실습 1\n\n");

// int ABC = 43;
// printf("이 변수의 크기는 %d\n\n\n", int(sizeof(ABC)));
// 
// 
// printf("2026-05-18 실습 1\n\n");
// 
// 
// printf("1. 반지름을 입력받아 원의 넓이 구하기\n\n");
// printf("반지름을 입력 : ");
// 
// int circleradius = 0;
// 
// std::cin >> circleradius;
// 
// printf("이 원의 넓이는 %f\n\n", circleradius * circleradius * 3.141592f);
// 
// 
// printf("2. 3개의 값의 평균값 구하기\n\n");
// 
// float value1 = 0.0f;
// float value2 = 0.0f;
// float value3 = 0.0f;
// 
// printf("1번째 : ");
// std::cin >> value1;
// 
// printf("2번째 : ");
// std::cin >> value2;
// 
// printf("3번째 : ");
// std::cin >> value3;
// 
// printf("\n평균은 %.2f\n\n", (value1+value2+value3)/3);
// 
// 
// printf("3. 정가와 할인율을 입력받아 할인가 구하기\n\n");
// 
// int normalprice = 0;
// printf("이 제품의 원래 가격은 : ");
// std::cin >> normalprice;
// 
// float dicountpercent = 0.0f;
// printf("할인율은 : ");
// std::cin >> dicountpercent;
// 
// int totalprice = 0;
// totalprice = (normalprice * (100 - dicountpercent) / 100);
// 
// printf("\n할인가는 %d\n\n", totalprice);



// printf("2026-05-19 간단실습 1\n\n");
	// 
	// printf("1. 양수 음수 0 판단");
	// 
	// int number1 = 0;
	// int number2 = 0;
	// 
	// printf("\n\n수를 입력 : ");
	// std::cin >> number1;
	// 	
	// if (number1 > 0)
	// {
	// 	printf("입력받은 수는 양수임");
	// }
	// else if (number1 == 0)	
	// {
	// 	printf("입력받은 수는 0임");
	// }
	// else
	// {
	// 	printf("입력받은 수는 음수임");
	// }
	// 
	// //-------------------------------------------------------------------
	// //-------------------------------------------------------------------
	// 
	// printf("\n\n2. 홀수 짝수 판단");
	// 
	// printf("\n\n수를 입력 : ");
	// std::cin >> number1;
	// 
	// if (number1 % 2 == 0)
	// {
	// 	printf("입력받은 수는 짝수임");
	// }
	// 
	// else
	// {
	// 	printf("입력받은 수는 홀수임");
	// }
	// 
	// //-------------------------------------------------------------------
	// //-------------------------------------------------------------------
	// 
	// printf("\n\n3. 두 수의 대소 비교");
	// 
	// printf("\n첫번째 수를 입력 : ");
	// std::cin >> number1;
	// 
	// printf("\n\n두번째 수를 입력 : ");
	// std::cin >> number2;
	// 
	// if (number1 > number2)
	// {
	// 	printf("처음 입력한 수가 나중에 입력한 수보다 큼");
	// }
	// else if (number1 < number2)
	// 
	// {
	// 	printf("처음 입력한 수가 나중에 입력한 수보다 작음");
	// }
	// else
	// {
	// 	printf("처음 입력한 수가 나중에 입력한 수와 같음");
	// }
	// 
	// //-------------------------------------------------------------------
	// //-------------------------------------------------------------------
	// 
	// printf("\n\n\n2026-05-19 간단실습 2\n\n");
	// 
	// printf("1. 6세 이상, 120cm 이상일때 탑승가능, 그외 불가능 표시하기");
	// 
	// int age = 0;
	// int height = 0;
	// 
	// printf("\n\n나이를 입력(살) : ");
	// std::cin >> age;
	// 
	// printf("\n\n키를 입력(cm) : ");
	// std::cin >> height;
	// 
	// if (age >= 6 && height >= 120)
	// {
	// 	printf("\n탑승가능");
	// }
	// 
	// else
	// {
	// 	printf("탑승불가");
	// }
	// 
	// printf("\n\n2. 점수를 입력하여 90점이상 A, 80점이상 B, 70점이상 C, 60점이상 D, 그외 불가능 표시");
	// 
	// int score = 0;
	// 
	// printf("\n점수 입력 : ");
	// std::cin >> score;
	// 
	// if (score >= 90)
	// {
	// 	printf("\nA 학점");
	// }
	// else if (score >= 80)
	// {
	// 	printf("\nB 학점");
	// }
	// else if (score >= 70)
	// {
	// 	printf("\nC 학점");
	// }
	// else if (score >= 60)
	// {
	// 	printf("\nD 학점");
	// }
	// else
	// {
	// 	printf("\nF 학점");
	// }
	// 
	// printf("\n\n3. 세 과목의 점수를 입력하여 평균 60점 이상이면 합격, 그외 불합격. 한과목이라도 40점 미만시 과락\n");
	// 
	// int score1 = 0;
	// int score2 = 0;
	// int score3 = 0;
	// 
	// printf("첫번째 과목점수 입력 : ");
	// std::cin >> score1;
	// printf("두번째 과목점수 입력 : ");
	// std::cin >> score2;
	// printf("세번째 과목점수 입력 : ");
	// std::cin >> score3;
	// 
	// if ((score1 + score2 + score3) / 3 >= 60 && (score1 >= 40) && (score2 >= 40) && (score3 >= 40))
	// {
	// 	printf("\n합격\n\n\n\n\n");
	// }
	// else
	// {
	// 	printf("\n불합격\n\n\n\n\n");
	// }



	//  printf("\n\n\n2026-05-19 간단실습 3\n\n");
	//  
	//  
	//  printf("\n\n1. 3개의 정수를 입력받아 최대값과 최소값 구하기\n\n");
	//  
	//  int num1 = 0;
	//  int num2 = 0;
	//  int num3 = 0;
	//  
	//  printf("첫번째 수 입력 : ");
	//  std::cin >> num1;
	//  printf("두번째 수 입력 : ");
	//  std::cin >> num2;
	//  printf("세번째 수 입력 : ");
	//  std::cin >> num3;
	//  
	//  if (((num1 >= num2) && (num1 >= num3)))
	//  {
	//  	printf("\n최대값 : %d", num1);
	//  }
	//  else if (((num2 >= num1) && (num2 >= num3)))
	//  {
	//  	printf("\n최대값 : %d", num2);
	//  }
	//  else if (((num3 >= num1) && (num3 >= num2)))
	//  {
	//  	printf("\n최대값 : %d", num3);
	//  }
	//  else
	//  {
	//  	printf("오류");
	//  }
	//  
	//  
	//  
	//  if (((num1 <= num2) && (num1 <= num3)))
	//  {
	//  	printf("\n최소값 : %d", num1);
	//  }
	//  else if (((num2 <= num1) && (num2 <= num3)))
	//  {
	//  	printf("\n최소값 : %d", num2);
	//  }
	//  else if (((num3 <= num1) && (num3 <= num2)))
	//  {
	//  	printf("\n최소값 : %d", num3);
	//  }
	//  else if ((num1 == num2) && (num1 == num3))
	//  {
	//  	printf("\n최소값 : %d", num1);
	//  }
	
	
	//  printf("\n\n2. 3개의 수를 입력받아 삼각형 만들 수 있는지 보기 (양의 정수만 가능)\n\n");
	//  
	//  int linenum1 = 0;
	//  int linenum2 = 0;
	//  int linenum3 = 0;
	//  
	//  printf("첫번째 수 입력 : ");
	//  std::cin >> linenum1;
	//  printf("두번째 수 입력 : ");
	//  std::cin >> linenum2;
	//  printf("세번째 수 입력 : ");
	//  std::cin >> linenum3;
	//  
	//  if (!((linenum1 + linenum2) <= linenum3) && !((linenum2 + linenum3) <= linenum1) && !((linenum1 + linenum3) <= linenum2))
	//  {
	//  	printf("\n삼각형을 만들 수 있음");
	//  }
	//  else
	//  {
	//  	printf("\n삼각형을 만들 수 없음");
	//  }
	//  
	//  printf("\n\n3. 계산기\n\n");
	//  
	//  float calnum1 = 0;
	//  char caldirector = 0;
	//  float calnum2 = 0;
	//  float resultnum = 0;
	//  
	//  printf("첫번째 수 입력 : ");
	//  std::cin >> calnum1;
	//  printf("연산기호 입력 : ");
	//  std::cin >> caldirector;
	//  printf("두번째 수 입력 : ");
	//  std::cin >> calnum2;
	//  
	//  if (caldirector == '+')
	//  {
	//  	resultnum = (calnum1 + calnum2);
	//  	printf("\n\n%f", resultnum);
	//  }
	//  else if (caldirector == '-')
	//  {
	//  	resultnum = (calnum1 - calnum2);
	//  	printf("\n\n%f", resultnum);
	//  }
	//  else if (caldirector == '*')
	//  {
	//  	resultnum = (calnum1 * calnum2);
	//  	printf("\n\n%f", resultnum);
	//  }
	//  else if ((caldirector == '/') && !(calnum2 == 0))
	//  {
	//  	resultnum = (calnum1 / calnum2);
	//  	printf("\n\n%f", resultnum);
	//  }
	//  else if ((caldirector == '/') && (calnum2 == 0))
	//  {
	//  	printf("\n\n0으로 나눌 수 없음");
	//  }
	//  else
	//  {
	//  	printf("\n\n오류");
	//  }
	//  
	//  
	//  printf("\n\n\n4. 윤년 출력하기\n\n");
	//  
	//	printf("윤년 계산\n\n");
	//	int inputyear = 0;
	//	
	//	
	//	printf("연도 입력 : ");
	//	std::cin >> inputyear;
	//	
	//	if ((inputyear % 400 == 0) || (inputyear % 4 == 0) && !(inputyear % 100 == 0))
	//	{
	//		printf("\n윤년입니다");
	//	}
	//	else
	//	{		
	//		printf("\n윤년이 아닙니다");
	//	}



	// printf("2026-05-20 간단실습 1 \n\n\n");
	// 
	// printf("1. 비트 연산을 활용하여 홀,짝수 판별 \n\n\n");
	// 
	// unsigned int numbers = 0;
	// printf("값 입력 (양수만)\n\n");
	// std::cin >> numbers;
	// 
	// if ((numbers & 1) == 1)
	// {
	// 	printf("%u 는 홀수임\n\n", numbers);
	// }
	// else
	// {
	// 	printf("%u 는 짝수임\n\n", numbers);
	// }
	// 
	// 
	// printf("2. 캐릭터가 사용가능한 무기 enum 만들기. 데이터 사용하여 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 작성 \n\n\n");
	// 
	// enum weapontype
	// {
	// 	sword = 1,
	// 	hammer = 1 << 1,
	// 	bow = 1 << 2,
	// 	spear = 1 << 3,
	// 	shield = 1 << 4
	// };
	// 
	// int playerweaponavailables = sword | spear | shield; // 내 캐릭터는 칼, 창, 방패 사용가능
	// 
	// printf("확인할 무기를 입력해주세요\n (1-sword, 2-hammer, 3-bow, 4-spear, 5-shield) : ");
	// 
	// int selectweapon = 0;
	// std::cin >> selectweapon;
	// 
	// switch (selectweapon)
	// {
	// case 1:
	// 	if ((playerweaponavailables & sword) != 0)
	// 	{
	// 		printf("검을 사용할 수 있습니다\n");
	// 	}
	// 	else
	// 	{
	// 		printf("검을 사용할 수 없습니다\n");
	// 	}
	// 	break;
	// case 2:
	// 	if ((playerweaponavailables & hammer) != 0)
	// 	{
	// 		printf("해머를 사용할 수 있습니다\n");
	// 	}
	// 	else
	// 	{
	// 		printf("해머를 사용할 수 없습니다\n");
	// 	}
	// 	break;
	// case 3:
	// 	if ((playerweaponavailables & bow) != 0)
	// 	{
	// 		printf("활을 사용할 수 있습니다\n");
	// 	}
	// 	else
	// 	{
	// 		printf("활을 사용할 수 없습니다\n");
	// 	}
	// 	break;
	// case 4:
	// 	if ((playerweaponavailables & spear) != 0)
	// 	{
	// 		printf("창을 사용할 수 있습니다\n");
	// 	}
	// 	else
	// 	{
	// 		printf("창을 사용할 수 없습니다\n");
	// 	}
	// 	break;
	// case 5:
	// 	if ((playerweaponavailables & shield) != 0)
	// 	{
	// 		printf("방패를 사용할 수 있습니다\n");
	// 	}
	// 	else
	// 	{
	// 		printf("방패를 사용할 수 없습니다\n");
	// 	}
	// 	break;
	// }


	//  printf("2026-05-20 간단실습 2 \n\n\n");
	//  
	//  printf("1. 0 입력시까지 입력한 숫자 합 출력 \n\n\n");
	//  
	//  int inputnumber = -1;
	//  int savednumber = 0;
	//  
	//  while (inputnumber != 0)
	//  {
	//  	printf("더할 숫자 입력 (0 입력시 종료) [while문 사용함]: ");
	//  
	//  	std::cin >> inputnumber;
	//  
	//  	savednumber = (savednumber + inputnumber);
	//  
	//  	printf("현재 더해진 숫자들의 합 = %d\n", savednumber);
	//  }
	//  
	//  
	//  do
	//  {
	//  	printf("더할 숫자 입력 (0 입력시 종료) [do while문 사용]: ");
	//  
	//  	std::cin >> inputnumber;
	//  
	//  	savednumber = (savednumber + inputnumber);
	//  
	//  	printf("현재 더해진 숫자들의 합 = %d\n", savednumber);
	//  } while (inputnumber != 0);
	//  
	//  
	//  
	//  printf("\n\n2. 입력한 숫자의 구구단 출력 \n\n\n");
	//  
	//  int inputmultinumber = 0;
	//  int domultinumber = 1;
	//  
	//  printf("구구단 출력할 숫자 입력 : ");
	//  
	//  std::cin >> inputmultinumber;
	//  
	//  
	//  while (domultinumber < 10)
	//  {
	//  	printf("%d X %d = %d\n", inputmultinumber, domultinumber, (inputmultinumber * domultinumber));
	//  	domultinumber++;
	//  }
	//  
	//  
	//  printf("\n\n3. 1부터 입력받은 수 중 홀수만 출력하기 \n\n\n");
	//  
	//  int finalnumber = 0;
	//  int currentnumber = 1;
	//  
	//  
	//  printf("마지막 수 입력: ");
	//  
	//  std::cin >> finalnumber;
	//  
	//  while (currentnumber <= finalnumber)
	//  {
	//  	if ((currentnumber % 2) == 1)
	//  	{
	//  		printf("%d\n", currentnumber);
	//  		currentnumber++;
	//  	}
	//  	else
	//  	{
	//  		currentnumber++;
	//  	}
	//  }
	//  
	//  
	//  printf("\n\n4. 1부터 100중 7의 배수만 출력 \n\n\n");
	//  
	//  int current7findnum = 1;
	//  
	//  while (current7findnum <= 100)
	//  {
	//  	if ((current7findnum % 7) == 0)
	//  	{
	//  		printf("%d\n", current7findnum);
	//  		current7findnum++;
	//  	}
	//  	else
	//  	{
	//  		current7findnum++;
	//  	}
	//  }

	// ------------------------------------------------------------------------------

// printf("1. 주사위 베팅\n\n\n");
// 
// srand(time(0));
// 
// //srand(static_cast<unsigned int>(time(NULL)));
// 
// int playervalue = 10000; // 내 금액
// int comvalue = 10000; // 컴퓨터 금액
// 
// int playerrole1 = 0; // 내 주사위 처음 눈
// int comrole1 = 0; // 컴퓨터 주사위 처음 눈
// int playerrole2 = 0; // 내 주사위 두번째 눈
// int comrole2 = 0; // 컴퓨터 주사위 두번째 눈
// 
// int betvalue = 0; // 베팅금액
// int bets = 0; // 베팅하는쪽 (1: 플레이어, 2: 컴퓨터)
// 
// // 주사위 굴리기
// 
// while ((playervalue > 0) && (comvalue > 0))
// 
// {
// 
// 	playerrole1 = ((rand() * 7) % 6) + 1;
// 	comrole1 = ((rand() * 7) % 6) + 1;
// 
// 	while ((playerrole1 == comrole1) || (playerrole2 == comrole2) || ((playerrole1 + playerrole2) == (comrole1 + comrole2)))  // 중복조건 제거
// 	{
// 		playerrole1 = ((rand() * 7) % 6) + 1;
// 		comrole1 = ((rand() * 7) % 6) + 1;
// 		playerrole2 = ((rand() * 7) % 6) + 1;
// 		comrole2 = ((rand() * 7) % 6) + 1;
// 	}
// 
// 	printf("\n첫번째 플레이어 주사위의 눈은 %d, 컴퓨터 주사위의 눈은 %d 입니다.\n", playerrole1, comrole1);
// 
// 	if (playerrole1 > comrole1)
// 	{
// 		printf("\n플레이어 주사위의 눈이 컴퓨터 주사위의 눈보다 크므로 컴퓨터가 베팅을 진행합니다.\n");
// 		bets = 2;
// 	}
// 	else
// 	{
// 		printf("\n컴퓨터 주사위의 눈이 플레이어 주사위의 눈보다 크므로 플레이어가 베팅을 진행합니다.\n");
// 		bets = 1;
// 	}
// 
// 	// 베팅하기
// 
// 
// 
// 	if (bets == 1) // 플레이어가 진행
// 	{
// 		printf("\n베팅할 금액을 입력하세요 : (소지금 : %d)", playervalue);
// 		std::cin >> betvalue;
// 
// 		while ((betvalue > playervalue) || (betvalue > comvalue))
// 		{
// 			printf("\n베팅금액이 어느 한 쪽의 소지금액보다 큽니다. 다시 입력해주세요.\n");
// 
// 			printf("플레이어의 소지금 : %d\n", playervalue);
// 			printf("컴퓨터의 소지금 : %d\n", comvalue);
// 
// 			std::cin >> betvalue;
// 		}
// 
// 		printf("\n플레이어가 %d 금액을 베팅하였습니다.\n", betvalue);
// 
// 		playervalue = playervalue - betvalue;
// 		comvalue = comvalue - betvalue;
// 	}
// 	else if (bets == 2) // 컴퓨터가 진행
// 	{
// 		betvalue = (((rand() * 77) % 5000) + 1);
// 
// 		while ((betvalue > playervalue) || (betvalue > comvalue))
// 		{
// 			betvalue = (((rand() * 77) % 5000) + 1);
// 		}
// 
// 		playervalue = playervalue - betvalue;
// 		comvalue = comvalue - betvalue;
// 
// 		printf("\n컴퓨터가 %d 금액을 베팅하였습니다. (컴퓨터의 남은 소지금 : %d)\n", betvalue, comvalue);
// 	}
// 
// 
// 	// 두번째 주사위 굴리기 (처음에서 이미 돌림)
// 
// 	printf("\n두번째 플레이어 주사위의 눈은 %d, 컴퓨터 주사위의 눈은 %d 입니다.\n", playerrole2, comrole2);
// 
// 	// 첫번째와 두번째의 주사위의 합 비교
// 
// 	if ((playerrole1 + playerrole2) > (comrole1 + comrole2))
// 	{
// 		printf("\n플레이어 주사위 눈의 합은 %d, 컴퓨터 주사위 눈의 합은 %d 입니다\n", (playerrole1 + playerrole2), (comrole1 + comrole2));
// 		printf("\n플레이어가 승리하였으므로 베팅 금액을 모두 가져갑니다.\n");
// 
// 		playervalue = playervalue + (betvalue * 2);
// 	}
// 	else if ((playerrole1 + playerrole2) < (comrole1 + comrole2))
// 	{
// 		printf("\n플레이어 주사위 눈의 합은 %d, 컴퓨터 주사위 눈의 합은 %d 입니다\n", (playerrole1 + playerrole2), (comrole1 + comrole2));
// 		printf("\n컴퓨터가 승리하였으므로 컴퓨터가 베팅 금액을 모두 가져갑니다.\n");
// 
// 		comvalue = comvalue + (betvalue * 2);
// 	}
// }
// 
// if (playervalue <= 0)
// {
// 	printf("\n플레이어의 소지금이 부족하여 게임을 종료합니다.\n");
// }
// else if (comvalue <= 0)
// {
// 	printf("\n컴퓨터의 소지금이 부족하여 게임을 종료합니다.\n");
// }

