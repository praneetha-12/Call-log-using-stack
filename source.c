#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5 //macro to define the maximum size of the stack

int push(char stack[MAX][80], int *top, char data[80]) //push function to make a call
{
    if(*top==MAX-1)
    return(-1);
    else
    {
        *top=*top+1;
        strcpy(stack[*top],data);
        return(1);
    }
}

int pop(char stack[MAX][80], int *top, char data[80])   //pop function to see who you made a call to recently
{
    if(*top==-1)
    return(-1);
    else
    {
        strcpy(data,stack[*top]);
        *top=*top-1;
        return(1);
    }
}

int main()
{
    char stack[MAX][80],name[80];
    int top,ch,reply;
    top=-1;
    printf("CONTACT BOOK OPTIONS:\n");
    printf("1. MAKE A CALL\n");
    printf("2. CHECK YOUR RECENT CALL\n");
    printf("3. EXIT\n");
    while(1)
    {
        printf("CHOOSE YOUR OPTION\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: //push or make a CALL
            printf("Enter the name:\n");
            scanf("%s",name);
            reply=push(stack,&top,name);
            if(reply==-1)
            printf("This person can't be reached. Please try again later.\n");
            else
            printf("Calling %s\n",name);
            break;

            case 2: //pop or check your recent CALL
            reply=pop(stack,&top,name);
            if(reply==-1)
            printf("No recent calls made\n");
            else
            printf("You called %s last\n",name);
            break;

            case 3:
            exit(0);
            
            default:
            printf("We are sorry, we can neither place your call or allow you to check any kind of details\n");
        }
    }
return 0;
}
