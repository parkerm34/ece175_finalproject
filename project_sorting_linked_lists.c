/*      Author: Parker Mathewson                                        *
 *      Comments: In this file I am going to attempt to complete all    *
 *                      the selection sorts for name, height, and       *
 *                      number of friends. I will put in a choice of    *
 *                      sorting from A-Z or from Z-A type.              */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP 1
#define NO_SWAP 0
#define STRUCT_LENGTH 22

typedef struct node_s
{
	char name;
	int number_of_friends;
	float height;
//	struct node_s* next;
}node_t;

void scan_function(FILE *inp, node_t pt[])
{
	fscanf(inp, "%c ", &pt->name);
	fscanf(inp, "%d ", &pt->number_of_friends);
	fscanf(inp, "%f ", &pt->height);
}

node_t* sort_by_friends(node_t* person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0;
	node_t* temp;
	printf("%c", sorting_hilo);
	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<STRUCT_LENGTH-1; i++)
		{
			if(sorting_hilo == 'M' || sorting_hilo == 'm')
			{
				if((person_array[i]->number_of_friends) < person_array[i+1]->number_of_friends)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			else
			{
				if((person_array[i]->number_of_friends) > person_array[i+1]->number_of_friends)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
		}
	}
	return person_array[0];
}

node_t* sort_by_height(node_t* person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0;
	node_t* temp;
	printf("%c", sorting_hilo);
	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<STRUCT_LENGTH-1; i++)
		{
			if(sorting_hilo == 'T' || sorting_hilo == 't')
			{
				if((person_array[i]->height) < person_array[i+1]->height)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			else
			{
				if((person_array[i]->height) > person_array[i+1]->height)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
		}
	}
	return person_array[0];
}
node_t* sort_by_name(node_t* person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0;
	node_t* temp;
	printf("%c", sorting_hilo);
	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<STRUCT_LENGTH-1; i++)
		{
			if(sorting_hilo == 'A' || sorting_hilo == 'a')
			{
				if((person_array[i]->name) < person_array[i+1]->name)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			else
			{
				if((person_array[i]->name) > person_array[i+1]->name)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
		}
	}
	return person_array[0];
}

void print_sorted_function(node_t* person_array[])
{
	int printing_counter=0;
	for(printing_counter=0; printing_counter<STRUCT_LENGTH; printing_counter++)
	{
		printf("%c %.2f %d\n", person_array[printing_counter]->name, person_array[printing_counter]->height, person_array[printing_counter]->number_of_friends);
	};
}

node_t* create_sorting_array(node_t random[])
{
	node_t *person_array[22];
	char sorting_hilo, what_sort;
	int i=0;

	for(i=0; i<STRUCT_LENGTH; i++)
	{
		person_array[i] = &random[i];
//		temp = temp->next;
	}
		printf("What would you like to sort by?\n");
		printf("Press F or f for number of friends,\n");
		printf("Press H or h for by height,\n");
		printf("Press N or n for by name,\n");
		printf("Or press Q or q to quit.\n");
		scanf("%c", &what_sort);
		fflush(stdin);
		switch(what_sort)
		{
			case 'F':
			case 'f':
			{
				printf("Type M or m for sorting by most number of friends, or any other character to sort by least number: ");
				scanf("c", &sorting_hilo);
				fflush(stdin);
				person_array[0] = sort_by_friends(person_array, sorting_hilo);
				print_sorted_function(person_array);
				break;
			}
			case 'H':
			case 'h':
			{
				printf("Type T or t for sorting by tallest first, or any other character to sort by shortest first: ");
				scanf("%c", &sorting_hilo);
				fflush(stdin);
				person_array[0] = sort_by_height(person_array, sorting_hilo);
				print_sorted_function(person_array);
				break;
			}
			case 'N':
			case 'n':
			{
				printf("Type A or a to sort alphabetically, or any other character for reverse alphabetically: ");
				scanf("%c", &sorting_hilo);
				fflush(stdin);
				person_array[0] = sort_by_name(person_array, sorting_hilo);
				print_sorted_function(person_array);
				break;
			}
			case 'Q':
			case 'q':
			{
				return 0;
				break;
			}
			default:
			{
				printf("done.");
				break;
			}
		}
	return person_array[0];
}	

int main(void)
{
	node_t person_array[22];
	char sorting_hilo;
	char what_sort;
	FILE* inp;
	int i=0;

	inp=fopen("person_info.dat", "r");
	if(inp == NULL) printf("there was an error reading the file.");
	else
	{

		while(!feof(inp))
		{
			for(i=0; i<22; i++)
			{
			person_array[i]=scan_function(inp, person_array[i]);
			}
//			temp = (node_t*)malloc(sizeof(node_t));
//			scan_function(inp, temp);
//			temp->next = NULL;
//
//			if(current == NULL) head=temp;
//			else current->next=temp;
//			current=temp;
		}

		person_array[0] = create_sorting_array(person_array);
	}
	return 0;
}

