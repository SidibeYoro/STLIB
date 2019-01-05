#include <stdio.h>
#include <stdlib.h>
#include "automate.c"
#include <string.h>

/**
 * \file       main.c
 * \author     Yoro , Awa , Firdaws , Kamilia
 * \version    1.3
 * \date       05 Janvier 2019
 * \brief      Fichier de test des fonctions du programme.
 *
 * \details    Cette fichier permet de tester certains fonctions implémentés dans le fichier automate.c
 *                  .
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

    printf("\n");
    printf("LTS vide ou pas : ");
    int x = estVide(l);
    printf("%d \n",x);

    printf("LTS pleine ou pas : ");
    int y = estpleine(l);
    printf("%d \n",y);
	// On affiche a nouveau notre lts
    afficher_lts(l);

	char * file = "test.txt";
	open_lts(file);
	read_lts(file);
	write_lts(file);
    afficher_lts(l);

///	supprimer_etat(l, t.depart);
	return 0;
}
