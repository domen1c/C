///  Project 6 - COP2220 - Domenic Mangani 11/28/14 - menuTwo.c

#include "menuOne.h"
#include "menuTwo.h"

// display menuTwo for user to select data viewing options
// no parameters, returns an integer containing user input.
int printMenuTwo ( void )
{
    int valid = 0, input;

    while ( valid == 0 )
    {
        printf ( "\nMenu Two:\n1) Edit stadium data\n"
                 "2) Add data for a new stadium\n"
                 "3) Delete a stadium\n4) Save modified list\n"
                 "9) Main Menu\nSelect (1-4, or 9): " );
        scanf ( "%i", &input );
        if ( (input >= 1 && input <= 4) || input == 9)
        {
            valid = 1;
        }
        else
            printf ( "Invalid! Please try again.\n" );
    }

    return input;
}

void modify( stadium_t* stadiums )
{
    int valid = 0, input;

    while ( valid == 0 )
    {
        printf ( "What stadium would you like to edit? (0-30): " );
        scanf ( "%i", &input );
        if ( input >= 0 && input <= 30 )
        {
            printf ( "Select data to edit:\n1)Name 2)Capacity" );
        }
        else
            printf ( "Invalid! Please try again.\n" );
    }

}

void save( stadium_t* stadiums, FILE* modified )
{
    int index;

    for ( index = 0; index < MAX_ELEMENTS; index++, stadiums++ )
    {
        fprintf ( modified, "%s|%d|%d|%s|%s|%s|%s|%s|%d|%s",
            stadiums->name, stadiums->capacity, stadiums->expCapacity,
            stadiums->city, stadiums->stateFull, stadiums->turf,
            stadiums->roof, stadiums->team, stadiums->opened,
            stadiums->state );
    }
    fclose( modified );
}
