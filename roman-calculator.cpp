//This is a project 1 for Skilwill Team 6
//in this project we build a calculator that takes roman symbols, converts and does calculations
#include <iostream>
#include <map>
using namespace std;

// this part converts roman numbers to integers

int romanToDecimal(string &str) {
  map<char, int> m;
  m.insert({'I', 1});
  m.insert({'V', 5});
  m.insert({'X', 10});
  m.insert({'L', 50});
  m.insert({'C', 100});
  m.insert({'D', 500});
  m.insert({'M', 1000});
  int sum = 0;
  for (int i = 0; i < str.length(); i++) {
    /*If present value is less than next value,
      subtract present from next value and add the
      resultant to the sum variable.*/
    if (m[str[i]] < m[str[i + 1]]) {
      sum += m[str[i + 1]] - m[str[i]];
      i++;
      continue;
    }
    sum += m[str[i]];
  }
  return sum;
}

// Driver Code
int main() {
  // Considering inputs given are valid
  // This part requires user inputs, converts it and prints the converted result
  string romNum1;
  cout << ("Enter Roman number 1: ");
  cin >> romNum1;
  cout << "Integer form of Roman Numeral is " << romanToDecimal(romNum1)
       << endl;
  string romNum2;
  cout << ("Enter Roman number 2: ");
  cin >> romNum2;
  cout << "Integer form of Roman Numeral is " << romanToDecimal(romNum2)
       << endl;

  // In this part user chooses the math operation
  char mathOperation;
  cout << ("Please, choose mathematical operator: + - * /: ");
  cin >> mathOperation;

  // The following part starts the calculation process
  int result;
  if (mathOperation == '+') {
    result = romanToDecimal(romNum1) + romanToDecimal(romNum2);
  } else if (mathOperation == '-') {
    result = romanToDecimal(romNum1) - romanToDecimal(romNum2);
  } else if (mathOperation == '*') {
    result = romanToDecimal(romNum1) * romanToDecimal(romNum2);
  } else {
    result = romanToDecimal(romNum1) / romanToDecimal(romNum2);
  }

  cout << "The result is ";
  cout << result;

  return 0;
}
