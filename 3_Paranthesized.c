#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char);
void pop();
int i,top=-1;
char e[20],stack[20];
int main(){
    printf("enter the expression:\n");
    scanf("%s",e);
    for(i=0;e[i]!='\0';i++){
        if(e[i]==')'){
            push(e[i]);
        }
        else if(e[i]==')'){
            pop();
            if(top==-2){
                break;
            }
        }
    }
if(top==-1){
    printf("expression is valid\n");
}
else{
    printf("expression is invalid\n");
    }
}
void push (char e){
    top=top+1;
    stack[top]=e;
}
void pop()
{
    top=top-1;
}