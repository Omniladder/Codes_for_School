
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char* mygetenv(char* the_proper_term_to_be_identified_as_requested_by_the_user); //prototypes function

extern char **environ; //gets in enviornment variables
static char string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable[500];//used to store final string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable_two

int main()
{
	char* string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable_two = mygetenv("PWD");
	//calls functions and stores string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable_two
	if(string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable_two != NULL) //Checks if Input had been found
	{
		printf("%s", string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable_two);//outputs location
	}
}

char* mygetenv(char* the_proper_term_to_be_identified_as_requested_by_the_user)
{
	int potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word_size = strlen(the_proper_term_to_be_identified_as_requested_by_the_user); //stores size of search term
	int potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word = 0;//used to go through each letter of enviornment variable



	for(int variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check = 0; environ[variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check] != NULL; variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check++) //loops through all enviornmental variables
	{
	
		while(potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word < potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word_size) //loops through every element of the term being ssearched for to figure out if its been found
		{
			if(environ[variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check][potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word] != the_proper_term_to_be_identified_as_requested_by_the_user[potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word])//checks if any letters dont match if they dont breaks
			{
				break;	//breaks out so that potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word would activate next one
			}
			potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word++;//increments to next index
		}
		
		
		
		if(potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word == potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word_size && environ[variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check][potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word_size] == '=') //checks if they were equal and that we hit end of word
		{
			strcpy(string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable, environ[variable_Used_To_Store_The_Location_Index_Of_A_Potential_Wanted_Enviornmental_Used_In_Order_Check] + potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word_size + 1);//sets string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable to variable
			return strcat(string_used_to_store_the_variable_that_needs_to_be_outted_and_hold_teh_result_from_enviormental_variable, "\n"); //adds \n to end and returns
		}
		
		potential_Index_of_letter_within_the_enviormental_variable_to_properly_check_if_one_by_one_the_letters_match_and_thus_the_word = 0; //starts letter index back at 0 for next one

	}
	
	printf("FAILED TO FIND VARIABLE NAMED %s\n", the_proper_term_to_be_identified_as_requested_by_the_user); //gives error if couldnt find term
	
	return (NULL);//used to tell if error happened
}

