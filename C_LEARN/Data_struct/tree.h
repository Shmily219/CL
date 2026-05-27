#pragma once
#include <stdlib.h>

typedef struct Threadnode{
	int data;
	struct Threadnode* lc, * rc;
	int ltag, rtag;
}Threadnode,*ThreadTree;