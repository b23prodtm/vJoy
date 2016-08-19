#pragma once
#include "Stdafx.h"

#include "IWrapper.h"

#include  "../../vjoyinterface/vjoyinterface.h"
#include  "../../vjoyinterface/vXboxInterface.h"

using namespace std;
BOOL IWrapper::isVBusExists(void)
{
	return ::isVBusExists();
}

BOOL IWrapper::GetNumEmptyBusSlots(UCHAR * nSlots)
{
	return ::GetNumEmptyBusSlots(nSlots);
}

BOOL IWrapper::isControllerExists(UINT UserIndex)
{
	return ::isControllerExists(UserIndex);
}

BOOL IWrapper::isControllerOwned(UINT UserIndex) {
	return ::isControllerOwned(UserIndex);
}

BOOL IWrapper::PlugIn(UINT UserIndex) {
	return ::PlugIn(UserIndex);
}

BOOL IWrapper::UnPlug(UINT UserIndex) {
	return ::UnPlug(UserIndex);
}

BOOL IWrapper::UnPlugForce(UINT UserIndex) {
	return ::UnPlugForce(UserIndex);
}

BOOL IWrapper::SetAxisX(UINT UserIndex, SHORT Value) {
	return ::SetAxisX(UserIndex, Value);
}

BOOL IWrapper::SetAxisY(UINT UserIndex, SHORT Value) {
	return ::SetAxisY(UserIndex, Value);
}
BOOL IWrapper::SetAxisRx(UINT UserIndex, SHORT Value) {
	return ::SetAxisRx(UserIndex, Value);
}

BOOL IWrapper::SetAxisRy(UINT UserIndex, SHORT Value) {
	return ::SetAxisRy(UserIndex, Value);
}

BOOL IWrapper::SetDpadUp(UINT UserIndex) {
	return ::SetDpadUp(UserIndex);
}

BOOL IWrapper::SetDpadRight(UINT UserIndex) {
	return ::SetDpadRight(UserIndex);
}

BOOL IWrapper::SetDpadDown(UINT UserIndex) {
	return ::SetDpadDown(UserIndex);
}

BOOL IWrapper::SetDpadLeft(UINT UserIndex) {
	return ::SetDpadLeft(UserIndex);
}

BOOL IWrapper::SetDpadOff(UINT UserIndex) {
	return ::SetDpadOff(UserIndex);
}

BOOL IWrapper::SetBtnA(UINT UserIndex, BOOL Press) {
	return ::SetBtnA(UserIndex,Press);
}

BOOL IWrapper::SetBtnB(UINT UserIndex, BOOL Press) {
	return ::SetBtnB(UserIndex, Press);
}

BOOL IWrapper::SetBtnX(UINT UserIndex, BOOL Press) {
	return ::SetBtnX(UserIndex, Press);
}

BOOL IWrapper::SetBtnY(UINT UserIndex, BOOL Press) {
	return ::SetBtnY(UserIndex, Press);
}

BOOL IWrapper::SetBtnStart(UINT UserIndex, BOOL Press) {
	return ::SetBtnStart(UserIndex, Press);
}

BOOL IWrapper::SetBtnBack(UINT UserIndex, BOOL Press) {
	return ::SetBtnBack(UserIndex, Press);
}

BOOL IWrapper::SetBtnLT(UINT UserIndex, BOOL Press) {
	return ::SetBtnLT(UserIndex, Press);
}

BOOL IWrapper::SetBtnRT(UINT UserIndex, BOOL Press) {
	return ::SetBtnRT(UserIndex, Press);
}

BOOL IWrapper::SetBtnLB(UINT UserIndex, BOOL Press) {
	return ::SetBtnLB(UserIndex, Press);
}

BOOL IWrapper::SetBtnRB(UINT UserIndex, BOOL Press) {
	return ::SetBtnRB(UserIndex, Press);
}

BOOL IWrapper::SetTriggerL(UINT UserIndex, BYTE Value) {
	return ::SetTriggerL(UserIndex, Value);
}

BOOL IWrapper::SetTriggerR(UINT UserIndex, BYTE Value) {
	return ::SetTriggerR(UserIndex, Value);
}

BOOL IWrapper::GetLedNumber(UINT UserIndex, PBYTE pLed) {
	return ::GetLedNumber(UserIndex, pLed);
}

BOOL IWrapper::GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib) {
	return ::GetVibration(UserIndex,pVib);
}


#pragma region Legacy Interface Functions
/////	General driver data
SHORT IWrapper::GetvJoyVersion(void) {
	return ::GetvJoyVersion();
}
BOOL IWrapper::vJoyEnabled(void) {
	return ::vJoyEnabled();
}
PVOID IWrapper::GetvJoyProductString(void) {
	return ::GetvJoyProductString();
}
PVOID IWrapper::GetvJoyManufacturerString(void) {
	return ::GetvJoyManufacturerString();
}
PVOID IWrapper::GetvJoySerialNumberString(void) {
	return ::GetvJoySerialNumberString();
}
//BOOL	 	DriverMatch(WORD * DllVer, WORD * DrvVer);
//VOID	 	RegisterRemovalCB(RemovalCB cb, PVOID data);
BOOL IWrapper::vJoyFfbCap(BOOL * Supported) {
	return ::vJoyFfbCap(Supported);
}
BOOL IWrapper::GetvJoyMaxDevices(int * n) {
	return ::GetvJoyMaxDevices(n);
}
BOOL IWrapper::GetNumberExistingVJD(int * n) {
	return ::GetNumberExistingVJD(n);
}

/////	vJoy Device properties
int IWrapper::GetVJDButtonNumber(UINT rID) {
	return ::GetVJDButtonNumber(rID);
}
int IWrapper::GetVJDDiscPovNumber(UINT rID) {
	return ::GetVJDDiscPovNumber(rID);
}
int IWrapper::GetVJDContPovNumber(UINT rID) {
	return ::GetVJDContPovNumber(rID);
}
BOOL IWrapper::GetVJDAxisExist(UINT rID, UINT Axis) {
	return ::GetVJDAxisExist(rID, Axis);
}
BOOL IWrapper::GetVJDAxisMax(UINT rID, UINT Axis, LONG * Max) {
	return ::GetVJDAxisMax(rID, Axis, Max);
}
BOOL IWrapper::GetVJDAxisMin(UINT rID, UINT Axis, LONG * Min) {
	return ::GetVJDAxisMin(rID, Axis, Min);
}
enum VjdStat IWrapper::GetVJDStatus(UINT rID) {
	return ::GetVJDStatus(rID);
}
BOOL IWrapper::isVJDExists(UINT rID) {
	return ::isVJDExists(rID);
}

/////	Write access to vJoy Device - Basic

BOOL IWrapper::AcquireVJD(UINT rID) {
	return ::AcquireVJD(rID);
}

VOID IWrapper::RelinquishVJD(UINT rID) {
	return ::RelinquishVJD(rID);
}


//// Reset functions
BOOL IWrapper::ResetVJD(UINT rID) {
	return ::ResetVJD(rID);
}
VOID IWrapper::ResetAll(void) {
	return ::ResetAll();
}
BOOL IWrapper::ResetButtons(UINT rID) {
	return ::ResetButtons(rID);
}
BOOL IWrapper::ResetPovs(UINT rID) {
	return ::ResetPovs(rID);
}

// Write data
BOOL IWrapper::UpdateVJD(UINT rID, PVOID pData) {
	return ::UpdateVJD(rID, pData);
}
BOOL IWrapper::SetAxis(LONG Value, UINT rID, UINT Axis) {
	return ::SetAxis(Value, rID, Axis);
}
BOOL IWrapper::SetBtn(BOOL Value, UINT rID, UCHAR nBtn) {
	return ::SetBtn(Value, rID, nBtn);
}
BOOL IWrapper::SetDiscPov(int Value, UINT rID, UCHAR nPov) {
	return ::SetDiscPov(Value, rID, nPov);
}
BOOL IWrapper::SetContPov(DWORD Value, UINT rID, UCHAR nPov) {
	return ::SetContPov(Value, rID, nPov);
}
#pragma endregion
	///-------------------------------------------------------------------------------------------------
	/// <summary>	Output set state. </summary>
	///
	/// <remarks>	Benjamin, 15.03.2016. </remarks>
	///
	/// <param name="dwUserIndex">	Zero-based index of the user. </param>
	/// <param name="pGamepad">	  	[in,out] If non-null, the state. </param>
	///
	/// <returns>	A DWORD. </returns>
	///-------------------------------------------------------------------------------------------------
	BOOL IWrapper::XOutputSetState(DWORD UserIndex, XINPUT_GAMEPAD* pGamepad) {
		return ::XOutputSetState(UserIndex, pGamepad);
	}

	BOOL IWrapper::XOutputSetGetState(DWORD UserIndex, XINPUT_GAMEPAD * pGamepad, PBYTE bVibrate, PBYTE bLargeMotor, PBYTE bSmallMotor, PBYTE bLed) {
		return ::XOutputSetGetState(UserIndex, pGamepad, bVibrate, bLargeMotor, bSmallMotor, bLed);
	}


	BOOL IWrapper::GetCreateProcID(DWORD UserIndex, PULONG ProcID) {
		return ::GetCreateProcID(UserIndex, ProcID);
	}

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Get Device Interface path. </summary>
	///
	/// <remarks>	Shaul, 17.03.2016. </remarks>
	///
	/// <param name="path">	Pointer to the output buffer holding the Device Interface path string. </param>
	/// <param name="size">	Size of the output buffer in WCHARs.</param>
	///
	/// <returns>	If sucessful: Size of the the path in WCHARs
	///             Negative number indicates failure.</returns>
	/// 
	///-------------------------------------------------------------------------------------------------
	int IWrapper::GetVXbusPath(LPCTSTR path, UINT size) {
		return ::GetVXbusPath(path, size);
	}

	HANDLE IWrapper::GetVXbusHandle(void) {
		return ::GetVXbusHandle();
	}

	WORD IWrapper::ConvertButton(LONG vBtns, WORD xBtns, UINT vBtn, UINT xBtn) {
		return ::ConvertButton(vBtns, xBtns,vBtn, xBtn);
	}

	BOOL IWrapper::SetDpad(UINT UserIndex, INT Value) {
		return ::SetDpad(UserIndex, Value);
	}

	BOOL IWrapper::UnPlug_Opt(UINT UserIndex, BOOL Force) {
		return ::UnPlug_Opt(UserIndex, Force);
	}
