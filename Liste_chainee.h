#define LISTE_CHAINEE_H_INCLUDED



// On crer une structure qui va nous permettre de faire nos liste chainee
typedef struct s_element {
    int value;
    struct s_element *next;
} element;


// O creer une structure liste qui va nous permettre de controler l'ensemble de nos LC
typedef struct Liste Liste;
struct Liste
{
    element *premier;
};




/**
 * \brief Affiche le nombre d'allocations et de désallocation de mémoire
 */
void print_allocations();

/**
 * \brief Wrapper pour allocation mémoire.
 *
 * @param __size taille de l'allocation
 * @return adresse de l'espace mémoire alloué
 */
void *malloc_wrapper(size_t __size);

/**
 * \brief Wrapper pour désallocation mémoire.
 *
 * @param p adresse de l'espace mémoire à désallouer
 */
void free_wrapper(void *p);

/**
 * \brief Désalloue l'ensemble de la mémoire utilisé pour une LLC
 *
 * @param pointeur sur l'adresse de la tête de liste
 */
void free_list(element **e);

/**
 * \brief Affiche une LLC
 *
 * @param l pointeur sur la tête de liste
 */
void print_list(element *l);

/**
 * \brief Ajoute un élément en tête de liste
 *
 * @param l pointeur sur la tête de liste
 * @param v valeur à ajouter à la liste
 * @return adresse du nouveau noeud dans la liste (en tête)
 */
element *add_head(element *l, int v);

/**
 * \brief Ajoute un élément en tête de liste
 *
 * @param l pointeur sur l'adresse de la tête de liste
 * @param v valeur à ajouter à la liste
 */
void add_head2(element **l, int v);

/**
 * \brief Ajoute un élément en queue de liste
 *
 * @param l pointeur sur l'adresse de la tête de liste
 * @param v valeur à ajouter à la liste
 */
void add_queue2(element **l, int v);

/**
 * \brief Ajoute de façon triée un élément dans une liste triée
 * @param l pointeur sur la tête de liste
 * @param v valeur à ajouter à la liste
 * @return pointeur sur la tête de liste modifiée (différent si l'ajout a eu lien en tête)
 */
element *add_sorted(element *l, int v);

/**
 * \brief Tri de liste (tri insertion)
 * @param l pointeur sur la tête de liste
 * @param ltriee nouvelle liste équivalente à l triée
 */
void sort_insertion(element *l, element **ltriee);


/** Fonction pour supprimer le premier element dans la liste chainee *
 * \brief suppresion du premier element de la liste
 * @param liste pointeur sur la tête de liste


*/
void suppression_head(element *liste);

/** Fonction pour supprimer le dernier element dans la liste chainee *
 * \brief suppresion du dernier element de la liste
 * @param liste pointeur sur la tête de liste


*/
void suppression_queue(element *liste);
