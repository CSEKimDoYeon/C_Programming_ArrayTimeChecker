#pragma once
#include "common.h"
#include "AppIO.h"
#include "Messages.h"
#include "ParameterSet.h"
#include "Timer.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"
#include "BinarySearchTreeDictionary.h"
#include "SortedArrayDictionary.h"
#include "SortedLinkedDictionary.h"
#include "UnsortedArrayDictionary.h"
#include "UnsortedLinkedDictionary.h"


typedef struct _AppController AppController;

AppController* AppController_new();
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);