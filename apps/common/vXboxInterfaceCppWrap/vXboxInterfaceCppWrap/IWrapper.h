//// IWrapper.h
//// The following ifdef block is the standard way of creating macros which make exporting 
//// from a DLL simpler. All files within this DLL are compiled with the VXBOX_EXPORTS
//// symbol defined on the command line. this symbol should not be defined on any project
//// that uses this DLL. This way any other project whose source files include this file see 
//// functions as being imported from a DLL, whereas this DLL sees symbols
//// defined with this macro as being exported.
//#ifdef VXBOX_EXPORTS
//#define VXBOX_API __declspec(dllexport)
//#else
//#define VXBOX_API __declspec(dllimport)
//#endif

#pragma once
#include <Xinput.h>
#include "../../vjoyinterface/vjoyinterface.h"
#include <valarray>

using namespace std;
namespace vXbox {
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
	//bool g_vDevice[MAX_NUMBER_XBOX_CTRLS] = { FALSE };
	//HANDLE g_hBus = INVALID_HANDLE_VALUE;

	public ref class IWrapper
	{
	public:
		// HID8USAGE enum
		const unsigned int hid_X = HID_USAGE_X,
			hid_Y = HID_USAGE_Y,
			hid_Z = HID_USAGE_Z,
			hid_RX = HID_USAGE_RX,
			hid_RY = HID_USAGE_RY,
			hid_RZ = HID_USAGE_RZ,
			hid_SL0 = HID_USAGE_SL0,
			hid_SL1 = HID_USAGE_SL1,
			hid_WHL = HID_USAGE_WHL,
			hid_POV = HID_USAGE_POV;
		// VjdStat
		static const int VJD_STAT_BUSY = vJoy::VJD_STAT_BUSY,
			VJD_STAT_FREE = vJoy::VJD_STAT_FREE,
			VJD_STAT_MISS = vJoy::VJD_STAT_MISS,
			VJD_STAT_OWN = vJoy::VJD_STAT_OWN,
			VJD_STAT_UNKN = vJoy::VJD_STAT_UNKN;
		static valarray<int> getVjdStat() {
			valarray <int> all = { VJD_STAT_BUSY,VJD_STAT_FREE,VJD_STAT_MISS, VJD_STAT_OWN, VJD_STAT_UNKN };
			return all;
		}
		/// Status
		bool isVBusExists();
		bool GetNumEmptyBusSlots(UCHAR * nSlots);
		bool isControllerExists(UINT UserIndex);
		bool isControllerOwned(UINT UserIndex);


		// Virtual device Plug-In/Unplug
		bool PlugIn(UINT UserIndex);
		bool UnPlug(UINT UserIndex);
		bool UnPlugForce(UINT UserIndex);

		// Data Transfer (Data to the device)
		bool SetBtnA(UINT UserIndex, bool Press);
		bool SetBtnB(UINT UserIndex, bool Press);
		bool SetBtnX(UINT UserIndex, bool Press);
		bool SetBtnY(UINT UserIndex, bool Press);
		bool SetBtnStart(UINT UserIndex, bool Press);
		bool SetBtnBack(UINT UserIndex, bool Press);
		bool SetBtnLT(UINT UserIndex, bool Press); // Left Thumb/Stick
		bool SetBtnRT(UINT UserIndex, bool Press); // Right Thumb/Stick
		bool SetBtnLB(UINT UserIndex, bool Press); // Left Bumper
		bool SetBtnRB(UINT UserIndex, bool Press); // Right Bumper
		bool SetTriggerL(UINT UserIndex, BYTE Value); // Left Trigger
		bool SetTriggerR(UINT UserIndex, BYTE Value); // Right Trigger
		bool SetAxisX(UINT UserIndex, SHORT Value); // Left Stick X
		bool SetAxisY(UINT UserIndex, SHORT Value); // Left Stick Y
		bool SetAxisRx(UINT UserIndex, SHORT Value); // Right Stick X
		bool SetAxisRy(UINT UserIndex, SHORT Value); // Right Stick Y
		bool SetDpadUp(UINT UserIndex);
		bool SetDpadRight(UINT UserIndex);
		bool SetDpadDown(UINT UserIndex);
		bool SetDpadLeft(UINT UserIndex);
		bool SetDpadUpRight(UINT UserIndex);
		bool SetDpadDownRight(UINT UserIndex);
		bool SetDpadDownLeft(UINT UserIndex);
		bool SetDpadUpLeft(UINT UserIndex);
		bool SetDpadOff(UINT UserIndex);

		// Data Transfer (Feedback from the device)
		bool GetLedNumber(UINT UserIndex, PBYTE pLed);
		bool GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib);

#pragma region Legacy Interface Functions
		/////	General driver data
		SHORT GetvJoyVersion(void);
		bool vJoyEnabled(void);
		PVOID GetvJoyProductString(void);
		PVOID GetvJoyManufacturerString(void);
		PVOID GetvJoySerialNumberString(void);
		//BOOL	 	DriverMatch(WORD * DllVer, WORD * DrvVer);
		//VOID	 	RegisterRemovalCB(RemovalCB cb, PVOID data);
		bool vJoyFfbCap(bool * Supported);
		bool GetvJoyMaxDevices(int * n);
		bool GetNumberExistingVJD(int * n);

		/////	vJoy Device properties
		int GetVJDButtonNumber(UINT rID);
		int GetVJDDiscPovNumber(UINT rID);
		int GetVJDContPovNumber(UINT rID);
		bool GetVJDAxisExist(UINT rID, UINT Axis);
		bool GetVJDAxisMax(UINT rID, UINT Axis, LONG * Max);
		bool GetVJDAxisMin(UINT rID, UINT Axis, LONG * Min);
		int GetVJDStatus(UINT rID);
		bool isVJDExists(UINT rID);

		/////	Write access to vJoy Device - Basic

		bool AcquireVJD(UINT rID);
		VOID RelinquishVJD(UINT rID);


		//// Reset functions
		bool ResetVJD(UINT rID);
		VOID ResetAll(void);
		bool ResetButtons(UINT rID);
		bool ResetPovs(UINT rID);

		// Write data
		bool UpdateVJD(UINT rID, PVOID pData);
		bool SetAxis(LONG Value, UINT rID, UINT Axis);
		bool SetBtn(bool Value, UINT rID, UCHAR nBtn);
		bool SetDiscPov(int Value, UINT rID, UCHAR nPov);
		bool SetContPov(DWORD Value, UINT rID, UCHAR nPov);
#pragma endregion
	};
}