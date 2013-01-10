#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000

void ReadFile(FILE* fichier){
	char chaine[TAILLE_MAX] = "";
	
	if ( fichier != NULL){
		while(fgets(chaine,TAILLE_MAX,fichier) != NULL)
			printf("%s",chaine);
		}
}

void ReadCaracter(FILE* fichier){
	char current;
	
	if (fichier != NULL){
		do{
			current = fgetc(fichier);
			printf("%c",current);
		}
		while(current != EOF);
	}
}
		

	


