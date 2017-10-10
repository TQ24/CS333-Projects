/*Project1
Extension3 : Make the safe/hacked C program use a string from the command line.

Tracy Quan
Sep 18,2017
*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){

   char name[30];
   char age[30];
   char favoritesports[30];
   if (argc != 4)
   {
      printf("Type in your name, age, and favoritesports");
      return 1;
   }
   strcpy(name, argv[1]);
   strcpy(age,argv[2]);
   strcpy(favoritesports, argv[3]);
   printf("\nPersonal Profile:\nName: %s\nAge: %s\nFavorite Sports: %s\n", name,age,favoritesports);
   return 0;
}
