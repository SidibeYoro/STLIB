 typedef struct transition{
    int depart;
    int arrive;
    char *alphabet;
    struct transition *next;
}transition;

typedef struct lts{
    char **alphabet;///tab ex manger, boire....// int eata[]
    int * etat;   //tab etat ex,:  1, 2, 3...
	int etat_initial; //1
	transition *tete, *queue; ///tabde trans ex/t1, t2,...
    int *etat_final; ///tab : ex 2, 4..
    int nb_etat_final;
    int nb_trans;   ///nb_etat =nb_trans plus 1;
}lts;

/* Nos declaations de fonction */
void open_lts(char *filename);

/**
 * \brief Ouvre un fichier texte contenant un lts
 *
 * @param filename , pointeur de type char
 */
lts *read_lts(char *filename);

/**
 * \brief lit les donnees d'un fichier lts
 *
 * @param filename , pointeur de type char
 * @return Retourne un lts avec l'ensemble de ces donnees
 */
lts *write_lts(char *filename);
/**
 * \brief ecris sur un fichier contenant un lts
 *
 * @param filename , pointeur de type char
 * @return Retourne un lts avec les nouveaux donnees ecris dedans
 */

void sauver_lts(lts * l, const char * save);

/**
 * \brief sauve un lts dans un fichier vide
 * @param l pointeur de type lts
 * @param save pointeur de type char

 */
lts *creer_lts();

/**
 * \brief cree un lts vide

 */
int estVide(lts * l);


/**
 * \brief verifie si un lts est vide
 * @param l pointeur de type lts
 * @return Retourne 0 si le lts estvide et 1 sino

*/

int estpleine(lts *l);

/**
 * \brief verifie si un lts est pleine
 * @param l pointeur de type lts
 * @return Retourne 0 si le lts estpleine et 1 sinon

*/

void ajouter_etat(lts *l, int e);
/**
 * \brief ajoute un etat e dans un lts
 * @param l pointeur de type lts
 * @param e , l'etat a ajouter de type int

*/


void afficher_lts(lts * l);
/**
 * \brief affiche un automate
 * @param l pointeur de type lts

*/
void supprimer_etat(lts *l, int e);

/**
 * \brief supprime un etat e dans un lts
 * @param l pointeur de type lts
 * @param e , l'etat a supprimer de type int
*/

void ajouter_transition(lts *l, transition *t);
/**
 * \brief ajoute une transition t dans un lts
 * @param l pointeur de type lts
 * @param t pointeur de type type transition
*/

transition*  new_transition(lts *l, char *al);
/**
 * \brief
 * @param
 * @param
  * @return Retourne 0 si le lts estpleine et 1 sinon
*/
