//Stefan Emmons
//COSC 2030-01
//Lab 01
//Dr. Hill, or Pedro Marquez
//2-6-2019

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
	string fileName;
	int first = 0, last = 0, pent = 0, offByOne = 0, count = 0;
	float num = 0;
	ifstream inFile;
	//While the operations for this program are fairly limited, we still need a few variables to hold the user file,
	//and initialize the integer values that will hold our desired values from each file.
	//"num" is essentially a placeholder for each iteration of the following "while" loop. While declaring this variable as a float isn't 
	//entirely neccessary, it's a safeguard. 

	cout << "Please enter the file name you are looking for: ";
	cin >> fileName;
	inFile.open(fileName);
	if (!(inFile))
	{
		//This is a very basic file name check, and will essentially let the user know if they have a problem with file input.
		cout << "Error, this file does not exist. Please check your spelling or directory."<<"\n";
		system("pause");
		return 0;
	}

	if(inFile.good())
	{
		//If the file opens with no problems, the following operations will be carried out. 
		while (!inFile.eof())
		{
			//Since we are not allowed to store information in an array or vector, I must allocate integer values to 
			//one-off variables that hold information based on the result of logical "if" statements
			//through each iteration of my "while" loop. 
			pent = offByOne;
			offByOne = num;
			inFile >> num;
			//Each variable is self documenting and relatively easy to understand. 
			if (count == 0)
			{
				first = num;
			}
			if (inFile.eof())
			{
				last = num;
			}
			count++;

		}
	}
	inFile.close();
	cout << "This data has been taken from the file specified as '" << fileName << "'.\n";
	cout << "The first number of this file is " << first << ".\n";
	cout << "The last number of this file is " << last << ".\n";
	cout << "The second to last number of this file is " << pent << ".\n";
	cout << "Overall, there are  " << count-1 << " numbers in this file.\n";
	system("pause");
	return 0;
}