#include<stdio.h>

struct st
{
	int rollno ;
	char name[10];
	struct st *next;
};

void add_begin(struct st **);
void print(struct st *);

main()
{
	int i =1;
	struct st *headptr=0;

	while(i)
	{

		printf("want to enter new data ...? \n plz enter   1=continue  & 0=exit  \n --> ");
		scanf("%d",&i);
		if(i==1)
		{
			add_begin(&headptr);
		}
		else
		{
			i=0;

		}


	}

	print(headptr);
}

void add_begin(struct st **ptr)
{

	struct st *temp,*temp1;
	temp=malloc(sizeof(struct st));

	printf("enter the rollno ....\n");
	scanf("%d",&(temp->rollno));
	printf("enter the name ...\n");
	scanf("%s",temp->name);

	if(*ptr==0)
	{

		temp->next=0;
		*ptr=temp;

	}
	else 
	{
		temp1=*ptr;
		while(temp1->next != NULL)
			temp1=temp1->next;

		temp->next=temp1->next;
		temp1->next=temp;

	}
}

void print(struct st *ptr)
{

	while(ptr)
	{

		printf("%d %s \n",ptr->rollno,ptr->name);
		ptr=ptr->next;

	}

}






