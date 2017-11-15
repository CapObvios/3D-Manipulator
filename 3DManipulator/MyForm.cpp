#include <Windows.h>

#include "MyForm.h"

using namespace System;
using namespace My3DManipulator;

/*
Author: Sergey Pavlov
Seminar 4-6
VS2015/17 (v140 toolkit & windows 8 compatible)
10.04.2017
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}