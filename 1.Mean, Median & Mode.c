#include <stdio.h>
void oneElmtSort(int n,float a[])
{
    float e=a[n-1];
    int i,j;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>e)
        {
            a[i+1]=a[i];
            if(i==0)
            {
                a[0]=e;
            }
        }
        else
        {
            a[i+1]=e;
            break;
        }
    }
}
void Sort(float a[],int n)
{
    int i,j,a_sz;
    for(a_sz=2;a_sz<=n;a_sz++)
    {
        oneElmtSort(a_sz,a);
    }
}
int main()
{
	int n,i;
	float sum=0;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	float a[n];
	printf("Enter %d elements to fill the array :\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%f",a+i);
		sum+=a[i];
	}
	float mean=sum/n;
	Sort(a,n);
	printf("\n");
	printf("This is your array after sorting :\n");
	for(i=0;i<n;i++)
    {
        printf("%.2f  ",a[i]);
    }
    printf("\n");
	float median;
	if(n%2==0)
	{
		median=(a[n/2-1]+a[n/2])/2;
	}
	else
	{
		median=a[n/2];
	}
	int b[n];
	for(i=0;i<n;i++)
	{
		b[i]=0;
	}
	float c[n];
	int j,k=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]!=a[i] && j!=(n-1))
			{
				b[k]=j-i;
				c[k]=a[i];
				i=j-1;
				k++;
				break;
			}
			else if(a[j]!=a[i] && j==(n-1))
            {
                b[k]=j-i;
                c[k]=a[i];
                k++;
                b[k]=1;
                c[k]=a[j];
                i=n;
            }
            else if(j==n-1)
            {
                b[k]=j-i+1;
                c[k]=a[i];
                i=n;
            }
		}
	}
	int p=b[0],t;
	for(i=0;i<k+1;i++)
	{
        if(p<b[i])
		{
			p=b[i];
		}
	}
	printf("\nStatistical analysis of entered data : \n\n   Mean : %.2f\n   Median : %.2f\n   Mode : ",mean,median);
	int d=0;
    for(i=0;i<k+1;i++)
	{
	    if(b[i]==p)
        {
            d++;
            if(d==1)
            {
                printf("%.2f",c[i]);
            }
            else
            {
                printf(", %.2f",c[i]);
            }
        }
	}
	printf("\n");
	return 0;
}
