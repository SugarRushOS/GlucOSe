#ifndef LOCALE_H
#define LOCALE_H

#include <typedef.h>
#include <string.h>
#define LC_ALL      LC_COLLATE | LC_CTYPE | LC_MONETARY | LC_NUMERIC | LC_TIME
#define LC_COLLATE  0x1
#define LC_CTYPE    0x2
#define LC_MONETARY 0x4
#define LC_NUMERIC  0x8
#define LC_TIME     0x10

char lccollate[5];
char lcctype[5];
char lctime[5];
char lcmessages[5];

struct lconv_s
{
    char* decimal_point;
    char* thousands_sep;
    char* grouping;
    char* int_curr_symbol;
    char* currency_symbol;
    char* mon_decimal_point;
    char* mon_thousands_sep;
    char* mon_grouping;
    char* positive_sign;
    char* negative_sign;
    char  int_frac_digits;
    char  frac_digits;
    char  p_cs_preceds;
    char  p_sep_by_space;
    char  n_cs_precedes;
    char  n_sep_by_space;
    char  p_sign_posn;
    char  n_sign_posn;
};

typedef struct lconv_s lconv_t;

char*    setlocale(int category, const char* locale); //✔️
lconv_t* localeconv(void);                            //✔️

#endif