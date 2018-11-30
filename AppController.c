#include "AppController.h"

#define MIN_TEST_SIZE 1000
#define NUMBER_OF_TESTS 5
#define INTERVAL_SIZE 1000


struct _AppController {
	Element** testData;
	Timer* _timer;
	ParameterSet* _parameterSet;
};

void AppController_generateTestDataByRandomNumbers(AppController* _this);
void AppController_showResult(AppController* _this, int aTestSize, long aTimeForAdd, long aTimeForSearch, long aTimeForremove);
void AppController_initPerformanceMeasurement(AppController* _this);
double AppController_timeForUnsortedArrayDictionary_add(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize);
double AppController_timeForUnsortedArrayDictionary_search(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize);
double AppController_timeForUnsortedArrayDictionary_remove(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize);
long AppController_timeForsortedArrayDictionary_add(AppController* _this, SortredArrayDictionary* Array, int aTestSize);
long AppController_timeForsortedArrayDictionary_search(AppController* _this, SortredArrayDictionary* Array, int aTestSize);
long AppController_timeForsortedArrayDictionary_remove(AppController* _this, SortredArrayDictionary* Array, int aTestSize);
long AppController_timerForUnsortedLinkedDictionary_add(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze);
long AppController_timerForUnsortedLinkedDictionary_search(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze);
long AppController_timerForUnsortedLinkedDictionary_remove(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze);
long AppController_timeForSortedLinkedDictionary_add(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize);
long AppController_timeForSortedLinkedDictionary_search(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize);
long AppController_timeForSortedLinkedDictionary_remove(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize);
long AppController_timeForBinarySearchTreeDictionary_add(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize);
long AppController_timeForBinarySearchTreeDictionary_search(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize);
long AppController_timeForBinarySearchTreeDictionary_remove(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize);

AppController* AppController_new() {
	AppController* _this = NewObject(AppController);
	_this->_parameterSet = ParameterSet_new();
	return _this;
}
void AppController_delete(AppController* _this) {
	ParameterSet_delete(_this->_parameterSet);
	free(_this);
}
void AppController_run(AppController* _this) {
	AppIO_out(MSG_StartPerformanceMeasuring);
	AppController_initPerformanceMeasurement(_this);

	int numberOfTests = ParameterSet_numberOfTests(_this->_parameterSet);
	int intervalSize = ParameterSet_intervalSize(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);

	AppIO_out(MGS_TitleForUnsortedArrayDictionary);
	int testSIze = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedArrayDictionary* ArrayForTest = UnsortedArrayDictionary_new(testSIze);
		double timeForAdd = AppController_timeForUnsortedArrayDictionary_add(_this, ArrayForTest, testSIze);
		double timeForSearch = AppController_timeForUnsortedArrayDictionary_search(_this, ArrayForTest, testSIze);
		double timeForRemove = AppController_timeForUnsortedArrayDictionary_remove(_this, ArrayForTest, testSIze);
		AppController_showResult(_this, testSIze, timeForAdd, timeForSearch, timeForRemove);
		UnsortedArrayDictionary_delete(ArrayForTest);
		testSIze += intervalSize;
	}

	AppIO_out(MSG_TitelForSortedArratDictionary);
	testSIze = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortredArrayDictionary* ArrayForTest = SortedArrayDictionary_new(testSIze);
		long timeForAdd = AppController_timeForsortedArrayDictionary_add(_this, ArrayForTest, testSIze);
		long timeForSearch = AppController_timeForsortedArrayDictionary_search(_this, ArrayForTest, testSIze);
		long timeForRemove = AppController_timeForsortedArrayDictionary_remove(_this, ArrayForTest, testSIze);
		AppController_showResult(_this, testSIze, timeForAdd, timeForSearch, timeForRemove);
		SortedArrayDictionary_delete(ArrayForTest);
		testSIze += intervalSize;
	}

	AppIO_out(MSG_TItleForUnsortedLinkedDictionary);
	testSIze = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedLinkedDictionary* LinkForTest = UnsortedLinkedDictionary_new(testSIze);
		long timeForAdd = AppController_timerForUnsortedLinkedDictionary_add(_this, LinkForTest, testSIze);
		long timeForSearch = AppController_timerForUnsortedLinkedDictionary_search(_this, LinkForTest, testSIze);
		long timerForremove = AppController_timerForUnsortedLinkedDictionary_remove(_this, LinkForTest, testSIze);
		AppController_showResult(_this, testSIze, timeForAdd, timeForSearch, timerForremove);
		UnsortedLinkedDictionary_delete(LinkForTest);
		testSIze += intervalSize;
	}

	AppIO_out(MSG_TitleForSortedLInkedDictionary);
	testSIze = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedLinkedDictionary* LinkForTest = SortedLinkedDictionary_new(testSIze);
		long timeForAdd = AppController_timeForSortedLinkedDictionary_add(_this, LinkForTest, testSIze);
		long timeForSearch = AppController_timeForSortedLinkedDictionary_search(_this, LinkForTest, testSIze);
		long timeForremove = AppController_timeForSortedLinkedDictionary_remove(_this, LinkForTest, testSIze);
		AppController_showResult(_this, testSIze, timeForAdd, timeForSearch, timeForremove);
		SortedLinkedDictionary_delete(LinkForTest);
		testSIze += intervalSize;
	}
	
	AppIO_out(MSG_TitleForBinarySearchTreeDictionary);
	testSIze = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		BinarySearchTreeDictionary* TreeForTest = BinarySearchTreeDictionary_new();
		long timeForAdd = AppController_timeForBinarySearchTreeDictionary_add(_this, TreeForTest, testSIze);
		long timeForSearch = AppController_timeForBinarySearchTreeDictionary_search(_this, TreeForTest, testSIze);
		long timeForremove = AppController_timeForBinarySearchTreeDictionary_remove(_this, TreeForTest, testSIze);
		AppController_showResult(_this, testSIze, timeForAdd, timeForSearch, timeForremove);
		BinarySearchTreeDictionary_delete(TreeForTest);
		testSIze += intervalSize;
	}

	AppIO_out(MSG_EndPerformanceMeasuring);
}

void AppController_generateTestDataByRandomNumbers(AppController* _this) {
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxTestSize; i++) {
		int value = rand();
		_this->testData[i] = Element_newWith(Key_newWith(value), Object_newWith(value));
	}
}

void AppController_showResult(AppController* _this, int aTestSize, long aTimeForAdd, long aTimeForSearch, long aTimeForremove) {
	char results[255];
	sprintf(results, "크기 %4d, 삽입 : %6ld, 검색 : %7ld, 삭제 : %7ld\n", aTestSize, aTimeForAdd, aTimeForSearch, aTimeForremove);
	AppIO_out(results);
}

void AppController_initPerformanceMeasurement(AppController* _this) {
	ParameterSet_setMinTestSize(_this->_parameterSet, MIN_TEST_SIZE);
	ParameterSet_setIntervalSize(_this->_parameterSet, INTERVAL_SIZE);
	ParameterSet_setNumberOfTests(_this->_parameterSet, NUMBER_OF_TESTS);

	_this->testData = NewVector(Element*, ParameterSet_maxTestSize(_this->_parameterSet));
	AppController_generateTestDataByRandomNumbers(_this);
}

double AppController_timeForUnsortedArrayDictionary_add(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayDictionary_isFull(Array)) {
			UnsortedArrayDictionary_AddKeyAndObject(Array, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
double AppController_timeForUnsortedArrayDictionary_search(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		UnsortedArrayDictionary_keyDoesExist(Array, Element_getKey(_this->testData[i]));
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
double AppController_timeForUnsortedArrayDictionary_remove(AppController* _this, UnsortedArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayDictionary_isEmpty(Array)) {
			Element* remove = UnsortedArrayDictionary_removeObjectForKey(Array, Element_getKey(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForsortedArrayDictionary_add(AppController* _this, SortredArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isFull(Array)) {
			SortedArrayDictionary_addKeyAndObject(Array, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForsortedArrayDictionary_search(AppController* _this, SortredArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		SortedArrayDictionary_KeyDoesExist(Array, Element_getKey(_this->testData[i]));
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForsortedArrayDictionary_remove(AppController* _this, SortredArrayDictionary* Array, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isEmpty(Array)) {
			Element* remove = SortedArrayDictionary_removeObjectForKey(Array, Element_getKey(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timerForUnsortedLinkedDictionary_add(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSIze; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedDictionary_isFull(aLink)) {
			UnsortedLinkedDictionary_AddKeyAndObject(aLink, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timerForUnsortedLinkedDictionary_search(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSIze; i++) {
		Timer_start(timer);
		UnsortedLInkedDictionary_keyDoesExist(aLink, Element_getKey(_this->testData[i]));
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timerForUnsortedLinkedDictionary_remove(AppController* _this, UnsortedLinkedDictionary* aLink, int aTestSIze) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSIze; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedDictionary_isEmpty(aLink)) {
			Element* remove = UnsortedLinkedDictionary_removeObjectForKey(aLink, Element_getKey(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForSortedLinkedDictionary_add(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isFull(aLink)) {
			SortedLinkedDictionary_addKeyAndObject(aLink, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForSortedLinkedDictionary_search(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		SortedLinkedDictionary_addKeyAndObject(aLink, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForSortedLinkedDictionary_remove(AppController* _this, SortedLinkedDictionary* aLink, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isEmpty(aLink)) {
			Element* remove = SortedLinkedDictionary_removeObjectForKey(aLink, Element_getKey(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForBinarySearchTreeDictionary_add(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isFull(aTree)) {
			BinarySearchTreeDictionary_addKeyAndObject(aTree, Element_getKey(_this->testData[i]), Element_getObject(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForBinarySearchTreeDictionary_search(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		BinarySearchTreeDictionary_KeyDoesExist(aTree, Element_getKey(_this->testData[i]));
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
long AppController_timeForBinarySearchTreeDictionary_remove(AppController* _this, BinarySearchTreeDictionary* aTree, int aTestSize) {
	Timer* timer = Timer_new();
	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isEmpty(aTree)) {
			Element* remove = BinarySearchTreeDictionary_removeObjectForKey(aTree, Element_getKey(_this->testData[i]));
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}
