#include <errno.h>
#include <stdio.h>

#include "xctest_common.h"

#include "cli/xcenv.h"
#include "cli/xcsuite.h"
#include "cli/xctest.h"


void	collect_tests(xcenv *env, xcsuite *suite);
void	display_results(xcenv *env, xcsuite *suite);
void	display_test(xcenv *env, xctest *test);
void	run_tests(xcenv *env, xcsuite *suite);


int main(int argc, char *argv[])
{
	xcenv *env = xcenv_init_arg(argc, argv);

	xcsuite *suite = xcsuite_init();
	collect_tests(env, suite);

	run_tests(env, suite);
	display_results(env, suite);

	xcsuite_destroy(suite);
	xcenv_destroy(env);
}


void collect_tests(xcenv *env, xcsuite *suite)
{
	return;
}

void	display_results(xcenv *env, xcsuite *suite)
{
	return;
}

void	display_test(xcenv *env, xctest *test)
{
	return;
}

void	run_tests(xcenv *env, xcsuite *suite)
{
	return;
}

