#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>

void assertmsg(const char* msg, const char* file, int line, const char* func); //✔️
#define ASSERT(EX) assertmsg(EX, __FILE__, __LINE__, __func__);                //✔️

#endif