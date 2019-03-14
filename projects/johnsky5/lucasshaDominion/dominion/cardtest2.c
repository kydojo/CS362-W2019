/* CS362 - Assignment 3 - cardtest2.c
 *	Unit test for adventurer card
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

int main() {
	
	int seed = 1000;
	int numPlayer = 2;
	int p1 = 0;
	int p2 = 1;
	int r, i;
	int cardDrawn1, cardDrawn2;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState origState;
	struct gameState newState;

	if( TESTING ) { printf( "TESTING CARD: adventurer\n" ); }

	initializeGame( numPlayer, k, seed, &newState );
	
	// Set player's turn to player 1
	origState.whoseTurn = p1;

	// Store a copy of the game state
	memcpy( &origState, &newState, sizeof( struct gameState ) );
	
	// Call cardEffect on adventurer
	cardEffect( adventurer, 0, 0, 0, &newState, 0, 0 );

	// *** Test that hand count increases by 2 ***
	if( TESTING ) { 
		printf( "\t\tPlayer Gains 2 Cards" );
		if( newState.handCount[p1] == origState.handCount[p1] + 2 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
		}
	}

	// *** Test that deck count decreases by 2 ***
	if( TESTING ) { 
		printf( "\t\tDeck Loses 2 Cards" );
		if( newState.handCount[p1] == origState.handCount[p1] - 2 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");		// expected to fail because I introduced this bug in Assignment 2
		}
	}

	// *** Test that the cards added to the player's hand are treasure cards ***
	cardDrawn1 = newState.hand[p1][newState.handCount[p1]-1];
	cardDrawn2 = newState.hand[p1][newState.handCount[p1]-2];

	if( TESTING ) {
		printf( "\t\tTreasure Cards Gained" );
		if( ( cardDrawn1 == copper || cardDrawn1 == silver ||  cardDrawn1 == gold ) &&
			 ( cardDrawn2 == copper || cardDrawn2 == silver ||  cardDrawn2 == gold ) ) {	
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");		
		}
	}

	return 0;
}
