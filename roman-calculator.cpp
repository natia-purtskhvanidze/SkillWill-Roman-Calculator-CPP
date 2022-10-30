//This is a project 1 for Skilwill Team 6
/*in this project we build a Roman calculator that takes roman symbols, converts them, does calculations
then converts the result back to Roman and returns the final result*/

#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

// this part converts roman numbers to integers
int romanToInteger(string &str) {
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

// Function to convert integer to Roman Numerals
int integerToRoman(int result)
{
  int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
  int i=12;   
  while(result>0)
  {
    int div = result/num[i];
    result = result%num[i];
    while(div--)
    {
      cout<<sym[i];
    }
    i--;
  }
}

// Driver Code
int main() {

  // Considering inputs given are valid
  // This part requires user inputsand converts it. Printing the converded results is commented (for testing purposes)
  string romNum1;
  cout << ("Enter Roman number 1: ");
  cin >> romNum1;
  /* cout << "Integer form of Roman Numeral is " << romanToInteger(romNum1)
       << endl; */
  string romNum2;
  cout << ("Enter Roman number 2: ");
  cin >> romNum2;
  /* cout << "Integer form of Roman Numeral is " << romanToInteger(romNum2)
       << endl; */

  // In this part user chooses the math operation
  char mathOperation;
  cout << ("Please, choose mathematical operator: + - * /: ");
  cin >> mathOperation;

  // The following part does the calculation process
  int result;
  if (mathOperation == '+') {
    result = romanToInteger(romNum1) + romanToInteger(romNum2);
  } else if (mathOperation == '-') {
    result = romanToInteger(romNum1) - romanToInteger(romNum2);
  } else if (mathOperation == '*') {
    result = romanToInteger(romNum1) * romanToInteger(romNum2);
  } else {
    result = romanToInteger(romNum1) / romanToInteger(romNum2);
  }

// The last part converts the calculation back to Roman and returns the result
  cout << "The result is: " << endl;
  return integerToRoman(result);

  return 0;
}
