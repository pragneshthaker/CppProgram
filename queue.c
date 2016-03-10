#include<stdio.h>
#include<stdlib.h>
#define ArraySize 10

struct QueueArr{
	int queueArr[ArraySize];
	int F,R;
};

typedef struct QueueArr Queue;

void initializeQueue(Queue*);
void enQueue(Queue*,int);
int deQueue(Queue*);
void display(Queue);

int main(){
	int choice, flag=1, x;
	Queue q;
	initializeQueue(&q);
	
	while(flag){
		printf("Enter your chice....");
		printf("\n1:Enqueue \n2:Dequeue \n3:display \n4:exit");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("Enter the value of the element you want to enqueue.. ");
					scanf("%d",&x);
					enQueue(&q,x);
					break;
					
			case 2: x= deQueue(&q);
					printf("the %d element is dequeued form the queue",x);
					break;
					
			case 3: display(q);
					break;
			
			case 4:flag=0;
			
			default: printf("invalid Choice");
		}
	}
	return 1;

}

void initializeQueue(Queue* q){
	q->F = q->R = -1;
}

void enQueue(Queue* q,int x){
	if(q->R == (ArraySize-1) ){
		printf("Queue Overflow Error");
		return;
	}
	
	//check for the 1st insertion
	if( q->F== -1 ) {
		q->F = q->R = 0;
		q->queueArr[q->R] = x;
		return;
	}
	
	//Other Insertion
	q->R++;
	q->queueArr[q->R] = x;

}

int deQueue(Queue* q){
	int x;
	//check for empty Queue
	if(q->F == -1){
		
		printf("Queue Underflow Error");
		return -1;
	}
	
	x = q->queueArr[q->F];
	//check for last element deletion
	if(q->F == q->R){
			q->F = q->R = -1;
			return x;
	}
	
	q->F++;
	return x;
}

void display(Queue q){
	int temp = q.F;
	
	
	//check for empty queue
	if(q.F==-1){
		printf("Queue is Empty");
		return;
	}
	
	printf("Current Content of Queue is ::");
	while( temp <= q.R+1){
		printf("\n%d",q.queueArr[temp]);
		temp++;
	}
		 

}
