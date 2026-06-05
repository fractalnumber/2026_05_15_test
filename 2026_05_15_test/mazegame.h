#pragma once

class Actor // 공통 클래스
{

public:

	std::string ActorName = "default";
	int HealthPoint = 150;
	int AttackPower = 5;
	
	Actor() = default;
	Actor(const std::string& InName, int InHealthPoint, int InAttackPower)
		: ActorName(InName),HealthPoint(InHealthPoint), AttackPower(InAttackPower)
	{	}

	//{		
		// 생성자
	//}


	~Actor() = default;
	//{
		// 소멸자
	//}
};
//--------------------------------------------------------------------------------------------------
class Player : public Actor // 플레이어용 클래스
{
public:
	Player() : Actor()
	{	}
	Player(const std::string& InName, int InHealthPoint, int InAttackPower)
		: Actor(InName,InHealthPoint,InAttackPower)
		

	{	}
};

class Monster : public Actor // 몬스터용 클래스
{
public:
	Monster() : Actor()
	{
	}
	Monster(const std::string& InName, int InHealthPoint, int InAttackPower)
		: Actor(InName, InHealthPoint, InAttackPower)
	{
	}
};
//--------------------------------------------------------------------------------------------------
class Troll : public Monster // 몬스터 하위 클래스 몹1
{
public:
	Troll() : Monster()
	{
	}
	Troll(const std::string& InName, int InHealthPoint, int InAttackPower)
		: Monster(InName, InHealthPoint, InAttackPower)
	{
	}
};

class Goblin : public Monster // 몬스터 하위 클래스 몹2
{
public:
	Goblin() : Monster()
	{
	}
	Goblin(const std::string& InName, int InHealthPoint, int InAttackPower)
		: Monster(InName, InHealthPoint, InAttackPower)
	{
	}
};

class Orc : public Monster // 몬스터 하위 클래스 몹3
{
public:
	Orc() : Monster()
	{
	}
	Orc(const std::string& InName, int InHealthPoint, int InAttackPower)
		: Monster(InName, InHealthPoint, InAttackPower)
	{
	}
};


void mazegame();

void mazegame_pause();

int MonsterBattle();

int RandNumGen();

