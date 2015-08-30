/********************************************************************
 *Program Name   : File I/O
 *Author         : Joseph Cohen
 *Date           : 10/25/2013
 *Description    : Extracts people data from a user difined input file
 *in the form of first name, last name and age. The data is stored in
 *an array of people structures and sorted by age in ascending order.
 *Finally, the sorted data is displayed on the screen.
 *
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

struct  player
{
	int 	J_Num;
	string  Name;
	char 	Position;		
};




/**************************************************
 **		CLASS DESCRIPTION    		 **
 **************************************************/

class Roster
{
	private:
		player* Players;
		string  Team;
		string  Gender;
		string  Sport;
		int     Max_Players;
	
	public:
		
		Roster(string T_Name, string T_Gender, string T_Sport, int Max)
		{
			Team   		= T_Name;
			Gender		= T_Gender;
			Sport  		= T_Sport;
			Max_Players     = Max;
			Players 	= new player[Max];		
		}
		
		Roster(string T_Name)
		{
			//local constants
			const string GENDER   = "Boys";
			const string SPORT    = "Hockey";
			const int MAX         = 25;
			//local variables
			
			Team   		= T_Name;
			Gender 		= GENDER;
			Sport  		= SPORT;
			Max_Players     = MAX;
			Players		= new player[MAX];
		}
		
		/********************************************************************
 		*Function Name  : Add_Player                
 		*Author         : Joseph Cohen
 		*Date           : 13 Spetember 2013
 		*Description	: Inserts the input value from keyboard and returns the value.
 		*
 		*BEGIN array_insertion
 		*	Insert person into Array at count
 		*	FOR (set the key to count, end when key = 0)
 		*  		WHILE (the age of person at key is less than age at count - 1)
 		*  			Swap array[count] and array[count - 1]
		*		END WHILE
 		*	END FOR
 		*END array insertion
 		********************************************************************/
		
		void add_player(player Player_1, int Count)
		{
			

			//void array_insertion(person People[], person Person_1, int Count)


			//local constants
		
			//local variables	
			player Temp;     //For ordering the main array.
			int    Key = -1; //To track the position for insertion.
	
			/**************************************************************************/
	
	
	
			//If the count is 0
			if(Count == 0)
			{
				//Insert Input in the array at Count.`
				Players[Count] = Player_1;
			}
			//Count not 0
			else
			{
				for(int ii = 0; ii < Count && Key != -1; ii++)
				{
					if(Player_1.J_Num < Players[ii].J_Num)
						Key = ii;
				}//END for
		
				for(int ii = 0; (Count -1) > Key; Count--)
				{
					Players[Count] = Players[Count - 1];
				}//END for
		
				Players[Key] = Player_1;
			}//END else
	
		
		}//END add_player
		
		
		void add_player(int Jersey, string In_Name, int Count)
		{

			//local constants
			const char POS = 'U'; 
		
			//local variables	
			player Player_1; //For array insertion.
			player Temp;     //For ordering the main array.
			int    Key = -1; //To track the position for insertion.
	
			/**************************************************************************/
			
			//Instantiate player. 
			Player_1.J_Num    = Jersey;
			Player_1.Name     = In_Name;
			Player_1.Position = POS;
	
	
			//If the count is 0
			if(Count == 0)
			{
				//Insert Input in the array at Count.`
				Players[Count] = Player_1;
			}
			//Count not 0
			else
			{
				for(int ii = 0; ii < Count && Key != -1 ; ii++)
				{
					if(Player_1.J_Num < Players[ii].J_Num)
						Key = ii;
				}
		
				for(int ii = 0; (Count -1) > Key; Count--)
				{
					Players[Count] = Players[Count - 1];
				}
		
				Players[Key] = Player_1;
			}//END else
	
		
		}//END add_player
		
		void display(int Count)
		{
			//For values from 0 to count.
			for(int ii = 0; ii < Count; ii++)
			{
				//For formatting.
				cout << setw(52) << "|                          |" << endl;
			
				//Display all of the array values at the loop counter delimited by spaces with margin markers.
				cout << setw(26) << "| " << setw(2)  << Players[ii].J_Num << "    "  << Players[ii].Name << "   " 
			     	 << Players[ii].Position << " |" << endl;
			}
		
			//For Formatting.
			cout << setw(52) << "|                          |" << endl;
		}
		
		string get_name()
		{
			return Team;
		}
		
		string get_gender()
		{
			return Gender;
		}
		
		string get_sport()
		{
			return Sport;
		}
};
	
/********************************
 ********************************/
 
 
 
/**************************************************
 **		FUNCTION PROTOTYPES		 **
 **************************************************/
 
int 	get_num(int);
string  get_name(int, int, int);
char 	get_position(int);
string  title_case(string);
string  f_format(string, int);
string  l_format(string, int);
void 	padding(string Name); 

/*************************************************/


int main()
{
    //local constants
    const string QUIT    = "exit";
    const char	 EXIT	 = -1;
	const int MAX_L  = 7;	    	//Size of last name.
	const int MAX_F  = 5;		//Size of frist name.
	const int SIZE   = 50;		//For setw of input.
	const char NO    = 'n';
	const char YES   = 'y';        
    
    
	//local variables
	string  First;			//Holds a first name to be stored in array.
	string  Last;			//Holds a last name to be stored in array.	
	int 	Count     = 0;		//To keep everything at the same position.	
	player  Player_1;               //Player structure including jersey number, name and position.
	Roster* Team_1;                 //Points to a Roster.
	string  T_Name;
	string  T_Gender;
	string  T_Sport;
	string  Blank;
	int     T_Max;			//Size of roster.
	char    Choice;
	
		
	/**************************start main program*********************/

	//Display header.
	cout << "\n\n\n";
	cout << setw(50) << "------------------------" << endl;
	cout << setw(50) << "|     Team Roster      |" << endl;
	cout << setw(50) << "------------------------" << endl;
	
	//Display instructions and expample.	
	cout << "\n\n" << setw(SIZE) << "Enter team name ('exit' to quit): ";
	
	//Get team name or quit code.
	getline(cin, T_Name);	
	
	//Promt to add other team info.
	cout << "\n" << setw(SIZE) << "Enter team name only?      (y/n): ";
	cin  >> Choice;
	getline(cin, Blank);
	
	//While the jersey number is not quit.
	if(T_Name != QUIT && Choice == NO)
	{		
		cout << "\n";
	
		//Get team gender.
		cout << setw(SIZE) << "Enter Team Gender               : ";		
		getline(cin, T_Gender);
		
		cout << "\n";
		
		//Get team gender.
		cout << setw(SIZE) << "Enter Team Sport                : ";
		getline(cin, T_Sport);
		
		cout << "\n";
		
		//Get team gender.
		cout << setw(SIZE) << "Enter Team Size                 : ";
		cin >> T_Max;
		
		cout << "\n";
		
		//Instantiate new roster.
		Team_1 = new Roster(T_Name, T_Gender, T_Sport, T_Max);	
		
		//Clear the screen.
		system("cls");
		
		//Display header.
		cout << "\n\n\n";
		cout << setw(50) << "------------------------" << endl;
		cout << setw(50) << "|     Add Players      |" << endl;
		cout << setw(50) << "------------------------" << endl;
		cout << "\n\n";
		
		//Get player's jersey number.
		Player_1.J_Num = get_num(SIZE);
		
		while(Player_1.J_Num != EXIT)
		{			
				
			cout << "\n";
	
			//Get player's name.
			Player_1.Name	  = get_name(MAX_L, MAX_F, SIZE);
		
			cout << "\n";
			
			//Promt to add position or not.
			cout << setw(SIZE) << "Player has position?      (y/n): ";
			cin  >> Choice;
			
			cout << "\n";
			
			if(Choice == YES)
			{
				//Get player's position.
				Player_1.Position = get_position(SIZE);
					
				//Add Player to Roster.
				Team_1->add_player(Player_1, Count);
			}				
			else
			{
				Team_1->add_player(Player_1.J_Num, Player_1.Name, Count);
			}
				
			//Increment the count.
			Count++;
			
			//Clear screen.
			system("cls");
			
			if(Count == T_Max)
			{			
				//Display array full message.
				cout << setw(48) << "!Max players reached!" << endl;
			
				//Pause for reflection.
				system("pause");
			
				//Set choice to exit (quits loop).
				T_Name = QUIT;
				
			}//END if
			else
			{
				//Display header.
				cout << "\n\n\n";
				cout << setw(50) << "------------------------" << endl;
				cout << setw(50) << "|     Add Players      |" << endl;
				cout << setw(50) << "------------------------" << endl;
				cout << "\n\n";
		
				//Get player's jersey number.
				Player_1.J_Num = get_num(SIZE);
			}//END else
			
				
		}//END while				
		
		
	}
	else 
	if(T_Name != QUIT)
	{
		//Instantiate new roster.
		Team_1 = new Roster(T_Name);	
		
		//Clear the screen.
		system("cls");
		
		//Display header.
		cout << "\n\n\n";
		cout << setw(50) << "------------------------" << endl;
		cout << setw(50) << "|     Add Players      |" << endl;
		cout << setw(50) << "------------------------" << endl;
		cout << "\n\n";
		
		//Get player's jersey number.
		Player_1.J_Num = get_num(SIZE);
		
		while(Player_1.J_Num != EXIT)
		{			
				
			cout << "\n";
	
			//Get player's name.
			Player_1.Name	  = get_name(MAX_L, MAX_F, SIZE);
		
			cout << "\n";
			
			//Promt to add position or not.
			cout << setw(SIZE) << "Enter position?      (y/n): ";
			cin  >> Choice;
			
			cout << "\n";
			
			if(Choice == YES)
			{
				//Get player's position.
				Player_1.Position = get_position(SIZE);
					
				//Add Player to Roster.
				Team_1->add_player(Player_1, Count);
			}				
			else
			{
				Team_1->add_player(Player_1.J_Num, Player_1.Name, Count);
			}				
				
			//Increment the count.
			Count++;
			
			//Clear screen.
			system("cls");
			
			if(Count == T_Max)
			{			
				//Display array full message.
				cout << setw(48) << "!Max players reached!" << endl;
			
				//Pause for reflection.
				system("pause");
			
				//Set choice to exit (quits loop).
				Player_1.J_Num = EXIT;
				
			}//END if
			else
			{	
				//Display header.
				cout << "\n\n\n";
				cout << setw(50) << "------------------------" << endl;
				cout << setw(50) << "|     Add Players      |" << endl;
				cout << setw(50) << "------------------------" << endl;
				cout << "\n\n";
		
				//Get player's jersey number.
				Player_1.J_Num = get_num(SIZE);
					
			}//END else			
				
		}//END while
		
	}//END else-if
		
	
	
	//Clear the screen.
	system("cls");
	
	
			
	//Display output header.
	cout << "\n\n\n\n";
	cout << setw(51) << "--------------------------" << endl;
	cout << setw(26) << "|"; padding(Team_1->get_name());   cout << "|" << endl;
	cout << setw(26) << "|"; padding(Team_1->get_gender()); cout << "|" << endl;
	cout << setw(26) << "|"; padding(Team_1->get_sport());  cout << "|" << endl;
	cout << setw(51) << "--------------------------" << endl;
	cout << "\n";
	cout << setw(52) << "----------------------------" << endl;
	cout << setw(52) << "| #    Last    , First Pos |" << endl;
	
	//Display output information
	Team_1->display(Count);
	
	//Display output footer.
	cout << setw(52) << "----------------------------" << endl;
	
	//Pause for reflection.
	system("pause");
	
	
	//Clear the screen.
	system("cls");
	
	//Display exit message.
	cout << "\n\n\n\n\n\n";
	cout << setw(51) << "--------------------------" << endl;		
	cout << setw(51) << "|    Have a nice day!    |" << endl;
	cout << setw(51) << "--------------------------" << endl;
	cout << "\n\n\n\n\n";
	
		
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
	int Num; //To get the jersery number or quit value.
	
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

void padding(string Name)
{
	const int MAX      = 24;
	const string SPACE = " ";
	
	int Size   = Name.length();
	int First  = (MAX - Size) / 2;
	int Second = MAX - Size - First;
	
	for(int ii = 0; ii < First; ii++)
	{
		cout << SPACE;
	}
	cout << Name;
	for(int ii = 0; ii < Second; ii++)
	{
		cout << SPACE;
	}
	
}//END padding.


/******************************************
 ******************************************/

