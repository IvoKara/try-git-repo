#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

struct tree_t {float height_m, value_lv;};

struct tree_t best_price_for_height(struct tree_t trees[10]);

int main(int argc, char **argv)
{
	srand(time(0));
	
	struct tree_t trees[10];
	
	for(int i = 0; i < 10; i++)
	{
		//just radom numbers
		trees[i].height_m = (rand() % 150 / 47.0) + 0.5;
		trees[i].value_lv = rand() % 470 / 47.0;
	}
	
	struct tree_t best_tree = best_price_for_height(trees);
	
	printf(" %.2f %.2f", best_tree.height_m, best_tree.value_lv);
	
	return 0;
}

struct tree_t best_price_for_height(struct tree_t trees[10])
{
	float min;
	int k = 0,i = 0;
	struct tree_t best_tree;
	for(; i < 10; i++)
	{
		float price = trees[i].value_lv/(trees[i].height_m*pow(10, 3));
		
		printf("#%d tree height: %.2f, it costs: %.2f\n",i+1 ,trees[i].height_m, trees[i].value_lv);
		printf("prices: %f\n\n", price);
		
		if(price < min || i == 0)
		{
			best_tree = trees[i];
			min = price;
			k = i + 1;
		}
	}
	
	printf("Best tree #%d -> ", k);
	
	return best_tree;
}
