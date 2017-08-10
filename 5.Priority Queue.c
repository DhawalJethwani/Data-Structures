#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
int size=0;
struct arr
{
    int *a;
    float *b;
};
typedef struct arr bin;
void swap(int i1,int i2,int *a,float *b)
{
    int t1;
    float t2;
    t1=a[i1];
    a[i1]=a[i2];
    a[i2]=t1;
    t2=b[i1];
    b[i1]=b[i2];
    b[i2]=t2;
}
void bubble_up(int i,int *a,float *b)
{
    if(i<=0)
    {
        printf("Do not access this index!!\n\n");
    }
    else if(i!=1)
    {
        while(a[i/2]>a[i] && i/2>0)
        {
            swap(i/2,i,a,b);
            i=i/2;
        }
    }
    return;
}
void bubble_down(int i,int *a,float *b)
{
    while(2*i+1<=size)
    {
        if(a[i]>a[2*i] && a[i]>a[2*i+1])
        {
            if(a[2*i+1]>=a[2*i])
            {
                swap(i,2*i,a,b);
                i=2*i;
            }
            else
            {
                swap(i,2*i+1,a,b);
                i=2*i+1;
            }
        }
        else if(a[i]>a[2*i] && a[i]<a[2*i+1])
        {
            swap(i,2*i,a,b);
            i=2*i;
        }
        else if(a[i]<a[2*i] && a[i]>a[2*i+1])
        {
            swap(i,2*i+1,a,b);
            i=2*i+1;
        }
        else
        {
            return;
        }
    }
    while(2*i<=size && 2*i+1>size)
    {
        if(a[i]>a[2*i])
        {
            swap(i,2*i,a,b);
            i=2*i;
        }
        else
        {
            return;
        }
    }
    if(2*i>size)
    {
        return;
    }
}
bin *ins(bin *l)
{
    if(size==0)
    {
        l->a=(int *)malloc(2*sizeof(int));
        l->b=(float *)malloc(2*sizeof(float));
    }
    else
    {
        l->a=(int *)realloc(l->a,(size+2)*sizeof(int));
        l->b=(float *)realloc(l->b,(size+2)*sizeof(float));
    }
    if(l->a!=NULL)
    {
        size++;
        float p;
        int k;
        printf("Enter the priority for this insertion (non negative integer value) : ");
        scanf("%f",&p);
        k=(int)p;
        while(p!=k || k<0)
        {
            printf("Invalid Input! Key should be a non negative integer.\n\nEnter the priority for this insertion (non negative integer value) : ");
            scanf("%f",&p);
            k=(int)p;
        }
        int key=k;
        float val;
        printf("Enter the value (only floating point numbers, no character inputs): ");
        scanf("%f",&val);
        l->a[size]=key;
        l->b[size]=val;
        bubble_up(size,l->a,l->b);
        Sleep(500);
        printf("\nSuccessfully inserted!!\n\n");
    }
    else
    {
        Sleep(500);
        printf("\nOverflow!!\n\n");
    }
    return l;
}
bin *del(bin *l)
{
    if(size==0)
    {
        Sleep(500);
        printf("\nUnderflow!!\n");
        printf("This function can not be implemented as the priority queue is empty!!\n\n");
        return l;
    }
    else
    {
        Sleep(500);
        printf("\nNode : (%d,%.2f) Successfully deleted!!\n\n",l->a[1],l->b[1]);
        swap(1,size,l->a,l->b);
        size--;
        l->a=(int *)realloc(l->a,(size+1)*sizeof(int));
        l->b=(float *)realloc(l->b,(size+1)*sizeof(float));
        bubble_down(1,l->a,l->b);
        return l;
    }
}
void min_key(bin *l)
{
    if(size==0)
    {
        Sleep(500);
        printf("This function can not be implemented as the priority queue is empty!!\n\n");
    }
    else
    {
        Sleep(500);
        printf("Node with minimum key : (%d,%.2f)\n\n",l->a[1],l->b[1]);
    }
}
void print_as_queue(bin *l)
{
    if(size==0)
    {
        Sleep(500);
        printf("This function can not be implemented as the priority queue is empty!!\n\n");
    }
    else
    {
        int i,j;
        for(i=1;i<=size;i++)
        {
            Sleep(500);
            printf("(%d,%.2f) ",l->a[i],l->b[i]);
        }
        printf("\n\n");
    }
}
void print_as_tree(bin *l)
{
    if(size==0)
    {
        Sleep(500);
        printf("This function can not be implemented as the priority queue is empty!!\n\n");
    }
    else
    {
        Sleep(500);
        int i,j,p,q;
        int c=log2(size);
        for(i=1;i<=c+1;i++)
        {
            p=(int)pow(2,i-1);
            for(j=1;j<=p;j++)
            {
                q=p-1+j;
                if(q>size)
                {
                    break;
                }
                printf("(%d,%.2f) ",l->a[q],l->b[q]);
                if(j%2==0)
                {
                    printf("  ");
                }
            }
            printf("\n");
            if(q>size)
            {
                break;
            }
        }
        printf("\n");
    }
}
int main()
{
    bin *l=(bin*)calloc(1,sizeof(bin));
    l->a=NULL;
    l->b=NULL;
    int d=0;
    while(1)
    {
        float p;
        int n;
        if(d==0)
        {
            printf("........Function to implement........\n");
            Sleep(500);
            printf(" 1 - Insert\n");
            Sleep(200);
            printf(" 2 - Delete\n");
            Sleep(200);
            printf(" 3 - Retrieve the node with minimum priority\n");
            Sleep(200);
            printf(" 4 - Print the priority queue as a linear array\n");
            Sleep(200);
            printf(" 5 - Print the priority queue as a binary tree/heap\n");
            Sleep(200);
            printf(" 6 - Exit\n");
            Sleep(300);
            printf("Press one of the above keys to continue.......... ");
            scanf("%f",&p);
            fflush(stdout);
            n=(int)p;
        }
        else
        {
            Sleep(500);
            printf("Which function are you about to execute?\n");
            printf("Look up from the above table and enter the corresponding key : ");
            scanf("%f",&p);
            fflush(stdout);
            n=(int)p;
        }
        while(p!=n || n<=0 || n>6)
        {
            printf("Invalid Input!! Try again.\n\n");
            Sleep(500);
            printf("Which function are you about to execute next?\n");
            printf("Look up from the above table and enter the corresponding key : ");
            scanf("%f",&p);
            fflush(stdout);
            n=(int)p;
        }
        int op=n;
        if(op==1)
        {
            l=ins(l);
            d=1;
        }
        else if(op==2)
        {
            l=del(l);
            d=1;
        }
        else if(op==3)
        {
            min_key(l);
            d=1;
        }
        else if(op==4)
        {
            print_as_queue(l);
            d=1;
        }
        else if(op==5)
        {
            print_as_tree(l);
            d=1;
        }
        else
        {
            return 0;
        }
    }
}
