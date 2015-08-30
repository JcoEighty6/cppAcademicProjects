/********************************************************************
 *Program Name   : Fun with Strings                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Gets player info such as jersey number name and
 *	position. Stores each of the data components in corresponding 
 *	arrays. The first and last name are split into two arrays. 
 *  The data is then formatted into a team roster and displayed with
 *  the names in title case and the position as a capital.
 *
 *BEGIN Fun with Strings
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
 *	WHILE (Jersey num is not quit)
 *		Store player info in corresponding arrays 
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
 *	END Fun with strings
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;



/***********************************FUNCTION PROTOTYPES**********************************/

int 	get_num();
string  get_name();
char 	get_position();
string  title_case(string);
string  f_format(string, int);
string  l_format(string, int);
void 	fill_roster(int , int , string , char , int [], string [], string [], char []);
void	display(int, int [], string [], string [], char [], int, int);

/****************************************************************************************/




/**************************************MAIN PROGRAM*****************************************/

int main()
{
    	//local constants
    	int QUIT      = -1;
	int MAX_P     = 5;			//Max number of players.
	int MAX_L     = 10;	    		//Size of last name.
	int MAX_F     = 7;		       	//Size of frist name.  
    
    
	//local variables	
	int 	J_num;				//Holds jersey number to be stored in array.
	string  First;				//Holds a first name to be stored in array.
	string  Last;				//Holds a last name to be stored in array.
	string  Name;				//Last and First name to be stored in array.
	char 	Position;			//Holds plyayer position to be stored in array.	
	int 	Jerseys[MAX_P];			//roster of jersey numbers.
	string  F_name[MAX_P];			//roster to hold first names.
	string  L_name[MAX_P];			//roster to hold last names.
	char 	Positions[MAX_P];		//roster of positions.
	int 	Count = 0;			//to keep everything at the same position.
	
	/**************************start main program*********************/

	//Display header.
	cout << "\n\n\n";
	cout << setw(50) << "------------------------" << endl;
	cout << setw(50) << "|  !Fun With Strings!  |" << endl;
	cout << setw(50) << "------------------------" << endl;
	
	//Display instructions and expample.	
	cout << "\n" << setw(60) << "Enter player data. (e.g., 99 Gretzky Wayne C)" << "\n\n";
	
	//Get jersey number or quit code.
	J_num = get_num();
	
	//If jersey num is not quit.
	if(J_num != QUIT)
	{
		cout << "\n";
	
		//Get player's name.
		Name	 = get_name();
		
		cout << "\n";
		
		//Get player's position.
		Position = get_position();
		
		cout << "\n";
		
	}
	
	//While jersey number is not quit.
	while(J_num != QUIT)
	{		
		
		//Insert data into corresponding arrays
		fill_roster(Count, J_num, Name, Position, Jerseys, L_name, F_name, Positions);
	
		//Increment the count.
		Count++;
				
		//If the count is at max.		
		if(Count == MAX_P)
		{
			//Display array full message.
			cout << setw(48) << "!Max players reached!" << endl;
			
			//Set jersey num to quit (quits loop).
			J_num = QUIT;
		}
		
		//If count not max.
		else
		{
			//Get next jersery num or quit.
			J_num = get_num();
			
			//If jersey num not quit.
			if(J_num != QUIT)
			{
				
				cout << "\n";
				
				//Get next name.
				Name     = get_name();
				
				cout << "\n";
				
				//Get next position.
				Position = get_position();
				
				cout << "\n";
			}//END If.
		
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
		display(Count, Jerseys, L_name, F_name, Positions, MAX_L, MAX_F);
		
		//Display output footer.
		cout << setw(51) << "--------------------------" << endl;
	}
	
	
		
	//return 0 to the OS and pause the screen
	system("pause");
    return (0);
	
}   //End main program

/*********************************************************************************************/




/******************************************FUNCTOIN DEFINITIONS*******************************/


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
 
string get_name()
{
	//local constants
	
	//local variables
	string Name;
	string Last;
	string First;
	string Space = " ";
	
	/*************************************/
	
	//Promt for last name.
	cout << setw(26) << "Last name: ";
	
	//Insert keyboard input into Last.	
	cin >> Last;
	
	cout << "\n";
	
	//Promt for first name.
	cout << setw(27) << "First name: ";
	
	//Insert keyboard input into First.	
	cin >> First;
	
	//Set Name to concatination of Last and First, Space delimited.
	Name = Last + Space + First;
	
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
	cout << setw(25) << "Position: ";
	
	//Set Position from keyboard input
	cin >> Position;
	
	//Return Position.
	return Position;

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




/************************************************************************************************************************************
 *Function Name  : fill_roster                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Inserts jersey number, last name first name and position 
 *	into the corresponding arrays. 
 *
 *BEGIN fill_roster
 *	Init position marker to first space in name
 *	Set jersey array to jersey number at count position
 *	Set last name array at count to title case name on left side of space
 *	Set first name array at count to title case name on right side of space
 *	Set position array at count to upper case position character
 *END fill_roster
 ************************************************************************************************************************************/
 
void fill_roster(int Count, int J_num, string Name, char Position, int Jerseys[], string L_name[], string F_name[], char Positions[])
{
	//local constants
	
	//local variables
	int Pos = Name.find(' ');        //To find position of break in name.
	int length;                      //Max length of name.
	string First;                    //Holds a first name to be stored in array.
	string Last;                     //Holds a last name to be stored in array.
	
	/******************************************************/
	
	//Set jersey array to jersey num at count position.
	Jerseys[Count]   = J_num;
	
	//Set last name array at count to title case name on left side of space. 			 	
	L_name[Count]    = title_case(Name.substr(0, Pos));	
	
	//Set first name array at count to title case name on right side of space.
	F_name[Count]    = title_case(Name.substr(Pos + 1));	
	
	//Set position array at count to upper case position character.
	Positions[Count] = toupper(Position);	
	
	
}//END fill_roster




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

void display(int Count,int Jerseys[], string L_name[], string F_name[], char Positions[], int MAX_L, int MAX_F)
{
	//local constants
	
	//local variables
	
	/*******************************************************************************************/
	
	//For values from 0 to count.
	for(int ii = 0; ii < Count; ii++)
	{
		cout << "\n";
		
		//Display all of the array values at the loop counter delimited by spaces with margin markers.
		cout << setw(26) << "|" << setw(2)  << Jerseys[ii] << " "  << l_format(L_name[ii], MAX_L) << " " 
			 << f_format(F_name[ii], MAX_F) << " "         << Positions[ii]        << "|" << endl;
	}
	
	cout << "\n";
	
}//END display
