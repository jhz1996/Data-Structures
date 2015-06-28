using namespace std;
#include <string>
#include <iostream>
class QLList{
private:
	struct ListNode{
		int data;
		struct ListNode *next;
	};

	struct Queue{
		struct ListNode *front;
		struct ListNode *rear;
		
	};
	struct Queue *Q;
	struct ListNode *temp;

public:
	QLList();
	void CreateQueue();
	int isEmptyQueue();
	void EnQueue(int data);
	int DeQueue();
	void DeleteQueue();
	int lengthOfQueue();
	void QLList::push_front(int data);
	void QLList::pop_back();


};