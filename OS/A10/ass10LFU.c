#include<stdio.h>
#include<stdlib.h>


int **frame;

int *pagerefstr;

int p = -1, n = -1;

int count = 0;
int timer = 0;

void Display()
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(frame[i][0] != -1)
		printf("\t %d", frame[i][0]);
	}
}

int Find(int x)
{
	int i, flag=0;

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

int GetIndex()
{
	int ar[n], arr[n];
	int count=0, index;

	int small = frame[0][2];
	int S, i;

	for(i = 0; i < n; i++)
	{
		if(frame[i][2] < small)
			small = frame[i][2];
	}

	for(i = 0; i < n; i++)
        {
			if(frame[i][2] == small)
				ar[count++] = frame[i][1];
        }

	S = ar[0];

	for(i = 0; i < count; i++)
        {
			if(ar[i] < S)
				S = ar[i];
        }

	for(i = 0; i < n; i++)
	{
		if(frame[i][1] == S)
		{
			index = i;
			break;
		}
	}
	return(index);
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
		printf("\n Enter the number of pages: ");
		scanf("%d",&p);
		if(p <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(p <= 0);

	frame=(int **)malloc(n*sizeof(int *));

	int i, j;

	for(i = 0; i < n; i++)
	{
		frame[i]=(int *)malloc(3*sizeof(int));
	}

	pagerefstr = (int *)malloc(p*sizeof(int));

	printf("\n Enter the page reference string: ");

	for(i = 0; i < p; i++)
	{
		pagerefstr[i] = -1;
		do
		{
			printf("\n\t Page no %d: ",i + 1);
			scanf("%d",&pagerefstr[i]);
			if(pagerefstr[i] < 0)
				printf("\nEnter a valid value!\n");
		}
		while(pagerefstr[i] < 0);
	}

	int ref, top = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 3; j++)
			frame[i][j] = -1;
	}

	int pfcounter = 0, f, index;

	for(i = 0; i < p; i++)
	{
		ref = pagerefstr[i];
		printf("\n Page no.: %d",ref);
		timer++;

		if(Find(ref) == 0)
		{
			pfcounter++;
			printf("\t Page fault");

			if(top!=n)
			{
				frame[top][0]=ref;
				frame[top][1]=timer;
				frame[top][2]=1;
				top++;
				Display();

				continue;
			}

			if(top==n)
			{
				index=GetIndex();
				frame[index][0]=ref;
				frame[index][1]=timer;
				frame[index][2]=1;
				Display();

				continue;
			}
		}

		if(Find(ref)==1)
		{
			printf("\t Match found!");
			
			for(j = 0; j < n; j++)
			{
				if(frame[j][0] == ref)
				{
					f = j;
					break;
				}
			}
			
			frame[f][1]=timer;
			frame[f][2]=frame[f][2]+1;
		}
	}

	printf("\n\n\t The total page faults are: %d",pfcounter);
	printf("\n");
}








