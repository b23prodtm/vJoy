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
//bool g_vDevice[MAX_NUMBER_XBOX_CTRLS] = { FALSE };
//HANDLE g_hBus = INVALID_HANDLE_VALUE;


namespace vXboxAPI {

	public ref class vXboxInterfaceWrap
	{
	public:

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
		bool SetDpadOff(UINT UserIndex);

		// Data Transfer (Feedback from the device)
		bool GetLedNumber(UINT UserIndex, PBYTE pLed);
		bool GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib);

	//private:
	//	//////////// Helper Functions /////////////////////////
	//int GetVXbusPath(LPCTSTR path, UINT size);
	//HANDLE GetVXbusHandle(void);
	//bool GetCreateProcID(DWORD UserIndex, PULONG ProcID);
	//bool XOutputSetState(DWORD UserIndex, XINPUT_GAMEPAD* pGamepad);
	//bool XOutputSetGetState(DWORD UserIndex, XINPUT_GAMEPAD* pGamepad, PBYTE bVibrate, PBYTE bLargeMotor, PBYTE bSmallMotor, PBYTE bLed);
	//bool SetDpad(UINT UserIndex, INT Value);
	//WORD ConvertButton(LONG vBtns, WORD xBtns, UINT vBtn, UINT xBtn);
	//bool UnPlug_Opt(UINT UserIndex, bool Force);
	};
}
