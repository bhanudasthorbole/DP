// Contiguous File Allocation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dsize, used = 0;
int *bitVector = NULL;

typedef struct info
{
	char fname[20];
	int start, length;
	struct info *next;
}dir;

dir *head = NULL, *last = NULL;


int search(int length)							// searches for 'length' size in bit vector
{
	int i, j, flag = 1, blknum;
	
	for(i = 0; i < dsize; i++)
	{
		if(bitVector[i] == 1)
		{
			flag = 1;
			for(blknum = i, j = 0; j < length; j++)
			{
				if(bitVector[blknum++] == 1)
					continue;
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				return i;
		}
	}

	return -1;
}

void allocate()
{
	char fname[20];
	int length, blknum, i, flag = 0, cnt = 0, avail;
	dir *t, *s = head;
	
	for(i = 0; i < dsize; i++)
	{
		if(bitVector[i] == 0)
			cnt++;
	}
	avail = dsize - cnt;
	if(cnt > dsize)
	{
		printf("\nNo disk space available\n");
		return;
	}
		
	do
	{
		printf("\n\tEnter filename: ");
		scanf("%s", fname);
		flag = 1;
		if(head != NULL)
		{
			for(s = head; s != NULL; s = s->next)
			{
				if(strcmp(s->fname, fname) == 0)
				{
					printf("\nFile already exists.\n");
					flag = 0;
					break;
				}
			}
		}
	}
	while(flag == 0);

	do
	{
		printf("\n\tEnter length of file: ");
		scanf("%d", &length);
		if(length > dsize || avail < length)
		{
			printf("\nNo disk space available\n");
			return;
		}
		if(length <= 0)
			printf("\nInvalid length! Enter again!\n");
	}
	while(length <= 0);

	if(length <= dsize - used)
		blknum = search(length);
	else
		blknum == -1;
		
	if(blknum <= -1)
		printf("\nNo disk space available.\n");
	else
	{
		printf("\nBlock allocated.\n");
		used += length;
		t = (dir *)malloc(sizeof(dir));
		strcpy(t->fname, fname);
		t->start = blknum;
		t->length = length;
		t->next = NULL;

		if(head == NULL)
			head = last = t;
		else
		{
			last->next = t;
			last = last->next;
		}

		for(i = 1; i <= length; i++)
			bitVector[blknum++] = 0;
	}
}

void deallocate()
{
	if(head == NULL)
	{
		printf("\nNothing to delete");
		return;
	}
	
	dir *f,*s;
	char fname[20];
	int start, length, i, blknum, flag = 0;
	
	printf("\nEnter filename to delete: ");
	scanf("%s", fname);

	for(s = head; s != NULL; s = s->next)
	{
		if(strcmp(s->fname, fname) == 0)
		{
			flag = 1;
			start = s->start;
			length = s->length;
			for(blknum = start, i = 0; i < length; i++)
				bitVector[blknum++] = 1;
			printf("\nFile %s deleted successfully.\n", fname);
			
			if(s == head)
			{
				head = head->next;
				free(s);
				used = used-length;
				break;
			}
			for(f = head; f->next != s; f = f->next)
			{}
			f->next = s->next;
			free(s);
			used = used-length;
			break;
		}
	}
	if(flag == 0)
		printf("\nNo such file or directory.\n");
}
void display_entry()
{
	if(head == NULL)
	{
		printf("\nDirectory is empty.\n");
		return;
	}

	dir *t;
	printf("\nDirectory Contents:\n");
	printf("\nName\tStart\tSize\n------------------------");
	for(t = head; t != NULL; t = t->next)
	{
		printf("\n%s\t%d\t%d", t->fname, t->start, t->length);
	}
	printf("\n\nUsed blocks: %d", used);
	printf("\nFree blocks: %d\n", dsize-used);
}

void init_disk()
{
	int i;
	bitVector = (int *)malloc(dsize*sizeof(int));
	for(i = 0; i < dsize; i++)
		bitVector[i] = 1;
}

int main()
{
	int choice, i;
	do
	{
		printf("\n\tEnter the size of disk: ");
		scanf("%d", &dsize);
		if(dsize <= 0)
			printf("\nInvalid disk size.\n");
	}
	while(dsize <= 0);

	init_disk();

	while(1)
	{
		printf("\n1. Show Bit Vector\n2. Create new file\n3. Show directory\n4. Delete file \n5. Exit");
		printf("\n\n\tEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n");
				for(i = 0; i < dsize; i++)
					printf("%d\t", bitVector[i]);
				printf("\n");
				break;
				
			case 2:
				allocate();
				break;
				
			case 3:
				display_entry();
				break;
				
			case 4:
				deallocate();
				break;
				
			case 5:
				printf("\nExiting program...\n\n");
				exit(0);
				
			default:
				printf("\nEnter a valid choice!\n");
				break;
		}
	}
}
