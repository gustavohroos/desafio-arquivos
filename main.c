#include <stdio.h>
#include <string.h>

#define MAX 100

FILE *fp;

void removerSpacos(char str[]) {
    int j = 0;
    for (int i = 1; str[i]; i++) {
        if (str[i] != ' ') {
           str[j] = str[i];
           j++;
        }
    }
    str[j] = '\0';
}

int main (){
    char conteudo[MAX];
    char novo_arq[MAX];
    char txt[] = ".txt";
    char next[] = "Next nothing is ";
    int tamanho, i, retirar;

    (fp = fopen("90052.txt", "r")); //abre o primeiro arquivo
    
    do
    {
        fgets(conteudo, MAX, fp);
            tamanho=strlen(conteudo);
            retirar=strlen(next);
        fclose(fp);
            for (i = 0; i < retirar; i++) //transforma o inicio da frase em espaços
            {
                conteudo[i]=' ';
            }
            
            removerSpacos(conteudo); //remove os espaços e deixa só o numero do proximo arquivo

            strcat(conteudo, txt); //adiciona o .txt 

            printf("\n%s", conteudo);

            strcpy(novo_arq, conteudo);

            rewind(fp);

            (fp = fopen(novo_arq, "r")); //abre o arquivo (numero).txt


    } while (strcmp(conteudo,next) < 0);


    return 0;

}