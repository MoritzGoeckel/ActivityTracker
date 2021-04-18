#pragma comment(lib, "user32")
// This includes user32 for linker

#include <windows.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

std::string getActiveWindow()
{
 char wnd_title[256];
 HWND hwnd=GetForegroundWindow();
 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
 return wnd_title;
}

DWORD getIdleTime(){
	LASTINPUTINFO lastii;
    lastii.cbSize = sizeof(LASTINPUTINFO);
    GetLastInputInfo(&lastii);
    return (GetTickCount() - lastii.dwTime) / 1000;
}

int main(int argc, char* arv[]){
	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		
		std::cout << "Title:     " << GetActiveWindowTitle() << std::endl;
		std::cout << "Idle time: " << getIdleTime() << std::endl;
	}
	return 0;
}

// cl /EHsc C:\Users\Moritz\Desktop\windows_api_test\test.cpp
// D:\Software\VS2019\VC\Auxiliary\Build\vcvars64.bat 

// D:\Software\VS2019\VC\Tools\MSVC\14.27.29110\bin\Hostx86\x86\cl

// D:\Software\VS2019\VC\Tools\MSVC\14.27.29110\bin\Hostx64\x64\cl

// D:\Software\VS2019\VC\Tools\MSVC\14.27.29110\bin\Hostx64\x64>cl /EHsc C:\Users\Moritz\Desktop\windows_api_test\test.cpp /oC:\Users\Moritz\Desktop\windows_api_test\test.exe

// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getlastinputinfo

// https://stackoverflow.com/questions/43176140/qt-c-getting-lastinputinfo-to-work