#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "single_linked.h"

NODE* reverseList(NODE* root)
{
    NODE* ptr, * prev, * next;
    prev = NULL;
    ptr = root;
    while (ptr != NULL)
    {

    }


}

int main(void)
{
    NODE* list = NULL; //initially list is empty 
    int choice, data, value, k;
    list = createList(list);
    while (1)
    {
        printf("1-display data\n");
        printf("2-count number of nodes\n");
        printf("3-search element\n");
        printf("4-insert node at the begining of the list\n");
        printf("5-insert node at the end at end of the list\n");
        printf("6-insert node after node\n");
        printf("7-insert node before node\n");
        printf("8-insert a node at a given position\n");
        printf("9-get node data\n");
        printf("10-set node data\n");
        printf("11-delete a node \n");
        printf("12-reverse list \n");
        printf("13-quit\n");
        printf("enter your choice :");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 13)
        {
            break;
        }
        else
        {
            if (list != NULL)
            {
                switch (choice)
                {
                case 1:
                    list->displayList(list);
                    break;
                case 2:
                    list->countNodes(list);
                    break;
                case 3:
                    printf("enter the element to be seacrched: ");
                    scanf("%d", &data);
                    list->searchNode(list, data);
                    break;
                case 4:
                    printf("enter the element to be inserted: ");
                    scanf("%d", &data);
                    list = list->insertAtBegin(list, data);
                    break;
                case 5:
                    printf("enter the element to be inserted: ");
                    scanf("%d", &data);
                    list->insertAtEnd(list, data);
                    break;
                case 6:
                    printf("enter the element to be inserted: ");
                    scanf("%d", &data);
                    printf("enter the element after which to insert: ");
                    scanf("%d", &value);
                    insertAfter(list, data, value);
                    break;
                case 7:
                    printf("enter the element to be inserted: ");
                    scanf("%d", &data);
                    printf("enter the element before which to insert: ");
                    scanf("%d", &value);
                    list = list->insertBefore(list, data, value);
                    break;
                case 8:
                    printf("enter the element to be inserted: ");
                    scanf("%d", &data);
                    printf("enter the position at which to insert: ");
                    scanf("%d", &k);
                    list = list->insertAtPosition(list, data, k);
                    break;
                case 9:
                    printf("enter the position to get data: ");
                    scanf("%d", &k);
                    printf("\n\ndata is %d\n\n", list->getNode(list, k));
                    break;
                case 10:
                    printf("enter data: ");
                    scanf("%d", &data);
                    printf("enter the position at which to set: ");
                    scanf("%d", &k);
                    list->setNode(list, data, k);
                    break;
                case 11:
                    printf("enter the element to be deleted: ");
                    scanf("%d", &data);
                    //  deleteNode(&list, data);
                    list = list->deleteNode(list, data);
                    break;
                case 12:
                    list = reverseList(list);
                    break;
                }

            }
            else
            {
                printf("\n\nlist is empty\n\n");
            }

        }
    }

}