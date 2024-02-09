#ifndef LISTE_H
#include <stdlib.h>
#include <stdio.h>
#define LISTE_H

typedef struct Client {
    int id;
    float x;
    float y;
    int quantite;
    struct Client* Suivant;
} Client;

Client* creerClient(int id, int x, int y, int quantite);
void afficherListe(Client* liste);
float distance(Client* c1, Client* c2);
float distanceDepot(Client* c);
float distanceTotale(Client* liste);
int meilleurePosition(Client* liste, Client* c);
Client* insertionClient(Client* liste, Client* c, int pos);
Client* suppressionClient(Client* liste, int pos);
void cleanMemory(Client* Liste);

#endif
