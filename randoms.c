/*
 * =====================================================================================
 *
 *       Assignment:  Homework #1 - part B
 *
 *    Description:  A program in C which generates a sequence of random numbers. Provide command line options to specify the number of these to produce as well as the range into which each falls. (The default is 10 numbers, each in the inclusive range 1 to 100.)
 *
 *        Version:  1.0
 *        Created:  09/20/2016 07:46:36 AM
 *            Due:  09/23/2016 11:59:59 PM
 *       Compiler:  gcc
 *
 *         Author:  Justin McQuaid (jtetra5), jmcquaid@oswego.edu
 *   Organization:  State University of New York at Oswego
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<ctype.h>
#include	<string.h>
#include	<time.h>
 
/*
 * @char *			program
 * @description 	consists of the first command line argument, the name of the program itself.
 */
static char *program;

/* @prototype		randoms
 * @description 	prototype for the 'randoms' function 
 */
void randoms(int, int, int);

/* 
 * @function	main
 * @purpose		Begins main program execution.
 * @description Will produce a sequence of random numbers based on the command line options provided.  The default values display 10 numbers, ranging from 1 to 100.  The program name is copied into the 'program' variable.  The variable 'c' is then passed into the while loop logic, which will utilize the switch cases depending on the command line options given by the user.  The output given will be a sequence of randomly generated numbers, which will be quantified and binded by the upper and lower bounds set by the user, and well as the count.  If a user enters an incorrect option, they will be notified that '?' was reached, and the default count, lower, and upper will be displayed.  If an option is missing, the user will be notified.
 */
int main ( int argc, char *argv[] )
{
	int count = 10;
	int upper = 100;
	int lower = 0;
	int c = 0;
	char *options = ":l:u:n:";
	program = (char *)malloc(sizeof(char)*(strlen(argv[0])+1));
	strcpy(program, argv[0]);
	while((c = getopt(argc, argv, options)) != -1)	{
		if (c == '?')	{
			printf("%s\n", "c == '?' was reached");
			c = optopt;
		} else if (c == ':')	{
			c = optopt;
			printf("missing value for option %c\n", c);
		}
		else {
			switch (c)	{
				case 'l':
					lower = atoi(optarg);
					break;
				case 'u':
					upper = atoi(optarg);
					break;
				case 'n':
					count = atoi(optarg);
					break;
			}
	
		}				
	}

	randoms(lower, upper, count);
	return EXIT_SUCCESS;
}		/* ----- end of function main ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  randoms
 *  Description:  This function takes three integers as parameters, the lower bound, the upper bound, and the count.  A NULL value is seeded by the 'srand' function, and then a for loop iterates through the random integers.
 * =====================================================================================
 */

void randoms (int l, int u, int n)
{
	unsigned int random;
	srand(time(NULL));
	for (int i = 0; i < n; i++)	{
		random = rand() % u + l;
		printf("%u\n", random);
	}
	return;
}/* -----  end of function randoms  ----- */

