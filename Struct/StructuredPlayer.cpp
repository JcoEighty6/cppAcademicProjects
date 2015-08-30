/********************************************************************
 *Program Name   : Structured Player                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Gets a single player's info such as jersey number name
 *	and position. Stores the data in a structure data type. 
 *  The data is then formatted into a team roster and displayed with
 *  the names in title case and the position as a capital.
 *
 *BEGIN Structured Player
 *	Init Quit = -1
 *	Init last name size = 10
 *	Init first name size = 7
 *  Init roster max = 5
 *	Init count = 0
 *  Get jersey num
 *	IF (not quit)
 *  	Get whole name
 *  	Get position
 *	END IF
 *	Clear Screen
 *	IF (Jersey num is quit)
 *		Display exit message
 *	ELSE
 *		Display team roster
 *	END IF-ELSE
 *	END Structured Player
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

struct  player
{
	int 	J_num;
	string  Name;
	char 	Position;		
};



/***********************************FUNCTION PROTOTYPES**********************************/

int 	get_num();
string  get_name(int, int);
char 	get_position();
string  title_case(string);
string  f_format(string, int);
string  l_format(string, int);
void	display(player);

/****************************************************************************************/




/**************************************MAIN PROGRAM**************************************/

int main()
{
    	//local constants
    	const int QUIT    = -1;
	const int MAX_L   = 7;		//Size of last name.
	const int MAX_F   = 5;		//Size of frist name.  
    
    
	//local variables
	string  First;			//Holds a first name to be stored in array.
	string  Last;			//Holds a last name to be stored in array.	
	int 	Count     = 0;		//to keep everything at the same position.	
	player  Player_1;
	
	/**************************start main program*********************/

	//Display header.
	cout << "\n\n\n";
	cout << setw(50) << "------------------------" << endl;
	cout << setw(50) << "|   Stuctured Players  |" << endl;
	cout << setw(50) << "------------------------" << endl;
	
	//Display instructions and expample.	
	cout << "\n" << setw(60) << "Enter player data. (e.g., 99 Gretzky Wayne C)" << "\n\n";
	
	//Get jersey number or quit code.
	Player_1.J_num = get_num();
	
	//If jersey num is not quit.
	if(Player_1.J_num != QUIT)
	{
		cout << "\n";
	
		//Get player's name.
		Player_1.Name	  = get_name(MAX_L, MAX_F);
		
		cout << "\n";
		
		//Get player's position.
		Player_1.Position = get_position();
		
		cout << "\n";
		
	}
	
	//Clear the screen.
	system("cls");
	
	//If count is 0.
	if(Player_1.J_num == QUIT)
	{
		//Display exit message.
		cout << "\n\n\n\n\n\n";
		cout << setw(51) << "--------------------------" << endl;
		cout << setw(51) << "|    Have a nice day!    |" << endl;
		cout << setw(51) << "--------------------------" << endl;
		cout << "\n\n\n\n\n";
	}
	//If count is not 0.
	else
	{
		
		
		//Display output header.
		cout << "\n\n\n\n";
		cout << setw(51) << "--------------------------" << endl;
		cout << setw(51) << "|       Team Roster      |" << endl;
		cout << setw(51) << "--------------------------" << endl;
		cout << "\n";
		cout << setw(51) << "--------------------------" << endl;
		
		//Display output information
		display(Player_1);
		
		//Display output footer.
		cout << setw(51) << "--------------------------" << endl;
	}
	
	
		
	//return 0 to the OS and pause the screen
	system("pause");
    return (0);
	
}   //End main program




/********************************************************************
 *Function Name  : get_num                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Promts user to input a jersey number
 *	or a -1 to quit, returns an int.
 *
 *BEGIN get_num
 *	Promt for jersey num or quit code
 *	Set num from keyboard input
 *  return num	
 *END get_num
 ********************************************************************/
 
int get_num()
{
	//local constants
	
	//local variables
	int Num;
	
	/**************************************************/
	
	//Promt for input.
	cout << setw(43) << "Jersey number (-1 to quit): ";
	
	//Insert keyboard input into Num.
	cin >> Num;
	
	//return Num.
	return Num;
	
}//END get_num.





/********************************************************************
 *Function Name  : get_name                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Promts user to input a Last and First name
 *	concatinates the two into a single string delimited by a
 *	space and returns it.
 *
 *BEGIN get_name
 *	Promt for last name
 *	Set last from keyboard input
 *  Promt for first name
 *  Set first from keyboard input
 *  Set name to concatination of last and first, space delimited
 *  Return name	
 *END get_name
 ********************************************************************/
 
string get_name(int MAX_L, int MAX_F)
{
	//local constants
	
	//local variables
	string Name;
	string Last;
	string First;
	string Space = " ";
	
	/*************************************/
	
	//Promt for last name.
	cout << setw(43) << "Last name                 : ";
	
	//Insert keyboard input into Last.	
	cin >> Last;
	
	cout << "\n";
	
	//Promt for first name.
	cout << setw(43) << "First name                : ";
	
	//Insert keyboard input into First.	
	cin >> First;
	
	//Set Name to concatination of Last and First, Space delimited.
	Name = l_format(title_case(Last), MAX_L) + "," + Space + f_format(title_case(First), MAX_F);
	
	//Return Name.
	return Name;
	
}//END get_name.




/********************************************************************
 *Function Name  : get_position                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Promts user to input a position
 *	returns a char.
 *
 *BEGIN get_position
 *	Promt for position
 *	Set position from keyboard input
 *  return position	
 *END get_position
 ********************************************************************/
 
char get_position()
{
	//local constants
	
	//local variables
	char Position;
	
	/*************************************/
	
	//Promt for position.
	cout << setw(43) << "Position                  : ";
	
	//Set Position from keyboard input
	cin >> Position;
	
	//Return Position.
	return toupper(Position);

}//END title_case.




/********************************************************************
 *Function Name  : title_case                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Course/Section : CSC263 - 001
 *Description	 : Sets an incomming string to title case and returns it.
 *
 *BEGIN title_case
 *	init length to the length of the incomming name
 *	FOR (each character of name to length)
 *		set each character to lower case
 *	END FOR
 *	set first character of name to upper case
 *  return name	
 *END title_case
 ********************************************************************/
 
string title_case(string Name)
{
	//local constants
	
	//local variables
	int Length = Name.length();    //length of incomming name for loop max.
	
	/***************************************/
	
	//For all characters of name to length.
	for (int ii = 0; ii < Length; ii++)
	{
		//Set each character to lower case.
		Name[ii] = tolower(Name[ii]);
	}
	
	//Set first character of name to upper case.
	Name[0] = toupper(Name[0]);
	
	//Return name.
	return Name;
	
	
}//END title_case




/********************************************************************
 *Function Name  : f_format                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : If the name is shorter than the max, 
 *	adds spaces to the end. If it's longer than max,
 *	truncates it. Returns a string. 
 *
 *BEGIN f_format
 *	IF (name length less than max)
 *		FOR (values from length to max)
 *			Add spaces
 *		END FOR
 *	ELSE
 *		Shorten name to max
 *	END IF-ELSE
 *  Return name	
 *END f_format
 ********************************************************************/
 
string f_format(string First, int MAX_F)
{
	//local constants
	
	//local variables
	string Space   = " ";
	
	/***************************************************/
	
	//If name is less than max.
	if(First.length() < MAX_F)
	{
		//for values from length to max.
		for(int ii = First.length(); ii < MAX_F; ii++)
		{
			//Add spaces to name.
			First = First + Space;			
		}		
	}
	
	//If name is more than max.
	else
	{		
		//Truncate to max.
		First = First.substr(0, MAX_F);	
	}
	
	//Return name.
	return First;

}//END f_format.




/********************************************************************
 *Function Name  : l_format                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : If the name is shorter than the max, 
 *	adds spaces to the end. If it's longer than max,
 *	truncates it. Returns a string. 
 *
 *BEGIN l_format
 *	IF (name length less than max)
 *		FOR (values from length to max)
 *			Add spaces
 *		END FOR
 *	ELSE
 *		Shorten name to max
 *	END IF-ELSE
 *  Return name	
 *END l_format
 ********************************************************************/

string l_format(string Last, int MAX_L)
{
	//local constants
	
	//local variables
	string Space   = " ";
	
	/**************************************************/
	
	//If name is less than max.
	if(Last.length() < MAX_L)
	{
		//for values from length to max.
		for(int ii = Last.length(); ii < MAX_L; ii++)
		{
			//Add spaces to name.
			Last = Last + Space;			
		}		
	}
	
	//If name is more than max.
	else
	{
		//Truncate to max.
		Last = Last.substr(0, MAX_L);	
	}
	
	//Return name.
	return Last;
	
}//END l_format.





/***************************************************************************************************************
 *Function Name  : display                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Displays each array from 0 to Count.
 *
 *BEGIN display
 *		Display data components of player structure, space delimited, with margin markers
 *END display
 ***************************************************************************************************************/

void display(player Player_1)
{
	//local constants
	
	//local variables
	
	/*******************************************************************************************/
	
	
		cout << "\n";
		
		//Display all of the array values at the loop counter delimited by spaces with margin markers.
		cout << setw(26) << "|" << setw(2)  << Player_1.J_num << "   "  << Player_1.Name << "    " 
			 << Player_1.Position << "|" << endl;
	
	
		cout << "\n";
	
}//END display
