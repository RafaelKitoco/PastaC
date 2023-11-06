#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spessoa {
    char nome[20];
    int idade;
    struct spessoa *PROXI;
} PESSOA;

typedef PESSOA *FILA;

void iniciar(FILA *fila) {
    *fila = NULL;
}

void inserir(FILA *fila, int idade, char *nome) {
    if (*fila == NULL) {
        *fila = (FILA)malloc(sizeof(PESSOA));
        if (*fila == NULL) { return; }
        (*fila)->idade = idade;
        strcpy((*fila)->nome, nome);

    } else {
        inserir(&(**fila).PROXI, idade, nome);
    }
}

void sair(FILA *fila) {
    PESSOA *temp = *fila;

    if (*fila == NULL) { return; }

    *fila = (*fila)->PROXI;

    free(temp);
}

void listar(FILA *fila) {
    if (*fila == NULL) { return; }

    printf("nome :%s \n idade : %d", (*fila)->nome, (*fila)->idade);
    listar(&(**fila).PROXI);
}

int main(int argc, char *argv[]) {
    FILA F;
    iniciar(&F);
    inserir(&F, 22, "Rafael");
    return 0;
}
