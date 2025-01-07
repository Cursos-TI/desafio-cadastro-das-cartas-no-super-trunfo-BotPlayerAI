#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESTADOS 8
#define CIDADES_POR_ESTADO 4

typedef struct {
    char codigo[4]; // Código da carta (ex: A01, B02)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("-------------------------------------\n");
}

int main() {
    Cidade cidades[ESTADOS * CIDADES_POR_ESTADO];
    int totalCartas = 0;
    char opcao;

    printf("Bem-vindo ao Sistema Super Trunfo: Países!\n");

    do {
        if (totalCartas >= ESTADOS * CIDADES_POR_ESTADO) {
            printf("Você atingiu o limite máximo de cartas cadastradas.\n");
            break;
        }

        printf("\nCadastro de uma nova cidade:\n");

        // Geração do código da carta
        char estado;
        int cidadeNumero;
        printf("Informe o estado (letra de A a H): ");
        scanf(" %c", &estado);

        if (estado < 'A' || estado > 'H') {
            printf("Estado inválido. Tente novamente.\n");
            continue;
        }

        printf("Informe o número da cidade (1 a 4): ");
        scanf("%d", &cidadeNumero);

        if (cidadeNumero < 1 || cidadeNumero > 4) {
            printf("Número da cidade inválido. Tente novamente.\n");
            continue;
        }

        sprintf(cidades[totalCartas].codigo, "%c%02d", estado, cidadeNumero);

        // Entrada dos dados
        printf("População: ");
        scanf("%d", &cidades[totalCartas].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cidades[totalCartas].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cidades[totalCartas].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cidades[totalCartas].pontos_turisticos);

        totalCartas++;
        printf("\nCarta cadastrada com sucesso!\n");

        printf("\nDeseja cadastrar outra cidade? (S/N): ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's');

    printf("\nExibindo todas as cartas cadastradas:\n");
    for (int i = 0; i < totalCartas; i++) {
        exibirCidade(cidades[i]);
    }

    printf("Fim do programa. Obrigado por usar o sistema!\n");
    return 0;
}
