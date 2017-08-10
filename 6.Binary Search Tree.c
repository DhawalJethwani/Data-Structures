#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

int conv=1;
struct node
{
    char a;
    struct node *parent;
    struct node *lchild;
    struct node *rchild;
    int flag;
};
typedef struct node str;

str *ins_node(str *root)
{
    str *temp=calloc(1,sizeof(str));
    if(temp)
    {
        char *string=(char *)malloc(100*sizeof(char));
        printf("Enter a character to insert in the tree\n");
        printf("(If you enter more than 1 characters then only 1st one will be accepted) : ");
        fflush(stdout);
        gets(string);
        Sleep(750);
        printf("   Accepted character : %c\n",string[0]);
        temp->a=string[0];
        if(!root)
        {
            root=temp;
        }
        else
        {
            str *temp1=root;
            while(1)
            {
                if(temp->a<=temp1->a)
                {
                    if(temp1->lchild==0)
                    {
                        temp1->lchild=temp;
                        temp->parent=temp1;
                        break;
                    }
                    else
                    {
                        temp1=temp1->lchild;
                    }
                }
                else if(temp->a>temp1->a)
                {
                    if(temp1->rchild==0)
                    {
                        temp1->rchild=temp;
                        temp->parent=temp1;
                        break;
                    }
                    else
                    {
                        temp1=temp1->rchild;
                    }
                }
            }
        }
        Sleep(750);
        printf("   Successfully inserted!!\n\n");
    }
    else
    {
        Sleep(750);
        printf("   Overflow!!\n\n");
    }
    return root;
}

str *del_node(str *root)
{
    int d;
    str *temp=root;
    if(temp)
    {
        char key;
        str *node=0;
        printf("Enter a character to delete from the tree, if it is present\n");
        char *string=(char *)malloc(100*sizeof(char));
        printf("(If you enter more than 1 characters then only 1st one will be accepted) : ");
        fflush(stdout);
        gets(string);
        Sleep(750);
        printf("   Accepted character : %c\n",string[0]);
        key=string[0];
        while(1)
        {
            d=0;
            if(temp->a==key)
            {
                d=1;
                node=temp;
                break;
            }
            else if(key<=temp->a && temp->lchild)
            {
                temp=temp->lchild;
            }
            else if(key>temp->a && temp->rchild)
            {
                temp=temp->rchild;
            }
            else
            {
                node=NULL;
                break;
            }
        }
        if(node)
        {
            if(!node->lchild && !node->rchild && !node->parent)
            {
                root=NULL;
            }
            else if(!node->lchild && !node->rchild)
            {
                if(node->parent->lchild==node)
                {
                    node->parent->lchild=NULL;
                    node->parent=NULL;
                }
                else
                {
                    node->parent->rchild=NULL;
                    node->parent=NULL;
                }
            }
            else if(!node->lchild)
            {
                int e=0;
                str *t=node->rchild;
                while(t->lchild)
                {
                    t=t->lchild;
                    e=1;
                }
                if(t->rchild)
                {
                    t->rchild->parent=t->parent;
                    if(e==0)
                    {
                        t->rchild->parent->rchild=t->rchild;
                    }
                    else
                    {
                        t->rchild->parent->lchild=t->rchild;
                    }
                }
                else
                {
                    if(e==0)
                    {
                        t->parent->rchild=NULL;
                    }
                    else
                    {
                        t->parent->lchild=NULL;
                    }
                }
                t->parent=NULL;
                if(node->lchild)
                {
                    t->lchild=node->lchild;
                    node->lchild->parent=t;
                    node->lchild=NULL;
                }
                if(node->rchild)
                {
                    t->rchild=node->rchild;
                    t->rchild->parent=t;
                    node->rchild=NULL;
                }
                if(node->parent)
                {
                    t->parent=node->parent;
                    if(node->parent->rchild==node)
                    {
                        t->parent->rchild=t;
                    }
                    else
                    {
                        t->parent->lchild=t;
                    }
                    node->parent=NULL;
                }
                else
                {
                    root=t;
                }
            }
            else
            {
                int e=0;
                str *t=node->lchild;
                while(t->rchild)
                {
                    t=t->rchild;
                    e=1;
                }
                if(t->lchild)
                {
                    t->lchild->parent=t->parent;
                    if(e==0)
                    {
                        t->lchild->parent->lchild=t->lchild;
                    }
                    else
                    {
                        t->lchild->parent->rchild=t->lchild;
                    }
                }
                else
                {
                    if(e==0)
                    {
                        t->parent->lchild=NULL;
                    }
                    else
                    {
                        t->parent->rchild=NULL;
                    }
                }
                t->parent=NULL;
                if(node->rchild)
                {
                    t->rchild=node->rchild;
                    node->rchild->parent=t;
                    node->rchild=NULL;
                }
                if(node->lchild)
                {
                    t->lchild=node->lchild;
                    t->lchild->parent=t;
                    node->lchild=NULL;
                }
                if(node->parent)
                {
                    t->parent=node->parent;
                    if(node->parent->lchild==node)
                    {
                        t->parent->lchild=t;
                    }
                    else
                    {
                        t->parent->rchild=t;
                    }
                    node->parent=NULL;
                }
                else
                {
                    root=t;
                }
            }
            free(node);
            Sleep(750);
            printf("   Successfully Deleted!!\n\n");
        }
        else
        {
            Sleep(750);
            printf("   Character is not found!!\n\n");
        }
    }
    else
    {
        Sleep(750);
        printf("   Underflow!!\n   Oops!! The tree is empty!!\n\n");
    }
    return root;
}

void search_key(str *temp)
{
    int d;
    if(temp)
    {
        char key;
        Sleep(500);
        printf("Enter character to search in the tree\n");
        char *string=(char *)malloc(100*sizeof(char));
        Sleep(250);
        printf("(If you enter more than 1 characters then only 1st one will be accepted) : ");
        fflush(stdout);
        gets(string);
        Sleep(750);
        printf("   Accepted character : %c\n",string[0]);
        key=string[0];
        while(1)
        {
            d=0;
            if(temp->a==key)
            {
                d=1;
                break;
            }
            else if(key<=temp->a && temp->lchild)
            {
                temp=temp->lchild;
            }
            else if(key>temp->a && temp->rchild)
            {
                temp=temp->rchild;
            }
            else
            {
                break;
            }
        }
        if(d==0)
        {
            Sleep(750);
            printf("   Key not found!!\n\n");
            return;
        }
        else if(d==1)
        {
            Sleep(750);
            printf("   Key found!!\n\n");
            return;
        }
    }
    else
    {
        Sleep(750);
        printf("   Oops!! The tree is empty!!\n\n");
        return;
    }
}

void min_val(str *temp)
{
    while(temp->lchild)
    {
        temp=temp->lchild;
    }
    Sleep(750);
    printf("   Character with minimum ASCII value : %c\n\n",temp->a);
}

void max_val(str *temp)
{
    while(temp->rchild)
    {
        temp=temp->rchild;
    }
    Sleep(750);
    printf("   Character with maximum ASCII value : %c\n\n",temp->a);
}

void print_preorder(str *temp)
{
    while(temp)
    {
        if(temp->flag==0)
        {
            printf("%c ",temp->a);
        }
        temp->flag=2;
        if(temp->lchild==0)
        {
            if(temp->rchild && temp->rchild->flag!=conv)
            {
                temp=temp->rchild;
            }
            else
            {
                temp->flag=conv;
                temp=temp->parent;
            }
        }
        else if(temp->lchild && temp->lchild->flag!=conv)
        {
            temp=temp->lchild;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild && temp->rchild->flag!=conv)
        {
            temp=temp->rchild;
        }
        else
        {
            temp->flag=conv;
            temp=temp->parent;
        }
    }
    conv=abs(conv-1);
}

void print_inorder(str *temp)
{
    while(temp)
    {
        if(temp->lchild==0)
        {
            if((temp->rchild && temp->rchild->flag!=conv) || temp->rchild==0)
            {
                printf("%c ",temp->a);
            }
            if(temp->rchild && temp->rchild->flag!=conv)
            {
                temp=temp->rchild;
            }
            else
            {
                temp->flag=conv;
                temp=temp->parent;
            }
        }
        else if(temp->lchild && temp->lchild->flag!=conv)
        {
            temp=temp->lchild;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild==0)
        {
            printf("%c ",temp->a);
            temp->flag=conv;
            temp=temp->parent;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild && temp->rchild->flag!=conv)
        {
            printf("%c ",temp->a);
            temp=temp->rchild;
        }
        else
        {
            temp->flag=conv;
            temp=temp->parent;
        }
    }
    conv=abs(conv-1);
}

void print_preorder1(str *temp)
{
    if(temp)
    {
        printf("%c ",temp->a);
        print_preorder(temp->lchild);
        print_preorder(temp->rchild);
    }
}

void print_inorder1(str *temp)
{
    if(temp)
    {
        print_inorder(temp->lchild);
        printf("%c ",temp->a);
        print_inorder(temp->rchild);
    }
}

void print_postorder(str *temp)
{
    if(temp)
    {
        print_postorder(temp->lchild);
        print_postorder(temp->rchild);
        printf("%c ",temp->a);
    }
}

int main()
{
    str *root=0;
    int op=1,d=0;
    char *x=(char *)malloc(100*sizeof(char));
    Sleep(750);
    printf("............Keys corresponding to the function to implement............\n");
    Sleep(500);
    printf(" 1 - Insert\n 2 - Delete\n 3 - Search\n 4 - Traversal(Preorder)\n 5 - Traversal(Inorder)\n 6 - Traversal(Postorder)\n 7 - Find minimum entry\n 8 - Find maximum entry\n 9 - Exit\n");
    Sleep(1000);
    printf("Press one of the above keys to continue...... ");
    while(1)
    {
        if(op>0 && op<10)
        {
            if(d)
            {
                Sleep(500);
                printf("Which function are you about to execute next?\n");
                Sleep(250);
                printf("Look up from the above table and enter the corresponding key : ");
            }
            fflush(stdout);
            gets(x);
            Sleep(500);
            printf("   Entered Value : %c\n",x[0]);
            Sleep(750);
            op=x[0]-'0';
            if(op>0 && op<10)
            {
                printf("   Value Accepted!!\n\n");
                Sleep(750);
            }
            if(op==1)
            {
                root=ins_node(root);
                d=1;
            }
            else if(op==2)
            {
                root=del_node(root);
                d=1;
            }
            else if(op==3)
            {
                search_key(root);
                d=1;
            }
            else if(op==4)
            {
                if(root)
                {
                    Sleep(250);
                    printf("   The tree when traversed in Preorder :\n   ");
                    Sleep(750);
                    print_preorder(root);
                    printf("\n\n");
                }
                else
                {
                    Sleep(750);
                    printf("   Oops!!The tree is empty!!\n\n");
                }
                d=1;
            }
            else if(op==5)
            {
                if(root)
                {
                    Sleep(250);
                    printf("   The tree when traversed in Inorder :\n   ");
                    Sleep(750);
                    print_inorder(root);
                    printf("\n\n");
                }
                else
                {
                    Sleep(750);
                    printf("   Oops!!The tree is empty!!\n\n");
                }
                d=1;
            }
            else if(op==6)
            {
                if(root)
                {
                    Sleep(250);
                    printf("   The tree when traversed in Postorder :\n   ");
                    Sleep(750);
                    print_postorder(root);
                    printf("\n\n");
                }
                else
                {
                    Sleep(750);
                    printf("   Oops!!The tree is empty!!\n\n");
                }
                d=1;
            }
            else if(op==7)
            {
                if(root)
                {
                    min_val(root);
                }
                else
                {
                    Sleep(750);
                    printf("   Oops!!The tree is empty!!\n\n");
                }
                d=1;
            }
            else if(op==8)
            {
                if(root)
                {
                    max_val(root);
                }
                else
                {
                    Sleep(750);
                    printf("   Oops!!The tree is empty!!\n\n");
                }
                d=1;
            }
            else if(op==9)
            {
                system("cls");
                int j;
                printf("\n");
                for(j=0;j<10;j++)
                {
                    printf(".");
                    Sleep(500);
                }
                printf("Good Bye!!\n");
                Sleep(1000);
                break;
            }
        }
        else
        {
            Sleep(250);
            printf("   Invalid Input!! Try Again.\n\n");
            Sleep(750);
            op=1;
            d=1;
        }
    }
    return 0;
}
