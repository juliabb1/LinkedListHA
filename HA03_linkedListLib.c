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

    if(start -> nextElem == NULL) {
        printf("Empty list.\n");
        return;
    }

    printf("**********************************\n");
    while(start->nextElem != NULL) {
        start = start->nextElem;
        printf("Last name: %s \n", start -> lastName);
        printf("First name: %s \n", start -> firstName);
        printf("Age: %d \n", start -> age);
        printf("\n");
    }
    printf("**********************************\n");

}

void delListElem(listElement *start){

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
        currElem = currElem->nextElem;                                          //currElem points to the element before the to be deleted list
    }
    delElem = currElem -> nextElem;                                             //delElem points to the element that should be deleted
    currElem -> nextElem = delElem -> nextElem;                                 //currElem points to nextElem which now ist the Elem after delElem
    free(delElem);
    printf("Succesfully deleted!\n\n");
}

void delList(listElement *start){

    if(start -> nextElem == NULL) {
        printf("List is already empty.\n\n");
        return;
    }

    listElement *currElem = start;
    listElement *delElem;

    while(currElem -> nextElem != NULL) {
        delElem = currElem -> nextElem;
        currElem -> nextElem = delElem -> nextElem;
        free(delElem);
    }

    printf("List succesfully deleted!\n\n");


}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

    /* YOUR CODE HERE */
    /* ---------------*/
	
    printf("\n>> saveList fcn is tbd.\n\n");
}

void loadList(listElement *start){
	
	
    /* YOUR CODE HERE */
    /* ---------------*/
    
    printf("\n>> loadList fcn is tbd.\n\n");

	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
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





