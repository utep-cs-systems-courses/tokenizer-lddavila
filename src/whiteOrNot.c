#include <stdio.h>

int space_char(char c){
  switch(c){
  case 32:
    return 1; 
  case 9:
    return 1; 
  case 10:
    return 1;
  case '\0':
    return 2; 
  default:
    return 0;
}
}

int non_space_char(char c){
  switch(c){
  case 32:
    return 0;
  case 9:
    return 0;
  case 10:
    return 0;
  case '\0':
    return 2;
  default:
    return 1; 
  }
}
