#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum{FALSE, TRUE} Boolean;


