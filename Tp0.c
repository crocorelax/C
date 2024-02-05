#include <stdio.h>
#include <stdlib.h>

int number_bettween_1_and_3(){
    printf("hey, donne moi un nombre entre 1 et 3 compris stp !");
    int x;
    while(1){

    scanf("%d",&x);
    if(x>=1&&x<=3){ break; }

    }
    return x;
}

void dix_prochains(void){
    int x;
    printf("hey, donne moi un nombre stp !\n");
    scanf("%d",&x);
    printf("votre nombre est:%d\n",x);
    printf("voici les dix suivants:\n");
    for (int i = x+1; i<= x+10; i++)
    {
        printf("%d\n",i);
    }
}

int PGCD(int x, int y){
    int r;
    r= x%y;
    while(r!=0){
        x=y; y=r; r= x%y;
    }
    printf("Le PGCD est:%d\n",y);
    return y;
}

int* ProposerValeur(){
    int x;
    printf("Entrer le nombre de chiffre que vous souhaiterez entrer :\n");
    scanf("%d",&x);
    int* Liste = (int*)malloc(x*sizeof(int));
    for (int i = 0; i < x; i++)
    {
        int temp;
        printf("Entre le %d nombre :",i);
        scanf("%d",&temp);
        Liste[i]= temp;
    }
    return Liste; 
}

int Valeur_minimale(int* Liste){
    int temp = Liste[0];
    for (int i = sizeof(Liste)/sizeof(int); i > 0; i--){
        if(temp>Liste[i]){
            temp=Liste[i];
        }
    }
    return temp;
}
int Valeur_maximale(int* Liste){
    int temp = Liste[0];
    for (int i = sizeof(Liste)/sizeof(int); i > 0; i--){
        if(temp<Liste[i]){
            temp=Liste[i];
        }
    }
    return temp;
}

int Valeur_somme(int* Liste){
     int temp = Liste[0];
    for (int i = sizeof(Liste)/sizeof(int); i > 0; i--){
        temp+=Liste[i];
    }
    return temp;
}

int Valeur_moyenne(int* Liste){
    int temp = Liste[0];
    int size = sizeof(Liste)/sizeof(int);
    for (int i = size; i > 0; i--){
        temp+=Liste[i];
    }
    return temp/size;
}

int Deux_Valeur_minimale(int* Liste){
    int petit=Valeur_maximale(Liste);
    int index;
    int pluspetit=Liste[0];
    for (int i = sizeof(Liste)/sizeof(int); i > 0; i--){
        if(pluspetit>Liste[i]){
            pluspetit=Liste[i];
            index=i;
        }
    }
    for (int i = sizeof(Liste)/sizeof(int); i > 0; i--){
        if(petit>Liste[i]&&i!=index){
            petit=Liste[i];
        }
    }
    printf("Valeur la plus petite :%d \nDeuxieme valeur la plus petite :%d \n",pluspetit,petit);
    return 0;
}

int* FusionDeTableaux(){
    int x;
    printf("Entrer le nombre de chiffre que vous souhaiterez entrer :\n");
    scanf("%d",&x);
    int* tab1 = (int*)malloc(x*sizeof(int));
    int* tab2 = (int*)malloc(x*sizeof(int));
    int* tab3 = (int*)malloc(x*sizeof(int));
    for (int i = 0; i < x; i++)
    {
        int temp;
        printf("Entre le %d nombre (du tableau 1):",i);
        scanf("%d",&temp);
        tab1[i]= temp;
    }
    for (int i = 0; i < x; i++)
    {
        int temp;
        printf("Entre le %d nombre (du tableau 2):",i);
        scanf("%d",&temp);
        tab2[i]= temp;
    }
    printf("Le nouveau tableau retourné est composé de : (");
    for (int i = 0; i < x; i++)
    {
        tab3[i]= tab1[i]+tab2[i];
        printf("%d, ",tab3[i]);
    }
    printf(")");
    free(tab1);
    free(tab2);
    return tab3; 
}

void DeleteElement(int* Liste){
    int x;
    printf("Entrer la case que vous souhaiterez supprimer :\n");
    scanf("%d",&x);
    int size = sizeof(Liste)/sizeof(int);
    for (int i = x; i < size-1; i++)
    {
        Liste[i]=  Liste[i+1];
    }
    Liste[size]=0;
}

int menu(void){
    int x;
    int exit =0;
    while(1){
    printf("ProposerNouvellesValeur(0)\nValeur minimale(1)\nValeur maximale(2)\nSomme(3)\nMoyenne(4)\nDeux Valeurs Minimales(5)\nFusion De Tableaux(6)\nDelete Element(7)\nExit(10)");
    scanf("%d",&x);
    switch (x)
    {
    case 0:
        int* Liste = ProposerValeur();
        break;
    case 1:
        int minimale= Valeur_minimale(Liste);
        printf("La valeur minimale proposer est %d\n",minimale);
        break;
    case 2:
        int maximale= Valeur_maximale(Liste);
        printf("La valeur maximale proposer est %d\n",maximale);
        break;
    case 3:
        int somme= Valeur_somme(Liste);
        printf("La somme des valeur proposer est %d\n",somme);
        break;
    case 4:
        int moyenne= Valeur_moyenne(Liste);
        printf("La moyenne des valeur proposer est %d\n",moyenne);
        break;
    case 5:
        Deux_Valeur_minimale(Liste);
        break;
    case 6:
        FusionDeTableaux();
        break;
    case 7:
        DeleteElement(Liste);
        break;
    case 10:
        free(Liste);
        exit=1;
        break;
    default:
        break;
    }
    if(exit==1){
        break;
    }
    }
}


int main(){
    printf("Hello World\n");
    
    return 0;
}
