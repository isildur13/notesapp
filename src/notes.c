#include <stdio.h>


int main (void){
	
	int choice;
	printf("---------------Welcome to notes app-------------------\n");
	printf("Please enter your choice(Number) from the following:-\n1.Create a Note \n2.Edit a Note.\n3.Delete a Note.\n4.View a Note.\n");
	scanf("%d",&choice);
	switch(choice){
	
	case 1: printf("You chose to Create a Note.\n");
			   break;
	case 2: printf("You chose to Edit a Note.\n");
			   break;
	case 3: printf("You chose to Delete a Note.\n");
			   break;
	case 4: printf("You chose to View a Note.\n");
		   	   break;
	default:printf("Please enter proper choice\n");
	}
	return 0;

}
