#include <stdio.h>
#include "tokenizer.h"
char *word_start(char *str){
  /*iterates *str until non space char is detected, indicating beggining of word*/
  while(non_space_char(*str)==0){
    ++str;
  }
  /*non_space_char returns a 2 only when a terminator character is detected*/
  if (non_space_char(*str)==2){
    char a = '\0';
    char *nullPtr = &a;
    return nullPtr;
  }
  return str;
}

char *word_end(char *str){
  /*iterates *str until spac-char is detected, indicating end of the current word*/
  while(space_char(*str) == 0)
    ++str;
  if(space_char(*str) == 2){
    char a = '\0';
    char *nullPtr = &a;
    return nullPtr;
  }
