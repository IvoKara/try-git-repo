#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int to_integer(char *str);

int main(int argc, char **argv)
{
	int sum = 0;
	for(int i = 1; i < argc; i++)
		sum += to_integer(argv[i]);
	printf("%d\n", sum);
	return 0;
}

int to_integer(char *str)
{
	int result = 0;
	for(int i = 0; i < strlen(str); i++)
		result = result*10 + str[i] - '0'; 
	return result;
}
