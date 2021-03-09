/*
Owen Brunty
2/28/21
Palindrome
 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[80];
  char flippedinput[80];
  char converted[80];
  cout << "Please enter a setnence or word and I will tell you if it's a palindrome." << endl;
  cin.get(input, 80);
  cin.get();

  //remove all spaces and punctuation from input and put it into converted
  int count = 0;
  for (int i = 0; i < 80; i++) {
    if ((input[i] != ' ') && (ispunct(input[i]) == false)){
      converted[count++] = input[i];
    }
  }

  //convert all letters to lowercase in converted
  for (int i = 0; i < 80; i++) {
    converted [i] = (tolower(converted[i]));
  }
  
  //flip converted and put it into flippedinput
  for (int i = 0; i < 80; i++) {
    flippedinput[strlen(converted)-i-1] = converted[i];
  }

  //cout << strlen(converted) << endl;
  //cout << strlen(flippedinput) << endl;
  
  //compare flippedinput and converted to check if palindrome
  if (strcmp(converted, flippedinput) == 0) {
    cout << "Palindrome" <<endl;
  }
  else {
    cout << "Not a palindrome" << endl;
  }
  
  //cout << converted << endl;
  //cout << flippedinput << endl;
  
  return 0;
}
