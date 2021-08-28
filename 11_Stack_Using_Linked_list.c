#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void view();

struct node
{
    int data;
    struct node *next;
};

typedef struct node nil;

nil *head = NULL;

int main ()
{
    int c;
    
    while(c != 4)
    {
        printf("\n\n-----------------------Main Menu--------------------");
        printf("\n1.To Insert\n2.To Delete\n3.To Display\n4.To Exit");
        printf("\nEnter your choise: ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            view();
            break;

            case 4:
            printf("You have Exited the code\nHave a nice day");
            break;
            
            default:
            printf("Choise is invalid\nPlease try again");
            break;
        }
    }
}

void push()
{
    nil *ptr, *temp;
    int val;

    ptr=(nil*)malloc(sizeof(nil));

    if(ptr == NULL)
    {
        printf("Stack is full");
    }

    else
    {
        printf("Enter the value: ");
            scanf("%d", &val);
            ptr->data=val;
            ptr->next=NULL;
        
        if(head == NULL)
        {
            head = ptr;
        }

        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;

        }
    }
}

void pop()  
{  
    nil *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nStack is empty");  
    }  
    
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nValue Deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr -> next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nValue deleted\n");  
    }     
} 

void view()
{
    nil *ptr;
    ptr = head;
    
    if (ptr == NULL)
    {
        printf("\nStack is empty");
    }

    else 
    {
        printf("\nThe values are ");
        while(ptr!=NULL)
        {
            printf("\n%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}