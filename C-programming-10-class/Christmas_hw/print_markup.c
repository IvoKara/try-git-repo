#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tag_t {char name[15]; int is_self_closing; struct tag_t *child;};

void add_child(struct tag_t *parent, char name[15], int is_self_closing);
void print_markup(struct tag_t ptag);

int main(int argc, char **argv)
{
	struct tag_t child;
	struct tag_t parent = {"body", 0, &child};
	add_child(&parent, "br", 1);	
	print_markup(parent);
	printf("\n");
	add_child(&parent, "div", 0);	
	print_markup(parent);
	printf("\n");
	
	return 0;
}

void print_markup(struct tag_t ptag)
{
	if(ptag.is_self_closing)	
	{
		printf("<%s/>", ptag.name);
		return;
	}
	
	printf("<%s>", ptag.name);
	
	if(ptag.child != NULL)
	{
		print_markup(*(ptag.child));
	}
	printf("</%s>", ptag.name);
}

void add_child(struct tag_t *parent, char name[15], int is_self_closing)
{
	if(parent -> is_self_closing)
		return;
	strcpy(parent -> child -> name, name);
	parent -> child -> is_self_closing = is_self_closing;
	parent -> child -> child = NULL;
}
