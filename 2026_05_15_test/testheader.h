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




////	 2026.05.19 이진수, 부동소수점, 부울, 글자, 흐름 제어 (조건)


// 부동소수점 (float)

// 소수점 아래부분이 정확하지 않음.
// float A = 1f (32비트)
// float B = 1 (64비트)
// ABC = (float)53;  <- 명시적 변환
// float ABC = 154892.254583;
// printf("실수 연습 %X.Yf", ABC);
// 소수점 위 X자리, 소수점 아래 Y자리까지 출력



// 부울 (bool)

// 1바이트
// 참, 거짓 판단



// 글자 (char)

// 8bit 데이터 타입
// 글자 표시에 사용
// char word is 'a';  (주 : 글자에는 작은따옴표 사용)
// printf("글자 테스트 %c", chara);



// 조건문

// 조건에 따라 특정 동작을 실행하게 함
// 비교 연산자 : 크기, 동일 등을 비교 (bool)
// bool ABC = true;
// ABC = 10 > 5 // true;
// ABC = 10 < 5 // false;
// ABC = 10 >= 5 // true;
// ABC = 10 == 5 // false; (== : 비교연산 사용)
// ABC = 10 <= 5 // false; 
// ABC = 10 >= 10 // true;
// ABC = 10 > 10 // false;
// ABC = 0.2f + 0.5f == 0.7f; (해당 용도로 사용 금지)

// if (참, 거짓 분기. 조건 만족 시 {} 안의 내용 실행)

// int a = 30;
// int b = 20;
// 
// if (a > b)
// 
// {
// 	printf("참 텍스트");
// }
// else
// {
// 	printf("거짓 텍스트");
// }
// elseif (if를 계속 사용)

// switch (상세 조건 분기. 조건 만족 시 {} 안의 내용 실행)
// break (해당 명령줄에서 실행 마치고 중괄호를 나감)

// int a = 10;
// 
// switch (a)
// 
// {
// case 1:
// 	printf("a는 1입니다.\n");
// 	break;
// case 2:
// 	printf("a는 10입니다\n");
// 	break;

// 삼향연산자

// int x = (a > 10) ? 1 : 0;  // ?앞의 조건식이 참이면 ?와 : 사이에 있는 값, 거짓이면 : 뒤에 있는 값

// 논리연산 (bool 관련)

// && (AND) , || (OR) , ! (NOT)
//