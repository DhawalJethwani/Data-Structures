#include <stdio.h>
#include <stdlib.h>

char **mk_vertex_list(char *a[],int size)
{
    printf("\nEnter %d vertex names to fill the graph :\n",size);
    int i;
    for(i=1;i<=size;i++)
    {
        a[i-1]=(char *)malloc(20*sizeof(char));
        scanf("%s",a[i-1]);
    }
    printf("\nVertex List :\n");
    for(i=1;i<=size;i++)
    {
        printf("%d : %s\n",i,a[i-1]);
    }
    return a;
}

struct vertex
{
    int c;
    struct vertex *p;
};
typedef struct vertex vrtx;

struct vlist
{
    vrtx *lhead;
    vrtx *t;
    int state;
};
typedef struct vlist vl;

vl *mk_adjacency_list(vl b[],int size,int edges)
{
    printf("\nConnect these vertices with directed edges.\nEnter the index of the starting and the terminating vertex of the edge with the help of the vertex list :\n");
    int m,n,i;
    for(i=0;i<edges;i++)
    {
        float p1,p2;
        fflush(stdout);
        scanf("%f %f",&p1,&p2);
        m=(int)p1;
        n=(int)p2;
        while(p1!=m || m<0 || m>size || p2!=n || n<0 || n>size)
        {
            printf("Invalid Input! Node indices should be a non negative integers less than %d.\n",size);
            fflush(stdout);
            scanf("%f %f",&p1,&p2);
            m=(int)p1;
            n=(int)p2;
        }
        if(!b[m-1].lhead)
        {
            b[m-1].lhead=(vrtx *)calloc(1,sizeof(vrtx));
            b[m-1].t=b[m-1].lhead;
            b[m-1].lhead->c=n;
            b[m-1].state=0;
        }
        else
        {
            b[m-1].t->p=(vrtx *)calloc(1,sizeof(vrtx));
            b[m-1].t=b[m-1].t->p;
            b[m-1].t->c=n;
            b[m-1].state=0;
        }
    }
    for(i=1;i<=size;i++)
    {
        b[i-1].t=b[i-1].lhead;
    }
    return b;
}

void print_adjacency_list(vl *b,int size)
{
    printf("\nAdjacency List :\n");
    int i;
    for(i=1;i<=size;i++)
    {
        printf("%d  :  ",i);
        vrtx *x=b[i-1].lhead;
        while(x)
        {
            printf("%d ",x->c);
            x=x->p;
        }
        printf("\n");
    }
}

int k=0;

void subdfs(int i,vl *b,int *arr)
{
    vrtx *curr=b[i-1].t;
    if(!curr)
    {
        b[i-1].state=2;
        return 1;
    }
    else
    {
        vrtx *temp=curr;
        while(temp)
        {
            if(b[temp->c-1].state==1)
            {
                printf("\nGraph has a cycle!!\n");
                exit(0);
            }
            temp=temp->p;
        }
        temp=curr;
        while(temp)
        {
            if(b[temp->c-1].state==0)
            {
                b[temp->c-1].state=1;
                subdfs(temp->c,b,arr);
                arr[k]=temp->c;
                k++;
                b[temp->c-1].state=2;
            }
            temp=temp->p;
        }
    }
}

int *dfs(vl *b,int size)
{
    int *arr=(int *)malloc(size*sizeof(int));
    int i;
    for(i=1;i<=size;i++)
    {
        if(b[i-1].state==0)
        {
            b[i-1].state=1;
            subdfs(i,b,arr);
            arr[k]=i;
            k++;
            b[i-1].state=2;
        }
    }
    return arr;
}

int main()
{
    float p;
    int size;
    printf("Enter the number of nodes in the graph : ");
    scanf("%f",&p);
    size=(int)p;
    while(p!=size || size<0)
    {
        printf("Invalid Input! Size should be a non negative integer.\n\nEnter the number of nodes in the graph : ");
        scanf("%f",&p);
        size=(int)p;
    }
    int edges;
    printf("Enter the number of edges in the graph : ");
    scanf("%f",&p);
    edges=(int)p;
    while(p!=edges || edges<0 || edges>size*size)
    {
        printf("Invalid Input! Number of edges should be a non negative integer, less than (size)^2.\n\nEnter the number of edges in the graph : ");
        scanf("%f",&p);
        edges=(int)p;
    }
    char *a[size];
    vl *b=(vl *)calloc(size,sizeof(vl));
    mk_vertex_list(a,size);
    b=mk_adjacency_list(b,size,edges);
    print_adjacency_list(b,size);
    int *arr=dfs(b,size);
    printf("\nTopological Sort for the above graph :\n");
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[size-i-1]);
    }
    return 0;
}
