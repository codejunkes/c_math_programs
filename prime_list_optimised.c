// Effecient way to find the list if prime numbers in sigle thread.
// Further improvement is to make it multi-threaded so that it will be yet more optimised.

#include<stdio.h>

void main()
{
	long signed int a[35000],h=400000,i,j,b;
	FILE *fp;

	a[0]=2;
	a[1]=3;
	i=2;
	while(a[i-1]<=h)
	{
		a[i]=a[i-1]+2;

	rev:	for(j=0;j<=i/2;j++)
		{
			b=a[i]%a[j];
			if(b==0)
				break;
			else
				continue;
		}
		if(b!=0)
		{
			//printf("\t%ld",a[i]);
			i++;
		}
		else
		{
			a[i]=a[i]+1;
			goto rev;
		}
	}


// Saving the output to a file.
	printf("Printing the list of prime numbers to a file 'Prime_list.txt'\n");
	fp = fopen("Prime_list.txt", "w");
	for(j=0;j<=35000;j++)
		fprintf(fp,"%lu\t",a[j]);
	fclose(fp);


}
