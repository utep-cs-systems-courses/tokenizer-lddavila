#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
char *copy_str(char *inStr, short len){
  char *copiedString;
  char *internalPtr;
  /*malloc allocates <len> number of places in memory to be used*/
  internalPtr = (char *)malloc((int)len+1);
  /*both pointers point to the same preallocated memory*/
  copiedString= internalPtr;
  int counter = (int)len;
  //condition makes sure we only take the number defined by len
  while(counter >0){
    //The value that *inStr points to is stored in the memory *ptrToBeReturned points to
    *internalPtr = *inStr;
    //increments where values are being stored, and what is being stored
    internalPtr++;
    inStr++;
    counter -=1;
  }
  //Adds the zero terminator
  *copiedString =(char) '\0';
  //return unmodifed pointer since it stayed in the same place
  return copiedString;
}
