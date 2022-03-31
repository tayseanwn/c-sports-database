#include "sport_athlete.h" // sharing macro defintion, types, and function prototypes from sport_athlete.h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* dump: Dumps contents of the athlete_tbl to specified
 *       file. Prints error message and does not
 *       terminate program upon failure. Does not store
 *       next pointer.
 */
// void dump_athlete(struct athlete **athlete_tbl)
// {
//     FILE *fp;
//     char filename[255];
//     struct athlete **node = athlete_tbl;
//
//     printf("Enter name of output file: ");
//     read_line(filename, 255);
//
//     if ((fp = fopen(filename, "wb")) == NULL)
//     {
//         fprintf(stderr, "File %s could not be written\n", filename);
//         return;
//     }
//
//     while (*node)
//     {
//         fwrite(*node, sizeof(struct athlete) - sizeof(struct athlete *), 1, fp);
//         node = &(*node)->next;
//     }
//     fclose(fp);
//     return;
// }
//
// /* restore: Restores contents from specified file. Does
//  *          not terminate upon file open failure, but
//  *          terminates upon malloc failure.
//  */
// void restore_athlete(struct athlete **athlete_tbl)
// {
//     FILE *fp;
//     char filename[255];
//     struct athlete buffer;
//     struct athlete *temp;
//     struct athlete **node;
//
//     printf("Enter name of input file: ");
//     read_line(filename, 255);
//
//     if ((fp = fopen(filename, "rb")) == NULL)
//     {
//         fprintf(stderr, "Error: file %s cannot be opened\n", filename);
//         return;
//     }
//
//     while (*athlete_tbl)
//     {
//         temp = *athlete_tbl;
//         *athlete_tbl = (*athlete_tbl)->next;
//         free(temp);
//     }
//
//     node = athlete_tbl;
//
//     while (fread(&buffer,sizeof(struct athlete) - sizeof(struct athlete *),1,fp) == 1)
//     {
//         if ((*node = malloc(sizeof(struct athlete))) == NULL)
//         {
//             fprintf(stderr, "Error: malloc failed in restore\n");
//             exit(EXIT_FAILURE);
//         }
//         (*node)->number = buffer.number;
//         strcpy((*node)->name, buffer.name);
//         (*node)->age = buffer.age;
//         (*node)->gender = buffer.gender;
//         (*node)->next = NULL;
//         node = &(*node)->next;
//     }
//     fclose(fp);
//     return;
// }

//To be implemented

// -----------------------------------------------------------------------------------------------------
// Global Varibales
// -----------------------------------------------------------------------------------------------------

int numdatabasesAthlete = 0;

// -----------------------------------------------------------------------------------------------------
// OTHER FUNCTIONS
// -----------------------------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------------------------
// Linked List add method
// -----------------------------------------------------------------------------------------------------

struct nodeAthlete *addNodeToFrontAthlete(struct nodeAthlete *linkedList, int eCode, int eAge, char eGender, char* eName) {
    struct nodeAthlete *newNode; /*Temporary pointer variable of type struct*/
    newNode = malloc(sizeof(struct nodeAthlete)); // let this pointer contain a size of a single struct node
    newNode->code = eCode;
    printf("Code (%d) added to new athlete\n", newNode->code);
    strcpy(newNode->name, eName);
    printf("Name (%s) added to new athlete\n", newNode->name);
    newNode->gender = eGender;
    printf("Gender (%c) added to new athlete\n", newNode->gender);
    newNode->age = eAge;
    printf("Age (%d) added to new athlete\n", newNode->age);
    newNode->next = linkedList; // point to the first element in the list
    return newNode;
}

// -----------------------------------------------------------------------------------------------------
// Linked List delete method
// -----------------------------------------------------------------------------------------------------

struct nodeAthlete *deleteNodeAthlete(struct nodeAthlete *linkedList, int n) {
    struct nodeAthlete *current, *previous; // current and previous nodes
    // initialize current and previous, traverse as long as current is not null and element n not found
    for (current = linkedList, previous = NULL; current != NULL &&  current->code != n; previous = current, current = current->next);
    if (current == NULL) { // not found
        printf("Error: Node with code %d not found. Cannot delete\n", n);
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
    numdatabasesAthlete--;
    return linkedList;
}


// -----------------------------------------------------------------------------------------------------
// IsFull method
// -----------------------------------------------------------------------------------------------------

boolean isFullAthlete (void) {
    boolean full = false;
    if (numdatabasesAthlete == databaseSize) {
        full = true;
        return full;
    }
    else
        return full;
}

// -----------------------------------------------------------------------------------------------------
// 1. Insert a new athlete (using command i )
// (i) Prompt the user for the athlete code/ID
//      - Assume the user will enter one integer
//      - Must be unique, cannot conflict. If the number < 0 or number > 99, or if database is full, then error and return to beginning
// (ii) Prompt the user for the name of the athlete
//      - Assume the user will enter a string of characters of any length
//      - If athlete name is longer than the acceptable length, accept as many characters as you can and ignore any additional characters
// (iii) Prompt the user for the number of competitors in this athlete
//      - Assume the user will enter one integer
//      - If the number is less than 16 or greater than 99, tell the user the error and return to the beginning
// (iv) Prompt the user for the gender of the athlete
//      - Assume the user will enter one character (followed by \n of course)
//      - If a value other than M, W, and X is entered, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

struct nodeAthlete *insertAthlete (struct nodeAthlete *list) {

    if (isFullAthlete()) { /*if full then return error and go to beginning*/
        printf("Cannot insert a new athlete because the database is full. (Maximum athlete = %d)\n", databaseSize);
        return list;
    }
    else {
        printf("Now creating new athlete...\n");
        /*Local variables*/
        int eCode;
        int eAge;
        char eGender;
        char eName[nameLength];
        /*Code*/
        printf("Enter athlete code (must between 0 and 99): ");
        begin:
        scanf("%d", &eCode);
        struct nodeAthlete *athlete, *current, *previous;
        int duplicate;
        for (current = list, previous = NULL; current != NULL &&  current->code != eCode;current = current->next, previous = current);
        if (current == NULL) { // not found
            athlete = NULL;
            duplicate = 0;
        }
        else {
            athlete = current; // found
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
        printf("Enter athlete's first name with no spaces (maximum name length: %d): ", nameLength-1);
        scanf("%s", eName);
        /*age*/
        printf("Enter the age: ");
        scanf("%d", &eAge);
        while (eAge < 16 || eAge > 99) {
            printf("Error: number cannot be less than 16 or greater than 99.\nEnter the age: ");
            while (getchar() != '\n');// now my buffer is clear
            scanf("%d", &eAge);
        }
        /*Gender*/
        printf("Enter the gender (M - Men, W - Women, X - Not Provided: \n");
        while (getchar() != '\n'); //clear buffer
        scanf(" %c", &eGender);
        while (eGender != 'M' && eGender != 'W' && eGender != 'X'){
            printf("Error: Invalid input. Choose M for Men, W for Women, X for not mentioned (case sensitive): ");
            while (getchar() != '\n');
            scanf(" %c", &eGender);
        }
        numdatabasesAthlete ++;
        printf("Athlete successfully added.\nTotal number of athletes in database: %d\n", numdatabasesAthlete);

        return addNodeToFrontAthlete(list, eCode, eAge, eGender, eName);
    }
}


// -----------------------------------------------------------------------------------------------------
// 2. Search for an athlete in the database and print it out (using command s )
// Prompt the user for the athlete code:
// (i) If the athlete code is found, print out all the values for this athlete only (see the print command below for more details)
// (ii) If the athlete code is not found, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

void searchListAthlete (struct nodeAthlete *list, int inputCode) {
    /*create boolean variable*/
    boolean foundNode = false;

    printf("Searching for athlete with code: %d\n", inputCode);
    struct nodeAthlete *current, *previous;
    int found;
    struct nodeAthlete *athlete;
    for (current = list, previous = NULL; current != NULL &&  current->code != inputCode;current = current->next, previous = current);
    if (current == NULL) { // not found
        athlete = NULL;
        found = 0;
    }
    else {
        athlete = current; // found
        found = 1;
    }
    if (found) {
        printf("Found athlete (code: %d)! See values below:\n", inputCode);
        printf("Athlete Code\t\tAthlete Name\t\tAthlete Gender\t\tAthlete Age\n");
        printf("%d\t\t\t%s\t\t\t%c\t\t\t%d\n",athlete->code, athlete->name, athlete->gender, athlete->age);
    }
    else
        printf("Error: We were unable to find athlete (code: %d).\n", inputCode);
}

// -----------------------------------------------------------------------------------------------------
// 3. Update an athlete in the database (using command u )
// Prompt the user for the athlete code:
// (i) If the athlete code is found, prompt the user to update all the values for the athlete (see the insert command above for details)
// (ii) If the athlete code is not found, tell the user the error and return to the beginning
// -----------------------------------------------------------------------------------------------------

void updateAnAthlete (struct nodeAthlete *list, int inputCode) {
    int found = 0;
    printf("Attempting to update athlete with code: %d\n", inputCode);
    int index = 0;
    /*search for athlete with code ID*/
    struct nodeAthlete *athlete;
    struct nodeAthlete *current, *previous;
    int duplicate;
//     int allCodes[numdatabasesAthlete];
    int count = 0;
    for (current = list, previous = NULL; current != NULL &&  current->code != inputCode;current = current->next, previous = current) {
//         allCodes[count] = current->code;
//         count++;
    }
    if (current == NULL) { // not found
        athlete = NULL;
        found = 0;
    }
    else {
        athlete = current; // found
        found = 1;
    }
    if (found) {
        printf("Found athlete (code: %d)!\n", inputCode);
        /*Local variables*/
        int eCode;
        int eAge;
        char eGender;
        char eName[nameLength];
        /*Code*/
        do {
            printf("Enter event ID code (must between 0 and 99): ");
            while (getchar() != '\n');
            scanf("%d", &eCode);
            struct nodeAthlete *currentTempB, *previousTempB;
            for (currentTempB = list, previousTempB = NULL; currentTempB != NULL &&  currentTempB->code != eCode;currentTempB = currentTempB->next, previousTempB = current);
            if (currentTempB == NULL) { duplicate = 0; } // not found
            else {
                duplicate = 1;
                printf("Error: Please choose another event code.\n");
            }
        }
        while (duplicate == 1 || eCode < 0);

        /*Name*/
        printf("Enter athlete's first name with no spaces (maximum name length: %d): ", nameLength-1);
        scanf("%s", eName);
        /*age*/
        printf("Enter the age: ");
        scanf("%d", &eAge);
        while (eAge < 16 || eAge > 99) {
            printf("Error: number cannot be less than 16 or greater than 99.\nEnter the age: ");
            while (getchar() != '\n');// now my buffer is clear
            scanf("%d", &eAge);
        }
        /*Gender*/
        printf("Enter the gender (M - Men, W - Women, X - Not Provided: \n");
        while (getchar() != '\n');// now my buffer is clear
        scanf(" %c", &eGender);
        while (eGender != 'M' && eGender != 'W' && eGender != 'X'){
            printf("Error: Invalid input. Choose M for Men, W for Women, X for Not Provided (case sensitive): ");
            while (getchar() != '\n'); // clear buffer again to avoid \n character conflict
            scanf(" %c", &eGender);
        }
        // create new element and then swap
//         struct nodeAthlete *newNode; /*Temporary pointer variable of type struct*/
//         newNode = malloc(sizeof(struct node)); // let this pointer contain a size of a single struct node
        athlete->code = eCode;
        printf("Code (%d) added to new athlete\n", athlete->code);
        strcpy(athlete->name, eName);
        printf("Name (%s) added to new athlete\n", athlete->name);
        athlete->gender = eGender;
        printf("Gender (%c) added to new athlete\n", athlete->gender);
        athlete->age = eAge;
        printf("Age (%d) added to new athlete\n", athlete->age);
        printf("All values have been updated.\n");
    }
    else
        printf("We were unable to find athlete (code: %d).\n", inputCode);
}

// -----------------------------------------------------------------------------------------------------
// 4. Print the entire list of athletes (using command p )
// Print out a table listing all the athletes in your database with all the attributes:
// - athlete Code
// - athlete Name
// - age
// - Gender
// -----------------------------------------------------------------------------------------------------

void displayListAthlete (struct nodeAthlete *linkedList) {
    printf("Olympics Database Athletes List:\n");
    printf("Linked List: ");
    struct nodeAthlete *current, *previous;
    for (current = linkedList, previous = NULL; current != NULL;current = current->next, previous = current){
        printf("->(%d)",current->code);
    }
    printf("\nAthlete Code\t\tAthlete Name\t\tAthlete Gender\t\tAthlete Age\n");
    for (current = linkedList, previous = NULL; current != NULL;current = current->next, previous = current){
        printf("%d\t\t\t%s\t\t\t%c\t\t\t%d\n",current->code, current->name, current->gender, current->age);
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
//     struct nodeAthlete *list =  NULL;
//     printf("Athletes Database For Winter Olympics - Version 2.0\n");
//     beginning:
//     printf("Please enter one of the following operations:\nInsert (insert i), Search (insert s), Update (insert u), Print (insert p), Quit (insert q), Delete (insert e): ");
//
//
//
//     /*prompt user*/
//     scanf(" %c", &input);
//
//     if (input == 'i') // if insert i create newAthlete
//         list = insertAthlete(list);
//     else if (input == 's') { // if insert s then search
//         printf("Which athlete would you like to search for? Enter athlete code: ");
//         scanf("%d", &code);
//         searchListAthlete(list, code);
//     }
//     else if (input == 'u') { // if input u then update
//         printf("Which athlete would you like to update? Enter athlete code: ");
//         scanf("%d", &code);
//         updateAnAthlete(list, code);
//     }
//     else if (input == 'p') // if input p then print
//         displayListAthlete(list);
//     else if (input == 'e') {// if input p then print
//         printf("Which athlete would you like to delete for? Enter athlete code: ");
//         scanf("%d", &code);
//         list = deleteNodeAthlete(list, code);
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

