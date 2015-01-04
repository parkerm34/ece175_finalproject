#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 50
#define NETWORK_SIZE 22
#define MAX_FRIENDS 21
#define START_FRIENDLIST "****"
#define MAXSEP 3
#define EXIT 1
#define NOFRIENDS 0
#define START 0
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


void print_function(friend_t *person)
{
	printf("%s", person->linkto_person->name);
//	printf("%s", temp->linkto_person->name);
//	person = person->next;
	print_function(person->next);
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

int find_deg_sep(friend_t *pt,char  person2[], person_info_t person[])    // PASS IN
{
        char query1[MAX_CHAR],query2[MAX_CHAR];
        int index_person1, index_person2, index_search=0;
	int deg_sep=0;
        friend_t *temp =(friend_t *)malloc(sizeof(friend_t));
	int status=START;
        
	friend_t *current =(friend_t*) malloc(sizeof(friend_t));
// through each linked list
	        
        
        //temp->linkto_person = pt->linkto_person;
	while(current!=NULL&&deg_sep<MAXSEP)
        {
	//	friend_t *current =(friend_t*) malloc(sizeof(friend_t))
                while(temp!=NULL&&status!=EXIT)
                {
			current=pt;
                        if(temp->linkto_person->id!= person[index_person2].id)
                                return deg_sep;
                        temp=temp->next;
                }
                deg_sep++;

                current=current->next;
        }
        return deg_sep;
}


void f_friend_separation(friend_t *pt, person_info_t person[])
{
        char query1[MAX_CHAR],query2[MAX_CHAR];
        int index_person1, index_person2, index_search=0;
	int deg_sep=0;
        printf("What person are you interested in?\n");
        scanf("%s",query1);
        printf("Who is the friend of %s that you wish to find ", query1);
        printf("the degrees of separation for:\n");
        scanf("%s",query2);

        index_person1 = find_index(person,query1);
        index_person2 = find_index(person,query2);

        deg_sep = find_deg_sep(person[index_person1].linkto_friendlist, query2, person);

        printf("The degrees of separation between %s  and %s  is:   %d.\n",query1,query2,deg_sep);
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
	


	while(!feof(friends_input))
	{

		index_in_array = find_index(person, friend);
		fscanf(friends_input, "%s", friend);

		while(strcmp(friend, START_FRIENDLIST)!=0)
		{
			temp = (friend_t*)malloc(sizeof(friend_t));
			
			temp->linkto_person = &person[find_index(person, friend)];
			if (person[index_in_array].linkto_friendlist == NULL)
				person[index_in_array].linkto_friendlist = temp;
			else
			{
				fscanf(friends_input, "%s", friend);
				index_in_array = find_index(person, friend);
				
				temp->linkto_person = &person[index_in_array];
				temp=temp->next;
				current_friend->next = temp;
				
			}
			current_friend=temp;
		}
		current_friend->next=NULL;
		fscanf(friends_input, "%s", friend);
	}
	fclose(friends_input);
	//temp = person->linkto_friendlist;
//	for(poop=0; poop<22; poop++);
	print_function(head);

	f_friend_separation(head, person);
	return 0;
}



