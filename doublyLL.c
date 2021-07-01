#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};

struct node *head,*last;

void createList(int n);
void insert_at_anyposition(int data,int position);
void search();
void delete_at_end();
void display();

void main ()
{
	int choice=0,n,data;
	while(choice!=6)
	{
		printf("-----DOUBLY LINKED LIST-----");
		printf("\n1.Create the list \n2.Insert at particular position \n3.Search an element \n4.Delete an element at end \n5.Display \n6.Exit\n");
		printf("Enter your choice : ");
		scanf("\n%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter number of nodes to be inserted: ");
				scanf("%d",&n);
				createList(n);
				break;
			case 2:printf("Enter the position where you want to insert new node: ");
                	       scanf("%d", &n);
                		printf("Enter data of %d node : ", n);
                		scanf("%d", &data);
				insert_at_anyposition(data,n);
				break;
			case 3:search();
				break;
			case 4:delete_at_end();
				break;
			case 5:display();
				break;
			case 6:exit(0);
				break;
			default: printf("Enter a valid choice");
		}
	}
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of node %d: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode;          
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insert_at_anyposition(int data,int position)
{
	int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf(" List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

       if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;          
            if(temp->next != NULL)
            {
               temp->next->prev = newNode;
            }
            
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf(" Invalid position\n");
        }
    }
}	

void search()	
{
	struct node *ptr;
 	int item,i=0,flag;
 	ptr = head;
 	if(ptr == NULL)
 	{
 		printf("\nEmpty list\n");
 	}
 	else
 	{
 		printf("\nEnter the value of node you want to search:\n");
 		scanf("%d",&item);
 		while (ptr!=NULL)
		{
 			if(ptr->data == item)
 			{
 				printf("\nNode found at %d position\n ",i+1);
				flag=0;
 				break;
			}
 			else
			{
 				flag=1;
 			}
 		i++;
 		ptr = ptr -> next;
 		}
 		if(flag==1)
 		{
			printf("\nNode not found\n");
		}
	}
} 		

void delete_at_end()
{
	struct node *ptr;
 	if(head == NULL)
 	{
 		printf("\nCannot delete");
 	}
 	else if(head->next == NULL)
 	{
 		head = NULL;
 		free(head);
 		printf("\nNode deleted\n");
 	}
 	else
 	{	 
		ptr = head;
 		if(ptr->next != NULL)
 		{
 		ptr = ptr -> next;
 		}
 		ptr -> prev -> next = NULL;
 		free(ptr);
 		printf("\nNode deleted\n");
	} 
 }
 
void display()
{
	struct node *ptr;
	if(head == NULL)
	{
	printf("List is empty");
	}
	else
	{
	printf("\n The nodes in DoublyLL : \n");
	ptr = head;
	while(ptr != NULL)
 	{
 		printf("%d\n",ptr->data);
 		ptr=ptr->next;
	}
	}
}
