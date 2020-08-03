#include "single_linked.h"
#include "stdio.h"
NODE* CreateNewNode(int data)
{
    NODE* newNode;
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->data = data;
    newNode->deleteNode = deleteNode;
    newNode->displayList = displayList;
    newNode->searchNode = searchNode;
    newNode->countNodes = countNodes;
    newNode->insertAtEnd = insertAtEnd;
    newNode->insertAtBegin = insertAtBegin;
    newNode->insertAtPosition = insertAtPosition;
    newNode->insertAfter = insertAfter;
    newNode->insertBefore = insertBefore;
    newNode->getNode = getNode;
    newNode->setNode = setNode;
    newNode->reverseList = reverseList;
    return newNode;
}
NODE* insertAtBegin(NODE* root, int data)
{
    NODE* node = CreateNewNode(data);
    node->next = root;
    root = node;
    return root;
}
void insertAtEnd(NODE* root, int data)
{
    NODE** node;
    if (root == NULL)
    {
        printf("list in not created\n");
    }
    else
    {
        node = CreateNewNode(data);
        while (root->next != NULL)
        {
            root = root->next;
        }
        root->next = node;
    }
}
NODE* createList(NODE* root)
{
    int count = 0, nNodes;
    int data;
    printf("enter the number of nodes : ");
    scanf("%dh", &nNodes);
    if (nNodes > 0)
    {
        if (root == NULL)
        {
            printf("Enter the first element to be inserted: ");
            scanf("%d", &data);
            root = insertAtBegin(root, data);
            nNodes--;
        }
        for (count = 0; count < nNodes; count++)
        {
            printf("Enter the next element to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(root, data);
        }
    }
    printf("\n");
    return root;
}
/* insert node after certian node
   this function takes 3 parameters:
   root: is pointer to the list
   data:the new node data
   value:the rquired node  data
*/
void insertAfter(NODE* root, int data, int value)
{
    NODE* node; //node is used to hold the address of the new created node
    NODE* head = root;//head is used to get the next node it is like a counter
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else //list is not empty
    {
        while ((head != NULL) && (head->data != value)) //loop until finding the required node
        {
            head = head->next; //get next node
        }

        if (head == NULL) //if root reached to NULL, this means node value is not in the list 
        {
            printf("\n\n not present in the list \n\n");//print to user that the node value is not in the list
        }
        else
        {
            node = CreateNewNode(data);//create new node
            node->next = head->next;//make the next pointer of the new created node points to the node which has the required value
            head->next = node;//make the next pointer of the node before the node which has the required value points to new created node
        }
    }
}
NODE* insertBefore(NODE* root, int data, int value)
{
    NODE* node;  //node is used to hold the address of the new created node
    NODE* head = root;//head is used to get the next node it is like a counter
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else //list is not empty
    {
        if (head->data == value)//value is in the first node, new node is to be inserted before the first node
        {
            root = root->insertAtBegin(root, data);//inset new node before the first node
        }
        else //insert new node between nodes
        {
            while ((head->next != NULL) && (head->next->data != value))//find pointer to node before the node which has value
            {
                head = head->next;//get next node
            }
            if (head->next == NULL)//after looping, head next points to null this means the rquired node whih has the value is not exist
            {
                printf("\n\nnot present in the list\n\n"); //print this node is not in the list
            }
            else if (head->next->data == value)//if the node which has the value is exist
            {
                node = CreateNewNode(data);//create new node
                node->next = head->next;//make the next pointer of the new created node points to the node which has the value
                head->next = node;//make the next pointer of the node before the node which has the required value points to new created node
            }
        }
    }
    return root; //return pointer to list
}
/*
this function counts number of nodes in the list
*/
int countNodes(NODE* root)
{
    int count = 0;//is used as a counter
    while (root != NULL)//loop all nodes until root becomes bull
    {
        root = root->next;//get the next node
        count++;//increment counter
    }
    printf("Number of nodes in list :%d\n\n", count);//print number of nodes
    return count;//return number of nodes
}
/*
   search which node has data
   this function takes two parameters:
   root:pointer to the list
   data:data to be searched
*/
void searchNode(NODE* root, int data)
{
    int count = 0; //is used to point to position of the which has data
    if (root == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }//insert new node between nodes
    else//insert new node between nodes
    {
        while (root != NULL && root->data != data)//loop until finding node which has data
        {
            root = root->next;//get the next node
            count++;//increment counter
        }
        if (root->data == data)//check if this node has data
        {
            printf("\n\n%d is in position %d\n\n", data, count);//print node position
        }
        else//there is no node has this data
        {
            printf("\n\ndata is not in the list \n\n");//print to user no node has this data
        }

    }

}
/*
display the data of all nodes
this function takes only 1 parameter
root:pointer to list
*/
void displayList(NODE* root)
{
    int count = 0;//is used as counter
    if (root == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else//insert new node between nodes
    {
        printf("List is>>>\n");//print list is >>>
        while (root != NULL)//loop all nodes until root becomes bull
        {
            printf("node(%d) : %d\n", count, root->data);//print node position and its data
            root = root->next;//get the next node
            count++;//increment counter
        }
        printf("\n\n");//print new line two times
    }
}
NODE* insertAtPosition(NODE* root, int data, int pos)
{
    NODE* node;  //node is used to hold the address of the new created node
    NODE* head = root;//head is used to get the next node it is like a counter
    int count; //is used as a counter
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else //list is not empty
    {
        if (pos == 0)//new node is to be inserted before the first node
        {
            root = root->insertAtBegin(root, data);//inset new node before the first node
        }
        else //insert new node between nodes
        {
            for (count = 1; (count < pos) && (head != NULL); count++) //loop to get the rquired position
            {
                head = head->next;//get next node
            }
            if (count == pos)//check if count the result of looping is equal to position
            {
                node = CreateNewNode(data);//create new node
                node->next = head->next;//make the next pointer of the new created node points to the node which has the value
                head->next = node;//make the next pointer of the node before the node which has the required value points to new created node
            }
            else if (pos > count) //position is not in the list 
            {
                printf("\n\nposition is not in list \n\n");//print that the input position is not in list
            }
        }

    }
    return root; //return pointer to list
}
int getNode(NODE* root, int pos)
{
    NODE* head = root;//head is used to get the next node it is like a counter
    int data;
    int count; //is used as a counter
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else //list is not empty
    {
        for (count = 0; (count < pos) && (head != NULL); count++) //loop to get the rquired position
        {
            head = head->next;//get next node
        }
        if (count == pos)//check if count the result of looping is equal to position
        {
            data = head->data; //get data from node
        }
        else if (pos > count) //position is not in the list 
        {
            printf("\n\nnode is not in list \n\n");//print that the input position is not in list
        }
    }
    return data; //return data
}
/*
change node data
*/
void setNode(NODE* root, int data, int pos)
{
    NODE* head = root;//head is used to get the next node it is like a counter
    int count; //is used as a counter
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else //list is not empty
    {
        for (count = 0; (count < pos) && (head != NULL); count++) //loop to get the rquired position
        {
            head = head->next;//get next node
        }
        if (count == pos)//check if count the result of looping is equal to position
        {
            head->data = data; //change node data
        }
        else if (pos > count) //position is not in the list 
        {
            printf("\n\nnode is not in list \n\n");//print that the input position is not in list
        }
    }
}
/*
    delete node from list
    delete node takes two parameters
    root:pointer to the list
    data:helps us to find the required to be deleted
*/
NODE* deleteNode(NODE* root, int data)
{
    NODE* temp;
    NODE* head = root;
    if (head == NULL)//check if the list is empty
    {
        printf("\n\nlist is Empty\n\n");//if list is empty print that message
    }
    else
    {
        if (root->data == data)//if the data is in the first node
        {
            temp = root; //temp has point to first node
            root = root->next; //root will have the pointer of the second node
            free(temp);//delete the first node
            temp = NULL;//temp now points to null
        }
        else {//if the node to be deleted is between nodes
            while ((head->next != NULL) && (head->next->data != data))//find the precessor node
            {
                head = head->next;//get next node
            }
            if (head->next == NULL)//if head->next = null means node is not found
            {
                printf("\n\ndata is not in the list\n\n");//print to user node is not in the list
            }
            else if (head->next->data == data)//if node is found
            {
                temp = head->next;//store the pointer od this node into temp to be deleted
                head->next = temp->next;//make the next pointer of precessor node points to node after the node which will be deleted
                free(temp);//delete node
                temp = NULL;//temp now points to null
            }
        }
    }
    return root;//return pointer to list
}
