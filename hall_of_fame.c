#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


static char * wnfgets(char * string, int maxLength, FILE * file)
{
	register int c;
	register char* cs;
	cs = string;

	while (--maxLength > 0 && (c = getc(file)) != EOF && (c != '\n'))
	{
		*cs++ = c;	
	}
	*cs = '\0';

	return (c == EOF && cs == string)? NULL : string;
}

// un petit commentaire ?
void afficherDonnee(FILE * file, donnee_t d) {
	fprintf(file,"%s : %s avec %d\n",d.nom,d.alias,d.score);
}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p){
	char saisie[1024];

	wnfgets(p->nom, 100, file);
	wnfgets(p->alias,40,file);

	wnfgets(saisie,1024,file);

	p->score = atoi(saisie);

}

int tableauFromFilename(const char * filename, donnee_t tab[TAILLE_MAX])
{
	FILE *  f = fopen(filename, "r");

	if (f != NULL)
	{
		char saisie[1024];		
		donnee_t d;
		int n = 0;

		while (n < TAILLE_MAX){
			if (wnfgets(d.nom,100,f) != NULL && wnfgets(d.alias,40,f) != NULL && wnfgets(saisie,1024,f) != NULL)
			{
				d.score = atoi(saisie);
				tab[n++] = d;				
			}
			else {
				break;
			}
		}
		return n;
	}
	
	return 0;

}
