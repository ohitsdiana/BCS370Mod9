/*
* Module 9 Assignment
* I chose a Stack Implementation in Java as a base for my .cpp program
* 
* Diana Guerrero
* Professor Zhao
* BCS 370
* 11/15/20
* 
*/

#include<stack>
#include <iostream>

using namespace std;

class appStroke 
{
	stack<char>st_primary;
	stack<char>st_secondary;

public:
	// Display current screen
	void display_screen()
	{
		stack<char>temp;

		while (!st_primary.empty()) 
		{
			temp.push(st_primary.top());
			st_primary.pop();
		}

		cout << "*** ";

		while (!temp.empty()) 
		{
			cout << temp.top();
			st_primary.push(temp.top());
			temp.pop();
		}

		cout << " ***\n";
	}

	// 1st App Menu Item Draw()
	void draw() 
	{
		cout << "Enter the Character Stroke: ";
		char x;
		cin >> x;

		st_primary.push(x);
		display_screen();
	}

	// 2nd App Menu Item Erase()
	void erase() 
	{
		st_primary.pop();
		display_screen();
	}

	// 3rd App Menu Item Undo()
	void undo() 
	{
		st_secondary.push(st_primary.top());
		st_primary.pop();
		display_screen();
	}

	// 4th App Menu Item Redo()
	void redo() 
	{
		if (!st_secondary.empty())
		{
			st_primary.push(st_secondary.top());
			st_secondary.pop();
		}
		display_screen();
	}

	// App running
	void play() 
	{
		int play = 1;
		while (play) 
		{
			char value;
			cout << "Chose An Option Below: " << endl;
			cout << " \n " << endl;
			cout << "To Draw press 1" << endl;
			cout << "To Erase press 2" << endl;
			cout << "To Undo press 3" << endl;
			cout << "To Redo press 4" << endl;
			cout << "To Exit press 5" << endl;
			cout << " \n " << endl;
			cout << "Enter your choice: " << endl;
			cin >> value;

			switch (value) 
			{
			case '1': this->draw();
				break;
			case '2': this->erase();
				break;
			case '3': this->undo();
				break;
			case '4': this->redo();
				break;
			case '5': cout << "Sketch Book App Over \n";
				play = 0;
				break;
			default: cout << "Invalid Choice \n";
				break;
			}
		}
	}
};

int main() 
{
	// Player Object 
	class appStroke player1; 
	player1.play();
	return 0;
} 