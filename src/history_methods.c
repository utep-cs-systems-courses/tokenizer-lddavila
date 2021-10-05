
#include<stdio.h>
#include<stdlib.h>
#include "history.h"
#include "tokenizer.h"
List* init_history(){
  //create a List object as defined in history.h
  List *localList = malloc(sizeof(List));
  //sets List object to point to nothing
  localList -> root = NULL;
  //returns the newly created list
  return localList;
}

void add_history(List *list, char *str){
  //creates a local copy of the struct and creates a new struct to store the string into
  struct s_Item *temporary = list ->root;
  struct s_Item *new = malloc(sizeof(struct s_Item));
  //if the given list is empty then we set the node's id = 1,making it the head
  if(temporary == NULL){
    //all of the new node's attributes are set
    list->root = new;
    new->id = 1;
    new->str = str;
    new->next = NULL;
  }
  //if the given list isn't empty 
  else{
    //navigate to the end of the existing list
    while(temporary->next != NULL){
      temporary = temporary->next;
    }
    //all of the new node's attributes are set
    temporary->next = new;
    new->id = temporary -> id + 1;
    new->str = str;
    new->next = NULL;
  }
}
char *get_history(List *list, int id){
  char *returnPtr = '\0';
  //creates local copy of list
  struct s_Item *localList = list->root;
  //condition covers edge case of being given invalid id
  if(id < 1){
    printf("Item IDs begin at 1.\n");
    return returnPtr; 
  }
  //condition covers edge case of having an empty list
  if(localList ==NULL){
    printf("There's no history to check\n");
    return returnPtr;
  }
  //while loop iterates until end of linked-list is reached or desired id is found
  while (localList->id != id){
    localList = localList->next;
    if(localList == NULL){
      printf("There's no item in history with that id.\n");
      return returnPtr;
    }
    
  }
  //returns the value stored in the current node's str attribute
  returnPtr = localList->str;
  //prints the string
  printf("ID: #%d | ", id);
  while(*returnPtr != '\0'){
    printf("%c",*returnPtr);
    returnPtr++;
  }
  printf("\n");
  return returnPtr;
}
void print_history(List *list){
  //create a local copy of the linked list
  struct s_Item *localList = list->root;
  //this conditonal covers the edge case of having an empty list
  if(localList == NULL){
    printf("There is no history. \n");
  }
  //if the list isn't empty then all the values are printed in the appropriate format
  else{
    while(localList != NULL){
      printf("ID: %d | ",localList->id);
      char *temporary = localList->str;
      while(*temporary != '\0'){
	printf("%c",*temporary);
	temporary++;
      }
      printf("\n");
      localList = localList->next;
    }
  }
}

void free_history(List *list){
  struct s_Item *tmp = list->root;
  while(tmp != NULL){
    free(tmp->str);
    tmp = tmp->next;
  }
  free(list);
}
