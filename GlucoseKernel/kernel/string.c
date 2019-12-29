#include <string.h>

const char* internalErrors[35] = {
    "CPU: Division by zero",
    "CPU: Debug exception",
    "CPU: Non maskable interrupt",
    "CPU: Breakpoint exception",
    "CPU: 'Into detected overflow'",
    "CPU: Out of bounds exception",
    "CPU: Invalid opcode exception",
    "CPU: No coprocessor exception",
    "CPU: Double fault (pushes an error code)",
    "CPU: Coprocessor segment overrun",
    "CPU: Bad TSS (pushes an error code)",
    "CPU: Segment not present (pushes an error code)",
    "CPU: Stack fault (pushes an error code)",
    "CPU: General protection fault (pushes an error code)",
    "CPU: Page fault (pushes an error code)",
    "CPU: Unknown interrupt exception",
    "CPU: Coprocessor fault",
    "CPU: Alignment check exception",
    "CPU: Machine check exception",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "CPU: Reserved",
    "KERNEL: Out of memory",
    "KERNEL: PANIC",
    "KERNEL: File not found"
};

char* strcat(char* dest, const char* src)
{
    size_t n = strlen(src);
    strncat(dest,src, n);
    return dest;
}
char* strncat(char* dest, const char* src, size_t n)
{
    strncpy(dest+strlen(dest), src, n);
    return dest;
}
char* strchr(const char* str, int c)
{
    size_t i = 0;
    while(str[i] != (char)c)
    {
        i++;
        if(!str[i])
            return 0;
    }
    return (char*) str+i;
}
int strcmp(const char* str1, const char* str2)
{
    return strncmp(str1, str2, (strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2)));
}
int strncmp(const char* str1, const char* str2, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if(str1[i]!=str2[i])
            return (*str1 < *str2) ? -1 : 1;
    return 0;
}
int strcoll(const char* str1, const char* str2)
{
    if(!strcmp(lccollate, "en-us"))
    {
        return strcmp(str1, str2);
    }else{
        return strcmp(str1, str2);
    }
}
char* strcpy(char* dest, const char* src)
{
    size_t n = strlen(src);
    return strncpy(dest, src, n);
}
char* strncpy(char* dest, const char* src, size_t n)
{
    for(size_t i = 0; i < n; i++)
        dest[i] = src[i];
    return dest;
}
size_t strcspn(const char* str1, const char* str2)
{
    size_t ret = -1;
    for(size_t i = 0; i < strlen(str2); i++)
        if(strchr(str1, str2[i]))
        {
            size_t a = (size_t) strchr(str1, str2[i]) - (size_t) str1;
            if(ret > a)
                ret = a;
            
        }
            
    return ret;
}
char* strerror(int errnum)
{
    return (char*)internalErrors[errnum];
}
size_t strlen(const char* str)
{
    size_t ret = 0;
    while (str[ret])
        ret++;
    return ret;
    
}
char* strpbrk(const char* str1, const char* str2)
{
    return strcspn(str1, str2) +(char*) str1;
}
char* strrchr(const char* str, int c)
{
    char* ret = (char*)str;
    size_t a = 0;
    while(str[a])
    {
        if(str[a] == (char)c)
            ret = (char*)&str[a];
        a++;
    }
    return ret;
}
size_t strspn(const char* str1, const char* str2)
{
    for(size_t i = 0; i < strlen(str1); i++)
    {
        if(strncmp(str1, str2, i))
            return i-1;
    }
    return 0;
}
char* strstr(const char* haystack, const char* needle)
{
    for(size_t i = 0; i < strlen(haystack); i++)
        if(strncmp(&haystack[i], needle, strlen(needle)) == 0)
            return (char*) &haystack[i];
    return 0;
}
char* strtok(char* str, const char* delim)
{
    static char* istr;
    if(str != NULL)
        istr = str;
    istr = strstr(istr, delim) + 1 ;
    return istr;
}

char* strrev(char* str)
{
    int a, b;
    char c;
    size_t len = strlen((const char*)str);
    for(a=0,b=len-1; a<b;a++,b--)
    {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
    }
    return str;
}