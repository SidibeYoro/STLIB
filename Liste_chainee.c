
#include "Liste_chainee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

// fONCTION POUR AJOUTER EN DEBUT DE LISTE

void insertion(Liste *liste, int nvNombre)
{
    /* CrŽation du nouvel ŽlŽment */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'ŽlŽment au dŽbut de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


// oN SUPPRIME LE PREMIERE ELEMENT DE LA LISTE


void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

// fONCTION POUR AFFICHER LA LISTE CHAINEE



void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d ->", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
