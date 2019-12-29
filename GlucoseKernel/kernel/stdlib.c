#include <stdlib.h>

static int randseed = 7;
static int randlast = 1;

char itoan[16] = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F'
};
/*
double atof(const char *str)
{
    double ret = 0;
    return ret;
}
int atoi(const char *str)
{
    int ret = 0;
    
    return ret;
}
long int atol(const char *str)
{
    long int ret = 0;
    return ret;
}
double strtod(const char *str, char **endptr)
{
    double ret = 0;
    return ret;
}
long int strtol(const char *str, char **endptr, int base)
{
    long int ret = 0;
    return ret;
}
unsigned long int strtoul(const char *str, char **endptr, int base)
{
    unsigned long int ret = 0;
    return ret;
}
void *calloc(size_t nitems, size_t size)
{
    void* ret = 0;

    return ret;
}
void free(void *ptr)
{

}
void *malloc(size_t size)
{
    void* ret = 0;
    return ret;
}
void *realloc(void *ptr, size_t size)
{
    void* ret = 0;
    return ret;
}
*/
void abort(void)
{
    printf("Aborted!");
    for(;;);
}
/*
int atexit(void (*func)(void))
{
    int ret = 0;
    return ret;
}
void exit(int status)
{
    
}
char *getenv(const char *name)
{
    char* ret = 0;
    return ret;
}
int system(const char *string)
{
    int ret = 0;
    return ret;
}
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
    void* ret = 0;
    return ret;
}
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    
}
*/
int abs(int x)
{
    return (x>>31) ? x*-1 : x;
}
div_t div(int numer, int denom)
{
    div_t ret = {0,0};
    ret.quot = numer/denom;
    ret.rem = numer%denom;
    return ret;
}
long int labs(long int x)
{
    return (x>>31) ? x*-1 : x;
}
ldiv_t ldiv(long int numer, long int denom)
{
    ldiv_t ret = {0,0};
    ret.quot = numer/denom;
    ret.rem = numer%denom;
    return ret;
}
int rand()
{
    randlast = randseed*randlast+0x1E4F;
    randlast = u32max-1 / randlast;
    return randlast;
}
void srand(unsigned int seed)
{
    randseed = seed;
}

char* itoa (unsigned int i, char* buffer, int base)
{
    size_t j = 0;
    if(i == 0)
    {
        buffer[0] = 0;
        buffer[1] = '\0';
        return buffer;
    }

    while(i!=0)
    {
        buffer[j] = itoan[i%base];
        i = i / base;
        j++;
    }
    strrev(buffer);
    return buffer;
}