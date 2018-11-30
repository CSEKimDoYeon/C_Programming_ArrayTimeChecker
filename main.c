#include "AppController.h"

int main() {
	AppController* _AppController = AppController_new();
	AppController_run(_AppController);
	AppController_delete(_AppController);

	system("pause");
	return 0;
}