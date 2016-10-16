/*
 * =====================================================================================
 *
 *       Assignment: Homework #1 - part A
 *
 *    Description:  Use C code to write a function (a part of an API) with the signature char **getPermutations(char *), which, when given a string, returns all the permutations of the input string.
 *
 *    Write a driver program which, when given a string on the command line, uses the above function to get and print all the permutations of the string. 
 *
 *        Version:  1.0
 *        Created:  09/06/2016 03:42:16 PM
 *            Due:	09/23/2016 11:59:59 PM
 *       Compiler:  gcc
 *
 *         Author:  Justin G. McQuaid (jtetra5), jmcquaid@mcquaidcoding.com
 *   Organization:  State University of New York at Oswego
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

// prototypes
char **getPermutations(char *);
void swap (char *, int, int);
size_t factorial (char *);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Begins main program execution.  This is the driver that takes the command line argument and makes a call to the 'getPermutations' function to generate the permutations.
 * =====================================================================================
 */

int main ( int argc, char *argv[] )
{
	// array of pointers which will contain all the permutations
	char **permutations;

	// the amount of permutations
	size_t n = factorial(argv[1]);

	// call to 'getPermutations' functions
	permutations = getPermutations(argv[1]);

	// for loop to print the permutations
	for (int i = 0; i < n; i++)	{
		printf("%s\n", permutations[i]);
		free(permutations[i]);
	}

	// frees the memory allocated for 'permutations'
	free(permutations);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getPermutations
 *  Description:  This function takes a command line argument and generates all permutations of said argument
 * =====================================================================================
 */

char **getPermutations ( char *ptr )
{
  	char *str;

	// allocate memory for 'str' that is the size of the parameter 'ptr'
	str = malloc(sizeof(char) * (strlen(ptr) + 1));

	// copy 'ptr' into 'str'
	strcpy (str, ptr);
	
	// the amount of letters in the command line argument
	size_t columns = strlen(str);

	// the amount of rows/permutations
	size_t rows = factorial(str);
	char **per;

	// for loop counter which indicates the element of 'per'
	int i = 0;

	// allocate memory for 'per'
    per = malloc(sizeof(char *) * rows);

	// This algorithm conducts the production of permutations, beginning with the innermost loop, which occurs if y does not equal z and y plus 1 equals z.  In terms of array indexes, the swapping occurs in '0-1,1-2, 2-3, etc.' format.  The outermost loop determines when the amount of permutations has been successfully produced, thus ending the iterations.
	for (int x = 0; x < rows / (columns - 1); x++)	{
		for (int y = 0; y < columns; y++)	{ 
			for (int z = 1; z < columns; z++)	{
				if (y != z && y + 1 == z)	{

					// allocate memory for per[i]
					per[i] = malloc(sizeof(char) * (strlen(str) + 1));

					// copy 'str' into 'per[i]
					strcpy(per[i], str);

					// swap the index y and z of str
					swap(str, y, z);
					i++;
				}
			}	
		}
	}
			
	// free the memory allocated for 'str'
	free(str);

	return per;
}	
	/* -----  end of function getPermutations  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  swap
 *  Description:  This function takes in a char pointer, an int, and another int.  The integer parameters indicate array indexes.  The return is void.
 * =====================================================================================
 */
	
void swap (char *str, int a, int b)
{
	char c;
	c = str[a];
	str[a] = str[b];
	str[b] = c;
}		/* -----  end of function Swap  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  factorial
 *  Description:  This function takes in a char pointer and returns the factorial of type size_t.
 * =====================================================================================
 */
	
size_t factorial (char *ptr )
{
	char *str;

	// allocates memory for 'str'
	str = malloc(sizeof(char) * (strlen(ptr) + 1));

	// copies 'ptr' into 'str'
	strcpy(str, ptr);

	// stores the size of the string
	size_t string = strlen(str);
	
	// factorial variable
	size_t factorial = 1;

	// for loop which applies 'n!' to 'factorial'
	for (size_t i = string; i >= 1; i--)	{
		factorial *= i;
	}

	//frees the memory allocated for 'str'
	free(str);
	return factorial;
}		/* -----  end of function factorial  ----- */
