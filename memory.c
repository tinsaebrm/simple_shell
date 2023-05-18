#include "shell.h"
#include <stdio.h>
/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 *
 * Name of contributor: Akoh inmiogbegbile
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		printf("Pointer successfully freed and set to NULL.\n");
		return (1);
	}
	printf("Pointer is NULL, cannot free.\n");
	return (0);
}
