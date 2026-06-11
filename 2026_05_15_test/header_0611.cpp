#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <sstream>
#include <map>
#include "header_0611.h"



void MinMax()
{
	printf("1. 최대값 최소값 찾기\n\n");

	std::vector<int>FindMinMaxArray = {43,56,233,54,21,6,74,3,96};	
	printf("정수 목록은 : ");

	for (int i = 0; i < FindMinMaxArray.size(); i++)
	{
		printf("[%d] ",FindMinMaxArray[i]);
	}
	std::vector<int>::iterator FindMax = std::max_element(FindMinMaxArray.begin(), FindMinMaxArray.end());
	std::vector<int>::iterator FindMin = std::min_element(FindMinMaxArray.begin(), FindMinMaxArray.end());
	printf("\n최대값은 : [%d]", *FindMax);
	printf("\n최소값은 : [%d]", *FindMin);
	
}

void NoEqual()
{

	printf("\n\n2. 중복 정수값 제거\n\n");

	std::vector<int>NoEqualArray = { 7,23,54,65,23,4,120,42,54 };
	printf("정수 목록은 : ");

	for (int i = 0; i < NoEqualArray.size(); i++)
	{
		printf("[%d] ", NoEqualArray[i]);
	}

	std::sort(NoEqualArray.begin(), NoEqualArray.end());
	NoEqualArray.erase(std::unique(NoEqualArray.begin(), NoEqualArray.end()), NoEqualArray.end());

	printf("\n중복 값 제거한 정수 목록은 : ");

	for (int i = 0; i < NoEqualArray.size(); i++)
	{
		printf("[%d] ", NoEqualArray[i]);
	}
	
}

void NoEqualString()
{
	printf("\n\n3. 문자열에서 중복되는 글자 제거\n\n");

	std::string NoEqualChar = "ThisisTestMessage";
	std::string Result = "";
	std::unordered_set<char> First;

	printf("%s 라는 문장이 있다.", NoEqualChar.c_str());


	//-----------------------
	//printf("\n문장 길이는... %d", StringLength);

	for (char c : NoEqualChar)
	{
		if (First.find(c) == First.end())
		{
			First.insert(c);
			Result += c;
		}
	}

	//------------------------
	printf("\n중복 글자 제거 후 %s 이 된다.", Result.c_str());	
	


}

void CharCount()
{
	printf("\n\n4. 문장에서 중복되는 단어 개별 카운트\n\n");

	std::vector<std::string> Strings = { "1","2","100","2","2","3","3","3","84","43","25" };
	std::map<std::string, int> FindChar;

	printf("전체 문장은 : ");

	for (int i = 0; i < Strings.size(); i++)
	{
		printf("%s ", Strings[i].c_str());
	}

	// 빈도수 계산
	for (const auto& String : Strings) {
		FindChar[String]++;
	}

	printf("\n");
	// 결과 출력
	for (const auto& pair : FindChar) {
		std::cout << pair.first << " : " << pair.second << "개\n";
	}

}
