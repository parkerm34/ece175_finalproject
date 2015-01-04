/*	Author: Parker Mathewson						*
 *	Date: 4/30/12								*
 *	Comments: This is a program that will be used to change attributes	*
 *			to user accounts along the lines of height, age, name	*
 *			and favorite color. They will not be allowed to change	*
 *			their ID.						*/

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

void change_attributes(person_info_t person[], int person_id, char change_attrib)
{
	int new_age=0, i=0;
	char new_name[MAX_CHAR], new_fav_color[MAX_CHAR];
	float new_height=0;
	
	if(change_attrib == 'h')
	{
		printf("What would you like to change the height to?: ");
		scanf("%f", &new_height);
		fflush(stdin);
		person[person_id].height = new_height;
	}		
	if(change_attrib == 'a')
	{
		printf("What would you like to change the new age to?: ");
		scanf("%d", &new_age);
		fflush(stdin);
		person[person_id].age = new_age;
	}
	if(change_attrib == 'f')
	{
		printf("What would you like to change the new favorite color to?: ");
		scanf("%s", new_fav_color);
		fflush(stdin);
		for(i=0; i<MAX_CHAR; i++)
			person[person_id].fav_color[i] = new_fav_color[i];
	}
	if(change_attrib == 'n')
	{
		printf("What would you like to change the new name to?: ");
		scanf("%s", new_name);
		fflush(stdin);
		for(i=0; i<MAX_CHAR; i++)
			person[person_id].name[i] = new_name[i];
	}
}

char display_available_changes(person_info_t person[], char change_attrib)
{
	int i=0, choice=0;
	char quitting;

	printf("You chose change attributes. if you would like to cancel or quit, press Q or q. Press any other key to continue.\n");
	scanf("%c", &quitting);
	fflush(stdin);
	if(quitting == 'Q' || quitting == 'q')
		return quitting;
	else
	{
		for(i=0; i<NETWORK_SIZE; i++)
			printf("%d. \t %.2f \t %d \t %s    \t %s\n", person[i].id, person[i].height, person[i].age, person[i].fav_color, person[i].name);
		
		printf("These are the available people to have attributes changed.\n");
		printf("Please choose which person you would like to change by selecting their ID: ");
		scanf("%d", &choice);
		fflush(stdin);
		change_attributes(person, choice, change_attrib);
	}
	printf("Here are the new attributes:\n");
	for(i=0; i<NETWORK_SIZE; i++)
		printf("%d. \t %.2f \t %d \t %s     \t %s\n", person[i].id, person[i].height, person[i].age, person[i].fav_color, person[i].name);

	printf("Would you like to make another change? y for yes, n for no: ");
	scanf("%c", &quitting);
	fflush(stdin);
	return quitting;
}		


int main(void)
{
	int i=0;
	person_info_t person[NETWORK_SIZE];
	char quitting;

	friend_t *temp=NULL, *current_friend=NULL;
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
	quitting = display_available_changes(person, 'a');	
	if(quitting == 'y')
		quitting = display_available_changes(person, 'a');	
	
	return 0;
}
