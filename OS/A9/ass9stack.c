#include<stdio.h>
#include<stdlib.h>

int n = -1, p = -1;

int *frame, *pagerefstr;
int pfcounter = 0;

void Display()
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(frame[i] != -1)
			printf("\t %d",frame[i]);
	}
}

int Find(int x)
{
	int i, flag=0;

	for(i = 0; i < n; i++)
	{
		if(frame[i] == x)
		{
			flag = 1;
			break;
		}
	}
	return(flag);
}



int main()
{
	int i, j;

	do
	{
		printf("\n Enter the number of frames: ");
		scanf("%d",&n);
		if(n <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(n <= 0);

	frame=(int *)malloc(n*sizeof(int));
	
	do
	{
		printf("\n Enter the number of pages in page reference string: ");
		scanf("%d",&p);
		if(p <= 0)
			printf("\nEnter a valid number!\n");
	}
	while(p <= 0);

	pagerefstr=(int *)malloc(p*sizeof(int));

	printf("\n Enter page sequence:\n");

	for(i = 0; i < p; i++)
	{
		pagerefstr[i] = -1;
		do
		{
			printf("\n\t Page %d: ", i + 1);  // Changed from i to i + 1
			scanf("%d",&pagerefstr[i]);
			if(pagerefstr[i] < 0)
				printf("\nEnter a valid number!\n");
		}
		while(pagerefstr[i] < 0);
	}

	int ref, top = 0;

	for(i = 0; i < n; i++)
	{
		frame[i] = -1;
	}

	int x, X;


	for(i = 0; i < p; i++)
	{
		ref = pagerefstr[i];
		printf("\n Page no.: %d",ref);

		if(Find(ref) == 0)
		{
			if(top != n)
			{
				frame[top++] = ref;
				pfcounter++;

				printf("\t Page fault");
				Display();
				continue;
			}
			if(top == n)
			{
				for(x = 0; x < n-1; x++)
					frame[x] = frame[x+1];

				frame[top-1] = ref;

				pfcounter++;

				printf("\t Page fault");
				Display();
				continue;
			}
		}

		if(Find(ref) == 1)
		{
			printf("\t Match found!");

			for(x = 0; x < n; x++)
			{
				if(frame[x] == ref)
					break;
			}

			for(X = x; X < top-1; X++)
			{
				frame[X] = frame[X+1];
			}

			frame[top-1]=ref;
			continue;
		}
	}

	printf("\n\n\t Total Number Of Page Faults : %d",pfcounter);
	printf("\n");
}