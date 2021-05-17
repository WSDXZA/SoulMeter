#include "pch.h"
#include ".\Packet Capture/MyWinDivert.h"
#include ".\Damage Meter/Damage Meter.h"
#include ".\UI\UiWindow.h"
#include ".\Damage Meter\MySQLite.h"

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console" )
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR cmdLine, int showCmd) {

	_wsetlocale(LC_ALL, L"Korean");

	MiniDump::Begin();
	
	if (!SWDB.Init()) {
		Log::WriteLog(const_cast<LPTSTR>(_T("InitDB Failed")));
		exit(-1);
	}

	if (WINDIVERT.Init()) {
			exit(-1);	
	}

	if(UIWINDOW.Init(1, 1, 1, 1)){
		UIWINDOW.Run();
	}

	MiniDump::End();
}