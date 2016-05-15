/*
Project 5 for COP2220
Domenic Mangani
11-12-14
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 50
#define LEN_NAME 100

int displayMenu ( void );
int getYear ( void );
int computeOldest ( int years[], int elements );
int computeNewest ( int *yearsPtr, int elements );
void lowStr( char *str );
void upStr( char *str );
void printArray ( char names[], char city[],
                  char state[], int *yearsPtr );
//void printArray ( char *namesPtr, char *cityPtr,
//                   char *statePtr, int *yearsPtr );

int main ( void )
{
    FILE *fp;
    int fileCount = 0, index, mainLoop = 0, menuChoice,
        tempYear, tempCount = 0, valid = 0;
    int years[MAX_ELEMENTS] = { 0 };
    char names[MAX_ELEMENTS][LEN_NAME] = { 0 };
    char namesLow[MAX_ELEMENTS][LEN_NAME] = { 0 };
    char city[MAX_ELEMENTS][LEN_NAME] = { 0 };
    char state[MAX_ELEMENTS][3] = { 0 };
    char line[LEN_NAME], response[LEN_NAME], tempState[0][2];
    char *startPtr, *endPtr;

    startPtr = line;
    endPtr = strchr (line, '|');

    fp = fopen ( "NFLStadiums.txt", "r" );
    if ( NULL == fp )
    {
        printf ( "Unable to open file." );
    }
    else
    {
        index = 0;
        while ( fgets( line, sizeof(line), fp ) && index < MAX_ELEMENTS )
        {
            startPtr = line;
            endPtr = strchr( startPtr, '|' );
            strncpy( names[index], startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy( city[index], startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy( state[index], startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            years[index] = atoi ( startPtr );

            index++;
        }
        fclose ( fp );
        fileCount = index;
    }

    // copy names array into temp array and format for case-insensitive search
    for ( index = 0; index < fileCount; index++ )
    {
        strcpy( namesLow[index], names[index] );
        lowStr( namesLow[index] );
    }

    // welcome user and display oldest / newest stadium data
    printf ( "Welcome to NFLStadiums.txt Data File!\n\n* Did you know?\n"
             "* The oldest stadium in this file was built in %i,\n"
             "* and the newest stadium was built in %i.\n\n",
             computeOldest( years, fileCount ), computeNewest( years, fileCount ));

    while ( mainLoop == 0 )
    {
        index = 0;
        tempCount = 0;
        menuChoice = displayMenu();
        if ( menuChoice == 1 )
        {
            printf ( "\nStadium / Location / Year Built\n\n" );
            for ( index = 0; index < fileCount; index++ )
            {
                printArray( names[index], city[index], state[index], years + index );
                tempCount++;
            }
            printf ( "\nTotal items printed: %i\n\n", tempCount );
        }
        else if ( menuChoice == 2 )
        {
            tempYear = getYear();
            printf ( "\nStadium(s) built after year: %i\n\n", tempYear );

            for ( index = 0; index < fileCount; index++ )
            {
                if ( years[index] > tempYear )
                {
                    printArray( names[index], city[index], state[index], years + index );
                    tempCount++;
                }
            }
            if ( tempCount == 0 )
            {
                printf ( "\nNo stadium(s) found. Please try again.\n\n" );
            }
            else
                printf ( "\nTotal items printed: %i\n\n", tempCount );
        }

        else if ( menuChoice == 3 )
        {
            printf ( "What state to search for? (Florida = FL): ");
            scanf ( "%s", tempState[0] );
            upStr(tempState[0]);

            while ( valid == 0 )
            {
                if ( strlen(tempState[0]) == 2 )
                {
                    valid = 1;
                }
                else
                {
                    printf ( "Invalid! Please try again.\n" );
                }
            }

            printf ( "\nStadium(s) built in state: %s\n", tempState[0] );

            for ( index = 0; index < fileCount; index++ )
            {
                if ( strcmp(state[index], tempState[0] ) == 0 )
                {
                    printArray( names[index], city[index], state[index], years + index );
                    tempCount++;
                }
            }
            if ( tempCount == 0 )
            {
                printf ( "\nNo stadium(s) found. Please try again.\n\n" );
            }
            else
                printf ( "\nTotal items printed: %i\n\n", tempCount );
        }

        else if ( menuChoice == 4 )
        {
            fflush( stdin );
            printf( "\nEnter stadium name, or part of it: " );
            fgets( response, sizeof(response), stdin );
            response[strlen(response) - 1] = '\0';
            lowStr( response );

            for ( index = 0; index < fileCount; index++ )
            {
                if ( strstr(namesLow[index], response) != NULL )
                {
                    printArray( names[index], city[index],
                                state[index], years + index );
                    tempCount++;
                }
            }
            if ( tempCount == 0 )
            {
                printf ( "\nNo stadium(s) found. Please try again.\n\n" );
            }
            else
                printf ( "\nTotal items printed: %i\n\n", tempCount );
        }
        else if ( menuChoice == 9 )
        {
            mainLoop = 1;
        }
    }
    printf ( "These results were provided by Dom.\n" );
    system( "PAUSE" );
    return 0;
}

// display menu and request user input with validation.
// returns user input 0-4, no parameters.
int displayMenu ( void )
{
    int check = 0, input = 0, valid = 0;

    while ( valid == 0 )
    {
        printf ( "Menu options:\n1)List all stadium data\n2)List stadiums built after specific year\n"
                 "3)List stadiums in specific state\n4)Search stadiums by name\n"
                 "9)Quit\nSelect an option (1,2,3,4,9): " );
        scanf ( "%i", &input );
        if ( input == 1 || input == 2 || input == 3 || input == 4 || input == 9 )
            valid = 1;
        else
            printf ( "\nInvalid selection. Please try again.\n" );
    }
    return input;
}

// request user input for stadium search by year built.
// returns the year by integer, no parameters.
int getYear ( void )
{
    int input, valid = 0;

    while ( valid == 0 )
    {
        printf ( "Input year (1900-2013): ");
        scanf( "%i", &input );

        if ( input >= 1900 && input <= 2013 )
            valid = 1;
        else
            printf ( "\nInvalid! Please try again.\n\n" );
    }
    return input;
}

// calculate oldest stadium built by array notation. return oldest by integer
// 2 parameters, int array pointer, and amount to search
int computeOldest ( int array[], int elements )
{
    int oldest, index = 0;
    oldest = array[0];

    for ( index = 0; index < elements; index++ )
    {
        if ( array[index] < oldest )
        {
            oldest = array[index];
        }
    }
    return oldest;
}

// calculate newest stadium built by pointer notation. return newest by integer
// 2 parameters, int array pointer, and amount to search
int computeNewest ( int *array, int elements )
{
    int newest, index = 0;
    newest = array[0];

    for ( index = 0; index < elements; index++ )
    {
        if ( array[index] > newest )
        {
            newest = array[index];
        }
    }
    return newest;
}

// display a specific index across parallel arrays using array/pointer notation. no return
// 4 parameters, 3 char arrays for stadium name, location, state, and 1 int for year built.
void printArray ( char *namesPtr, char *cityPtr, char *statePtr, int *yearsPtr )
{
    printf ( "%s / %s, %s / %i\n", namesPtr, cityPtr, statePtr, *yearsPtr );
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

/** Test Data

Welcome to NFLStadiums.txt Data File!

* Did you know?
* The oldest stadium in this file was built in 1924,
* and the newest stadium was built in 2014.

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 1

Stadium / Location / Year Built

Arrowhead Stadium / Kansas City, MO / 1972
AT&T Stadium / Arlington, TX / 2009
Bank of America Stadium / Charlotte, NC / 1996
CenturyLink Field / Seattle, WA / 2002
Edward Jones Dome / St. Louis, MO / 1995
EverBank Field / Jacksonville, FL / 1995
FedExField / Landover, MD / 1997
FirstEnergy Stadium / Cleveland, OH / 1999
Ford Field / Detroit, MI / 2002
Georgia Dome / Atlanta, GA / 1992
Gillette Stadium / Foxborough, MA / 2002
Heinz Field / Pittsburgh, PA / 2001
Lambeau Field / Green Bay, WI / 1957
Levi's Stadium / Santa Clara, CA / 2014
Lincoln Financial Field / Philadelphia, PA / 2003
LP Field / Nashville, TN / 1999
Lucas Oil Stadium / Indianapolis, IN / 2008
M&T Bank Stadium / Baltimore, MD / 1998
Mercedes-Benz Superdome / New Orleans, LA / 1975
MetLife Stadium / East Rutherford, NJ / 2010
NRG Stadium / Houston, TX / 2002
O.co Coliseum / Oakland, CA / 1966
Paul Brown Stadium / Cincinnati, OH / 2000
Qualcomm Stadium / San Diego, CA / 1967
Ralph Wilson Stadium / Orchard Park, NY / 1973
Raymond James Stadium / Tampa, FL / 1998
Soldier Field / Chicago, IL / 1924
Sports Authority Field at Mile High / Denver, CO / 2001
Sun Life Stadium / Miami Gardens, FL / 1987
TCF Bank Stadium / Minneapolis, MN / 2009
University of Phoenix Stadium / Glendale, AZ / 2006

Total items printed: 31

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 2
Input year (1900-2013): 2005

Stadium(s) built after year: 2005

AT&T Stadium / Arlington, TX / 2009
Levi's Stadium / Santa Clara, CA / 2014
Lucas Oil Stadium / Indianapolis, IN / 2008
MetLife Stadium / East Rutherford, NJ / 2010
TCF Bank Stadium / Minneapolis, MN / 2009
University of Phoenix Stadium / Glendale, AZ / 2006

Total items printed: 6

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 3
What state to search for? (Florida = FL): oh

Stadium(s) built in state: OH
FirstEnergy Stadium / Cleveland, OH / 1999
Paul Brown Stadium / Cincinnati, OH / 2000

Total items printed: 2

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 4

Enter stadium name, or part of it: dome
Edward Jones Dome / St. Louis, MO / 1995
Georgia Dome / Atlanta, GA / 1992
Mercedes-Benz Superdome / New Orleans, LA / 1975

Total items printed: 3

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 2
Input year (1900-2013): 1995

Stadium(s) built after year: 1995

AT&T Stadium / Arlington, TX / 2009
Bank of America Stadium / Charlotte, NC / 1996
CenturyLink Field / Seattle, WA / 2002
FedExField / Landover, MD / 1997
FirstEnergy Stadium / Cleveland, OH / 1999
Ford Field / Detroit, MI / 2002
Gillette Stadium / Foxborough, MA / 2002
Heinz Field / Pittsburgh, PA / 2001
Levi's Stadium / Santa Clara, CA / 2014
Lincoln Financial Field / Philadelphia, PA / 2003
LP Field / Nashville, TN / 1999
Lucas Oil Stadium / Indianapolis, IN / 2008
M&T Bank Stadium / Baltimore, MD / 1998
MetLife Stadium / East Rutherford, NJ / 2010
NRG Stadium / Houston, TX / 2002
Paul Brown Stadium / Cincinnati, OH / 2000
Raymond James Stadium / Tampa, FL / 1998
Sports Authority Field at Mile High / Denver, CO / 2001
TCF Bank Stadium / Minneapolis, MN / 2009
University of Phoenix Stadium / Glendale, AZ / 2006

Total items printed: 20

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 3
What state to search for? (Florida = FL): fL

Stadium(s) built in state: FL
EverBank Field / Jacksonville, FL / 1995
Raymond James Stadium / Tampa, FL / 1998
Sun Life Stadium / Miami Gardens, FL / 1987

Total items printed: 3

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 4

Enter stadium name, or part of it: stad
Arrowhead Stadium / Kansas City, MO / 1972
AT&T Stadium / Arlington, TX / 2009
Bank of America Stadium / Charlotte, NC / 1996
FirstEnergy Stadium / Cleveland, OH / 1999
Gillette Stadium / Foxborough, MA / 2002
Levi's Stadium / Santa Clara, CA / 2014
Lucas Oil Stadium / Indianapolis, IN / 2008
M&T Bank Stadium / Baltimore, MD / 1998
MetLife Stadium / East Rutherford, NJ / 2010
NRG Stadium / Houston, TX / 2002
Paul Brown Stadium / Cincinnati, OH / 2000
Qualcomm Stadium / San Diego, CA / 1967
Ralph Wilson Stadium / Orchard Park, NY / 1973
Raymond James Stadium / Tampa, FL / 1998
Sun Life Stadium / Miami Gardens, FL / 1987
TCF Bank Stadium / Minneapolis, MN / 2009
University of Phoenix Stadium / Glendale, AZ / 2006

Total items printed: 17

Menu options:
1)List all stadium data
2)List stadiums built after specific year
3)List stadiums in specific state
4)Search stadiums by name
9)Quit
Select an option (1,2,3,4,9): 9
These results were provided by Dom.
Press any key to continue . . .

*/

