#include <stdio.h>
#include <stdlib.h>

void enque();
void deque();
void view();

struct node 
{
    int dt;
    struct node *nt;
};

typedef struct node nil;

nil *hd=NULL;

int main ()
{
    int c;

    while(c != 4)
    {
        printf("\n\n-----------------------Main Menu--------------------");
        printf("\n1.To Insert\n2.To Delete\n3.To Display\n4.To Exit");
        printf("\nEnter your choise: ");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
            enque();
            break;

            case 2:
            deque();
            break;

            case 3:
            view();
            break;

            case 4:
            printf("You have succesfilly Exited the code\nHave a nice day");
            break;

            default:
            printf("You have entered a wrong choise\nPlease try again");
            break;
        }
    }
}

void enque()
{
    nil *ptr, *temp;
    int val;

    ptr=(nil*)malloc(sizeof(nil));
    
    if(ptr == NULL)
    {
        printf("The Queue is full");
    }

    else
    {
        printf("Enter a value: ");
        scanf("%d", &val);
        ptr->dt=val;
        ptr->nt=NULL;

        if(hd == NULL)
        {
            hd = ptr;
        }

        else
        {
            temp = hd;
            while(temp -> nt != NULL)
            {
                temp = temp -> nt;
            }
            temp -> nt = ptr;
        }
    }
}


void deque()
{
    nil *temp;
    if(hd == NULL)
    {
        printf("The Queue is Empty");
    }
    
    else
    {
        temp = hd;
        hd = temp -> nt;
        free(temp);
        printf("\nElement Deleted");

    }
}

void view()
{
    nil *ptr;
    ptr = hd;
    
    if (ptr == NULL)
    {
        printf("\nNothing to print");
    }

    else 
    {
        printf("\nThe values are ");
        while(ptr!=NULL)
        {
            printf("\n%d ", ptr->dt);
            ptr = ptr->nt;
        }
    }
}