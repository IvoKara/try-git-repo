#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct decoration_t {char type; float size;};

struct decoration_t pick_best_ball(struct decoration_t balls[10]);

int main(int argc, char **argv)
{
	struct decoration_t toys[10];
	
	srand(time(0));
	
	char types_of_toys[4] = "CBO";
	
	for(int i =0; i < 10; i++)
	{
		toys[i].type = types_of_toys[rand() % 3];
		toys[i].size = (float)(rand() % 10);
		printf("Toy:#%d, Type: %c, Size: %.2f\n", i+1, toys[i].type, toys[i].size);
	}
	
	struct decoration_t best_ball = pick_best_ball(toys);
	printf(", Type: %c, Size: %.2f\n", best_ball.type, best_ball.size);
	
	return 0;
}

struct decoration_t pick_best_ball(struct decoration_t balls[10])
{
	int i = 0;
	for(; i < 10; i++)
	{
		if(balls[i].type == 'B' && balls[i].size > 5.0)
			break;
	}
	if(i == 10)
		i--;
	printf("The best ball: Toy:#%d", i + 1);
	return balls[i];
}
