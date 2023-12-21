#include<stdio.h>
#include<stdlib.h>
typedef struct node
    {
    int coeff;
    int power;
    struct Node *next;
    }list;

float x; int y;


list *head1=NULL,*head2=NULL,*head3=NULL,*new,*temp;
void insert(int polynomial)
{
    switch(polynomial){
		case 1 : //list *temp;
				 temp=head1;
				 new=(list*)malloc(sizeof(list));
                 printf("Enter The Coefficient and Power of The Polynomial Term: \n");
                 scanf("%d%d",&new->coeff,&new->power);

                    if(head1==NULL)
                    {
                        head1=new;
                        new->next=NULL;
                    }

                    else if(head1->next==NULL)
                    {
                        head1->next=new;
                        new->next=NULL;
                    }

                    else
                    {
                        while(temp->next!=NULL)
                            temp=temp->next;
                        temp->next=new;
                        new->next=NULL;
                    }
                    break;

		case 2 : //list *temp;
				 temp=head2;
				 new=(list*)malloc(sizeof(list));
                 printf("Enter The Coefficient and Power of The Polynomial Term: \n");
                 scanf("%d%d",&new->coeff,&new->power);

                    if(head2==NULL)
                    {
                        head2=new;
                        new->next=NULL;
                    }

                    else if(head2->next==NULL)
                    {
                        head2->next=new;
                        new->next=NULL;
                    }

                    else
                    {
                        while(temp->next!=NULL)
                            temp=temp->next;
                        temp->next=new;
                        new->next=NULL;
                    }
                    break;

		case 3 : //list *temp;
				 temp=head3;
				 new=(list*)malloc(sizeof(list));
                 new->coeff=x;
                 new->power=y;
                    if(head3==NULL)
                    {
                        head3=new;
                        new->next=NULL;
                    }

                    else if(head3->next==NULL)
                    {
                        head3->next=new;
                        new->next=NULL;
                    }

                    else
                    {
                        while(temp->next!=NULL)
                            temp=temp->next;
                        temp->next=new;
                        new->next=NULL;
                    }
                    break;
        default : printf("FATAL ERROR SELF DESTRUCT ACTIVATED");

        }
}

void multiply(void)
{
	list *temp1=head1,*temp2=head2;
	while(temp1!=NULL)
	{

		while(temp2!=NULL)
		{

			x=(temp1->coeff)*(temp2->coeff);
			y=(temp1->power)+(temp2->power);
			insert(3);
			temp2=temp2->next;
		}
		temp1=temp1->next;
		temp2=head2;

	}

}

void add(void)
{
    temp=head3;
    list *temp2,*ptr;
    temp2=head3->next;
    ptr=head3;

    while(temp!=NULL)
    {
        while(temp2!=NULL)
        {
            if(temp->power=temp2->power)
            {
                temp->coeff+=temp2->coeff;
                ptr->next=temp->next;
                free(temp2);
                temp2=ptr->next;
            }
            else
            {
                ptr=temp2;
                temp2=temp2->next;
            }
        }
    }

}

void display(void)
{
    list *temp1=head1,*temp2=head2,*temp3=head3;
    while(temp3!=NULL)
    {
        printf("%dX^%d   ",temp3->coeff,temp3->power);
        temp3=temp3->next;

    }

}

int main()
{
	int choice=1,option=1;
	printf("enter the elements of 1st polynomial\n");
		while(option!=0)
		{

			printf("Enter\n1 to Insert term\n0 to Move On.\n");
			scanf("%d",&option);
			if(option==1)
			{
				insert(1);
			}
			else if(option==0)
			{
				continue;
			}
			else
			{

				printf("invalid input\n");
			}
		}

		printf("enter the elements of 2nd polynomial\n");
		while(choice!=0)
		{

			printf("Enter\n1 to Insert term\n0 to Move On.\n");
			scanf("%d",&choice);
			if(choice==1)
			{
				insert(2);
			}
			else if(choice==0)
			{
				continue;
			}
			else
			{

				printf("invalid input\n");
			}
		}

		multiply();
		add();
		display();


}


