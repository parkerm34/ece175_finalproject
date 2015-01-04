/*	Author: Parker Mathewson							*
 *	Date: 4/29/12									*
 *	Comments: This program is to go into the array of structs and create a linked	*
 *			list for each person for their friends list. This will use	*
 *			the original array to gather information and a file to scan	*
 *			in who is friends with each person.				*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define NETWORK_SIZE 22
#define START_FRIENDLIST "****"
#define MAX_FRIENDS 21
#define MAX_CHAR 50

#define FOUND_PERSON 0
#define FIND_FRIEND 0

typedef struct friend_node friend_t;

typedef struct
{	char name[MAX_CHAR];
	int age;
	int id;
	float height;
	char fav_color[MAX_CHAR];
	int num_of_friends;

	friend_t *linkto_friendlist;	

} person_info_t;

struct friend_node
{
	person_info_t *linkto_person;
	struct friend_node *next;
};

int find_index(person_info_t person[], char friend[])
{
	int i=0;
	for(i=0; i<NETWORK_SIZE; i++)
	{
		if(strcmp(friend, person[i].name) == 0)
			return i;
	}
	return (NULL);
}

void print_function(friend_t *temp)
{
	while(temp != NULL)
	{
		printf("%s\n", temp->linkto_person->name);
		temp=temp->next;
	}
	printf("\n");
}

void make_friendlist(person_info_t person[])
{
	int k=0, index_in_array=0, j=0, i=0;
	friend_t *temp=NULL, *current_friend=NULL, *head[NETWORK_SIZE];
	FILE* friends_input;
	char friend[MAX_CHAR];

	friends_input = fopen("friends.dat", "r");
	fscanf(friends_input, "%s", friend);
	while(!feof(friends_input))
	{
		for(k=0; k<MAX_FRIENDS; k++)
		{
			if(strcmp(friend, START_FRIENDLIST)==0)
			{
				temp = (friend_t*)malloc(sizeof(friend_t));
				temp->next=NULL;
				fscanf(friends_input, "%s", friend);
				fscanf(friends_input, "%s", friend);
				if(friend == NULL || strcmp(friend, START_FRIENDLIST)==0);
				else
				{
					index_in_array = find_index(person, friend);
					if(friend == "Nelson")
					{
						temp->linkto_person = &person[index_in_array];
						person[j].linkto_friendlist = temp;
						head[j] = person[j].linkto_friendlist;
						current_friend = temp;
					}
					else if(index_in_array == (NULL) && index_in_array != 0);
					else
					{
						temp->linkto_person = &person[index_in_array];
						person[j].linkto_friendlist = temp;
						head[j] = person[j].linkto_friendlist;
						current_friend = temp;
					}
				}
				j++;
			}

			if(strcmp(friend, START_FRIENDLIST) != 0)
			{
				fscanf(friends_input, "%s", friend);
				if(friend == START_FRIENDLIST);
				else
				{
					if(friend == "Nelson")
					{
						temp->linkto_person = &person[index_in_array];
						person[j].linkto_friendlist = temp;
						head[j] = person[j].linkto_friendlist;
						current_friend = temp;
					}
					temp = (friend_t*)malloc(sizeof(friend_t));
					temp->next=NULL;
					index_in_array = find_index(person, friend);	

					if(index_in_array == NULL);
					else
					{
						temp->linkto_person = &person[index_in_array];
						current_friend->next = temp;
				//		temp=temp->next;
						current_friend = temp;
					}
				}
			}	
		}
	}
	fclose(friends_input);
	for(i=0; i<NETWORK_SIZE; i++)
	{
			printf("Friends list for %s:\n", person[i].name);
			print_function(head[i]);
	}
}

void scan_structure_funct(person_info_t person[ ])
{
	int i;
	FILE* people_input;

	people_input = fopen("people.dat", "r");
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
	make_friendlist(person);
}

int main(void)
{
	person_info_t person[NETWORK_SIZE];

	scan_structure_funct(person);
//	print_function(person[1].linkto_friendlist);
	return 0;
}
/*	for(i=0; i<NETWORK_SIZE; i++)
//	{
//		printf("%s\t\t%d\t\t%d\t\t%.2f\t\t%s\t\t%d\n", person[i].name, person[i].age, person[i].id, person[i].height, person[i].fav_color, 
person[i].num_of_friends);
	}
*/
