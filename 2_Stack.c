#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void view();
int stack[50], top= -1, max;
int main(){
	int ch;
	printf("enter size of stack maximum 50:");
	scanf("%d", &max);

	do{
		printf("choose the option:\n 1:for push \n 2:for pop\n 3:for view\n 4.to exit \n");
	scanf ("%d",&ch);
	switch (ch){
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: view();
		break;
		case 4: printf("Exit");
		break;
		default:
			printf("incorrect option!");
			break;
			}
	}	while(ch!=4);
			return(0);
		}
void push(){
	int element;
	if(top>=max-1)
	printf("stack overflow!\n");
	else{
		printf("enter the value of element to be push in stack \n");
		scanf("%d", &element);
		top+=1;
		stack[top]= element;
	}
}
void pop(){
	int element;
	if(top==-1)
	printf("stack underflow!\n");
	else{
	
		printf("\n %d is deleted element  \n",stack[top]);
		top-=1;
	}
}
void view(){
	int i;
	if(top>=0)
	{printf("\nstack elements are:\n");
	for(i=top; i>=0; i--)
		printf(" \n %d \n", stack[i]);
	
	}
	else{
		printf("\n empty stack \n");
	}
	}