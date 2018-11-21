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
 * \brief Affiche le nombre d'allocations et de d�sallocation de m�moire
 */
void print_allocations();

/**
 * \brief Wrapper pour allocation m�moire.
 *
 * @param __size taille de l'allocation
 * @return adresse de l'espace m�moire allou�
 */
void *malloc_wrapper(size_t __size);

/**
 * \brief Wrapper pour d�sallocation m�moire.
 *
 * @param p adresse de l'espace m�moire � d�sallouer
 */
void free_wrapper(void *p);

/**
 * \brief D�salloue l'ensemble de la m�moire utilis� pour une LLC
 *
 * @param pointeur sur l'adresse de la t�te de liste
 */
void free_list(element **e);

/**
 * \brief Affiche une LLC
 *
 * @param l pointeur sur la t�te de liste
 */
void print_list(element *l);

/**
 * \brief Ajoute un �l�ment en t�te de liste
 *
 * @param l pointeur sur la t�te de liste
 * @param v valeur � ajouter � la liste
 * @return adresse du nouveau noeud dans la liste (en t�te)
 */
element *add_head(element *l, int v);

/**
 * \brief Ajoute un �l�ment en t�te de liste
 *
 * @param l pointeur sur l'adresse de la t�te de liste
 * @param v valeur � ajouter � la liste
 */
void add_head2(element **l, int v);

/**
 * \brief Ajoute un �l�ment en queue de liste
 *
 * @param l pointeur sur l'adresse de la t�te de liste
 * @param v valeur � ajouter � la liste
 */
void add_queue2(element **l, int v);

/**
 * \brief Ajoute de fa�on tri�e un �l�ment dans une liste tri�e
 * @param l pointeur sur la t�te de liste
 * @param v valeur � ajouter � la liste
 * @return pointeur sur la t�te de liste modifi�e (diff�rent si l'ajout a eu lien en t�te)
 */
element *add_sorted(element *l, int v);

/**
 * \brief Tri de liste (tri insertion)
 * @param l pointeur sur la t�te de liste
 * @param ltriee nouvelle liste �quivalente � l tri�e
 */
void sort_insertion(element *l, element **ltriee);


/** Fonction pour supprimer le premier element dans la liste chainee *
 * \brief suppresion du premier element de la liste
 * @param liste pointeur sur la t�te de liste


*/
void suppression_head(element *liste);

/** Fonction pour supprimer le dernier element dans la liste chainee *
 * \brief suppresion du dernier element de la liste
 * @param liste pointeur sur la t�te de liste


*/
void suppression_queue(element *liste);
