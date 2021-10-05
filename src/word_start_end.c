#include <stdio.h>
#include "tokenizer.h"
char *word_start(char *str){
  /*iterates *str until non space char is detected, indicating beggining of word*/
  while(non_space_char(*str)==0){
    str++;
  }
  return str;
}

char *word_end(char *str){
  /*iterates *str until spac-char is detected, indicating end of the current word*/
  while(space_char(*str) == 0){
    ++str;
  }
return str;
}
  
