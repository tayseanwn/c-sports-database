//To be implemented

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// -----------------------------------------------------------------------------------------------------
// TYPE DEFINITIONS
// -----------------------------------------------------------------------------------------------------

#define true 1
#define false 0
#define boolean int
#define nameLength 51 /*last space is reserved for null 0*/
#define databaseSize 100

// -----------------------------------------------------------------------------------------------------
// EXTERNAL (INSTANCE) VARIABLES
// -----------------------------------------------------------------------------------------------------


struct nodeAthlete {
    int code; /*IDs*/
    char name[nameLength]; /*String of characters*/
    char gender; /*W= Women, M = Men, X= Not Provided*/
    int age;
    struct nodeAthlete *next;
};
// int numdatabasesAthlete = 0;


// -----------------------------------------------------------------------------------------------------
// PROTOTYPES FOR FUNCTIONS (DECLARATIONS) - Blueprint
// -----------------------------------------------------------------------------------------------------


struct nodeAthlete *addNodeToFrontAthlete(struct nodeAthlete*, int, int, char, char*);
struct nodeAthlete *deleteNodeAthlete(struct nodeAthlete*, int);
boolean isFullAthlete (void);
struct nodeAthlete *insertAthlete (struct nodeAthlete*);
void searchListAthlete (struct nodeAthlete*, int);
void updateAnAthlete (struct nodeAthlete*, int);
void displayListAthlete (struct nodeAthlete*);

// void quit (void); // not neccesary for this assignment
