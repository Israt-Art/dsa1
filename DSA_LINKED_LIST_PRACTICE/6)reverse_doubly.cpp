#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list{

int data;
struct list *next;
struct list *back;


};

typedef struct list node;

void display(node *head);
void reverse(node *start);

int main(){

node *start=NULL;
node *prev=NULL;
node *temp=NULL;

char ans;

printf("create doubly linked list:");
printf("type 'Y' to enter a node or any other key to stop:\n");

while(1){

    printf("do you want to create a node:");
    scanf("%c",&ans);
    ans=toupper(ans);

    if(ans!='Y'){
        break;
    }
 temp=(node*)malloc(sizeof(node));
 printf("enter data:");

 scanf("%d",&temp->data);
 temp->next=NULL;
 temp->back=NULL;

 if(start==NULL){
    start=temp;
 }
 else{
    prev->next=temp;
    temp->back=prev;
 }

 prev=temp;

}

display(start);
reverse(start);

return 0;







}
