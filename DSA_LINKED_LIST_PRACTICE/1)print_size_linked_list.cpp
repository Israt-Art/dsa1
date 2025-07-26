#include<stdio.h>
#include<stdlib.h>

struct Node{

int data;
struct Node* next;

};

struct Node* createNode(int data){

struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));

newNode->data=data;
newNode->next=NULL;

return newNode;

};

int getSize(struct Node* head){

int count=0;
struct Node* temp=head;

while(temp!=NULL){
    count++;
    temp=temp->next;
}

return count;

}

int main(){

struct Node* head=NULL;
struct Node* temp=NULL;

/*Step 1: No node yet
head = NULL
temp = NULL

Step 2: First node created
head = address of node1
temp = address of node1

Step 3: Adding more nodes
temp = moves to the last node every time you add
head = still pointing to the first node
*/

int n,value;

printf("enter number of nodes:");
scanf("%d",&n);

printf("Enter %d element:",n);
for(int i=0;i<n;i++){
    scanf("%d",&value);

    struct Node* newNode=createNode(value);

    if(head==NULL){
        head=newNode; //head now holds the address of the first node.
        //After this, even if you create more nodes and move temp or other pointers, head will always be pointing to the beginning of the linked list.
        temp=head; // temp now points to the first node
    }

    else{
        temp->next=newNode;//Connect the new node to the current linked list.
        temp=temp->next;
    }
}

printf("Size of linked list:%d\n",getSize(head));


return 0;

}
