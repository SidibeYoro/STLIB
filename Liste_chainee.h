#define LISTE_CHAINEE_H_INCLUDED



// On crer une structure qui va nous permettre de faire nos liste chainee
typedef struct Element Element;
struct Element {
    int nombre;
    Element *suivant;

};

// O creer une structure liste qui va nous permettre de controler l'ensemble de nos LC
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

