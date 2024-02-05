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

int menu(void){
    int x;
    int exit =0;
    while(1){
    printf("ProposerValeur(0)\nValeur minimale(1)\nValeur maximale(2)\nSomme(3)\nMoyenne(4)\nExit(5)");
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
    menu();
    return 0;
}
