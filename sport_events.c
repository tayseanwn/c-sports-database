#include "sport_events.h" // sharing macro defintion, types, and function prototypes from sport_events.h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//To be implemented

// -----------------------------------------------------------------------------------------------------
// Global Varibales
// -----------------------------------------------------------------------------------------------------

// struct node {
//     int id; /*IDs*/
//     char name[nameLength]; /*String of characters*/
//     char gender; /*W= Women, M = Men, X= Mixed*/
//     int competitors;
//     struct node *next;
// };
int numdatabases = 0;

// -----------------------------------------------------------------------------------------------------
// OTHER FUNCTIONS
// -----------------------------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------------------------
// Linked List add method
// -----------------------------------------------------------------------------------------------------

struct node *addNodeToFront(struct node *linkedList, int eCode, int eComp, char eGender, char* eName) {
    struct node *newNode; /*Temporary pointer variable of type struct*/
    newNode = malloc(sizeof(struct node)); // let this pointer contain a size of a single struct node
    newNode->id = eCode;
    printf("ID (%d) added to new event\n", newNode->id);
    strcpy(newNode->name, eName);
    printf("Name (%s) added to new event\n", newNode->name);
    newNode->gender = eGender;
    printf("Gender (%c) added to new event\n", newNode->gender);
    newNode->competitors = eComp;
    printf("Number of competitors (%d) added to new event\n", newNode->competitors);
    newNode->next = linkedList; // point to the first element in the list
    return newNode;
}

// -----------------------------------------------------------------------------------------------------
// Linked List delete method
// -----------------------------------------------------------------------------------------------------

struct node *deleteNode(struct node *linkedList, int n) {
    struct node *current, *previous; // current and previous nodes
    // initialize current and previous, traverse as long as current is not null and element n not found
    for (current = linkedList, previous = NULL; current != NULL &&  current->id != n; previous = current, current = current->next);
    if (current == NULL) { // not found
        printf("Error: Node with id %d not found. Cannot delete\n", n);
        return linkedList;
    }
    if (previous == NULL) { // found, current is first element
        printf("Removing the first element\n");
        linkedList = linkedList->next;
    }
    else { // any other condition
        printf("Removing an element found in a position after the first\n");
        previous->next = current->next;
    }
    free(current);
    numdatabases--;
    return linkedList;
}


// -----------------------------------------------------------------------------------------------------
// IsFull method
// -----------------------------------------------------------------------------------------------------

boolean isFull (void) {
    boolean full = false;
    if (numdatabases == databaseSize) {
        full = true;
        return full;
    }
    else
        return full;
}

// -----------------------------------------------------------------------------------------------------
// 1. Insert a new event (using command i )
// (i) Prompt the user for the event code/ID
//      - Assume the user will enter one integer
//      - Must be unique, cannot conflict. If the number < 0 or number > 99, or if database is full, then error and return to beginning
// (ii) Prompt the user for the name of the event
//      - Assume the user will enter a string of characters of any length
//      - If event name is longer than the acceptable length, accept as many characters as you can and ignore any additional characters
// (iii) Prompt the user for the number of competitors in this event
//      - Assume the user will enter one integer
//      - If the number is less than 10 or greater than 99, tell the user the error and return to the beginning
// (iv) Prompt the user for the gender of the event
//      - Assume the user will enter one character (followed by \n of course)
//      - If a value other than M, W, and X is entered, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

struct node *insertEvent (struct node *list) {

    if (isFull()) { /*if full then return error and go to beginning*/
        printf("Cannot insert a new event because the database is full. (Maximum events = %d)\n", databaseSize);
        return list;
    }
    else {
        printf("Now creating new event...\n");
        /*Local variables*/
        int eCode;
        int eComp;
        char eGender;
        char eName[nameLength];
        /*Code*/
        printf("Enter event ID code (must between 0 and 99): ");
        begin:
        scanf("%d", &eCode);
        struct node *event, *current, *previous;
        int duplicate;
        for (current = list, previous = NULL; current != NULL &&  current->id != eCode;current = current->next, previous = current);
        if (current == NULL) { // not found
            event = NULL;
            duplicate = 0;
        }
        else {
            event = current; // found
            duplicate = 1;
        }
        if (duplicate) {
                printf("Error: conflict. Choose a new code: ");
                goto begin;
        }
        if (eCode < 0 ) { /*if there are no conflicts, check if number is valid*/
            printf("Error: code must be equal to or greater than 0. Choose a new code: ");
//             scanf("%d", &eCode);
            goto begin;
        }
        /*Name*/
        printf("Enter event name with no spaces (maximum name length: %d): ", nameLength-1);
        scanf("%s", eName);
//         gets(eName);
        /*Competitors*/
        printf("Enter the number of competitors: ");
        scanf("%d", &eComp);
        while (eComp < 10 || eComp > 99) {
            printf("Error: number cannot be less than 10 or greater than 99.\nEnter the number of competitors: ");
            while (getchar() != '\n');// now my buffer is clear
            scanf("%d", &eComp);
        }
        /*Gender*/
        printf("Enter the gender (M - Men, W - Women, X - Mixed: ");
        while (getchar() != '\n');
        scanf("%c", &eGender);
        while (eGender != 'M' && eGender != 'W' && eGender != 'X'){
            printf("Error: Invalid input. Choose M for Men, W for Women, X for Mixed (case sensitive): ");
            while (getchar() != '\n');
            scanf(" %c", &eGender);
        }
        numdatabases ++;
        printf("Event successfully added.\nTotal number of events in database: %d\n", numdatabases);

        return addNodeToFront(list, eCode, eComp, eGender, eName);
    }
}


// -----------------------------------------------------------------------------------------------------
// 2. Search for an event in the database and print it out (using command s )
// Prompt the user for the event code:
// (i) If the event code is found, print out all the values for this event only (see the print command below for more details)
// (ii) If the event code is not found, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

void searchList (struct node *list, int code) {
    /*create boolean variable*/
    boolean foundNode = false;

    printf("Searching for event with code: %d\n", code);
    struct node *current, *previous;
    int found;
    struct node *event;
    for (current = list, previous = NULL; current != NULL &&  current->id != code;current = current->next, previous = current);
    if (current == NULL) { // not found
        event = NULL;
        found = 0;
    }
    else {
        event = current; // found
        found = 1;
    }
    if (found) {
        printf("Found event (code: %d)! See values below:\n", code);
        printf("Event ID\t\tEvent Name\t\tEvent Gender\t\tEvent Competitors\n");
        printf("%d\t\t\t%s\t\t\t%c\t\t\t%d\n",event->id, event->name, event->gender, event->competitors);
    }
    else
        printf("Error: We were unable to find event (code: %d).\n", code);
}

// -----------------------------------------------------------------------------------------------------
// 3. Update an event in the database (using command u )
// Prompt the user for the event code:
// (i) If the event code is found, prompt the user to update all the values for the event (see the insert command above for details)
// (ii) If the event code is not found, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

void updateAnEvent (struct node *list, int code) {
    int found = 0;
    printf("Attempting to update event with code: %d\n", code);
    int index = 0;
    /*search for event with code ID*/
    struct node *event;
    struct node *current, *previous;
    int duplicate;
//     int ids[numdatabases];
    int count = 0;
    for (current = list, previous = NULL; current != NULL &&  current->id != code;current = current->next, previous = current);
    if (current == NULL) { // not found
        event = NULL;
        found = 0;
    }
    else {
        event = current; // found
        found = 1;
    }
    if (found) {
        printf("Found event (code: %d)!\n", code);
        /*Local variables*/
        int eCode;
        int eComp;
        char eGender;
        char eName[nameLength];
        /*Code*/

        do {
            printf("Enter event ID code (must between 0 and 99): ");
            while (getchar() != '\n');
            scanf("%d", &eCode);
            struct node *currentTemp, *previousTemp;
            for (currentTemp = list, previousTemp = NULL; currentTemp != NULL &&  currentTemp->id != eCode;currentTemp = currentTemp->next, previousTemp = current);
            if (currentTemp == NULL) { duplicate = 0; } // not found
            else {
                duplicate = 1;
                printf("Error: Please choose another event code.\n");
            }
        }
        while (duplicate == 1 || eCode < 0);

        /*Name*/
        printf("Enter event name with no spaces (maximum name length: %d): ", nameLength-1);
        scanf("%s", eName);
        /*Competitors*/
        printf("Enter the number of competitors: ");
        scanf("%d", &eComp);
        while (eComp < 10 || eComp > 99) {
            printf("Error: number cannot be less than 10 or greater than 99.\nEnter the number of competitors: ");
            while (getchar() != '\n');// now my buffer is clear
            scanf("%d", &eComp);
        }
        /*Gender*/
        printf("Enter the gender (M - Men, W - Women, X - Mixed: ");
        while (getchar() != '\n'); // clear buffer
        scanf(" %c", &eGender);
        while (eGender != 'M' && eGender != 'W' && eGender != 'X'){
            printf("Error: Invalid input. Choose M for Men, W for Women, X for Mixed (case sensitive): ");
            while (getchar() != '\n');
            scanf(" %c", &eGender);
        }
        // create new element and then swap
//         struct node *newNode; /*Temporary pointer variable of type struct*/
//         newNode = malloc(sizeof(struct node)); // let this pointer contain a size of a single struct node
        event->id = eCode;
        printf("ID (%d) added to new event\n", event->id);
        strcpy(event->name, eName);
        printf("Name (%s) added to new event\n", event->name);
        event->gender = eGender;
        printf("Gender (%c) added to new event\n", event->gender);
        event->competitors = eComp;
        printf("Number of competitors (%d) added to new event\n", event->competitors);
        printf("All values have been updated.\n");
    }
    else
        printf("We were unable to find event (code: %d).\n", code);
}

// -----------------------------------------------------------------------------------------------------
// 4. Print the entire list of events (using command p )
// Print out a table listing all the events in your database with all the attributes:
// - Event Code
// - Event Name
// - Competitors
// - Gender
// -----------------------------------------------------------------------------------------------------

void displayList (struct node *linkedList) {
    printf("Olympics Database Events List:\n");
    printf("Linked List: ");
    struct node *current, *previous;
    for (current = linkedList, previous = NULL; current != NULL;current = current->next, previous = current){
        printf("->(%d)",current->id);
    }
    printf("\nEvent ID\t\tEvent Name\t\tEvent Gender\t\tEvent Competitors\n");
    for (current = linkedList, previous = NULL; current != NULL;current = current->next, previous = current){
        printf("%d\t\t\t%s\t\t\t%c\t\t\t%d\n",current->id, current->name, current->gender, current->competitors);
    }
}

// -----------------------------------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------------------------------

// int main (void) {
//
//     /*Create local variables*/
//     char input;
//     int code;
//     struct node *list =  NULL;
//     printf("Sports Event Database For Winter Olympics - Version 2.0\n");
//     beginning:
//     printf("New features of our second edition: an additional operation \"Delete\" was added.\nPlease enter one of the following operations:\nInsert (insert i), Search (insert s), Update (insert u), Print (insert p), Quit (insert q), New: Delete (insert e): ");
//
//
//
//     /*prompt user*/
//     scanf(" %c", &input);
//
//     if (input == 'i') // if insert i create newEvent
//         list = insertEvent(list);
//     else if (input == 's') { // if insert s then search
//         printf("Which event would you like to search for? Enter event code: ");
//         scanf("%d", &code);
//         searchList(list, code);
//     }
//     else if (input == 'u') { // if input u then update
//         printf("Which event would you like to update? Enter event code: ");
//         scanf("%d", &code);
//         updateAnEvent(list, code);
//     }
//     else if (input == 'p') // if input p then print
//         displayList(list);
//     else if (input == 'e') {// if input p then print
//         printf("Which event would you like to delete for? Enter event code: ");
//         scanf("%d", &code);
//         list = deleteNode(list, code);
//     }
//     else if (input == 'q') // if input q then jump to end
//         goto end;
//     else { // any other character return invalid input
//         printf("Invalid input\n");
//     }
//     printf("");
//     goto beginning; // if any input, other than q, restart program
//
//
//     end:
//     return 0;
// }
//
