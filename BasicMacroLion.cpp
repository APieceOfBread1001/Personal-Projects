// Stupid tools for stupid people
#include <iostream>
#include <windows.h>
int short THENUMPAD;
int num;//count of actions
INPUT input;//getting ready here for executing commands
INPUT minput;//mouse input
INPUT sinput;//quirky special keys input
int n2 = 0;
bool IFFING = 0;//boolean to check if an if statement is active
void specact(int short hexvk, int short Atype4);//function for special key presses
void mosact(int short Atype3, int short coord1, int short coord2);//function for mouse actions
void kbdact(int short Atype2,char Akey2);//function for virtual key presses
void numpadkeywait(int short THENUMPAD, int numpadsleeper);//function to have keybinds that do a series of inputs once
class actclass {
public:
	bool Abool1;//boolean to keyboard input, or used for equal signs in if statements
	bool Abool2;//boolean to mouse input or for a greater sign in if statements
	bool Abool3;//boolean to special keys or for a lesser sign in if statements
	bool Abool4;//yet another boolean for active if statements
	bool Abool5 = 0;
	char Atype;//action type (helps differentaite different commands and types of things)
	char Akey;//action key
	int Anum1;//number count 1 usually for x or R in color or number of rows going back every repetition
	int Anum2;//number count 2 usually for y or G in color or in "constant" repetitions
	int Anum3;//number count 3 usually for z (unused) or B in color or even in repetitions counted down

	bool ifcount(int ifincrease) {
				if (Atype == 18) {
				if (Abool4 == 1) {
				Akey = Akey + ifincrease;
				return 1;
				}
				}
				return 0;
				}
	void resetaction() {
		bool Abool1 = 0;
		bool Abool2 = 0;
		bool Abool3 = 0;
		bool Abool4 = 0;
		bool Abool5 = 0;
		char Atype = 0;
		char Akey = 0;
		int Anum1 = 0;
		int Anum2 = 0;
		int Anum3 = 0;
	}
	bool innitializecmds(std::string command){
		std::string tempstr;
	
	if (command == "wait") {//waits an integer of time between 
			Atype = 0;
			std::cin >> Anum1;
			}

			else if (command == "start") {//breaks out of loop and starts the actual program on loop
			Atype = 4;
			}

			else if (command == "press") {//presses virtual key
			Atype = 1;
			Abool1 = 1;
			std::cin >> Akey;
			}

			else  if (command == "hold") {//holds down virtual key
			Atype = 2;
			Abool1 = 1;
			std::cin >> Akey;
			}

			else  if (command == "release") {//releases held virtual key
			Atype = 3;
			Abool1 = 1;
			std::cin >> Akey;
			}

			else if (command == "mpressl") {//presses left click from mouse
			Atype = 5;
			Abool2 = 1;
			}

			else if (command == "mpressr") {//presses right click from mouse
			Atype = 6;
			Abool2 = 1;
			}

			else if (command == "mholdl") {//holds down left click from mouse
			Atype = 7;
			Abool2 = 1;
			}

			else if (command == "mholdr") {//holds down right click from mouse
			Atype = 8;
			Abool2 = 1;
			}

			else if (command == "mreleasel") {//releases left click from mouse
			Atype = 9;
			Abool2 = 1;
			}

			else if (command == "mreleaser") {//releases right click from mouse
			Atype = 10;
			Abool2 = 1;
			}

			else if (command == "mset") {//sets a cursor position (does not give input of movement)
			Atype = 11;
			Abool2 = 1;
			std::cin >> Anum1 >> Anum2;
			}

			else if (command == "specpress") {//press a special key
			Atype = 12;
			Abool3 = 1;
			std::cin >> tempstr;
			}

			else if (command == "spechold") {//hold a special key
			Atype = 13;
			Abool3 = 1;
			std::cin >> tempstr;
			}

			else if (command == "specrelease") {//release a special key
			Atype = 14;
			Abool3 = 1;
			std::cin >> tempstr;
			}
			else if (command == "repeat") {//repitition of a certain part of the series of inputs
			Atype = 15;
			std::cin >> Anum1 >> Anum2;// permanent values for 1 lines went back and 2 number of repetitions
			Anum3 = Anum2;//first setting of the temporary integer for repetitions (one that is not "constant")
			}

			else if (command == "mmove") {//moves the cursor relative to the previous mouse position
			Atype = 16;
			Abool2 = 1;
			std::cin >> Anum1 >> Anum2;
			}

			else if (command == "mmoveset") {//moves the cursor relative to the previous mouse position
			Atype = 17;
			Abool2 = 1;
			std::cin >> Anum1 >> Anum2;
			}

			else if (command == "mmove") {//moves the cursor relative to the previous mouse position
			Atype = 16;
			Abool2 = 1;
			std::cin >> Anum1 >> Anum2;
			}

			else if (command == "mmoveset") {//moves the cursor relative to the previous mouse position
			Atype = 17;
			Abool2 = 1;
			std::cin >> Anum1 >> Anum2;
			}
			else { return 0; };

			if (Abool3 == 1) {//translates special key name into the corresponding virtual key
			if (tempstr == "middlemouse") {
			Anum1 = 0x04;
			}
			else if (tempstr == "backspace") {
			Anum1 = 0x08;
			}
			else if (tempstr == "tab") {
			Anum1 = 0x09;
			}
			else if (tempstr == "enter") {
			Anum1 = 0x0D;
			}
			else if (tempstr == "lshift") {
			Anum1 = 0xA0;
			}
			else if (tempstr == "rshift") {
			Anum1 = 0xA1;
			}
			else if (tempstr == "ctrl") {
			Anum1 = 0x11;
			}
			else if (tempstr == "alt") {
			Anum1 = 0x12;
			}
			else if (tempstr == "capslock") {
			Anum1 = 0x14;
			}
			else if (tempstr == "esc") {
			Anum1 = 0x1B;
			}
			else if (tempstr == "space") {
			Anum1 = 0x20;
			}
			else if (tempstr == "leftarrow") {
			Anum1 = 0x25;
			}
			else if (tempstr == "uparrow") {
			Anum1 = 0x26;
			}
			else if (tempstr == "rightarrow") {
			Anum1 = 0x27;
			}
			else if (tempstr == "downarrow") {
			Anum1 = 0x28;
			}
			else if (tempstr == "F1") {
			Anum1 = 0x70;
			}
			else if (tempstr == "F2") {
			Anum1 = 0x71;
			}
			else if (tempstr == "F3") {
			Anum1 = 0x72;
			}
			else if (tempstr == "F4") {
			Anum1 = 0x73;
			}
			else if (tempstr == "F5") {
			Anum1 = 0x74;
			}
			else if (tempstr == "F6") {
			Anum1 = 0x75;
			}
			else if (tempstr == "F7") {
			Anum1 = 0x76;
			}
			else if (tempstr == "F8") {
			Anum1 = 0x77;
			}
			else if (tempstr == "F9") {
			Anum1 = 0x78;
			}
			else if (tempstr == "F10") {
			Anum1 = 0x79;
			}
			else if (tempstr == "F11") {
			Anum1 = 0x7A;
			}
			else if (tempstr == "F12") {
			Anum1 = 0x7B;
			}
			}//end of special keys initialization

			// I HATE THE NON CLASSIFICATION OF STRINGS IN C++
			//strings are so hard to work with in c++ I SWEAR TO GOD WHY MUST I ENDURE THIS
			//i literally cant even make a switch statement on the above case

			return 1;
	}
};

int main()
{
	actclass actions[1024];
	bool looping = 0;
	POINT boop;
	int num = 0;//command number (initialization)
	int tempint = 0;//temporary int for the "write" command
	int tempint2 = 0;//used exclusively for if statements
	char tempchar;
	int short numpadkey;//used to stick a bind to a numpadkey
	std::string command;//string of command input
	std::string tempstr;//temporary string for necessary processes
	std::string tempstr2;
	bool writing = 1; //boolean for the writing of words into an array of press commands
	bool createbool = 0;//boolean confirming if a binded numpad key has been created (defaults to no here)
	bool COUNTING = 0;//boolean for a counter already existing by the same name
	int numpadwaittime;//the waiting time in miliseconds during the numpad keybind
	//numpadwaittime waits that amount of time before allowing the repeat of the series of inputs and also checks for the keypress
	//getting ready here for executing commands
	HDC monhandle = GetDC(NULL); //makes a handle to a device context for getting the color of pixels on screen
	INPUT numpadinput;
	memset(&numpadinput, 0, sizeof(numpadinput));
	int n2 = 0; //used for going through inputs when the program is running
	std::cout << "program started you may input commands\n(type cmd to show available commands)\n";
	while (TRUE) {
		tempint = 0;
		n2 = 0;
		actions[num].Atype = 0;
		while (actions[num].Atype != 4) {

			if (IFFING == 1) {
			tempint2 = num;
			IFFING = 0;
			while (tempint2 != -1) {
			if (actions[tempint2].ifcount(1) == 1) {
			IFFING = 1;
			}
			tempint2 -= 1;
			}
			}
			std::cin >> command;
			//its just calibration so its one time while it sorts everything, can optimize later 
			if (actions[num].innitializecmds(command) == 1) {
			}

			else if (command == "write") {//makes a string of virtual key presses between two of the same character such as "hello"
			std::cin >> tempstr;
			tempint = 0;
			writing = 1;
				while (writing == 1) {
				if (tempstr[tempint + 1] == tempstr[0]) {
				if (IFFING == 1) {
			tempint2 = num;
			IFFING = 0;
			while (tempint2 != -1) {
			if (actions[tempint2].ifcount(tempint) == 1) {
			IFFING = 1;
			}
			tempint2 -= 1;
			}
			}
				writing = 0;
				}//end of tempstr[tempint+1] if statement
				else {
				actions[num].Atype = 1;
				actions[num].Abool1 = 1;
				actions[num].Akey = tempstr[tempint + 1];
				tempint += 1;
				num += 1;
				}
				}//end of writing loop

			}else if (command == "reset") {//resets the inputs from the points you are at
			while (num != -1) {
			actions[num].resetaction();
			num -= 1;
			}
			}
			else if (command == "jumpto") {//goes back to the start of the input series
			std::cin >> tempint;
			actions[tempint].Atype = 0;

				if (IFFING == 1) {
			tempint2 = num;
			IFFING = 0;
			while (tempint2 != -1) {
			if (actions[tempint2].ifcount(1) == 1) {
			IFFING = 1;
			}
			tempint2 -= 1;
			}
			}
				num = (tempint - 1); //setting the position to with -1 to negate the increase every loop
				}//end of jumpto command

			else if (command == "if") {

				if (IFFING == 1) {
			tempint2 = num;
			IFFING = 0;
			while (tempint2 != -1) {
			if (actions[tempint2].ifcount(1) == 1) {
			IFFING = 1;
			}
			tempint2 -= 1;
			}
			}
			IFFING = 1;
			actions[num].Atype = 18;
			actions[num].Abool4 = 1;
			actions[num].Akey = 1;
			tempint = num;
			std::cin >> tempstr;

				if (tempstr == "pixel" || tempstr == "npixel") {
				if (tempstr == "pixel") {
				actions[num+1].Atype = 0;//Atype is used for the kind of if statement made
				}
				else {
				actions[num+1].Atype = 1;
				}

				std::cin >> actions[num].Anum1 >> actions[num].Anum2;
				std::cin >> tempstr2;
				std::cin >> actions[num+1].Anum1 >> actions[num+1].Anum2 >> actions[num+1].Anum3;
				num += 1;
				}

				else if (tempstr == "pixelcopy" || tempstr == "npixelcopy") {
				looping = 1;
				std::cin >> tempstr2;
					while (looping == 1) {
					
					if (GetAsyncKeyState(VK_NUMPAD1)) {
					GetCursorPos(&boop);
					COLORREF pixelvalue = GetPixel(monhandle, boop.x, boop.y);
					std::cout << "R=" << (int)GetRValue(pixelvalue) << ", G=" << (int)GetGValue(pixelvalue) << ", B=" << (int)GetBValue(pixelvalue) << " X,Y " << boop.x << " " << boop.y << "\n";
					actions[num].Anum1 = boop.x;
					actions[num].Anum2 = boop.y;
					actions[num+1].Anum1 = (int)GetRValue(pixelvalue);
					actions[num+1].Anum2 = (int)GetGValue(pixelvalue);
					actions[num+1].Anum3 = (int)GetBValue(pixelvalue);
					}

					else if (GetAsyncKeyState(VK_NUMPAD3)) {
					if (tempstr == "pixelcopy") {
					actions[num + 1].Atype = 0;//Atype is used for the kind of if statement made
					}
					else {
					actions[num + 1].Atype = 1;
					}
					num += 1;
					looping = 0;
					}
					Sleep(200);
					}
					}
				
				else if (tempstr == "counter" || tempstr == "ncounter") {//if the counter shows a specific number
				
				if (tempstr == "counter") {
				actions[num + 1].Atype = 2;
				}else { actions[num + 1].Atype = 3; }

				std::cin >> tempchar;
				looping = 0;
				tempint2 = num;

				while (tempint2 != -1) {
				if (actions[tempint2].Atype == 19) {
				if (actions[tempint2].Akey == tempchar) {
				actions[num + 1].Akey = tempchar;
				actions[num + 1].Anum2 = tempint2;
				std::cin >> actions[num + 1].Anum1;
				looping = 1;
				}
				}
				tempint2 -= 1;
				}//end of Atype 19 check loop

				if (looping == 0) {
				looping = 1;
				num -= 2;
				std::cout << "error couldnt find the original integer counter base\n";
				}

				num += 1;//to skip the second command value of if statement
				}//end of if counter statement

			if (tempstr2 == "equal") {//these booleans are used for the kind of checking of the if statement
			actions[tempint].Abool5 = 0;
			}
			else if (tempstr2 == "roughly") {
			std::cin >> actions[tempint].Anum3;
			actions[tempint].Abool5 = 1;
			}
			}//end of if command

			else if (command == "endif") {
				if (IFFING == 1) {
				tempint2 = num;
				while (tempint2 != -1) {
				if (actions[tempint2].Atype == 18) {
				if (actions[tempint2].Abool4 == 1) {
				actions[tempint2].Abool4 = 0;
				tempint2 = 0;
				}
				}
				tempint2 -= 1;
				}

					tempint2 = num;
					IFFING = 0;
					while (tempint2 != -1) {
					if (actions[tempint2].ifcount(-1) == 1) {
					IFFING = 1;
					}
					tempint2 -= 1;
					}
					}
					else {std::cout << "error in finding active if statement"; }
					num -= 1;
					}//end of endif

			else if (command == "counter") {//uses a single character as an integer to count every time it is activated
			std::cin >> tempchar;
			tempint2 = num;

			while (tempint2 != -1) {
			if (actions[tempint2].Atype == 19) {
			if (actions[tempint2].Akey == tempchar) {
			COUNTING = 1;
			actions[num].Atype = 20;
			std::cin >> actions[num].Anum1;
			actions[num].Anum2 = tempint2;
			actions[num].Anum3 = actions[tempint2].Anum3;
			}
			}
			tempint2 -= 1;
			}

			if (COUNTING == 0) {//if an integer of the same name does not exist yet
			actions[num].Atype = 19;
			std::cin >> actions[num].Anum1;
			actions[num].Anum2 = 0;
			std::cin >> actions[num].Anum3;
			}

			actions[num].Akey = tempchar; //setting the character value regardless
			COUNTING = 0; //reseting the counting boolean for next initialization
			}

			else if (command == "msetcopy"||command == "mmovecopy"||command == "mmovesetcopy") {
			looping = 1;

			while (looping == 1) {
			if (GetAsyncKeyState(VK_NUMPAD1)) {
			GetCursorPos(&boop);
			std::cout << "X Y " << boop.x << " " << boop.y << std::endl;
			}

			if (GetAsyncKeyState(VK_NUMPAD2)) {
			if (command == "msetcopy") {
			actions[num].Atype = 11;
			}else if (command == "mmovecopy") {
			actions[num].Atype = 16;
			}else if (command == "mmovesetcopy") {
			actions[num].Atype = 17;
			}

			actions[num].Abool2 = 1;
			actions[num].Anum1 = boop.x;
			actions[num].Anum2 = boop.y;
			num += 1;
			}

			if (GetAsyncKeyState(VK_NUMPAD3)) {
			looping = 0;
			}
			Sleep(200);
			}
			num -= 1;
			}//end of mouse copying function

			else if (command == "mtest1") {
			looping = 1;
			while (looping == 1) {

			if (GetAsyncKeyState(VK_NUMPAD1)) {
			GetCursorPos(&boop);
			std::cout << "X Y " << boop.x << " " << boop.y << std::endl;
			}

			if (GetAsyncKeyState(VK_NUMPAD2)) {
			SetCursorPos(boop.x, boop.y);
			}

			if (GetAsyncKeyState(VK_NUMPAD3)) {
			looping = 0;
			}
			Sleep(200);
			}
			num -= 1;
			}//end of mtest1

			else if (command == "mtest2") {
			looping = 1;

			while (looping == 1) {
			if (GetAsyncKeyState(VK_NUMPAD1)) {
			GetCursorPos(&boop);
			std::cout << "X Y " << boop.x << " " << boop.y << std::endl;
			}

			if (GetAsyncKeyState(VK_NUMPAD2)) {
			INPUT tempinput;
			POINT temppoint;
			GetCursorPos(&temppoint);
			memset(&tempinput, 0, sizeof(tempinput));
			tempinput.type = INPUT_MOUSE;
			tempinput.mi.dx = (boop.x - temppoint.x);
			tempinput.mi.dy = (boop.y - temppoint.y);
			tempinput.mi.dwFlags = MOUSEEVENTF_MOVE;
			SendInput(1, &tempinput, sizeof(tempinput));
			ZeroMemory(&tempinput, sizeof(tempinput));
			}

			if (GetAsyncKeyState(VK_NUMPAD3)) {
			looping = 0;
			}
			Sleep(200);
			}
			num -= 1;
			}//end of mtest2
			
			else if (command == "colorpicker") {
			looping = 1;
			num -= 1;//undoing the advancement of the command list

			while (looping == 1) {
			if (GetAsyncKeyState(VK_NUMPAD1)) {
			GetCursorPos(&boop);
			COLORREF pixelvalue = GetPixel(monhandle, boop.x, boop.y); //obtains the color of the pixel at x and y coordinates using the handle of the device
			std::cout << "R=" << (int)GetRValue(pixelvalue) << ", G=" << (int)GetGValue(pixelvalue) << ", B=" << (int)GetBValue(pixelvalue) << " X,Y " << boop.x << " " << boop.y << "\n";
			}

			if (GetAsyncKeyState(VK_NUMPAD3)) {
			looping = 0;
			}
			Sleep(200);
			}
			}

			else if (command == "cmd") {//displays instructions on the available commands
			num -= 1;
			std::cout << "commands:\n press (key) = single keypress\n hold (key) = start (key) pressing a key\n release (key) = releases a held key\n wait (time) = waits for a number of miliseconds\n start = begins the program in 5 seconds\n mpressl = presses left mouse button\n mpressr = presses right mouse button\n mholdl = holds down left mouse button\n mholdr = holds down right mouse button\n mreleasel = releases left mouse button\n mreleaser = releases right mouse button\n mset (x) (y) = sets the cursor position without moving the mouse\n mmove (x) (y) = moves cursor position by the amount given\n repeat (lines back) (amount of times) = goes back one or several lines back in repetition\n mmoveset (x) (y) = combines both aspects of move and set cursor to move the mouse to a set fixed position on screen\n create (numpad) (time) = creates a macro bound to a key on the number-pad (9,8,7,6,5,4)\nthe time for the macro is for the miliseconds between triggers, small time variable means faster spam but harder to press only once (recommended about 200 to 300 miliseconds delay)\n specpress (key) = special keypresses such as shift, space or enter (for list type speccmd)\n spechold (key) = holds down special keys\n specrelease (key) = releases special keys\n write \"message\" = writes a series of press commands using the mssage (note any character can be used instead of \")\n mtest1\/mtest2 = allows to test for cursor data\n(numpad 1 to take the current cursor position)\n(numpad 2 to set or move to cursor position previously selected)\n(numpad 3 to stop testing)\n msetcopy\/mmovecopy\/mmovesetcopy all work the same as above mtest1 and mtest2\n (numpad 1 to take coordinates and 2 to set the command in the coordinates taken before. note: multiple can be set in a row one after another\n and numpad 3 to get out of copying mouse locations)\n reset = resets to the start and lets you rewrite the program\n jumpto = allows you to jump to any part of the code and write from there (starting at 0)\n";
			}

			else if (command == "speccmd") {//special characters available to be typed after specpress, spechold and specrelease
			num -= 1;
			std::cout << "\n possible special keys are in the following list:\n middlemouse backspace tab enter\n ctrl alt capslock\n lshift (note the left shift has been bugged in my computer and appears to use and not be able to let go of my right shift instead which I do not know why it happens) \n rshift esc space\n leftarrow uparrow rightarrow downarrow\n";
			}

			else if (command == "create") {
			std::cin >> numpadkey >> numpadwaittime;

			if (numpadkey > 3 && numpadkey < 10) {
			actions[num].Atype = 4;
			createbool = 1;
			std::cout << "macro has been assigned to numberpad key\n";
			}
			else {
			std::cout << "non-valid numpad key\n";
			num -= 1;
			}
			}//end of create

			else {
			std::cout << "\n error occured in classifying\n";
			num -= 1;
			}

			if (actions[num].Atype != 4) {
			num += 1; //if not ended advance forward
			}
		}//end of command initialization loop
















		bool numpad0;
		Sleep(2000);//waits two seconds so there is time for the user to get ready
		if (createbool == 1) {
		numpadkeywait(numpadkey, numpadwaittime);
		}
		bool working = 1;
		working = 1;
		while (working == 1) {//actual functioning of the program <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		if (actions[n2].Atype == 0) {//if sleep command
		Sleep(actions[n2].Anum1);
		}
		else if (actions[n2].Atype == 15) {//if repeat command
		if (actions[n2].Anum3 != 0) {//if end of repeats not found
		actions[n2].Anum3 -= 1;//remove one repetition from the total used
		n2 = n2 - (1 + actions[n2].Anum1);
		}
		else {
		actions[n2].Anum3 = actions[n2].Anum2;
		}
		}
		else if (actions[n2].Atype == 18) {//if if statement is found
		if (actions[n2].Abool5 == 0) {//equal
		if (actions[(n2 + 1)].Atype == 0 || actions[(n2 + 1)].Atype == 1) {//in both cases it will evaluate the same way anyway
			IFFING = 0;
			COLORREF pixelvalue = GetPixel(monhandle, actions[n2].Anum1, actions[n2].Anum2);

			if ((int)GetRValue(pixelvalue) == actions[(n2 + 1)].Anum1) {
			if ((int)GetGValue(pixelvalue) == actions[(n2 + 1)].Anum2) {
			if ((int)GetBValue(pixelvalue) == actions[(n2 + 1)].Anum3) {
			IFFING = 1;
			if (actions[(n2 + 1)].Atype == 1) {
			n2 += actions[n2].Akey-1;
			}
			}
			}
			}

			if (IFFING == 0 && actions[n2 + 1].Atype == 0) {
			n2 += actions[n2].Akey-1;
			}
			IFFING = 0;
			}

			else if (actions[(n2 + 1)].Atype == 2 || actions[(n2 + 1)].Atype == 3) {//if counter
			if (actions[actions[n2 + 1].Anum2].Anum2 == actions[n2 + 1].Anum1) {
			if (actions[(n2 + 1)].Atype == 3) {
			n2 += actions[n2].Akey-1;
			}
			}
			else {
			if (actions[(n2 + 1)].Atype == 2){
			n2 += actions[n2].Akey-1;
			}
			}
			}
			}
			else if (actions[n2].Abool5 == 1) {//roughly
			if (actions[(n2 + 1)].Atype == 0 || actions[(n2 + 1)].Atype == 1) {//same as above text
			COLORREF pixelvalue = GetPixel(monhandle, actions[n2].Anum1, actions[n2].Anum2);
			IFFING = 0;

			if ((int)GetRValue(pixelvalue) - actions[n2].Anum3 < actions[(n2 + 1)].Anum1) {
			if ((int)GetGValue(pixelvalue) - actions[n2].Anum3 < actions[(n2 + 1)].Anum2) {
			if ((int)GetBValue(pixelvalue) - actions[n2].Anum3 < actions[(n2 + 1)].Anum3 && (int)GetRValue(pixelvalue) + actions[n2].Anum3 > actions[(n2 + 1)].Anum1 && (int)GetGValue(pixelvalue) + actions[n2].Anum3 > actions[(n2 + 1)].Anum2 && (int)GetBValue(pixelvalue) + actions[n2].Anum3 > actions[(n2 + 1)].Anum3){
			IFFING = 1;
			if (actions[(n2 + 1)].Atype == 1) {
			n2 += actions[n2].Akey;
			}
			}
			}
			}
			if (IFFING == 0 && actions[(n2 + 1)].Atype == 0) {
			n2 += actions[n2].Akey; 
			}
			IFFING = 0;
			}
			}
			}
			else if (actions[n2].Abool1 == 1) {
			kbdact(actions[n2].Atype, actions[n2].Akey);//keyboard actions
			}
			else if (actions[n2].Abool2 == 1) {
			mosact(actions[n2].Atype, actions[n2].Anum1, actions[n2].Anum2);//mouse actions
			}
			else if (actions[n2].Abool3 == 1) {
			specact(actions[n2].Anum1, actions[n2].Atype);//special keys actions
			}
			else if (actions[n2].Atype == 4) {//if end of instructions appear
			if (createbool == 1) {
			numpadkeywait(numpadkey, numpadwaittime);
			}
			n2 = -1;
			}
			
			else if (actions[n2].Atype == 19){//counter base
			actions[n2].Anum2 += actions[n2].Anum1;
			if (actions[n2].Anum2 > actions[n2].Anum3) {
			actions[n2].Anum2 -= actions[n2].Anum3;
			}
			}
			
			else if (actions[n2].Atype == 20) {//other counting points directed to the base
			actions[actions[n2].Anum2].Anum2 += actions[n2].Anum1;
			if (actions[actions[n2].Anum2].Anum2 > actions[n2].Anum3) {
			actions[actions[n2].Anum2].Anum2 -= actions[n2].Anum3;
			}
			}
			if (GetAsyncKeyState(VK_NUMPAD0)) {//numpad 0 stops the tool
			while (GetAsyncKeyState(VK_NUMPAD0)) {
			Sleep(100);
			}
			numpad0 = 1;//numpad is pressed
			while (numpad0 == 1) {
			Sleep(200);
			if (GetAsyncKeyState(VK_NUMPAD0)) {
			while (GetAsyncKeyState(VK_NUMPAD0)) {
			Sleep(100);
			}
			numpad0 = 0;
			}
			if (GetAsyncKeyState(VK_NUMPAD3)) {//numpad 3 goes back to writing commands
			working = 0;
			numpad0 = 0;
			bool clearing = 1;
			clearing = 1;
			int nclear = 0;
			nclear = 0;
			while (clearing) {
			if (actions[nclear].Atype == 4){
			actions[nclear].Atype = 0;
			clearing = 0;
			}
			nclear += 1;
			}
			}
			}
			}
			n2 += 1; //end of the working loop adding a 1 to the n2 value
			}
			}
			}















	//old keypresser

	//INPUT input;
	//memset(&input, 0, sizeof(input));
	//input.type = INPUT_KEYBOARD;
	//input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(key)), 0);
	//while (TRUE) {
	//	input.ki.dwFlags = KEYEVENTF_SCANCODE | 0;
	//	SendInput(1, &input, sizeof(INPUT));
	//	Sleep(downtime);
	//	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	//	SendInput(1, &input, sizeof(INPUT));
	//	Sleep(time);
	//}

void specact(int short hexvk, int short Atype4) {
	//special key presses are made here
	//hexvk is the integer used for the type of virtual special-key pressed
	//Atype4 is for the type of press command
	memset(&input, 0, sizeof(input));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = hexvk;
	switch (Atype4) {

	case 12:
	input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	break;

	case 13:
	input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &input, sizeof(INPUT));
	break;

	case 14:
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	break;

	}
	ZeroMemory(&input, sizeof(input));
	}

void mosact(int short Atype3, int short coordx, int short coordy) {
	//mouse actions
	//different function for mouse presses so there is less to process
	//Atype3 for type of action
	// coodx and coordy for mmove (setcursorpos)
	memset(&minput, 0, sizeof(minput));
	minput.type = INPUT_MOUSE;
	switch(Atype3){

	case 5://mpressl
	minput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &minput, sizeof(minput));
	minput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 6: //mpressr
	minput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &minput, sizeof(minput));
	minput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 7: //mholdl
	minput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 8://mholdr
	minput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 9://mreleasel
	minput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 10://mreleaser
	minput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 11://mset
	SetCursorPos(coordx,coordy);
	break;

	case 16:
	minput.mi.dx = (coordx);
	minput.mi.dy = (coordy);
	minput.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &minput, sizeof(minput));
	break;

	case 17:
	POINT temppoint;
	GetCursorPos(&temppoint);
	minput.mi.dx = (coordx - temppoint.x);
	minput.mi.dy = (coordy - temppoint.y);
	minput.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &minput, sizeof(minput));
	break;

	default:
	std::cout << "error occured in mouse function";
	break;
	}
	ZeroMemory(&minput, sizeof(minput));
}

void kbdact(int short Atype2,char Akey2) {//keyboard actions
	//Atype2 is the specific use of a key
	//Akey2 is the key pressed
	//input has been declared as INPUT variable outside function for global usage
	//using windows.h headerfile so made sure to #include <windows.h>
	//sleep line has been left out of the function

	memset(&input, 0, sizeof(input));
	input.type = INPUT_KEYBOARD;
	switch (Atype2)
	{

	case 1: 
	input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(Akey2)), 0);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | 0;
	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	break;

	case 2:
	input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(Akey2)), 0);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | 0;
	SendInput(1, &input, sizeof(INPUT));
	break;

	case 3:
	input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(Akey2)), 0);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	break;

	default:
	std::cout << "error occured in key-press action";
	system("PAUSE");
	break;
	}
	ZeroMemory(&input, sizeof(input));
	}

void numpadkeywait(int short THENUMPAD, int numpadsleeper) {//stops program until number-pad is pressed
	bool waiting = 1;
	while (waiting == 1) {

		switch (THENUMPAD) {//I literally cant find a way to put a variable into the GetAsyncKeyState command
		case 9:
		if (GetAsyncKeyState(VK_NUMPAD9)) { waiting = 0; }
		break;

		case 8:
		if (GetAsyncKeyState(VK_NUMPAD8)) { waiting = 0; }
		break;

		case 7:
		if (GetAsyncKeyState(VK_NUMPAD7)) { waiting = 0; }
		break;

		case 6:
		if (GetAsyncKeyState(VK_NUMPAD6)) { waiting = 0; }
		break;

		case 5:
		if (GetAsyncKeyState(VK_NUMPAD5)) { waiting = 0; }
		break;

		case 4:
		if (GetAsyncKeyState(VK_NUMPAD4)) { waiting = 0; }
		break;

		default:
		std::cout << "error in numpad number while usage";
		break;
		}
		Sleep(numpadsleeper);
		}
}