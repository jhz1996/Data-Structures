#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include<iostream>
using namespace std;
struct Queue{
	struct ListNode *front;
	struct ListNode *rear;

};

struct ListNode{
	int data;
	struct ListNode *next;
};

//struct Queue *CreateQueue(){
//	struct Queue *Q;
//	struct ListNode *temp;
//	Q = (Queue*)malloc(sizeof(struct Queue));
//
//
//	temp = (ListNode*)malloc(sizeof(struct ListNode));
//	Q->front = Q->rear = NULL;
//	//return Q;
//	return Q;
//}
//
//int IsEmptyQueue(struct Queue *Q){
//	return(Q->front == NULL);
//}
//
//void EnQueue(struct Queue *Q, int data){
//	struct ListNode* newNode;
//	newNode = (ListNode*)malloc(sizeof(struct ListNode));
//	//newNode = malloc(sizeof(struct ListNode));
//	if (!newNode){
//		return;
//
//	}
//
//	newNode->data = data;
//	newNode->next = NULL;
//	if (Q->rear){
//		while (Q->rear->next != NULL){
//			Q->rear = Q->rear->next;
//
//		}
//		Q->rear->next = newNode;
//
//	}
//
//	else if (Q->front == NULL){
//		Q->front = newNode;
//		Q->rear = Q->front;
//	}
//
//}
//
//int DeQueue(struct Queue *Q){
//	int data = 0;
//	struct ListNode *temp;
//	if (IsEmptyQueue(Q)){
//		printf("Queue is Empty");
//		return 0;
//	}
//
//	else{
//		temp = Q->front;
//		data = Q->front->data;
//		Q->front = Q->front->next;
//		free(temp);
//	}
//	return data;
//
//
//}
//
//void DeleteQueue(struct Queue *Q){
//	struct ListNode *temp;
//
//	temp = Q->front;
//	if (Q->front == NULL){
//		return;
//	}
//
//	else{
//		while (temp != NULL){
//			free(temp);
//			temp = temp->next;
//		}
//	}
//
//
//}

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	printf("%d ", node->data);

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	printf("%d ", node->data);

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}


void clear(queue<node*> &q)
{
	std::queue<node*> empty;
	std::swap(q, empty);
}

//node* InsertInBinaryTree(struct node* root, int data){
//	queue < node* > Q;
//	struct node *temp;
//	struct node *newNode;
//	newNode = (struct node*)malloc(sizeof(struct node));
//
//	newNode->left = newNode->right = NULL;
//	newNode->data = data;
//	/*struct ListNode *test;
//	test = (ListNode*)malloc(sizeof(struct ListNode));*/
//
//
//	//if (!newNode){
//	//	printf("Memory Error"); 
//	//	return;
//	//}
//
//	if (!root){
//		root = newNode;
//		return root;
//
//	}
//	/*Q = CreateQueue();*/
//	Q.push(newNode);
//	
//	while (!Q.empty()){
//		temp = Q.front();
//		if (temp != NULL){
//			if (temp->left!=NULL){
//				Q.push(temp->left);
//
//			}
//			else{
//				temp->left = newNode;
//				return root;
//			}
//			if (temp->right!=NULL){
//				/*EnQueue(Q, temp->right);*/
//				Q.push(temp->right);
//			}
//
//			else{
//				temp->right = newNode;
//				return root;
//				
//			}
//		}
//		return root;
//	}
//	/*clear(Q);*/
//	
//}
void PrintArray(int ints[], int len){
	for (int i = 0; i < len; i++){
		printf("%d", ints[i]);
		printf(" ");
	}
}
void PrintPathsRecur(struct node* root, int path[], int pathLen){
	if (root == NULL){
		return;
	}

	path[pathLen] = root->data;
	pathLen++;

	if (root->left == NULL && root->right == NULL){
		PrintArray(path, pathLen);
	}

	else{
		PrintPathsRecur(root->left, path, pathLen);
		PrintPathsRecur(root->right, path, pathLen);

	}

}

int DiameterOfTree(struct node* root, int *ptr){
	int left, right;
	if (!root){
		return 0;

	}
	left = DiameterOfTree(root->left, ptr);
	right = DiameterOfTree(root->right, ptr);

	if (left + right > *ptr){
		*ptr = left + right;
	}
	return max(left, right) + 1;
}

struct node* MirrorOfBinaryTree(struct node* root){
	struct node* temp;

	if (root){
		MirrorOfBinaryTree(root->left);
		MirrorOfBinaryTree(root->right);

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}


void PrintArray(int ints[], int len);

/* Driver program to test above functions*/
int main()
{
	int path[100];
	int ptr = 0;
	struct node *root = newNode(1);
	/*InsertInBinaryTree(root, 5);
	InsertInBinaryTree(root, 6);
	InsertInBinaryTree(root, 8);
	InsertInBinaryTree(root, 11);*/
	/*insertNode(root, 2);
	insertNode(root, 3);
	insertNode(root, 7);*/
	root->left = newNode(2);
	root->right = newNode(3);
	/*root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(11);*/
	MirrorOfBinaryTree(root);



	cout<<DiameterOfTree(root, &ptr);
	printf("\n Preorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\n Inorder traversal of binary tree is \n");
	printInorder(root);

	printf("\n Postorder traversal of binary tree is \n");
	printPostorder(root);

	PrintPathsRecur(root, path, 0);
	
	getchar();
	return 0;
}