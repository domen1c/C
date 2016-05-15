///  Project 6 - COP2220 - Domenic Mangani 11/28/14 - menuOne.c

#include "menuOne.h"

// display menuOne for user to select data viewing options
// no parameters, returns an integer containing user input.
int printMenuOne ( void )
{
    int valid = 0, input;

    while ( valid == 0 )
    {
        printf ( "\nMenu One:\n1) List all stadiums\n2) Search stadiums by name\n"
                 "3) Search stadiums by state\n4) Search for stadiums over capacity\n"
                 "5) Sort stadium data by name\n6) Sort stadium data by capacity\n"
                 "9) Main Menu\nSelect (1-6, or 9): " );
        scanf ( "%i", &input );
        if ( (input >= 1 && input <= 6) || input == 9)
        {
            valid = 1;
        }
        else
            printf ( "Invalid! Please try again.\n" );
    }

    return input;
}

// how to pass different structures to same function? (stadium_t and temp_t)
void printOneStadium ( stadium_t stadArray[], int elements )
{
    printf ( "Name: %s\nTeam: %s\nTurf: %s\nRoof: %s\nCapacity/Extended: %i/%i\n"
             "Opened: %i in %s, %s-%s\n", stadArray[elements].name,
             stadArray[elements].team, stadArray[elements].turf, stadArray[elements].roof,
             stadArray[elements].capacity, stadArray[elements].expCapacity, stadArray[elements].opened,
             stadArray[elements].city, stadArray[elements].stateFull, stadArray[elements].state );
}

void printAllStadiums ( stadium_t stadArray[], int elements )
{
    int count = 0, index;

    printf ( "\nDisplaying all stadium data:\n" );
    for ( index = 0; index < elements; index++ )
    {
        printOneStadium( stadArray, elements );
        count++;
    }
    printf ( "\nTotal stadiums printed: %i\n\n", count );
}

void printOverCapacity ( stadium_t stadArray[], int elements )
{
    int count = 0, index;
    printf ( "\nSearching stadiums over capacity:\n\n" );
    for ( index = 0; index < elements; index++ )
    {
        if ( stadArray[index].capacity > stadArray[index].expCapacity )
        {
            printOneStadium( stadArray, index );
            count++;
        }
    }
    printf ( "Total stadiums printed: %i\n\n", count );
}

// change an array's index to lowercase for case-insensitive search
// no return, and has one string array parameter.
void lowStr( char *str )
{
    char *str2;

    for (str2 = str; *str2 != '\0'; str2++)
        *str2 = (char) tolower(*str2);
}

// change an array's index to uppercase for case-insensitive search
// no return, and has one string array parameter.
void upStr( char *str )
{
    char *str2;

    for (str2 = str; *str2 != '\0'; str2++)
        *str2 = (char) toupper(*str2);
}

int compare_name( const void *x, const void *y )
{
    return ( strcmp( ((stadium_t * )x)->name, ((stadium_t * )y)->name ));
}

int compare_capacity( const void *x, const void *y )
{
    if ( ((stadium_t * )x)->capacity < ( (stadium_t * )y)->capacity )
        return -1;
    else if ( ((stadium_t *)x)->capacity > ((stadium_t *)y)->capacity )
        return 1;
    else
        return 0;
}
