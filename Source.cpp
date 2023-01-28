/*Lab_Assignment_B.Green.cpp
Bryce Green
3/28/2021
Version 1.0
The program takes the 10 five digit numbers in the vector and asks the user to input a 5 digit number to see if it matches and if they are lucky or not.*/

#include <iostream>
#include <vector>
using namespace std;

//prototype for the binary search function
int binarySearch(vector<int>&, int, int);


int main()
{
	//creating a vector with the lucky numbers
	vector<int> lottery = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
	int luckynumber;

	//asks the user to input 5 digit number
	cout << "Enter the 5 Digit Number: ";
	cin >> luckynumber;

	//assigns the binary search output into the variable value
	int value = binarySearch(lottery, 10, luckynumber);

	//if the value is equivalent to -1, then output not a winner
	if (value == -1)
	{
		cout << "Not a winner :( better luck next time";
	}

	//everything else should be a winner, gives back the winning number that they matched with
	else
	{
		cout << "OMG YOU WON WOOHOO, your winning number is... "<< lottery[value];
	}
}

//Binary Search Function
int binarySearch(vector<int> &lottery, int numElems, int value)
{
	int first = 0, // First array element
		last = numElems - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag
	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate midpoint
		if (lottery[middle] == value) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (lottery[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}
