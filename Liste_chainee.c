
#include "Liste_chainee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG 0

int NB_MALLOC = 0;
int NB_FREE = 0;

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->value = 0;
    element->next = NULL;
    liste->premier = element;

    return liste;
}


void print_allocations() {
    printf("Nb allocations: %d\n", NB_MALLOC);
    printf("Nb de-allocations: %d\n", NB_FREE);
}

void *malloc_wrapper(size_t __size) {
    void *rtr;
    rtr = malloc(__size);
    if (rtr != NULL)
        NB_MALLOC++;
    if (LOG) {
        if (rtr != NULL)
            printf("Allocation %p\n", rtr);
        else
            printf("Allocation impossible\n");
    }
    return rtr;
}

void free_wrapper(void *p) {
    if (p != NULL)
        NB_FREE++;
    if (LOG) {
        printf("Liberation %p\n", p);
    }
    free(p);
}

void free_list(element **e) {
    element *p;
    while (*e != NULL) {
        p = *e;
        *e = (*e)->next;
        free_wrapper(p);
    }
}

void print_list(element *l) {
    printf("{");
    if (l != NULL) {
        printf("%d", l->value);
        while (l->next) {
            l = l->next;
            printf(", %d", l->value);
        }
    }
    printf("}\n");
}

element *add_head(element *l, int v) {
    element *e = (element *) malloc_wrapper(sizeof(element));
    if (e == NULL) {
        return NULL;
    }
    e->value = v;
    e->next = l;
    return e;
}

void add_head2(element **l, int v) {
    element *e = (element *) malloc_wrapper(sizeof(element));
    if (l == NULL || e == NULL) {
        return;
    }
    e->value = v;
    e->next = (*l);
    (*l) = e;
}

void add_queue2(element **l, int v) {
    element *e = (element *) malloc_wrapper(sizeof(element));
    if (l == NULL || e == NULL) {
        return;
    }
    e->value = v;
    e->next = NULL;
    if (*l == NULL) {
        (*l = e);
        return;
    }
    element *courant = *l;
    while (courant->next != NULL) {
        courant = courant->next;
    }
    courant->next = e;
}

element *add_sorted(element *l, int v) {
    element *e = malloc_wrapper(sizeof(element));
    if (e == NULL)
        return NULL;

    e->value = v;
    e->next = NULL;

    // add in head
    if (l == NULL || v <= l->value) {
        e->next = l;
        return e;
    }

    // general case
    element *courant = l;
    while (courant->next != NULL && v > courant->next->value) {
        courant = courant->next;
    }
    e->next = courant->next;
    courant->next = e;
    return l;
}

void sort_insertion(element *l, element **ltriee) {
    while (l != NULL) {
        *ltriee = add_sorted(*ltriee, l->value);
        l = l->next;
    }
}

// Permet de supprimer le dernier element dans la liste chainee
void suppression_head(element *liste)
{
    element *e = (element *) malloc_wrapper(sizeof(element));

    if (e == NULL) {
            return ;
        }

    if(e !=NULL){

            liste->value = liste->next->value;
            liste->next = NULL;


    }

}


void suppression_queue(element *liste)
{
    element *e = (element *) malloc_wrapper(sizeof(element));

    if (e == NULL) {
            return ;
        }

    if(e !=NULL){

            element *courant = liste ;
            while (courant->next != NULL) {
               courant= courant->next;

            }

            courant->value =0;
            courant = NULL;







    }

}

// fONCTION POUR AFFICHER LA LISTE CHAINEE

