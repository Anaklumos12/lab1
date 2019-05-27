/**
@file maxarray.cpp
This program is designed to find the maximum value
of a given array in a specific way
@author Anurag Kumar
@date: 05-26-2019

*/

#include <iostream>

/*Template function to find the larger of
two values passed to it
@param a the first value to be compared
@param b the second value to be compared
@pre 
@return returns the larger value of a and b
*/
template <class T>
T max(T a, T b)
{
	std::cout << "a " << a << " b "<< b <<" ding\n";
	if (a > b) {
		std::cout << a << " this is a\n";
		return a;
	}
	else {
		std::cout << b << " this is b\n";
		return b;
	}
	return 0;
}

/**Template function to find the maximum value of 
the elements in a given array using recursion
while traversing the array in a binary fashion
@param anArr the array that holds the values to be searched
@param first the index of the given first value in the array
@param last the index of the given last value in the array
@pre the array exists, and has values in it, and first and last params are valid indexes of the array
@post if the search is successful, the array shouldn't change.
@throw There is no exception handling in this funciton. Have fun.
@return This will return the maximum value in this function if successful
*/
template <class T1> 
T1 maxArray(T1 anArr[], int first, int last)
{	
	int mid = (first + ((last - first) / 2));
	if (first == last) {
		//std::cout << anArr[first] << "liger\n";
		T1 arrVal = anArr[first];
		return arrVal;
		//std::cout << "baby ate your space dingos\n";
	}
	else {
		if (last - first != 1) {
			//std::cout << "for first is " << first << " and last is " << last << " mid is " << mid << '\n';
			T1 left = maxArray(anArr, first, mid);
			T1 right = maxArray(anArr, mid, last);
			//std::cout << "this is left " << left << " this is right " << right << '\n';
			return max(left, right);
			//std::cout << "dingos'll ate your space baby\n";
		}
		else {
			T1 left = maxArray(anArr, first, first);
			T1 right = maxArray(anArr, last, last);
			return max(left, right);
		}
	}
}

/* This is the main method of the lab.
I've put some pre-generated arrays in it, just uncomment
a single array at a time and it should be able to run
from there.
*/
int main()
{
	std::cout << '\n';
	//int arr[] = { 56, 95, 180, 194, 373, 380, 384, 452, 454, 497, 516, 535, 551, 566, 600, 677, 776, 861, 869, 887, 946, 958, 998, 1074, 1187, 1227, 1242, 1357, 1413, 1442, 1497, 1512, 1541, 1592, 1596, 1599, 1603, 1662, 1677, 1678, 1761, 1803, 1879, 1930, 2202, 2215, 2233, 2245, 2271, 2308 };
	//int arr[] = { 1,2,43,6,7,88,4,3 };
	//double arr[] = { 0.0314714107,0.4349440487,0.9797064638,0.7364307279,0.8366839353,0.6566659333,0.3641601281,0.5164549323,0.4028447113,0.6825495426 };
	//double arr[] = { -986, -951, -889, -855, -836, -830, -823, -774, -773, -767, -664, -651, -619, -610, -601, -579, -491, -480, -463, -454, -415, -403, -347, -315, -220, -204, -184, -154, -64, -46, 7, 9, 15, 29, 65, 81, 113, 221, 227, 258, 468, 492, 577, 611, 614, 628, 657, 669, 862, 893 };
	int theSize1 = std::size(arr);
	std::cout << '\n' << "maxArray output: " << maxArray(arr, 0, theSize1-1);
}
