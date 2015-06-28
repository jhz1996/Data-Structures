//#include "ULList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int blockSize=2;
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

	/*ULList::ULList(){
		struct ListNode* next=NULL;
		struct LinkedBlock *next=NULL;
		struct ListNode *head=NULL;
}
*/

struct LinkedBlock* newLinkedBlock(){
	struct LinkedBlock* block = (struct LinkedBlock*)malloc(sizeof(struct LinkedBlock));
	block->next = NULL;
	block->head = NULL;
	block->nodeCount = 0;
	return block;

}

struct ListNode* newListNode(int value){
	struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	temp->next = NULL;
	temp->value = value;
	return temp;

}
//2nd parameter is the current LinkedBlock
void searchElement(int k, struct LinkedBlock **fLinkedBlock, struct ListNode **fListNode){

	int j = (k + blockSize - 1) / blockSize; //check to see if our position is in a different block....if k>blocksize +1 then we are in a different block
	struct LinkedBlock* p = blockHead; //start at the first block
	while (--j){
		p = p->next;

	}

	*fLinkedBlock = p;    //set an arbitrary block fLinkedBlock equal to the current block we are on

	struct ListNode *q = p->head;     //create a new temp node q and set equal to the head of the current block we are on
	k = k%blockSize;      
	if (k == 0){
		k = blockSize;   
		k = p->nodeCount + 1 - k; //if we are in the first block then increment the current counter for the amount of nodes in the list;
	}

	while (k--){ //keep iterating until we reach the kth element in the block. We are finding the next empty space for the kth element we will insert in the block
		q = q->next;

	}
	*fListNode = q;
}

void shift(struct LinkedBlock *A){
	struct LinkedBlock *B;
	struct ListNode*temp;
		while (A->nodeCount > blockSize){

			if (A->next == NULL){
				A->next = newLinkedBlock();
				B = A->next;
				temp = A->head->next;
				A->head->next = A->head->next->next;
				B->head = temp;
				temp->next = temp;
				A->nodeCount--;
				B->nodeCount++;
			}

			else{
				B = A->next;
				temp = A->head->next;
				A->head->next = A->head->next->next;
				temp->next = B->head->next;
				B->head->next = temp;
				B->head = temp;
				A->nodeCount--;
				B->nodeCount++;
			}
			A = B;
		}
}

void addElement(int k, int x){
	struct ListNode *p, *q;
	struct LinkedBlock *r;

	if (!blockHead){
		blockHead = newLinkedBlock();  //if there is no head create one
		blockHead->head = newListNode(x); //set the head of the block to be the new node
		blockHead->head->next = blockHead->head; //and have the blockhead's head point to itself
		blockHead->nodeCount++;

	}

	else{
		if (k == 0){
			p = blockHead->head;
			q = p->next;   //q is one step ahead of p
			p->next = newListNode(x);
			p->next->next = q;
			blockHead->head = p->next;
			blockHead->nodeCount++;
			shift(blockHead);

		}

		else{
			searchElement(k, &r, &p);
			q = p; //
			while (q->next != p){ //while we are not at the end of the list keep iterating. You are at the end of the list when the endNode->next equals itself
				q = q->next; //q should be one ahead of p

			}
			q->next = newListNode(x);
			q->next->next = p; //q points to null now BUT this is used to shift q.
			r->nodeCount++;
			shift(r);

		}
	}
}

int searchElement(int k){

	struct ListNode *p;
	struct LinkedBlock *q;
	searchElement(k, &q, &p);
	return p->value;

}

int testUnRolledLinkedList(){
	int tt = clock();
	int m, k, x;
	char cmd[10];

	scanf("%d", &m);
	blockSize = (int)(sqrt(m - 0.001)) + 1;

	for (int i = 0; i < m; i++){
		scanf("%s", cmd);
		if (strcmp(cmd, "add") == 0){
			scanf("%d %d", &k, &x);
			addElement(k, x);
		}

		else if (strcmp(cmd, "search") == 0){
			scanf("%d", &k);
			printf("%d\n", searchElement(k));
		}
		else{
			fprintf(stderr, "Wrong Input\n");
		}

	}
	return 0;
}

int main(){
	addElement(0, 1);
	addElement(1, 2);
	addElement(2, 3);



}