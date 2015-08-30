/********************************************************************
 *Program Name   : Structured Roster                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Gets player info such as jersey number name and
 *	position. Holds the data components in a structure data type
 *	then stores in an array. The data is then formatted into a team roster 
 *  and displayed with the names in title case and the position as a capital.
 *
 *BEGIN Structured Roster
 *	Init count = 0
 *  	Get jersey num
 *	IF (not quit)
 *  	Get whole name
 *  	Get position
 *	END IF
 *	WHILE (Jersey num is not quit)
 *		Store player info in roster array
 *		Increment count
 *		IF (Roster is at max)
 *			Display roster full message
 *		ELSE
 *			Get jersey num
 *			IF (not quit)
 *  			Get whole name
 *  			Get position			
 *			END IF
 *		END IF-ELSE
 *	END WHILE
 *	Clear Screen
 *	IF (Count is still 0)
 *		Display exit message
 *	ELSE
 *		Display team roster
 *	END IF-ELSE
 *END Structured Roster
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

int 	get_num(int);
string  get_name(int, int, int);
char 	get_position(int);
string  title_case(string);
string  f_format(string, int);
string  l_format(string, int);
void    fill_roster(int, player, player[]);
void	display(player[], int);

/****************************************************************************************/




/**************************************MAIN PROGRAM*****************************************/

int main()
{
    	//local constants
    	const int QUIT    = -1;
	const int MAX_L   = 7;	    	//Size of last name.
	const int MAX_F   = 5;		//Size of frist name.
	const int MAX_P   = 5;  	//Size of roster.
	const int SIZE    = 51;		//For setw of input.
    
    
	//local variables
	string  First;			//Holds a first name to be stored in array.
	string  Last;			//Holds a last name to be stored in array.	
	int 	Count     = 0;		//To keep everything at the same position.	
	player  Player_1;               //Player structure including jersey number, name and position.
	player  Roster[MAX_P];          //Array of Players of max size MAX_P/
	
	/**************************start main program*********************/

	//Display header.
	cout << "\n\n\n";
	cout << setw(50) << "------------------------" << endl;
	cout << setw(50) << "|   Stuctured Players  |" << endl;
	cout << setw(50) << "------------------------" << endl;
	
	//Display instructions and expample.	
	cout << "\n" << setw(60) << "Enter player data. (e.g., 99 Gretzky Wayne C)" << "\n\n\n";
	
	//Get jersey number or quit code.
	Player_1.J_num = get_num(SIZE);	
	
	//While the jersey number is not quit.
	while(Player_1.J_num != QUIT)
	{		
		cout << "\n";
	
		//Get player's name.
		Player_1.Name	  = get_name(MAX_L, MAX_F, SIZE);
		
		cout << "\n";
		
		//Get player's position.
		Player_1.Position = get_position(SIZE);
		
		cout << "\n";
		
		//Insert data into the roster array.
		fill_roster(Count, Player_1, Roster);
		
		//Increment the count.
		Count++;
				
		//If the count is at max.		
		if(Count == MAX_P)
		{			
			//Display array full message.
			cout << setw(48) << "!Max players reached!" << endl;
			
			//Pause for reflection.
			system("pause");
			
			//Set jersey num to quit (quits loop).
			Player_1.J_num = QUIT;
		}
		
		//Count not max.
		else
		{	
			//Clear the screen.
			system("cls");
				
			//Display header.
			cout << "\n\n\n";
			cout << setw(50) << "------------------------" << endl;
			cout << setw(50) << "|   Stuctured Players  |" << endl;
			cout << setw(50) << "------------------------" << endl;
			
			//Display how many players have been enetered.
			cout << setw(24)<< "|" << Count << "|" << " " << "Player(s) enetered." << "\n\n";
				
			//Get next jersery num or quit.
			Player_1.J_num = get_num(SIZE);	
		
		}//END If-Else.
		
		
	}//END While.	
	
	
	//Clear the screen.
	system("cls");
	
	
	//If count is 0.
	if(Count == 0)
	{
		//Display exit message.
		cout << "\n\n\n\n\n\n";
		cout << setw(51) << "--------------------------" << endl;
		cout << setw(51) << "|    Have a nice day!    |" << endl;
		cout << setw(51) << "--------------------------" << endl;
		cout << "\n\n\n\n\n";
	}
	//Count is not 0.
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
		display(Roster, Count);
		
		//Display output footer.
		cout << setw(51) << "--------------------------" << endl;
	}
	
	
		
	//return 0 to the OS and pause the screen
	system("pause");
    return (0);
	
}   //End main program



/**************************************************
 **		FUNCTION DEFINITIONS		 **
 **************************************************/



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
 
int get_num(int SIZE)
{
	//local constants
	
	//local variables
	int Num;		//To get the jersery number or quit value.
	
	/**************************************************/
	
	//Promt for jersey number or quit.
	cout << setw(SIZE) << "Jersey number (-1 to quit): ";
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
 
string get_name(int MAX_L, int MAX_F, int SIZE)
{
	//local constants
	
	//local variables
	string Name;
	string Last;
	string First;
	string Space = " ";
	
	/*************************************/
	
	//Promt for last name.
	cout << setw(SIZE) << "Last name                 : ";
	
	//Insert keyboard input into Last.	
	cin >> Last;
	
	cout << "\n";
	
	//Promt for first name.
	cout << setw(SIZE) << "First name                : ";	
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
 *	Get position from keyboard input as string
 *  Set first character of string to position
 *  return position	
 *END get_position
 ********************************************************************/
 
char get_position(int SIZE)
{
	//local constants
	
	//local variables
	string Input;
	char Position;
	
	/*************************************/
	
	//Promt for position.
	cout << setw(SIZE) << "Position                  : ";
	cin >> Input;
	
	//Shorten the string to 1 char.
	Position = Input[0];
	
	//Return Position.
	return toupper(Position);

}//END title_case.




/********************************************************************
 *Function Name  : title_case                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
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
	const string SPACE   = " ";
	
	//local variables
	
	
	/***************************************************/
	
	//If name is less than max.
	if(First.length() < MAX_F)
	{
		//for values from length to max.
		for(int ii = First.length(); ii < MAX_F; ii++)
		{
			//Add spaces to name.
			First = First + SPACE;			
		}		
	}
	
	//Name is more than max.
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
	const string SPACE   = " ";
	
	//local variables
	
	
	/**************************************************/
	
	//If name is less than max.
	if(Last.length() < MAX_L)
	{
		//for values from length to max.
		for(int ii = Last.length(); ii < MAX_L; ii++)
		{
			//Add spaces to name.
			Last = Last + SPACE;			
		}		
	}
	
	//Name is more than max.
	else
	{
		//Truncate to max.
		Last = Last.substr(0, MAX_L);	
	}
	
	//Return name.
	return Last;
	
}//END l_format.



/***************************************************************************************************************
 *Function Name  : fill_roster                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Inserts the current player structure into the roster array at the count position.
 *
 *BEGIN fill_roster
 *	Insert player into roster at count
 *END fill_roster
 ***************************************************************************************************************/

void fill_roster(int Count, player Player_1, player Roster[])
{
	//local constants
	
	//local variables
	
	/*******************************************/	
	
	//Insert player into roster at count.
	Roster[Count] = Player_1;
	
}//EMD fill_roster




/***************************************************************************************************************
 *Function Name  : display                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Displays each array from 0 to Count.
 *
 *BEGIN display
 *	FOR (values from 0 to Count)
 *		Display array values, space delimited, with margin markers
 *	END FOR
 *END display
 ***************************************************************************************************************/

void display(player Roster[], int Count)
{
	//local constants
	
	//local variables
	
	/*******************************************************************************************/
	
	
		
		//For values from 0 to count.
		for(int ii = 0; ii < Count; ii++)
		{
			//For formatting.
			cout << setw(51) << "|                        |" << endl;
			
			//Display all of the array values at the loop counter delimited by spaces with margin markers.
			cout << setw(26) << "|" << setw(2)  << Roster[ii].J_num << "    "  << Roster[ii].Name << "   " 
			     << Roster[ii].Position << "|" << endl;
		}
		
		//For Formatting.
		cout << setw(51) << "|                        |" << endl;
		
}//END display
