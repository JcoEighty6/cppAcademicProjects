/********************************************************************
 *Program Name   : File Compare
 *Author         : Joseph Cohen
 *Date           : 11/1/2013
 *Description    : Compares two user specified files line by line
 *to see which lines are different. Outputs the lines of each
 *file that differ up to a max of 5.
 *
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
	
int  file_size(ifstream&);
void display(int[], int);

int main()
{
	
    //local constants
    const int 	 MAX_L = 5;
    const string QUIT = "exit";
    
	//local variables
	int         Ary[MAX_L];
	string      F_1_N;			//File 1 Name
	string      F_2_N;			//File 2 Name
	int         File1_Size;
	int         File2_Size;
	ifstream    In_File1;
	ifstream    In_File2;
	int         Line_Count = 1;
	int         Ary_Count  = 0;
	string      Compare_1;
	string      Compare_2;   
	
			
	/**************************start main program*********************/



	//Display header.
	cout << "\n\n\n\n\n\n\n";
	cout << setw(48) << "--------------------" << endl;
	cout << setw(48) << "|   File Compare   |" << endl; 
	cout << setw(48) << "--------------------" << endl;
	
	//Promt for file 1.
	cout << "\n" << setw(60) << "First file name or path ('exit' to quit)?: ";
	
	//Set user's choice.
	cin >> F_1_N;
	
	//Open the input file with the user specified name or path.
	In_File1.open(F_1_N.c_str());
	
		
	while(F_1_N != QUIT)
	{
		while(!In_File1 && F_1_N != QUIT)
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
			cout << setw(48) << "-------------------" << endl;
			cout << setw(48) << "|   File Compare  |" << endl; 
			cout << setw(48) << "-------------------" << endl;
	
			//Promt for file name / path / quit.
			cout << "\n" << setw(58) << "First file name or path ('exit' to quit)?: ";
	
			//Set user's choice.
			cin >> F_1_N;
	
			//Open the input file with the user specified name or path.
			In_File1.open(F_1_N.c_str());
			
       	}//END while 
		   
		//Promt for file 2.
		cout << "\n" << setw(60) << "Second file name or path ('exit' to quit)?: ";
	
		//Set user's choice.
		cin >> F_2_N;
	
		//Open the input file with the user specified name or path.
		In_File2.open(F_2_N.c_str());   
		
		
		while(!In_File2 && F_2_N != QUIT)
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
			cout << setw(48) << "-------------------" << endl;
			cout << setw(48) << "|   File Compare  |" << endl; 
			cout << setw(48) << "-------------------" << endl;
	
			//Promt for file name / path / quit.
			cout << "\n" << setw(58) << "Second file name or path ('exit' to quit)?: ";
	
			//Set user's choice.
			cin >> F_2_N;
	
			//Open the input file with the user specified name or path.
			In_File2.open(F_2_N.c_str());
			
       	}//END while
       	
       	File1_Size = file_size(In_File1);
       	
       	File2_Size = file_size(In_File2);
       	
       	getline(In_File1, Compare_1);       	
       	
		while(!In_File1.eof() && !In_File2.eof() && Ary_Count != MAX_L)
		{			
       		getline(In_File2, Compare_2);
       		
       		if(Compare_1 != Compare_2)
       		{
       			Ary[Ary_Count] = Line_Count;
       			
       			Line_Count++;
       			
       			Ary_Count++;
       		}
			
			if(Ary_Count == MAX_L)
			{
				system("cls");
			
				cout << setw(50) << "!Array is full!" << endl;
				cout << setw(35) << "!No more lines will be checked!" << endl;
			
				system("pause");
			}
		}//END While
		
		//clear screen.
		system("cls");
		
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << setw(51) << "--------------------" << endl;
		cout << setw(51) << "| Line Differences |" << endl; 
		cout << setw(51) << "--------------------" << endl;
		cout << "\n";
		//display(Ary, Ary_Count);
		//For values from 0 to count.
		for(int ii = 0; ii < Ary_Count; ii++)
		{
			cout << "\n";
			
			//Display all of the array values at the loop counter delimited by spaces with margin markers.
			cout << setw(32) << "|  " << setw(3)  << "Line:" << " "  << Ary[ii] << " " 
			     << "      " << " |";
			     
		}
		cout << "\n\n\n\n\n";
		
		//Pause for reflection.
		system("pause");
			
		//clear screen.
		system("cls");
		
		
		//Display header.
		cout << "\n\n\n\n\n\n\n";
		cout << setw(48) << "--------------------" << endl;
		cout << setw(48) << "|   File Compare   |" << endl; 
		cout << setw(48) << "--------------------" << endl;
	
		//Promt for file 1.
		cout << "\n" << setw(60) << "First file name or path ('exit' to quit)?: ";
	
		//Set user's choice.
		cin >> F_1_N;
	
		//Open the input file with the user specified name or path.
		In_File1.open(F_1_N.c_str());
		
	}//END while.
	
	
	//clear screen.
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




int file_size(ifstream& File)
{
	//local constants
	
	//local variables
	string Line;
	int    Count = 0;
	
	/**************************/
	
	while(!File.eof())
	{
		File >> Line;
		if(Line.length() != 0)
		{
			Count++;
		}
	}
	
	return Count;
}


void display(int Ary[], int Count)
{
	//local constants
	
	//local variables
	
	/*******************************************************************************************/
	
	
		
		//For values from 0 to count.
		for(int ii = 0; ii < Count; ii++)
		{
			cout << "\n";
			
			//Display all of the array values at the loop counter delimited by spaces with margin markers.
			cout << setw(32) << "|  " << setw(3)  << "Line:" << " "  << Ary[ii] << " " 
			     << "      " << " |";
			     
		}
}

