//============================================================================
// Name        : CaspersConstant.cpp
// Author      : Djordje
// Version     : 1
// Description : My attempt at illustrating Caspers mathematical constant using c++.
// 				 My aim is to use good coding practices.

//============================================================================
#include <iostream>
using namespace std;

int uniqueDigitTest3Digits(int l, int a);
int uniqueDigitTest4Digits(int l, int p);
void operation3(int a);
void operation4(int a);
int sortNumASC(int n);
int inputNumber(void);

// struct to return multiple values
// error for error handiling
// length for range checking and selecting correct operation based on it.
struct Foo {
     bool error;
     int length;
} result;
Foo displayAndCheck(int b);

int main() {

	int number1;
	enterNumber:
	number1 = inputNumber();
	result = displayAndCheck(number1);
	if (result.error){
		goto enterNumber;
	}
	int length = result.length;
	// unique digit test, for 3 digit numbers.
	if ((uniqueDigitTest3Digits(length, number1)) == 1){
		goto enterNumber;
	}
	// unique digit test, for 4 digit numbers.
	if ((uniqueDigitTest4Digits(length, number1)) == 1){
			goto enterNumber;
		}

	if(length == 3) {
		operation3(number1);
	}
	else if(length == 4) {
		operation4(number1);
	}
	return 0;
}

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

Foo displayAndCheck(int b){
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
	 Foo result = { error, length };
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

void operation3(int a){
	cout << "3 digit function works" << endl;
	// array size 20, array[0] = a;
	 int casperNumbers [20] = {a};
	 for (int i = 0; i<1;i++ ){ // change upper range in the for loop to 10
			  int n = casperNumbers[i];
			  cout << "Unsorted: " << n << endl;
			  n = sortNumASC(n);
			  cout << "Sorted:   " << n << endl;

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
	 int casperNumbers [20] = {a};
	 for (int i = 0; i<1;i++ ){    // change upper range in the for loop to 10
			  int n = casperNumbers[i];
			  cout << "Unsorted: " << n << endl;
			  n = sortNumASC(n);
			  cout << "Sorted:   " << n << endl;
	 }
}

// Bubblesort Ascending
 int sortNumASC(int n) {
  while (true) {
    int a = n % 10, p = 9;
    bool s = false;
    for (int r = n / 10; r; r/= 10) {
      int b = r % 10;
      if (a < b) {
        n -= p * (b - a);
        s = true;
      } else a = b;
      p *= 10;
    }
    if (!s) return n;
  }
}








