#ifndef STDLIB_H
#define STDLIB_H

#include <typedef.h>
#include <NULL.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define EXIT_FAILEURE -1
#define EXIT_SUCCESS  0
#define RAND_MAX      sizeof(int)

struct div_s {
    int quot;
    int rem;
};
typedef struct div_s div_t;

struct ldiv_s {
    long int quot;
    long int rem;
};
typedef struct ldiv_s ldiv_t;   

struct regs_s{
    u32 ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 interruptnum, errorcode;
    u32 eip, cs, eflags, useresp, ss;
};
typedef struct regs_s regs_t;

double            atof    (const char *str);                                                                                          //❌
int               atoi    (const char *str);                                                                                          //❌
long int          atol    (const char *str);                                                                                          //❌
double            strtod  (const char *str, char **endptr);                                                                           //❌
long int          strtol  (const char *str, char **endptr, int base);                                                                 //❌
unsigned long int strtoul (const char *str, char **endptr, int base);                                                                 //❌
void*             calloc  (size_t nitems, size_t size);                                                                               //❌
void              free    (void *ptr);                                                                                                //❌
void*             malloc  (size_t size);                                                                                              //❌
void*             realloc (void *ptr, size_t size);                                                                                   //❌
void              abort   (void);                                                                                                     //❌
int               atexit  (void (*func)(void));                                                                                       //❌
void              exit    (int status);                                                                                               //❌
char*             getenv  (const char *name);                                                                                         //❌
int               system  (const char *string);                                                                                       //❌
void*             bsearch (const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)); //❌
void              qsort   (void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));                         //❌
int               abs     (int x);                                                                                                    //✔️
div_t             div     (int numer, int denom);                                                                                     //✔️
long int          labs    (long int x);                                                                                               //✔️
ldiv_t            ldiv    (long int numer, long int denom);                                                                           //✔️
int               rand    (void);                                                                                                     //✔️
void              srand   (unsigned int seed);                                                                                        //✔️
char*             itoa    (unsigned i, char* buffer, int base);                                                                       //❌
#endif