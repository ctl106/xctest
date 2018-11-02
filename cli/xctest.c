#include <stddef.h>

#include "xcstatus.h"
#include "xcstring.h"

#include "xctest.h"


struct _xctest {
	xcstring	*unit;
	xcstring	*name;
	int			number;	// negative indicates unset value

	xcstatus	status;
	int			error;	// should use errno values?
};


/*	constructors and desctructors	*/

void xctest_destroy(xctest *test)
{
	if(test == NULL)
		return;

	xcstring_destroy(test->unit);
	xcstring_destroy(test->name);
	free(test);
}

xctest *xctest_init()
{
	xctest *test = malloc(sizeof(xctest));

	test->unit = NULL;
	test->name = NULL;
	test->number = -1;

	test->status = xc_unrun;
	test->error = 0;

	return test;
}


/*	control	*/

void	xctest_run(xctest *test);

