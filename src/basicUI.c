#include <stdio.h>

#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
void main(){
  /*Creates the history list for items to be stored in */
  List *history = init_history();
  while(1){
    printf("Please enter input|'?INTEGER' gets specific history|'>' prints history|'&' frees\n");
    /*dynamically allocates memory */
    char *ptr = (char*) malloc(100*sizeof(char*));
    char *ptrToBeTokenized = ptr;
    char a;
    a = getchar();
    switch(a){
     //prints specific history
    case '?':
      a = getchar();
      get_history(history,a-'0');
      /*This extra getchar() is necessary to avoid adding extra spaces to history*/
      a = getchar();
      //This continue restarts the while loop
      continue;
    //prints whole history
    case '>':
      a = getchar();
      print_history(history);
      continue;
    //frees history
    case '&':
      a = getchar();
      free_history(history);
      history = init_history();
      break;
    //if the user isn't using any of the functions then whatever they type has to be stored in history 
    default:
      while( a != 10){
	/*copies the char stored in 'a' into the space that *ptr refereces */
	*ptr = a;
	*ptr++;
	a = getchar();
      }
      ptr++;
      /*manually enters the terminator character to the *ptr so we can stop.*/
      ptr = '\0';
      /*adds the created *ptr to history*/
       char **tokenizedPtr = tokenize(ptrToBeTokenized);
    
       while(**tokenizedPtr != '\0'){
	 add_history(history, *tokenizedPtr);
	 tokenizedPtr++;
        }
    }
  }
}
