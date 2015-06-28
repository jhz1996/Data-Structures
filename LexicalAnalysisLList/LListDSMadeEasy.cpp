#include "LListDsEasy.h"
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <string.h>
#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std; 

LList::LList(){
	p = NULL;
	head = NULL;
	q = NULL;
}
int LList::ListLength(){
	struct ListNode *current = head;
	int count = 0;

	while (current != NULL){
		count++;
		current = current->next;

	}
	return count;
}

void LList::InsertInLinkedList(char* data, int position){
	int k = 0;
	/*ListNode *p;
	ListNode *q;*/
	ListNode *newNode;
	newNode = (ListNode*)malloc(sizeof(struct ListNode));
	//malloc returns a pointer to memory that was allocated

	if (!newNode){
		printf("Memory-Error");
	}

	newNode->data = (char*)malloc(strlen(data) + 1);
	strcpy(newNode->data, data);
	p = head;

	if (position == 0){
		newNode->next = p;
		head = newNode;
	}

	else{

		while (p != NULL && k < position){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}

}

void LList::DeleteLinkedList(){
	struct ListNode *auxilaryNode, *iterator;
	iterator = head;

	while (iterator){
		auxilaryNode = iterator->next;
		free(iterator);
		iterator = auxilaryNode;
	}
	head = NULL;

}

void LList::DeleteNodeFromLinkedList(int position){
	int k = 0;
	//struct ListNode *p, *q;
	if (head == NULL){
		printf("List Empty");
		return;
	}

	p = head;

	if (position == 0){
		head = head->next;
		free(p);

	}

	else{

		while (p != NULL && k < position){
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL){
			printf("Position does not exist");
		}
		else{
			q->next = p->next;
			free(p);
		}

	}

}

void LList::PrintList(){
	/*if (p->next == NULL){
		cout << p->data;
	}*/
	
	p = head;
	while (p != NULL){
		cout << p->data<<", ";
		p = p->next;

	}

}

void LList::InsertInBack( char *data){
	ListNode *newNode;
	newNode = (ListNode*)malloc(sizeof(struct ListNode));

	if (!newNode){
		printf("Memory-Error");
	}

	newNode->data = (char*)malloc(strlen(data) + 1);
	strcpy(newNode->data, data);
	p = head;

	if (p == NULL){
		newNode->next = p;
		head = newNode;
	}
	else{
		while (p != NULL){
			q = p;
			p = p->next;
		}

		q->next = newNode;
		newNode->next = NULL;
	}
	cout << newNode->data;
	

	
}

void LList::InsertInFront(char* data){
	ListNode *newNode;
	newNode = (ListNode*)malloc(sizeof(struct ListNode));


	if (!newNode){
		printf("Memory-Error");
	}
	newNode->data = (char*)malloc(strlen(data) + 1);
	strcpy(newNode->data, data);
	if (head = NULL){
		head = newNode;
	}
	else{
		newNode->data = data;
		//p = head;
		newNode->next = head;

		head = newNode;
	}
}