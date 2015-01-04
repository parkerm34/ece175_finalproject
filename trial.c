#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 50
#define NETWORK_SIZE 22
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

void print_function(friend_t *person, friend_t *temp)
{
	printf("%s", (person->linkto_person->name));
	printf("%s", temp->linkto_person->name);
//	person = person->next;
//	print_function(person->next);
}

int find_index(person_info_t person[], char friend[])
{
	int i=0;
	for(i=0; i<NETWORK_SIZE; i++)  
	{
		if(strcmp(friend, person[i].name) == 0)
			return person[i].id;
	}                       
	return -1;
}


int main(void)
{
	int k=0, index_in_array=0, j=0, i=0, poop=0;
	friend_t *temp=NULL, *current_friend=NULL, *head=NULL;
	FILE* friends_input, *people_input;
	char friend[MAX_CHAR];
	person_info_t  person[NETWORK_SIZE];

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
	
	friends_input = fopen("friends.dat", "r");
	fscanf(friends_input, "%s", friend);
	while(!feof(friends_input))
	{
		for(k=0; k<MAX_FRIENDS; k++)  
		{
			temp = (friend_t*)malloc(sizeof(friend_t));
			temp->next=NULL;
			if(strcmp(friend, START_FRIENDLIST)==0)
			{
				fscanf(friends_input, "%s", friend);
				if(friend == NULL || strcmp(friend, START_FRIENDLIST)==0);
				else
				{
					index_in_array = find_index(person, friend);
					person[j].linkto_friendlist = temp;
					head = person[j].linkto_friendlist;
					temp->linkto_person = &person[index_in_array];
					current_friend = temp;
				}
				j++;   
			}
			else if(strcmp(friend, START_FRIENDLIST) != 0)
			{
				fscanf(friends_input, "%s", friend);
				index_in_array = find_index(person, friend);
				if(index_in_array == -1);
				else
				{
				temp->linkto_person = &person[index_in_array];
				current_friend = temp;
				current_friend->next = temp;
				}
			}
		}
	}
	fclose(friends_input);
	temp = person->linkto_friendlist;
//	for(poop=0; poop<22; poop++);
	print_function(head, temp);
}
