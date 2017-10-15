#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "hall_of_fame.h"


BEGIN_TEST_GROUP(vecteur)

TEST(fgets) {
   char exemple [] = "scanf, c'est pas bien\n";
   LOG(exemple);
   char chaine1[25];
   char chaine2[10];

   FILE * file = fmemopen(exemple, sizeof(exemple)+1, "r");
   // REQUIRE ( NULL != file);

   fgets(chaine1, 25, file);
   LOG(chaine1);
   fclose(file);
   REQUIRE( strlen(exemple) == strlen(chaine1) );

   file = fmemopen(exemple, sizeof(exemple)+1, "r");
   // REQUIRE ( NULL != file);

   fgets(chaine2, 10, file);
   LOG(chaine2);
   
   REQUIRE( strlen(exemple) > strlen(chaine2) );

   fgets(chaine2, 10, file);
   LOG(chaine2);
   fclose(file);
}


TEST(Sizeof) {
	int taille1 = sizeof(struct donnee);
   int taille2 = sizeof(int)+100*sizeof(char); // :-)

	CHECK (taille1 == taille2);
}

// pas de test mais un exemple simple de manipulation
TEST(AffichageA) {
   struct donnee essai;

   strcpy(essai.nom, "2048");
   strcpy(essai.alias, "loic");
   essai.score = 16000;

   printf("%s ", essai.nom);
   printf("%s ", essai.alias);
   printf("%d ", essai.score);

}

TEST(AffichageB) {
   struct donnee essai;
   strcpy(essai.nom, "pokemon GO");
   strcpy(essai.alias, "loic");
   essai.score = 498;

   afficherDonnee(stdout, essai); 

   // creation du flux de texte => buffer
   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");
   REQUIRE ( NULL != file);

   afficherDonnee(file, essai);
   fclose(file);

   CHECK( 0==strcmp(buffer, "pokemon GO : loic avec 498\n") );
}

TEST(AffichageC) {
   donnee_t essai;
   strcpy(essai.nom, "overwatch");
   strcpy(essai.alias, "loic");
   essai.score = 2300;

   afficherDonnee(stdout, essai); 

   // creation du flux de texte => buffer
   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");
   REQUIRE ( NULL != file);

   afficherDonnee(file, essai);
   fclose(file);

   CHECK( 0==strcmp(buffer, "overwatch : loic avec 2300\n") );
}

TEST(Saisie) {
   struct donnee essai;
   char buffer[1024];
   strcpy(buffer, "rien\ndutout\n10");
   FILE * file = fmemopen(buffer, 1024, "r");
   // REQUIRE ( NULL != file);

   saisirDonnee(file, &essai);
   fclose(file);

   afficherDonnee(stdout, essai);

   // verification de ce qui est envoye sur le flux
   // chaque composante est affichee avec trois chiffre apres la virgule
   // %.3f
   //CHECK( 0==strcmp(buffer, "[ 1.000 2.000 3.000 ]") );

   
} 


END_TEST_GROUP(vecteur)


int main(void) {
	RUN_TEST_GROUP(vecteur); 
 	return 0;
}
