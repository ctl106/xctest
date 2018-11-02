#ifndef XCSUITE_H_INCLUDED
#define XCSUITE_H_INCLUDED


#include "xctest.h"


typedef struct	_xcsuite	xcsuite;

/*	constructors and destructors	*/
void	xcsuite_destroy(xcsuite *suite);
xcsuite	*xcsuite_init();

/* control	*/
void	xcsuite_run(xcsuite *suite);
void	xcsuite_run_par(xcsuite *suite);
void	xcsuite_run_seq(xcsuite *suite);

/*	accessors	*/
xctest	*xcsuite_find(xcsuite *suite, size_t n);

/*	modifiers	*/
int		xcsuite_append(xcsuite *suite, xctest *test);
xcsuite	*xcsuite_cat(xcsuite *dest, const xcsuite source);


#endif // XCSUITE_H_INCLUDED
