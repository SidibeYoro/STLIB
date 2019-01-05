#include <stdio.h>
#include <stdlib.h>
#include "automate.c"
#include <string.h>
/*
 *
 */
int main(){
	lts  *l=creer_lts();
	ajouter_transition(l,new_transition(l,"manger"));
	ajouter_transition(l,new_transition(l,"travailler"));
	ajouter_transition(l,new_transition(l,"voyager"));
	ajouter_transition(l,new_transition(l,"manger"));
	ajouter_transition(l,new_transition(l,"travailler"));
	ajouter_transition(l,new_transition(l,"faire la  fete"));
	ajouter_transition(l,new_transition(l,"voyager"));
    ajouter_transition(l,new_transition(l,"manger"));
    ajouter_transition(l,new_transition(l,"dormir"));


	afficher_lts(l);
	char * file = "test.txt";
	open_lts(file);
	read_lts(file);
	write_lts(file);
///	supprimer_etat(l, t.depart);
	return 0;
}


