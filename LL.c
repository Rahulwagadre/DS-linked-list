#include<stdio.h>
#include<stdlib.h>

// node initialization
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// head pointer (global scope)
Node *head = NULL;

// creating new node in heap area
Node* create_node(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// adding node at the beginning of the list
void add_at_beginning(int data)
{
    Node *temp = create_node(data);
    if(head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}

// adding node at the end of the list
void add_at_end(int data)
{
    Node *temp = create_node(data);
    if(head == NULL)
        head = temp;
    else
    {
       Node *ptr = head;
       while(ptr->next!=NULL)
       {
           ptr = ptr->next;
       }
       ptr->next = temp;
    }
}

// adding node at a certain position of the list
void add_at_index(int data,int index)
{
    Node* temp = create_node(data);
    Node *ptr = head;
    if(index == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        int i = 0;
        for(i=0;i<index-2;i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

// deletion of a node from a certain position
void delete_from_index(int index)
{
    int i = 0;
    Node *current = head;
    Node *prev = head;
    if(head != NULL)
    {
        if(index == 1)
        {
            head = head->next;
            free(current);
        }
        else{
            for(i=0;i<index-2;i++)
            {
                prev = prev->next;
            }
            current = prev->next;
            prev->next = current->next;
            free(current);
        }
        printf("\n\nnode deleted successfully");
    }
    else{
        printf("\n\nlist is already empty");
    }
}

// reversal of list
void reverse_list()
{
    Node *current = head,*next,*prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// print list
void show_list()
{
    Node *ptr = head;
    printf("\n\n");
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n\n");
}

// main function
int main()
{
    printf("****   Complete Linked List Implementation   ****\n");
    do{
        int choice,data,index;
        printf("_______________________________________________________________________________\n\n\n\n");
        printf("-> Insertion at beginning : press 1\n-> Insertion at end : press 2\n-> Insertion at certain position : press 3\n-> Deletion from certain position : press 4\n-> Reversal of list : press 5\n-> show list : press 6\n-> To end programm : press 7\n");
        printf("\n\nenter choice > ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    add_at_beginning(data);
                    break;
            case 2: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    add_at_end(data);
                    break;
            case 3: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    printf("Enter index > ");
                    scanf("%d",&index);
                    add_at_index(data,index);
                    break;
            case 4: printf("\n\nEnter index which you want to delete > ");
                    scanf("%d",&index);
                    delete_from_index(index);
                    break;
            case 5: reverse_list();
                    printf("\n\nlist reversed successfully ! ");
                    break;
            case 6: show_list();
                    break;
            case 7: printf("\n\nprogram terminated successfully !\n\n");
                    printf("_______________________________________________________________________________\n\n\n");
                    exit(0);
            default: printf("\n\noops...! wrong input");

        }
    }while(1);
    return 0;
}
