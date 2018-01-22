#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str);
void copy_array(float *source, float *dest, int count)
{
	strncpy(dest, source, count);
}

int main(int argc, char **argv)
{
	char str[10] = "";
	reverse(str);
	printf("%s\n", str);
	return 0;
}

void print_bytes(void *ptr, int count)
{
	
}

int word_count(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{}	
}

void reverse(char *str)
{
	for(int i = 0; i < strlen(str)/2; i++)
	{
		char swap = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = swap;
	}
}
