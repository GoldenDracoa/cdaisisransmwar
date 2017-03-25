#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nom_chemin.h"

int main()
{
    char racine[80] = "C:\\Users\\ransomware\\Documents\\CIBLE";
    char categorie[4][8] = {"test","photo","musique","divers"};
    char fruit[8][8] = {"poire","pomme","peche","prune","banane","cerise","orange","fraise"};
    char legume[12][20] = {"poireau","carotte","navet","haricot","epinard","brocoli","artichaut","betterave","chou","mais","panais","radis"};

    int index_base;

    printf("Creation Arborescence!\n");

    // Boucle Principale
    for(index_base = 0; index_base < 4; index_base++){
        char *niv_a;
        int alea_niv_b = rand()%8;
        int alea_nb_file_a = rand()%26;
        int index_niv_b;

        niv_a = chemin_dossier(racine,categorie[index_base]);
        printf("%s\n",niv_a);
        mkdir(niv_a);
        creation_masse_file(niv_a, alea_nb_file_a);

        for (index_niv_b = 0; index_niv_b < alea_niv_b; index_niv_b++){
            char *niv_b;
            int alea_niv_c = rand()%12;
            int alea_nb_file_b = rand()%26;
            int index_niv_c;

            niv_b = chemin_dossier(niv_a,fruit[index_niv_b]);
            printf("%s\n",niv_b);
            mkdir(niv_b);
            creation_masse_file(niv_b, alea_nb_file_b);
            for(index_niv_c = 0; index_niv_c < alea_niv_c; index_niv_c++){
                char *niv_c;
                int alea_nb_file_c = rand()%26;
                niv_c = chemin_dossier(niv_b,legume[index_niv_c]);
                printf("%s\n",niv_c);
                mkdir(niv_c);
                creation_masse_file(niv_c, alea_nb_file_c);
            }

        }
    }



    return 0;
}
