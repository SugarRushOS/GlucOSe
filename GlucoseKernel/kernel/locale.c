#include <locale.h>

static lconv_t NMlocales;

char lccollate[5]  = "";
char lcctype[5]    = "";
char lctime[5]     = "";
char lcmessages[5] = "";
char lclocale[5] = "";
char* setlocale(int category, const char* locale){
    if(category & LC_COLLATE)
    {
        if(!strcmp(locale, "C"))
        {
            strcpy(lccollate, "en-us");
        }else if(!strcmp(locale, ""))
        {
            strcpy(lccollate, "en-us");
        }
    }
    else if(category & LC_CTYPE)
    {
        if(!strcmp(locale,"C"))
        {
            strcpy(lcctype, "en-us");
        }else if(!strcmp(locale, ""))
        {
            strcpy(lcctype, "en-us");
        }
    }
    else if(category & LC_MONETARY)
    {
        lconv_t* l = localeconv();
        if(!strcmp(locale, "C"))
        {
            l->int_curr_symbol   = "USD";
            l->currency_symbol   = "$";
            l->mon_decimal_point = ".";
            l->mon_thousands_sep = ",";
            l->mon_grouping      = "\0";
            l->positive_sign     = "";
            l->negative_sign     = "-";
            l->int_frac_digits   = 2;
            l->frac_digits       = 2;
            l->p_cs_preceds      = 0;
            l->p_sep_by_space    = 0;
            l->n_cs_precedes     = 0;
            l->n_sep_by_space    = 0;
            l->p_sign_posn       = 1;
            l->n_sign_posn       = 1;
        }
        else if(!strcmp(locale, ""))
        {
            l->int_curr_symbol   = "USD";
            l->currency_symbol   = "$";
            l->mon_decimal_point = ".";
            l->mon_thousands_sep = ",";
            l->mon_grouping      = "\0";
            l->positive_sign     = "";
            l->negative_sign     = "-";
            l->int_frac_digits   = 2;
            l->frac_digits       = 2;
            l->p_cs_preceds      = 0;
            l->p_sep_by_space    = 0;
            l->n_cs_precedes     = 0;
            l->n_sep_by_space    = 0;
            l->p_sign_posn       = 1;
            l->n_sign_posn       = 1;
        }else if(!strcmp(locale, "en_US"))
        {
            l->int_curr_symbol   = "USD";
            l->currency_symbol   = "$";
            l->mon_decimal_point = ".";
            l->mon_thousands_sep = ",";
            l->mon_grouping      = "\0";
            l->positive_sign     = "";
            l->negative_sign     = "-";
            l->int_frac_digits   = 2;
            l->frac_digits       = 2;
            l->p_cs_preceds      = 0;
            l->p_sep_by_space    = 0;
            l->n_cs_precedes     = 0;
            l->n_sep_by_space    = 0;
            l->p_sign_posn       = 1;
            l->n_sign_posn       = 1;
        }
    }
    else if(category & LC_NUMERIC)
    {
        lconv_t* l = localeconv();
        if(!strcmp(locale, "C"))
        {
            l->decimal_point     = ".";
            l->thousands_sep     = ",";
            l->grouping          = "\0";
        }
        else if(!strcmp(locale, ""))
        {
            l->decimal_point     = ".";
            l->thousands_sep     = ",";
            l->grouping          = "\0";
        }else if(!strcmp(locale, "en_US"))
        {
            l->decimal_point     = ".";
            l->thousands_sep     = ",";
            l->grouping          = "\0";
        }
    }
    else if(category & LC_TIME)
    {
        if(!strcmp(locale, "C"))
        {
            strcpy(lctime, "en-us");
        }else if(!strcmp(locale, ""))
        {
            strcpy(lctime, "en-us");
        }
    }
    return (char*) locale;
}

lconv_t* localeconv(void){
    return &NMlocales;
}