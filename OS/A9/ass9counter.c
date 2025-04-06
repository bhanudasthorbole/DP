#include<stdio.h>
#include<stdlib.h>

int n = -1, p = -1;

int pfcounter;

int **frame;
int *pagerefstr;

void Display()
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(frame[i][0] != -1)
			printf("\t %d", frame[i][0]);
	}
}


int Index()
{
	int i, index;

	int small = frame[0][1];

	for(i = 0; i < n; i++)
	{
		if(frame[i][1] < small)
			small = frame[i][1];
	}

	for(i = 0; i < n; i++)
	{
		if(frame[i][1] == small)
		{
			index = i;
			break;
		}
	}

	return(index);
}

int Find(int x)
{
	int i, flag = 0;

	for(i = 0; i < n; i++)
	{
		if(frame[i][0] == x)
		{
			flag = 1;
			break;
		}
	}

	return(flag);
}



int main()
{
	do
	{
		printf("\n Enter the number of frames: ");
		scanf("%d",&n);
		if(n <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(n <= 0);

	do
	{
		printf("\n Enter the number of pages in page reference string: ");
		scanf("%d",&p);
		if(p <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(p <= 0);

	frame = (int **)malloc(n*sizeof(int *));

	int i, j;

	for(i = 0; i < n; i++)
	{
		frame[i] = (int *)malloc(2*sizeof(int));
	}
	pagerefstr = (int *)malloc(p*sizeof(int));
	
	printf("\n Enter page sequence:");

	for(i = 0; i < p; i++)
	{
		pagerefstr[i] = -1;
		do
		{
			printf("\n\t Page %d: ", i + 1);  // Changed from i to i + 1
			scanf("%d", &pagerefstr[i]);
			if(pagerefstr[i] < 0)
				printf("\nEnter a valid value!\n");
		}
		while(pagerefstr[i] < 0);
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 2; j++)
			frame[i][j] = -1;
	}

	int ref, counter = 0, top = 0, z, k;

	for(i = 0; i < p; i++)
	{
		counter++;
		ref = pagerefstr[i];
		printf("\n Page number->%d",ref);

		if(Find(ref) == 0)
		{
			if(top != n)
			{
				pfcounter++;

				printf("\t Page fault");

				frame[top][0]=ref;
				frame[top][1]=counter;

				Display();
				top += 1;
				continue;
			}

			if(top == n)
			{
				z = Index();
				pfcounter++;
				printf("\t Page fault");

				frame[z][0]=ref;
				frame[z][1]=counter;

				Display();
				continue;
			}
		}

		if(Find(ref) == 1)
		{
			printf("\t Match found!");

			for(k = 0; k < n; k++)
			{
				if(frame[k][0] == ref)
					break;
			}

			frame[k][1] = counter;
			continue;
		}
	}

	printf("\n\t Total page faults: %d",pfcounter);
	printf("\n");
}







