/* CS362 - Assignment 3 - unittest2.c
 *	Unit test for numHandCards function
 *
 *	Author:		Kyle Johson
 *	Due:			02/10/2019
 */

#include "dominion.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// Set TESTING to 0 to remove print statements from console output
#define TESTING 1

int main() {
	
	int seed = 1000;
	int numPlayer = 2;
	int r, i;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	if( TESTING ) { printf( "TESTING FUNCTION: numHandCards()\n" ); }

	initializeGame( numPlayer, k, seed, &G );

	// Set hand count to zero (empty)
 	G.handCount[whoseTurn( &G )] = 0;

	if( TESTING ) { 
		printf( "\t\tHand Count = 0" );
		if( numHandCards( &G ) == 0 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 1
 	G.handCount[whoseTurn (&G )] = 1;

	if( TESTING ) { 
		printf( "\t\tHand Count = 1" );
		if( numHandCards( &G ) == 1 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 2
	G.handCount[whoseTurn( &G )] = 2;

	if( TESTING ) { 
		printf( "\t\tHand Count = 2" );
		if( numHandCards( &G ) == 2 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 3
	G.handCount[whoseTurn( &G )] = 3;

	if( TESTING ) { 
		printf( "\t\tHand Count = 3" );
		if( numHandCards( &G ) == 3 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 4
	G.handCount[whoseTurn( &G )] = 4;

	if( TESTING ) { 
		printf( "\t\tHand Count = 4" );
		if( numHandCards( &G ) == 4 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 5
	G.handCount[whoseTurn( &G )] = 5;

	if( TESTING ) { 
		printf( "\t\tHand Count = 5" );
		if( numHandCards( &G ) == 5 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 6
	G.handCount[whoseTurn( &G )] = 6;

	if( TESTING ) { 
		printf( "\t\tHand Count = 6" );
		if( numHandCards( &G ) == 6 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	// Set hand count to 7
	G.handCount[whoseTurn( &G )] = 7;

	if( TESTING ) { 
		printf( "\t\tHand Count = 7" );
		if( numHandCards( &G ) == 7 ) {
			printf("\t\t\tPASS\n");
		}
		else {
			printf("\t\t\tFAIL\n");
		}
	}

	return 0;
}
