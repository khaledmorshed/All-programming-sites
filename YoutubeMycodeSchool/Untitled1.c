#include<stdio.h>
int main()
{
    int i,j,n;
    int a[100];

    printf("The array number is: ");
    scanf("%d",&n);
    printf("The array numbers are : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&n);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                a[j]=-1;
                a[i]=-1;
            }
        }
    }
    printf("The unique elements of  array are : ");
    for(i=0;i<n;i++)
    {
        if(a[i]!=-1)
        printf("%d \n",a[i]);

    }

    return 0;


}
