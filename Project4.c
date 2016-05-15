/*
COP2220 Project 4
Domenic Mangani
11/4/14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 32
#define LEN_NAME 20


void welcome ( void );
int displayMenu ( void );
void displaySingle ( const char host[][LEN_NAME], int wins,
                     int losses, int ties, int elements );

char *findTeam ( const char host[][LEN_NAME], char *needle, int elements );
void displayWinTotal ( const char host[][LEN_NAME], int wins[], int losses[], int ties[], int elements );
void displayWinners ( const char host[][LEN_NAME], int wins[], int losses[], int ties[], int elements );
int displayAll ( const char host[][LEN_NAME], int wins[], int losses[], int ties[], int elements );


int main ( void )
{

    char found;
    char response[LEN_NAME];
    char needle[LEN_NAME];
    const char host[MAX_ELEMENTS][LEN_NAME] = { "Arizona", "Atlanta", "Baltimore", "Buffalo",
                                                "Carolina", "Chicago", "Cincinnati", "Cleveland", "Dallas", "Denver",
                                                "Detroit", "Green Bay", "Houston", "Indianapolis", "Jacksonville",
                                                "Kansas City", "Miami", "Minnesota", "N.Y. Giants", "N.Y. Jets",
                                                "New England", "New Orleans", "Oakland", "Philadelphia", "Pittsburgh",
                                                "San Diego", "San Francisco", "Seattle", "St. Louis", "Tampa Bay",
                                                "Tennessee", "Washington"
                                              };
    int wins[MAX_ELEMENTS] = { 6, 2, 5, 5, 3, 3, 4, 4, 6, 6, 6, 5, 4, 5, 1, 4, 4, 3,
                               3, 1, 6, 4, 0, 5, 5, 5, 4, 4, 2, 1, 2, 3
                             };
    int losses[MAX_ELEMENTS] = { 1, 6, 3, 3, 5, 5, 2, 3, 2, 1, 2, 3, 4, 3, 7, 3, 3,
                                 5, 4, 7, 2, 4, 7, 2, 3, 3, 3, 3, 5, 6, 6, 5
                               };
    int ties[MAX_ELEMENTS] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                             };

    int mainLoop = 0, index = 0, menuChoice, num;

    welcome();

    while ( mainLoop == 0 )
    {
        menuChoice = displayMenu();
        if ( menuChoice == 1 )
        {
            fflush(stdin);
            printf( "Enter team/city name: " );
            fgets( response, sizeof(response), stdin );
            response[strlen(response) - 1] = '\0';

            for ( index = 0; index < MAX_ELEMENTS - 1; index++ )
            {
                if (strstr(host[index], response) != NULL)
                {
                    found = 'Y';
                    num = index;
                    printf ("\nNeedle: %s found in Haystack[index]: %s\n", response, host[index]);
                }
            }

//            if ( found == 'Y' )
//                {
//
//                    displaySingle ( host, wins, losses, ties, num );
//
//                }
//            else if ( found == 'N' )
//            {
//                printf ( "Substring not found." );
//            }

        }
        else if ( menuChoice == 2 )
        {
            displayAll ( host, wins, losses, ties, MAX_ELEMENTS );
        }
        else if ( menuChoice == 3 )
        {
            displayWinners ( host, wins, losses, ties, MAX_ELEMENTS );
        }
        else if ( menuChoice == 4 )
        {
            displayWinTotal( host, wins, losses, ties, MAX_ELEMENTS );
        }
        else if ( menuChoice == 9 )
        {
            mainLoop = 1;
        }

    } // end mainLoop

    printf ( "Program quit by user.\n\nThese results were provided by Dom!\n" );
    system ( "PAUSE" );

    return 0;
}

// function to greet user with display message. no parameters or return.
void welcome ( void )
{
    printf ( "Welcome to another depressing Jaguar season!\n");
}

// function to display menu and request user input with validation.
// no parameters, returns user input by way of integers 0-4.
int displayMenu ( void )
{
    int input = 0, valid = 0;

    while ( valid == 0 )
    {
        printf ( "Menu options:\n1)Search team by name\n2)List all team data\n"
                 "3)Display winning team data\n4)Display amount of winning teams\n"
                 "9)Quit\nSelect an option (1,2,3,4,9): " );
        scanf ( "%i", &input );

        if ( input == 1 || input == 2 || input == 3 || input == 4 || input == 9 )
        {
            valid = 1;
            return input;
        }
        else
        {
            printf ( "\nInvalid selection. Please try again.\n\n" );
        }
    }
    return;
}

void displaySingle ( const char host[][LEN_NAME], int wins[], int losses[],
                     int ties[], int elements )
{
    printf ("Team: %s [W:%i L:%i T:%i]\n\n", host[elements], wins[elements],
            losses[elements], ties[elements] );
}

/*  function to display host name and season record. parameters include char array
    to store team names, and int arrays to store records. returns total output printed  */
int displayAll ( const char host[][LEN_NAME], int wins[], int losses[],
                 int ties[], int elements )
{
    int index;

    printf ( "Season stats for all Teams:\n");

    for ( index = 0; index < elements; index++ )
    {
        printf ( "%s [W:%i L:%i T:%i]\n",
                 host[index], wins[index], losses[index], ties[index] );
    }

    printf ( "\nTotal teams displayed: %i\n\n", elements );
    return elements;
}

/*  function to display teams with a winning season. parameters include char array
    for team names, and int arrays for win/loss/tie records. no return  */
void displayWinners ( const char host[][LEN_NAME], int wins[],
                      int losses[], int ties[], int elements )
{
    int index, count = 0, lowest = 1;

    printf ( "\nWinning Teams:\n");

    for ( index = 0; index < elements; index++ )
    {
        if ( wins[index] > losses[index] && losses[index] <= lowest  )
        {
            printf ( "%s [W:%i L:%i T:%i]\n",
                     host[index], wins[index], losses[index], ties[index] );
            count++;
        }
    }
    printf ( "Total winning teams: %i\n\n", count );
}

/*  function to display number of teams with a positive record (wins>losses).
    parameters include char array for team names, and int arrays
    for win/loss/tie records. returns total output printed  */
void displayWinTotal ( const char host[][LEN_NAME], int wins[],
                       int losses[], int ties[], int elements )
{
    int index, count = 0;

    for ( index = 0; index < elements; index++ )
    {
        if ( wins[index] > losses[index] )
        {
            printf ( "%s [W:%i L:%i T:%i]\n",
                     host[index], wins[index], losses[index], ties[index] );
            count++;
        }
    }
    printf ( "\nTotal winning teams: %i\n\n", count );

}

char *findTeam ( const char host[][LEN_NAME], char *needle, int elements )
{
    //char * strstr ( const char *, const char * );
    int index, count = 0;
    char *result;

    for ( index = 0; index < elements; index++ )
    {
        result = strstr(host[index], needle);
        printf( "The substring is: %s\n", result );

        if ( result )
        {
            printf ( "input val = %s", needle );
            printf ( "host val = %s", host[index] );
            printf ( "Team located?\nhost val= %s\ninput val= %s", host, needle );
            count++;
        }

    }
    return result;

}


/**
//----- TEST DATA -----//

Welcome to another depressing Jaguar season!
Menu options:
1)Search team by name
2)List all team data
3)Display winning team data
4)Display amount of winning teams
9)Quit
Select an option (1,2,3,4,9): 2
Season stats for all Teams:
Team: Arizona
Stats [W:6 L:1 T:0]
Team: Atlanta
Stats [W:2 L:6 T:0]
Team: Baltimore
Stats [W:5 L:3 T:0]
Team: Buffalo
Stats [W:5 L:3 T:0]
Team: Carolina
Stats [W:3 L:5 T:1]
Team: Chicago
Stats [W:3 L:5 T:0]
Team: Cincinnati
Stats [W:4 L:2 T:1]
Team: Cleveland
Stats [W:4 L:3 T:0]
Team: Dallas
Stats [W:6 L:2 T:0]
Team: Denver
Stats [W:6 L:1 T:0]
Team: Detroit
Stats [W:6 L:2 T:0]
Team: Green Bay
Stats [W:5 L:3 T:0]
Team: Houston
Stats [W:4 L:4 T:0]
Team: Indianapolis
Stats [W:5 L:3 T:0]
Team: Jacksonville
Stats [W:1 L:7 T:0]
Team: Kansas City
Stats [W:4 L:3 T:0]
Team: Miami
Stats [W:4 L:3 T:0]
Team: Minnesota
Stats [W:3 L:5 T:0]
Team: N.Y. Giants
Stats [W:3 L:4 T:0]
Team: N.Y. Jets
Stats [W:1 L:7 T:0]
Team: New England
Stats [W:6 L:2 T:0]
Team: New Orleans
Stats [W:4 L:4 T:0]
Team: Oakland
Stats [W:0 L:7 T:0]
Team: Philadelphia
Stats [W:5 L:2 T:0]
Team: Pittsburgh
Stats [W:5 L:3 T:0]
Team: San Diego
Stats [W:5 L:3 T:0]
Team: San Francisco
Stats [W:4 L:3 T:0]
Team: Seattle
Stats [W:4 L:3 T:0]
Team: St. Louis
Stats [W:2 L:5 T:0]
Team: Tampa Bay
Stats [W:1 L:6 T:0]
Team: Tennessee
Stats [W:2 L:6 T:0]
Team: Washington
Stats [W:3 L:5 T:0]

Total teams displayed: 32

Menu options:
1)Search team by name
2)List all team data
3)Display winning team data
4)Display amount of winning teams
9)Quit
Select an option (1,2,3,4,9): 3

Winning Teams:
Team: Arizona [W:6 L:1 T:0]
Team: Denver [W:6 L:1 T:0]
Total winning teams: 2

Menu options:
1)Search team by name
2)List all team data
3)Display winning team data
4)Display amount of winning teams
9)Quit
Select an option (1,2,3,4,9): 4
Team: Arizona
Stats [W:6 L:1 T:0]
Team: Baltimore
Stats [W:5 L:3 T:0]
Team: Buffalo
Stats [W:5 L:3 T:0]
Team: Cincinnati
Stats [W:4 L:2 T:1]
Team: Cleveland
Stats [W:4 L:3 T:0]
Team: Dallas
Stats [W:6 L:2 T:0]
Team: Denver
Stats [W:6 L:1 T:0]
Team: Detroit
Stats [W:6 L:2 T:0]
Team: Green Bay
Stats [W:5 L:3 T:0]
Team: Indianapolis
Stats [W:5 L:3 T:0]
Team: Kansas City
Stats [W:4 L:3 T:0]
Team: Miami
Stats [W:4 L:3 T:0]
Team: New England
Stats [W:6 L:2 T:0]
Team: Philadelphia
Stats [W:5 L:2 T:0]
Team: Pittsburgh
Stats [W:5 L:3 T:0]
Team: San Diego
Stats [W:5 L:3 T:0]
Team: San Francisco
Stats [W:4 L:3 T:0]
Team: Seattle
Stats [W:4 L:3 T:0]

Total winning teams: 18

Menu options:
1)Search team by name
2)List all team data
3)Display winning team data
4)Display amount of winning teams
9)Quit
Select an option (1,2,3,4,9): 9
Program quit by user.

These results were provided by Dom!
Press any key to continue . . .

Process returned 0 (0x0)   execution time : 13.949 s
Press any key to continue.

*/
