#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"

void addListElem(listElement *start){
    
    listElement * new;                                      //creates a new list
    new = (listElement *)malloc(sizeof(listElement));       //reserves storage for the new list
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;                         //currElem starts from startElem
    while (currElem->nextElem != NULL) {                    //currElem
        currElem = currElem->nextElem;                      //get last elem in list
    }
        currElem->nextElem = new;                           //currElem points his pointer to "new" => add new list to the end of list
        new->nextElem = NULL;                               //new list points to NULL
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s", &new->lastName);                            
    printf("Please enter first name: \n");
    scanf("%s", &new->firstName);
    printf("Please enter age: \n");
    scanf("%d", &new->age);
    printf("\n\n");
}

void printList(listElement *start){

    listElement *currElem = start;

    if(currElem -> nextElem == NULL) {
        printf("Empty list.\n\n");
        return;
    }

    printf("**********************************\n");
    printf("\n");
    while(currElem->nextElem != NULL) {
        currElem = currElem->nextElem;
        printf("Last name: %s \n", currElem -> lastName);
        printf("First name: %s \n", currElem -> firstName);
        printf("Age: %d \n", currElem -> age);
        printf("\n");
    }
    printf("**********************************\n");

}

void delListElem(listElement *start){

    int choice = 0;

    if(start->nextElem == NULL) {                                             //when list ist empty
        printf("Empty list.\n\n");
        return;
    }

    char remove_lastName[50];
    listElement *currElem = start;
    listElement *delElem;

    printf("Last name of the person you want to remove: ");
    scanf("%s", &remove_lastName);

    
    while(strcmp(currElem -> nextElem->lastName, remove_lastName) != 0){        //searches for the element that should be deleted
        currElem = currElem->nextElem;                                          //currElem points to the element before delElem
    }

    delElem = currElem -> nextElem;                                             //delElem points to the element that should be deleted

    //safety question
    printf("Do you really want to remove this element?\n");
    printf("**********************************\n");
    printf("Last name: %s \n", delElem -> lastName);
    printf("First name: %s \n", delElem -> firstName);
    printf("Age: %d \n", delElem -> age);
    printf("**********************************\n");
    printf("0: no\n1: yes\n");
    scanf("%d", &choice);
    system("cls");

    //removal
    if(!choice) {
        printf("Element will not be deleted.\n\n");
        return;
    }

    currElem -> nextElem = delElem -> nextElem;                                 //currElem points to nextElem which now ist the Elem after delElem
    free(delElem);
    printf("Succesfully deleted!\n\n");

}

void delList(listElement *start){

    int choice = 0;

    if(start -> nextElem == NULL) {
        printf("List is already empty.\n\n");
        return;
    }

    //safety question
    printf("Do you really want to delete the whole list?\n");
    printf("0: no\n1: yes\n");
    scanf("%d", &choice);
    printf("\n");

    if(!choice) {
        printf("List will not be deleted.\n\n");
        return;
    }

    listElement *currElem = start;
    listElement *delElem;

    while(currElem -> nextElem != NULL) {                                       //iteration until last elem in list
        delElem = currElem -> nextElem;                                         
        currElem -> nextElem = delElem -> nextElem;                             
        free(delElem);                                                          //deallocation of delElem
    }

    printf("List succesfully deleted!\n\n");


}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; 
        counter++;
        }
    return counter;
}

void saveList(listElement *start){

    FILE *fptr;
    listElement* currElem = start;
    char filename[50];
    int counter = 0;

    printf("filename: ");                       //user chooses the filename
    scanf("%s", &filename);
    fptr = fopen(filename, "w");               //will create a file with mode "w": write
    if(fptr == NULL) {
        printf("Could not open file.\n");
        return;
    }

    if(currElem->nextElem == NULL) {
        printf("You created an empty file.\n");
    }

    //writes into the file
    while(currElem->nextElem != NULL && counter != getLenOfList(start)){
        currElem = currElem->nextElem;
        fprintf(fptr, "%s\n%s\n%d\n", currElem -> lastName, currElem -> firstName, currElem -> age);
        counter++;
    }


    fclose(fptr);

}

void loadList(listElement *start){
	
	FILE *fptr;
    listElement* currElem = start;
    listElement* newElem;
    char filename[50];
   
    printf("*****************************************************************************************\n");
    system("dir. *txt");
    printf("*****************************************************************************************\n");
    printf("filename: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");

    if(fptr == NULL){
        printf("Could not open file.\n");
        return;
    }

    while(!feof(fptr)){
        newElem = (listElement*)malloc(sizeof(listElement));                                                
        currElem -> nextElem =  newElem;
        newElem -> nextElem = NULL;
        currElem = newElem;
        fscanf(fptr, "%s\n%s\n%d\n", &(currElem -> lastName), &(currElem -> firstName), &(currElem -> age));
    
    }
        
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list

    fclose(fptr);
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}





