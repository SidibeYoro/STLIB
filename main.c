
#include <stdio.h>
#include <stdlib.h>
#include "automate.h"
#include <string.h>
/*
 *
 */
int main() {

	lts  l=creer_lts();
	ajouter_transition(&l,new_transition(l,"manger"));
	ajouter_transition(&l,new_transition(l,"boire"));
	ajouter_transition(&l,new_transition(l,"dormir"));
	afficher_lts(l);
	printf("\n");
char * file = "file2.txt";

	//lire_lts(file);
	return 0;
}

