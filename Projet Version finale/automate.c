#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automate.h"
#define MAX_T 15 //max de trans
/**
 * \file       automate.c
 * \author     Yoro , Awa , Firdaws , Kamilia
 * \version    1.@
 * \date       05 Janvier 2019
 * \brief      Implémentation de l'ensemble de nos fonctions pour les LTS.
 *
 * \details    Cette fichier implémente les differentes fonctions pour la mise en place d'un lts
 *                  de la création à l'affichage en passant par l'ajout et la suppression des etats et transitions.
 */

void open_lts(char *filename){

            FILE* fichier = NULL;
            fichier = fopen(filename, "r+");


             char test[256] = "";

             // c
             char c ;

            if (fichier != NULL)
            {
                printf("L'automate lu est la suivante \n");
                while (fgets(test, 256,fichier) != NULL) {
                        printf("%s \n ",test);

                                }
                                        fclose(fichier);

            }

                else {
                    // On affiche un message d'erreur si on veut
                    printf("Impossible d'ouvrir le fichier test.txt");
                }
}


lts *read_lts(char *filename)
{
    char test[256];
    FILE *fptr;

    if ((fptr = fopen("test.txt", "r")) == NULL)
    {
        printf("erreur");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline
    fscanf(fptr,"%[^\n]", test);

    printf("donnees du fichier test:\n%s", test);
    fclose(fptr);

    return 0;
}



lts *write_lts(char *filename){
    char  test[256] ;
   FILE *fptr;

   fptr = fopen("test.txt", "a");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   printf("\n");
   printf("Entrer un mot:\n");
   scanf("%s",test);

   fprintf(fptr,"%s", test);


   return 0;
}


/**
* \deprecated 
void sauver_lts(lts * l, const char * save){
*/

}
lts *creer_lts(){
   lts *l;
   l =(lts*)malloc(sizeof(lts));
   l->alphabet=(char**)malloc(sizeof(char*)*(MAX_T+1));;
   l->etat=(int*)malloc(sizeof(int)*(MAX_T+1));
   l->etat_final=NULL;
   l->etat_initial=l->nb_trans=0;
   l->tete=l->queue=NULL;
   return l;
}
int estVide(lts * l){
    return (l->nb_trans==0);

}
int estpleine(lts *l){
    if(l->nb_trans==MAX_T) return 1;
    return 0;
}
void ajouter_etat(lts *l, int e){
	if(estVide(l))
    	l->etat[0]=e;
    else
        l->etat[l->nb_trans]=e;
}

void afficher_lts(lts * l){
	int i=0;
	transition * tmp=l->tete;
	printf("%d", tmp->depart);
	while(tmp!=NULL){
            printf("--");
             printf("%s",tmp->alphabet);
             printf("--");
             printf("%d",tmp->arrive);


    tmp=tmp->next;
	}
printf("fin");
}
/*
void supprimer_etat(lts *l, int e){
    int tmp;
    if(estVide(l)){
        printf("on peut rien supprimer");
    }
    else
    if(estpleine(l)){
        tmp=l->etat;
         printf("je donne le numero de l'etat à supprimer");
         scanf("%d",&e);
         lts *r=recherche_etat(l,e);
    }

}*/

//}
void ajouter_transition(lts *l, transition *t){
   if(estVide(l)){
   		ajouter_etat(l,t->depart);
       l->tete=t;
       l->queue=t;
		l->alphabet[l->nb_trans++]=t->alphabet;
   }else{
       transition * tmp=l->queue;
   		tmp->next=t;
   		l->queue=t;
       l->nb_trans++;
    l->alphabet[l->nb_trans-1]=t->alphabet;
   }

	ajouter_etat(l,t->arrive);

}

transition*  new_transition(lts *l, char *al){
	transition *t=malloc(sizeof(transition));
	t->alphabet=al;
	if(estVide(l)){
		t->depart=0;
		t->arrive=1;
	}else{
	    transition * tmp=l->queue;
		t->depart=tmp->arrive;
		t->arrive=t->depart+1;
	}
	return t;
}

void supprimer_transition(){
//if(estVide(t)){
   // printf"on peut rein supprimer"
}


