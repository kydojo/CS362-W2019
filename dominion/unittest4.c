/* CS362 - Assignment 3 - unittest4.c
 *	Unit test for whoseTurn function
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

	if( TESTING ) { printf( "TESTING FUNCTION: whoseTurn()\n" ); }

	r = initializeGame( numPlayer, k, seed, &G );

	// Set the game state to player 1's turn (zero-based)
 	G.whoseTurn = 0;

	if( TESTING ) { 
		printf( "\t\tPlayer One's Turn" );
		if( whoseTurn( &G ) == 0 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game state to player 2's turn (zero-based)
 	G.whoseTurn = 1;

	if( TESTING ) { 
		printf( "\t\tPlayer Two's Turn" );
		if( whoseTurn( &G ) == 1 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	return 0;
}
