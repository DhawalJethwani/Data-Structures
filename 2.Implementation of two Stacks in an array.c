#include <stdio.h>
#include <stdlib.h>
int top1=-1,top2=-1;
int push(float x,float stk_no,float a[],int n)
{
	if(top1<top2)
	{
		if(stk_no==1)
		{
			top1++;
			a[top1]=x;
		}
		else if(stk_no==2)
		{
			top2--;
			a[top2]=x;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}
int pop(float stk_no,int n)
{
	if(top1>=0 && top2<n)
	{
		if(stk_no==1)
		{
			top1--;
			return top1+1;
		}
		else if(stk_no==2)
		{
			top2++;
			return top2-1;
		}
	}
	else
	{
		return -1;
	}
}
int top(float stk_no,int n)
{
	if(stk_no==1)
	{
		if(top1>=0)
		{
			return top1;
		}
		else
		{
			return -1;
		}
	}
	else if(stk_no==2)
	{
		if(top2<n)
		{
			return top2;
		}
		else
		{
			return -1;
		}
	}
}
void prnt_arr(float a[],int n)
{
	int r;
	for(r=0;r<=top1;r++)
	{
		printf("%.2f ",a[r]);
	}
	for(r=top1+1;r<top2;r++)
	{
		printf("* ");
	}
	for(r=top2;r<n;r++)
	{
		printf("%.2f ",a[r]);
	}
	printf("\n\n");
}
int main()
{
	float p;
	int n;
	printf("Enter the combined sizes of both the stacks : ");
	scanf("%f",&p);
	n=(int)p;
	while(p!=n || n<=0)
	{
		printf("Invalid Input! Size should be a positive integer.\n\nEnter the combined sizes of both the stacks : ");
		scanf("%f",&p);
		n=(int)p;
	}
	top2=n;
	float* a=(float*)malloc(n*sizeof(float));
	float stk_no,op,x;
	int i,j,k;
	while(1)
	{
		printf("\nPress 1 to operate on 1st stack, 2 for 2nd stack and 0 to exit : ");
		scanf("%f",&stk_no);
		if(stk_no==0)
		{
			return 0;
		}
		else
		{
			while(stk_no!=1 && stk_no!=2)
			{
				printf("Invalid Input! Try again.\n\n");
				printf("Press 1 to operate on 1st stack and 2 for 2nd stack and 0 to exit : ");
				scanf("%f",&stk_no);
			}
		}
		printf("\nPress 1 for push operation, 2 for pop operation, 3 for returning the top element of the chosen stack and 4 for printing the present array : ");
		scanf("%f",&op);
		if(op==1)
		{
			printf("\nEnter a value correct upto 2 decimal places to push in the stack : ");
			scanf("%f",&x);
			i=push(x,stk_no,a,n);
			if(i==-1)
			{
				printf("Stack Overflow! Push function not allowed.\n\n");
			}
			else
			{
				printf("\nAfter pushing %.2f in stack %.0f, the new array is : \n",x,stk_no);
				prnt_arr(a,n);
			}
		}
		else if(op==2)
		{
			j=pop(stk_no,n);
			if(j==-1)
			{
				printf("Stack Underflow! Pop operation not allowed.\n\n");
			}
			else
			{
				printf("\nThe element retrieved is %.2f\n\n",a[j]);
				printf("After pop operation on stack %.0f, the new array is : \n",stk_no);
				prnt_arr(a,n);
			}
		}
		else if(op==3)
		{
			k=top(stk_no,n);
			if(k!=-1)
			{
				printf("\nTop element of stack %.0f is %.2f.\n\n",stk_no,a[k]);
			}
			else
			{
				printf("Stack is empty.\n\n");
			}
		}
		else if(op==4)
		{
			prnt_arr(a,n);
		}
		else
		{
			printf("Invalid Input! Try again.\n\n");
			printf("Press 1 for push operation, 2 for pop operation, 3 for returning the top element of the chosen stack and 4 for printing the present array : ");
			scanf("%f",&op);
		}
	}
	return 0;
}
