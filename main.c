#include <stdlib.h>
#include <stdio.h>
#include "pileReels.h"


int main(int argc, char const *argv[])
{
    printf("Hello world!\n");
    char expression[] = "22+5*";

    float resultat = evaluer(expression);

    char expression2[] = "(3+(4*(5-6)))";

    float resultat2 = evaluerInfixe(expression2);

    printf("resultat:%f",resultat2);

    printf("Goodbye world!\n");
    return 0;
}
