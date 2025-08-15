#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Função para verificar se uma letra é vogal
int eh_vogal(char letra) {
    letra = toupper(letra); // garante maiúscula
    return (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

// Função que gera uma letra aleatória de A a Z
char letra_aleatoria() {
    int num = rand() % 26;  // 0 a 25
    return 'A' + num;       // converte para letra
}

int main() {
    
    for(int k = 0; k < 1000; k++){
    srand(time(NULL)); // inicializa gerador aleatório

    //char resultado[51]; // até 50 letras + '\0'
    char resultado[51];
    int tamanho = 7;   // tamanho da sequência desejada
    int i = 0;

    // Gerar primeira letra (sem restrição)
    resultado[i] = letra_aleatoria();
    i++;

    // Gerar as próximas letras seguindo a regra
    while (i < tamanho) {
        char nova_letra = letra_aleatoria();

        // Regra de alternância
        if (eh_vogal(resultado[i - 1]) && !eh_vogal(nova_letra)) {
            resultado[i] = nova_letra;
            i++;
        } else if (!eh_vogal(resultado[i - 1]) && eh_vogal(nova_letra)) {
            resultado[i] = nova_letra;
            i++;
        }
        // caso contrário, sorteia de novo na próxima iteração
    }

    resultado[i] = '\0'; // finaliza string
    printf("\n");
    printf("Sequencia gerada: %s\n", resultado);

    system("timeout /NOBREAK 1");
    }
    return 0;

    
}
