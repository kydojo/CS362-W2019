/* CS362 - Assignment 4 - randomtestadventurer.c
 *	Random testing of the adventurer card implementation
 *
 *	Author:		Kyle Johson
 *	Due:			02/27/2019
 */

#include "dominion.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
	int numPlayers;
	int p1 = 0;
	int p2 = 1;
	int r, i, j;
	int cardDrawn1, cardDrawn2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState origState;
	struct gameState newState;
	int passCount = 0, failCount = 0;

	//if( TESTING ) { printf( "TESTING CARD: adventurer\n" ); }


	// Iterate NUM_TESTS times
	for( i = 0; i < NUM_TESTS; i++ ) {

		// Get a random number of players between 2 and MAX_PLAYERS
		numPlayers = myRand( 2, MAX_PLAYERS );

		// Initialize the game
		initializeGame( numPlayers, k, seed, &newState );
		
		// Iterate over all players
		for( j = 0; j < numPlayers; j++ ) {
			origState.whoseTurn = j;
			
			// Store a copy of the game state
			memcpy( &origState, &newState, sizeof( struct gameState ) );

			// Call cardEffect on adventurer
			cardEffect( adventurer, 0, 0, 0, &newState, 0, 0 );

			// *** Test that hand count increases by 2 ***
			if( TESTING ) { 
				//printf( "\t\tPlayer Gains 2 Cards" );
				if( newState.handCount[p1] == origState.handCount[p1] + 2 ) {
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
					failCount++;
				}
			}

			// *** Test that deck count decreases by 2 ***
			if( TESTING ) { 
				//printf( "\t\tDeck Loses 2 Cards" );
				if( newState.handCount[p1] == origState.handCount[p1] - 2 ) {
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
					failCount++;
				}
			}

			// *** Test that the cards added to the player's hand are treasure cards ***
			cardDrawn1 = newState.hand[p1][newState.handCount[p1]-1];
			cardDrawn2 = newState.hand[p1][newState.handCount[p1]-2];

			if( TESTING ) {
				//printf( "\t\tTreasure Cards Gained" );
				if( ( cardDrawn1 == copper || cardDrawn1 == silver ||  cardDrawn1 == gold ) &&
					 ( cardDrawn2 == copper || cardDrawn2 == silver ||  cardDrawn2 == gold ) ) {	
					//printf("\t\tPASS\n");
					passCount++;
				}
				else {
					//printf("\t\tFAIL\n");		
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
