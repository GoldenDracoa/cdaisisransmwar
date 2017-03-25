#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "nom_chemin.h"


char* chemin(char racine[], char dossier[]){
    char *temp;
    char liaison[] = "\\";
    int taille = strlen(racine) + strlen(liaison) + strlen(dossier) +1;
    temp = malloc(taille * sizeof(char));
    strcpy(temp,racine);
    strcat(temp,liaison);
    strcat(temp,dossier);
    return temp;
}

char* chemin_dossier(char racine[], char dossier[]){
    char *temp;
    char liaison[] = "\\";
    int taille = strlen(racine) + strlen(liaison) + strlen(dossier) +1;
    temp = malloc(taille * sizeof(char));
    strcpy(temp,racine);
    strcat(temp,liaison);
    strcat(temp,dossier);
    return temp;

}

char* nom_fichier(int num_fichier){
    char alphabet[26][2] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    char extension[4][5] = {".txt",".doc",".mp3",".xls"};
    char nom_base[9] ="Fichier_";
    char *retour;

    int alea = rand()%4;
    int taille =strlen(nom_base) + strlen(extension[alea]) + 1;

    retour = malloc(taille * sizeof(char));
    strcpy(retour,nom_base);
    strcat(retour,alphabet[num_fichier]);
    strcat(retour,extension[alea]);

    return retour;

}



void creation_masse_file(char racine[], int nb_fichier_total){
    int index_fichier;
    for (index_fichier = 0; index_fichier < nb_fichier_total; index_fichier++){
        FILE *temp;
        char *nom_temp;

        nom_temp = nom_fichier(index_fichier);
        temp = open(chemin(racine,nom_temp), O_CREAT);
        close(temp);
    }
}
