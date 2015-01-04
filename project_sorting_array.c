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
#define NETWORK_SIZE 22
#define MAX_CHAR 50

typedef struct person_info_s
{
	char name[MAX_CHAR];
	int age;
	int id;
	float height;
	char fav_color[MAX_CHAR];
	int num_of_friends;

//	friend_t *linkto_friendlist;
}person_info_t;

void scan_function(person_info_t person[])
{
	FILE* inp;
	int i=0;

	inp=fopen("person_info.dat", "r");
	if(inp == NULL) printf("there was an error reading the file.");
	else
	{

		while(!feof(inp))
		{
			fscanf(inp, "%s", &person[i].name);
			fscanf(inp, "%d ", &person[i].num_of_friends);
			fscanf(inp, "%f ", &person[i].height);
			i++;
		}
	fclose(inp);
	}
}

/***************This function sorts the users by their number of friends**********************/
person_info_t sort_by_number_of_friends(person_info_t person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0;
	person_info_t temp;
	printf("\nYou chose to sort by the number of friends.");
	if(sorting_hilo == 'M' || sorting_hilo == 'm')
		printf(" Here are the people sorted by the most number of friends:\n\n");
	else
		printf(" Here are the people sorted by the least number of friends:\n\n");
	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<NETWORK_SIZE-1; i++)
		{
			if(sorting_hilo == 'M' || sorting_hilo == 'm')
			{
				if(person_array[i].num_of_friends < person_array[i+1].num_of_friends)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			else
			{
				if(person_array[i].num_of_friends > person_array[i+1].num_of_friends)
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

/******************This function sorts the users by their heights.*******************/
person_info_t sort_by_height(person_info_t person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0;
	person_info_t temp;
	printf("\nYou chose to sort by height.");
	if(sorting_hilo == 'T' || sorting_hilo == 't')
		printf(" Here are the people sorted by who is tallest:\n\n");
	else
		printf(" Here are the people sorted by who is shortest:\n\n");
	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<NETWORK_SIZE-1; i++)
		{
			if(sorting_hilo == 'T' || sorting_hilo == 't')
			{
				if((person_array[i].height) < person_array[i+1].height)
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			else
			{
				if((person_array[i].height) > person_array[i+1].height)
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
/********************This function is to sort by the first name of the people within the network. If the first letter is the same it compares the second letters.*****************/
person_info_t sort_by_name(person_info_t person_array[], char sorting_hilo)
{
	int flag=SWAP, i=0, j=0, k=0, counter=0;
	person_info_t temp;
	char name_1[MAX_CHAR], name_2[MAX_CHAR];

	printf("\nYou chose to sort by name.");
							/*Part 2 of sentence depends on u_sort_hi_o_lo*/
	if(sorting_hilo == 'A' || sorting_hilo == 'a')
		printf(" Here are the names alphabetically:\n\n");
	else
		printf(" Here are the names reverse alphabetically:\n\n");

	while(flag == SWAP)
	{
		flag = NO_SWAP;
		for(i=0; i<NETWORK_SIZE-1; i++)
		{
			for(j=0; j<MAX_CHAR; j++)
			{
				name_1[j] = person_array[i].name[j];
				name_2[j] = person_array[i+1].name[j];
			}

			if(name_1[counter] < 123 && name_1[counter] > 96)
				name_1[counter] = name_1[counter] - 32;
			if(name_2[counter] < 123 && name_2[counter] > 96)
				name_2[counter] = name_2[counter] - 32;
									/*This block is to compare letter in ascii values*/
			for(j=0; j<MAX_CHAR; j++)
			{
				if(name_1[counter] == name_2[counter])
					k=j;
				else
				{
					if(counter == 0)
						k=0;
					j=MAX_CHAR;
				}
			}
/*Sort alphabetically*/
			if(sorting_hilo == 'A' || sorting_hilo == 'a')
			{
				if(name_1[k] > name_2[k])
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
/*Sort reverse Alphabetically*/
			else
			{
				if(name_1[k] < name_2[k])
				{
					temp = person_array[i];
					person_array[i] = person_array[i+1];
					person_array[i+1] = temp;
					flag=SWAP;
				}
			}
			k=0;
		}
	}
	return person_array[0];
}

/******************This function is pretty self explanatory... Prints the sorted arrays*****************/
void print_sorted_function(person_info_t person_array[])
{
	int printing_counter=0;
	for(printing_counter=0; printing_counter<NETWORK_SIZE; printing_counter++)
	{
		printf("%s %.2f %d\n", person_array[printing_counter].name, person_array[printing_counter].height, person_array[printing_counter].num_of_friends);
	};
}

/******************This function is the main body of the whole sorting portion of the project. ******************/
/******************This function only calls for the array of peoples information and asks the user from there.**************/
char create_sorting_array(person_info_t random[])
{
	person_info_t person_array[22];
	char sorting_hilo, what_sort, quitting;
	int i=0, k=0;

	for(i=0; i<NETWORK_SIZE; i++)
	{
		person_array[i] = random[i];
	}
	while(quitting != 'Q' && quitting != 'q' && quitting != 'C' && quitting != 'c')
	{
		if(k==1)
		{
			printf("would you like to sort again? Y or y for yes or N or n for no:");
			scanf("%c", &quitting);
			fflush(stdin);
			if(quitting == 'N' || quitting == 'n')
			{
				printf("Would you like to go back to what you were doing last? If so press C or c.\n");
				printf("If you would like to return to the main menu press Q or q:");
				scanf("c", &quitting);
				fflush(stdin);
				return quitting;
			}
			else
				k=0;
		}
		else
		{
			k=1;
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
					scanf("%c", &sorting_hilo);
					fflush(stdin);
					person_array[0] = sort_by_number_of_friends(person_array, sorting_hilo);
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
					printf("Would you like to go back to what you were doing last? If so press C or c.\n");
					printf("If you would like to return to the main menu press Q or q:");
					fflush(stdin);
					scanf("c", &quitting);
					return quitting;
					break;
				}
				default:
				{
					printf("done.");
					break;
				}
			}
		}
	}
}	

int main(void)
{
	person_info_t person_array[22];
	char quitting;

	scan_function(person_array);

	quitting = create_sorting_array(person_array);

	return 0;
}

