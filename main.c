#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "liste.h"



int main() {
    Client* liste = NULL;
    Client* tab[5];

    tab[0] = creerClient(0, 5, 2, 20);
    tab[1] = creerClient(1, -1, 9, 5);
    tab[2] = creerClient(2, 1, 1, 10);
    tab[3] = creerClient(3, 2, 2, 15);
    tab[4] = creerClient(4, 2, 2, 15);

    for (int i = 0; i < 4; i++) {
        liste = insertionClient(liste, tab[i], i+1);
        afficherListe(liste);
        printf("\nDistance parcourue: %f\n", distanceTotale(liste));
    }

    liste = insertionClient(liste,tab[4],2);
    afficherListe(liste);
    printf("\nDistance parcourue: %f\n", distanceTotale(liste));

    liste = suppressionClient(liste,2);
    afficherListe(liste);
    printf("\nDistance parcourue: %f\n", distanceTotale(liste));

    cleanMemory(liste);

    return 0;
}


