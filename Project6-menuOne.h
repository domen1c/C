///  Project 6 - COP2220 - Domenic Mangani 11/28/14 - menuOne.h

#ifndef MENUONE_H_INCLUDED
#define MENUONE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define MAX_ELEMENTS 50
#define LEN_LINE 200
#define LEN_NAME 200

typedef struct
{
    char name[LEN_NAME];
    char turf[LEN_NAME];
    char roof[LEN_NAME];
    char team[LEN_NAME];
    char city[LEN_NAME];
    char stateFull[LEN_NAME];
    char state[3];
    int capacity;
    int expCapacity;
    int opened;
}stadium_t;

typedef struct
{
    char name[LEN_NAME];
    char turf[LEN_NAME];
    char roof[LEN_NAME];
    char team[LEN_NAME];
    char city[LEN_NAME];
    char stateFull[LEN_NAME];
    char state[3];
    int capacity;
    int expCapacity;
    int opened;
}temp_t;

int printMenuOne ( void );
void printOneStadium ( stadium_t stadArray[], int elements );
void printAllStadiums ( stadium_t stadArray[], int elements );
void printOverCapacity ( stadium_t stadArray[], int elements );
void lowStr( char *str );
void upStr( char *str );
int compare_name( const void *x, const void *y );
int compare_capacity( const void *x, const void *y );

#endif // MENUONE_H_INCLUDED
