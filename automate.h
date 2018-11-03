/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   automate.h
 * Author: Auchan
 *
 * Created on 27 octobre 2018, 15:23
 */

#ifndef AUTOMATE_H
#define AUTOMATE_H
typedef struct transition{
    int depart;
    int arrive;
    char *alphabet;
}transition;
typedef struct lts{
    char **alphabet;
    int* etat;
    transition *trans;
    int etat_initial;
    int *etat_final;
}lts;
void lire_lts(FILE*F);
lts sauver_lts();
lts  creer_lts();
void ajouter_etat();
void supprimer_etat();
void ajouter_transition();
void supprimer_transition();



#endif /* AUTOMATE_H */

