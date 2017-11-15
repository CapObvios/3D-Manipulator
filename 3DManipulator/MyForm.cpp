#include <Windows.h>

#include "MyForm.h"

using namespace System;
using namespace My3DManipulator;

/*
Author: Sergey Pavlov
Seminar 4-6
VS2015/17 (v140 toolkit & windows 8 compatible)
10.04.2017

Figures folder contain geometry figures. First all the points are states and then the poligons are given.
vertex.h - vertex data type
Drawer & GeometryTypes - seminar 1-2 files with 2d graphics logic
Types - contains data typs necessary for working with 3d data.
MyForm - main window
*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}