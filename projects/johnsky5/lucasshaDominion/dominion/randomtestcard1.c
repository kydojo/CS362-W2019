/* CS362 - Assignment 4 - randomtestcard1.c
 *	Random testing of the smithy card implementation
 *
 *	Author:		Kyle Johson
 *	Due:			02/27/2019
 */

#include "dominion.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// Set TESTING to 0 to remove print statements from console output
#define TESTING 1
#define NUM_TESTS 10000

// Helper function to return a random number with the range of the two arguments
int myRand( int low, int high ) {
	return ( rand() % (high - low + 1) + low );
}

int main() {
	
	int seed = 1000;
	int numPlayers = 2;
	int r, i, j;
	int passCount = 0, failCount = 0;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	//if( TESTING ) { printf( "TESTING CARD: smithy\n" ); }

	for( i = 0; i < NUM_TESTS; i++ ) {

		// Get a random number of players between 2 and MAX_PLAYERS
		numPlayers = myRand( 2, MAX_PLAYERS );
		
		// Initialize the game
		initializeGame( numPlayers, k, seed, &G );

		// Iterate over all players
		for( j = 0; j < numPlayers; j++ ) {
		
			// Set player's turn
			G.whoseTurn = j;

			// Set the player's hand size to 1 card
			G.handCount[0] = 1;

			// Call cardEffect on smithy
			cardEffect( smithy, 0, 0, 0, &G, 4, 0 );

			//printf( "Hand Size: %d\n", numHandCards( &G ) );
			if( TESTING ) { 
				//printf( "\t\t+3 Cards" );
				if( numHandCards( &G ) == 3 ) {
					//printf("\t\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\t\tFAIL\n");
					failCount++;
				}
			}
		}
	}

	printf("Iterations:\t\t%d\n", NUM_TESTS);
	printf("Tests passed:\t%d\n", passCount);
	printf("Tests failed:\t%d\n\n", failCount);
	printf("NOTE: Tests expected to fail, as bug was introduced\nto this card implementation in Assignment 2.\n\n");

	return 0;
}
