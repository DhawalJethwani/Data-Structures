#include <stdio.h>
int tp=-1;
void push(char x,char sym[])
{
    tp++;
    sym[tp]=x;
}
char pop(char sym[])
{
    if(tp<0)
    {
        return 'a';
    }
    else
    {
        tp--;
        return sym[tp+1];
    }
}
char top(char sym[])
{
    if(top<0)
    {
        return 'a';
    }
    else
    {
        return sym[tp];
    }
}
int order(char sym1)
{
    if(sym1=='^')
    {
        return 4;
    }
    else if(sym1=='*' || sym1=='/')
    {
        return 3;
    }
    else if(sym1=='+' || sym1=='-')
    {
        return 2;
    }
    else if(sym1==')')
    {
        return 1;
    }
    if(sym1=='(')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
void wtdw_optr(char x,char sym[])
{
    int o1=order(x);
    int o2=order(top(sym));
    char o3;
    if(o2=='a')
    {
        push(x,sym);
    }
    else if(o1==0)
    {
        push(x,sym);
    }
    else if(o1==1)
    {
        while(top(sym)!='(')
        {
            o3=pop(sym);
            printf("%c ",o3);
        }
        pop(sym);
    }
    else if(o1>=o2)
    {
        push(x,sym);
    }
    else
    {
        while(o1<o2)
        {
            o3=pop(sym);
            printf("%c ",o3);
            o2=order(top(sym));
        }
        push(x,sym);
    }
}
int isalphanum(char c)
{
    if(c>='a' && c<='z') return 1;
    else if(c>='A' && c<='Z') return 1;
    else if(c>='0' && c<='9') return 1;
    else if(c=='.') return 1;
    return 0;
}
int main()
{
    int i;
    char c;
    char str[200],sym[150];
    p:
    printf("Enter a valid infix expression : \n");
    scanf("%s",str);
    for(i=0;str[i+1]!='\0';i++)
    {
        if((str[i]=='^' || str[i]=='/' || str[i]=='*' || str[i]=='+' || str[i]=='-') && (str[i+1]=='^' || str[i+1]=='/' || str[i+1]=='*' || str[i+1]=='+' || str[i+1]=='-'))
        {
            printf("\nInvalid input!! Consecutive symbols not allowed. Try again!!\n");
            goto p;
        }
    }
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!='(' && str[i]!='^' && str[i]!='/' && str[i]!='*' && str[i]!='+' && str[i]!='-' && str[i]!=')' && !isalphanum(str[i]))
         {
             printf("\nInvalid input!! Symbol '%c' not allowed. Try again!!\n",str[i]);
             goto p;
         }
    }
    int c1=0,c2=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(') c1++;
        if(str[i]==')') c2++;
        if(c2>c1)
        {
            printf("\nInvalid input!! Error in placing opening and closing brackets. Try again!!\n",str[i]);
            goto p;
        }
    }
    if(c1!=c2)
    {
        printf("\nInvalid input!! Error in number of brackets. Number of opening and closing brackets should be equal. Try again!!\n",str[i]);
        goto p;
    }
    printf("\nThe postfix expression for the above notation is :\n");
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]=='(' || str[i]=='^' || str[i]=='/' || str[i]=='*' || str[i]=='+' || str[i]=='-' || str[i]==')'))
        {
            printf(" ");
            wtdw_optr(str[i],sym);
        }
        else if(isalphanum(str[i]))
        {
            printf("%c",str[i]);
        }
    }
    while(order(top(sym))!=-1)
    {
        c=pop(sym);
        printf("%c ",c);
    }
    return 0;
}
