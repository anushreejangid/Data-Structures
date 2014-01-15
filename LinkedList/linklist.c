#include<stdio.h>
#include<stdlib.h>
struct node
 {
   int data;
   struct node *next;
 };

struct node *first = NULL;

void traversell()
{
  struct node *p = first;
  int count = 0;
  printf("\n\n");
  if(first == NULL)
    printf("Linked list: ");
  while(p->next!= NULL)
    {
    printf("%d  ",p->data);
    p = p->next;
    count++;
    }

  if(first==NULL)
    {

    printf("\n\nTHE LINKED LIST IS EMPTY :.. \n");
    }
    else
    {
   printf("%d  ",p->data);
   printf("\nTotal no. of elements are : %d ",count+1);
  }
}
void insertpos()
{
  struct node *newp,*p = first;
  int item,pos = 0,count = 0;
  if(first == NULL)
   { printf("\n\nLinked List is empty .The element can only be inserted at the beginning.\n");
    return;
    }
  printf("\n\nEnter the position after which you want to insert the element: ");
  scanf("%d",&pos);
  printf("\n\nEnter the element you want to insert : ");
  scanf("%d",&item);
/*    do
	{
		++count;
		p = p->next;
		printf("\nPos : %d Count : %d \n ",pos,count);
	}while(p->next!=NULL && count<pos);*/
	while(p->next!= NULL)
	{
		++count;
		if(count>pos-1)
		  break;
		p = p->next;
	  //	printf("\nPos : %d Count : %d \n ",pos,count);
	}
    printf("\nCount value is : %d",count);
    if(pos>count)
	 printf("\nInvalid position specified .. \n");
    else
	 {
		newp = (struct node *)malloc(sizeof(struct node));
		newp->data = item;
		newp->next = p->next;
		p->next = newp;
		printf("Element inserted successfully:");
	  }
    traversell();
}
void insertbeg()
{
  struct node *newp;
  int item;
  printf("\n\nEnter the element you want to insert : ");
  scanf("%d",&item);
  newp = (struct node *)malloc(sizeof(struct node));
  newp->data = item;
  if(first!= NULL)
   {
	newp->next = first;
	first = newp;
   }
   else
   {

    newp->next = NULL;
    first = newp;
   }
   traversell();
}
void insertll()
{
  struct node *p = first,*newp;
  int item;
  printf("\n\nEnter the element you want to insert : ");
  scanf("%d",&item);
  newp = (struct node *)malloc(sizeof(struct node));
  if(first ==NULL)
    {
	 newp->data = item;
	 newp->next = NULL;
	 first = newp;
    }
   else
    {
	   while((p->next)!=NULL)
	    {
		p = p->next;
	    }
	   newp->data = item;
	   newp->next = NULL;
	   p->next = newp;
	   printf("\n\n Element inserted succesfully ..\n");
    }
    traversell();
}

void deleteelem()
{
  struct node *p = first;
  int pos = 0,count = 0;
  printf("\n\nEnter the position of the element which you want to delete : ");
  scanf("%d",&pos);
  if(first == NULL)
    printf("Linked List is empty .");
  else
  {
    if(pos == 1)
	 {
	   printf("\n\nFirst element deleted..\n");
	   first = p->next;
	 }
	else
	{
	while((p->next)!= NULL)
	{
		++count;
		if(count>= pos-1)
		  break;
		p = p->next;
	  //	printf("\nPos : %d Count : %d \n ",pos,count);
	}
    printf("\nCount value is : %d",count);
    if(pos>count+1)
	 printf("\nInvalid position specified .. \n");
    else
	 {
		p->next = (p->next)->next;
		printf("Element deleted successfully:");
	  }
	}
  }
  traversell();
}

void deletell()
{
  struct node *p = first;
  printf("\n\n");
  if(first == NULL)
    {	 printf("\n\nLINKED LIST EMPTY.NOTHING TO DELETE:.. \n");
	 return;
    }
  while((p->next)->next!=NULL)
    {
		p = p->next;
    }
  if(first->next == NULL)
    {
	first = NULL;
	printf("\n\nLast element deleted.Linked list empty. :\n");
    }
    else
	printf("\n\nElement deleted:\n\n");

   p->next = NULL;
}
void main()
 {
   int choice;
   while(1)
   {
   printf("\n\n Welcome to Singly Linked List program. Press \n\n");
   printf("1. Add a element.\n");
   printf("2. Delete element\n");
   printf("3. Display and count elements\n");
   printf("4. Add element at the beginning.\n");
   printf("5. Add element after specified position.\n");
   printf("6. Delete the specified element.\n");
   printf("7. Exit\n\n");
   printf("ENTER YOUR CHOICE : \n\n");
   scanf("%d",&choice);
   switch(choice)
    {
	 case 1: insertll();break;
	 case 2: deletell();break;
	 case 3: traversell();break;
	 case 4: insertbeg();break;
	 case 5: insertpos();break;
	 case 6: deleteelem();break;
	 case 7: printf("\n\n GOOD BYE !! \n\n");exit(0);break;
	 default:{
			 printf("Invalid choice !!! \n");
		    }
    }
   }

}
