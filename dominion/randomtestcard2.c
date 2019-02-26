/* CS362 - Assignment 3 - randomtestcard2.c
 *	Random testing of the village card implementation
 *
 *	Author:		Kyle Johson
 *	Due:			02/10/2019
 *
 *
 *
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

	//if( TESTING ) { printf( "TESTING CARD: village\n" ); }

	for( i = 0; i < NUM_TESTS; i++ ) {

		// Get a random number of players between 2 and MAX_PLAYERS
		numPlayers = myRand( 2, MAX_PLAYERS );
		
		// Initialize the game
		initializeGame( numPlayers, k, seed, &G );

		// Iterate over all players
		for( j = 0; j < numPlayers; j++ ) {
		
			// Set player's turn
			G.whoseTurn = j;


