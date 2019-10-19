//============================================================================
// Name        : testDigits.cpp
// Author      : Djordje
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void printUnique(int l);

void printUnique(int l)
{
    // Start traversing the numbers
        int num = l;
        bool visited[10] = {false};
        int visitedCounter = 0;

        // Find digits and maintain its hash
        while (num)
        {

            if (visited[num % 10]){
            	// TO DO , FIX THIS FOR 4 DIGIT NUMBERS,
            	// COMPARE THE SETS OF UNIQUE DIGITS.
            	visitedCounter++;
            }

            if(visitedCounter == 2){
            	  // if a digit occurs more than 2 times
            	  // then break
                break;
            }

            visited[num%10] = true;

            num = num/10;
        }

        // num will be 0 only when above loop
        // doesn't get break that means the
        // number is unique so print it.
        if (num == 0){
            cout << l << endl;
        }
}


int main()
{

	while(1){

	int l;
    cout << "enter a number: " << endl;
    cin >> l;
    printUnique(l);

	}
    return 0;
}
