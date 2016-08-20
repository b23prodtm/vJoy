#pragma once
#include "Stdafx.h"

#include "IWrapper.h"

#include  "../../vjoyinterface/vXboxInterface.h"

using namespace std;

using namespace vXbox;
bool vXbox::IWrapper::isVBusExists(void) {
	return ::isVBusExists() == TRUE;
}
bool vXbox::IWrapper::GetNumEmptyBusSlots(UCHAR * nSlots) {
	return ::GetNumEmptyBusSlots(nSlots) == TRUE;
}
bool vXbox::IWrapper::isControllerExists(UINT UserIndex) {
	return ::isControllerExists(UserIndex) == TRUE;
}
bool vXbox::IWrapper::isControllerOwned(UINT UserIndex) {
	return ::isControllerOwned(UserIndex) == TRUE;
}
bool vXbox::IWrapper::PlugIn(UINT UserIndex) {
	return ::PlugIn(UserIndex) == TRUE;
}
bool vXbox::IWrapper::UnPlug(UINT UserIndex) {
	return ::UnPlug(UserIndex) == TRUE;
}
bool vXbox::IWrapper::UnPlugForce(UINT UserIndex) {
	return ::UnPlugForce(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetAxisX(UINT UserIndex, SHORT Value) {
	return ::SetAxisX(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::SetAxisY(UINT UserIndex, SHORT Value) {
	return ::SetAxisY(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::SetAxisRx(UINT UserIndex, SHORT Value) {
	return ::SetAxisRx(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::SetAxisRy(UINT UserIndex, SHORT Value) {
	return ::SetAxisRy(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::SetDpadUp(UINT UserIndex) {
	return ::SetDpadUp(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadRight(UINT UserIndex) {
	return ::SetDpadRight(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadDown(UINT UserIndex) {
	return ::SetDpadDown(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadLeft(UINT UserIndex) {
	return ::SetDpadLeft(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadUpRight(UINT UserIndex) {
	return ::SetDpadUpRight(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadDownRight(UINT UserIndex) {
	return ::SetDpadDownRight(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadDownLeft(UINT UserIndex) {
	return ::SetDpadDownLeft(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadUpLeft(UINT UserIndex) {
	return ::SetDpadUpLeft(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetDpadOff(UINT UserIndex) {
	return ::SetDpadOff(UserIndex) == TRUE;
}
bool vXbox::IWrapper::SetBtnA(UINT UserIndex, bool Press) {
	return ::SetBtnA(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnB(UINT UserIndex, bool Press) {
	return ::SetBtnB(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnX(UINT UserIndex, bool Press) {
	return ::SetBtnX(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnY(UINT UserIndex, bool Press) {
	return ::SetBtnY(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnStart(UINT UserIndex, bool Press) {
	return ::SetBtnStart(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnBack(UINT UserIndex, bool Press) {
	return ::SetBtnBack(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnLT(UINT UserIndex, bool Press) {
	return ::SetBtnLT(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnRT(UINT UserIndex, bool Press) {
	return ::SetBtnRT(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnLB(UINT UserIndex, bool Press) {
	return ::SetBtnLB(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetBtnRB(UINT UserIndex, bool Press) {
	return ::SetBtnRB(UserIndex, (Press ? TRUE : FALSE)) == TRUE;
}
bool vXbox::IWrapper::SetTriggerL(UINT UserIndex, BYTE Value) {
	return ::SetTriggerL(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::SetTriggerR(UINT UserIndex, BYTE Value) {
	return ::SetTriggerR(UserIndex, Value) == TRUE;
}
bool vXbox::IWrapper::GetLedNumber(UINT UserIndex, PBYTE pLed) {
	return ::GetLedNumber(UserIndex, pLed) == TRUE;
}

bool vXbox::IWrapper::GetVibration(UINT UserIndex, PXINPUT_VIBRATION pVib) {
	return ::GetVibration(UserIndex, pVib) == TRUE;
}


#pragma region Legacy Interface Functions
/////	General driver data
SHORT vXbox::IWrapper::GetvJoyVersion(void) {
	return ::GetvJoyVersion();
}

bool vXbox::IWrapper::vJoyEnabled(void) {
	return ::vJoyEnabled() == TRUE;
}
PVOID vXbox::IWrapper::GetvJoyProductString(void) {
	return ::GetvJoyProductString();
}
PVOID vXbox::IWrapper::GetvJoyManufacturerString(void) {
	return ::GetvJoyManufacturerString();
}
PVOID vXbox::IWrapper::GetvJoySerialNumberString(void) {
	return ::GetvJoySerialNumberString();
}
//BOOL	 	DriverMatch(WORD * DllVer, WORD * DrvVer);
//VOID	 	RegisterRemovalCB(RemovalCB cb, PVOID data);
bool vXbox::IWrapper::vJoyFfbCap(bool * Supported) {
	BOOL s = Supported ? TRUE : FALSE;
	return ::vJoyFfbCap(&s) == TRUE;
}
bool vXbox::IWrapper::GetvJoyMaxDevices(int * n) {
	return ::GetvJoyMaxDevices(n) == TRUE;	
}
bool vXbox::IWrapper::GetNumberExistingVJD(int * n) {
	return ::GetNumberExistingVJD(n) == TRUE;
}

/////	vJoy Device properties
int vXbox::IWrapper::GetVJDButtonNumber(UINT rID) {
	return ::GetVJDButtonNumber(rID);
}
int vXbox::IWrapper::GetVJDDiscPovNumber(UINT rID) {
	return ::GetVJDDiscPovNumber(rID);
}
int vXbox::IWrapper::GetVJDContPovNumber(UINT rID) {
	return ::GetVJDContPovNumber(rID);
}
bool vXbox::IWrapper::GetVJDAxisExist(UINT rID, UINT Axis) {
	return ::GetVJDAxisExist(rID, Axis) == TRUE;
}
bool vXbox::IWrapper::GetVJDAxisMax(UINT rID, UINT Axis, LONG * Max) {
	return ::GetVJDAxisMax(rID, Axis, Max) == TRUE;
}
bool vXbox::IWrapper::GetVJDAxisMin(UINT rID, UINT Axis, LONG * Min) {
	return ::GetVJDAxisMin(rID, Axis, Min) == TRUE;
}
int vXbox::IWrapper::GetVJDStatus(UINT rID) {
	// return value match with "CLR" enum
	VjdStat ret = ::GetVJDStatus(rID);
	for each (VjdStat stat in vXbox::Enums::All) {
		if (stat == ret)
			return stat;
	};
	return VJD_STAT_UNKN;
}

bool vXbox::IWrapper::isVJDExists(UINT rID) {
	return ::isVJDExists(rID) == TRUE;
}

/////	Write access to vJoy Device - Basic
bool vXbox::IWrapper::AcquireVJD(UINT rID) {
	return ::AcquireVJD(rID) == TRUE;
}

VOID  vXbox::IWrapper::RelinquishVJD(UINT rID) {
	::RelinquishVJD(rID);
}

//// Reset functions
bool vXbox::IWrapper::ResetVJD(UINT rID) {
	return ::ResetVJD(rID) == TRUE;
}
VOID vXbox::IWrapper::ResetAll(void) {
	::ResetAll();
}
bool vXbox::IWrapper::ResetButtons(UINT rID) {
	return ::ResetButtons(rID) == TRUE;
}
bool vXbox::IWrapper::ResetPovs(UINT rID) {
	return ::ResetPovs(rID) == TRUE;
}

// Write data
bool vXbox::IWrapper::UpdateVJD(UINT rID, PVOID pData) {
	return ::UpdateVJD(rID, pData) == TRUE;
}
bool vXbox::IWrapper::SetAxis(LONG Value, UINT rID, UINT Axis) {
	return ::SetAxis(Value, rID, Axis) == TRUE;
}
bool vXbox::IWrapper::SetBtn(bool Value, UINT rID, UCHAR nBtn) {
	return ::SetBtn((Value ? TRUE : FALSE), rID, nBtn) == TRUE;
}
bool vXbox::IWrapper::SetDiscPov(int Value, UINT rID, UCHAR nPov) {
	return ::SetDiscPov(Value, rID, nPov) == TRUE;
}
bool vXbox::IWrapper::SetContPov(DWORD Value, UINT rID, UCHAR nPov) {
	return ::SetContPov(Value, rID, nPov) == TRUE;
}
#pragma endregion