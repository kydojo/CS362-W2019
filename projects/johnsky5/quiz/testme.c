/* CS362 - Random Tester
 * 
 * Author: 	Kyle Johnson
 * Due:		02/10/2019
 * Descr:	The function testme() was given. The task was to, first,
 * 			understand testme(), and then to write the functions
 * 			inputChar() and inputString() in such a way that they
 * 			would sufficiently, randomly test testme()'s functionality.
 * 			The test should complete within 5 minutes (this test 
 * 			finishes in under 1 second).
 * 			The randomization within each function was adapted from
 * 			an online post (the URL is below).
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Adapted from: https://stackoverflow.com/questions/19724346/generate-random-characters-in-c
char inputChar()
{
    return "[{( ax)}]"[rand() % 9];
	 //return ch;
}

// Adapted from: https://stackoverflow.com/questions/19724346/generate-random-characters-in-c
char *inputString()
{
    static char str[6];
	 int i;
	 for( i = 0; i < 5; i++ ) {
		str[i] = "rest"[rand() % 5];
	 }
	 str[5] = '\0';
	 return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}