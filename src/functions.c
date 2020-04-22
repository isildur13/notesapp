#include<stdio.h>
#include<mysql/mysql.h>
#include"../headers/vars.h"

//-----------------Database related functions.
// Core DB tasks.
//db_connection_status(){}
//db_connection_start(){}
//db_connection_stop(){}


//db_create_table(){}
//db_create_db(){}
//db_delete_table(){}
//db_delete_db(){}


// DB functions.
//db_create_entry(){}
//db_update_entry(){}
//db_delete_entry(){}
//db_view_entry(){}



//----------------Notesapp Core functions.

//create_note(){}
//edit_note(){}
//delete_note(){}
//view_note(){}


//Main Menu function

int menu(){


int x = 0;
while(!x){
        printf("---------------Welcome to notes app-------------------\n");
        printf("Please enter your choice(Number) from the following:-\n1.Create a Note \n2.Edit a Note.\n3.Delete a Note.\n4.View a Note.\n");
        
	scanf("%d",&choice);


        switch(choice){
        case 1: printf("You chose to Create a Note.\n");
                x = 1;
                break;
        case 2: printf("You chose to Edit a Note.\n");
                x = 1;
                break;
        case 3: printf("You chose to Delete a Note.\n");
                x = 1;
                break;
        case 4: printf("You chose to View a Note.\n");
                x = 1;
                break;
        default:printf("Please enter proper choice\n");
        }

        }
        return choice;


}
