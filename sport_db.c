// -----------------------------------------------------------------------------------------------------
// DIRECTIVES (Include and Define)
// -----------------------------------------------------------------------------------------------------
#include "sport_db.h" // sharing macro defintion, types, and function prototypes from sport_db.h


#include <stdio.h>

#include <stdlib.h>
#include <string.h>


// -----------------------------------------------------------------------------------------------------
// MAIN FUNCTION
// -----------------------------------------------------------------------------------------------------

int main (void) {

//     printf("1. Print help (using command h ): Print a simple message or messages describing how to use the program.\n");
//     printf("2. Quit (using command q ) Quit the program\n");
//     printf("3. Control events (using command e )\n");
//     printf("4. Control athletes (using command a )\n");
    char input;
    while (input != 'q'){

        printf("1. Print help (using command h ): Print a simple message or messages describing how to use the program.\n");
        printf("2. Quit (using command q ) Quit the program\n");
        printf("3. Control events (using command e )\n");
        printf("4. Control athletes (using command a )\n");

//         while (getchar() != '\n');
        scanf(" %c", &input);

        if (input == 'q')
            break;
        else if(input == 'h'){
            printf("Welcome to the version 2.0 of the Sports Database. In this database you can add both athletes and events into your database.\n");
            printf("Use options (3) and (4) to control events and athletes. You will have the ability to repetitively insert, search, update, delete, and display a list.\n");
            printf("Let's begin!\n");
        }
        else if (input == 'a') { // if they want to go to athlete to modify
            /*Create local variables*/
            char input;
            int code;
            struct nodeAthlete *list =  NULL;
            printf("Athletes Database For Winter Olympics - Version 2.0\n");
            beginningAthlete:
            printf("Please enter one of the following operations:\nInsert (insert i), Search (insert s), Update (insert u), Print (insert p), Quit (insert q), Delete (insert e): ");



            /*prompt user*/
            scanf(" %c", &input);

            if (input == 'i') // if insert i create newAthlete
                list = insertAthlete(list);
            else if (input == 's') { // if insert s then search
                printf("Which athlete would you like to search for? Enter athlete code: ");
                scanf("%d", &code);
                searchListAthlete(list, code);
            }
            else if (input == 'u') { // if input u then update
                printf("Which athlete would you like to update? Enter athlete code: ");
                scanf("%d", &code);
                updateAnAthlete(list, code);
            }
            else if (input == 'p') // if input p then print
                displayListAthlete(list);
            else if (input == 'e') {// if input p then print
                printf("Which athlete would you like to delete for? Enter athlete code: ");
                scanf("%d", &code);
                list = deleteNodeAthlete(list, code);
            }
            else if (input == 'q') // if input q then jump to end
                goto endAthlete;
            else { // any other character return invalid input
                printf("Invalid input\n");
            }
            printf("");
            goto beginningAthlete; // if any input, other than q, restart program


            endAthlete:
            printf("Now exiting Athlete Control Center.\n");

        }


        else if (input == 'e') { // if they want to go to event to modify
            /*Create local variables*/
            char input;
            int code;
            struct node *list =  NULL;
            printf("Sports Event Database For Winter Olympics - Version 2.0\n");
            beginning:
            printf("Please enter one of the following operations:\nInsert (insert i), Search (insert s), Update (insert u), Print (insert p), Quit (insert q), New: Delete (insert e): ");



            /*prompt user*/
            scanf(" %c", &input);

            if (input == 'i') // if insert i create newEvent
                list = insertEvent(list);
            else if (input == 's') { // if insert s then search
                printf("Which event would you like to search for? Enter event code: ");
                scanf("%d", &code);
                searchList(list, code);
            }
            else if (input == 'u') { // if input u then update
                printf("Which event would you like to update? Enter event code: ");
                scanf("%d", &code);
                updateAnEvent(list, code);
            }
            else if (input == 'p') // if input p then print
                displayList(list);
            else if (input == 'e') {// if input p then print
                printf("Which event would you like to delete for? Enter event code: ");
                scanf("%d", &code);
                list = deleteNode(list, code);
            }
            else if (input == 'q') // if input q then jump to end
                goto end;
            else { // any other character return invalid input
                printf("Invalid input\n");
            }
            printf("");
            goto beginning; // if any input, other than q, restart program


            end:
            printf("Now exiting Events Control Center.\n");
        }

        else {
            printf("Error: Wrong input, try again...\n");
        }
    }

    return 0;

}
