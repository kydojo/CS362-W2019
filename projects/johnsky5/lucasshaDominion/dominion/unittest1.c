/* CS362 - Assignment 3 - unittest1.c
 *	Unit test for isGameOver function
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

	if( TESTING ) { printf( "TESTING FUNCTION: isGameOver()\n" ); }

	initializeGame( numPlayer, k, seed, &G );

	// Test province pile checking functionality for an empty province pile
	if( TESTING ) { printf( "\tProvince Pile Checking:\n" ); }

	// Set the province pile to 0 (empty)
 	G.supplyCount[province] = 0;

	if( TESTING ) { 
		printf( "\t\tProvince Pile Empty" );
		if( isGameOver( &G ) == 1 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Test province pile checking functionality for a non-empty province pile
	// Set the province pile to 1 (not empty)
 	G.supplyCount[province] = 1;

	// Set all supply piles to not be empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 1;
	}

	if( TESTING ) { 
		printf( "\t\tProvince Pile Not Empty" );
		if( isGameOver( &G ) == 0 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}


	// Test supply pile checking functionality (assumes province pile is not empty)
	// Province pile is non-empty
	printf("\n\tSupply Pile Checking (Assumes Province Pile Not Empty):\n");
	G.supplyCount[province] = 1;

	// No supply piles are empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 1;
	}

	if( TESTING ) { 
		printf( "\t\tSupply Piles Not Empty" );
		if( isGameOver( &G ) == 0 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// All supply piles are empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 0;
	}

	if( TESTING ) { 
		printf( "\t\tAll Supply Piles Empty" );
		if( isGameOver( &G ) == 1 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// One supply pile is empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 1;
	}
	G.supplyCount[12] = 0;

	if( TESTING ) { 
		printf( "\t\tOne Supply Pile Empty" );
		if( isGameOver( &G ) == 0 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Two supply piles are empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 1;
	}
	G.supplyCount[1] = 0;
	G.supplyCount[12] = 0;
	
	if( TESTING ) { 
		printf( "\t\tTwo Supply Piles Empty" );
		if( isGameOver( &G ) == 0 ) {
			printf("\t\tPASS\n");
		}
		else {
			printf("\t\tFAIL\n");
		}
	}

	// Three supply piles are empty
	for( i = 0; i < 25; i++ ) {
		G.supplyCount[i] = 1;
	}
	G.supplyCount[1] = 0;
	G.supplyCount[12] = 0;
	G.supplyCount[24] = 0;
	
	if( TESTING ) { 
		printf( "\t\tThree Supply Piles Empty" );
		if( isGameOver( &G ) == 1 ) {
			printf("\tPASS\n");
		}
		else {
			printf("\tFAIL\n");
		}
	}

	return 0;
}
