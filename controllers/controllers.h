#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../models/models.h"

Ingredient *createNewIngredient(char *ingredientName) {
  Ingredient *temp = (Ingredient*)malloc(sizeof(Ingredient));
  strcpy(temp->name,ingredientName);
  temp->next = temp->prev = NULL;
  return temp;
}

void pushTail(char* name) {
  Ingredient *temp = createNewIngredient(name);

  if(!headIn) { 
    headIn = tailIn = temp; 
  } else { 
    tailIn->next = temp; 
    temp->prev = tailIn; 
    tailIn = temp;  
  }
}

Ingredient* searchPantry(char* name) {
  Ingredient* curr = headIn;
  
  while(curr) {
    if(strcmp(curr->name, name) == 0) {
      return curr;
    }
    curr = curr->next;
  }
  
  return NULL;
}

void printIngredient() {
  Ingredient *curr = headIn;
  puts("Ingredient's List\n");
  if(!curr) {
    printf("No Ingredient\n");
    return;
  } else {
      while(curr) {
      printf("%s\n",curr->name);
      curr = curr->next;
      }
  }
  return;
}

void popHead() {
  if(!headIn) {
    return;
  } else if(headIn == tailIn) { 
    free(headIn);
    headIn = tailIn = NULL;
  } else { 
    Ingredient *temp = headIn->next;
    headIn->next = temp->prev = NULL; 
    free(headIn); 
    headIn = temp;
  }
}

void popTail() {
  if(headIn && headIn == tailIn) { 
    headIn = tailIn = NULL;
    free(headIn);
  } else { 
    Ingredient *newTail = tailIn->prev; 
    tailIn->prev = newTail->next = NULL; 
    free(tailIn); 
    tailIn = newTail; 
  }
}

int popMid(char *inName) {
  if(!headIn) {
    printf("Pantry Empty\n");
    getchar();
    return 0;
  } else if(strcmp(headIn->name,inName) == 0) {
    popHead();
  } else if(strcmp(tailIn->name,inName) == 0) {
    popTail(); 
  } else { 
    Ingredient* curr = headIn;
    while(curr && strcmp(curr->name,inName) != 0) {
      curr = curr->next;
    }

    if(curr) {
    curr->prev->next = curr->next; 
    curr->next->prev = curr->prev;
    

    curr->prev = curr->next = NULL; 
    free(curr); 
    curr = NULL;
    } else {
      printf("sorry we couldn't find what you wanted\n");
      getchar();
      return 0;
    } 
  }
  return 1;
}