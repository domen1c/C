//Project 3 for COP2220
//Domenic Mangani
//10/27/14

// declare library, constant, and prototypes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 11

void greetingsEarthlings( void );
void displayCurrent( int *ticketPtr, int *pricePtr );
void closeOut( int *ticketPtr, int *pricePtr );
char looper( void );
char confirmation( void );
char getColor( char *colorPtr );
char getType( void );
int getAmount( char tempType );
int confirmPurchase( char tempColor, char tempType, int tempAmount,
                     int *todayPtr, int *groupPtr, int *singlePtr);
int main ( void )
{
    // declare and initialize local array
    char color[MAX_ELEMENTS] = { 'M', 'R', 'O', 'Y', 'L', 'G', 'T', 'B', 'N', 'P', 'K' };
    int today[MAX_ELEMENTS] = { 130, 120, 115, 105, 93, 83, 77, 70, 65, 60, 50 };
    int group[MAX_ELEMENTS] = { 125, 115, 95, 90, 75, 70, 65, 60, 55, 50, 40 };
    int single[MAX_ELEMENTS] = { 125, 127, 110, 100, 88, 78, 72, 65, 60, 55, 45 };

    // declare and initialize local variables
    char runAgain, tempColor, tempType;
    int mainLoop = 0, tempAmount = 0, subTotal = 0, totalTickets = 0, totalPrice = 0;

    // welcome user
    greetingsEarthlings();

    while ( mainLoop == 0 )
    {
        runAgain = looper();
        if ( runAgain == 'Y' )
        {
            tempColor = getColor( color );
            if ( tempColor != 'Q' )
            {
                tempType = getType();
                tempAmount = getAmount( tempType );
                subTotal = confirmPurchase( tempColor, tempType, tempAmount,
                                            today, group, single );
                if ( subTotal != 0 )
                {
                    totalPrice += subTotal;
                    totalTickets += tempAmount;
                    displayCurrent( &totalTickets, &totalPrice );
                }
                else
                    printf ( "Purchase canceled, returning to main menu.\n\n" );
            }
            else
                mainLoop = 1;
        }
        else if ( runAgain == 'N' )
        {
            mainLoop = 1;
        }
    }// end mainLoop

    printf ( "\nTicket Novice closed by user.\n" );
    closeOut( &totalTickets, &totalPrice );

    system( "PAUSE" );
    return;
}// end main

//----- function list -----//

// welcome message
void greetingsEarthlings ( void )
{
    printf ( "Welcome to Ticket Novice, where coupons are not excepted!\n");
}

// display current totals with pointers ( no return value )
void displayCurrent( int *ticketPtr, int *pricePtr )
{
    printf ( "\nCurrent tickets purchased: %i\nCurrent price total: $%i\n\n", *ticketPtr, *pricePtr );
}

// display final totals for tickets and revenue with pointers ( no return value )
void closeOut( int *ticketPtr, int *pricePtr )
{
    printf ( "\nTotal tickets purchased: %i\nTotal revenue generated: $%i\n"
             "\nThese results were brought to you by Dom!\n", *ticketPtr, *pricePtr);
}

// request user confirmation to proceed with main ticket menu ( no parameters, returning char )
char looper( void )
{
    int valid = 0;
    char tempRun;

    while ( valid == 0 )
    {
        printf ( "Would you like to purchase tickets? (Y/N): " );
        scanf ( "\n%c", &tempRun );
        tempRun = toupper( tempRun );

        if ( tempRun == 'Y' || tempRun == 'N' )
        {
            valid = 1;
            return tempRun;
        }
        else
        {
            printf ( "\nInvalid selection. Please try again.\n" );
        }
    }
    return;
}// end confirmLoop Function

// request user confirmation to proceed with ticket purchase ( no parameters, returning char )
char confirmation( void )
{
    int valid = 0;
    char tempRun;

    while ( valid == 0 )
    {
        printf ( "Confirm current purchase? (Y/N): " );
        scanf ( "\n%c", &tempRun );
        tempRun = toupper( tempRun );

        if ( tempRun == 'Y' || tempRun == 'N' )
        {
            valid = 1;
            return tempRun;
        }
        else
        {
            printf ( "\nInvalid selection. Please try again.\n" );
        }
    }
    return;
}// end confirmation Function

// request user input on ticket color ( char color array, returning char )
char getColor ( char *colorPtr )
{
    char tempColor, *cPtr;
    cPtr = colorPtr;

    while ( cPtr )
    {
        printf( "Ticket color selection:\nM)Maroon\nR)Red\nO)Orange\nY)Yellow"
                "\nL)Light Green\nG)Dark Green\nT)Teal\nB)Blue\nN)Navy\nP)Purple"
                "\nK)Pink\nQ)Quit\nPlease select ticket color, or Q to quit: " );
        scanf ( "\n%c", &tempColor );
        tempColor = toupper( tempColor );

        if ( strchr ( cPtr, tempColor ) )
        {
            return tempColor;
        }
        else if ( tempColor == 'Q' )
        {
            return tempColor;
        }
        else
        {
            printf ( "\nInvalid selection. Please try again.\n\n" );
        }
    }// end while
    return;
}// end getColor function */

// request user input on ticket type ( no parameters, returning char )
char getType ( void )
{
    char tempType;
    int valid = 0;

    while ( valid == 0 )
    {
        printf( "\nTypes of tickets available:\nG)Group\nS)Single\n"
                "D)Game Day\nPlease select ticket type (G,S,D) ");
        scanf ( "\n%c", &tempType );
        tempType = toupper ( tempType );

        if ( tempType == 'G' || tempType == 'S' || tempType == 'D' )
        {
            valid = 1;
            return tempType;
        }
        else
        {
            printf ( "\nInvalid selection! Please try again.\n" );
        }
    }
    return;
}//end getType function

// request user input on ticket amount ( char variable, returning int )
int getAmount ( char tempType )
{
    int tempAmount, valid = 0;

    while ( valid == 0 )
    {
        if ( tempType == 'G' )
        {
            printf( "\nNotice! Group tickets have a minimum purchase of 10!\n"
                    "How many group tickets would you like? (10-99): " );
            scanf ( "\n%i", &tempAmount );
            if ( tempAmount >= 10 && tempAmount <= 99 )
            {
                valid = 1;
                return tempAmount;
            }
            else
            {
                printf ( "\nInvalid selection! Please try again.\n" );
            }
        }
        else if ( tempType == 'S' || tempType == 'D')
        {
            printf( "How many single tickets would you like? (1-99): " );
            scanf ( "\n%i", &tempAmount );
            if ( tempAmount >= 1 && tempAmount <= 99 )
            {
                valid = 1;
                return tempAmount;
            }
            else
            {
                printf ( "\nInvalid selection! Please try again.\n" );
            }
        }
    }// end while loop
    return;
}// end getAmount function

// display current order and request user confirmation of purchase
// ( ticketColor, ticketType, ticketAmount, pricing array pointers )
int confirmPurchase ( char tempColor, char tempType, int tempAmount,
                      int *todayPtr, int *groupPtr, int *singlePtr )
{
    int tempTotal, valid = 0;
    char tempConfirm;

    while ( valid == 0 )
    {
        if ( tempColor == 'M' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[0];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[0], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[0];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[0], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[0];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[0], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Maroon ticket
        else if ( tempColor == 'R' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[1];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[1], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[1];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[1], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[1];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[1], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Red ticket
        else if ( tempColor == 'O' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[2];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[2], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[2];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[2], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[2];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[2], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Orange ticket
        else if ( tempColor == 'Y' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[3];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[3], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[3];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[3], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[3];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[3], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Yellow ticket
        else if ( tempColor == 'L' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[4];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[4], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[4];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[4], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[4];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[4], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Light green ticket
        else if ( tempColor == 'G' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[5];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[5], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[5];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[5], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[5];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[5], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Dark green ticket
        else if ( tempColor == 'T' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[6];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[6], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[6];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[6], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[6];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[6], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Teal ticket
        else if ( tempColor == 'B' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[7];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[7], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[7];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[7], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[7];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[7], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Blue ticket
        else if ( tempColor == 'N' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[8];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[8], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[8];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[8], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[8];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[8], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Navy ticket
        else if ( tempColor == 'P' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[9];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[9], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[9];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[9], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[9];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[9], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Purple ticket
        else if ( tempColor == 'K' )
        {
            switch ( tempType )
            {
            case 'G' :
                tempTotal = tempAmount * groupPtr[10];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, groupPtr[10], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'S' :
                tempTotal = tempAmount * singlePtr[10];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, singlePtr[10], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            case 'D' :
                tempTotal = tempAmount * todayPtr[10];
                printf( "\nYou have selected the following:\nTicket color: %c\nTicket type: %c\n"
                        "Ticket cost: $%i\nTicket amount: %i\nSubtotal for purchase: $%i\n\n",
                        tempColor, tempType, todayPtr[10], tempAmount, tempTotal);

                tempConfirm = confirmation();
                if ( tempConfirm == 'Y')
                    return tempTotal;
                else
                    return 0;
                break;

            default :
                break;
            }
        }// end Pink ticket
    }// end while
    return;
}// end function

//----- test data -----//

/** Test Run #1
20 Pink Group, 10 Blue Game Day, 5 Navy Single, 10 Yellow Game Day
Total tickets purchased: 45
Total revenue generated: $2700

Welcome to Ticket Novice!
Where coupons are not excepted.
Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: y

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 10

You have selected the following:
Ticket color: Y
Ticket type: G
Ticket cost: $90
Ticket amount: 10
Subtotal for purchase: $900

Confirm current purchase? (Y/N): y

Current tickets purchased: 10
Current price total: $900

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: n

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) s
How many single tickets would you like? (1-99): 5

You have selected the following:
Ticket color: N
Ticket type: S
Ticket cost: $60
Ticket amount: 5
Subtotal for purchase: $300

Confirm current purchase? (Y/N): y

Current tickets purchased: 15
Current price total: $1200

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: b

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) d
How many game day tickets would you like? (1-99): 10

You have selected the following:
Ticket color: B
Ticket type: D
Ticket cost: $70
Ticket amount: 10
Subtotal for purchase: $700

Confirm current purchase? (Y/N): y

Current tickets purchased: 25
Current price total: $1900

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: k

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 20

You have selected the following:
Ticket color: K
Ticket type: G
Ticket cost: $40
Ticket amount: 20
Subtotal for purchase: $800

Confirm current purchase? (Y/N): y

Current tickets purchased: 45
Current price total: $2700

Would you like to purchase tickets? (Y/N): n

Ticket Novice closed by user.

Total tickets purchased: 45
Total revenue generated: $2700

These results were brought to you by Dom!
Press any key to continue . . .

End Test Run #1 */

/* Test Run #2
10 Maroon Group, 8 Navy Single, 3 Yellow Game Day, 11 Pink Group,
10 Dark green Single, 8 Maroon Game day
Total tickets purchased: 50
Total revenue generated: $4305

Welcome to Ticket Novice!
Where coupons are not excepted.
Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: s

Invalid selection. Please try again.

Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: m

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 1

Invalid selection! Please try again.

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 10

You have selected the following:
Ticket color: M
Ticket type: G
Ticket cost: $125
Ticket amount: 10
Subtotal for purchase: $1250

Confirm current purchase? (Y/N): y

Current tickets purchased: 10
Current price total: $1250

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: n

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) s
How many single tickets would you like? (1-99): 8

You have selected the following:
Ticket color: N
Ticket type: S
Ticket cost: $60
Ticket amount: 8
Subtotal for purchase: $480

Confirm current purchase? (Y/N): y

Current tickets purchased: 18
Current price total: $1730

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: y

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) d
How many game day tickets would you like? (1-99): 3

You have selected the following:
Ticket color: Y
Ticket type: D
Ticket cost: $105
Ticket amount: 3
Subtotal for purchase: $315

Confirm current purchase? (Y/N): y

Current tickets purchased: 21
Current price total: $2045

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: k

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 11

You have selected the following:
Ticket color: K
Ticket type: G
Ticket cost: $40
Ticket amount: 11
Subtotal for purchase: $440

Confirm current purchase? (Y/N): y

Current tickets purchased: 32
Current price total: $2485

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: g

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) s
How many single tickets would you like? (1-99): 10

You have selected the following:
Ticket color: G
Ticket type: S
Ticket cost: $78
Ticket amount: 10
Subtotal for purchase: $780

Confirm current purchase? (Y/N): y

Current tickets purchased: 42
Current price total: $3265

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: m

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) d
How many game day tickets would you like? (1-99): 8

You have selected the following:
Ticket color: M
Ticket type: D
Ticket cost: $130
Ticket amount: 8
Subtotal for purchase: $1040

Confirm current purchase? (Y/N): y

Current tickets purchased: 50
Current price total: $4305

Would you like to purchase tickets? (Y/N): n

Ticket Novice closed by user.

Total tickets purchased: 50
Total revenue generated: $4305

These results were brought to you by Dom!
Press any key to continue . . .

End Test Run #2 */

/** Test Run #3
15 Blue Single, 20 Red Group, 50 Pink Game Day, 10 Maroon Group
Total tickets purchased: 95
Total revenue generated: $7025

Welcome to Ticket Novice!
Where coupons are not excepted.
Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: b

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) s
How many single tickets would you like? (1-99): 15

You have selected the following:
Ticket color: B
Ticket type: S
Ticket cost: $65
Ticket amount: 15
Subtotal for purchase: $975

Confirm current purchase? (Y/N): y

Current tickets purchased: 15
Current price total: $975

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: r

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 7

Invalid selection! Please try again.

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 20

You have selected the following:
Ticket color: R
Ticket type: G
Ticket cost: $115
Ticket amount: 20
Subtotal for purchase: $2300

Confirm current purchase? (Y/N): y

Current tickets purchased: 35
Current price total: $3275

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: k

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) d
How many game day tickets would you like? (1-99): 50

You have selected the following:
Ticket color: K
Ticket type: D
Ticket cost: $50
Ticket amount: 50
Subtotal for purchase: $2500

Confirm current purchase? (Y/N): y

Current tickets purchased: 85
Current price total: $5775

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: m

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 10

You have selected the following:
Ticket color: M
Ticket type: G
Ticket cost: $125
Ticket amount: 10
Subtotal for purchase: $1250

Confirm current purchase? (Y/N): y

Current tickets purchased: 95
Current price total: $7025

Would you like to purchase tickets? (Y/N): n

Ticket Novice closed by user.

Total tickets purchased: 95
Total revenue generated: $7025

These results were brought to you by Dom!
Press any key to continue . . .
End Test Run #3 */

/* Test Run #4
10 Maroon Group, 20 Red Group, 20 Blue Group, 99 Teal Game day
Total tickets purchased: 149
Total revenue generated: $12373

Welcome to Ticket Novice!
Where coupons are not excepted.
Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: m

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 10

You have selected the following:
Ticket color: M
Ticket type: G
Ticket cost: $125
Ticket amount: 10
Subtotal for purchase: $1250

Confirm current purchase? (Y/N): y

Current tickets purchased: 10
Current price total: $1250

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: r

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 20

You have selected the following:
Ticket color: R
Ticket type: G
Ticket cost: $115
Ticket amount: 20
Subtotal for purchase: $2300

Confirm current purchase? (Y/N): y

Current tickets purchased: 30
Current price total: $3550

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: b

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) g

Notice! Group tickets have a minimum purchase of 10!
How many group tickets would you like? (10-99): 20

You have selected the following:
Ticket color: B
Ticket type: G
Ticket cost: $60
Ticket amount: 20
Subtotal for purchase: $1200

Confirm current purchase? (Y/N): y

Current tickets purchased: 50
Current price total: $4750

Would you like to purchase tickets? (Y/N): y
Ticket color selection:
M)Maroon
R)Red
O)Orange
Y)Yellow
L)Light Green
G)Dark Green
T)Teal
B)Blue
N)Navy
P)Purple
K)Pink
Q)Quit
Please select ticket color, or Q to quit: t

Types of tickets available:
G)Group
S)Single
D)Game Day
Please select ticket type (G,S,D) d
How many game day tickets would you like? (1-99): 99

You have selected the following:
Ticket color: T
Ticket type: D
Ticket cost: $77
Ticket amount: 99
Subtotal for purchase: $7623

Confirm current purchase? (Y/N): y

Current tickets purchased: 149
Current price total: $12373

Would you like to purchase tickets? (Y/N): n

Ticket Novice closed by user.

Total tickets purchased: 149
Total revenue generated: $12373

These results were brought to you by Dom!
Press any key to continue . . .

End Test Run #4 */

