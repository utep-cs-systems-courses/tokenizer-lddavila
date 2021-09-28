#include <stdio.h>
#include "tokenizer.h"
#include <string.h>
int count_words(char *str){
  int counter = 0;
  /*iterates str as long as  it doesn't point to a terminator character*/
  while(*str != '\0') {
    /*updates *str to point to the beginning of the word*/
    str = word_start(str);
    /*checks to make sure the string isn't full of just spaces*/
    if(*str == '\0')
      break;
    counter++;
    /*navigates *str point to end of current word*/
    str = word_end(str);
  }
  return counter;
}
