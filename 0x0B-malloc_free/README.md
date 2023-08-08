Hy, I'm glad that you made it here. You are absolutely at the right place. As we are going to look out for Recursions in C programming. feel confortable it was made easy to look through.

You have to remember that my codes for every project at low level programming repo, uses Betty style in each line of codes and usually uses
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 for compilation process.

No more than 5 functions per file, no printf or puts. Instead I use putchar.

No printf, puts, calloc, realloc.

Now let's look what made this thing

	1. Write a function that creates an array of chars, and initializes it with a specific char.

		* Prototype: char *create_array(unsigned int size, char c);
		* Returns NULL if size = 0
		* Returns a pointer to the array, or NULL if it fails

	2. Write a function that returns a pointer to a newly allocated space in memory, which contains 
		a copy of the string given as a parameter.

		* Prototype: char *_strdup(char *str);
		* The _strdup() function returns a pointer to a new string which is a duplicate of the 
			string str. Memory for the new string is obtained with malloc, and can be freed with free.
		* Returns NULL if str = NULL
		* On success, the _strdup function returns a pointer to the duplicated string. 
			It returns NULL if insufficient memory was available


	3. Write a function that concatenates two strings.

		* Prototype: char *str_concat(char *s1, char *s2);
		* The returned pointer should point to a newly allocated space in memory which contains the contents of s1, 
			followed by the contents of s2, and null terminated
		* if NULL is passed, treat it as an empty string
		* The function should return NULL on failure


	4. Write a function that returns a pointer to a 2 dimensional array of integers.

		* Prototype: int **alloc_grid(int width, int height);
		* Each element of the grid should be initialized to 0
		* The function should return NULL on failure
		* If width or height is 0 or negative, return NULL

	5. Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.

		* Prototype: void free_grid(int **grid, int height);
		* Note that we will compile with your alloc_grid.c file. Make sure it compiles.



		You can find me on the other social media:

		Linkedin: https://www.linkedin.com/in/aphrodis-uwineza-961079281/
		Twitter: https://twitter.com/AphrodisGarrix
		Instagram: https://www.instagram.com/aphrodisgarrix/


Don't hesitate to reach out to me. formally or informally.
