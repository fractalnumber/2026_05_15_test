#include "header_0602.h"


void Animal::Printinfo()
{
	printf("\n\n");
	printf("이름 : %s\n", AnimalName.c_str());
	printf("나이 : %.0f\n", Age);
	printf("에너지 : %d / %d", Energy, MaxEnergy);
}

void Animal::Move()
{
	if (Energy > 0)
	{
		printf("움직였다. 에너지 %d 감소\n", ConsumeMoveEnergy);
		Energy -= ConsumeMoveEnergy;
		printf("\n\n\n에너지 : %d / %d", Energy, MaxEnergy);
	}
	else
	{
		Energy = 0;
	}
	
}

void Animal::Eat_to_Recover()
{
	if (Energy + Eat_to_RecoverEnergy < MaxEnergy)
	{
		printf("음식을 먹었다.에너지가 %d 만큼 회복되었다\n", Eat_to_RecoverEnergy);
		Energy += Eat_to_RecoverEnergy;
	}
	
}

void Animal::Shout()
{
	printf("\n%s (이)가 소리를 질렀다. 아무 일도 일어나지 않았다.\n", AnimalName.c_str());
}


/*
void header0602()
{
	Animal* MyAnimal = new Animal();
	// MyAnimal->Printinfo();
	// MyAnimal->Move();
	
	// MyAnimal->GetAge();
	// MyAnimal->Age();

	Eagle* MyEagle = new Eagle("독수리",5);

	MyEagle->Printinfo();
	MyEagle->Fly();

	Animal* pEagle = MyEagle;
	// (Eagle*)pEagle;
	
	delete MyEagle;
	MyEagle = nullptr;

	Elephant* MyElephant = new Elephant("코끼리",30);

	MyElephant->Printinfo();
	MyElephant->Nose_Absorbtion();

	Animal* pElephant = MyElephant;

	delete MyElephant;
	MyElephant = nullptr;


	Crocodile* MyCrocodile = new Crocodile("악어",10);

	MyCrocodile->Printinfo();
	MyCrocodile->Bite();

	Animal* pCrocodile = MyCrocodile;

	delete MyCrocodile;
	MyCrocodile = nullptr;

}

void header0602_virtual()
{
	Animal* Zoo[3] = { nullptr, };
	Zoo[0] = new Eagle("독수리",5);
	Zoo[1] = new Elephant("코끼리",30);
	Zoo[2] = new Crocodile("악어",10);

	for (Animal* anim : Zoo)
	{
		anim->Printinfo();
		anim->Shout();
	}

	for (int i = 0; i < 3; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}
}

void Eagle::Fly()
{
	printf("\n");
	printf("하늘을 날고 있습니다. 에너지가 0 소모됩니다.\n");
}

void Elephant::Nose_Absorbtion()
{
	printf("\n");
	printf("코로 무언가를 빨아들이고 있습니다. 에너지가 소모되지는 않습니다.\n");
}

void Crocodile::Bite()
{
	printf("\n");
	printf("악어가 무언가를 물기 시작합니다.\n");
}
*/