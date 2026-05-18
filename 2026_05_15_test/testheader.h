////	 2026.05.15 텍스트 출력 사용 예시

//	int main()
//	{
//		 std::cout << "hello world!";
//		 printf("hello world!");
//	 }


// \n 줄바꿈
// \t 탭키 효과





////	 2026.05.18 scanf , std::cin , 오류무시 , 변수 선언 , 연산


//  #define _CRT_SECURE_NO_WARNINGS

//	int number = 0;
//  int size = scanf("%d", &number);

//  std::cin >> number;
//  printf('input number is %d", number);



// 변수선언 예시     int ???? = XXX;    타입 integer , ???? 라는 변수 이름 , XXX 라는 값 지정

// int a = 10;				  // 32비트 정수
// short b = 500;	          // 16비트 정수
// long c = 100000;           // 32비트 또는 64비트
// char d = 255;              // 8비트 정수

// unsigned int a = 10;       // 부호 없는 32비트 정수
// unsigned short b = 500;    // 부호 없는 16비트 정수
// unsigned long c = 100000;  // 부호 없는 32비트 또는 64비트 (플랫폼에 따라 다름)
// unsigned char d = 255;     // 부호 없는 8비트 정수

// 변수 이름은 대소문자를 구분함.
// 숫자나 특수문자로 시작하는 이름 설정 불가.



// 연산

// +, -, *, /, % (산술연산)
// = (등호 왼쪽에 오른쪽의 값 대입)
// +=, -=, ++ (더하기 1), -- (빼기 1)


printf("2026-05-18 실습 1\n\n");

printf("1. 값 바꾸기\n\n");

int abcd = 50;
int efgh = 20;

printf("abcd: %d\n", abcd);
printf("efgh: %d\n\n", efgh);

printf("변수 1개 새로 선언 후 임시저장\n\n");

int ijkl = 0;

ijkl = efgh;
efgh = abcd;
abcd = ijkl;

printf("abcd: %d\n", abcd);
printf("efgh: %d\n\n", efgh);


printf("2. 값 합치기\n\n");

abcd = 50;
efgh = 20;

ijkl = abcd + efgh;
printf("efgh: %d\n\n", ijkl);

printf("3. 가로세로 곱해서 넓이 출력하기\n\n");

// abcd 와 efgh 곱하면 1000임
ijkl = abcd * efgh;
printf("넓이: %dm²\n\n", ijkl);


printf("4. 나머지 출력하기\n\n");

printf("4-1 %연산자 사용\n\n");
abcd = 50;
efgh = 20;

ijkl = abcd % efgh;

printf("나머지는: %d\n\n", ijkl);

printf("4-2 %연산자 미사용\n\n");

ijkl = abcd / efgh;

printf("나머지는: %d\n\n", ijkl);





printf("2026-05-18 실습 2\n\n");

printf("1. 섭씨->화씨 \n\n");
int ctemp = 0;
int ktemp = 0;

printf("확인할 온도 입력 : ");
std::cin >> ctemp;


ktemp = ctemp * 9 / 5 + 32;

printf("섭씨 온도가 %d도 면 ", ctemp);
printf("화씨 온도가 %d도 이다 \n\n\n", ktemp);


printf("2. 시간 출력하기 \n\n");

int sectime = 0;
int mintime = 0;
int hourtime = 0;

printf("확인할 시간 입력 : ");
std::cin >> sectime;

printf("%d초 를 변환하면 \n", sectime);

mintime = sectime / 60 % 60;
hourtime = sectime / 3600;
sectime = sectime % 60;

printf("%d 시간 ", hourtime);
printf("%d 분 ", mintime);
printf("%d 초\n\n\n", sectime);


printf("3. 동전계산 \n\n");

int money = 0;

printf("금액 입력 : ");
std::cin >> money;

printf("%d원이 있을때 \n", money);

int money_500 = 0;
int money_100 = 0;
int money_50 = 0;
int money_10 = 0;

money_500 = money / 500;
money_100 = money % 500 / 100;
money_50 = money % 100 / 50;
money_10 = money % 50 / 10;

printf("필요한 동전의 갯수는 각각 ");
printf("500원 %d개, ", money_500);
printf("100원 %d개, ", money_100);
printf("50원 %d개, ", money_50);
printf("10원 %d개가 된다.\n\n\n", money_10);


printf("4. 자리수 분리 \n\n");

int placenumbers = 0;
int place3 = 0;
int place2 = 0;
int place1 = 0;
int placeplus = 0;

printf("확인할 자리수 입력(3자리 제한) : ");
std::cin >> placenumbers;

printf("%d 라는 수가 있을때\n\n", placenumbers);

place3 = placenumbers / 100;
place2 = (placenumbers - (place3 * 100)) / 10;
place1 = placenumbers - (place3 * 100) - (place2 * 10);

printf("각 자리의 수는 ");
printf("100자리 수는 %d, ", place3);
printf("10자리 수는 %d, ", place2);
printf("1자리 수는 %d\n", place1);

placeplus = place3 + place2 + place1;
printf("각 자리의 수의 합은 %d\n\n\n", placeplus);


printf("5. 파일용량 계산 \n\n");

int filesize = 0;
int filesizekb = 0;
int filesizeb = 0;

printf("확인할 파일용량 입력 : ");
std::cin >> filesize;

filesizekb = filesize * 1024;
filesizeb = filesizekb * 1024;

printf("파일 용량이 %d MB 일때\n", filesize);
printf("이 파일 의 KB환산 용량은 %d KB 이고 ", filesizekb);
printf("이 파일 의 Byte환산 용량은 %d Byte 이다 \n\n\n", filesizeb);


printf("6. 타일 필요한 개수 구하기 \n\n");

int horizontalsize = 0;
int verticalsize = 0;
int tiles = 0;

printf("가로길이 입력 : ");
std::cin >> horizontalsize;
printf("세로길이 입력 : ");
std::cin >> verticalsize;

printf("가로가 %d cm, 세로가 %d cm 인 방을 30cmx30cm 의 타일로 채우려면 \n", horizontalsize, verticalsize);
tiles = ((horizontalsize + 30 - 1) / 30) * ((verticalsize + 30 - 1) / 30);
printf("최소 %d 개의 타일이 필요하다\n\n\n\n\n\n\n\n", tiles);