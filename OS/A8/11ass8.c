#include<stdio.h>
#include<stdlib.h>

void main()
{

	int *refString, pagefaults = 0, i, pages = -1, frames = -1;
	
	do
	{
		printf("\nEnter number of pages for reference string: ");
		scanf("%d",&pages);
		if(pages <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(pages <= 0);
	
	refString = (int *)malloc(pages*sizeof(int));
	
	printf("\nEnter the reference string value:\n");
	for(i = 0; i < pages; i++)
	{	
		refString[i] = -1;
		do
		{
			printf("\n\tValue no. %d: ",i+1);
			scanf("%d", &refString[i]);
			if(refString[i] < 0)
				printf("\nEnter a valid value!\n");
		}
		while(refString[i] < 0);
	}
	
	do
	{
		printf("\nEnter total number of frames: ");
		scanf("%d", &frames);
		if(frames <= 0)
			printf("\nEnter a valid value!\n");
	}
	while(frames <= 0);

	int temp[frames];
	for(i = 0; i < frames; i++)
	{
		temp[i] = -1;
	}
	
	int j, s = 0;

	for(i = 0; i < pages; i++)
	{
		s = 0;
		for(j = 0; j < frames; j++)
		{
			if(refString[i] == temp[j])
			{
				s++;
				pagefaults--;
			}
		}
		pagefaults++;
		if((pagefaults < frames) && (s == 0))
		{
			temp[i] = refString[i];
		}
		else if(s == 0)
		{
			temp[(pagefaults-1)%frames] = refString[i];
		}
        printf("\n");
        printf("%d\t-\t", refString[i]);  // Print the current reference string value
        for(j = 0; j < frames; j++)
        {
            if(temp[j] == -1)
                printf(" \t");
            else
                printf("%d\t", temp[j]);
        }
        if(s == 0)  // If s is 0, it means a page fault occurred
            printf("*");  // Display asterisk for page fault
        printf("\n");
    }
	printf("\n\t---> Total number of page faults: %d",pagefaults);
	printf("\n\n");
}
