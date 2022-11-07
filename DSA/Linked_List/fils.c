#include <stdio.h>
#include <stdlib.h>

# FIFO or LILO : FIRST IN FIRST OUT 


typedef struct node
{
	int data;   	
	struct node* next;  	
}node;

/* A pointer to the last node in the queue. */
node *rear = NULL;
/* A pointer to the first node in the queue. */
node *front = NULL;

node* newNode(int item)
{
	// allocate a new node in a heap
	node* node = malloc(sizeof(node));

	node->data = item;
	node->next = NULL;
	return node;
	
}

// Utility function to dequeue the front element
int dequeue()		// delete at the beginning
{
	if (front == NULL)
	{
		printf("\nQueue is empty!");
		return -1;
	}

	node* temp = front;
	printf("Removing %d\n", temp->data);

	// advance front to the next node
	front = front->next;

	// if the list becomes empty
	if (front == NULL) {
		rear = NULL;
	}
    int item = temp->data;
	return item;
}

// Utility function to add an item to the queue
void enqueue(int item)		// insertion at the end
{
	// allocate a new node in a heap
	node* node = newNode(item);
	printf("Inserting %d\n", item);

	// special case: queue was empty
	if (front == NULL)
	{
		// initialize both front and rear
		front = node;
		rear = node;
	}
	else {
		// update rear
		rear->next = node;
		rear = node;
	}
}

int peek()
{
	// check for an empty queue
	if (front != NULL) {
		return front->data;
	}
	else {
		return -1;
	}
}

int isEmpty() 
{
	return rear == NULL && front == NULL;
}

void display()
{
    node *temp = front;
    int k = 0;
    while(temp != NULL)
    {
        printf("Element %i: %i\n",++k,temp->data);
        temp = temp->next;
    }
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	printf("The front element is %d\n", peek());

	dequeue();

	if (isEmpty()) {
		printf("The queue is empty\n");
	}
	else {
		display();
	}
}