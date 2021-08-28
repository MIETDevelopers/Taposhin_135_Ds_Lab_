#include <stdio.h>   
#include <stdlib.h>

void insert();      
void delete();
void view();
void search();

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

int main ()
{
    int c;
    
    while(c != 5)
    {
        printf("\n\n-----------------------Main Menu--------------------");
        printf("\n1.To Insert\n2.To Delete\n3.To Display\n4.To Search\n5.To Exit");
        printf("\nEnter your choise: ");
        scanf("%d",&c);
        printf("\n------------------------------------------------------------\n\n");
        switch (c)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            view();
            break;

            case 4:
            search();
            break;

            case 5:
            printf("You have Exited the code\nHave a nice day");
            break;
            
            default:
            printf("Choise is invalid\nPlease try again");
            break;
        }
    }
}

void insert ()
{
    node *ptr, *temp;
    int val;

    ptr=(node*)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("\nInsufficient Space to store any value");
    }

    else 
    {
        printf("Enter a value: ");
        scanf("%d", &val);
        ptr -> data = val;
        ptr -> next = NULL;
        ptr -> prev = NULL;
        
            
        if(head == NULL)
        {
            
            head = ptr;
            ptr -> prev = head;
            head -> prev = NULL;
            printf("\nNode Inserted");
        }

        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> prev = temp;
            printf("\nNode Inserted");
        }
    }
}

void delete ()
{
    node *temp, *ptr;
    if(head == NULL)
    {
        printf("\nThere are no element present to perform this function");
    }

    else
    {
        if (head -> next == NULL)
        {
            head = NULL;
            free(head);
            printf("\nNode Deleted");
        }
        
        else
        {
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            ptr = temp -> prev;
            ptr -> next = NULL;
            free(temp);
            printf("\nNode Deleted");
        }

    }
}

void view()
{
    node *ptr, *temp;
    ptr = head;
    int choise;
    
    if (ptr == NULL)
    {
        printf("\nThere are no element present to view");
    }

    else 
    {
        printf("Press 1 to show from first to last\nPress 2 to show from last to first");
        printf("\n\nEnter a choise : ");
        scanf("%d",&choise);
        printf("\nThe values are : ");

        if(choise == 1)
        {
            while(ptr!=NULL)
            {
                printf("\n%d ", ptr->data);
                ptr = ptr->next;
            }
        }

        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            temp = ptr;

            while(temp!=NULL)
            {
                printf("\n%d ", temp->data );
                
                temp = temp->prev;
            }

        }
    }
}

void search()
{
    node *ptr;
    int val,i=0,flag;

    ptr = head;
    if(ptr == NULL)
    {
        printf("The list is empty");
    }

    else 
    {
        printf("Enter the element you want to search: ");
        scanf("%d", &val);

        while(ptr!=NULL)
        {
            if(ptr->data == val)
            {
                printf("Element found at location %d", i+1);
                flag=0;
                break;
            }
            else
            {
               flag=1;
               
            }
            i++;
            ptr=ptr->next;
        }

        if(flag==1)
        {
            printf("\nElement not found");
            
        }
    }
}