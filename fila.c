#include <stdio.h>
#include <stdlib.h>

typedef struct Date_nac {
    int dia, ano;
    char mes[100];
} DATE;

typedef struct Info {
    int telefone;
    char email[100];
} INFO;

typedef struct PESSOA {
    char nome[100];
    DATE data;
    INFO info_contact;
} PESSOA;

void mostrar(PESSOA x) {
    puts("------------------------");
    printf("nome :%s \n", x.nome);
    printf("data de nascimento %d/%s/%d \n", x.data.dia, x.data.mes, x.data.ano);
    printf("Informacao de contacto : \n");
    printf("telefone : %d \n", x.info_contact.telefone);
    printf("email : %s", x.info_contact.email);
    puts("-------------------------");
}

void ler(PESSOA *x) {
    puts("-------------------------");
    printf("\nQual é o seu nome : ");
    scanf(" %s", (x->nome));
    puts("");
    printf("Qual sua data de nascimento :");
    scanf("%d %s %d", &x->data.dia, x->data.mes, &x->data.ano);
    puts("");
    printf("A sua informacao de contacto : ");
    puts("-------------------------");
    printf("email : ");
    scanf(" %s", (x->info_contact.email));
    puts("");
    printf("telefone :");
    scanf("%d", &x->info_contact.telefone);
}

void mostrar_info() {
    FILE *ficheiro;
    int ch;

    ficheiro = fopen("info", "r");
    if (ficheiro == NULL) {
        printf("Imposivel de abrir o ficheiro !");
    } else {
        while ((ch = fgetc(ficheiro)) != EOF) { printf("%c", ch); }
        fclose(ficheiro);
    }
}

void abrir(char nome[100], PESSOA x) {
    FILE *ficheiro;

    ficheiro = fopen(nome, "a+");

    if (ficheiro == NULL) {
        printf("Imposivel de abrir o ficheiro");
    } else {
        fprintf(
            ficheiro,
            "\n nome: %s \n data de nascimento : %d/%s/%d \n informacao de contacto : \n email: "
            "%s \n telefone : %d \n--------------------\n",
            x.nome, x.data.dia, x.data.mes, x.data.ano, x.info_contact.email,
            x.info_contact.telefone);
        fclose(ficheiro);
    }
}

int main(int argc, char *argv[]) {
    PESSOA x = {"Rafael", {3, 2000, "Setembro"}, {930937864, "rkitoco@gmail.com"}};

    abrir("info", x);

    mostrar(x);
    puts("---------------------------");
    ler(&x);
    abrir("info", x);
    puts("----------------------------");
    mostrar(x);

    mostrar_info();

    return 0;
}
