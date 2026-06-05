#pragma once

#include <iostream>
#include <string>



// 예제) 동물 클래스

// 움직이면 에너지를 소비함
// 소리를 지른다
// 먹을 수 있음 (에너지를 회복함)
// 잠을 잘 수 있다 (나이가 증가하고 에너지가 회복됨)
// 자신의 모든 정보를 출력한다.

class Animal
{

public:

	std::string AnimalName = "동물";
	float Age = 20;
	int Energy = 500;
	int MaxEnergy = 1000;

	const int ConsumeMoveEnergy = 1;
	const int Eat_to_RecoverEnergy = 20;

	char Keyinput = '0';
	
	Animal() = default;
	Animal(const std::string& InName, float& InAge) : AnimalName(InName), Age(InAge)
	{
	}
	/*
	Animal(float& InAge) : Age(InAge)
	{
	}
	Animal(int& InEnergy) : Energy(InEnergy)
	{
	}
	Animal(int& InMaxEnergy) : Energy(InMaxEnergy)
	{
	}
	*/

	//{		
		// 생성자
	//}


	~Animal() = default;
	//{
		// 소멸자
	//}


	void Printinfo();
	void Move();
	void Eat_to_Recover();
	void Shout();

	
	
	
public:

	// getter, setter // 프로그래머의 의도에 따라 사용처를 한정시키기 위함

	// float GetAge() const; // const의 의미는 함수 내에서 다른 멤버 변수를 수정하지 않겠다.
	// inline float GetAge() const { return Age; } // getter
	// inline void SetAge(float InAge) { Age = InAge; } // setter

};

// -------------------------------------------------------

class Eagle : public Animal // 거의 모든 상황에서 public만 사용함
{
public:
	Eagle() :Animal()
	{	}
	Eagle(const std::string& InName, float& InAge):Animal(InName, InAge)
	{	}
	/*
	Eagle(float& InAge) :Animal(InAge)
	{	}
	Eagle(int& InEnergy) : Animal(InEnergy)
	{	}
	Eagle(int& InMaxEnergy) : Animal(InMaxEnergy)
	{	}
	*/
	void Fly();

private:
	const float FlyEnergy = 20.0f;
};

// -------------------------------------------------------

class Elephant : public Animal 
{
public:
	Elephant() :Animal()
	{	}
	Elephant(const std::string& InName, float& InAge) :Animal(InName, InAge)
	{	}
	/*
	Elephant(float& InAge) :Animal(InAge)
	{	}
	Elephant(int& InEnergy) : Animal(InEnergy)
	{	}
	Elephant(int& InMaxEnergy) : Animal(InMaxEnergy)
	{	}
	*/
	void Nose_Absorbtion();

};

// -------------------------------------------------------

class Crocodile : public Animal
{
public:
	Crocodile() :Animal()
	{	}
	Crocodile(const std::string& InName, float& InAge) :Animal(InName, InAge)
	{	}
	/*
	Crocodile(float& InAge) :Animal(InAge)
	{	}
	Crocodile(int& InEnergy) : Animal(InEnergy)
	{	}
	Crocodile(int& InMaxEnergy) : Animal(InMaxEnergy)
	{	}
	*/
	void Bite();

};




void header0602();
void header0602_virtual();

