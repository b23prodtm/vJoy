// Test-vXboxInterface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>

extern "C"
{
#include <setupapi.h>
#include <Hidsdi.h>
}

#include <Dbt.h>
#include <tchar.h>

#include "..\..\vXboxInterfaceCppWrap\vXboxInterfaceCppWrap\IWrapper.h"
#include "..\..\vXboxInterfaceCppWrap\vXboxInterfaceCppWrap\IWrapper.cpp"


using namespace std;
using namespace vXbox;
#ifdef XBOX
#pragma comment(lib, "vJoyInterface")
int main()
{
	BOOL res;
	UCHAR nEmpty;
	IWrapper w;
	
	// Test if bus exists
	BOOL bus = w.isVBusExists();
	if (bus)
		printf("Virtual Xbox bus exists\n\n");
	else
	{
		printf("Virtual Xbox bus does NOT exist - Aborting\n\n");
		getchar();
		return -1;
	}

	res = w.AcquireVJD(1);
	printf("\n\nAcquireVJD(%d): %d\n", 1, res);
	//Sleep(500);

	res = w.AcquireVJD(1);
	printf("\n\nAcquireVJD(%d): %d\n", 1, res);
	//Sleep(500);

	res = w.AcquireVJD(1);
	printf("\n\nAcquireVJD(%d): %d\n", 1, res);
	//Sleep(500);

	res = w.AcquireVJD(1);
	printf("\n\nAcquireVJD(%d): %d\n", 1, res);
	//Sleep(500);




	printf("Press any key to continue \n");
	getchar();



	// Install Virtual Devices
	for (UINT i = 0; i < 6; i++)
	{
		res = w.GetNumEmptyBusSlots(&nEmpty);
		if (res)
			printf("\n\nNumber of Empty Slots: %d\n", nEmpty);
		else
			printf("\n\nCannot determine Number of Empty Slots");

		res = w.isControllerExists(i);
		printf("\nisControllerExists(%d): %X\n", i, res);
		res = w.isControllerOwned(i);
		printf("\nisControllerOwned(%d): %X\n", i, res);
		res = w.PlugIn(i);
		printf("Plug-in device %d: %X\n", i, res);
		res = w.isControllerExists(i);
		printf("isControllerExists(%d): %X\n", i, res);
		res = w.isControllerOwned(i);
		printf("\nisControllerOwned(%d): %X\n", i, res);
	}
	printf("\n");
	w.SetTriggerL(2, 0);
	w.SetTriggerR(2, 0);

	for (int T = 0; T < 100; T++)
	{
		w.SetAxisX(1, T * 300);
		w.SetAxisY(1, (T * 300)*-1);
		w.SetAxisRx(1, T * 100);
		w.SetAxisRy(1, (T * 100)*-1);
		switch (T)
		{
		case 0:
			w.SetDpadUp(1);
			w.SetBtnA(1, FALSE);
			w.SetBtnB(1, TRUE);
			break;
		case 20:
			w.SetDpadRight(1);
			w.SetBtnB(1, FALSE);
			break;
		case 40:
			w.SetDpadDown(1);
			break;
		case 60:
			w.SetDpadLeft(1);
			break;
		case 80:
			w.SetDpadOff(1);
			w.SetBtnA(1, TRUE);
			break;
		}

		w.SetTriggerL(1, 2 * T);
		w.SetTriggerR(1, 57 + (2 * T));
		Sleep(100);
	}
	w.SetTriggerL(1, 255);
	w.SetTriggerR(1, 255);

	printf("Press any key to detect device feedback \n");
	getchar();

	UCHAR Led;
	BOOL Led_Ok, Vib_Ok;
	XINPUT_VIBRATION Vib;
	int iDev = 0;
	while (getchar() != 'q')
	{
		for (iDev = 1; iDev < 5; iDev++)
		{
			Led_Ok = w.GetLedNumber(iDev, &Led);
			Vib_Ok = w.GetVibration(iDev, &Vib);
			printf("LED: %d; Left Motor: %d; Right Motor: %d  \n", Led, Vib.wLeftMotorSpeed, Vib.wRightMotorSpeed);
		};
	}

	printf("Press any key to remove devices \n");
	getchar();

#if 1
	// UnInstall Virtual Devices
	for (UINT i = 0; i < 6; i++)
	{
		res = w.UnPlugForce(i);
		printf("UnPlug (Forced) device %d: %X\n", i, res);
	}
#endif // 0

	printf("Press any key to exit \n");
	getchar();

	return 0;

}
#else // !XBOX
int main()
{
	printf("NOT Xbox mode\n");
	return 0;
}

#endif // !XBOX 