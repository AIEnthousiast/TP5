#ifndef hall_of_fame_h
#define hall_of_fame_h

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin
typedef struct donnee_t{
	int score;
	char nom[100];
	char alias[40];
}donnee_t;

#define TAILLE_MAX 50

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
// mettre ici les autres declarations
int tableauFromFilename(const char *, donnee_t[TAILLE_MAX]);
#endif
