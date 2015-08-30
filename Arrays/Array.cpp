/********************************************************************
 *Program Name:   Array                
 *Author      :   Joseph Cohen
 *Date        :   13 Spetember 2013
 *Description :   This program will perform an insertion sort into an array.  
 *Input positive integers in the range of 1 - 10 and place them in ascending 
 *order into an array. Use a sentinel value to stop entering integers. 
 *The user should not be allowed to enter more than 10 valid values.
 *
 *BEGIN Ordered Array Insert
 *	Init array count = 0
 *  	Init quit = 0
 *	Init max = 5
 *	Call function to input the first value
 *	WHILE (the value is not quit)
 *		IF (the value is not in range)
 *			Display "Invalid Input Value"
 *		ELSE (the value is in range)
 *			Call the array_insert function to put the number in the array
 *			Increment the array count
 *		END IF
 *		IF (the array is at max)
 *			Clear the screen
 *			Display "Reached Data Limit" message
 *			Set the input value = quit value
 *		ELSE
 *			Call function to input the next value
 *		END IF
 *	END WHILE
 *	Clear Screen
 *	Prompt user to display array in ascending or descending order
 *	IF (user chooses ascending order)
 *		call function to display ascending order
 *	ELSE
 *		display function in descending order
 *	END IF
 *	Display closing remarks
 *END Array Insert
 ********************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;




/***************************FUNCTION PROTOTYPES***********************/
void print_ascend(int Array[], int Count);
void print_descend(int Array[], int Count);
int  input_num();
char display_choice(char Choice);
bool input_validation(int Input);
void array_insertion(int Array[], int Input, int Count);
/********************************************************************/




/**********************************MAIN******************************/
int main()
{
	//local constants
	const int  QUIT = 0;
	const int  MAX  = 5;
	const char NORM = 'a';
    
	//local variables	
	int  Count = 0;         //Array Index
	int  Array[MAX];        //Array to store values	
	int  Input;             //Value to be entered into array
	char Choice;            //Choice for Display function
	    
    /******************************start main program******************************/

	//Prompt for number input.
	cout << "\n\n\n";
	cout << setw(50) << "------------------------" << endl;
	cout << setw(50) << "|Welcome to the Matrix!|" << endl;
	cout << setw(50) << "------------------------" << endl;
	cout << "\n" << setw(57) << "At any time enter zero (0) to quit." << endl;
	cout << "\n" << setw(57) << "Valid values are between 1 and 10. " << endl;
	
	//retreive input.
	Input = input_num();
	
	
	
	//If not quit, validate input.
	while(Input != QUIT)
	{
		//If input is bad data display error message.
		if(input_validation(Input))
			cout << "\n" << setw(47)<< "!Invalid Array Value!";
			
		//Insert input into the array and increment the count.
		else
		{
			array_insertion(Array,Input,Count);
			Count++;
		}
		
		//If array is full.
		if(Count == MAX)
		{
			//Display the full array messge.
			cout << "\n" << setw(47)<< "!Array Limit Reached!" << "\n";
			system("pause");
			
			//Quit the loop
			Input = QUIT;
						
		}
		
		//Get more input.
		else
		{
			Input = input_num();
		}
	}//END while.
	
	
	
	//Clear screen
	system("cls");
	
	
	
	//If the user quits early display exit message
	if(Count == 0)
	{
		cout << "\n\n\n\n\n\n";
		cout << setw(51) << "--------------------------" << endl;
		cout << setw(51) << "|    Have a nice day!    |" << endl;
		cout << setw(51) << "--------------------------" << endl;
		cout << "\n\n\n\n\n";
	}
	
	//Else give display options.
	else
	{
				
		//if the display choice is for ascending display in that order.
		if(display_choice(Choice) == NORM)
		{
			print_ascend(Array[], Count);		
		}
		//if display choice is not ascening print descending.
		else
		{			
			print_descend(Array, Count);		
		}
	}
	
	
	
	//return 0 to the OS and pause the screen
	system("pause");
    return (0);
	
}//End main program

/********************************************END MAIN******************************/





/*******************************************FUNCTION DEFINITIONS****************/


/********************************************************************
 *Function Name  : print_ascend                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description    : Prints the array in ascending order until it 
 *	reaches the max array position.
 *
 *BEGIN print_ascend
 *	Clear the screen
 *	Display the header
 *	FOR (starting at zero and ending at max array position)
 *		Display array values
 *	END FOR
 *	Display Footer
 *END print_ascend
 ********************************************************************/

void print_ascend(int Array[], int Count)
{

	//local constants
        
	//local variables	
		    
	/********************************************************************/ 

	//clear the screen.
	system("cls");

	//print data.
	cout << "\n\n\n";
	cout << setw(50) << "-------------------------" << endl;
	cout << setw(50) << "|Array Results Ascending|" << endl;
	cout << setw(50) << "-------------------------" << endl;
	cout << endl;
	cout << setw(52) << "------------------------------" << endl;
	for(int ii = 0; ii != Count; ii++)
	{
		cout << setw(40) << "Array Value (" << ii + 1 << "): " << setw(3) << Array[ii] << endl;
	}	
	cout << setw(52) << "------------------------------" << endl;
	
}//END print_ascending





/********************************************************************
 *Function Name  : print_descend                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description    : Prints the array in descending order from 
 *	the max array position to zero.
 *
 *BEGIN print_descend
 *	Clear the screen
 *	Display the header
 *	FOR (starting at max array position ending at zero)
 *		Display array values
 *	END FOR
 *	Display Footer
 *END print_descend
 ********************************************************************/

void print_descend(int Array[], int Count)
{

	//local constants
        
	//local variables	
		    
	/********************************************************************/ 
	
	//clear the screen.
	system("cls");
	
	//print data.
	cout << "\n\n\n";
	cout << setw(51) << "--------------------------" << endl;
	cout << setw(51) << "|Array Results Descending|" << endl;
	cout << setw(51) << "--------------------------" << endl;
	cout << endl;
	cout << setw(52) << "------------------------------" << endl;	
	for(; Count > 0  ; Count--)
	{
		cout << setw(40) << "Array Value (" << Count << "): " << setw(3) << Array[Count - 1] << endl;
	}	
	cout << setw(52) << "------------------------------" << endl;
	
}//END print_descending



	
	
/********************************************************************
 *Function Name  : intput_num                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description    : Retrieves a number from the user via the
 *	keyboard and returns the value.
 *
 *BEGIN input_num
 *	Prompt user for input
 *	Get input
 *	return input
 *END input_num
 ********************************************************************/	
	
int input_num()
{
 
 	//local constants
 	
 	//local varianbles
 	int Input;
 	
	/********************************************************************/

	//promt the user for a value.
	cout << "\n" << setw(51) << "Please enter a number :  ";
	
	//store the users input.
	cin  >> Input;
	
	//return the input
	return Input;
	

}//END input_num.





/********************************************************************
 *Function Name  : display_choice                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description	 : Displays a menu of options asking the user
 *	if they want to view the results in
 *	ascending or descending order.
 *
 *BEGIN display_choice
 *	Clear the screen
 *	Display menu
 *	Get choice
 *	return choice
 *END display_choice
 ********************************************************************/

char display_choice(char Choice)
{
 
 	//local constants
 	
 	//local variables
 
 
 
	/********************************************************************/
 
	//Clear screen.
	system("cls");
		
	//Display choice menu.
	cout << "\n\n\n";
	cout << setw(60) << "-------------------------------------" << endl;
	cout << setw(60) << "Would you like to view the results,  " << endl;
	cout << setw(60) << "Ascending (a)                        " << endl;
	cout << setw(60) << "Descending (d)?                      " << endl;
	cout << setw(39) << "Enter a choice: ";
	
	//Store the user's choice.
	cin >> Choice;
	
	//Blank line.
	cout << endl;
	
	//Return the choice.
	return Choice;
	
}//END display_choice.





/********************************************************************
 *Function Name  : input_validation                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description	 : Determines if the input passed to the function
 *	is between 1 and the max value.
 *
 *BEGIN input_validation
 *	IF (input is between 1 and max)
 *		return true
 *	ELSE
 *  	return false
 *END input_validation
 ********************************************************************/

bool input_validation(int Input)
{
 
	//local constants
	const int MAX = 10;
	
	//local variables
	
	
	/**************************************************************************/
	
	//If input is between 1 and 10, return true.
	if(Input < 1 || Input > MAX)
		return true;
		
	//If input is not between 1 and 10, return false.	
	else
		return false;
		
}//END input_validation





/********************************************************************
 *Function Name  : array_insertion                
 *Author         : Joseph Cohen
 *Date           : 13 Spetember 2013
 *Description	 : Inserts the input value from the 
 *					     keyboard and returns the value.
 *
 *BEGIN array_insertion
 *	Insert input into Array at count
 *	FOR (set the key to count, end when key = 0)
 *  	WHILE (the array at key is less than count - 1)
 *  		Swap array[count] and array[count - 1]
 *      END WHILE
 *	END FOR
 *END array insertion
 ********************************************************************/

void array_insertion(int Array[], int Input, int Count)
{

	//local constants
		
	//local variables	
	int Temp;               //For ordering the main array.
	
	/**************************************************************************/
	
	//Insert Input in the array at Count.
	Array[Count] = Input;
		
	//Set the key = to count to compare the previous array value.
	for(int Key = Count ; Key > 0 ; Key--)
	{
		
		
		//Loop while the array value at count is less than the previous value.
		while(Array[Key] < Array[Count - 1])
		{
			//Swap array values until the lowest numbers are at the beginning.
			Temp = Array[Count - 1];		
			Array[Count - 1] = Array[Count];			
			Array[Count] = Temp;			
			
			//Decrement Count
			Count--;
			
		}//END while.
		
	}//END for.
	
}//END array_insertion.












