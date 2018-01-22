#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct barbaron_t {char type, size; float value;};
struct barbaron_shop_t {struct barbaron_t barb_in_shop[10]; int current;};

void add_barbaron(struct barbaron_shop_t *barbs, struct barbaron_t new);
struct barbaron_t buy_barbaron(struct barbaron_shop_t *barbs, char type, char size, float *money);

int main(int argc, char **argv)
{
	struct barbaron_shop_t b_test = {{{'A','S', 12.45}, {'P', 'M', 4.3}, {'B', 'L', 3.4}}, 3};
	struct barbaron_t to_add = {'C', 'L', 10.5};
	
	add_barbaron(&b_test, to_add);
	
	for(int i = 0; i < b_test.current; i++)
		printf("type:%c, size:%c, value:%.2f\n", b_test.barb_in_shop[i].type, b_test.barb_in_shop[i].size, b_test.barb_in_shop[i].value);
		
	float money = 20.00;
	struct barbaron_t needed_barb = buy_barbaron(&b_test, 'C', 'L', &money);
	
	printf("money after shop:%.2f of: %c %c %.2f\n", money, needed_barb.type, needed_barb.size, needed_barb.value);
	
	return 0;
}

struct barbaron_t buy_barbaron(struct barbaron_shop_t *barbs, char type, char size, float *money)
{
	int i = 0;
	for(; i < barbs -> current; i++)
		if(barbs -> barb_in_shop[i].type == type && barbs -> barb_in_shop[i].size == size && barbs -> barb_in_shop[i].value <= *money)
		{
			*money-= barbs -> barb_in_shop[i].value;
			break;
		}
	return barbs -> barb_in_shop[i];
}

void add_barbaron(struct barbaron_shop_t *barbs, struct barbaron_t new)
{
	if(barbs -> current == 10)
	{
		printf("Not enough space\n");
		return;
	}
	
	barbs -> barb_in_shop[barbs -> current] = new;
	barbs -> current++;
}
