//Gabriel Barragan
//Created April 23 2012
//This is the interface that will manuver the user throughout the entire network.

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

char display_available_changes(person_info_t person[], char change_attrib);
char person_query_and_printing(person_info_t person[]);
char create_sorting_array(person_info_t random[]);
int find_index_person_query(person_info_t person[], char query[]);
int find_index(person_info_t person[], char friend[]);
void find_most_or_least(person_info_t people[], char sorting_hilo);
void print_most_or_least(person_info_t person[], int index, char sorting_hilo);
void interface(person_info_t person[ ]); 					//main welcome page of the program
void change_atribute_interface(person_info_t person[ ]); 			//function for changing information
void degree_of_separation_interface(person_info_t person[ ]); 			//function to find the degree of separation
void friendship_interface(person_info_t person[ ]); 				//function to  see who is friends
void view_information_interface(person_info_t person[ ]);			//function to view people information
void print_sorted_function(person_info_t person_array[]);
void change_attributes(person_info_t person[], int person_id, char change_attrib);
person_info_t sort_by_name(person_info_t person_array[], char sorting_hilo);
person_info_t sort_by_height(person_info_t person_array[], char sorting_hilo);
person_info_t sort_by_number_of_friends(person_info_t person_array[], char sorting_hilo);
						  
int main(void)
{
	char cont_question, friend[MAX_CHAR], quitting;
	int k=0, index_in_array=0, j=0, i=0;
	
	person_info_t person[NETWORK_SIZE];

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
				//                      fscanf(friends_input, "%s", friend);
				if(friend == NULL || strcmp(friend, START_FRIENDLIST)==0);
				else
				{
					index_in_array = find_index(person, friend);
					person[j].linkto_friendlist = temp;
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
	
	interface(person);
	do								//want this to come up one time, so use do and while at the end
	{
		printf("\n\nWould you like to return to the main menu or would you like to exit the network?\n");
		printf("\nPress 'Y' or 'y' to return to main menu, or press any other key to exit network.\n");
		fflush(stdin);
		scanf("%c", &cont_question);
		if(cont_question=='Y' || cont_question=='y')		//checks to see if person would like to stay in the network or not
			interface(person);
		else							//what to do if the person wants to leave the network
		{
			printf("\n\nGoodbye!\n");
			return (0);
		}
	}while(cont_question='Y' || cont_question!='y');		//will continue to ask if the user wants to do more in the network as long as the user presses 'y' or 'Y'
	return(0);
}


void interface(person_info_t person[ ]) //main welcome page of the program
{
        int input=0; 			//user input is defined to zero
	char quitting;

        printf("\n\nWelcome to The Social Network! This is the homepage where you can navigate through the interface");
	printf("and do various functions to help make your experience better.\n");
        printf("\nWhat would you like to do?\n");
        printf("\nPress 1 to change an atribute of a person.\nPress 2 to add a relationship.\nPress 3 to delete a relationship.");
	printf("\nPress 4 to sort people.\nPress 5 to find who has the most friends.");
        printf("\nPress 6 to find who has the least ammount of friends.\nPress 7 to see the degree of separation between friends.\nPress 8 to see if a friendship exists.");
        printf("\nPress 9 to view information.\nPress 0 to exit the social network.\n");
        fflush(stdin);							//flush at the top of function because it will be recalled frequently in interface
        scanf("%d", &input);
        switch(input)							//case statements used to see what the user wants to do in the program
        {
                case 0:
                        printf("Sorry to see you leave.");		//used to exit the funtion
                        break;
                case 1:
                        change_atribute_interface(person);		//calls attribute interface function
                        break;
                case 2:
			//function call for adding relationships
                        break;
                case 3:
			//function call for deleting relationships
                        break;
                case 4:
			quitting = create_sorting_array(person);
			if(quitting == 'a')
				quitting = create_sorting_array(person);
                        break;
                case 5:
			find_most_or_least(person, 'M');
                        break;
                case 6:
			find_most_or_least(person, 'l');
			break;
                case 7:
			//function to call the degree of separation between two people
                        break;
                case 8:
			//function to call and see if a friendship exists
                        break;
		case 9:
			view_information_interface(person);		//starts te information interface
			break;
                default :						//if the user enters anything not in the range, will restart the interface
                        printf("Sorry, Your input does not  yield any functionality. You will be returned to the homepage.");
                        interface(person);				//calls the original interface
        }
}

void change_atribute_interface(person_info_t person[ ])                        //function for changing information
{
	int input=0;
	char quitting;
	printf("Welcome to the editing interface.  What attribute of the person would you like to change?\n\n");
	printf("Press 1 to change a name.\nPress 2 to change a persons age\nPress 3 to change a persons height.\nPress 4 to change a perons favorite color.\n");
	printf("Press 0 to return to the main menu.\n\n");
	fflush(stdin);
	scanf("%d", &input);
	switch(input)
	{
		case 0:
			interface(person);					//returns to homepage
			break;
		case 1:
			quitting = display_available_changes(person, 'n');
			if(quitting == 'y')
                		quitting = display_available_changes(person, 'y');
			break;
		case 2:
			quitting = display_available_changes(person, 'a');
			if(quitting == 'y')
                		quitting = display_available_changes(person, 'y');
			break;
		case 3:
			quitting = display_available_changes(person, 'h');
			if(quitting == 'y')
                quitting = display_available_changes(person, 'y');
			break;
		case 4:
			quitting = display_available_changes(person, 'f');
			if(quitting == 'y')
		                quitting = display_available_changes(person, 'y');
			break;
		default :
                        printf("Sorry, Your input does not  yield any functionality. You will be returned to the homepage.\n");
                        interface(person);                              //calls the original interface
	}
}

void view_information_interface(person_info_t person[ ])
{
	int input=0;
	char quitting;
	printf("\nWelcome to the information interface.  What information would you like to see?\n");
	printf("\nPress 1 to show a persons information.\nPress 2 to show a persons friend list.\nPress 0 to return to the main interface.\n");
	fflush(stdin);
	scanf("%d", &input);
	switch(input)
	{
		case 1:
			quitting = person_query_and_printing(person);
			if(quitting == 'a')
				quitting = person_query_and_printing(person);
			break;
		case 2:
			//function that takes person to see what persons friend list they want to see.
			break;
		case 0:
			interface(person);
			break;
		default :
                       printf("Sorry, Your input does not  yield any functionality. You will be returned to the homepage.\n");
                       interface(person);                              //calls the original interface

	}
}

int find_index(person_info_t person[], char friend[])
{
	int i=0;
	for(i=0; i<NETWORK_SIZE; i++)  
	{
		//      printf("%s", friend);
		//      printf("%s\n", person[i].name);
		if(strcmp(friend, person[i].name) == 0)
			return person[i].id;
	}                       
	return -1;
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

/********************This function is to sort by the first name of the people within the network.******************/
/********************If the first letter is the same it compares the second letters.*************************/
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
void print_sorted_function(person_info_t person[])
{
	int printing_counter=0;  
	for(printing_counter=0; printing_counter<NETWORK_SIZE; printing_counter++)
	{
		printf("%d \t %s   \t %d \t %.2f \t %d\n", person[printing_counter].id, person[printing_counter].name, person[printing_counter].age, 
person[printing_counter].height, person[printing_counter].num_of_friends);
	};
}

/******************This function is the main body of the whole sorting portion of the project. ******************/
/******************This function only calls for the array of peoples information and asks the user from there.**************/
char create_sorting_array(person_info_t random[])
{
	person_info_t person_array[22];
	char sorting_hilo='a', what_sort='a', quitting='a';
	int i=0, k=0;
	
	fflush(stdin);

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
				printf("If you would like to return to the main menu press Q or q:");
				scanf("%c", &quitting);
				fflush(stdin);
				return quitting;
			}
			else if(quitting == 'Y' || quitting == 'y')
				return 'a';
		}
		else
		{
			printf("\nWhat would you like to sort by?\n");
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
					printf("If you would like to return to the main menu press Q or q:");
					fflush(stdin);
					scanf("%c", &quitting);
					return quitting;
					break;
				}
				default:
				{
				//	printf("done.");
					break;
				}
			}
		}
	k=1;
	}
}
/*************Special case for Searching Query*******************/
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
/***************Searches and displays results for user interaction people*****************/
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
		printf("\n\n");
		for(i=0; i<NETWORK_SIZE; i=i+3)
			printf("%s,   \t%s,   \t%s\n", person[i].name, person[i+1].name, person[i+2].name);

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
				printf("\n\nYour query contains irregular characters.\n");
				printf("If you would like to quit back to the main menu press Q or q\n");
				printf("If you would like to attempt again press any other character:");
				scanf("%c", &quitting);
				fflush(stdin);
				if(quitting == 'Q' || quitting == 'q')
					return quitting;
				else
					return 'a';
			}
		}
		printf("You are looking up %s...\n", query);
		index = find_index_person_query(person, query);  
		if(index == -1)
		{
			printf("\n\nError. Not found\n");
			printf("If you would like to quit back to the main menu press Q or q\n");
			printf("If you would like to attempt again press any other character:");
			scanf("%c", &quitting);
			fflush(stdin);
			if(quitting == 'Q' || quitting == 'q')
				return quitting;
			else
				return 'a';
		}
		printf("Name \t ID \t Height \t Age \t Favorite Color \t Number of Friends\n");
		printf("%s \t %d \t %.2f \t\t %d \t %s \t\t\t %d\n", person[index].name, person[index].id, person[index].height, person[index].age,
			   person[index].fav_color, person[index].num_of_friends);
	}
	printf("\n\nIf you would like to quit back to the main menu press Q or q\n");
	printf("If you would like to attempt again press any other character:");
	scanf("%c", &quitting);
	fflush(stdin);
	if(quitting == 'Q' || quitting == 'q')
		return quitting;
	else
		return 'a';
}
/***************These short functions or for finding the most and least popular*******************/
void print_most_or_least(person_info_t person[], int index, char sorting_hilo)
{
	if(sorting_hilo == 'M' || sorting_hilo == 'm')
		printf("\nThe most popular person in the social network is %s at %d friends\n", person[index].name, person[index].num_of_friends);
	else
		printf("\nThe least popular person in the social network is %s at %d friends\n", person[index].name, person[index].num_of_friends);
}

void find_most_or_least(person_info_t people[], char sorting_hilo)
{
	int index=0, i=0, min=21, max=0;
	
	if(sorting_hilo == 'M' || sorting_hilo == 'm')
	{   
		for(i=0; i<NETWORK_SIZE; i++)
		{
			if(people[i].num_of_friends >=  max)
			{
				max = people[i].num_of_friends;
				index = i;
			}
		}
		print_most_or_least(people, index, sorting_hilo);
	}
	else
	{
		for(i=0; i<NETWORK_SIZE; i++)
		{
			if(people[i].num_of_friends <=  min )
			{
				min = people[i].num_of_friends;
				index = i;
			}
		}
		print_most_or_least(people, index, sorting_hilo);
	}       
}               

/******************This is the physical changing of the attributes function******************/
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

/*******************This displays the changed and unchanged attributes**********************/
char display_available_changes(person_info_t person[], char change_attrib)
{
	int i=0, choice=0; 
	char quitting;
	
	if(change_attrib == 'y')
	{
		printf("\nPlease choose which attribute you would like to change. Press a for age, h for height, n for name, or f for favorite color: ");
		scanf("%c", change_attrib);
		fflush(stdin);
	}
		
	printf("\nYou chose change attributes. if you would like to cancel or quit, press Q or q. Press any other key to continue.\n");
	scanf("%c", &quitting);
	fflush(stdin);
	if(quitting == 'Q' || quitting == 'q')
		return quitting;
	else
	{
		for(i=0; i<NETWORK_SIZE; i++)
			printf("%d. \t %.2f \t %d \t %s    \t %s\n", person[i].id, person[i].height, person[i].age, person[i].fav_color, person[i].name);
		
		printf("\nThese are the available people to have attributes changed.\n");
		printf("Please choose which person you would like to change by selecting their ID: ");
		scanf("%d", &choice);
		fflush(stdin);
		change_attributes(person, choice, change_attrib);
	}
	printf("Here are the new attributes:\n");
	for(i=0; i<NETWORK_SIZE; i++)
		printf("%d. \t %.2f \t %d \t %s     \t %s\n", person[i].id, person[i].height, person[i].age, person[i].fav_color, person[i].name);
	
	printf("\nWould you like to make another change? y for yes, n for no: ");
	scanf("%c", &quitting);
	fflush(stdin);
	return quitting;
}

