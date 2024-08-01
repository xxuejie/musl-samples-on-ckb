#include <stdio.h>

#include <iostream>
using namespace std;

struct S {
  S() { std::cout << "Initializing S!\n"; }
};

static S s;

int main(int argc, char* argv[]) {
  printf("cout pointer: %p\n", &cout);
  cout << "Hello!" << endl;

  if (argc < 1) {
    cout << "No arguments!" << endl;
    return 0;
  }

  char c = argv[0][0];
  bool isLowercaseVowel, isUppercaseVowel;

  // evaluates to 1 (true) if c is a lowercase vowel
  isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

  // evaluates to 1 (true) if c is an uppercase vowel
  isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

  // show error message if c is not an alphabet
  if (!isalpha(c))
    printf("Error! Non-alphabetic character.");
  else if (isLowercaseVowel || isUppercaseVowel)
    cout << c << " is a vowel.";
  else
    cout << c << " is a consonant.";
  cout << endl;

  return 0;
}
