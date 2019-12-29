#include <assert.h>

void assertmsg(const char* msg, const char* file, int line, const char* func)
{
    printf("Glucose Kernel: %s\nline:%u\nfunction: %s()\nAssertion failed: %s", file, line, func, msg);
}