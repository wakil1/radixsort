#include<stdio.h>
#include<stdlib.h>



typedef struct _node
{
int data; /*sets the data */

struct _node *next;

}listNode;


void insert(listNode **head, listNode *newNode){ /*inserts newNode in head linkedlist */
    if(*head == NULL){
        *head=newNode;
    }
    else{
      listNode *temp=*head;
      
      while(temp -> next != NULL){
          temp = temp-> next; 
      }
    newNode -> next = temp -> next;
     temp -> next= newNode;
    }


}
void printList(listNode *head){ /*prints the array list */
    
    listNode *temp=head;
    if(head == NULL){
    return;
    }
    
    while(temp != NULL){
     printf("%i ",temp -> data);
     temp=temp->next;
    }
printf("\n");
}

void printAll(listNode* heads[10]){ /*calls printList to print the whole BucketArray */
int i;

for(i=0;i<10;i++){
    if(heads[i]==NULL){
        printf("bucket[%i]: \n",i);
    }   
    else{
printf("bucket[%i]: ",i);
printList(heads[i]);

}

}
}
void deleteList(listNode *head){ /*used to free everything */
    listNode *temp=head;
    if(head == NULL){ /*if head is NULL do nothing */
    return;
}else {
     while(head != NULL){
      head=head->next;
        free(temp);
       temp=head;
                         
     }
     
}
}

listNode *newList(){ /*sets head of linkedList  to null and returns it */
listNode *head=NULL;


return head;
}


int maxDigits(listNode* head){
int count=0,max=-5;
listNode *temp=head;
while(temp != NULL){ /*finds the max number */
if ((temp -> data) > max){
max = temp -> data;
}
temp=temp -> next;
}


while(max != 0){ /*finds how many digits are in the max digit that was found */
max /= 10;
count++;
}

return count;
}

void radixSort(int max, listNode **linked){
int divide,i,k,valueTemp;

listNode *buckets[10],*temp=NULL, *temporary=NULL;
for(k=0;k<10;k++){
    buckets[k]=newList();
}
for(i=0;i<max;i++){
 divide=1; 

temp=*linked; 

for(k=0;k != i;k++){ /*used to figure out how much to divide */
divide *= 10;
} 
printf("\n");

while(temp != NULL){
valueTemp = ((temp -> data)/divide)%10; /*element to insert in buckets array */

temporary=temp; 
temp = temp -> next; 
temporary->next=NULL;


insert(&buckets[valueTemp],temporary); /* inserts depending on modules of Valuetemp */

}

temp=NULL;

printAll(buckets);

*linked=newList();
for(k=0;k<10;k++){
temp=buckets[k];

while(temp != NULL){ /* inserts value that were in buckets to the new linked List */
temporary=temp;
temp=temp->next;
temporary->next=NULL;   
insert(linked,temporary);

}
}

for(k=0;k<10;k++){
    buckets[k]=newList();
}

}
deleteList(*linked); /*frees all numbers once done */


}

int main(int argc, char *argv[]){
 listNode *sort=NULL,*newNode=NULL;
char *buffer;
int seed=-5,max,numVals=0,lowVal=0,highVal=0,i=0,j=0,ran=-5;
if(argc == 5){ /*reads values from command line read by buf */
buffer=argv[1];
seed=atoi(buffer);
buffer=argv[2];
numVals=atoi(buffer);
buffer=argv[3];
lowVal=atoi(buffer);
buffer=argv[4];
highVal=atoi(buffer);
}


srand(seed); /*sets the seed */
sort=NULL;


for(i=0;i<numVals;i++){
 newNode=malloc(sizeof(listNode));
    
 j=0;     
while(j == 0){
   ran=rand() % seed +1;
	if((highVal > ran) && (ran > lowVal)){ /*must be between these numbers set in command line */ 
        newNode -> data = ran;
         j=-1;
           }
}    
newNode -> next=NULL;
insert(&sort,newNode); /*linked list to be sorted */   

}
max=maxDigits(sort); /*finds the max digits */


radixSort(max,&sort); /*sorts the linked list */



return 0;
}

