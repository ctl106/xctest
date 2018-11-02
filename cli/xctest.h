#ifndef XCTEST_H_INCLUDED
#define XCTEST_H_INCLUDED


typedef struct _xctest xctest;

/*	constructors and desctructors	*/
void	xctest_destroy(xctest *test);
xctest	*xctest_init();

/*	control	*/
void	xctest_run(xctest *test);


#endif // XCTEST_H_INCLUDED
