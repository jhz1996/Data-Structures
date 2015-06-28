

class ULList{
private:
	struct LinkedBlock{
		struct LinkedBlock *next;
		struct ListNode *head;
		int nodeCount;

	};

	struct ListNode{
		struct ListNode* next;
		int value;
	};

	struct LinkedBlock* blockHead;
	


public:

	

	ULList();
	struct LinkedBlock* newLinkedBlock();
	struct ListNode* ULList::newListNode(int value);
	



};