/********************************************************************
 *Program Name   :   Dice Roll
 *Author         :   Joseph Cohen
 *Date           :   9/6/2013
 *Program Description: Asks the user if they want to roll the dice 
 *and if so how many times. Keeps track of how many times each sum
 *if the two die values has been rolled then displays the counts.
 *Finally asks the user if they want to roll again or quit.
 *
 *BEGIN Dice Roll
 *	Seed random number generator
 *	Promt for roll or quit
 *	WHILE not quit
 *		Init counters to 0
 *		Promt for how many times to roll 
 *		FOR the number of times to roll
 *			roll the dice
 *			count each sum
 *      	END FOR
 *   		Clear the screen
 *   		Display sum counts
 *		Promt for reroll or quit
 *	END WHILE
 *END Dice Roll
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


bool validate(int);

int main()
{
    //local constants
    const char YES = 'y';
    const int  MAX = 10;
    
	//local variables
	int  Roll_n;	        //Score Value	
	int  Sum_Count[MAX];	//For keeping track of sums
	int  Count = 0;         //For array position
	char Choice;		//For users choice to roll or not
	int  Die_1;		//Value of die 1
	int  Die_2;		//Value of die 2
	int  Dice;		//Sum of dice
	
	/**************************start main program*********************/

	//seed random number generator
	srand(time(0));

	//Prompt for number input
	cout << "\n\n\n\n\n\n\n";
	cout << setw(48) << "----------------" << endl;
	cout << setw(48) << "|  Dice  Roll  |" << endl; 
	cout << setw(48) << "----------------" << endl;
	
	cout << "\n" << setw(54) << "Roll the dice? (y)/(n): ";
	
	cin >> Choice;
	
	//While the input is not quit value.
	while(Choice == YES)
	{
		for(int ii = 0; ii < (MAX + 1); ii++)
		{
			Sum_Count[ii] = 0;
		}
		
		cout << setw(46) << "How many times? ";
		
		cin >> Roll_n;
		
		//Put score in the array at count position.
		for(int ii = 0; ii < Roll_n; ii++)
		{
			Die_1 = 1 + rand() %6;
			Die_2 = 1 + rand() %6;
			
			Dice = Die_1 + Die_2;
			
			Sum_Count[Dice - 2]++;
			
		}
		
		//clear screen
		system("cls");
		
		//Display sum vlues
		cout << "\n\n\n\n\n\n\n";
		cout << setw(50) << "-------------------" << endl;
		cout << setw(50) << "| Dice Sum Totals |" << endl; 
		cout << setw(50) << "-------------------" << endl;
		cout << "\n";
		cout << setw(58) << "-----------------------------------" << endl;
		for(int ii = 0; ii < (MAX + 1); ii++)
		{
			cout << setw(25)  << ii + 2 <<  " has been rolled: " << setw(7) << Sum_Count[ii] 
			     << " times!" << endl;
		}
		cout << setw(58) << "-----------------------------------" << endl;
		cout << "\n\n\n\n";	
		
		//pause for reflection
		system("pause");
		
		//clear screen
		system("cls");
		
		//Prompt for number input
		cout << "\n\n\n\n\n\n\n";
		cout << setw(48) << "----------------" << endl;
		cout << setw(48) << "|  Dice  Roll  |" << endl; 
		cout << setw(48) << "----------------" << endl;
	
		cout << "\n" << setw(54) << "Roll the dice? (y)/(n): ";
		
		cin >> Choice;
	}//END while
	
	
	//Clear the screen
	system("cls");
	
	
	
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << setw(51) << "-------------------" << endl;
	cout << setw(51) << "| Have A Nice Day |" << endl; 
	cout << setw(51) << "-------------------" << endl;
	cout << "\n\n\n\n\n";
	
	
	//return 0 to the OS and pause the screen
	system("pause");
    return (0);
	
}   //End main program
