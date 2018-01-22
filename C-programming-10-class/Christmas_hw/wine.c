#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *min(int *a, int *b);
void copy(char **src, int size, int *dest);

int main(int argc, char **argv)
{
	int wines[atoi(argv[1])];
	copy(argv, argc, wines);
	
	int money = 0;	
	int l = 0, r = atoi(argv[1]) - 1;
	int year = 1;
	while(l - r < 1)
	{	
		int *m = min(&wines[l], &wines[r]);
		money += *m * year;
		if(wines[l] == wines[r] && l < r - 1)
		{
			if(wines[l + 1] < wines[r - 1])
			{
				l++;
				year++;
				continue;
			}
		}
		
		if(m - wines == l)
			l++;
		else 
			r--;
		year++;
	}
	printf("%d\n", money);
	return 0;
}

void copy(char **src, int size, int *dest)
{
	int j = 0;
	for(int i = 2; i < size; i++)
	{
		dest[j] = atoi(src[i]);
		j++;
	}
}

int* min(int *a, int *b)
{
	if(*a >= *b)
		return b;
	return a;
}
