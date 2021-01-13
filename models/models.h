struct Recipe
{
     char name[255];
     char description[255];
     char instruction[25][255];
     char ingredient[255][255];
}recipeBook[255];

struct Ingredient
{
  char name[255];
  Ingredient *next,*prev;
}*headIn, *tailIn;

struct Favorite
{
  char name[255];
  Favorite *next,*prev;
}*headFav, *tailFav;