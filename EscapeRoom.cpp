#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
#include <limits>
using namespace std;

bool inv = true;
bool endLoop = false;
bool codeLock = false;
bool keyLock = false;
bool gameOver = false;
bool gameWin = false;
bool enter = true;
const enum rooms_t { livingroom, hallway, bedroom, kitchen, bathroom, basement, inventory };//Här använder vi oss utav enum för att hålla ordning på vart spelaren befinner sig.
rooms_t position; // Position gör så att du skickas till det tilldelade rummet med dom olika alternativen i.

//Här valde vi att använda oss utav bool för att spelaren ska kunna soma på sig olika föremål och kunna spara dom i ett inventory.
bool flashlight = false;
bool boltcutter = false;
bool codeNote = false;
bool keyBedroom = false;

//Win condition: Spelet går ut på att man ska hitta 2st specifika items för att kunna öppna dörren. Man går in i olika rum och får olika alternativ. Det gäller att man inte väljer "fel" alternativ och dör.

void countdown(void)
{



	const string one = R"(
    88      
  ,d88     
888888       
    88        
    88       
    88      
    88     
    88
)";
	const string two = R"(
 ad888888b,  
 d8"     "88  
         a8P  
      ,d8P"   
    a8P"      
  a8P'        
 d8"          
 88888888888
)";
	const string three = R"(
  ad888888b,
 d8"     "88
         a8P
      aad8"
      ""Y8,
         "8b
 Y8,     a88
  "Y888888P'
)";
	const string start = R"(
                                                                                                                                                                                                           
88888888888                                                                                                                                                                                                
88                          ,d                                   ,d                                   ,d                               ,d                                                                  
88                          88                                   88                                   88                               88                                                                  
88aaaaa      8b,dPPYba,   MM88MMM   ,adPPYba,  8b,dPPYba,      MM88MMM   ,adPPYba,       ,adPPYba,  MM88MMM  ,adPPYYba,  8b,dPPYba,  MM88MMM       ,adPPYb,d8  ,adPPYYba,  88,dPYba,,adPYba,    ,adPPYba,  
88"""""      88P'   `"8a    88     a8P_____88  88P'   "Y8        88     a8"     "8a      I8[    ""    88     ""     `Y8  88P'   "Y8    88         a8"    `Y88  ""     `Y8  88P'   "88"    "8a  a8P_____88  
88           88       88    88     8PP"""""""  88                88     8b       d8       `"Y8ba,     88     ,adPPPPP88  88            88         8b       88  ,adPPPPP88  88      88      88  8PP"""""""  
88           88       88    88,    "8b,   ,aa  88                88,    "8a,   ,a8"      aa    ]8I    88,    88,    ,88  88            88,        "8a,   ,d88  88,    ,88  88      88      88  "8b,   ,aa  
88888888888  88       88    "Y888   `"Ybbd8"'  88                "Y888   `"YbbdP"'       `"YbbdP"'    "Y888  `"8bbdP"Y8  88            "Y888       `"YbbdP"Y8  `"8bbdP"Y8  88      88      88   `"Ybbd8"'  
                                                                                                                                                   aa,    ,88                                              
                                                                                                                                                    "Y8bbdP"                                               
)";

	do
	{
		if (_kbhit())
		{
			break;
		}
		Sleep(2000);
		cout << three << endl;

		if (_kbhit())
		{
			break;
		}
		Sleep(1000);
		system("cls");
		cout << two << endl;

		if (_kbhit())
		{
			break;
		}
		Sleep(1000);
		system("cls");
		cout << one << endl;

		if (_kbhit())
		{
			break;

		}
		Sleep(1000);
		system("cls");
		break;


	} while (enter);


	do
	{
		cout << start << endl;
		Sleep(800);
		system("cls");
		Sleep(800);


		if (_kbhit())
		{
			enter = false;
		}


	} while (enter);
	while (_kbhit()) _getch(); // tömmer keyboard buffer för att inte avsluta startText efter countdown körts.
}

void startText(void)
{

	cout << R"(narrator:
you wake up with what feels like a hangover and you can’t seem to remember what you did before or up to the point you got knocked out
you feel a sting in your left leg and you look down to see a big dart poking out

[insert name] : 
SHIT!that can’t be good.

narrator :
you jank the dart out and look at the label that says "BIOHAZARD:MISSFORTUNE 7".

[insert name] : 
what is this madness ? !? !

narrator : 
you stand up on wobbly legs and procced to have a look around in what seems to be a livingroom.
the first thing you see is the door across the hall leading out of the house is locked with both key and code lock
you will need to find the code and something to break the keylock with.
(press enter to continue)
)";
	bool enter2 = true;
	do
	{



		if (_kbhit())
		{
			enter2 = false;
		}


	} while (enter2);
	system("cls");

}

void endText(void)
{
	system("cls");
	cout << R"(

narrator: finally, you have opened the locks on the door and eagerly pushes it open only to get hit in the face by the stock of a rifle almost completely knocking you out
	scientist 1 : dammit he made it....
	scientist 2 : how can he STILL get this far ?
	scientist 1 : I don’t know but we will just have to try again.
	narrator : you can barely make out what the two men were saying but after what felt like an eternity you see the end of a barrel and then everything goes dark.
	*
	*
	*
	*
	*
	*
	Narrator:
		  you wake up with what feels like a hangover............
)";
}

void openDoor()
{
	char question = 'Q';
	if ((boltcutter == false) || (codeNote == false))
	{
		system("cls");
		cout << "the door is locked with code and keylock you need to find things to open it with" << endl;
	}
	else
	{


		if ((boltcutter == true) && (question == 'Q'))
		{
			system("cls");
			cout << "do you want to use the code and the boltcutter" << endl;
			cout << "a for yes" << endl;
			cout << "b for no" << endl;
			cin >> question;
			cin.ignore(256, '\n');// Här ignorerar den det antalet tecken du anger när du skriver in lite vad som, upp till den tecken du anger som en brytpunkt(rätt svar som tex ett a då blir svaret a). Den tar upp till 256 tecken
			switch (question) // Här använder vi oss utav en switch för att visa relevent information för den miljö spelaren befinner sig i / olika alternativ i dom olika rummen.
			{
			case 'a':
				system("cls");//Clear screen (För att göra speler mer "lättläst"
				cout << "you put the boltcutter to the lock and snap it of." << endl;
				Sleep(3500);
				cout << "you take out the note and type in the code and a lamp on the lock turns green." << endl;
				Sleep(4500);
				keyLock = true;
				codeLock = true;
				break;

			case 'b':
				system("cls");
				break;

			default:
				system("cls");
				cout << "wrong input try again.111" << endl;
				Sleep(1500);
				system("cls");
				question = 'Q';
				break;
			}

		}

	}


	if ((keyLock == true) && (codeLock == true)) // Om du har hittat dessa två items så kan du öppna dörren och vinna spelet.
	{
		gameWin = true;
		endText();

	}

}

int chooseRoom()//Här i chooseRoom tar vi hjälp av enum för att veta vart spelaren befinner sig. 
{

	char answer = 'a';


	system("cls");
	cout << "----------Where do you want to go ? ---------- \n\n a = Kitchen\n b = Livingroom\n c = Bedroom\n d = Basement\n e = Bathroom\n f = Hallway\n g = Inventory\n" << endl;
	cout << "Answer: "; cin >> answer;
	cin.ignore(256, '\n');


	system("cls");

	switch (answer) 
	{
	case 'a':
		cout << "---------- You are in the kitchen -----------\n What do you want to do?\n" << endl;
		position = kitchen; // Position gör så att du skickas till det tilldelade rummet med dom olika alternativen i.
		
		break;
	case 'b':
		position = livingroom;

		break;
	case 'c':
		cout << "--------- You are in the bedroom ----------\n What do you want to do?\n" << endl;
		position = bedroom;
		break;
	case 'd':
		position = basement;
		break;
	case 'e':
		cout << "--------- You are in the bathroom ----------\n What do you want to do?\n" << endl;
		position = bathroom;
		break;
	case 'f':
		position = hallway;
		break;
	case 'g':
		cout << "--------- You are in the Inventory ----------\n What do you want to do?\n" << endl;
		position = inventory;
		break;


	default:
		system("cls");
		cout << "********** Wrong input try again. ********** " << endl;
		Sleep(1500);
		chooseRoom();

	}


	return position;





}

void Basement()
{

	char answer = 'Z';
	bool endLoop = false;
	while (endLoop == false)
	{
		string choice;
		if (flashlight == false)
		{
			cout << "---------- The stairs down to the basement has no lights ----------\n" << endl;

		}
		cout << "a/ Go down the stairs." << endl;
		cout << "b/ Go to another room.\n" << endl;
		cin >> choice;
		cin.ignore(256, '\n');
		system("cls");

		if ((choice == "a") && (flashlight == true))
		{
			endLoop = true;
			answer = 'a';
			break;
		}
		if ((choice == "a") && (flashlight == false))
		{
			cout << "********** Without a lightsource you fall down the stairs and break your neck. **********\n" << endl;

			gameOver = true;
			answer = 'Q';
			break;
		}

		if (choice == "b")
		{
			endLoop = true;
			chooseRoom();
			break;
		}


	}

	while ((answer == 'a') && (flashlight == true)) 
	{
		cout << "---------- You are standing in the basement. ----------\n" << endl;
		cout << "a/ Open tool cabinet.\nb/ Search hole in wall.\nc/ Check under stairs.\nd/ Go to another room.\n" << endl;
		cin >> answer;
		cin.ignore(256, '\n');

		system("cls");
		string Answer;

		switch (answer)
		{
		case 'a':
			cout << "********** You open the tool cabinet and an axe falls out spliting your skull open. **********\n" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'b':
			cout << "********** You reach in to the hole and get bitten by a spider, you swell up and burst **********\n" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'c':
			if (boltcutter == true)
			{
				cout << "---------- You have already looked under the stairs and found a boltcutter, what do you want to do? ----------\n" << endl;
				answer = 'a';
				//break;
			}
			else
			{
				cout << "---------- You look under the stairs and find a boltcutter -----------\n" << endl;
				cout << "Do you want to pick it up?" << endl;
				cout << "yes/no" << endl;


				cout << "Answer: "; cin >> Answer;
				system("cls");
			}

			if (Answer == "yes")
			{
				cout << "You pick up the boltcutter, what do you want to do next?" << endl;
				boltcutter = true;
				answer = 'a';
				break;
			}
			if (Answer == "no")
			{
				cout << "You ignore the boltcutter, what do you want to do next?" << endl;
				answer = 'a';
				break;
			}
		case 'd':
				chooseRoom();
				break;
			
		default:
			cout << "********** Wrong input try again. **********" << endl;
			answer = 'a';
			Sleep(1500);
			system("cls");
			break;


		}
	}

}

void Kitchen()
{
	system("cls");
	cout << "---------- You are standing in the kitchen. ----------\n" << endl;
	char answer = 'a';
	string Answer;

	while ((answer == 'a') || (answer == 'b') || (answer == 'c'))
	{
		cout << "a/ Open oven\nb/ Open keylocker\nc/ Search fridge\nd/ Go to another room. \n" << endl;
		cout << "Answer: "; cin >> answer;
		cin.ignore(256, '\n');
		system("cls");
		if (answer == 'd')
		{
			chooseRoom();
			break;
		}

		switch (answer)
		{


		default:					// får error om den flyttas längst ner.
			cout << "********** Wrong input try again. **********" << endl;
			Sleep(1500);
			break;

		case 'a':
			cout << "**********  You open the oven and die **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'b':
			cout << "********** You open the keylocker and die **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'c':
			if (keyBedroom == true)
			{
				cout << "---------- You have already searched the fridge and found the key, what do you want to do? ---------- " << endl;
				break;
			}
			cout << "---------- You search the fridge and find a key. ----------" << endl;
			//string Answer;
			cout << "Do you want to pick it up?" << endl;
			cout << "yes/no" << endl;
			cout << "Answer: "; cin >> Answer;
			if (Answer == "yes")
			{
				system("cls");
				cout << "---------- You pick up the key, what do you want to do next? ----------" << endl;
				keyBedroom = true;
				break;
			}
			if (Answer == "no")
			{
				system("cls");
				cout << "---------- You leave the key in the fridge, what do you want to do next? -----------" << endl;
				break;
			}
			break;



		}
	}
}

void Livingroom()// Detta livingroom funkar som det ska den andra var den som du skicka som blev helt vato loco.
{
	system("cls");
	cout << "---------- You are standing in the livingroom. ----------\n" << endl;
	char answer = 'a';
	string Answer;

	while ((answer == 'a') || (answer == 'b') || (answer == 'c'))
	{
		cout << "a/ Sit on the couch\nb/ Take out a book from the bookshelf\nc/ Check in the coffe table drawer\nd/ Go to another room.\n" << endl;
		cout << "Answer: "; cin >> answer;
		cin.ignore(256, '\n');

		if (answer == 'd')
		{
			chooseRoom();
			break;
		}

		switch (answer)
		{
		case 'a':
			system("cls");
			cout << "********** You sit on the couch and fall asleep for the rest of your life **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'b':
			system("cls");
			cout << "********** You open the book and out comes a snake that bites you **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'c':
			if (flashlight == true)
			{
				system("cls");
				cout << "---------- You have already searched the coffe table and found the flashlight, what do you want to do? ----------" << endl;
				break;
			}
			system("cls");
			cout << "---------- You open the coffe table drawer and find a flashlight. ----------" << endl;
			cout << "Do you wish to take it?" << endl;
			cout << "yes/no" << endl;
			cout << "Answer: "; cin >> Answer;

			if (Answer == "yes")
			{
				system("cls");
				cout << "---------- You take the flashlight. ----------\n" << endl;
				flashlight = true;
				break;
			}
			if (Answer == "no")
			{
				system("cls");
				cout << "----------- You leave the flashlight and closing the drawer. ----------\n" << endl;
				break;
			}
		default:
			system("cls");
			cout << "********** Wrong input try again. **********" << endl;
			Sleep(1500);
			break;
		}
	}






}

void Bathroom()// Här är det bara DÖD Mohahahaha 

{

	system("cls");
	cout << "---------- You are standing in the bathroom. ----------\n" << endl;
	char answer = 'a';

	while ((answer == 'a') || (answer == 'b') || (answer == 'c') || (answer == 'd'))
	{
		cout << "a/ Check under the bathroom mat.\nb/ Take a bath.\nc/ Look into the mirror\nd/ Go to another room.\n " << endl;
		cout << "Answer "; cin >> answer;
		cin.ignore(256, '\n');
		system("cls");


		switch (answer)
		{

		case 'a':

			cout << "********** You looked under the bathroom mat and die of a sudden arrow hits your head **********\n" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'b':

			cout << "********** You jump into the bathtub full of electric eels and die. **********\n" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'c':

			cout << "********** As soon as you get eye contact with yourself in the mirror you get murdered by your own reflection. **********\n" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'd':
			answer = 'Q';
			chooseRoom();
			break;

		default:
			cout << "********** Wrong input try again. **********" << endl;
			Sleep(1500);
			break;
		}

	}

}

void Hallway()
{

	cout << "--------- You are in the hallway ----------\n What do you want to do?\n" << endl;
	string choice;
	cout << "a/ Open door" << endl;
	cout << "b/ Go to another room" << endl;
	cout << "Answer: "; cin >> choice;
	if (choice == "b") {
		//endLoop = true;
		chooseRoom();
	}
	else if (choice == "a")
	{
		//endLoop = true;
		openDoor();

	}
	else
	{
		system("cls");

		cout << "********** Wrong input try again. **********" << endl;
		Sleep(1500);
		system("cls");

	}


}

void Bedroom()
{
	system("cls");
	cout << "---------- You are standing in the bedroom. ----------\n" << endl;
	char answer = 'a';
	string Answer;

	while ((answer == 'a') || (answer == 'b') || (answer == 'c'))
	{
		cout << "a/ Check under pillow\nb/ Open closet\nc/ Walk in to the wall\nd/ Go to another room.\n" << endl;
		cout << "Answer: "; cin >> answer;
		cin.ignore(256, '\n');
		system("cls");

		if (answer == 'd')
		{
			chooseRoom();
			break;
		}

		switch (answer)
		{
		case 'a':
			cout << "********** You look under the pillow and find a flower. You smell it and die **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'b':
			cout << "********** You open the closet and you get attacked by a monster and die **********" << endl;
			answer = 'Q';
			gameOver = true;
			break;

		case 'c':
			if (codeNote == true)
			{
				cout << "---------- You found the note already its not a good idea to walk into the wall AGAIN, what do you want to do? ---------- " << endl;
				break;
			}

			cout << "---------- You fall down and find a locked box under the bed. ----------" << endl;
			if (keyBedroom == true)
			{

				cout << "Do you want to open it?" << endl;
				cout << "yes/no" << endl;
				cout << "Answer: "; cin >> Answer;

				if ((Answer == "yes") && (keyBedroom == true))
				{
					system("cls");
					cout << "---------- You open the box and take out a pice of paper with a code on it, what do you want to do next? ----------" << endl;
					codeNote = true;
					break;
				}
				if (Answer == "no")
				{
					system("cls");
					cout << "---------- You leave the box under the bed even though you know you will have to walk in to the wall again to find it----------\nWhat do you want to do next?" << endl;
					break;
				}

			}
			else
			{
				cout << "---------- You dont have the key to the box find it and come back watch out for the wall.... ----------\n" << endl;
				break;
			}

		default:
			cout << "********** Wrong input try again. **********" << endl;
			Sleep(1500);
			break;



		}
	}





}

void Inventory()

{





	system("cls");

	//while (inv == true)


	//{

	cout << "---------- INVENTORY ----------\n";

	if (flashlight == true)

	{
		cout << "¤ Flashlight\n";
	}

	if (boltcutter == true)
	{
		cout << "¤ Bolcutter\n";
	}

	if (codeNote == true)
	{
		cout << "¤ Codenote\n";
	}

	if (keyBedroom == true)
	{
		cout << "¤ Key\n";
	}

	string answer;
	cout << "_____________________________\n" << endl;
	cout << "Close Inventory\nType yes\n" << endl;
	cout << "Answer: "; cin >> answer;
	//cin.get(); why???

	if (answer == "yes")
	{
		inv = false;
		chooseRoom();

	}



	//}



}

int room(int z)
{
	bool endLoop = false;
	while (endLoop == false)
	{

		string choice;
		cout << z << endl;
		do
		{
			switch (z)
			{

			case hallway:

				endLoop = true;
				Hallway();
				break;

			case livingroom:
				//cout << "---------- You are standing in the livingroom. ----------\n" << endl;
				endLoop = true;
				Livingroom();
				break;

			case bedroom:
				endLoop = true;
				Bedroom();
				break;

			case kitchen:
				endLoop = true;
				Kitchen();
				break;

			case bathroom:
				endLoop = true;
				Bathroom();
				break;

			case basement:
				endLoop = true;
				Basement();
				break;

			case inventory:



				endLoop = true;
				Inventory();
				break;
			}

		} while (endLoop == false);

		return 0;
	}

}





int main()
{
	setlocale(LC_ALL, "");



	countdown(); //ascci nedräkning i starten av spelet.
	startText(); // efter nedräkningen kommer det lite flavour text och instruktioner.
	while ((gameOver == false) && (gameWin == false))
	{

		int z = position;
		room(z);
	}



	if (gameOver == true)
	{
		cout << "Try again." << endl;
	}


}
