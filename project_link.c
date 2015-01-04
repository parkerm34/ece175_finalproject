/*	Author: Parker Mathewson
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	person_info_t *person;
	friend_node_t *next;
} friend_node_t;

typedef struct person_info_s
{
	char name[50];
	int age;
	int id;
	float height;
	char fav_color[50];
	int num_of_friends;

	friend_t *next;
} person_info_t;

person_info_t* find_person(char query[])
{
	

friend_t* set_friends(person_info_t* person, FILE* inp, person_info_t* person_to_link)
{
	int index=0;
	friend_t *current, *head, *temp;
	head = person->next;
	current = head;
	temp = NULL;

	char temp_2[20];
	fscanf(inp, "%s", temp_2);

	while(temp_2 != "****")
	{
		temp = (friend_node_t *)malloc(sizeof (friend_node_t));

		index = find_person(temp_2);
		current->person = person_to_link[index];
		current->next = temp;

		temp->next=NULL;

		if (current==NULL) head=temp;
		else current->next=temp;
		current=temp;
	}
	return head;
}		

void scan_function(person_info_t person[], int i, inp)
{
	person->next = set_friends(person[i], inp);
}

int main(void)
{
	person_info_t person[22];
	int i=0;
	FILE *inp;
	inp = fopen("people.dat", "r");

	for(i=0; i<22; i++)
	{
		scan_function(*person, i, inp);
	}

	return 0;
}
