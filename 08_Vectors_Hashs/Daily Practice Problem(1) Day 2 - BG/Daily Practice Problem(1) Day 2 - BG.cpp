// Daily Practice Problem(1) Day 2 - BG.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Given a list of integers nums, find and return the first number that appears only once in the list.
// If no such number exists, return -1.
// 
// So in this practice problem its very similar to the first LeetCode problem but we are looking for a number that only appears
// once in a vector. In order to solve this we use the unordered_map and vector libraries. We create the vector with the integers
// to test and then call our function within main and print the result. Within the function we set our unordered_map with two 
// integers one for the number and one for the index of the number. Then we set a variable for it in this case its countMap.
// Afterwards we loop through the vector with a key, num, and a value, nums, the key being the number and the value being
// how many times it appears in the vector. This way we can count and store the number of times each number appears in the vector.
// With this information we can then set up a second for loop to check if the countMap list has any numbers that appear just once and if so
// we return that num. Finally at the end of the program we return -1 if there isn't a single number in the vector.
//



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstUniqueNumber(const vector<int>& nums);

int main()
{
	vector<int> nums = { 4, 5, 1, 2, 1, 4, 2 };

	int result = firstUniqueNumber(nums);
	cout << "First unique number is: " << result << endl;
	
}

int firstUniqueNumber(const vector<int>& nums)
{
	unordered_map<int, int> countMap;

	for (int num : nums)
	{
		countMap[num]++;
	
	}

	for (int num : nums)
	{
		if (countMap[num] == 1)
		{
			return num;
		}
	}

	return -1;
}


//Given a list of integers nums, find and return the first number that appears only once in the list.

//If no such number exists, return -1.