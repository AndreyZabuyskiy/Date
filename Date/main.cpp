#include "Application.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Application application;
	application.start();

	return 0;
}