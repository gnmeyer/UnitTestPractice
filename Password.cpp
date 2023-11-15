#include "Password.h"
#include <string>

#include <string>
#include <vector>

using std::string;
using std::vector;

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

bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
}

Password::Password() {
  pass_history.push_back("ChicoCA-95929");
}


/*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string s) {
    int flag = 1;

    if(s.length() > 7 && count_leading_characters(s) < 4 && has_mixed_case(s) && authenticate(s)) {

      while(int i = 0 < pass_history.size()) {
        if(pass_history[i] == s) {
          flag = 1;
          break;
        }
      }

      flag = 0;
    }

    if(flag == 0) {
      pass_history.push_back(s);
    }

  }


    /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string s){
    if(pass_history.size() == 0) {
      return false;
    }

    if(s == pass_history[pass_history.size()-1]) {
      return false;
    } 

    return true;
  }

