#pragma once


struct node
{
	int data = 0;								// 데이터부 (실제 데이터)
	node* next = nullptr;						// 링크부 (다음 노드를 가리킬 포인팅 부분)

	node(int indata) : data(indata) 
	{}
};


class linkedlist
{
public:

	linkedlist() = default;
	~linkedlist();

	void add(int indata);						// 리스트의 마지막에 데이터를 추가하는 함수
	void insertAT(int indata, int inposition);	// 리스트의 중간에 데이터를 추가하는 함수
	void remove(int indata);					// 특정 데이터를 가지는 노드를 제거하는 함수
	void removeAT(int inposition);				// 특정 번째의 노드를 제거하는 함수
	node* search(int indata) const;				// 특정 데이터가 있는지 찾는 함수, return 값이 null이면 없고 null이 아니면 있다.
	void clear();								// 모든 노드를 제거하는 함수
	void printlist() const;						// 리스트의 현재 상황을 출력하는 함수

private:

	node* head = nullptr;						// 리스트의 시작
	node* tail = nullptr;						// 리스트의 끝
	int size = 0;								// 전체 노드의 개수
};