#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void displayLinkedList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    //  memory allocation in the heap
    node *head = (node *)malloc(sizeof(struct node));
    node *second = (node *)malloc(sizeof(struct node));
    node *third = (node *)malloc(sizeof(struct node));

    //  linkage
    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 22;
    third->next = NULL;

    displayLinkedList(head);
}