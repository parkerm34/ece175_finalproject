/*	Author: Parker Mathewson						*
 *	Date: 4/29/12								*
 *	Comments: This is a function to take a query and print out the info	*
 *			of the person asked upon. This will print out all info.	*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define SWAP 1   
#define NO_SWAP 0
#define NETWORK_SIZE 22  
#define MAX_CHAR 50
#define FOUND_PERSON 0
#define FIND_FRIEND 0
#define MAX_FRIENDS 21
#define START_FRIENDLIST "****"

typedef struct friend_node friend_t;

typedef struct									//defines the structure for the entire network.
{	char name[MAX_CHAR];
	int age;
	int id;
	float height;
	char fav_color[20];
	int num_of_friends;
	
	friend_t *linkto_friendlist;
} person_info_t;

struct friend_node
{
	person_info_t *linkto_person;
	struct friend_node *next;
};

void scan_function(person_info_t person[])
{
        FILE* inp;
        int i=0;

        inp=fopen("people.dat", "r");
	if(inp == NULL) printf("There was an error reading the file.");
	else
	{
		while(!feof(inp))
		{
			fscanf(inp,"%s%d%d%f%s%d", &person[i].name, &person[i].age, &person[i].id, &person[i].height, &person[i].fav_color,
				   &person[i].num_of_friends);
			i++;
		}
	}	        
	fclose(inp);
}

int find_index_person_query(person_info_t person[], char query[])
{
        int i=0, j=0;
        for(i=0; i<NETWORK_SIZE; i++)
        {
		if(query[j] == person[i].name[j])
		{
			j++;
			if(query[j] == person[i].name[j])
			{
				j++;
				if(query[j] == person[i].name[j])
		                        return i;
				else;
			}
			else;
		}
        }
	return -1;
}

char person_query_and_printing(person_info_t person[])
{
	char query[MAX_CHAR], quitting;
	int index=0, i=0;

	printf("You have chosen to get information on the person of your choice.\n");
	printf("If you would like to continue, please press Y or y.\n");
	printf("If you would like to quit to the main menu press Q or q, or to go back to your last screen press C or c: ");
	fflush(stdin);
	scanf("%c", &quitting);
	fflush(stdin);
	if(quitting == 'Q' || quitting == 'q' || quitting == 'C' || quitting == 'c')
		return quitting;
	else
	{
		printf("Please type in the name of the person you would like information on: ");
		fgets(query, MAX_CHAR, stdin);
		fflush(stdin);
		if(query[0] > 96 && query[0] < 123)
			query[0] = query[0]-32;
		for(i=1; i<MAX_CHAR; i++)
		{
			if(query[i] > 64 && query[i] < 91)
				query[i]=query[i]+32;
		}
		for(i=1; i<MAX_CHAR; i++)
		{
			if(query[i] < 65 && query[i] > 90 && query[i] < 97 && query[i] > 122)
			{
				printf("Your query contains irregular characters.\n");
				printf("If you would like to cancel this function, press C or c.\n");
				printf("If you would like to quit back to the main menu press Q or q\n");
				printf("If you would like to attempt again press any other character:");
				scanf("%c", &quitting);
				fflush(stdin);
				if(quitting == 'Q' || quitting == 'q' || quitting == 'C' || quitting == 'c')
					return quitting;
				else
					return 'a';
			}
		}
		printf("You are looking up %s...\n", query);
		index = find_index_person_query(person, query);
		if(index == -1)
		{
			printf("Error. Not found\n");
			printf("If you would like to cancel this function, press C or c.\n");
			printf("If you would like to quit back to the main menu press Q or q\n");
			printf("If you would like to attempt again press any other character:");
			scanf("%c", &quitting);
			fflush(stdin);
			if(quitting == 'Q' || quitting == 'q' || quitting == 'C' || quitting == 'c')
				return quitting;
			else
				return 'a';
		}
		printf("Name \t ID \t Height \t Age \t Favorite Color \t Number of Friends\n");
		printf("%s \t %d \t %.2f \t\t %d \t %s \t\t\t %d\n", person[index].name, person[index].id, person[index].height, person[index].age, 
person[index].fav_color, person[index].num_of_friends);
	}
	printf("If you would like to cancel this function, press C or c.\n");
	printf("If you would like to quit back to the main menu press Q or q\n");
	printf("If you would like to attempt again press any other character:");
	scanf("%c", &quitting);
	fflush(stdin);
	if(quitting == 'Q' || quitting == 'q' || quitting == 'C' || quitting == 'c')
		return quitting;
	else
		return 'a';
}

int main(void)
{
	char quitting;
	person_info_t  person[NETWORK_SIZE];
	scan_function(person);
	quitting = person_query_and_printing(person);
	if(quitting == 'a')
		quitting = person_query_and_printing(person);

	return 0;
}
