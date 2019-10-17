//============================================================================
// Name        : CaspersConstant.cpp
// Author      : Djordje
// Version     : 1
// Description : My attempt at illustrating Caspers mathematical constant using c++.
// 				 My aim is to use good coding practices.

//============================================================================
#include <iostream>
using namespace std;

void operation3(int a);
void operation4(int a);
long sortNumASC(long n);
long number1;
signed long long int testNumber;

int main() {
	enterNumber:
	cout << "Enter 3 or 4 digit number, with at least 2 different values (including 0):" << endl;
	 cin >> testNumber;
	 cout << "Your number is: " << testNumber << endl;
	cout << endl;
	// length of number, by the number of digits
	int length = std::to_string(testNumber).length();

	// range error handling
	try {
		if ( length > 4 || length < 3 ){
			throw 99;
		}
		else{
			number1 = testNumber;
		}
	} catch( int length) {
		cout << "Error, number is out of range, please enter a 3 or 4 digit number only ! error number: " << length << endl;
		cout << "Try again." <<  endl;
		cout << endl;
		goto enterNumber;
	}
	// TO DO
	// CHECK IF IT HAS AT LEAST 2 UNIQUE VALUES
	// FIX LOOPING WHEN NUMBER OF DIGITS EXCEEDS INT SIZE , IMPLEMENT ERROR

	if(length == 3) {

		operation3(number1);

	}

	else if(length == 4) {

		operation4(number1);

	}

	cout << "abc" << endl;
	cout << "def" << endl;

	return 0;
}


void operation3(int a){

	cout << "3 digit function works" << endl;
	// array size 20, array[0] = a;
	long casperNumbers [20] = {a};
	 for (int i = 0; i<20;i++ ){
		 long n = long(casperNumbers[i]);
		 std::cout << "Unsorted: " << n << std::endl;
		 n = sortNumASC(n);
		 std::cout << "Sorted:   " << n << std::endl;

	 }
	// sort array[i] from highest to lowest = tempL
	// sort array[i] from lowest to highest tempH
	// deduction : tempH - tempL = array[i+1]
	// cout temph - templ = array[i+1]
	// i++;
	// }
	//

}

void operation4(int a){

	cout << "4 digit function works" << endl;
	// array size 20, array[0] = a;
	// for (int i = 0; i<20;i++ ){
	// sort array[i] from highest to lowest = tempL
	// sort array[i] from lowest to highest tempH
	// deduction : tempH - tempL = array[i+1]
	// cout temph - templ = array[i+1]
	// i++;
	// }
	//
}

// Bubblesort Ascending
long sortNumASC(long n) {
  while (true) {
    long a = n % 10, p = 9;
    bool s = false;
    for (long r = n / 10; r; r/= 10) {
      long b = r % 10;
      if (a < b) {
        n -= p * (b - a);
        s = true;
      } else a = b;
      p *= 10;
    }
    if (!s) return n;
  }
}








