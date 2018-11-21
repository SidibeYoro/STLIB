
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automate.h"
#include "Liste_chainee.c"


#define MAX_T 15 //max de trans


// tout d'abord on met en place nos fonctions pour faire marcher les liste chainees


/*lts sauver_lts(){

}  */
lts creer_lts(){
   lts lts;//=calloc(1,sizeof(lts));
   lts.alphabet=(char**)malloc(sizeof(char*)*(MAX_T+1));;
   lts.etat=(int*)malloc(sizeof(int)*(MAX_T+1));
   lts.etat_final=NULL;
   lts.etat_initial=lts.nb_trans=0;
   lts.trans=(transition*)malloc(sizeof(transition)*MAX_T);
   return lts;
}

void lire_lts(char *filename){

    FILE* fichier = NULL;
fichier = fopen(filename, "r+");


 char texte[256] = "";

 // c= c'est la ligne
 char c ;

    if (fichier != NULL)
    {
    printf("L'automate lu est la suivante \n");


  while (fgets(texte, 256
               ,fichier) != NULL) {
        // on admet que le sparateur soit : |
              //  if (t != ',' ) {

                        printf("%s \n ",texte);

                }
                        fclose(fichier);

    }

    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }




}

void ajouter_etat(lts *l, int e){
	if(!l->nb_trans)
    	l->etat[0]=e;
    	else
    l->etat[l->nb_trans]=e;
}

void afficher_lts(lts l){
	int i=0;
	printf("(%d)",l.trans[i].depart);
	for(i=0;i<l.nb_trans;i++){
		printf("----");
		printf("%s",l.trans[i].alphabet);
		printf("----(%d)",l.trans[i].arrive);
	}

}
void supprimer_etat(){

}
void ajouter_transition(lts *l, transition t){
   if((l->nb_trans+1)<=MAX_T && !l->nb_trans){
   		ajouter_etat(l,t.depart);
		l->trans[l->nb_trans++]=t;
		l->alphabet[l->nb_trans-1]=t.alphabet;
   }else{
   		l->trans[l->nb_trans++]=t;
		l->alphabet[l->nb_trans-1]=t.alphabet;
   }
	ajouter_etat(l,t.arrive);


}

transition  new_transition(lts l, char *al){
	transition t;
	t.alphabet=al;
	if(!l.nb_trans){
		t.depart=0;
		t.arrive=1;
	}else{
		t.depart=l.trans[l.nb_trans-1].arrive;
		t.arrive=l.trans[l.nb_trans-1].arrive+1;
	}
	return t;
}

void supprimer_transition(){

}


int main() {

	lts  l=creer_lts();
	ajouter_transition(&l,new_transition(l,"manger"));
	ajouter_transition(&l,new_transition(l,"boire"));
	ajouter_transition(&l,new_transition(l,"dormir"));
	afficher_lts(l);
	printf("\n");
char * file = "file.txt";

	lire_lts(file);


// tet ListeChainee

   element *numbers = NULL;

    //
    numbers = add_head(numbers, 2);
    numbers = add_head(numbers, 5);
    numbers = add_head(numbers, 8);
    //


    //sort_insertion(numbers, &numbers_sorted);
    //
    print_list(numbers);
   //suppression_head(numbers);
   suppression_queue(numbers);


    print_list(numbers);

    free_list(&numbers);




	return 0;
}



