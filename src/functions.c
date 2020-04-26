#include<stdio.h>
#include"../headers/vars.h"
#include <sys/stat.h>
#include <stdlib.h>
//----------------Notesapp Core functions.
//int create_path(int filename){
//}

int write_notes(int filename,char * notes){

	char filename_str[150];
	int write_status = 0;
	sprintf(filename_str,"/root/.notesdir/%d/%d.txt",filename,filename);
	FILE* f = fopen(filename_str, "a");	
	
	if (f != NULL)                       // check for success
	{
	     fprintf(f, "%s",notes);            // 
	     fclose(f);                       // close the file
	     f = NULL;                        // set file handle to null since f is no longer valid
	     write_status = 1;
	     return 1;
	}else{
		return 0;
	}

}

int check_note(int date){

	printf("Checking for notes.. dated %d \n",date);

	char location[150];
	struct stat sb;
	sprintf(location,"/root/.notesdir/%d",date);
	printf("Checking at %s  \n",location);
	//Checking for the directory based on the date name. requires sys/stat.h
	
	if (stat(location,&sb) == 0 && S_ISDIR(sb.st_mode)){

		printf("Note Exists... \n");
		return 1;
		} else {
		printf("Note does not Exists.. \n");
		return 0;
	}
}	

int create_note(int date){
	
	char notes[100];
	char folder_path[150];
	sprintf(folder_path,"/root/.notesdir/%d",date);

	if (check_note(date) == 1){
		printf("Note Already exists.. So cannot create one.\n");
		return 1;
	}
	else{ 
		printf("Creating Dir...\n");
		mkdir(folder_path,777);
		printf("Creating a note dated: %d \n",date);
		printf("Enter the contents below \n");	
		scanf("%[^n]%*c",notes);
		write_notes(date,notes);
		return 0;
	}	

}

int edit_note(int date){
	char notes[150];
	if (check_note(date) == 1){
		printf("Editing note...\n");
                printf("Enter the contents below \n");
                scanf("%[^n]%*c",notes);
		write_notes(date,notes);		
		return 1;
	}
	else{ 
		printf("Note doesnot Exist: %d \n",date);
		return 0;
	}


}

int delete_note(int date){
	char notes_path[150];
	char notes_path_cmd[150];
	if (check_note(date) == 1){
		
		printf("Deleting Notes... \n");
		sprintf(notes_path,"/root/.notesdir/%d",date);
		sprintf(notes_path_cmd,"rm -rf %s",notes_path);

		if(system(notes_path_cmd) == 0){
			printf("Notes deleted successfully");
		}
		else{
			printf("Failed to delete the file....");
		}	
		return 1;
	}
	else{ 
		printf("Note doesnot Exist%d \n",date);
		return 0;
	}	
}

int view_note(){

	char file_path[150];
	char s[40];
	char c;
	int n;
	if (check_note(date) == 1){
		printf("Viewing the note \n");
		FILE *reader;
		printf("-----------%d----------",date);
		sprintf(file_path,"/root/.notesdir/%d/%d.txt",date,date);
	        reader = fopen(file_path,"r");
		while( c != EOF)
  		{
    		c = fgetc(reader); /* read from file*/
    		printf("%c",c); /*  display on screen*/
  		}
		fclose(reader);	
		return 1;
	}
	else{ 
		printf("Note doesnot Exist: %d \n",date);
		return 0;
	}	
}

//Main Menu function

int menu(){
int x = 0;
while(!x){
        printf("---------------Welcome to notes app-------------------\n");
        printf("Please enter your choice(Number) from the following:-\n1.Create a Note \n2.Edit a Note.\n3.Delete a Note.\n4.View a Note.\n");
	scanf("%d",&choice);
	printf("Enter the note date: ");
	scanf("%d",&date);
	switch(choice){
        case 1: printf("You chose to Create a Note.\n");
                x = 1;
		create_note(date);
                break;
        case 2: printf("You chose to Edit a Note.\n");
                x = 1;
		edit_note(date);
                break;
        case 3: printf("You chose to Delete a Note.\n");
                x = 1;
		delete_note(date);
                break;
        case 4: printf("You chose to View a Note.\n");
                x = 1;
		view_note(date);
                break;
        default:printf("Please enter proper choice\n");
        }

        }
        return 0; 
}
