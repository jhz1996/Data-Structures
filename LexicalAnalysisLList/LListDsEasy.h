using namespace std;
#include <iostream>


class LList{
private:
	struct ListNode{
		char* data;
		struct ListNode* next;

	};
	ListNode *p;
	ListNode *head;
	ListNode *q;
public:

	LList();
	int ListLength();
	void InsertInLinkedList(char* data, int position);
	void DeleteNodeFromLinkedList(int position);
	void DeleteLinkedList();
	void PrintList();
	void LList::InsertInBack(char* data);
	void LList::InsertInFront(char* data);

};

	
	


