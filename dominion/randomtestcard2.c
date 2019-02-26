/* CS362 - Assignment 4 - randomtestcard2.c
 *	Random testing of the village card implementation
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
	struct gameState origState;
	struct gameState newState;
	//if( TESTING ) { printf( "TESTING CARD: village\n" ); }

	for( i = 0; i < NUM_TESTS; i++ ) {

		// Get a random number of players between 2 and MAX_PLAYERS
		numPlayers = myRand( 2, MAX_PLAYERS );
		
		// Initialize the game
		initializeGame( numPlayers, k, seed, &newState );

		// Iterate over all players
		for( j = 0; j < numPlayers; j++ ) {
		
			// Set player's turn
			newState.whoseTurn = j;
			
			// Store a copy of the game state
			memcpy( &origState, &newState, sizeof( struct gameState ) );
	
			// Call cardEffect on village
			cardEffect( village, 0, 0, 0, &newState, 0, 0 );

			// *** Test that hand count increases by 1 ***
			if( TESTING ) { 
				//printf( "\t\tPlayer Gains 1 Card" );
				if( newState.handCount[j] == origState.handCount[j] + 1 ) {
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
					failCount++;
				}
			}
	
			// *** Test that deck count decreases by 1 ***
			if( TESTING ) { 
				//printf( "\t\tDeck Loses 1 Card" );
				if( newState.deckCount[j] == origState.deckCount[j] - 1 ) {
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
					failCount++;
				}
			}

			// *** Test that the player's actions increase by 2 ***
			if( TESTING ) { 
				//printf( "\t\tPlayer Gains 2 Actions" );
				if( newState.numActions == origState.numActions + 2 ) {
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
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

