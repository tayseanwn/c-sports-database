//To be implemented
#include <stdlib.h>
#include <string.h>

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

struct node {
    int id; /*IDs*/
    char name[nameLength]; /*String of characters*/
    char gender; /*W= Women, M = Men, X= Mixed*/
    int competitors;
    struct node *next;
};
// int numdatabases = 0;

// -----------------------------------------------------------------------------------------------------
// PROTOTYPES FOR FUNCTIONS (DECLARATIONS) - Blueprint
// -----------------------------------------------------------------------------------------------------

struct node *addNodeToFront(struct node*, int, int, char, char*);
struct node *deleteNode(struct node*, int);
boolean isFull (void);
struct node *insertEvent (struct node*);
void searchList (struct node*, int);
void updateAnEvent (struct node*, int);
void displayList (struct node*);

// void quit (void); // not neccesary for this assignment

