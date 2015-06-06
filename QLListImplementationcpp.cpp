#include "QLList.h"

#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string.h>
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include<algorithm>
#include<string>

using namespace std;

QLList::QLList(){
	Q = NULL;
	temp = NULL;

}

void QLList::CreateQueue(){
	/*struct Queue *Q;
	struct ListNode *temp;*/
	Q = (Queue*)malloc(sizeof(struct Queue));
	/*
	if (!Q){
	return NULL;
	}*/

	temp = (ListNode*)malloc(sizeof(struct ListNode));
	Q->front = Q->rear = NULL;
	//return Q;
}

int QLList::isEmptyQueue(){

	return(Q->front == NULL);

}

void QLList::EnQueue(int data){
	struct ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(struct ListNode));
	if (!newNode){
		return;

	}

	newNode->data = data;
	newNode->next = NULL;
	if (Q->rear){
		while (Q->rear->next != NULL){
			Q->rear = Q->rear->next;

		}
		Q->rear->next = newNode;

	}
	
	else if (Q->front == NULL){
		Q->front = newNode;
		Q->rear = Q->front;
	}

}

int QLList::DeQueue(){
	int data = 0;
	struct ListNode *temp;
	if (isEmptyQueue()){
		printf("Queue is Empty");
		return 0;
	}

	else{
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;


}

void QLList::DeleteQueue(){
	struct ListNode *t;
	/*while (Q->front){
		t = Q->front;
		cout << Q->front->data;
		t = t->next;
		free(Q->front);
	}
	free(Q);*/

	t = Q->front;
	if (Q->front == NULL){
		cout << "nothing to display";
	}

	else{
		while (t != NULL){
			cout << endl << t->data;
			t = t->next;
		}
	}

}

int QLList::lengthOfQueue(){
	int count = 0;
	temp = Q->front;
	while (temp!= NULL){

		temp = temp->next;
		++count;

	}


	return count;
}

void QLList::push_front(int data){
	struct ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(struct ListNode));
	
	newNode->data = data;
	newNode->next = NULL;
	temp = Q->front;
	if (Q->front != NULL){
		
		Q->front = newNode;
		Q->front->next = temp;
	}

	else{
		Q->front = newNode;
		Q->front->next = NULL;
	}


}

void QLList::pop_back(){
	temp = Q->front;
	while (temp->next != Q->rear){
		temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;
	


}