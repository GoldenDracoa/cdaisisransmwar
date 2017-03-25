#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/in.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define LOCALHOST "127.0.0.1"

int main (){
	char buffer[1024];
	struct sockaddr_in sin;
	int sd ;
	int length;
	char donnee_envoie[10]="abcdefgh";

	/* Ouverture d'un socket afin de recevoir des demandes */
	
	sd = socket(AF_INET,SOCK_STREAM,0);
	
	/* Configuration de la connexion*/
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(60000);

	/* Si le client arrive à se connecter */
	if (connect(sd, (struct sockaddr *)&sin, sizeof(sin)) < 0){
		printf("Problème de connection");
		exit(1);
	}
	recv(sd,buffer,sizeof(buffer),0);
	printf("\ndonnée recu non affiché\n");
	printf(buffer); 
	printf("\napres affichage\n");
	printf("Envoie de données\n ");
	if (send(sd,donnee_envoie,strlen(donnee_envoie),0) < 0){
		perror("pb envoie\n");
	}
	printf("Données envoyé - FIN \n");
	
	shutdown(sd, 2);
	close(sd);	
}
