#pragma once
#include <stdbool.h>
#define maxsize 20

//字符串
typedef struct {
	char *ch;
	int len;
	int maxlen;
}Str;