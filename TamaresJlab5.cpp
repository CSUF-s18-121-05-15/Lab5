//Justin Tamares
//CPSC 121 Lab 5
//2/26/18

#include <iostream>
using namespace std;

const int SIZE = 5;//Global constant used for multiple functions

int arraySum(int[], const int);//Prototype headers used for better readability
double arrayMean(int[], const int);
void arrayDisplay(int[], const int);
void sequenceArray(int[], const int);
int arraySearch(int[], const int, int);

int main()
{
	int choice, userArray[SIZE];
	char answer; //char is used to go back to the menu
	cout << "Please enter your first number" << endl;
	cin >> userArray[0];
	cout << "Please enter your second number" << endl;
	cin >> userArray[1];
	cout << "Please enter your third number" << endl;
	cin >> userArray[2];
	cout << "Please enter your fourth number" << endl;
	cin >> userArray[3];
	cout << "Please enter your fifth number" << endl;
	cin >> userArray[4];
	//The user has finished entering their numbers
	do
		//Do while loop used to repeat menu if necessary
	{
		cout << "Please select from the following menu" << endl;
		cout << "1.Sum of Array" << endl;
		cout << "2.Mean of Array" << endl;
		cout << "3.Display Array" << endl;
		cout << "4.Sequence Array" << endl;
		cout << "5.Search Array" << endl;
		cout << "6.Edit Array" << endl;
		cout << "7.Exit" << endl;
		cin >> choice;
		switch (choice)//Switch statement to be more organized and to select from menu
		{
		case 1:
		{
			cout << "The sum is " << arraySum(userArray, SIZE) << endl;//Calls the sum function
			cout << "Would you like to go back to the menu?" << endl;//Yes or no question provided to go back to the menu; repeated with every case except the exit option
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}
		case 2:
		{
			cout << "The mean is " << arrayMean(userArray, SIZE) << endl;//Calls the function to calculate the mean
			cout << "Would you like to go back to the menu?" << endl;
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}
		case 3:
		{
			arrayDisplay(userArray, SIZE);//Calls the function to display array
			cout << "Would you like to go back to the menu?" << endl;
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}
		case 4:
		{
			sequenceArray(userArray, SIZE);
			cout << "Would you like to go back to the menu?" << endl;
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}
		case 5:
		{
			int num;
			cout << "Please enter a number you are searching for" << endl;//The user enters a number that they want to find in the array
			cin >> num;
			int position = arraySearch(userArray, SIZE, num);//This num has to be defined by cin first in order to be used.
															 //position is created so it can received the return value from the search function
			arraySearch(userArray, SIZE, num);//Calls the search function

			if (!(position == -1))//If the value is not -1, the position of the array is displayed
			{
				cout << "The position of the number in the array is [" << position << "]" << endl;
			}
			else
			{
				cout << "Your value was not found in the array" << endl;// If the user enters any number that is not in the array, they will get this message
			}
			cout << "Would you like to go back to the menu?" << endl;
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}
		case 6://User re-enters values for the array
		{
			cout << "Please re-enter your first number" << endl;//instead of using a function, it edits in the int main function.
			cin >> userArray[0];
			cout << "Please re-enter your second number" << endl;
			cin >> userArray[1];
			cout << "Please re-enter your third number" << endl;
			cin >> userArray[2];
			cout << "Please re-enter your fourth number" << endl;
			cin >> userArray[3];
			cout << "Please re-enter your fifth number" << endl;
			cin >> userArray[4];
			cout << "Would you like to go back to the menu?" << endl;
			cout << "Yes or no?" << endl;
			cin >> answer;
			break;
		}

		case 7://Return(0) is used to exit the program
		{
			return(0);
		}

		}
	} while (answer == 'y' || answer == 'Y');//Doesn't matter if the Y is capitalized or not

	system("pause");
	return(0);

}

int arraySum(int userArray[], const int arraySize)
{
	int sum = 0;
	for (int count = 0; count < arraySize; count++)
		sum += userArray[count];//Combined operator for the sum
	return sum;
}

double arrayMean(int userArray[], const int arraySize) //double function to return.
{
	double mean = 0.0; //double is used instead of int to be more precise for the mean
	for (int count = 0; count < arraySize; count++)
	{
		mean += userArray[count];//Similar to the sum function
	}
	mean /= arraySize;//Added step of dividing by the array size
	return mean;
}

void arrayDisplay(int userArray[], const int arraySize)//Prints the array
{
	for (int count = 0; count < arraySize; count++)
	{
		cout << userArray[count] << " ";
	}
	cout << endl;
}

void sequenceArray(int userArray[], const int arraySize)
{
	int difference;
	for (int i = 0; i < 4; i++)
	{
		difference = userArray[1 + i] - userArray[0 + i]; //Repeats until 4 and 3
		cout << difference << " ";
	}
	cout << endl;
}

int arraySearch(int userArray[], const int arraySize, int number)//This function is heavily based on the search examples from chapter 8 in the textbook.
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < arraySize && !found)
	{
		if (userArray[index] == number)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}
