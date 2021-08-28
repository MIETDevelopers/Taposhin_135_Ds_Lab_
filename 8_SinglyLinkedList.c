#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
void search();

struct node 
{
    int data ;
    struct node *next;
};

typedef struct node nil;

nil *head=NULL;

int main ()
{
    int c;

    while(c != 5)
    {
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.To Insert\n2.To Delete\n3.To Display\n4.Search for an element\n5.Exit\n");  
        printf("\nEnter your choice: "); 
        scanf("%d",&c);

        switch(c)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            search();
            break;

            case 5:
            printf("You have succesfully exited the code\nHave a nice day");
            break;
             
            default:
            printf("Entered a Wrong choise");
            break;
        }
    }
}

void delete()
{
    nil *ptr, *temp;
    int pos,i; 

    if(head == NULL)
    {
        printf("List is empty");
    }

    else if (head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("Only node of the list deleted");
    }

    else
    {
        printf("Enter the postion to delete ");
        scanf("%d", &pos);

        temp = head;
        while(i<pos-1)
        {
            temp = temp -> next;
            i++  ;
        }
        
        ptr = temp -> next;
        temp -> next = ptr -> next;
        
        free(ptr);
        printf("Deleted Node from The list");
    }
}

void search ()
{
    nil *ptr;
    int val,i=0,flag;

    ptr = head;
    if(ptr == NULL)
    {
        printf("List is Empty");
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


void display()
{
    nil *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to print");
    }

    else 
    {
        printf("\nThe values are ");
        while(ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert()
{
    nil *ptr, *temp, *check;
    int val, pos ,i = 0,count=0;

    ptr=(nil *)malloc(sizeof(nil));

    if(ptr == NULL)
    {
        printf("No memory present in RAM");
    }
    
    else
    {
        if(head == NULL)
        {
            printf("Enter the value: ");
            scanf("%d", &val);
        
            ptr->data = val;
            ptr->next = NULL;
            head = ptr;
        }
        
        else
        {
            check = head;
            while (check -> next != NULL)
            {
                check = check -> next;
                count++;
            }
            printf("Last node is located at %d position", count);
            
            printf("\nEnter the position: ");
            scanf("%d", &pos);

            if(pos>count+1)
            {
                printf("Enter a valid position");
            }

            else if(pos==count+1)
            {
                printf("Enter the value: ");
                scanf("%d", &val);

                ptr -> data = val;
                ptr -> next = NULL;
                
                temp = head;
                
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = ptr;
                printf("Node Inserted at end");
            }

            else
            {
                printf("Enter the value: ");
                scanf("%d", &val);

                ptr -> data = val;
                ptr -> next = NULL;
            
                temp = head;
                
                while(i<pos-1)
                {
                    temp = temp -> next;
                    i++; 
                }
                ptr -> next = temp -> next;
                temp -> next = ptr;
                printf("Node inserted");
                
            }

        }    
    }
}