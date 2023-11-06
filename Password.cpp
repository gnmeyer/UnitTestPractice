#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

int Password::psize(string phrase) {
  return phrase.length();
}

bool Password::has_mixed_case(string phrase) {
  int index=1;

  if(std::isupper(phrase[0])) {
    while( index < phrase.length()) {
      if(std::islower(phrase[index])) {
        index++;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
  
  return true;
  
}