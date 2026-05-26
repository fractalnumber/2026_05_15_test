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




////	 2026.05.20  비트 연산자, enum, 반복문, 랜덤


// 비트 연산

// 비트 AND -> & 를 하나만 사용
// 양변에 있는 데이터의 각 자리수의 비트가 둘다 1 이면 1 이다.
// 조건 만족 여부 확인할때 사용

// 비트 OR -> | 를 하나만 사용
// 양변에 있는 데이터의 각 자리수의 비트가 하나라도 1 이면 1 이다.
// 특정 부분에 값 세팅하고 싶을때 사용

// 비트 NOT -> ~
// 비트 값을 반대로 바꾼다.
// 

// 비트 XOR -> ^
// 양변에 있는 데이터의 각 자리수의 비트가 다르면 1, 같으면 0이다.
// 

// 비트 시프트
// 왼쪽 << , // 오른쪽 >>
// 2의 n제곱만큼 수가 변동


// enum (상수의 집합)

// enum weekdays {Mon,Tue,Wed,Thu,Fri,Sat,Sun}; <- 맨 왼쪽값은 0, 이후 1씩 증가. 특정 값에 숫자 지정하면 그 값부터 1씩 증가
// int enumtest1 = mon;

// enum bitflagtest
// {
// up	= 1 << 0
// down = 1 << 1
// left = 1 << 2
// down = 1 << 3
// };

// int direction = up | right; // 오른쪽 위
// direction = up | down | left | right; // 모든 방향


// 반복문 (statement)

// for (반복횟수를 정확히 지정할 때)

// for(int i = 0; i < 5; i++) // (int i = 0 은 변수 선언과 초기화, 세미콜론 뒤는 종료 조건, 두번째 세미콜론 뒤는 증감부)
// {
//	printf("hello world! %d"\n, i);
// }

// while (특정 조건이 성립하는 동안 반복해야 할 때)

// int j = 0;
// 

// do-while (특정 조건이 성립하는 동안 반복해야 할 때 (최소 1번 실행))


// 랜덤
// 
// srand(time(0));  // 랜덤값을 현재시간으로 설정
// 
// int randomnumber = 0;
// 
// randomnumber = rand();
// 
// printf("%d", randomnumber);


////	 2026.05.21 함수

// 함수 (특정 기능을 실행하는 코드 묶음)

// 선언부
// 함수의 틀 부분 (이름 형식 값 등.) 헤더에 선언


// 정의부
// 함수 동작 부분 ( {} 사이에 코드 작성.) cpp에 작성

// 구성요소
// 1. 리턴 타입 - 함수 실행을 마치고 나서 돌려주는 결과값
// 2. 함수 이름 - 함수 구분을 위해 붙이는 이름 (함수를 호출할 때 사용)
// 3. 파라미터 - 함수 호출 시 전달하는 값 (매개변수나 인자 로도 부름 / 데이터 타입과 이름으로 구성 / 0개 이상~)
// 4. 함수 바디 - 함수의 실제 실행 코드. 종료 시 return 사용.

//  int add(int num1, int num2)
//  {
//  	int addresult = num1 + num2;
//  	
//  	return addresult;
//  }
//  
//  int sub(int num1, int num2)
//  {
//  	int subresult = num1 - num2;
//  	return subresult;
//  }
//  
//  int mul(int num1, int num2)
//  {
//  	int mulresult = num1 * num2;
//  	return mulresult;
//  }
//  
//  int divide(int num1, int num2)
//  {	
//  	int divresult = 0;
//  	
//  	if (num2 != 0)
//  	{
//  		int divresult = num1 / num2;
//  	}
//  	return divresult;
//  }
//  
//  void test()
//  {
//  	return;
//  }

// pragma once : 헤더 중복기입시 오동작 방지 용도로 들어가있음.

// int add(int num1, int num2);
// 
// int sub(int num1, int num2);
// 
// int mul(int num1, int num2);
// 
// int divide(int num1, int num2);

// void test(); // return 필요 없음 , 파라미터 값도 필요 없음. 함수 종료가 필요할 시는 return 사용.


// template <typename T>  // 타입에 상관 없이 작성해야 할 때. 템플릿 작동내용은 헤더파일에 직접 작성
// T add(T num1, T num2);
// {
// 		T result = num1 + num2;
//		return result;
// }



////	 2026.05.22 배열, 2차원 배열, 캐스팅, 참조 , 랜덤


// 같은 종류의 데이터타입을 한번에 여러 개 저장할 때 사용
// 랜덤 액세스 속도가 빠름, 삽입이나 삭제가 까다롭다.

// int Num1, Num2, Num3; == int Numbers[3];

// Numbers [0] = 11;
// Numbers [1] = 22;
// Numbers [2] = 33;

// Numbers [0] = Numbers[1]; // 대입연산 가능

// Numbers [3] = 100; 선언된 값을 넘어 접근 불가

// int NumTest[5] = {1,3,5,6,7};
// int NumTest[5] = {3,5}; //  {3,5,0,0,0} 으로 채워짐

// int arraysize = sizeof(NumTest); // sizeof는 byte 단위로 값을 돌려줌.
// 배열의 항목 개수 = sizeof 결과값 / 데이터유형 값


// 2차원 배열

// int Numbers2[5][3]; (가로 3, 세로 5 의 배열(역순))
// int Numbers3[5][3] = {{1,2,3,4,5},{6,7,8,9,0},{11,12,13,14,15}};



// 캐스팅

// 어떤 값의 데이터 유형을 다른 유형으로 임시로 변경

// C스타일 (강제 변환)
// int A = 5;
// float B = (float)A;												// A에 있는 값을 float로 변경만 하고 float B에 저장한다.
// bool C = (bool)A;												// A에 있는 값을 bool로 변경만 하고 bool C에 저장한다.


// C++스타일
// 1. static_cast
//		C스타일 변환과 유사
//		문법적으로 변환이 허용되는 경우에만 변환
//		B = static_cast<float>(A);									// A에 있는 값을 float로 변경하고 B에 저장
// 2. dynamic_cast
//		상속 관계에서 사용. 다운캐스팅 (부모->자식 상속)			// 캐스팅이 가능하면 null이 아닌 값, 불가능하면 null 반환
//		RTTI (Runtime Type Information) 를 관리						// 변환속도가 매우 느림 (사용 비권장)
//		결과를 받을 변수 = dynamic_cast<캐스팅할 타입>(변수);	
// 3. const_cast
//		const나 volatile 속성을 추가/제거 할 때 사용				// 사용 비권장
// 4. reinterpret_cast
//		원래 구조를 무시하고 목표 타입으로 강제적으로 해석
//		포인터 타입 또는 유니온 변환 등에 사용
//		C스타일 캐스트의 부분을 그대로 가져온것						// 사용 비권장


// 참조 (변수의 별명)

// 한번 만들면 변수 변경이 불가능
// int& 별명 = 원래 변수이름;
// 별명에 값을 넣으면 원래 변수가 변경됨.
// 함수에서 여러 값을 돌려주게 하고싶을때 파라미터에 (int& 식으로 사용)


// 피셔-예이츠 알고리즘

// 1. 마지막 요소에서 자기 자신을 포함하여 랜덤한 요소 하나를 선택
// 2. 선택한 요소로 치환하고 그 자리는 완료 처리
// 3. 완료된 자리에서 이전 자리로 옮겨 반복



////		2026.05.26 포인터

// 메모리 주소를 저장하는 변수
// 데이터 타입에 * 붙임 (예 : int*  char* 등.)  

// (예1 : int* A = nullptr; // int 타입 변수의 주소를 저장하는 변수 A인데 기본값은 nullptr 이다.)
// (예2 : float* B = nullptr; // float 타입 변수의 주소를 저장하는 변수 B인데 기본값은 nullptr 이다.)
// (예3 : char* C = nullptr; // char타입 변수의 주소를 저장하는 변수 C인데 기본값은 nullptr 이다.)

//		포인터 연산자

// & (주소 연산자) : 변수 앞에 붙이면 그 변수의 주소를 돌려줌
// * (간접 참조 연산자) : 포인터 변수 앞에 붙이면 그 포인터 변수가 가리키는 실제 값을 돌려준다.

// int data = 10;
// a = &data; // data 라는 변수의 주소를 a에 저장한다.
// int temp = *a; // a가 가리키는 주소에 있는 실제 값(data) 을 temp에 넣는다. (곱연산과 혼동 주의. 확실히 하고싶으면 괄호 사용)

//		상수와 포인터

// const 는 자신의 왼쪽에 있는 것을 변경하지 않음 (왼쪽에 아무것도 없으면 오른쪽을 변경하지 않음)
// const int A 와 int const A 는 일단 동일

// const int* constpointer = &data; // constpointer 는 data의 주소를 가리키는데 그 값을 변경하지 않겠다.
// int* const constpointer = &data; // constpointer 는 data의 값을 가리키는데 그 주소를 변경하지 않겠다.

//		+ 연산과 - 연산

// int* A = &data;
// data = data + 1; // data의 주소크기에 해당 데이터 타입의 단일 단위크기 만큼 증가 
// data++; // data의 주소크기에 해당 데이터 타입의 단일 단위크기 만큼 증가
// data--; // data의 주소크기에 해당 데이터 타입의 단일 단위크기 만큼 감소

//		배열과 포인터

// int array = {1,2,3,4,5}
// int* parray = array; // array의 첫번째 요소의 주소를 parray 에 저장한다.
// array[1]; // array 의 두번째 요소
// parray + 1; // 포인터를 이용해서 두번째 요소에 접근

// 배열을 파라미터(함수)로 넘길때도 포인터를 활용한다.

// range-for : 배열이나 컨테이너의 첫 요소에서 마지막 요소까지 순차적으로 처리할 때 사용


//		c++의 메모리 영역
// 1. 코드 영역 (프로그램 실행 코드가 저장되는 공간)
// 2. 데이터 영역 (프로그램 시작부터 끝내기 전까지 변수가 저장되는 공간 (전역 변수, static 변수 등))
// 3. 스택 영역 (함수가 호출 될 때마다 필요한 변수 공간 (지역변수). 함수가 끝나면 자동으로 정리됨. 크기 제한 있음 (별도 설정 없을 시 1Mb)) 힙 영역보다 빠름
// 4. 힙 영역 (프로그램 실행 중 필요에 따라 직접 메모리를 할당, 사용하는 공간. 할당후에는 해제를 직접 해야 함 (크기는 컴퓨터 RAM 용량) 스택 영역보다 느림


//		동적 할당

// 프로그램 실행도중 메모리를 사용하기 위해 확보하는 행위 (처리 속도가 느림, 메모리 단편화 문제가 발생할 수 있음.)
// C++ 방식 : new, delete

// int* A = new int(5); // int 크기의 동적 할당을 받고 초기값 5를 설정하고 그 주소를 A에 저장함.
// delete A; (반드시 해야함. 안 하면 메모리 사용가능 부분이 이러한 방식을 사용할 때 마다 줄어듬)
// A = nullptr; (주소를 지운 다음 그곳의 값을 없앰. 다른 프로그램이 해당 부분을 할당받아 사용할 때 그 값이 영향을 끼치는 것을 방지)

// A = new int[10]; // int 10개 크기의 배열을 만든다.
// delete[] A; // 배열 할당 해제 시 []를 써야 함. 안 쓰면 맨 앞 부분만 해제됨