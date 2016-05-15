///  Project 6 - COP2220 - Domenic Mangani 11/28/14 - main.c
/// stadium name | capacity | expCap | city | state (full) | turf | roof | team | opened

#include "menuOne.h"
#include "menuTwo.h"

int main ( void )
{
    FILE *fp, *modified;
    stadium_t stadiums[MAX_ELEMENTS];

    int count, fileCount, index, input, mainLoop = 0, menuChoice, valid = 0;
    char line[LEN_LINE], namesLow[MAX_ELEMENTS][LEN_NAME] = {{ 0 }},
    *startPtr, *endPtr, response[LEN_NAME] = { 0 }, tempState[3];

    fp = fopen ( "NFLStadiums2.txt", "r" );
    if ( NULL == fp )
        printf ( "Unable to open file." );
    else
    {
        index = 0;
        while ( fgets( line, sizeof(line), fp ) && index < MAX_ELEMENTS )
        {
            startPtr = strchr ( line, '\n' );
            if ( startPtr )
            {
                startPtr = '\0';
            }

            startPtr = line;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].name, startPtr, endPtr - startPtr );
// scan error somewhere between here -
            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            stadiums[index].capacity = atoi ( startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            stadiums[index].expCapacity = atoi ( startPtr );
/// ask how to handle the additional pipe in |St| Louis| (NFLStadium.txt line 5)
            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].city, startPtr, endPtr - startPtr );
// and here -
            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].stateFull, startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].turf, startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].roof, startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            strncpy ( stadiums[index].team, startPtr, endPtr - startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '|' );
            stadiums[index].opened = atoi ( startPtr );

            startPtr = endPtr + 1;
            endPtr = strchr( startPtr, '\0' );
            strcpy ( stadiums[index].state, startPtr);

            index++;
        }
        fclose ( fp );
        fileCount = index;
    }
    // copy stadium names into array to format for search
    for ( index = 0; index < fileCount; index++ )
    {
        strcpy( namesLow[index], stadiums[index].name );
        lowStr( namesLow[index] );
    }

    printf ( "Welcome to Project 6!\n" );
    while ( mainLoop == 0 )
    {
        count = 0, input = 0;
        printf ( "\nMain Menu:\n1) View/Sort stadium data\n2) Maintain stadium data\n"
                 "9) Exit\nPlease select (1, 2, or 9): " );
        scanf ( "%i", &input );
        if ( input == 1 || input == 2 || input == 9 )
        {
            if ( input == 1 )
            {
                menuChoice = printMenuOne();
                switch ( menuChoice )
                {
                case 1 : /// print all stadiums
                {
                    for ( index = 0; index < fileCount; index++ )
                    {
                        printOneStadium( stadiums, index );
                        count++;
                        if ( count == 10 )
                        {
                            printf ( "Pausing data list at count: %i\n", count );
                            system( "PAUSE" );
                        }
                    }
                    printf ( "\nTotal stadiums printed: %i\n\n", count );
                    break;
                }
                case 2 : /// search for stadiums by name
                {
                    fflush( stdin );
                    printf( "\nEnter stadium name, or part of it: " );
                    fgets( response, sizeof(response), stdin );
                    response[strlen(response) - 1] = '\0';
                    lowStr( response );
                    printf ( "\nSearching stadiums with string: %s\n", response );

                    for ( index = 0; index < fileCount; index++ )
                    {
                        if ( strstr(namesLow[index], response) != NULL )
                        {
                            printOneStadium( stadiums, index );
                            count++;
                        }
                    }
                    if ( count == 0 )
                    {
                        printf ( "\nNo stadium(s) found. Please try again.\n\n" );
                    }
                    else
                        printf ( "\nTotal stadium(s) printed: %i\n", count );
                    break;
                }
                case 3 : /// search for stadiums by state
                {
                    printf ( "What state to search for? (Florida = FL): ");
                    scanf ( "%s", tempState );
                    upStr(tempState);
                    printf ( "\nSearching stadiums with string: %s\n", tempState );
                    while ( valid == 0 )
                    {
                        if ( strlen(tempState) == 2 )
                            valid = 1;
                        else
                            printf ( "Invalid! Please try again.\n" );
                    }
                    for ( index = 0; index < fileCount; index++ )
                    {
                        if ( strncmp(stadiums[index].state, tempState, 2 ) == 0 )
                        {
                            printOneStadium( stadiums, index );
                            count++;
                        }
                    }
                    if ( count == 0 )
                        printf ( "\nNo stadium(s) found. Please try again.\n" );
                    else
                        printf ( "Total stadiums printed: %i\n", count );
                    break;
                }
                case 4 : /// print all stadiums over capacity
                    printOverCapacity ( stadiums, fileCount );
                    break;
                case 5 : /// sort data by stadium name
                    qsort (stadiums, fileCount, sizeof(stadium_t), compare_name );
                    for ( index = 0; index < fileCount; index++ )
                        printOneStadium( stadiums, index );
                    break;

                case 6 : /// sort data by capacity
                    qsort (stadiums, fileCount, sizeof(stadium_t), compare_capacity );
                    for ( index = 0; index < fileCount; index++ )
                        printOneStadium( stadiums, index );
                    break;
                default :
                    break;
                }
            }
            else if ( input == 2 )
            {
                menuChoice = printMenuTwo();
                switch ( menuChoice )
                {
                case 1 : /// Edit stadium data
                    printf ( "\nUnder construction.\n\n" );
                    break;
                case 2 : /// Add new stadium
                    printf ( "\nUnder construction.\n\n" );
                    break;
                case 3 : /// Delete a stadium
                    printf ( "\nUnder construction.\n\n" );
                    break;
                case 4 : /// Save modified data
                    //printf ( "\nUnder construction.\n\n" );
                    modified = fopen ( "Modified.txt", "w" );
                    if ( NULL == fp )
                        printf ( "Unable to open file." );
                    else
                    {
                        //for ( index = 0; index < sizeof(stadiums); index++ )
                        //{
                            save( stadiums, modified );
                        //}
                        printf ( "\nData file saved.\n" );

                    }
                    break;
                }
            }
            else if ( input == 9 )
            {
                mainLoop = 1;
            }
        }
        else
        {
            printf ( "Invalid! Please try again.\n\n" );
        }
    }
    printf ( "Program closed by user.\n" );
    system ( "PAUSE" );

    return 0;
}




