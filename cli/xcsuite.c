#include <stddef.h>
#include <stdlib.h>

#include "xcsuite.h"


#ifndef XC_SUITE_SIZE
	#define	XC_SUITE_SIZE 10	// a rather arbitrary number, tbh
#endif // XC_STRING_SIZE


/*	utilities	*/
static int	resize(xcsuite *suite, size_t cnt);	// cnt is target length


struct _xcsuite {
	size_t	length;
	size_t	size;
	xctest	**tests;

	size_t	failures;
	size_t	passes;
	size_t	errors;
};


/*	constructors and destructors	*/

void xcsuite_destroy(xcsuite *suite)
{
	if (suite == NULL)
		return;

	int i;
	for (i = 0; i < suite->size; i++)
		xctest_destroy(xcsuite_find(suite, i));
	free(suite->tests);
	free(suite);
}


xcsuite	*xcsuite_init()
{
	xcsuite *suite = malloc(sizeof(xcsuite));

	suite->length = 0;
	suite->size = 0;
	suite->tests = NULL;

	suite->failures = 0;
	suite->passes = 0;
	suite->errors = 0;

	return suite;
}


/* control	*/

void	xcsuite_run(xcsuite *suite);
void	xcsuite_run_par(xcsuite *suite);
void	xcsuite_run_seq(xcsuite *suite);


/*	accessors	*/

xctest	*xcsuite_find(xcsuite *suite, size_t n)
{
	return suite->tests[n];
}


/*	modifiers	*/

int		xcsuite_append(xcsuite *suite, xctest *test);

xcsuite	*xcsuite_cat(xcsuite *dest, const xcsuite source);


/*	utilities	*/

static int resize(xcsuite *suite, size_t cnt)
{
	int output = 0;

	size_t new_size = 0;
	while(new_size < cnt)
		new_size += XC_SUITE_SIZE;

	if (new_size != suite->size) {
		xctest **new_tests = realloc(suite->tests, new_size);
		if(new_tests) {
			suite->tests = new_tests;
			suite->size = new_size;
		} else
			output = 1;
	}

	return output;
}

