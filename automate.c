/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "automate.h"
#include <string.h>

void lire_lts(FILE*f){
char *c, *d="";
fscanf(f,"%c",&c);
while(c){
    if(c==","); //creer une transition et ajouter l'alphabet; 

    else 
        d=strcat(d,c);
    
            fscanf(f,"%c",&c);

if(feof(f))break;
}
//rewind(f);
printf("%s",&d);
}

lts sauver_lts(){
    
}
lts creer_lts(){
   
}
void ajouter_etat(){
    
}
void supprimer_etat(){
    
}
void ajouter_transition(){
    
}
void supprimer_transition(){
    
}


