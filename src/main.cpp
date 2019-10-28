//============================================================================
// Name        : main.cpp
// Author      : Djordje
// Version     : 1
// Description : My attempt at illustrating Kaprekar mathematical constant using c++.
// 				 My aim is to use good coding practices.

//============================================================================
#include <iostream>
#include "KaprekarsConstant.h"

// struct to return multiple values
// error for error handling
// length for range checking and selecting correct operation based on it.

using namespace std;

int main(void) {
	while(1){
		int number1;
		int errorTryAgain = 0;
		// While loop, until input is accepted. The loop is sensitive to errorTryAgain variable.
		// 0 is initial state, ask user for input,
		// 1 means an error occurred in any of the error checks, ask input number again.
		// 2 means no errors occurred and program will continue.
		while (errorTryAgain == 0 || errorTryAgain == 1){
			number1 = inputNumber();
			Check result1 = displayAndCheck(number1);
			int length = result1.length;
			if (result1.error){
				errorTryAgain = 1;
			}
			// unique digit test, for 3 digit numbers.
			else if ((uniqueDigitTest3Digits(length, number1)) == 1){
				errorTryAgain = 1;
			}
			// unique digit test, for 4 digit numbers.
			else if ((uniqueDigitTest4Digits(length, number1)) == 1){
				errorTryAgain = 1;
			}
			else {
				errorTryAgain = 2;
				operation(number1, length);
			}
		}
	}
	return 0;
}
