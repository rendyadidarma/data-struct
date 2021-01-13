#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../controllers/controllers.h"



int main() {
  manualRecipe();
    int choice;
    bool inMenu = false;
    
    do {
      inMenu = true;
        system("clear");
    // printf("%d Recipe Found\n",countRecipe);
    printf("-- Home Page --\n");
    printf("1. Search Recipe\n");
    printf("2. Cook Book\n");
    printf("3. Kitchen\n");
    printf("4. Pantry\n");
        scanf("%d", &choice);
    switch(choice) {
        case 1 : {
          // char name[255];
          //   printf("Enter the name of recipe : ");
          //   scanf("%s", name);
          //   break;
        }
        case 2 : {
            

            break;
        }
        case 3 : {
          bool inKitchen = false;
          int recipeNum = -1;
          do {
            system("clear");
            inKitchen = true;
            puts("Kitchen Area");
            if(recipeNum == -1) 
            printf("Selected recipe : No Recipe Selected\n");
            else
            printf("Selected recipe : %s\n", recipeBook[recipeNum].name);
            printf("1. Select Recipe\n");
            printf("2. Ingredients List\n");
            printf("3. Start Cooking\n");
            printf("4. Exit Kitchen\n>>");
            int n;
            scanf("%d",&n); getchar();
            switch(n) {
              case 1 : {
                recipeNum = selectRecipe();
                break;
              }
              case 2 : {
                printIngredient();
                getchar();
                break;
              }
              case 3 : {
                if(recipeNum == -1) 
                  puts("No Recipe Selected");
                else
                inCooking(recipeNum);
                break;
              }
              case 4 : {
                inKitchen = false;
                break;
              }
            }
          }while(inKitchen);
            break;
        }

        case 4 : {
          bool inPantry = true;
          while(inPantry) {
          system("clear");
            printIngredient();
            int n;
            printf("1. Search Pantry\n");
            printf("2. Add Ingredient\n");
            printf("3. Remove Ingredient\n");
            printf("4. Exit from Pantry\n >>");

            scanf("%d",&n); getchar();
            switch(n) {
              case 1: {
              char search[255]; 
                bool flag = false;
                do {
                  puts("Press 0 to abort");
                  scanf(" %[^\n]", search); getchar();
                  if(strcmp(search,"0") == 0) 
                      break;
                  Ingredient* temp = searchPantry(search);
                  if(!temp) {
                    printf("Not find any ingredient's with that name\n");
                    getchar();
                  } else {
                    system("clear");
                    printf("%s found", temp->name);
                    flag = true;
                    getchar();
                  }
                } while(!flag || strcmp(search,"0") != 0);
                break;
              }
              case 2: {
                // Add Ingredient
                char addIngredient[255];
                printf("Enter your new ingredient name : ");
                scanf(" %[^\n]", addIngredient);
                getchar();
                pushTail(addIngredient);

                puts("Ingredient inputted..");
                getchar();
                break;
              }
              case 3: {
                // Remove Ingredient
                char removeIngredient[255];
                printf("Enter the ingredient name : ");
                scanf(" %[^\n]", removeIngredient);
                getchar();
                int result = popMid(removeIngredient);
                if(result){ 
                  puts("Ingredient removed..");
                  getchar();
                } 
                break;
              }
              case 4: {
                inPantry = false;
              }
            }
          }
            break;
        }
    }

  }while (inMenu); 
}