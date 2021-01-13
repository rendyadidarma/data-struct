#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
    getchar();
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

int getIngredientTotal(int recipeNum) {
  int i = 1, sum = 0;
  while(recipeBook[recipeNum].ingredient[i] != '\0') {
    sum++;
  }
  return sum;
}

void inCooking(int recipeNum) {
  printf("Recipe Name : %s\n", recipeBook[recipeNum].name);
  puts("Recipe Ingredients :");
  int count = 1;
  for(int i = 1; i < 5 ; i++) {
    printf("%d . %s\n",count++, recipeBook[recipeNum].ingredient[i]);
  }
  puts("---------------------------");
  count = 1;
  puts("Instruction : ");
  for(int i = 0; i < 5; i++) {
    printf("Step %d : %s\n",count++, recipeBook[recipeNum].instruction[i]);
  }
  puts("Start Cooking ? (1/0) (1 -> start | abort <- 0)");
  int n;
  scanf("%d",&n); getchar();
  switch(n) {
    case 1 : {
      system("clear");
      bool cooking = false;
        do {
          cooking = true;
          for(int i = 0 ; i < 5; i++) {
            printf("Step %d : %s\n", i+1, recipeBook[recipeNum].instruction[i+1]);

            int until = 20 * (i+1);
            for(int i = 0; i < 101; i++) {
              if(i == 100)
                printf("|");
              else if( i < until)
                printf("-");
              else 
                printf(" ");
            }
            printf("%d%\n",until);
              getchar();
          }
          printf("restart? (1/0)\n >>");
          int n;
          scanf("%d",&n); getchar();
          switch (n)
          {    
          case 0:
            cooking = false;
            break;
          }

        } while(cooking);
      break;
    }
    default : {
      return;
    }
  }
}

void manualRecipe() {

    strcpy(recipeBook[1].name,"fried chicken");
    strcpy(recipeBook[1].description,"delicious(this is description)");
    strcpy(recipeBook[1].instruction[1],"clean the chicken");
    strcpy(recipeBook[1].instruction[2],"heat the oil");
    strcpy(recipeBook[1].instruction[3],"sprinkle with salt");
    strcpy(recipeBook[1].instruction[4],"put the chicken in the oil");
    strcpy(recipeBook[1].instruction[5],"drain and ready to serve");
    strcpy(recipeBook[1].ingredient[1],"Chicken");
    strcpy(recipeBook[1].ingredient[2],"Oil");
    strcpy(recipeBook[1].ingredient[3],"Salt");
    strcpy(recipeBook[1].ingredient[4],"Sauce (optional)");
    
    
      
}

int selectRecipe() {
  system("clear");
  int num = 1;
  // tinggal tambah agar recipe fleksibel
    printf("%d. %s\n",num,recipeBook[1].name);
  
  int x;
  printf("Choose : ");
  scanf("%d",&x); getchar();

  return x;
}
