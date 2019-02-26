/* CS362 - Assignment 3 - randomtestcard1.c
 *	Random testing of the smithy card implementation
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
	int r, i;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	//if( TESTING ) { printf( "TESTING CARD: smithy\n" ); }

	for( i = 0; i < NUM_TESTS; i++ ) {

		initializeGame( numPlayers, k, seed, &G );

		// Test that hand count increases by 3 when smithy is played
	
		// Set player's turn to player 1
		//G.whoseTurn = 0;

		// Set the player's hand size to 1 card
		G.handCount[0] = 1;

		// Call cardEffect on smithy
		cardEffect( smithy, 0, 0, 0, &G, 4, 0 );

		//printf( "Hand Size: %d\n", numHandCards( &G ) );
		if( TESTING ) { 
			printf( "\t\t+3 Cards" );
			if( numHandCards( &G ) == 3 ) {
				printf("\t\t\tPASS\n");
			}
			else {
				printf("\t\t\tFAIL\n");
