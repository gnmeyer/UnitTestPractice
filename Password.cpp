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

  if(phrase[0]=='\0') {
    return false;
  }

  if(std::isupper(phrase[0])) {
    while( index < phrase.length()) {
      if(std::islower(phrase[index])) {
        index++;
      } else if(phrase[index] == '_')  {
        index++;
        if(std::isupper(phrase[index])) {
          index++;
        } else {
          return false;
        }
      } else if(phrase[index] == '\n' || phrase[index] == '\0') {
        return false;
      } else {
        return false;
      }
        
    }
  } else {
    return false;
  }
  
  return true;
  
}

// bool Password::has_mixed_case(string pass){
//   bool lower = false;
//   bool upper = false;
//   for(int i = 0; i < pass.size(); i++){
//     if( pass[i] >= 'A' && pass[i] <= 'Z' ){
//       upper = true;
//     }
//     else if( pass[i] < 'z'){
//       lower = true;
//     }
//   }
//   return upper && lower;
// }

bool Password::has_mixed_case(string phrase){
  bool mixed = false;
  bool hasLowerCase = false;
  bool hasUpperCase = false;
  int currASCII = 0;
  for(int i = 0; i < phrase.length()-1; i++)
  {
    currASCII = int(phrase[i]); //typecast the character at this point of the string into an int to get the ASCII code.

    if(currASCII >= 65 && currASCII <=90) //ASCII val is from 65-90 [an upper case letter]
    {
      hasUpperCase = true;
    }
    if(currASCII >= 97 && currASCII <= 122) //ASCII val is from 97-122 [a lower case letter]
    {
      hasLowerCase = true;
    }
  }
  if(hasLowerCase && hasUpperCase)
  {
    mixed = true;
  }
  return mixed;
}