#include<stdio.h>
#include<math.h>
#include<dos.h>

void ascending(int a[])
{
	int temp=0;
	int i1=0,j1=0;
	for(i1=0;i1<4;i1++)
	{
		for(j1=0;j1<3-i1;j1++)
		{
			if(a[j1]>a[j1+1])
			{
				temp=a[j1];
				a[j1]=a[j1+1];
				a[j1+1]=temp;
			}
		}
	}
}

void descending(int a[])
{
	int temp=0;
	int i1=0,j1=0;
	for(i1=0;i1<4;i1++)
	{
		for(j1=0;j1<3-i1;j1++)
		{
			if(a[j1]<a[j1+1])
			{
				temp=a[j1];
				a[j1]=a[j1+1];
				a[j1+1]=temp;
			}
		}
	}
	
}

int digit(int a[])
{
	int i2=0,sum=0;
	for(i2=0;i2<4;i2++)
	{
		sum+=pow(10,3-i2)*a[i2];
	}
	return sum;
}
int main()
{
	int des[4],asc[4];
	int n=0,i=0;
	int small=0,big=0;
	int diff=0,ldiff=0;
	printf("Enter the four digit number : ");
	scanf("%d",&n);
	int dup=n;
	for(i=3;i>=0;i--)
	{
		des[i]=asc[i]=dup%10;
		dup/=10;
	}
	
	ascending(asc);
	descending(des);
	int n1=0;
	while(1)
	{
		small=digit(asc);
		big=digit(des);
		
		diff=big-small;
		if(diff==ldiff)
		{
			printf("The Kaprekar constant is : %d",diff);
			return 0;
		}
		n1=diff;
		for(i=3;i>=0;i--)
		{
			des[i]=asc[i]=n1%10;
			n1/=10;
		}
		
		ascending(asc);
		descending(des);
		
		ldiff=diff;
	}
	
	
	return 0;
}
