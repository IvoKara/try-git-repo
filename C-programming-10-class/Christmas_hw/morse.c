#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encode(char alph);

int main(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
		for(int j = 0; j < strlen(argv[i]); j++)
			encode(argv[i][j]);
			
	return 0;
}

void encode(char alph)
{
	char dots[6];
	char dashes[6];
	int dash_len = abs(5-atoi(&alph));
	int dot_len = 5 - dash_len;
	switch(alph)
	{
		case 'A': printf(".- "); break;
		case 'B': printf("-... "); break;
		case 'C': printf("-.-. "); break;
		case 'D': printf("-.. "); break;
		case 'E': printf(". "); break;
		case 'F': printf("..-. "); break;
		case 'G': printf("--. "); break;
		case 'H': printf(".... "); break;
		case 'I': printf(".. "); break;
		case 'J': printf(".--- "); break;
		case 'K': printf("-.- "); break;
		case 'L': printf(".-.. "); break;
		case 'M': printf("-- "); break;
		case 'N': printf("-. "); break;
		case 'O': printf("--- "); break;
		case 'P': printf(".--. "); break;
		case 'Q': printf("--.- "); break;
		case 'R': printf(".-. "); break;
		case 'S': printf("... "); break;
		case 'T': printf("- "); break;
		case 'U': printf("..- "); break;
		case 'V': printf("...- "); break;
		case 'W': printf(".-- "); break;
		case 'X': printf("-..- "); break;
		case 'Y': printf("-.-- "); break;
		case 'Z': printf("--.. "); break;
		default:
		
			memset(dots, '.', dot_len);
			dots[dot_len] = '\0';
			memset(dashes, '-', dash_len);
			dashes[dash_len] = '\0';
			if(atoi(&alph) < 5)
				printf("%s%s ", dots, dashes);			
			else
				printf("%s%s ", dashes, dots);
			break;
	}
}
