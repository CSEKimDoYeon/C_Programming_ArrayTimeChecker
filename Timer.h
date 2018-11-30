#pragma once


#include <stdlib.h>
#include "common.h"
#include <Windows.h>



typedef struct _Timer Timer;

Timer* Timer_new(void);

void Timer_delete(Timer* _this);

void Timer_start(Timer* _this);

void Timer_stop(Timer* _this);

double Timer_duration(Timer* _this);