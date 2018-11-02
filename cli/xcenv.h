#ifndef XCENV_H_INCLUDED
#define XCENV_H_INCLUDED


typedef enum _xclod {
	xc_quite,
	xc_normal,
	xc_verbose
} xclod;

typedef struct _xcenv xcenv;

/*	constructors and destructors	*/
void	xcenv_destroy(xcenv *env);
xcenv	*xcenv_init();
xcenv	*xcenv_init_arg(int argc, char *argv[]);


#endif // XCENV_H_INCLUDED
