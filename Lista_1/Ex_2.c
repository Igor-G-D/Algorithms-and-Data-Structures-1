#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void insere(char **baseString,char * newString);
void Apaga ( char **baseString, char *toBeDeletedString );
void imprime(char * s);
int menu(void);
void LerString(char palavra[MAX]);

int main()
{
	int escolha;
    char *list = NULL;
    char *name = ( char* )malloc( sizeof( char ) * 256);
    
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
            printf("Digite o nome a ser inserido: ");
            LerString(name);
			insere(&list, name);
			break;
		case 2:
            printf("Digite o nome a ser removido: ");
            LerString(name);
			Apaga(&list, name);
			break;
		case 3:
			imprime(list);
			break;
		case 4:
			free(name);
			free(list);
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Listar nomes\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

void LerString(char palavra[MAX])
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < MAX)) {
		palavra[i++] = c;
		c = getchar();
	}
    palavra[i] = '\0';


}



void insere(char **baseString,char * newString)
{
    int sizeBase;
	if (*baseString == NULL) {
        sizeBase = 0;
    } else {
        sizeBase = strlen(*baseString);
    }
    int sizeNew = strlen(newString);

	if(sizeBase == 0) {
        *baseString = ( char* )malloc( sizeof( char ) * sizeNew + 1);
        strcpy(*baseString, newString);
    } else {
        int counter = 0;

        (*baseString) = ( char* )realloc( (*baseString), ( (sizeBase+sizeNew + 2) * sizeof( char ) ) );
        (*baseString)[sizeBase] = ',';

        for( int i = sizeBase+1 ; i < ( sizeBase + sizeNew + 2) ; i++ ) {
            (*baseString)[i] = newString[counter];
            counter++;
		}	
    }
}

void Apaga ( char **baseString, char *toBeDeletedString )
{
	int found = 0;
    char *tempBase = (char*)malloc((strlen(*baseString)+1) * sizeof(char));
    strcpy(tempBase, *baseString);
    free(*baseString);
	*baseString = NULL;
    char *temp = strtok(tempBase,",");
    while (temp != NULL) {
        if(strcmp(temp, toBeDeletedString) != 0 || found) {
            insere(baseString, temp);
        } else {
			found = 1;
		}
		temp = strtok(NULL,",");
    }
	free(temp);
	free(tempBase);

}

void imprime(char * s)
{
	printf("Name List: %s\n", s);
}
