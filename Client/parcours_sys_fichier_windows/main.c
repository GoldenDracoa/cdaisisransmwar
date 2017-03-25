#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <windows.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "fonction_parcours.h"

#define PATH_SEPARATOR "\\"

int main()
{

    char racine[72] = "C:\\Users\\ransomware\\Documents";
    int carto;
    carto = open("C:\\Users\\ransomware\\Documents\\CARTE\\cartographie.txt",O_CREAT | O_WRONLY);

    parcours_dossier(racine, carto);

    close(carto);

    return 0;
}
