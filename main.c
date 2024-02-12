#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Patient
{
    char nom[50];
    char prenom[50];
    int age;
    char NumeroSecuriteSociale[16];
    struct Patient* Suivant;
}Patient;

typedef struct fileAttente{
    int nombre;
    Patient* Premier;
    Patient* Dernier;
}fileAttente;


//declaration de la liste d'attente en globale
fileAttente* File;

//verification si la liste est vide
int fileVide(fileAttente* file){
    if(file->nombre==0&&file->Premier==NULL&&file->Dernier==NULL)
    { 
        printf("la file est vide action annule\n"); 
        return 1;
    }
    return 0;
}


void initFile(fileAttente* file){
    printf("Initialisation de file d'attente\n");
    file->nombre=0;
    file->Premier=NULL;
    file->Dernier=NULL;
    return;
}

//file pleine ne pourra pas se faire dans le cadre d'une file dynamique

Patient *saisiePatient(){

    Patient* nouveauPatient = malloc(sizeof(Patient));

    printf("Renseignez\n");
    printf("-nom:\n");
    scanf("%s",nouveauPatient->nom);
    printf("-prenom:\n");
    scanf("%s",nouveauPatient->prenom);
    printf("-age:\n");
    scanf("%d", &nouveauPatient->age);
    printf("-numero de securite sociale:\n");
    scanf("%s",nouveauPatient->NumeroSecuriteSociale);

    nouveauPatient->Suivant=NULL;

    return nouveauPatient;
}

void arriveePatient(fileAttente *file, Patient *nouveauPatientFile){

    if(file==NULL||nouveauPatientFile==NULL){ return;}

    //si la file etait vide premier = dernier = nouveau patient
    if(file->nombre==0){
        file->Dernier=nouveauPatientFile;
        file->Premier=nouveauPatientFile;
        file->nombre++;
        return;
    }
    //cas basique, on relie le dernier au nouveau, le nouveau est a present le dernier
    file->Dernier->Suivant=nouveauPatientFile;
    file->Dernier=nouveauPatientFile;
    file->nombre++;
    return;
}

void departPatient(fileAttente *file) {

    if(fileVide(file)){return;}

    //on affiche le nom du premier patient de la file
    printf("Patient partie: %s\n",file->Premier->nom);

    //on creer un pointeur temporaire vers le premier patient
    Patient* temp = file->Premier;

    //je reduis la taille de la file
    file->nombre--;

    //je n'avais qu'un seul patient, il n'a plus personne dans la file
    //ceci n'est pas reelement utile puisque le free malloc aurait forcer les pointeurs a pointe sur null
    if(file->nombre==0){
        file->Premier=NULL;
        file->Dernier=NULL;
    }
    //j'avais plusieurs patient (cas basique), le premier deviens le suivant du premier
    else
    {
        file->Premier=file->Premier->Suivant;
    } 
    
    //si il ne reste qu'un seul patient je pense a mettre dernier sur premier
    if(file->nombre==1){
        file->Dernier=file->Premier;
    }
    
    //on libere le patient
    free(temp);
}

//Verifie si le numero de securite sociale donne appartiens a un patient de la file et le renvoie
Patient * estPresent(fileAttente* file, char *NumeroSecuriteSociale){

    if(fileVide(file)||NumeroSecuriteSociale==NULL){return NULL;}

    //Recuperer le premier de la file
    Patient* index =file->Premier;

    int resultat=-1;
    //parcourir la file jusqu'a rencontrer une correspondance dans les numero de secu
    while(resultat!=0){

        //on compare le numero donne avec celui de l'index
        resultat = strcmp(index->NumeroSecuriteSociale,NumeroSecuriteSociale);

        //si l'index obtenu est bon, on le renvoie
        if(!resultat) return index;

        //si le on a un prochaine element, on avance
        if(index->Suivant!=NULL) index=index->Suivant;
    }

    //sinon on renvoie rien
    return NULL;
}

void abandonPatient(fileAttente *file, char *NumeroSecuriteSociale){

    //verification des parametres
    if(fileVide(file)||NumeroSecuriteSociale==NULL){return;}

    //appelle à la verification de la presence d'un patient avec le numero voulu
    Patient* patient = estPresent(file,NumeroSecuriteSociale);

    //si on le trouve pas on abandonne
    if(patient==NULL){return;}

    //si la file n'a qu'un patient
    if(file->nombre==1){
        file->Premier=NULL;
        file->Dernier=NULL;
    }

    //le patient est premier dans la file
    else if(patient==file->Premier)
    {
        file->Premier=file->Premier->Suivant;
    }

    //apres avoir verifier je sais que j'ai un patient au milieu ou a la fin de la file
    else{

        //je parcours la liste jusqu'a atteindre l'element avant celui que je dois supprimer
        Patient* precedent = file->Premier;

        while(precedent->Suivant!=NULL&&precedent->Suivant!=patient){precedent=precedent->Suivant;}    

        //si l'element a supprimer est le derniere element de la file
        if(patient->Suivant==NULL){
            file->Dernier=precedent;
            precedent->Suivant=NULL;
        }
        //c'est un element au milieu (cas banale)
        else
        {
            precedent->Suivant=patient->Suivant;
        }
    }

    free(patient);
    file->nombre--;
    return;
}

void viderFile(fileAttente* file){
    if(fileVide(file)){return;}

    for(int i =0; i<file->nombre;i++){
        departPatient(file);
    }
}


void afficherPatient(Patient* patient){
    if(patient==NULL) return;

    printf("nom: %s\n",patient->nom);
    printf("prenom: %s\n",patient->prenom);
    printf("age: %d\n",patient->age);
    printf("numero de secu: %s\n",patient->NumeroSecuriteSociale);
}

void afficherListe(fileAttente* file){
    if(fileVide(file)){return;}

    Patient* patient = file->Premier;
    for(int i =0; i<file->nombre;i++){
        afficherPatient(patient);
        patient=patient->Suivant;
    }
}

void enregistreFileAttente(fileAttente* file, char *nomFic){
    //on enregistre pas si c'est vide
    if(fileVide(file)||nomFic==NULL){return;}
    
    //on ouvre le fichier en modre ecriture binaire
    FILE* f;
    f=fopen(nomFic,"wb");

    //on verifie que on a bien ouvert un fichier
    if(f == NULL) {
        printf("Erreur ouverture du fichier\n");
        return;
    }

    //on ecrit la taille de la liste
    fwrite(&file->nombre,sizeof(int),1,f);
    
    //tant que l'on a un patient dans la file on l'ecrit dans le fichier et on passe au suivant
    Patient* index = file->Premier;
    while(index!=NULL){
        fwrite(index,sizeof(Patient),1,f);
        index=index->Suivant;
    }
    
    //on ferme le fichier
    fclose(f);
}

void lireFileAttente(fileAttente* file, char *nomFic){
    if(nomFic==NULL){return;}

    //on ouvre le fichier en mode lecture bianire
    FILE* f;
    f=fopen(nomFic,"rb");

    //on verifie que l'on a bien ouvert un fichir
    if(f == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la lecture.\n");
        return;
    }

    //on instancie une longueur, on recupere la longueur du tableau qui se situe au debut du fichir
    int longueur = 0;
    fread(&longueur,sizeof(int),1,f);

    //pour la longueur de la file
    for (int i = 0; i < longueur; i++)
    {
        //on creer un emplacement de patient
        Patient* nouveauPatient = malloc(sizeof(Patient));
        //on recupere les donnees d'un patient du fichier
        fread(nouveauPatient,sizeof(Patient),1,f);
        //on l'insere dans la file à l'aide d'une methodes precedente
        arriveePatient(file,nouveauPatient);
    }

    //on ferme le fichier
    fclose(f);
}

int menu(void){
    int indexMenu = -1;
    char numero[16];
    File = malloc(sizeof(fileAttente));
    initFile(File);

    printf("On est bon\n\n");
    while(1){
        printf("Menu:");
        printf("-Arrivee Patient (rajoute un nouveau patient a la liste)(0)\n");
        printf("-Depart Patient (le premier patient de la file est appele)(1)\n");
        printf("-Abandon Patient (le patient abandonne sa place)(2)\n");
        printf("-Afficher File d'attente (affiche les informations de tous les patients) (3)\n");
        printf("-EnregistrerFichier (4)\n");
        printf("-LireFichier (5)\n");
        printf("-Exit(6)\n");
        
        scanf("%d",&indexMenu);
        switch (indexMenu)
        {
        case 0:
            arriveePatient(File,saisiePatient());
            break;
        case 1:
            departPatient(File);
            break;
        case 2:
            scanf("%15s", numero);
            abandonPatient(File,numero);
            break;
        case 3:
            printf("Patient dans la file :\n");
            afficherListe(File);
            break;
        case 4:
            enregistreFileAttente(File,"FileAttente.bin");
            break;
        case 5:
            lireFileAttente(File,"FileAttente.bin");
            break;
        case 6:
            viderFile(File);
            free(File);
            return 0;
        default:
            break;
        }
    }
}

int main() {
    printf("Hello World!\n");
    menu();
    printf("Goodbye World!\n");
    return 0;
}