#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#if __linux__
	#include <linux/limits.h>
	#define XC_PATH_MAX	PATH_MAX
#else // The correct OS value isn't critical, so just use any reasonable value
	#define XC_PATH_MAX 260
#endif // operating system detect


#include "xcstring.h"


#ifndef XC_STRING_SIZE
	#define	XC_STRING_SIZE XC_PATH_MAX
#endif // XC_STRING_SIZE


/*	utilities	*/
static int	resize(xcstring *str, size_t cnt);	// cnt is target length


struct _xcstring {
    size_t	length;
    size_t	size;
    char	*buffer;
};


/*	constructors and desctructors	*/

void xcstring_destroy(xcstring *str)
{
	if (str == NULL)
		return;

	free(str->buffer);
	free(str);
}

xcstring *xcstring_init()
{
	xcstring *str = malloc(sizeof(xcstring));
	str->length = 0;
	str->size = 0;
	str->buffer = NULL;
	return str;
}

xcstring *xcstring_init_c(const char *source)
{
	xcstring *str = xcstring_init();
	xcstring_cat_c(str, source);
	return str;
}

xcstring *xcstring_init_str(xcstring source)
{
	xcstring *str = xcstring_init();
	xcstring_cat_str(str, source);
	return str;
}


/*	retrievers	*/

const char	*xcstring_cstr(xcstring *str)
{
	return (const char*)(str->buffer);
}


/*	modifiers	*/

xcstring *xcstring_cat_c(xcstring *dest, const char *source)
{
	size_t cnt = strlen(source);
	return xcstring_ncat_c(dest, source, cnt);
}

xcstring *xcstring_cat_str(xcstring *dest, const xcstring source)
{
	return xcstring_ncat_str(dest, source, source.length);
}

xcstring *xcstring_ncat_c(xcstring *dest, const char *source, size_t cnt)
{
	xcstring *output = NULL;

	if (strlen(source) < cnt)	// sometimes results in a smaller realloc
		cnt = strlen(source);

	size_t new_length = dest->length + cnt;

	if (!resize(dest, new_length)) {
		strncat(dest->buffer, source, cnt);
		dest->length = new_length;
		output = dest;
	}

	return output;
}

xcstring *xcstring_ncat_str(xcstring *dest, const xcstring source, size_t cnt)
{
	return xcstring_ncat_c(dest, source.buffer, cnt);
}


/*	utilities	*/

static int resize(xcstring *str, size_t cnt)
{
	int output = 0;

	size_t new_size = 0;
	while(new_size < cnt)
		new_size += XC_STRING_SIZE;

	if (new_size != str->size) {
		char *new_buffer = realloc(str->buffer, new_size);
		if(new_buffer) {
			str->buffer = new_buffer;
			str->size = new_size;
		} else
			output = 1;
	}

	return output;
}

