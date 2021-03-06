///*----------------------------------------------------------------------------
// *      doorLock_data.c
// *----------------------------------------------------------------------------
// *      Name:    doorLock_data.c
// *---------------------------------------------------------------------------*/
//
#include "doorlock_data.h"


// time data
int year = 1999;
int month = 12;
int day = 31;
int hour  = 23;
int minute = 59;
int second = 40  ;
int dayInmonth[13] = { 1,31,28,31,30,31,30,31,31,30,31,30,31 };
void time_update(void) {
	int carry;
	second++;
	carry = second / 60;
	second %= 60;

	minute += carry;
	carry = minute / 60;
	minute %= 60;

	hour += carry;
	carry = hour / 24;
	hour %= 24;

	day--;
	day += carry;
	carry = day / (dayInmonth[month]);
	day %= (dayInmonth[month]);
	day++;

	month--;
	month += carry;
	carry = month / 12;
	month %= 12;
	month++;

	year += carry;
}
void setTimer(int YYYY, int MM, int DD, int hh, int mm, int ss  ) {
	year = YYYY;
	month = MM;
	day = DD;
	hour = hh;
	minute = mm;
	second = ss;
}
int getTime(int timeType) {
	switch (timeType){
	case YEAR: return year;
	case MONTH: return month;
	case DAY: return day;
	case HOUR: return hour;
	case MINUTE: return minute;
	case SECOND: return second;
	default:return  -1; 
	}
}


//request flag
bool _isRequestedPermission = false;
bool isRequestedPermission(void) {
	return _isRequestedPermission;
}
void setRequsetPermission(bool value) {
	_isRequestedPermission = value;
}

//password data
int pwd[PASSWORD_SIZE];
int pwdSize = 0;
void clearPwd(void) {
	pwd[0] = 0;
	pwd[1] = 0;
	pwd[2] = 0;
	pwd[3] = 0;
	pwdSize = 0;
}
void setPwd(int pwdValue) {
	if (pwdSize >= 4) return;
		pwd[pwdSize] = pwdValue;
		pwdSize++;
}
int getPwd_i(int index) {
	return pwd[index];
}
int getPwdSize(void) {
	return pwdSize;
}
void popbackPwd(void) {
	if (pwd > 0) {
		pwdSize--;
		pwd[pwdSize] = 0;
	}
}

// log
//50개 정도 보관함.
//uart data

bool _isServerConnected = false;
bool isServerConnected(void) {
	return  _isServerConnected;
}
void set_isServerConnected(bool flag) {
	_isServerConnected = flag;
}


int connectionCounter = TOP_CONNECTION_COUNTER;
void connectionCountDown(void) {
	connectionCounter--;
}
bool isConnectionCountZero(void) {
	if (connectionCounter <= 0)
		return true;
	else		
		return false;
}
void resetConnectionCounter(void) {
	connectionCounter = TOP_CONNECTION_COUNTER;
}


int SelectedLockerNumber = 0;
int getSelectedLockerNumber(void) {
	return SelectedLockerNumber;
}
void setSelectedLockerNumber(int num) {
	SelectedLockerNumber = num;
}

int currentSystemMode = SYSTEM_MODE_SELECT_LOCKER_NUMBER;
bool _isChangedCurrentSystemMode = false;
bool isChangedCurrentSystemMode(void) {
	if (_isChangedCurrentSystemMode == true) {
		_isChangedCurrentSystemMode = false;
		return true;
	}
	return false;
}
int getCurrentSystemMode(void) {
	return currentSystemMode;

}
void setCurrentSustemMode(int mode) {
	if (currentSystemMode != mode) {
		currentSystemMode = mode;
		_isChangedCurrentSystemMode = true;
	}
}



int _requestPermissionMsgCounter = 0;
void sendingMsgCountDown(void) {
	_requestPermissionMsgCounter--;
	if (_requestPermissionMsgCounter < 0)
		_requestPermissionMsgCounter = 0;
}
void resetSendingMsgCounter(void) {
	_requestPermissionMsgCounter = SENDING_MSG_COUNT_TOP;
}
bool isSendingMsgCounterZero(void){
	if (_requestPermissionMsgCounter == 0)
		return true;
	return false;
}



