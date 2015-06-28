#include "QLList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <iostream>
#include<cstdio>
using namespace std;


int main(){
	string s = "OK";
	char name1[] = "John";
	char name2[] = "Thomas";
	char name3[] = "Albert";
	//QLList ;
	/*struct ListNode *next;*/
	/*QLList.ListNode(int i, struct ListNode next);*/
	QLList ok;
	
	/*char *cstr = new char[s.length() + 1];
	strcpy(cstr, s.c_str());
*/
	/*ok.EnQueue(cstr);*/
	ok.CreateQueue();
	ok.EnQueue(5);
	ok.EnQueue(6);
	/*ok.DeQueue();
	ok.DeQueue();
	ok.EnQueue(4);*/
	
	ok.EnQueue(4);
	ok.DeQueue();
	ok.DeleteQueue();
	cout << endl;
	ok.push_front(7);
	ok.DeleteQueue();
	cout << endl;
	//ok.pop_back();
	/*ok.DeQueue();*/
	cout<<ok.lengthOfQueue();
	ok.DeleteQueue();
	system("pause");
}