

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

void lire_lts(char *filename);
lts sauver_lts();
lts  creer_lts();
void ajouter_etat();
void supprimer_etat();
void ajouter_transition();
void supprimer_transition();
