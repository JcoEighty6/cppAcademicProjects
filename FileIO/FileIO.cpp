/********************************************************************
 *Program Name   : File I/O
 *Author         : Joseph Cohen
 *Date           : 10/25/2013
 *Description    : Extracts people data from a user defined input file
 *	in the form of first name, last name and age. The data is stored in
 *	an array of people structures and sorted by age in ascending order.
 *	Finally, the sorted data is displayed on the screen.
 *
 * BEGIN File I/O
 * 	  Init count to 0
 *	  Get file name or quit
 *    WHILE not end of file and not quit
 *	  	 Validate input file
 *		 Get person 
 *		 Insert person
 *		 Increment the count
 *		 IF the count is max
 *		 	Display notification
 *			Set file name to exit
 *		 END IF
 *	  END WHILE
 *	  Display data
 * END File I/O
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

struct person
{
	string First;
	string Last;
	int    Age;
};
	


/**************************************************
 **		FUNCTION PROTOTYPES		 **
 **************************************************/


person  get_data(ifstream&);
string  f_format(string);
string  l_format(string);
string  title_case(string);
void    array_insertion(person[], person, int);
void	display(person[], int);


/*************************************************/


int main()
{
	
	//local constants
	const int MAX_P    = 10;
	const int QUIT     = 0;
	const string EXIT  = "exit";
    
	//local variables
	person   	 Person_1;
	person		 Blank;
	string   	 File_Name;
	ifstream 	 In_File;
	string   	 Age;
	person   	 People[MAX_P];
	int		 Count = 0;   
	
			
	/**************************start main program*********************/



	//Display header.
	cout << "\n\n\n\n\n\n\n";
	cout << setw(48) << "----------------" << endl;
	cout << setw(48) << "|   File I/O   |" << endl; 
	cout << setw(48) << "----------------" << endl;
	
	//Promt for file name / path / quit.
	cout << "\n" << setw(58) << "Enter file name or path ('exit' to quit)?: ";
	
	//Set user's choice.
	cin >> File_Name;
	
	//Open the input file with the user specified name or path.
	In_File.open(File_Name.c_str());
	
	
	//While the file is not at the end, the user didn't exit.
	while(!In_File.eof() && File_Name != EXIT)
	{
		//while the in file is not valid and the file name is not exit code.
		while(!In_File && File_Name != EXIT)
		{
			//Display error message.
			cout << "\n";
    		cout << setw(52) << "Input file does not exist" << endl;
    		cout << "\n";
    		
    		//Pause for reflection.
    		system("pause");
    		
    		//Clear the screen.
    		system("cls");
    			
    		//Display header.
			cout << "\n\n\n\n\n\n\n";
			cout << setw(48) << "----------------" << endl;
			cout << setw(48) << "|   File I/O   |" << endl; 
			cout << setw(48) << "----------------" << endl;
	
			//Promt for file name / path / quit.
			cout << "\n" << setw(58) << "Enter file name or path (exit to quit)?: ";
	
			//Set user's choice.
			cin >> File_Name;
	
			//Open the input file with the user specified name or path.
			In_File.open(File_Name.c_str());
			
       	}//END while 
		
		//Get next person's info from the file.
		Person_1 = get_data(In_File);      			
		
		//Insert the person into the array and sort.
		array_insertion(People, Person_1, Count);
		
		//Increment Count.
		Count++;
				
		//If the count is at max.		
		if(Count == MAX_P)
		{
			//Clear the screen.
			system("cls");
			
			//Display array full message.
			cout << "\n\n\n\n\n\n\n";
			cout << setw(48) << "!Array is full!" << "\n\n";
			cout << setw(55) << "!No more people can be eneterd!" << endl;
			cout << "\n\n\n\n\n";
			
			//Pause for reflection.
			system("pause");
			
			//set the file name to exit code.
			File_Name = EXIT;
			
		}//END if
		
	}//END While
		
	//clear screen.
	system("cls");
	
		
	//If the user didn't choose to exit.
	if(Count > 0)
	{
		//Display all the people in the array.
		cout << "\n\n\n\n\n";
		cout << setw(51) << "-------------------" << endl;
		cout << setw(51) << "|     People      |" << endl; 
		cout << setw(51) << "-------------------" << endl;
		cout << "\n";		
		cout << setw(52) << "======================";
		display(People, Count);
		cout << "\n";
		cout << setw(52) << "======================";
		cout << "\n\n\n";
		
		//Pause for reflection.
		system("pause");
	}	
		
	//Clear the screen.	
	system("cls");	
		
	//Display exit message.
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << setw(51) << "-------------------" << endl;
	cout << setw(51) << "| Have A Nice Day |" << endl; 
	cout << setw(51) << "-------------------" << endl;
	cout << "\n\n\n\n\n";

	
	//return 0 to the OS and pause the screen.
	system("pause");
    return (0);
	
}   //End main program.





/**************************************************
 **		FUNCTION DEFINITIONS		 **
 **************************************************/



/********************************************************************
 *Function Name  : get_data                
 *Author         : Joseph Cohen
 *Date           : 2 October 2013
 *Description	 : Extracts the first and last name and age  
 *	respectively from the file-stream. Converts age to an integer
 *	returns a struct of type person. 
 *
 *BEGIN get_data 
 *	Extract first name from the file-stream
 *	Format  name into title case and appropriate length
 *	Extract last name from the file-stream
 *	Format name into title case and appropriate length
 *	Extract age from file-stream
 *	Convert age to integer
 *  Return person	
 *END get_data
 ********************************************************************/

person get_data(ifstream& In_File)
{
	//local constants
	
	//local variables
	string First;
	string Last;
	string Age;
	person Person_1;
	
	/***************************/
		
	In_File >> First;
	
	Person_1.First = title_case(f_format(First));
	
	In_File >> Last;
	
	Person_1.Last  = title_case(f_format(Last));
	
	In_File >> Age;
	
	Person_1.Age = atoi(Age.c_str());
	
	return Person_1;
}//END get_data





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


string f_format(string First)
{
	//local constants
	const int    MAX_F = 7;
	const string Space = " ";
	//local variables
	
	
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

string l_format(string Last)
{
	//local constants
	const int     MAX_L  = 10;
	const string  Space  = " ";
	
	//local variables
	
	
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
 *Function Name  : array_insertion                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description	 : Inserts the input value from the 
 *keyboard and returns the value.
 *
 *BEGIN array_insertion
 *	Insert person into Array at count
 *	FOR (set the key to count, end when key = 0)
 *  	WHILE (the age of person at key is less than age at count - 1)
 *  		Swap array[count] and array[count - 1]
 *      END WHILE
 *	END FOR
 *END array insertion
 ********************************************************************/

void array_insertion(person People[], person Person_1, int Count)
{

	//local constants
		
	//local variables	
	person Temp;               //For ordering the main array.
	int    Key = -1;
	
	/**************************************************************************/
	
	
	//If the count is 0
	if(Count == 0)
	{
		//Insert Input in the array at Count.`
		People[Count] = Person_1;
	}
	//Count not 0
	else
	{
		//for values from 0 to count
		for(int ii = 0; ii < Count && Key > -1; ii++)
		{
			//if person's age is less than age at array location
			if(Person_1.Age < People[ii].Age)
				//set key to current location
				Key = ii;
		}
		
		//for values from count to key
		for(Count; Count > Key; Count--)
		{
			//move the next lowest array location to the current count location
			People[Count] = People[Count - 1];
		}
		
		//move person 1 to the key location.
		People[Key] = Person_1;
	}
	
}//END array_insertion.





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

void display(person People[], int Count)
{
	//local constants
	
	//local variables
	
	/*******************************************************************************************/
	
	
		
		//For values from 0 to count.
		for(int ii = 0; ii < Count; ii++)
		{
			cout << "\n";
			
			//Display all of the array values at the loop counter delimited by spaces with margin markers.
			cout << setw(32) << "|  " << setw(3)  << People[ii].Age << " "  << People[ii].Last << " " 
			     << People[ii].First << " |";
			     
		}
		
	
}//END display




