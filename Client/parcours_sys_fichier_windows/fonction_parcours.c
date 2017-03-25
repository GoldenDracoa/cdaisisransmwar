#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <fcntl.h>
#include <unistd.h>

#include "fonction_parcours.h"

#define PATH_SEPARATOR "\\"



void parcours_dossier(const char* racine , int carto){


    DIR* rep_courant;
    struct dirent* contenu;
    char* chemin_dossier;
    char* w_chemin;

    DWORD attribut;

    errno = 0;
    rep_courant = opendir(racine);
    if (errno != 0){
        perror(" ouverture du dossier");
        return;
    }

     while((contenu = readdir(rep_courant)) != NULL){
        if(strcmp(contenu->d_name, ".") == 0 || strcmp(contenu->d_name, "..") == 0  ){
            continue;
        }
        chemin_dossier= (char*) calloc(strlen(racine)+ strlen(contenu->d_name) + 2, sizeof(char));
        chemin_dossier[0] = '\0';
        strcat(chemin_dossier, racine);
        strcat(chemin_dossier, PATH_SEPARATOR);
        strcat(chemin_dossier,contenu->d_name);



        attribut = GetFileAttributes(chemin_dossier);
        if(attribut & FILE_ATTRIBUTE_DIRECTORY){
            parcours_dossier(chemin_dossier,carto);
        }
        else{
            w_chemin = (char*) calloc(strlen(chemin_dossier)+2, sizeof(char));

            w_chemin[0] = '\0';
            strcat(w_chemin,chemin_dossier);
            strcat(w_chemin,"\n");
            int taille_w =strlen(w_chemin);
            //printf("%s",w_chemin);

            write(carto,w_chemin,taille_w);
        }



    }
    closedir(rep_courant);
}
