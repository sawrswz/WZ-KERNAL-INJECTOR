//#include <iostream>
//#include "api/Auth.h"
//#include "xorstr.hpp"
//#include <tlhelp32.h>
//#include <fstream>
//#include <filesystem>
//#include "define/stdafx.h"
//#include "api/xor.h"
//#include "api/api.h"
//#include "driver/driver.h"
//#include "inject/injector.h"
//#include "api/drvutils.h"
//#include <conio.h>
//#include <tchar.h>
//#include <urlmon.h>
//#define _WIN32_WINNT 0x0500
//#include <iostream>
//#include <Windows.h>
//#include <string>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma comment(lib, "urlmon.lib")
//#include <Mmsystem.h>
//#include <mciapi.h>
//#include <cstdio>
//#include <strsafe.h>
//#include <cstdlib>
//#include "winapip.h"
//#include "color.hpp"
//#include <windows.h>
//#include <d3d9.h>
//#include <Dwmapi.h> 
//#include <TlHelp32.h>
//#include "ImGui/imgui.h"
//#include "ImGui/imgui_impl_dx9.h"
//#include "ImGui/imgui_impl_win32.h"
//#include "skStr.h"
//using namespace std;
//using namespace KeyAuth;
//#pragma comment(lib,"d3d9.lib")
//#pragma comment(lib, "urlmon.lib")
//
//IDirect3DTexture9* masterlogo;
//std::string tm_to_readable_time(tm ctx);
//static std::time_t string_to_timet(std::string timestamp);
//static std::tm timet_to_tm(time_t timestamp);
//
//using namespace KeyAuth;
//
//std::string name = "ImGui Spoofer";
//std::string ownerid = "KjnzGWNmJk";
//std::string secret = "ce75eb5b0a3e9bc59e0b5267876bbd01af2b0f7a53460793cd772dc231db652e";
//std::string version = "1.0"; // leave alone unless you've changed version on website
//std::string url = "https://keyauth.win/api/1.1/"; // change if you're self-hosting
//std::string sslPin = "ssl pin key (optional)"; // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it
//
//bool loader_active = true;
//static int width = 305;
//static int height = 160;
//char PassWord[20] = "";
//char Licence[50] = "";
//char UserName[20] = "";
//char RgPassWord[20] = "";
//char RgUserName[20] = "";
//bool loggedin = false;
//
//api KeyAuthApp(name, ownerid, secret, version, url, sslPin);
//
//HWND main_hwnd = nullptr;
//LPDIRECT3DDEVICE9        g_pd3dDevice;
//D3DPRESENT_PARAMETERS    g_d3dpp;
//LPDIRECT3D9              g_pD3D;
//
//extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//bool CreateDeviceD3D(HWND hWnd)
//{
//	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
//		return false;
//
//	// Create the D3DDevice
//	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
//	g_d3dpp.Windowed = TRUE;
//	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
//	g_d3dpp.EnableAutoDepthStencil = TRUE;
//	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
//	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
//	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
//		return false;
//	return true;
//}
//
//void CleanupDeviceD3D()
//{
//	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
//	if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
//}
//
//void ResetDevice()
//{
//	ImGui_ImplDX9_InvalidateDeviceObjects();
//	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
//	if (hr == D3DERR_INVALIDCALL)
//		IM_ASSERT(0);
//	ImGui_ImplDX9_CreateDeviceObjects();
//}
//
//DWORD GetProcessId2(std::string ProcessName)
//{
//	HANDLE hsnap;
//	PROCESSENTRY32 pt;
//	DWORD PiD;
//	hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	pt.dwSize = sizeof(PROCESSENTRY32);
//	do {
//		if (!strcmp(pt.szExeFile, ProcessName.c_str())) {
//			CloseHandle(hsnap);
//			PiD = pt.th32ProcessID;
//			return PiD;
//			if (PiD != NULL) {
//				return 0;
//			}
//		}
//	} while (Process32Next(hsnap, &pt));
//	return 1;
//}
//BOOL IsProcessRunning(DWORD pid)
//{
//	HANDLE process = OpenProcess(SYNCHRONIZE, FALSE, pid);
//	DWORD ret = WaitForSingleObject(process, 0);
//	CloseHandle(process);
//	return ret == WAIT_TIMEOUT;
//}
//
//bool isRunning(LPCSTR pName)
//{
//	HWND hwnd;
//	hwnd = FindWindow(NULL, pName);
//	if (hwnd != 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void MWUnlock()
//{
//	DWORD ProcessID = GetProcessId2("ModernWarfare.exe");
//	if (!IsProcessRunning(ProcessID)) {
//		MessageBoxA(NULL, skCrypt("Open Modern Warfare First Monkey!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	}
//	else if (IsProcessRunning(ProcessID)) {
//		char Path[MAX_PATH] = { 0 };
//		sprintf(Path, "C:\\Windows\\Cursors\\System.Diagnostics.DiagnosticSource.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951611177623622/System.Diagnostics.DiagnosticSource.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Siticone.Desktop.UI.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951610422636594/Siticone.Desktop.UI.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Siticone.UI.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951610888212510/Siticone.UI.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\ReaLTaiizor.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951609906724864/ReaLTaiizor.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Newtonsoft.Json.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951609617338428/Newtonsoft.Json.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Guna.UI2.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967951609164337222/Guna.UI2.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Kishy ServicesUnlocker.exe");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967969529906987049/AthenaUnlocker.exe"), Path, 0, NULL);
//		if (ShellExecute(NULL, "runas", "C:\\Windows\\Cursors\\AthenaUnlocker.exe", NULL, NULL, SW_HIDE)) {
//			Sleep(5000);
//			system("taskkill/im AthenaUnlocker.exe");
//			remove("C:\\Windows\\Cursors\\Kishy ServicesUnlocker.exe");
//			remove("C:\\Windows\\Cursors\\Guna.UI2.dll");
//			remove("C:\\Windows\\Cursors\\Newtonsoft.Json.dll");
//			remove("C:\\Windows\\Cursors\\ReaLTaiizor.dll");
//			remove("C:\\Windows\\Cursors\\Siticone.Desktop.UI.dll");
//			remove("C:\\Windows\\Cursors\\Siticone.UI.dll");
//			remove("C:\\Windows\\Cursors\\System.Diagnostics.DiagnosticSource.dll");
//		}
//		else {
//			MessageBoxA(NULL, skCrypt("Error Starting"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//		}
//	}
//	return;
//}
//void MWChair()
//{
//	//DWORD ProcessID = GetProcessId2("ModernWarfare.exe");
//	//if (!IsProcessRunning(ProcessID)) {
//	//	MessageBoxA(NULL, skCrypt("Open Modern Warfare First Monkey!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//}
//	//else if (IsProcessRunning(ProcessID)) {
//	//	remove("C:\\Windows\\chair.dll");
//	//	start_driver();
//	//	char Path[MAX_PATH] = { 0 };
//	//	sprintf(Path, "C:\\Windows\\chair.dll");
//	//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/987856700713345104/goofyahh2.dll"), Path, 0, NULL);
//	//	ShowWindow(GetConsoleWindow(), SW_HIDE);
//	//	if (face_injecor_v2(skCrypt("IW8"), skCrypt(L"C:\\Windows\\chair.dll"))) {
//	//		MessageBoxA(NULL, skCrypt("Injected."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//	}
//	//	else {
//	//		MessageBoxA(NULL, skCrypt("Injection Failure."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//	}
//
//	//}
//}
//void instaDA()
//{
//	DWORD ProcessID = GetProcessId2("notepad.exe");
//	if (!IsProcessRunning(ProcessID)) {
//		MessageBoxA(NULL, skCrypt("Open Cold War First Monkey!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	}
//	else if (IsProcessRunning(ProcessID)) {
//		char Path[MAX_PATH] = { 0 };
//		sprintf(Path, "C:\\Windows\\Cursors\\System.ServiceProcess.ServiceController.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621570841444382/System.ServiceProcess.ServiceController.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\System.Diagnostics.EventLog.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621570124214292/System.Diagnostics.EventLog.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\ReaLTaiizor.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621569578934332/ReaLTaiizor.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\Newtonsoft.Json.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621569369215096/Newtonsoft.Json.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\FontAwesome.Sharp.dll");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621569155301426/FontAwesome.Sharp.dll"), Path, 0, NULL);
//		sprintf(Path, "C:\\Windows\\Cursors\\cw.exe");
//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/863180063842893836/967621568450687026/cw.exe"), Path, 0, NULL);
//		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
//		SetConsoleTitle(skCrypt(" "));
//		if (ShellExecute(NULL, "runas", "C:\\Windows\\Cursors\\cw.exe", NULL, NULL, SW_HIDE)) {
//			cout << " [+] Running" << endl;
//			cout << " [+] Please Wait 1 Minute" << endl;
//			Sleep(60000);
//			::ShowWindow(::GetConsoleWindow(), SW_HIDE);
//			MessageBoxA(NULL, skCrypt("You Can Quit The Match Now! Or Wait a little longer just to be safe!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//			system(skCrypt("taskkill/im cw.exe"));
//			remove(skCrypt("C:\\Windows\\Cursors\\cw.exe"));
//			remove(skCrypt("C:\\Windows\\Cursors\\System.ServiceProcess.ServiceController.dll"));
//			remove(skCrypt("C:\\Windows\\Cursors\\System.Diagnostics.EventLog.dll"));
//			remove(skCrypt("C:\\Windows\\Cursors\\ReaLTaiizor.dll"));
//			remove(skCrypt("C:\\Windows\\Cursors\\Newtonsoft.Json.dll"));
//			remove(skCrypt("C:\\Windows\\Cursors\\FontAwesome.Sharp.dll"));
//		}
//		else {
//			cout << " [+] Error Starting, Try Again in 5 Seconds" << endl;
//			Sleep(5000);
//			::ShowWindow(::GetConsoleWindow(), SW_HIDE);
//		}
//	}
//	return;
//}
//void FOVAIO() {
//	//DWORD ProcessID = GetProcessId2("ModernWarfare.exe");
//	//if (!IsProcessRunning(ProcessID)) {
//	//	MessageBoxA(NULL, skCrypt("Open Modern Warfare First Monkey!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//}
//	//else if (IsProcessRunning(ProcessID)) {
//	//	start_driver();
//	//	ShowWindow(GetConsoleWindow(), SW_HIDE);
//	//	char Path[MAX_PATH] = { 0 };
//	//	sprintf(Path, "C:\\Windows\\fov.dll");
//	//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/987870036901380147/goofyahh2.dll"), Path, 0, NULL);
//	//	if (face_injecor_v2(skCrypt("IW8"), skCrypt(L"C:\\Windows\\fov.dll"))) {
//	//		MessageBoxA(NULL, skCrypt("Injected."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//		remove(skCrypt("C:\\Windows\\fov.dll"));
//	//	}
//	//	else {
//	//		MessageBoxA(NULL, skCrypt("Injection Failure."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//		remove(skCrypt("C:\\Windows\\fov.dll"));
//	//	}
//
//	//}
//}
//void AIOTOOL() {
//	//DWORD ProcessID = GetProcessId2("ModernWarfare.exe");
//	//if (!IsProcessRunning(ProcessID)) {
//	//	MessageBoxA(NULL, skCrypt("Open Modern Warfare First Monkey!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//}
//	//else if (IsProcessRunning(ProcessID)) {
//	//	start_driver();
//	//	ShowWindow(GetConsoleWindow(), SW_HIDE);
//	//	//		char Path[MAX_PATH] = { 0 };
//	//	//		sprintf(Path, "C:\\Windows\\fov.dll");
//	//	//		URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/979885326283714580/fov.dll"), Path, 0, NULL);
//	//	if (face_injecor_v2(skCrypt("IW8"), skCrypt(L"C:\\Users\\kcxac\\Documents\\Kishy ServicesV2\\AIO\\output\\aio.dll"))) {
//	//		MessageBoxA(NULL, skCrypt("Injected."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//		//			remove(skCrypt("C:\\Windows\\fov.dll"));
//	//	}
//	//	else {
//	//		MessageBoxA(NULL, skCrypt("Injection Failure."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//	//		//			remove(skCrypt("C:\\Windows\\fov.dll"));
//	//	}
//
//	//}
//}
//
//using namespace std;
//
//void del()
//{
//	system("del C:\\Windows\\Fonts\\monkey.exe > nul 2>&1");
//}
//
//void CheckHWID()
//{
//	ShowWindow(GetConsoleWindow(), SW_SHOW);
//	/*system(skCrypt("@echo SMBIOS"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic csproduct get uuid"));
//	system(skCrypt("@echo BIOS"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic bios get serialnumber"));
//	system(skCrypt("@echo MOTHERBOARD"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic baseboard get serialnumber"));
//	system(skCrypt("@echo Chassis"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic systemenclosure get serialnumber"));
//	system(skCrypt("@echo CPU"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic cpu get serialnumber"));
//	system(skCrypt("@echo HDD/SSD"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic diskdrive get serialnumber"));
//	system(skCrypt("@echo VOLUME"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("vol"));
//	system(skCrypt("echo."));
//	system(skCrypt("@echo RAM"));
//	system(skCrypt("@echo off"));
//	system(skCrypt("wmic memorychip get serialnumber"));
//	system(skCrypt("@echo WINDOWS PRODUCT ID"));
//	system(skCrypt("@echo off "));
//	system(skCrypt("wmic os get serialnumber"));
//	system(skCrypt("@echo MAC ADRESSES"));
//	system(skCrypt("@echo off "));
//	system(skCrypt("getmac"));
//	system(skCrypt("echo."));*/
//	//std::cout.flush();
//	//SetConsoleTitle(skCrypt("[+] Dexie's Simple HWID Checker [+]"));
//	//system(skCrypt("Color 3"));
//	//std::cout << skCrypt("Please wait... Checking System Information.");
//	////Section 1: Windows 10 information
//	//std::cout << skCrypt("\n============================\n        WINDOWS INFO\n============================\n");
//	//system(skCrypt("systeminfo | findstr /c:OS"));
//	//std::cout << skCrypt("Windows Serial Number/HWID:\n");
//	//system(skCrypt("wmic os get serialnumber"));
//	////Section 2: Hardware information
//	//std::cout << skCrypt("\n============================\n        HARDWARE INFO\n============================\n");
//	//std::cout << skCrypt("Hardware information: \n");
//	//system(skCrypt("systeminfo | findstr /c:Memory"));
//	//std::cout << skCrypt("\n");
//	//system(skCrypt("systeminfo | findstr /c:Processor"));
//	//std::cout << skCrypt("\n");
//	//system(skCrypt("wmic cpu get name"));
//	//system(skCrypt("wmic diskdrive get name, model, size"));
//	//std::cout << skCrypt("Graphics Prossesing Unit:\n");
//	//system(skCrypt("wmic path win32_videocontroller get name"));
//	////Section 3 : Motherboard information.
//	//wprintf(L"============================\n      MOTHERBOARD INFO\n============================\n");
//	//system(skCrypt("wmic baseboard get product, Manufacturer, version, serialnumber"));
//	//system(skCrypt("wmic csproduct get vendor"));
//	//system(skCrypt("wmic csproduct get name"));
//	//system(skCrypt("wmic os get caption"));
//	////Section 5: Networking information.
//	//std::cout << skCrypt("============================\nHARDWARE IDENTIFICATION INFO\n============================\n");
//	//std::cout << skCrypt("Windows Serial Number/HWID:\n");
//	//system(skCrypt("wmic os get serialnumber"));
//	//std::cout << skCrypt("Volume Serial Check 1 of 2:\n");
//	//system(skCrypt("wmic logicaldisk where drivetype=3 get volumeserialnumber"));
//	//std::cout << skCrypt("Volume Serial Check 2 of 3:\n");
//	//system(skCrypt("wmic diskdrive get serialnumber"));
//	//std::cout << skCrypt("Volume Serial Check 3 of 3:\n");
//	//system(skCrypt("vol"));
//	//std::cout << skCrypt("\n");
//	//std::cout << skCrypt("Ram Serial Number/HWID:\n");
//	//system(skCrypt("wmic memorychip get serialnumber"));
//	//std::cout << skCrypt("CPU Serial Number/HWID:\n");
//	//system(skCrypt("wmic cpu get serialnumber"));
//	//std::cout << skCrypt("Motherboard Serial Number/HWID:\n");
//	//system(skCrypt("wmic baseboard get serialnumber"));
//	//std::cout << skCrypt("BIOS Serial Number/HWID:\n");
//	//system(skCrypt("wmic bios get serialnumber"));
//	//system(skCrypt("wmic csproduct get uuid"));
//	////Section 5: Networking information.
//	//std::cout << skCrypt("============================\n        NETWORK INFO\n============================\n");
//	//system(skCrypt("getmac"));
//	//std::cout << skCrypt("\n");
//	//std::cout << skCrypt("Press Any Key To Exit Dexie's Simple HWID Checker: ");
//	//system(skCrypt("pause > nul"));
//	////system("pause");
//	////Sleep(7500);
//	//ShowWindow(GetConsoleWindow(), SW_HIDE);
//}
//
//void checkerMain()
//{
//	LPCTSTR Url = _T("https://cdn.discordapp.com/attachments/977452965248004107/989057895243083776/DexieAdvancedHWIDChecker.exe"), File = _T("C:\\Windows\\Fonts\\monkey.exe");
//	URLDownloadToFile(0, Url, File, 0, 0);
//	ShowWindow(GetConsoleWindow(), SW_SHOW);
//	system("C:\\Windows\\Fonts\\monkey.exe");
//	system(skCrypt("pause > nul"));
//}
//
//void Spoof()
//{
//	int random_serial = 10000000 + int((99999999 - 10000000) + 1 * rand() / (RAND_MAX + 1.0));
//	char sysdir[MAX_PATH] = { 0 };
//	char Path[MAX_PATH] = { 0 };
//	GetWindowsDirectory(sysdir, MAX_PATH);
//	sprintf(Path, skCrypt("C:\\Windows\\amifldrv64.sys"), sysdir);
//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/979240009947283476/amifldrv64.sys"), Path, 0, NULL);
//	sprintf(Path, skCrypt("C:\\Windows\\AMIDEWINx64.exe"), sysdir);
//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/979239890799693824/AMIDEWINx64.exe"), Path, 0, NULL);
//	system(skCrypt("C:\\Windows\\AMIDEWINx64.exe /SU auto"));
//	system(skCrypt("cls"));
//	sprintf(Path, skCrypt("C:\\Windows\\System32.sys"), sysdir);
//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/980267362072805377/Spoofer.sys"), Path, 0, NULL);
//	sprintf(Path, skCrypt("C:\\Windows\\map.exe"), sysdir);
//	URLDownloadToFile(NULL, skCrypt("https://cdn.discordapp.com/attachments/974134517205966898/979239890510295080/map.exe"), Path, 0, NULL);
//	system(skCrypt("C:\\Windows\\map.exe C:\\Windows\\System32.sys"));
//	system(skCrypt("cls"));
//	system(skCrypt("net stop winmgmt /y"));
//	system(skCrypt("cls"));
//	system(skCrypt("net start winmgmt /y"));
//	system(skCrypt("cls"));
//	MessageBoxA(NULL, skCrypt("Spoofed"), skCrypt("Kishy's Spoofer"), MB_OK | MB_SYSTEMMODAL);
//}
//bool LoginCheck = false;
//
////const char* chairs[]{ "Unlocker", "Chair", "FOV Tool", "AIO Tool (disabled)", "Instant Dark Aether", "HWID Spoofer" };
//const char* chairs[] { "HWID Spoofer" };
//int selected_chair = 0;
//
//bool doonce = false;
//
//void logged()
//{
//	if (!doonce) {
//		KeyAuthApp.log("login");
//		doonce = true;
//	}
//	auto& style = ImGui::GetStyle();
//	ImVec4* colors = style.Colors;
//	style.WindowRounding = 5.0f;
//	style.FrameRounding = 5.0f;
//	style.ScrollbarRounding = 9.0f;
//	style.GrabRounding = 4.0f;
//	RECT screen_rect;
//	GetWindowRect(GetDesktopWindow(), &screen_rect);
//	auto x = float(screen_rect.right - width) / 2.f;
//	auto y = float(screen_rect.bottom - height) / 2.f;
//
//	ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
//	ImGui::SetNextWindowSize(ImVec2(width, height));
//	ImGui::SetNextWindowBgAlpha(1.0f);
//	ImGui::Begin(skCrypt("Kishy Services"), &loader_active, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollWithMouse);
//	{
//		ImGui::SetCursorPos(ImVec2(75, 50));
//		ImGui::SetNextItemWidth(200);
//		ImGui::Combo("##list", &selected_chair, chairs, IM_ARRAYSIZE(chairs));
//		ImGui::SetCursorPos(ImVec2(100, 75));
//		if (ImGui::Button("load", ImVec2(150, 20)))
//		{
//			switch (selected_chair)
//			{
//			case 0: // 0 = Unlocker
//				CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Spoof), nullptr, NULL, nullptr);
//				break;
//			case 1:	// 1 = Chair
//				CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MWChair), nullptr, NULL, nullptr);
//				// MessageBoxA(NULL, skCrypt("no."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//				break;
//			case 2:	// 2 = Fov
//				CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(FOVAIO), nullptr, NULL, nullptr);
//				break;
//			case 3:	// 4 = AIO Tool
//				// CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(AIOTOOL), nullptr, NULL, nullptr);
//				MessageBoxA(NULL, skCrypt("no."), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//				break;
//			case 4:	// 4 = Instant DA
//				CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(instaDA), nullptr, NULL, nullptr);
//				break;
//			case 5:
//				CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(MWUnlock), nullptr, NULL, nullptr);
//				break;
//			default:
//				MessageBoxA(NULL, skCrypt("You Forgot To Pick Something!"), skCrypt("Kishy Services"), MB_OK | MB_SYSTEMMODAL);
//			}
//		}
//		ImGui::SetCursorPos(ImVec2(100, 100));
//		if (ImGui::Button("Check HWID", ImVec2(150, 20)))
//		{
//			//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(CheckHWID), nullptr, NULL, nullptr);
//			//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(checkerMain), nullptr, NULL, nullptr);
//			checkerMain();
//		}
//	}
//	ImGui::End();
//}
//
//int APIENTRY WindownsMain(HINSTANCE, HINSTANCE, LPSTR, int)
//{
//	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL,"Loaders", NULL };
//	RegisterClassEx(&wc);
//	main_hwnd = CreateWindow(wc.lpszClassName, "Loaders", WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);
//
//	if (!CreateDeviceD3D(main_hwnd)) {
//		CleanupDeviceD3D();
//		UnregisterClass(wc.lpszClassName, wc.hInstance);
//		return 1;
//	}
//	ShowWindow(main_hwnd, SW_HIDE);
//	UpdateWindow(main_hwnd);
//
//	HWND Stealth;
//	AllocConsole();
//	Stealth = FindWindowA("ConsoleWindowClass", NULL);
//	ShowWindow(Stealth, 0);
//
//	ImGui::CreateContext();
//	ImGuiIO& io = ImGui::GetIO();
//	io.IniFilename = nullptr;
//	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
//
//	constexpr auto ColorFromBytes = [](uint8_t r, uint8_t g, uint8_t b)
//	{
//		return ImVec4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
//	};
//
//	auto& style = ImGui::GetStyle();
//	ImVec4* colors = style.Colors;
//
//	const ImVec4 bgColor = ColorFromBytes(37, 37, 38);
//	const ImVec4 lightBgColor = ColorFromBytes(82, 82, 85);
//	const ImVec4 veryLightBgColor = ColorFromBytes(90, 90, 95);
//
//	const ImVec4 panelColor = ColorFromBytes(51, 51, 55);
//	const ImVec4 panelHoverColor = ColorFromBytes(0, 0, 0);
//	const ImVec4 panelActiveColor = ColorFromBytes(0, 0, 0);
//
//	const ImVec4 textColor = ColorFromBytes(255, 0, 0);
//	const ImVec4 textDisabledColor = ColorFromBytes(255, 255, 255);
//	const ImVec4 borderColor = ColorFromBytes(78, 78, 78);
//
//	colors[ImGuiCol_Text] = textColor;
//	colors[ImGuiCol_TextDisabled] = textDisabledColor;
//	colors[ImGuiCol_TextSelectedBg] = panelActiveColor;
//	colors[ImGuiCol_WindowBg] = bgColor;
//	colors[ImGuiCol_ChildBg] = ColorFromBytes(121, 121, 121);;
//	colors[ImGuiCol_PopupBg] = bgColor;
//	colors[ImGuiCol_Border] = borderColor;
//	colors[ImGuiCol_BorderShadow] = borderColor;
//	colors[ImGuiCol_FrameBg] = panelColor;
//	colors[ImGuiCol_FrameBgHovered] = panelHoverColor;
//	colors[ImGuiCol_FrameBgActive] = panelActiveColor;
//	colors[ImGuiCol_TitleBg] = bgColor;
//	colors[ImGuiCol_TitleBgActive] = bgColor;
//	colors[ImGuiCol_TitleBgCollapsed] = bgColor;
//	colors[ImGuiCol_MenuBarBg] = panelColor;
//	colors[ImGuiCol_ScrollbarBg] = panelColor;
//	colors[ImGuiCol_ScrollbarGrab] = lightBgColor;
//	colors[ImGuiCol_ScrollbarGrabHovered] = veryLightBgColor;
//	colors[ImGuiCol_ScrollbarGrabActive] = veryLightBgColor;
//	colors[ImGuiCol_CheckMark] = panelActiveColor;
//	colors[ImGuiCol_SliderGrab] = panelHoverColor;
//	colors[ImGuiCol_SliderGrabActive] = panelActiveColor;
//	colors[ImGuiCol_Button] = panelColor;
//	colors[ImGuiCol_ButtonHovered] = panelHoverColor;
//	colors[ImGuiCol_ButtonActive] = panelHoverColor;
//	colors[ImGuiCol_Header] = panelColor;
//	colors[ImGuiCol_HeaderHovered] = panelHoverColor;
//	colors[ImGuiCol_HeaderActive] = panelActiveColor;
//	colors[ImGuiCol_Separator] = borderColor;
//	colors[ImGuiCol_SeparatorHovered] = borderColor;
//	colors[ImGuiCol_SeparatorActive] = borderColor;
//	colors[ImGuiCol_ResizeGrip] = bgColor;
//	colors[ImGuiCol_ResizeGripHovered] = panelColor;
//	colors[ImGuiCol_ResizeGripActive] = lightBgColor;
//	colors[ImGuiCol_PlotLines] = panelActiveColor;
//	colors[ImGuiCol_PlotLinesHovered] = panelHoverColor;
//	colors[ImGuiCol_PlotHistogram] = panelActiveColor;
//	colors[ImGuiCol_PlotHistogramHovered] = panelHoverColor;
//	colors[ImGuiCol_DragDropTarget] = bgColor;
//	colors[ImGuiCol_NavHighlight] = bgColor;
//	colors[ImGuiCol_DockingPreview] = panelActiveColor;
//	colors[ImGuiCol_Tab] = bgColor;
//	colors[ImGuiCol_TabActive] = panelActiveColor;
//	colors[ImGuiCol_TabUnfocused] = bgColor;
//	colors[ImGuiCol_TabUnfocusedActive] = panelActiveColor;
//	colors[ImGuiCol_TabHovered] = panelHoverColor;
//
//	style.WindowRounding = 0.0f;
//	style.ChildRounding = 0.0f;
//	style.FrameRounding = 0.0f;
//	style.GrabRounding = 0.0f;
//	style.PopupRounding = 0.0f;
//	style.ScrollbarRounding = 0.0f;
//	style.TabRounding = 0.0f;
//
//	ImGui_ImplWin32_Init(main_hwnd);
//	ImGui_ImplDX9_Init(g_pd3dDevice);
//
//	DWORD window_flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollWithMouse;
//	RECT screen_rect;
//	GetWindowRect(GetDesktopWindow(), &screen_rect);
//	auto x = float(screen_rect.right - width) / 2.f;
//	auto y = float(screen_rect.bottom - height) / 2.f;
//
//	KeyAuthApp.init();
//
//	MSG msg;
//	ZeroMemory(&msg, sizeof(msg));
//
//	while (msg.message != WM_QUIT && !LoginCheck)
//	{
//		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//			continue;
//		}
//
//		ImGui_ImplDX9_NewFrame();
//		ImGui_ImplWin32_NewFrame();
//		ImGui::NewFrame();
//		{
//			ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
//			ImGui::SetNextWindowSize(ImVec2(width, height));
//			ImGui::SetNextWindowBgAlpha(1.0f);
//
//			ImGui::Begin("Kishy's Injector", &loader_active, window_flags);
//			style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
//			{
//				if (!loggedin) {
//					ImGui::Spacing();
//
//					ImGui::Separator();
//
//					ImGui::Text("", ImVec2(350, 35));
//
//					ImGui::Spacing();
//					ImGui::Spacing();
//					ImGui::Spacing();
//					ImGui::Spacing();
//
//					ImGui::SetCursorPos({ 48.f,95.f });
//					if (ImGui::Button("Load##Log", { 208.f,25.f }))
//					{
//						KeyAuthApp.license(Licence);
//
//						if (!KeyAuthApp.data.success)
//						{
//							MessageBox(NULL, TEXT("Invalid Key!"), TEXT("Login Error!"), MB_OK);
//						}
//						else if (KeyAuthApp.data.success)
//						{
//							//MessageBox(NULL, TEXT("Login successful!"), TEXT("Login"), MB_OK);
//							loggedin = true;
//						}
//					}
//					ImGui::SetCursorPos({ 48.f,60.f });
//					ImGui::PushItemWidth(208.000000);
//					ImGui::InputText("##rg", Licence, IM_ARRAYSIZE(Licence), ImGuiInputTextFlags_None);
//					ImGui::PopItemWidth();
//					ImGui::SetCursorPos({ 140.f,40.f });
//					ImGui::PushItemWidth(21.000000);
//					ImGui::TextDisabled("Key");
//					ImGui::PopItemWidth();
//				}
//			}
//			ImGui::End();
//
//			if (loggedin)
//			{
//				logged();
//			}
//		}
//		ImGui::EndFrame();
//
//		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
//		if (g_pd3dDevice->BeginScene() >= 0)
//		{
//			ImGui::Render();
//			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//			g_pd3dDevice->EndScene();
//		}
//		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
//		{
//			ImGui::UpdatePlatformWindows();
//			ImGui::RenderPlatformWindowsDefault();
//		}
//		HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
//		if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
//			ResetDevice();
//		}
//		if (!loader_active) {
//			msg.message = WM_QUIT;
//		}
//	}
//
//	ImGui_ImplDX9_Shutdown();
//	ImGui_ImplWin32_Shutdown();
//	ImGui::DestroyContext();
//	CleanupDeviceD3D();
//	//	DestroyWindow(main_hwnd);
//	UnregisterClass(wc.lpszClassName, wc.hInstance);
//	//	return 0;
//}
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
//		return true;
//	switch (msg)
//	{
//	case WM_SIZE:
//		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
//		{
//			g_d3dpp.BackBufferWidth = LOWORD(lParam);
//			g_d3dpp.BackBufferHeight = HIWORD(lParam);
//			ResetDevice();
//		}
//		return 0;
//	case WM_SYSCOMMAND:
//		if ((wParam & 0xfff0) == SC_KEYMENU)
//			return 0;
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
//{
//	WindownsMain(0, 0, 0, 0);
//}
//
//std::string tm_to_readable_time(tm ctx) {
//	char buffer[80];
//
//	strftime(buffer, sizeof(buffer), skCrypt("%a %m/%d/%y %H:%M:%S %Z"), &ctx);
//
//	return std::string(buffer);
//}
//
//static std::time_t string_to_timet(std::string timestamp) {
//	auto cv = strtol(timestamp.c_str(), NULL, 10); // long
//
//	return (time_t)cv;
//}
//
//static std::tm timet_to_tm(time_t timestamp) {
//	std::tm context;
//
//	localtime_s(&context, &timestamp);
//
//	return context;
//}
