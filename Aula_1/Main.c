#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2048;

int isValid(char * s);


int main(){

    char *string;
    FILE *file;
    int breakVar,breakVar2 = 0;
    int counter = 0;

    if ((file = fopen("/home/igor/Programming/Algoritmos_E_Estrutura_De_Dados_1/Aula_1/input.txt", "r")) == NULL) {
		printf("Error on opening file!\n");
		exit(1);
	}
	while(!feof(file)) {
        counter = 0;
        char *word = (char*)malloc(sizeof(char));
        while(!feof(file)) {
            char currentChar = fgetc(file);
            if(currentChar == '\n' || currentChar == '\377') {
                break;
            }
            else {
                word[counter] = currentChar;
                counter++;
                word = (char*)realloc(word, (1+counter) * sizeof(char));
            }
        }
        word[counter] = '\0';
        int result = isValid(word);
        if(result) {
            printf("%s e valido\n", word);
        } else {
            printf("%s nao e valido\n", word);
        }
        free(word);
    }

    fclose(file);

    return 0;
}

int isValid(char * s){

    int strLength = strlen(s);
    if(strLength%2 != 0) {
        return 0;
    }
    char *pile;
    pile = (char *) malloc((strLength/2)*sizeof(char));
    int topPile = -1;
    for(int i=0;i<strLength;i++) {

       if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
           topPile++;
           if(topPile == strLength/2){
               return 0;
           } else {
                pile[topPile] = s[i];
           } 
        }
        else if(topPile == -1) {
            return 0;
        }
        else if(s[i] == ')') {
            if(pile[topPile] != '(') {
                return 0;
            }
            topPile--;
        }
        else if(s[i] == ']') {
            if(pile[topPile] != '[') {
                return 0;
            }
            topPile--;
        }
        else if(s[i] == '}') {
            if(pile[topPile] != '{') {
                return 0;
            }
            topPile--;
        }
    }
    if(topPile != -1) {
        free(pile);
        return 0;
    } else {
        free(pile);
        return 1;
    }

}

