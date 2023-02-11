#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void cria_lista(void);
void insere(char **baseString,char * newString);
void Apaga ( char **baseString, char *toBeDeletedString );
void imprime(char * s);
int menu(void);
int livre(void);
void LerString(char palavra[MAX]);

int main()
{
	int escolha;
    char *list;
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
			exit(0);
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
    while (i < MAX) {
        palavra[i] = '\0';
        i++;
    }

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
        *baseString = ( char* )malloc( sizeof( char ) * sizeNew );
        strcpy(*baseString, newString);
    } else {
        int counter = 0;
        *baseString = ( char* )realloc( *baseString, ( ( sizeBase+sizeNew+2 ) * sizeof( char ) ) );
        //*baseString[sizeBase] = ',';
        for( int i = sizeBase+1 ; i < ( sizeBase + sizeNew ) ; i++ ) {
            *baseString[i] = newString[counter];
            counter++;
        }
    }
}

void Apaga ( char **baseString, char *toBeDeletedString )
{
    int found = 0;
    char *tempBase;
    strcpy(*baseString, tempBase);
    free(*baseString);
    char *temp = strtok(tempBase,",");
    while (temp != NULL) {
        if(temp != toBeDeletedString && found != 1) {
            insere(baseString, temp);
        }
    }

}

void imprime(char * s)
{
	printf("Name List: %s", s);
}
