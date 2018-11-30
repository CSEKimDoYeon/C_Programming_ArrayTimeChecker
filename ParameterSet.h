#pragma once

#include "common.h"

typedef struct _ParameterSet ParameterSet;

ParameterSet* ParameterSet_new(void);
ParameterSet* ParameterSet_newWith(int givenMinTestSize, int givenIntervalSize, int givenNumverOfTests);

void ParameterSet_delete(ParameterSet* _this);

void ParameterSet_setMinTestSize(ParameterSet* _this, int newMinTestSize);
int ParameterSet_minTestSize(ParameterSet* _this);

void ParameterSet_setIntervalSize(ParameterSet* _this, int newIntervalSize);
int ParameterSet_intervalSize(ParameterSet* _this);

void ParameterSet_setNumberOfTests(ParameterSet* _this, int newNumberOFTests);
int ParameterSet_numberOfTests(ParameterSet* _this);

int ParameterSet_maxTestSize(ParameterSet* _this);