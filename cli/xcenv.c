#include <stdio.h>

#include "xcstring.h"

#include "xcenv.h"


struct _xcenv {
	FILE		*out;	// redirect stdout of unit to out
	xcstring	*unit;
	xclod		lod;	// level of detail of output
};


void xcenv_destroy(xcenv *env)
{
	if(env->out != stdout && env->out != stderr)
		fclose(env->out);

	xcstring_destroy(env->unit);

	free(env);
}

xcenv *xcenv_init()
{
	xcenv *env = malloc(sizeof(xcenv));
	env->out = NULL;
	env->unit = NULL;
	env->lod = xc_normal;
	return env;
}

xcenv *xcenv_init_arg(int argc, char *argv[])
{
	xcenv *env;

	if(argc <= 1)
		env = NULL;

	else {
		env = xcenv_init();

		// set env based on cli flags
		env->unit = xcstring_init_c(argv[1]);
	}

	return env;
}
