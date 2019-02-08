/* CS362 - Assignment 3 - unittest3.c
 *	Unit test for supplyCount function
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
	int r, i;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	if( TESTING ) { printf( "TESTING FUNCTION: supplyCount()\n" ); }

	r = initializeGame( numPlayer, k, seed, &G );

	// Test province pile checking functionality for an empty province pile
	//if( TESTING ) { printf( "\tProvince Pile Checking:\n" ); }

	// Set the game's adventurer supply count
 	G.supplyCount[adventurer] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Adventurer" );
		if( supplyCount( adventurer, &G ) == 10 ) {
			printf("\tPASS\n");
		}
		else {
			printf("\tFAIL\n");
		}
	}

	// Set the game's council_room supply count
 	G.supplyCount[council_room] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Council Room" );
		if( supplyCount( council_room, &G ) == 10 ) {
			printf("\tPASS\n");
		}
		else {
			printf("\tFAIL\n");
		}
	}

	// Set the game's feast supply count
 	G.supplyCount[feast] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Feast" );
		if( supplyCount( feast, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's gardens supply count
 	G.supplyCount[gardens] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Gardens" );
		if( supplyCount( gardens, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's mine supply count
 	G.supplyCount[mine] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Mine" );
		if( supplyCount( mine, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's remodel supply count
 	G.supplyCount[remodel] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Remodel" );
		if( supplyCount( remodel, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's smithy supply count
 	G.supplyCount[smithy] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Smithy" );
		if( supplyCount( smithy, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's village supply count
 	G.supplyCount[village] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Village" );
		if( supplyCount( village, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's baron supply count
 	G.supplyCount[baron] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Baron" );
		if( supplyCount( baron, &G ) == 10 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Set the game's great hall supply count
 	G.supplyCount[great_hall] = 10;

	// Test the supplyCount function
	if( TESTING ) { 
		printf( "\t\tSupply Count: Great Hall" );
		if( supplyCount( great_hall, &G ) == 10 ) {
			printf("\tPASS\n");
		}
		else {
			printf("\tFAIL\n");
		}
	}

	return 0;
}
