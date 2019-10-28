#include <iostream>
#include "KaprekarsConstant.h"
#include <sstream>

using namespace std;

int inputNumber(void){
	int inputNumber1;
	cout << "Enter 3 or 4 digit number, with at least 2 different values (including 0):" << endl;
	cin >> inputNumber1;
	// to keep asking for the number until it's an accepted int type.
	while(cin.fail()) {
		cout << "Error, number is out of range, or wrong data type, Try again\n" << endl;
		cout << "Enter 3 or 4 digit number, with at least 2 different values (including 0):" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		cin >> inputNumber1;
	}
return inputNumber1;
}

Check displayAndCheck(int b){
	bool error = false;
	cout << "Your number is: " << b << "\n" << endl;
	// length of number, by the number of digits
	 int length = to_string(b).length();
	// range error handling
	try {
		if ( length > 4 || length < 3 ){
			throw 99;
		}
	}
	catch(int length) {
		cout << "Error, number is out of range, please enter a 3 or 4 digit number only ! error number: " << length << endl;
		cout << "Try again.\n" <<  endl;
		cout << endl;
		error = true;
		}
	 Check result = { error, length };
	 return result;
	 // returning variables will be in result.error and result.length
}

int uniqueDigitTest3Digits(int l, int a){
	if (l == 3) {
			int num = a;
			bool visited[10] = {false};
			int visitedCounter = 0;
			// Find digits and maintain its hash
			while (num)
			{
				if (visited[num % 10]){

					visitedCounter++;
				}
				if(visitedCounter == 2){

					  // if a digit occurs more than 2 times
					  // then output error
					  // this does not work for 4 digit numbers, because a value of 1122
					  // would also be declined, visitedCounter will go up, even if a different set of
					  // digits goes up.

					  cout << "Error, the input number must have at least 2 unique digits.\nTry again:\n "<< endl;
					  return 1;
				}
				visited[num%10] = true;
				num = num/10;
			}
			// num will be 0 only when above loop
			// doesn't get the error, that means the
			// num is unique, so the program continues on.
			return 2;
		}
	return 0;
}

int uniqueDigitTest4Digits(int l, int p){
	if (l == 4) {
		// following lines of code are to extract the digits out of the integer.
		int d = p % 10;
		int temp = p / 10;
		int c = temp % 10;
		temp = p / 100;
		int b = temp % 10;
		temp = p / 1000;
		int a = temp % 10;

		// make array, filled with digits of the number
		int numberArray[4] = {a , b, c, d};

		// check that each digit dooesn't repeat 3 times in the array.
		int seen[4];
			for(int i = 0; i < 4; i++)
				seen[i] = 0;

			for(int i = 0; i < 4; i++) {
				if(seen[i] == 0) {
					int count = 0;
					for(int j = i; j < 4; j++)
						if(numberArray[j] == numberArray[i]) {
							count += 1;
							seen[j] = 1;
							if (count > 2){
								cout << "Error, must contain at least 2 unique digits. " << endl;
								cout << "Try again.\n"<< endl;
								return 1;
							}
						}
					}
			}
			return 2;
	}
	return 0;
}

void operation(int a, int l){
	// array size 20, array[0] = a;
	 int casperNumbers [20] = {a};
	 int asc = 1; // for declaring whether sorting ascends or descends
	 int dsc = 2; // for declaring whether sorting ascends or descends
	 for (int i = 0; i<10;i++ ){ // change upper range in the for loop to 10
			  int unsorted = casperNumbers[i];
			  int sortedA = sortNum(unsorted, l, asc);
			  int sortedD = sortNum(unsorted, l, dsc);
			  casperNumbers[i+1] = sortedD - sortedA;
			  cout << sortedD << " - " << sortedA << " = " << casperNumbers[i+1] << endl;
			  if (casperNumbers[i] == casperNumbers[i+1]){
				  break;
			  }
	 }
	 cout << "Reached Kaprekar's constant.\n Goodbye! \n" << endl;
}

 // Bubblesort for 3 or 4 digit values, both ascending and descending, depending on the inputs
int sortNum(int t, int l, int k) {
	int a, b, c, d, temp;
    // following lines of code are to extract the digits out of the integer.
    d = t % 10;
    temp = t / 10;
    c = temp % 10;
    temp = t / 100;
    b = temp % 10;
    temp = t / 1000;
    a = temp % 10;

    int descendingArray[l];

	if (l == 4){
		descendingArray[0] = a;
		descendingArray[1] = b;
		descendingArray[2] = c;
		descendingArray[3] = d;
	  }
	else {
		descendingArray[0] = b;
		descendingArray[1] = c;
		descendingArray[2] = d;
	}
 	stringstream ss;

 	// make array, filled with digits of the number

 	int i, j, flag = 1;    // set flag to 1 to start first pass
 	int temp2;             // holding variable
 	int numLength = l;

 	for(i = 1; (i <= numLength) && flag; i++)
 	     {
 	     	  flag = 0;
 	          for (j=0; j < (numLength -1); j++)
 	         {
 	        	  if (k == 2){
					   if (descendingArray[j+1] > descendingArray[j])      // ascending order simply changes to <
					  {
							temp2 = descendingArray[j];             // swap elements
							descendingArray[j] = descendingArray[j+1];
							descendingArray[j+1] = temp2;
							flag = 1;               // indicates that a swap occurred.
					   }
 	        	  }
 	        	 if (k == 1){
					   if (descendingArray[j+1] < descendingArray[j])      // Now it's ascending
					  {
							temp2 = descendingArray[j];             // swap elements
							descendingArray[j] = descendingArray[j+1];
							descendingArray[j+1] = temp2;
							flag = 1;               // indicates that a swap occurred.
					   }
				  }

 	          }
 	     }
 	for (unsigned q = 0; q < sizeof descendingArray / sizeof descendingArray [0]; ++q){
 	        ss << descendingArray [q];
 	}
 	int result;
 	ss >> result;
 	return result;
  }
