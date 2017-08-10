#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int sz=0;
struct node
{
    float a;
    struct node *pa;
};
typedef struct node str;
str* rtn_ptr_of_node_index(int m,str* head)
{
    str* thead=head;
    int i;
    if(m>0)
    {
        for(i=1;i<m;i++)
        {
            thead=thead->pa;
        }
        return thead;
    }
    else
    {
        return NULL;
    }
}
str* ins_nd_aft(str* head)
{
    float p;
    int k;
    printf("Enter the index of the node after which you want to insert the new node (Press 0 for insertion at beginning) : ");
    scanf("%f",&p);
    k=(int)p;
    while(p!=k || k<0 || k>sz)
    {
        printf("Invalid Input! Index should be a positive integer less than or equal to size of linked list(i.e. %d).\n\nEnter the index of the node after which you want to insert the new node : ",sz);
        scanf("%f",&p);
        k=(int)p;
    }
    int m=k;
    str* temp = calloc(1,sizeof(str));
    if(temp)
    {
        float val;
        printf("Enter a value to fill in this new node : ");
        scanf("%f",&(temp->a));
        sz++;
        if(m>0)
        {
            str* pnode=rtn_ptr_of_node_index(m,head);
            temp->pa = pnode->pa;
            pnode->pa = temp;
            return head;
        }
        else if(m==0)
        {
            temp->pa = head;
            head = temp;
            return head;
        }
    }
    else
    {
        return NULL;
    }
}
str* dlt_node(str* head)
{
    if(sz>0)
    {
        int i;
        str* temp;
        str* thead=head;
        float p;
        int k;
        printf("Enter the index of the node you want to delete : ");
        scanf("%f",&p);
        k=(int)p;
        while(p!=k || k<=0 || k>sz)
        {
            printf("Invalid Input! Index should be a positive integer less than or equal to size of linked list.\n\nEnter the index of the node you want to delete : ");
            scanf("%f",&p);
            k=(int)p;
        }
        if(k==1)
        {
            sz--;
            temp=head->pa;
            free(head);
            return temp;
        }
        else if(k<=sz)
        {
            sz--;
            rtn_ptr_of_node_index(k-1,head);
            temp=thead->pa;
            thead->pa=thead->pa->pa;
            free(temp);
            return head;
        }
    }
    else
    {
        printf("Underflow!! List is empty. Operation not allowed.\n\n");
    }
}
int is_emp(str* head)
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void print_vals_in_lst(str* head)
{
    str* temp=head;
    if(temp==NULL)
    {
        printf("List is empty!!\n\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%f ",temp->a);
        temp=temp->pa;
    }
    printf("\n");
}
int main()
{
    str* head=NULL;
    while(1)
    {
        float p;
        int n;
        printf("Press 1 for insertion, 2 for deletion, 3 for printing the list, 4 for checking  if list is empty, and 5 to exit :");
        scanf("%f",&p);
        n=(int)p;
        while(p!=n || n<=0 || n>5)
        {
            printf("Invalid Input!! Try again.\nPress 1 for insertion, 2 for deletion, 3 for printing the list, 4 for checking if list is empty, and 5 to exit :");
            scanf("%f",&p);
            n=(int)p;
        }
        int op=n;
        if(op==1)
        {
            head=ins_nd_aft(head);
        }
        else if(op==2)
        {
            head=dlt_node(head);
        }
        else if(op==3)
        {
            print_vals_in_lst(head);
        }
        else if(op==4)
        {
            int t=is_emp(head);
            if(t==1)
            {
                printf("List is empty!!\n");
            }
            else if(t==0)
            {
                printf("List has %d elements!!",sz);
            }
        }
        else
        {
            return 0;
        }
    }
}
