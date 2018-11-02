#ifndef XCSTRING_H_INCLUDED
#define XCSTRING_H_INCLUDED


typedef struct	_xcstring	xcstring;

/*	constructors and desctructors	*/
void		xcstring_destroy(xcstring *str);
xcstring	*xcstring_init();
xcstring	*xcstring_init_c(const char *source);
xcstring	*xcstring_init_str(xcstring source);

/*	accessor	*/
const char	*xcstring_cstr(xcstring *str);

/*	modifiers	*/
xcstring *xcstring_cat_c(xcstring *dest, const char *source);
xcstring *xcstring_cat_str(xcstring *dest, const xcstring source);
xcstring *xcstring_ncat_c(xcstring *dest, const char *source, size_t cnt);
xcstring *xcstring_ncat_str(xcstring *dest, const xcstring source, size_t cnt);


#endif // XCSTRING_H_INCLUDED
