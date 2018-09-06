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
	int co = 15;
	int ca = 11;
	string name;
	double heatThr = 2;
	int coolness = 1;
} Sno;

/*
	co - the accent color
	ca - the console color
	name - the name of the snowman
	heatThr - This is the level of resistance to heat. 2-0. 2 = Doubles damage taken to heat (multiplies damage) cont.
	-- 1 = multiplies the incoming damage by 1, so takes normal damage to it. 0 = takes no damage to heat (unless its in the sun)
	coolness = increases the chance of greater loot. 
	-- You get coolness points for...
		-- Standing out in the sun, defeating other snowmen, finding bad items.


*/

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
	bool snowcool = true; //This is the while loop condition. Ends when theyre out of it
	int creation; //Int for the waitforkey
	system("cls"); //Clears the screen
	cout << "-*- Snowman Creation -*-\n\nWhat would you like to name your snowman?" << endl;
	getline(cin, Sno.name); //Gets the snowmans name
	system("cls"); //Clears screen
	while (snowcool == true) { //Keeps them looped in this part
		cout << "-*- Snowman Customization I -*-" << endl;
		swapColor();
		cout << "\n1";
		swapColor();
		cout << ") Roll your Snowman!" << endl;
		swapColor();
		cout << "\n2";
		swapColor();
		cout << ") Put a Hat on your Snowman!" << endl;
		swapColor();
		cout << "\n3";
		swapColor();
		cout << ") " << endl;
		swapColor();
		cout << "\n-*- Stats -*-\nName: ";
		swapColor();
		cout << Sno.name;
		creation = waitForKey();
		/*
		1 - Roll a snowman-- gets the weight (more explained at the top)
		2 - Put a hat on-- increases some stats (MORE AT TOP AA)
		3 - Weapons-- start the snowman off strong.
		*/
	}
}

void options() {
	system("cls");
	int colorc;
	int colorce;
	cout << "-*- Options -*-" << endl;
	cout << "\n1";
	cout << ") Change Console Color" << endl;
	cout << "2";
	cout << ") Change Accent Color" << endl;
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
		swapColor();
		swapColor();
		system("cls"); // I know you guys hate sys. i love you too.
		cout << "-*- SNOWMAN ROYALE -*-\n" << endl; 
		swapColor(); //Ok so swap color changes the numbers to the accent color (Sno.ac)
		cout << "1";
		swapColor(); // Changes it back to the player's console CHOICE!
		cout << ") Enter the SNOWDEATH" << endl;
		swapColor();
		cout << "\n2"; 
		swapColor();
		cout << ") Load a Game" << endl;
		swapColor();
		cout << "\n3";
		swapColor();
		cout << ") Options" << endl;
		startint = waitForKey(); //Waits for the player to press a number. sends them to the selected thing
		//1: create a snowman, 2: load a game, 3: send them to the options
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

