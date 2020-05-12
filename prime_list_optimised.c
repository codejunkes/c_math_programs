// Effecient way to find the list if prime numbers in sigle thread.
// Further improvement is to make it multi-threaded so that it will be yet more optimised.

#include<stdio.h>

void main()
{
	long signed int a[350000],h=5023307,i,j,b,size;
	size = 350000;
	int nline = 0;
	FILE *fp, *fp_csv;

	a[0]=2;
	a[1]=3;
	i=2;
	while(a[i-1]<=h)
	{
		a[i]=a[i-1]+2;

	rev:	for(j=0;j<=i/3;j++)
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
			a[i]=a[i]+2;
			goto rev;
		}
	}


// Saving the output to a file.
	printf("Printing the list of prime numbers to a file 'Prime_list.txt'\n");
	fp = fopen("Prime_list.txt", "w");
	i = 0;
	for(j=0;j<size;j++)
	{
		if(nline==1)
		{
			fprintf(fp,"%lu\n",a[j]);
			i = 0;
		}
		else
		{
			fprintf(fp,"%lu\t",a[j]);
			i++;
		}
		if(i>=5)
			nline = 1;
		else
			nline = 0;
	}
	fclose(fp);

	fp_csv = fopen("Prime_list.csv", "w");
	printf("Printing CSV file for Prime list.\n");
	fprintf(fp_csv, "Serial number, Prime \n");
	for(j=0;j<size;j++)
	{
		fprintf(fp_csv, "%u,%u\n", j+1, a[j]);
	}
	fclose(fp_csv);
}

