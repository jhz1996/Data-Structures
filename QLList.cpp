#include "QLList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <iostream>
using namespace std;
//struct ListNode{
//	int data;
//	struct ListNode *next;
//};
//
//struct Queue{
//	struct ListNode *front;
//	struct ListNode *rear;
//
//};
//struct Queue *Q;
//struct ListNode *temp;


int main(){
	//QLList ;
	/*struct ListNode *next;*/
	/*QLList.ListNode(int i, struct ListNode next);*/
	QLList ok;
	
	ok.CreateQueue();
	ok.EnQueue(5);
	ok.EnQueue(6);
	//ok.DeQueue();
	ok.DeleteQueue();
	system("pause");
}