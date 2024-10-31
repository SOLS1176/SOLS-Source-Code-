/*
Developer; Stephen Morais
Date: 14 August 2023
Purpose: To display all possible permutations of a list of items
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

short pNum = 0;

void FindPermutation(char list[], short left, short length)
{
	short right, temp;
	char newList[length];
	
	for(right = left; right < length; right++)
	{
		if(right > left)
		{
			temp = list[left];
			list[left] = list[right];
			list[right] = temp;
			
			cout << setw(5) << pNum << setw(length + 1) << list;
			pNum++;
			
			if(pNum % 8 == 0)
			{
				cout << endl;
			}
		}
		
		if( left < length - 1)
		{
			strcpy(newList, list);
			FindPermutation(newList, left+1, length);
		}
	}
}

int main()
{
	short i, size;
	char word[16];
	
	//cout << "Enter a word: ";
	cin >> word;
	cout << endl;
	
	size = strlen(word);
	
	cout << setw(5) << pNum << setw(size + 1) << word;
	pNum++;
	FindPermutation(word, 0, size);
	return 0;
}