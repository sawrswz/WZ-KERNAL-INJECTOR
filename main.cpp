
#include <iostream>
#include "api/Auth.h"
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include "define/stdafx.h"
#include "api/xor.h"
#include "api/api.h"
#include "driver/driver.h"
#include "inject/injector.h"
#include "api/drvutils.h"
#include <conio.h>
#include <tchar.h>
#include <urlmon.h>
#define _WIN32_WINNT 0x0500
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "urlmon.lib")
#include <Mmsystem.h>
#include <mciapi.h>
#include <cstdio>
#include <strsafe.h>
#include <cstdlib>
#include "winapip.h"
#include "color.hpp"
#include <windows.h>
#include <d3d9.h>
#include <Dwmapi.h> 
#include <TlHelp32.h>
using namespace std;
using namespace KeyAuth;

std::string name = XorStr("sawr"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = XorStr("Xi6oCmctEq"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = XorStr("7104700c3469793cb3da95a5621461795c4d89b2f762334c3bddb98f13f38c39"); // app secret, the blurred text on licenses tab and other tabs
std::string version = XorStr("1.0"); // leave alone unless you've changed version on website

//typedef functions
using CREATE_FILE_WINAPI = HANDLE(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
using READ_FILE_WINAPI = BOOL(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
using GET_SIZE_FILE_WINAPI = DWORD(HANDLE  hFile, unsigned long* lpFileSizeHigh);

//create class winapi-importer
WinApiImport<CREATE_FILE_WINAPI> api_parser("CreateFileA", "kernel32.dll");
//if import is invalid or wrong - return null pointer
//or auto
std::function<CREATE_FILE_WINAPI> func_api = api_parser.get_function();

//or using like this
const auto f_create_file = WinApiImport<CREATE_FILE_WINAPI>::get("BCryptDecrypt", "bcrypt.dll");

extern"C"
IMAGE_DOS_HEADER __ImageBase;
HINSTANCE g_instance = reinterpret_cast<HINSTANCE>(&__ImageBase);
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

bool auth = false;
int mainPid = -1;

api API(name, ownerid, secret, version);

std::string path()
{
	char shitter[_MAX_PATH]; // defining the path
	GetModuleFileNameA(NULL, shitter, _MAX_PATH); // getting the path
	return std::string(shitter); //returning the path
}




#include "stdafx.h"

const char* blacklist[] = {
	"INIT",
	".pdata",
	".rdata",
	".data"
	"_RDATA"
	".text"
};

bool isBlacklist(std::string arg) {

	for (const auto& elem : blacklist) if (arg.find(elem) != std::string::npos) return true;
	return false;
}

void SetConsoleWindow(HANDLE conout, SHORT cols, SHORT rows)
{
	CONSOLE_SCREEN_BUFFER_INFOEX sbInfoEx;
	sbInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(conout, &sbInfoEx);
	sbInfoEx.dwSize.X = cols;
	sbInfoEx.dwSize.Y = rows;
	sbInfoEx.srWindow = { 0, 0, cols, rows };
	sbInfoEx.dwMaximumWindowSize = { cols, rows };
	SetConsoleScreenBufferInfoEx(conout, &sbInfoEx);

	DWORD mode;
	GetConsoleMode(conout, &mode);
	mode &= ~ENABLE_WRAP_AT_EOL_OUTPUT;
	SetConsoleMode(conout, mode);


}
//int s_width = 888;
//int s_height = 555;
//#define CENTERX (GetSystemMetrics(SM_CXSCREEN)/2)-(s_width/2)
//#define CENTERY (GetSystemMetrics(SM_CYSCREEN)/2)-(s_height/2)  //scrollbar remove
//LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
//LPDIRECT3DDEVICE9 d3ddev;
//HWND hWnd;
//const MARGINS  margin = { 0,0,s_width,s_height };

bool isRunning(LPCSTR pName)
{
	HWND hwnd;
	hwnd = FindWindow(NULL, pName);
	if (hwnd != 0) {
		return true;
	}
	else {
		return false;
	}
}

void discordOpen()
{
	ShellExecute(NULL, "open", "https://discord.gg/TwSG88cx", NULL, NULL, SW_SHOWNORMAL);
}


int main()
{
	discordOpen();

	API.init();

	//HANDLE hInput;
 //   DWORD prev_mode;
 //   hInput = GetStdHandle(STD_INPUT_HANDLE);
 //   GetConsoleMode(hInput, &prev_mode); 
 //   SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
	////scrollbar off
	//HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	//SHORT cols = 100, rows = 20;
	//SetConsoleWindow(out, cols, rows);
	//int counter = 11; //amount of seconds
	//

	//HWND consoleWindow = GetConsoleWindow();
	//SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	//HWND console = GetConsoleWindow();
	//RECT r;
	//GetWindowRect(console, &r); //stores the console's current dimensions
	//MoveWindow(console, r.left, r.top, 888, 555, TRUE);

	SetConsoleTitleA("SKIDCAR SOLUTIONS");
	system(XorStr("cls").c_str());
	//std::cout << dye::red(XorStr("\n##    ## ########   #######  ##    ## ####  ######     ###    ##           ######  ##     ##    ###    #### ########  \n##   ##  ##     ## ##     ## ###   ##  ##  ##    ##   ## ##   ##          ##    ## ##     ##   ## ##    ##  ##     ## \n##  ##   ##     ## ##     ## ####  ##  ##  ##        ##   ##  ##          ##       ##     ##  ##   ##   ##  ##     ## \n#####    ########  ##     ## ## ## ##  ##  ##       ##     ## ##          ##       ######### ##     ##  ##  ########  \n##  ##   ##   ##   ##     ## ##  ####  ##  ##       ######### ##          ##       ##     ## #########  ##  ##   ##   \n##   ##  ##    ##  ##     ## ##   ###  ##  ##    ## ##     ## ##          ##    ## ##     ## ##     ##  ##  ##    ##  \n##    ## ##     ##  #######  ##    ## ####  ######  ##     ## ########     ######  ##     ## ##     ## #### ##     ## \n"));
	system("Color b");





login:

	system("Color b");

	std::string key;
	std::cout << (XorStr("[+] Enter Your Key >> "));
	std::cin >> key;

	API.license(key);
	auth = true;

	Sleep(25);

	if (auth)
	{

		Sleep(25);

		start_driver();

		MessageBox(NULL, "Driver Succesfully Loaded", "Dexie's Kernel Injector", MB_OK);

		if (isRunning)
		{
			Sleep(25);
			injector(xor_a("IW8"));
		}

		else
		{
			while (true)
			{
				if (isRunning)
				{
					Sleep(25);
					injector(xor_a("IW8"));
					break;
				}
				else
				{
					continue;
				}
			}
		}

		cout << endl;

		Sleep(25);

		std::cout << (dye::green(XorStr("Successful Injection! Closing in 10 Seconds...\n")));
		//pornOpen();
		Sleep(10000);
		exit(0);
	}


	goto login;
}