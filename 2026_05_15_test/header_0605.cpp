#include "header_0605.h"

// 배열1 {데이터1, 배열2의 주소}
// 배열2 {데이터2, 배열3의 주소}
// 배열3 {데이터3, 배열4의 주소}
// ...
// 배열100 {데이터100, null}

// 배열 네이밍의 숫자는 편의상 지정한 것


// 1.최초 배열1은 {데이터1, null}로 생성된다 

// 2. n번째부터는 그 전 배열[1](주소값임) 을 n을 바라보게 바꾸고, n번째 배열의 내용은 {데이터n, null}로 생성한다.

// 3. 특정 데이터를 가지고 있는 배열을 삭제하는 경우 그 배열의 주소값 내용(앞 배열을 가리키는 주소)을 전 배열에 전달하고 삭제후 할당 해제한다.
//	만약 삭제하려는 배열의 주소값 부분이 null로 되어있는 경우 그 전 배열의 주소값 부분을 null로 바꾼 다음 삭제후 할당 해제한다.

// 3.1 특정 주소를 가지고 있는 배열을 삭제하는 경우도 동일한 과정을 거                                       친다.

// 4. 첫번째 배열의 맨 앞부터 시작해서 주소를 한번 탈때마다 사이즈 1을 증가시킨다. 맨 마지막 배열의 주소값 부분이 null이 나오면 이 과정을 종료한다. (초기값 1로 시작)
//	그러면 이게 리스트의 크기가 된다.






linkedlist::~linkedlist()
{
	clear();
}

void linkedlist::clear()
{

}
void linkedlist::add(int indata)
{
	node* mynode = new node(indata);
	
	if ((node*) head == nullptr)
	{
		tail->next = mynode;
		size++;
	}
	

	
}

void linkedlist::insertAT(int indata, int inposition)
{
}

void linkedlist::remove(int indata)
{


}

void linkedlist::removeAT(int inposition)
{
}

node* linkedlist::search(int indata) const
{
	return nullptr;
}

void linkedlist::printlist() const
{
	

}
