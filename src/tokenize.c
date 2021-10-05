#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
char **tokenize(char* str){
  //Allocate space in memory for a pointer that points to pointers
  char **internalPointer = (char**) malloc((count_words(str)+1)*sizeof(char *));
  char **ptrToBeReturned = internalPointer;
  //The while loop iterates until it reaches the end of the string
  while (*str != '\0'){
    //counter keeps track of how many letters are after the start of the word
    int counter = 0;
    //iterates str to point to the beginning of the next word
    str = word_start(str);
    //iterates str to point to the space after the end of the current word
    while(space_char(*str) !=1){
      if(*str == '\0')
	break;
      str++;
      counter++;
    }
    
    char *addedToken = copy_str(str-counter,counter);
    
    //adds the token to the internal double pointer
    *internalPointer= addedToken;
    internalPointer++;
    //iterates str to get to the begining of the next word since it currently points to a space
    str = word_start(str);
  }
  //creates z terminator pointer and adds it to the tokens
  char a = '\0';
  char *zeroPointer = &a;
  *internalPointer = zeroPointer;
  return ptrToBeReturned;
}


void print_tokens(char **tokens){
  while(**tokens !='\0'){
    //in case the pointer points to an empty pointer
    if(**tokens == '\0')
      break;
    char *temporary = *tokens;
    while (*temporary != '\0'){
      if(*temporary == '\0')
	break;
      printf("%c", *temporary);
      temporary++;
    }
    printf("\n");
    tokens++;
  }
  printf("\n");
}

char *get_token(char **tokens, int id){
  //initialize temporary pointer to use to cycle through given 
  char *temporary = *tokens;
  int counter = 0; 
  while (counter < id){
    //this conditional takes care of the edge case of **tokens being empty
    if(*temporary == '\0'){
      printf("There's no item in history with that id.\n");
      break;
    }
    //temporary and counter are incremented to make sure that the wrong value isn't returned
    temporary++;
    counter++; 
  }
  char *returnPtr = temporary;
  //the while loop actually prints the word
  while(*returnPtr != '\0'){
    printf("%c",*returnPtr);
    returnPtr++;
  }
  printf("\n");
  return returnPtr;
}

void free_tokens(char **tokens){
  while(**tokens != '\0'){
    free(*tokens);
    tokens++;
  }
  free(tokens);
}
