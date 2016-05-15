// Program:	Project 2
// Author:		DM
// Course:		COP2220

// library and constants
#include <stdio.h>
#define TOUCH_DOWN 6
#define EXTRA_POINT 1
#define TWO_POINT 2
#define FIELD_GOAL 3
#define SAFETY 2

void greetings (void);
void printPlay (char teamTemp, int homeTemp, int awayTemp);
void printWinner (int homeWin, int awayWin, int playCount);
char getTeam (void);
int getPlay (char team);
int getScore (char scoreTeam, char scoreType);

int main (void)
{
    //local variables
    char teamSelect, scoreSelect;
    int mainLoop = 0, nestedLoop = 0, count = 0;
    int awayScore = 0, homeScore = 0, homePoint = 0, awayPoint = 0;

    //welcome
    greetings();

    while (mainLoop == 0)
    {
        while (nestedLoop == 0)
        {
            //input team
            teamSelect = getTeam();
            if (teamSelect == 'H')
            {
                homePoint = getPlay(teamSelect);
                switch (homePoint)
                {
                case 'E' :
                    getScore(teamSelect, homePoint);
                    homeScore += EXTRA_POINT;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'S' :
                    getScore(teamSelect, homePoint);
                    homeScore += SAFETY;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'F' :
                    getScore(teamSelect, homePoint);
                    homeScore += FIELD_GOAL;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'T' :
                    getScore(teamSelect, homePoint);
                    homeScore += TOUCH_DOWN;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'C' :
                    getScore(teamSelect, homePoint);
                    homeScore += TWO_POINT;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                }//end homePoint switch
            }//end 'H' if/else
            else if (teamSelect == 'A')
            {
                awayPoint = getPlay(teamSelect);
                switch (awayPoint)
                {
                case 'E' :
                    getScore(teamSelect, awayPoint);
                    awayScore += EXTRA_POINT;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'S' :
                    getScore(teamSelect, awayPoint);
                    awayScore += SAFETY;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'F' :
                    getScore(teamSelect, awayPoint);
                    awayScore += FIELD_GOAL;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'T' :
                    getScore(teamSelect, awayPoint);
                    awayScore += TOUCH_DOWN;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                case 'C' :
                    getScore(teamSelect, awayPoint);
                    awayScore += TWO_POINT;
                    printPlay(teamSelect, homeScore, awayScore);
                    break;
                }//end awayPoint switch
            }//end 'A' if/else
            else if (teamSelect == 'Q')
            {
                printWinner(homeScore, awayScore, count);
                printf ("\nThanks for playing! Results provided by Dom.\n");
                mainLoop = 1;
                break;
            }//end 'Q' if/else
            else
            {
                printf ("\nError! Invalid selection. Try again.\n");
            }
        count++;//play counter
        }//end nestedLoop
    }//end mainLoop

}//end main function

void greetings()
{
    printf ( "Welcome to Dom's Football Scoring!\n" );
}

//get user input for team variable and validate it.
char getTeam()
{
    char teamChoice;
    int teamValid = 0;
    while (teamValid == 0)
    {
        printf ("Select team 'H' for Home, 'A' for Away, or 'Q' to quit: ");
        scanf ( "\n%c", &teamChoice);
        teamChoice = toupper(teamChoice);
        if (teamChoice == 'H' || 'A' || 'Q')
        {
            teamValid = 1;
            if (teamChoice == 'H')
            {
                printf("\nH) Home team selected:\n");
            }
            else if (teamChoice == 'A')
            {
                printf("\nA) Away team selected:\n");
            }
            else
            {
                return teamChoice;
            }
        }
        else
        {
            printf ("\nError! Invalid team selection. Try again.\n");
        }
    }//end teamValid loop
    return teamChoice;
}//end getTeam

//get user input for score type and validate it.
int getPlay(char team)
{
    char tempScore = 0;
    int tempValid = 0;
    printf ("E) Extra Point (1 point)\nS) Safety (2 points)\nF) Field Goal (3 points)\nT) Touch Down (6 points)\nC) Two-Point conversion (2 points)\nSelect score type (E,S,F,T,C): " );
    scanf ("\n%c", &tempScore );
    tempScore = toupper(tempScore);
    if ((tempScore == 'E') || (tempScore == 'S') || (tempScore == 'F') || (tempScore == 'T') || (tempScore == 'C'))
    {
        tempValid = 1;
    }
    else
    {
        printf ("\nError! Invalid score selection. Try again.\n");
    }
    return tempScore;
}//end getPlay

//function to return number of points based on play type
int getScore(char scoreTeam, char scoreType)
{
    if (scoreTeam == 'H')
    {
        switch (scoreType)
        {
        case 'E' :
            printf ( "\n1 point added to the Home team's score.\n" );
            return 1;
            break;
        case 'S' :
            printf ( "\n2 points added to the Home team's score.\n" );
            return 2;
            break;
        case 'F' :
            printf ( "\n3 points added to the Home team's score.\n" );
            return 3;
            break;
        case 'T' :
            printf ( "\n6 points added to the Home team's score.\n" );
            return 6;
            break;
        case 'C' :
            printf ( "\n2 points added to the Home team's score.\n" );
            return 2;
            break;
        }//end case
    }//end if team == 'H'
    else if (scoreTeam == 'A')
    {
        switch (scoreType)
        {
        case 'E' :
            printf ("\n1 point added to the Away team's score.\n");
            return 1;
            break;
        case 'S' :
            printf ( "\n2 points added to the Away team's score.\n" );
            return 2;
            break;
        case 'F' :
            printf ( "\n3 points added to the Away team's score.\n" );
            return 3;
            break;
        case 'T' :
            printf ( "\n6 points added to the Away team's score.\n" );
            return 6;
            break;
        case 'C' :
            printf ( "\n2 points added to the Away team's score.\n" );
            return 2;
            break;
        }//end switch
    }//end if
    scoreTeam = 0, scoreType = 0;
}//end setScore function

//display current score and which team is leading
void printPlay (char teamTemp, int homeTemp, int awayTemp)
{
    if ((teamTemp == 'H') && (homeTemp > awayTemp))
    {
        printf ( "\nCurrent score:\nHome: %i\nAway: %i\nLeading: H\n\n", homeTemp, awayTemp, teamTemp);
    }
    else if ((teamTemp == 'H') && (awayTemp > homeTemp))
    {
        printf ( "\nCurrent score:\nHome: %i\nAway: %i\nLeading: A\n\n", homeTemp, awayTemp, teamTemp);
    }
    else if ((teamTemp == 'A') && (homeTemp > awayTemp))
    {
        printf ( "\nCurrent score:\nHome: %i\nAway: %i\nLeading: H\n\n", homeTemp, awayTemp, teamTemp);
    }
    else if ((teamTemp == 'A') && (awayTemp > homeTemp))
    {
        printf ( "\nCurrent score:\nHome: %i\nAway: %i\nLeading: A\n\n", homeTemp, awayTemp, teamTemp);
    }
    else
    {
        printf ( "\nCurrent score:\nHome: %i\nAway: %i\nGame is all tied up!\n\n", homeTemp, awayTemp);
    }
}//end printPlay

//display winner
void printWinner(int homeWin, int awayWin, int playCount)
{
    char winner;
    if (homeWin > awayWin)
    {
        winner = 'H';
        printf ("\nGame Over!\nTotal plays: %i\nFinal score...\nHome: %i\nAway: %i\nWinner: %c\n", playCount, homeWin, awayWin, winner);
    }
    else if (homeWin < awayWin)
    {
        winner = 'A';
        printf ("\nGame Over!\nTotal plays: %i\nFinal score...\nHome: %i\nAway: %i\nWinner: %c\n", playCount, homeWin, awayWin, winner);
    }
    else
    {
        printf ("\nGame Over! Total plays: %i\nHome: %i\nAway: %i\nWinner: Draw\n", playCount, homeWin, awayWin);
    }
}//end getWinner


/* TEST DATA

Test Run #1
Sample data:
    Home team scores 2 touch downs, and 1 field goal for 15 points.
    Away team scores 1 touch down, 2 field goals, 1 extra point, and 1 safety for 15 points.
    Game ends in a draw.

Welcome to Dom's Football Scoring!
Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 6
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Away team's score.

Current score:
Home: 6
Away: 6
Game is all tied up!

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 12
Away: 6
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Away team's score.

Current score:
Home: 12
Away: 9
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Home team's score.

Current score:
Home: 15
Away: 9
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Away team's score.

Current score:
Home: 15
Away: 12
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): e

1 point added to the Away team's score.

Current score:
Home: 15
Away: 13
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): s

2 points added to the Away team's score.

Current score:
Home: 15
Away: 15
Game is all tied up!

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: q

Game Over! Total plays: 8
Home: 15
Away: 15
Winner: Draw

Thanks for playing! Results provided by Dom.

Process returned 0 (0x0)   execution time : 52.042 s
Press any key to continue.

Test Run #2
Sample Data:
    Home team scores 1 touch down, 1 extra point, and 1 field goal for 10 points.
    Away team scores 1 touch down, 1 two-point conversion, 2 field goals, and 1 safety for 16 points.

Welcome to Dom's Football Scoring!
Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 6
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): e

1 point added to the Home team's score.

Current score:
Home: 7
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Away team's score.

Current score:
Home: 7
Away: 6
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): c

2 points added to the Away team's score.

Current score:
Home: 7
Away: 8
Leading: A

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Home team's score.

Current score:
Home: 10
Away: 8
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Away team's score.

Current score:
Home: 10
Away: 11
Leading: A

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Away team's score.

Current score:
Home: 10
Away: 14
Leading: A

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): s

2 points added to the Away team's score.

Current score:
Home: 10
Away: 16
Leading: A

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: q

Game Over!
Total plays: 8
Final score...
Home: 10
Away: 16
Winner: A

Thanks for playing! Results provided by Dom.

Process returned 0 (0x0)   execution time : 64.052 s
Press any key to continue.


Test Run #3
Sample Data:
    Home team scores 3 touch downs, 2 extra points, 1 two-point conversion and 1 field goal for 25 points.
    Away team scores 1 touch down, 1 two-point conversion, and 1 safety for 10 points.

Welcome to Dom's Football Scoring!
Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 6
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): e

1 point added to the Home team's score.

Current score:
Home: 7
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 13
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): e

1 point added to the Home team's score.

Current score:
Home: 14
Away: 0
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Away team's score.

Current score:
Home: 14
Away: 6
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): c

2 points added to the Away team's score.

Current score:
Home: 14
Away: 8
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): t

6 points added to the Home team's score.

Current score:
Home: 20
Away: 8
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): c

2 points added to the Home team's score.

Current score:
Home: 22
Away: 8
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: a

A) Away team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): s

2 points added to the Away team's score.

Current score:
Home: 22
Away: 10
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: h

H) Home team selected:
E) Extra Point (1 point)
S) Safety (2 points)
F) Field Goal (3 points)
T) Touch Down (6 points)
C) Two-Point conversion (2 points)
Select score type (E,S,F,T,C): f

3 points added to the Home team's score.

Current score:
Home: 25
Away: 10
Leading: H

Select team 'H' for Home, 'A' for Away, or 'Q' to quit: q

Game Over!
Total plays: 10
Final score...
Home: 25
Away: 10
Winner: H

Thanks for playing! Results provided by Dom.

Process returned 0 (0x0)   execution time : 56.401 s
Press any key to continue.

*/
