#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//why don't use strcmp?

int string_compare(char *str1, char *str2);

int main(int argc, char **argv)
{
	char str1[] = "abc";
	char str2[]= "abd";
	printf("%d, %d\n", string_compare(str1, str2), strcmp(str1, str2));
	return 0;
}

int string_compare(char *str1, char *str2)
{
	int size = strlen(str1);
	
	if(size < strlen(str2))
		size = strlen(str2);
		
	for(int i = 0; i < size; i++)
	{
		if(str1[i] > str2[i])
			return 1;
		if(str2[i] > str1[i])
			return -1;
	}
	
		return 0;
}
