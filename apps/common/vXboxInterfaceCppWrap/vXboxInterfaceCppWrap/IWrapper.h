// vXboxInterfaceWrap.h
#pragma once
#include <Xinput.h>

using namespace std;

////////////// Definitions /////////////////////////
//
//typedef struct _BUSENUM_UNPLUG_HARDWARE {
//	__in ULONG Size;
//
//	__in ULONG SerialNo;
//
//	__in ULONG Flags;
//
//	ULONG Reserved[1];
//
//} BUSENUM_UNPLUG_HARDWARE, *PBUSENUM_UNPLUG_HARDWARE;
//
//
//
////{F679F562-3164-42CE-A4DB-E7DDBE723909}  
//DEFINE_GUID(GUID_DEVINTERFACE_SCPVBUS, 0xf679f562, 0x3164, 0x42ce, 0xa4, 0xdb, 0xe7, 0xdd, 0xbe, 0x72, 0x39, 0x9);
//
//#define VBOX_BUS
//#define FEEDBACK_BUFFER_LENGTH 9
//#define MAX_NUMBER_XBOX_CTRLS 4
//
//#define DPAD_UP XINPUT_GAMEPAD_DPAD_UP
//#define DPAD_DOWN XINPUT_GAMEPAD_DPAD_DOWN
//#define DPAD_LEFT XINPUT_GAMEPAD_DPAD_LEFT
//#define DPAD_RIGHT XINPUT_GAMEPAD_DPAD_RIGHT
//#define DPAD_OFF 0
//
//#define AXIS_MAX	32767
//#define AXIS_MIN	-32768
//
//
//#define FILE_DEVICE_BUSENUM		FILE_DEVICE_BUS_EXTENDER
//#define BUSENUM_IOCTL(_index_)	CTL_CODE(FILE_DEVICE_BUSENUM, _index_, METHOD_BUFFERED, FILE_READ_DATA)
//#define BUSENUM_W_IOCTL(_index_)	CTL_CODE(FILE_DEVICE_BUSENUM, _index_, METHOD_BUFFERED, FILE_WRITE_DATA)
//#define BUSENUM_R_IOCTL(_index_)	CTL_CODE(FILE_DEVICE_BUSENUM, _index_, METHOD_BUFFERED, FILE_READ_DATA)
//#define BUSENUM_RW_IOCTL(_index_)	CTL_CODE(FILE_DEVICE_BUSENUM, _index_, METHOD_BUFFERED, FILE_WRITE_DATA | FILE_READ_DATA)
//
//#define IOCTL_BUSENUM_BASE 0x801
//
//#ifdef VBOX_BUS
//#define IOCTL_BUSENUM_PLUGIN_HARDWARE	BUSENUM_W_IOCTL(IOCTL_BUSENUM_BASE+0x0)
//#define IOCTL_BUSENUM_UNPLUG_HARDWARE	BUSENUM_W_IOCTL(IOCTL_BUSENUM_BASE+0x1)
//#define IOCTL_BUSENUM_EJECT_HARDWARE	BUSENUM_W_IOCTL(IOCTL_BUSENUM_BASE+0x2)
//#define IOCTL_BUSENUM_REPORT_HARDWARE	BUSENUM_RW_IOCTL(IOCTL_BUSENUM_BASE+0x3)
//#else
//#define IOCTL_BUSENUM_PLUGIN_HARDWARE	BUSENUM_IOCTL(0x0)
//#define IOCTL_BUSENUM_UNPLUG_HARDWARE	BUSENUM_IOCTL(0x1)
//#define IOCTL_BUSENUM_EJECT_HARDWARE	BUSENUM_IOCTL(0x2)
//#define IOCTL_BUSENUM_REPORT_HARDWARE	BUSENUM_IOCTL(0x3)
//#endif
//
//#define IOCTL_BUSENUM_ISDEVPLUGGED	BUSENUM_RW_IOCTL(IOCTL_BUSENUM_BASE+0x100)
//#define IOCTL_BUSENUM_EMPTY_SLOTS	BUSENUM_RW_IOCTL(IOCTL_BUSENUM_BASE+0x101)
//#define IOCTL_BUSENUM_PROC_ID		BUSENUM_RW_IOCTL(IOCTL_BUSENUM_BASE+0x102)
//
//
//
////////////// Globals /////////////////////////
//XINPUT_GAMEPAD g_Gamepad[MAX_NUMBER_XBOX_CTRLS];
//BOOL g_vDevice[MAX_NUMBER_XBOX_CTRLS] = { FALSE };
//HANDLE g_hBus = INVALID_HANDLE_VALUE;

public ref class IWrapper
{
public:

	/// Status
	BOOL isVBusExists();
	BOOL GetNumEmptyBusSlots(UCHAR * nSlots);
	BOOL isControllerExists(UINT UserIndex);
	BOOL isControllerOwned(UINT UserIndex);


	// Virtual device Plug-In/Unplug
	BOOL PlugIn(UINT UserIndex);
	BOOL UnPlug(UINT UserIndex);
	BOOL UnPlugForce(UINT UserIndex);

	// Data Transfer (Data to the device)
	BOOL SetBtnA(UINT UserIndex, BOOL Press);
	BOOL SetBtnB(UINT UserIndex, BOOL Press);
	BOOL SetBtnX(UINT UserIndex, BOOL Press);
	BOOL SetBtnY(UINT UserIndex, BOOL Press);
	BOOL SetBtnStart(UINT UserIndex, BOOL Press);
	BOOL SetBtnBack(UINT UserIndex, BOOL Press);
	BOOL SetBtnLT(UINT UserIndex, BOOL Press); // Left Thumb/Stick
	BOOL SetBtnRT(UINT UserIndex, BOOL Press); // Right Thumb/Stick
	BOOL SetBtnLB(UINT UserIndex, BOOL Press); // Left Bumper
	BOOL SetBtnRB(UINT UserIndex, BOOL Press); // Right Bumper
	BOOL SetTriggerL(UINT UserIndex, BYTE Value); // Left Trigger
	BOOL SetTriggerR(UINT UserIndex, BYTE Value); // Right Trigger
	BOOL SetAxisX(UINT UserIndex, SHORT Value); // Left Stick X
	BOOL SetAxisY(UINT UserIndex, SHORT Value); // Left Stick Y
	BOOL SetAxisRx(UINT UserIndex, SHORT Value); // Right Stick X
	BOOL SetAxisRy(UINT UserIndex, SHORT Value); // Right Stick Y
	BOOL SetDpadUp(UINT UserIndex);
	BOOL SetDpadRight(UINT UserIndex);
	BOOL SetDpadDown(UINT UserIndex);
	BOOL SetDpadLeft(UINT UserIndex);
	BOOL SetDpadOff(UINT UserIndex);

	// Data Transfer (Feedback from the device)
	BOOL GetLedNumber(UINT UserIndex, PBYTE pLed);
	BOOL GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib);

#pragma region Legacy Interface Functions
	/////	General driver data
	SHORT  GetvJoyVersion(void);
	BOOL vJoyEnabled(void);
	PVOID GetvJoyProductString(void);
	PVOID GetvJoyManufacturerString(void);
	PVOID GetvJoySerialNumberString(void);
	//BOOL	 	DriverMatch(WORD * DllVer, WORD * DrvVer);
	//VOID	 	RegisterRemovalCB(RemovalCB cb, PVOID data);
	BOOL vJoyFfbCap(BOOL * Supported);
	BOOL GetvJoyMaxDevices(int * n);
	BOOL GetNumberExistingVJD(int * n);

	/////	vJoy Device properties
	int GetVJDButtonNumber(UINT rID);
	int GetVJDDiscPovNumber(UINT rID);
	int GetVJDContPovNumber(UINT rID);
	BOOL GetVJDAxisExist(UINT rID, UINT Axis);
	BOOL GetVJDAxisMax(UINT rID, UINT Axis, LONG * Max);
	BOOL GetVJDAxisMin(UINT rID, UINT Axis, LONG * Min);
	enum VjdStat GetVJDStatus(UINT rID);
	BOOL isVJDExists(UINT rID);

	/////	Write access to vJoy Device - Basic

	BOOL AcquireVJD(UINT rID);

	VOID RelinquishVJD(UINT rID);


	//// Reset functions
	BOOL ResetVJD(UINT rID);
	VOID ResetAll(void);
	BOOL ResetButtons(UINT rID);
	BOOL ResetPovs(UINT rID);

	// Write data
	BOOL UpdateVJD(UINT rID, PVOID pData);
	BOOL SetAxis(LONG Value, UINT rID, UINT Axis);
	BOOL SetBtn(BOOL Value, UINT rID, UCHAR nBtn);
	BOOL SetDiscPov(int Value, UINT rID, UCHAR nPov);
	BOOL SetContPov(DWORD Value, UINT rID, UCHAR nPov);
#pragma endregion
};