#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<iostream>
using namespace std;

void strcpy( char wordsTo[], char wordsFrom[]);
int strcmp( char words[], char slotConfig[]);
void fileNew( char newFile[], char slotConfig[][3][10]);
void fileStart( char words[][10], int numb[] );
void fileIn( char slotConfig[][3][10], char fileName[]);
int main(){
	//declaring variable
	unsigned seed = time(NULL);
	int value[6];
	char symb[6][10];
	char symbnew[10][3][10];
	// Trying to open a file to fin FIX THIS PLEASE
	fileStart( symb, value);
	srand(time(NULL));
	bool menu = true;
	bool menu2 = false;
	int column;
	int stop;
	char fileCreate[50];
	char fileGrab[50];
	char selection;
	int selection2;
	while(menu == true)
	{
		selection = '0';
		cout << " Welcome to the slots " << endl;
		cout << " ==================== " << endl;
		cout << " 1. Generate new slot configuration" << endl;
		cout << " 2. Access Existing configuration from existing file" << endl;
		cout << " 3. Print slot configuration to screen" << endl;
		cout << " 4. Save slot configuration to a file" << endl;
		cout << " 5. Quit" << endl;
		cin >> selection;
		
		switch(selection)
		{
				//What file they would like to create
			case '1':
				cout << "Generating new Configuration save or dont load in new file or this config will be lost!" << endl;
				for(int i = 0; i < 10; i++)
				{
					for(int j = 0; j < 3; j++)
					{
					strcpy( symbnew[i][j], symb[rand()%6]);
					
					}
				}
				break;
			// what file they want to access
			case '2':
				cout << "What file would you like to access?" << endl;
				cin >> fileGrab;
				fileIn( symbnew, fileGrab);			
				break;
			case '3':
				menu2 = true;
				while(menu2 == true)
				{				
					cout << "Would you like to print out column and stop or the whole config?" << endl;
					cout << "1. To mess around in column and stop to see number value?" << endl;
					cout << "2. Print out whole Config to screen" << endl;
					cout << "3. Return to main menu" << endl;
					cin >> selection2;
					switch(selection2)
					{
						case 1:
							cout << "What column from 1-3 would you like to access?" << endl;
							cin >> column;
							cout << "What stop from 1-10 would you like to access?" << endl;
							cin >> stop;
							for(int i = 0; i < 6; i++)
							{
								if( strcmp(symbnew[stop-1][column-1],symb[i]) == 0)
								{
									cout << "The Symbol is " << symb[i] << " and the value is " << value[i] << endl;
									cout << endl << endl;								
								}
							}
							break;
						case 2:
							for(int i = 0; i < 10; i++)
							{
								cout << symbnew[i][0] << " " << symbnew[i][1] << " " << symbnew[i][2] << endl;
							}
							break;
						case 3:
							menu2 = false;
					}	
				} 
				break;
			case '4':
				cout << "What do you want save this configuration as?" << endl;
				fileNew( fileCreate, symbnew);
				break;
			//leaving the menu
			case '5':
				menu = false;		
	
		}

			
	}

	
	

	return 0;	
}
//Making the new file
void fileNew( char newFile[], char slotConfig[][3][10] )
{
	cin >> newFile;
	//Saving the name to new memory then placing it in a fout program so it saves to new file
	ofstream fout(newFile);	
	for(int i = 0; i < 10; i++)
	{
		fout << slotConfig[i][0] << " " << slotConfig[i][1] << " " << slotConfig[i][2] << endl;
	}
}
//Beginning programm to generate a list
void fileStart( char words[][10], int numb[] )
{
	ifstream fin("symbols");
		//having it save the words and value
	for(int i = 0; i < 7; i++)
	{
		
		fin >> words[i] >> numb[i];
	
	}
}
void fileIn( char slotConfig[][3][10], char fileName[])
{
	ifstream fin(fileName);
	for(int i = 0; i < 10; i++)
	{
		
		fin >> slotConfig[i][0]	>> slotConfig[i][1] >> slotConfig[i][2];
	}
}
int strcmp( char words[], char slotConfig[])
{
	int i = 0;
	int j = 0;
	bool newman = false;
	while( newman == false)
	{
				
		if(words[i] == slotConfig[i])
		{
			j = j;
		}
		else
		{
			j++;
		}
		if(words[i] == '\0')
		{
			newman = true;
		}
		i++;
	}
	return j;
} 
void strcpy( char *wordsTo, char *wordsFrom)
{
	int i = 0;
	bool newman = false;
	while( newman == false)
	{
				
		wordsTo[i] = wordsFrom[i];
		if(wordsFrom[i] == '\0')
		{
			newman = true;
		}
		i++;
	}
} 
