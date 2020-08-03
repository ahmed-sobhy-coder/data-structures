#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
typedef struct node NODE;
struct node
{
    int data;
    NODE* next;
    NODE* (*deleteNode)(NODE* root, int data);
    void (*displayList)(NODE* root);
    void (*searchNode)(NODE* root, int data);
    int (*countNodes)(NODE* root);
    void (*insertAtEnd)(NODE* root, int data);
    NODE* (*insertAtBegin)(NODE* root, int data);
    NODE* (*insertAtPosition)(NODE* root, int data, int pos);
    void (*insertAfter)(NODE* root, int data, int pos);
    NODE* (*insertBefore)(NODE* root, int data, int value);
    int (*getNode)(NODE* root, int pos);
    void(*setNode)(NODE* root, int data, int pos);
    NODE* (*reverseList)(NODE* root);
};
NODE* deleteNode(NODE* root, int data);
void displayList(NODE* root);
void searchNode(NODE* root, int data);
int countNodes(NODE* root);
void insertAtEnd(NODE* root, int data);
NODE* insertAtBegin(NODE* root, int data);
NODE* insertAtPosition(NODE* root, int data, int pos);
NODE* CreateNewNode(int data);
void insertAfter(NODE* root, int data, int value);
NODE* insertBefore(NODE* root, int data, int value);
int getNode(NODE* root, int pos);
void setNode(NODE* root, int data, int pos);
NODE* reverseList(NODE* root);
#endif