//    ____  _   _  _____        ____  __    _    _   _   ____   _____   __ _    _     _____ 
//   / ___|| \ | |/ _ \ \      / /  \/  |  / \  | \ | | |  _ \ / _ \ \ / // \  | |   | ____|
//   \___ \|  \| | | | \ \ /\ / /| |\/| | / _ \ |  \| | | |_) | | | \ V // _ \ | |   |  _|  
//    ___) | |\  | |_| |\ V  V / | |  | |/ ___ \| |\  | |  _ <| |_| || |/ ___ \| |___| |___ 
//   |____/|_| \_|\___/  \_/\_/  |_|  |_/_/   \_\_| \_| |_| \_\\___/ |_/_/   \_\_____|_____|      

#include "stdafx.h"
#include "windows.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

struct Snowman {
	int co = 7;
	int ca = 7;
	string name;

} Sno;

void wait_enter(void) //Method of wait_enter, call it to create a Press Enter to continue screen.
{
	cin.ignore();
	cout << "Press ENTER to continue...";
	cin.ignore();
}

int waitForKey()
{
	return _getch() - 48;
}

void swapColor()
{
	static bool accent = true;
	if (accent)
		SetConsoleTextAttribute(hConsole, Sno.ca);
	else
		SetConsoleTextAttribute(hConsole, Sno.co);
	accent = !accent;
}

void  snowmake() {
	bool snowcool = true;
	system("cls");
	cout << "-*- Snowman Creation -*-\n\nWhat would you like to name your snowman?" << endl;
	getline(cin, Sno.name);
	system("cls");
	while (snowcool == true) {
		cout << "-*- Snowman Customization I -*-" << endl;
		cout << "\n1";
		cout << ") Roll your Snowman!" << endl;
		cout << "\n2";
		cout << ") Put a Hat on your Snowman!" << endl;
		cout << "\n3";
		cout << ") "
	}
}

void options() {
	system("cls");
	int colorc;
	int colorce;
	cout << "-*- Options -*-" << endl;
	cout << "\n1) Change Console Color\n2) Change Accent Color" << endl;
	colorc = waitForKey();
		switch (colorc) {
		case 1:
			system("cls");
			cout << "-*- Console Color -*- \n\nWhat color do you want your console?\n\n1) White\n\n2) Yellow\n\n3) Green\n\n4) Red" << endl;
			colorc = waitForKey();
			switch (colorc) {
			case 1:
				Sno.co = 15;
				break;
			case 2:
				Sno.co = 14;
				break;
			case 3:
				Sno.co = 10;
				break;
			case 4:
				Sno.co = 12;
				break;
			}
		case 2:
			SetConsoleTextAttribute(hConsole, Sno.co);
			system("cls");
			cout << "-*- Accent Color -*-\n\nWhat is your choice/marker color?\n\n1) White\n\n2) Red\n\n3) Magenta\n\n4) Cyan\n\n5) Same as Console Color" << endl;
			colorc = waitForKey();
			switch (colorc) {
			case 1:
				Sno.ca = 15;
				break;
			case 2:
				Sno.ca = 12;
				break;
			case 3:
				Sno.ca = 13;
				break;
			case 4:
				Sno.ca = 11;
				break;
			case 5:
				Sno.ca = Sno.co;
				break;
			}
			break;
		}

}

void start() {
	bool hastart = true;
	int startint;
	while (hastart == true) {
		system("cls");
		cout << "-*- SNOWMAN ROYALE -*-\n" << endl;
		swapColor();
		cout << "1";
		swapColor();
		cout << ") Enter the SNOWDEATH" << endl;
		swapColor();
		cout << "\n2";
		swapColor();
		cout << ") Load a Game" << endl;
		swapColor();
		cout << "\n3";
		swapColor();
		cout << ") Options" << endl;
		startint = waitForKey();
		switch (startint) {
		case 1:
			snowmake();
			break;
		case 2:
			break;
		case 3:
			options();
			break;
		}

	}
}

int main()
{
	start();
    return 0;
}

