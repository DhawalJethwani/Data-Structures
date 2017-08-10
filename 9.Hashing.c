#include <stdio.h>
#include <stdlib.h>

struct index
{
    int c;
    struct index *p;
};
typedef struct index in;

struct valnode
{
    in *lhead;
    int value;
};
typedef struct valnode vn;

int hash_ch(int value)
{
    return value%7;
}

vn *mk_hash_table_ch(vn a[],int size)
{
    printf("\nEnter %d numbers you want to insert in the hash table :\n",size);
    int i,val;
    for(i=0;i<size;i++)
    {
        float p;
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
        while(p!=val)
        {
            printf("Invalid Input! Values should be a non negative integer.\n");
            fflush(stdout);
            scanf("%f",&p);
            val=(int)p;
        }
        int j=hash_ch(val);
        in *t=a[j].lhead;
        a[j].lhead=(in *)calloc(1,sizeof(in));
        a[j].lhead->p=t;
        a[j].lhead->c=val;
    }
    return a;
}

void search_ch(vn a[],int size)
{
    printf("\nEnter the number you want to search in the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int j=hash_ch(val);
    in *curr=a[j].lhead;
    int d=0;
    while(curr)
    {
        if(curr->c==val)
        {
            d=1;
            break;
        }
        curr=curr->p;
    }
    if(d==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }
}

vn *delete_ch(vn a[])
{
    printf("\nEnter the number you want to delete from the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int j=hash_ch(val);
    in *curr=a[j].lhead;
    int d=0,e;
    in *t;
    if(curr && curr->c==val)
    {
        a[j].lhead=curr->p;
        free(curr);
        d=1;
    }
    else if(curr)
    {
        while(curr)
        {
            if(curr->p && curr->p->c==val)
            {
                    in *t=curr->p;
                    curr->p=curr->p->p;
                    free(t);
                    d=1;
                    break;
            }
            curr=curr->p;
        }
    }
    if(d==0)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Deleted value : %d\n",val);
    }
    return a;
}

void print_hash_table_ch(vn *a,int size)
{
    printf("\nHash Table :\n");
    int i;
    for(i=0;i<7;i++)
    {
        printf("%d  :  ",i);
        in *x=a[i].lhead;
        while(x)
        {
            printf("%d ",x->c);
            x=x->p;
        }
        printf("\n");
    }
}

struct node1
{
    int c;
    int state;
};
typedef struct node1 n1;

int hash_lp(int size,int val,int k)
{
    return ((val%size)+k)%size;
}

n1 *mk_hash_table_lp(n1 *a,int size)
{
    printf("\nEnter %d numbers you want to insert in the hash table :\n",size);
    int i,j,val;
    for(i=0;i<size;i++)
    {
        float p;
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
        while(p!=val)
        {
            printf("Invalid Input! Values should be a non negative integer.\n");
            fflush(stdout);
            scanf("%f",&p);
            val=(int)p;
        }
        int k=0;
        int j=hash_lp(size,val,k);
        k++;
        if(a[j].state==0)
        {
            a[j].c=val;
            a[j].state=1;
        }
        else
        {
            while(a[j].state==1)
            {
                j=hash_lp(size,val,k);
                k++;
            }
            a[j].c=val;
            a[j].state=1;
        }
    }
    return a;
}

void search_lp(n1 a[],int size)
{
    printf("\nEnter the number you want to search in the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int k=0;
    int j=hash_lp(size,val,k);
    int d=0;
    for(i=0;i<size;i++)
    {
        if(a[j].c==val)
        {
            d=1;
            break;
        }
        k++;
        j=hash_lp(size,val,k);
    }
    if(d==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }
}

n1 *delete_lp(n1 a[],int size)
{
    printf("\nEnter the number you want to delete from the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int k=0;
    int j=hash_lp(size,val,k);
    int d=0;
    for(i=0;i<size,a[j].state!=0;i++)
    {
        if(a[j].c==val)
        {
            a[j].c=-99;
            a[j].state=2;
            d=1;
            break;
        }
        k++;
        j=hash_lp(size,val,k);
    }
    if(d==0)
    {
        printf("Key not found\n");
    }
    return a;
}

void print_hash_table_lp(n1 *a,int size)
{
    int i;
    printf("\nHash Table :\n");
    for(i=0;i<size;i++)
    {
        if(a[i].state==1)
        {
            printf("%d : %d\n",i,a[i].c);
        }
        else
        {
            printf("%d :\n",i);
        }
    }
}

struct node2
{
    int c;
    int state;
};
typedef struct node2 n2;

int hash_qp(int size,int val,int k)
{
    return ((val%size)+k*k)%size;
}

n1 *mk_hash_table_qp(n1 *a,int size)
{
    printf("\nEnter %d numbers you want to insert in the hash table :\n",size);
    int i,j,val;
    for(i=0;i<size;i++)
    {
        float p;
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
        while(p!=val)
        {
            printf("Invalid Input! Values should be a non negative integer.\n");
            fflush(stdout);
            scanf("%f",&p);
            val=(int)p;
        }
        int k=0;
        int j=hash_qp(size,val,k);
        k++;
        if(a[j].state==0)
        {
            a[j].c=val;
            a[j].state=1;
        }
        else
        {
            while(a[j].state==1)
            {
                j=hash_qp(size,val,k);
                k++;
            }
            a[j].c=val;
            a[j].state=1;
        }
    }
    return a;
}

void search_qp(n1 a[],int size)
{
    printf("\nEnter the number you want to search in the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int k=0;
    int j=hash_qp(size,val,k);
    int d=0;
    for(i=0;i<size;i++)
    {
        if(a[j].c==val)
        {
            d=1;
            break;
        }
        k++;
        j=hash_qp(size,val,k);
    }
    if(d==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }
}

n1 *delete_qp(n1 a[],int size)
{
    printf("\nEnter the number you want to delete from the hash table :\n");
    int i,val;
    float p;
    fflush(stdout);
    scanf("%f",&p);
    val=(int)p;
    while(p!=val)
    {
        printf("Invalid Input! Values should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        val=(int)p;
    }
    int k=0;
    int j=hash_qp(size,val,k);
    int d=0;
    for(i=0;i<size;i++)
    {
        if(a[j].state==0)
        {
            break;
        }
        if(a[j].c==val)
        {
            a[j].c=-99;
            a[j].state=2;
            d=1;
            break;
        }
        k++;
        j=hash_lp(size,val,k);
    }
    if(d==0)
    {
        printf("Key not found\n");
    }
    return a;
}

void print_hash_table_qp(n1 *a,int size)
{
    int i;
    printf("\nHash Table :\n");
    for(i=0;i<size;i++)
    {
        if(a[i].state==1)
        {
            printf("%d : %d\n",i,a[i].c);
        }
        else
        {
            printf("%d :\n",i);
        }
    }
}

int main()
{
    while(1)
    {
        printf("\nPlease enter the number corresponding to the way you want to resolve collisions:\n");
        printf("1.Linear Probing\n2.Quadratic Probing\n3.Separate Chaining\n4.Exit\n");
        float p;
        int d;
        scanf("%f",&p);
        d=(int)p;
        while(p!=d || d<0 || d>4)
        {
            printf("Invalid Input! Input should be a non negative integer.\n\nTry again : ");
            scanf("%f",&p);
            d=(int)p;
        }
        if(d==1)
        {
            float q;
            int size;
            printf("Enter the number of elements to insert in the hash table : ");
            scanf("%f",&q);
            size=(int)q;
            while(q!=size || size<0)
            {
                printf("Invalid Input! Size should be a non negative integer.\n\nEnter the number of elements to insert in the hash table : ");
                scanf("%f",&p);
                size=(int)q;
            }
            n1 *a=(n1 *)calloc(size,sizeof(n1));
            a=mk_hash_table_lp(a,size);
            while(1)
            {
                printf("\nEnter your choice :\n");
                printf("1.Deletion\n2.Search\n3.Print the Hash Table\n4.End or try some other method for resolving collision\n");
                float r;
                int c;
                scanf("%f",&r);
                c=(int)r;
                while(r!=c || c<0 || c>5)
                {
                    printf("Invalid Input! Input should be a non negative integer.\n\nTry again : ");
                    scanf("%f",&r);
                    c=(int)r;
                }
                if(c==1)
                {
                    a=delete_lp(a,size);
                }
                else if(c==2)
                {
                    search_lp(a,size);
                }
                else if(c==3)
                {
                    print_hash_table_lp(a,size);
                }
                else if(c==4)
                {
                    break;
                }
            }
        }
        else if(d==2)
        {
            float q;
            int size;
            printf("Enter the number of elements to insert in the hash table : ");
            scanf("%f",&q);
            size=(int)q;
            while(q!=size || size<0)
            {
                printf("Invalid Input! Size should be a non negative integer.\n\nEnter the number of elements to insert in the hash table : ");
                scanf("%f",&p);
                size=(int)q;
            }
            n2 *a=(n2 *)calloc(size,sizeof(n2));
            a=mk_hash_table_qp(a,size);
            while(1)
            {
                printf("\nEnter your choice :\n");
                printf("1.Deletion\n2.Search\n3.Print the Hash Table\n4.End or try some other method for resolving collisions\n");
                float r;
                int c;
                scanf("%f",&r);
                c=(int)r;
                while(r!=c || c<0 || c>5)
                {
                    printf("Invalid Input! Size should be a non negative integer.\n\n : ");
                    scanf("%f",&r);
                    c=(int)r;
                }
                if(c==1)
                {
                    a=delete_qp(a,size);
                }
                else if(c==2)
                {
                    search_qp(a,size);
                }
                else if(c==3)
                {
                    print_hash_table_qp(a,size);
                }
                else if(c==4)
                {
                    break;
                }
            }
        }
        else if(d==3)
        {
            float q;
            int size;
            printf("Enter the number of elements to insert in the hash table : ");
            scanf("%f",&q);
            size=(int)q;
            while(q!=size || size<0)
            {
                printf("Invalid Input! Size should be a non negative integer.\n\nEnter the number of elements to insert in the hash table : ");
                scanf("%f",&p);
                size=(int)q;
            }
            vn *a=(vn *)calloc(7,sizeof(vn));
            a=mk_hash_table_ch(a,size);
            while(1)
            {
                printf("\nEnter your choice :\n");
                printf("1.Deletion\n2.Search\n3.Print the Hash Table\n4.End or try some other method for resolving collision\n");
                float r;
                int c;
                scanf("%f",&r);
                c=(int)r;
                while(r!=c || c<0 || c>5)
                {
                    printf("Invalid Input! Input should be a non negative integer.\n\nTry again : ");
                    scanf("%f",&r);
                    c=(int)r;
                }
                if(c==1)
                {
                    a=delete_ch(a);
                }
                else if(c==2)
                {
                    search_ch(a,size);
                }
                else if(c==3)
                {
                    print_hash_table_ch(a,size);
                }
                else if(c==4)
                {
                    break;
                }
            }
        }
        else if(d==4)
        {
            break;
        }
    }
    return 0;
}

