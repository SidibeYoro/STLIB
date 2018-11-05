/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_T 15 //max de trans

typedef struct transition{
    int depart;
    int arrive;
    char *alphabet;
}transition;

typedef struct lts{
    char **alphabet;//tab ex manger, boire....
    int* etat;   //tab etat ex,:  1, 2, 3...
	int etat_initial; //1
	transition *trans; ///tabde trans ex/t1, t2,...
    int *etat_final; //tab : ex 2, 4..
    int nb_trans;   ///nb_etat =nb_trans plus 1;
}lts;



lts sauver_lts(){
    
}
lts creer_lts(){
   lts lts;//=calloc(1,sizeof(lts));
   lts.alphabet=(char**)malloc(sizeof(char*)*(MAX_T+1));;
   lts.etat=(int*)malloc(sizeof(int)*(MAX_T+1));
   lts.etat_final=NULL;
   lts.etat_initial=lts.nb_trans=0;
   lts.trans=(transition*)malloc(sizeof(transition)*MAX_T);
   return lts;
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
	for(i;i<l.nb_trans;i++){
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



int main(){
	lts  l=creer_lts();
	ajouter_transition(&l,new_transition(l,"manger"));
	ajouter_transition(&l,new_transition(l,"boire"));
	ajouter_transition(&l,new_transition(l,"dormir"));
	afficher_lts(l);
	return 0;
}




