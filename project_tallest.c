/*	Author: Parker Mathewson					*
 *	Date: 4/30/12							*
 *	Comments: This is a program that is a short version of sorting.	*
 *			All it will do is call find the tallest and the	*
 *			shortest in the network and return by user	*
 *			interaction.					*/

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
{	char name[50];
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

void print_tallest_or_shortest(person_info_t person[], int index, char sorting_hilo)
{
	if(sorting_hilo == 'T' || sorting_hilo == 't')
		printf("The tallest person in the social network is %s at %.2f\n", person[index].name, person[index].height);
	else
		printf("The shortest person in the social network is %s at %.2f\n", person[index].name, person[index].height);		
}

void find_tallest_or_shortest(person_info_t people[], char sorting_hilo)
{
	int index=0, i=0, min_max=people[0].height;

	if(sorting_hilo == 'T' || sorting_hilo == 't')
	{
		for(i=0; i<NETWORK_SIZE; i++)
		{
			if(people[i].height > min_max)
				index = i;
		}
	}
	else
	{
		for(i=0; i<NETWORK_SIZE; i++)
		{
			if(people[i].height < min_max )
				index = i;
		}
	}
	print_tallest_or_shortest(people, index, sorting_hilo);
}

int main(void)
{
	int i=0;
	person_info_t person[NETWORK_SIZE];
	FILE *friends_input, *people_input;
	
	people_input = fopen("people.dat", "r");
	friends_input = fopen("friends.dat", "r");

	if(people_input == NULL) printf("There was an error reading the file.");
	else
	{
		while(!feof(people_input))
		{
			fscanf(people_input,"%s%d%d%f%s%d", &person[i].name, &person[i].age, &person[i].id, &person[i].height, &person[i].fav_color,
				   &person[i].num_of_friends);
			i++;
		}
	}	
	
	find_tallest_or_shortest(person, 'T');
	find_tallest_or_shortest(person, 'a');
	return 0;
}
