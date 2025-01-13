🎮 Nível Novato

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

🛡️ Nível Aventureiro

#include <stdio.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    float densidade_populacional; // Calculado: População / Área
    float pib_per_capita;         // Calculado: PIB / População
} Cidade;

// Função para calcular densidade populacional e PIB per capita
void calcular_propriedades(Cidade *cidade) {
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib / cidade->populacao;
}

// Função para exibir os dados de uma cidade
void exibir_cidade(const Cidade *cidade) {
    printf("\n=== Dados da Cidade ===\n");
    printf("Nome: %s\n", cidade->nome);
    printf("População: %d\n", cidade->populacao);
    printf("Área: %.2f km²\n", cidade->area);
    printf("PIB: %.2f bilhões\n", cidade->pib);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade->densidade_populacional);
    printf("PIB per Capita: %.2f bilhões/habitante\n", cidade->pib_per_capita);
}

int main() {
    int num_cidades;

    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &num_cidades);
    getchar(); // Limpa o buffer do teclado

    Cidade cidades[num_cidades];

    for (int i = 0; i < num_cidades; i++) {
        printf("\n=== Cadastro da Cidade %d ===\n", i + 1);

        printf("Nome da cidade: ");
        fgets(cidades[i].nome, sizeof(cidades[i].nome), stdin);
        cidades[i].nome[strcspn(cidades[i].nome, "\n")] = '\0'; // Remove o '\n' do final

        printf("População (em habitantes): ");
        scanf("%d", &cidades[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cidades[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cidades[i].pib);

        // Calcula as propriedades
        calcular_propriedades(&cidades[i]);
        getchar(); // Limpa o buffer do teclado
    }

    // Exibe as informações de todas as cidades
    for (int i = 0; i < num_cidades; i++) {
        exibir_cidade(&cidades[i]);
    }

    return 0;
}

🏆 Nível Mestre

#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char nome[50];
    double densidade_populacional;
    double area_territorial;
    double pib;
    double super_poder; // Soma de todas as propriedades
} Carta;

// Função para calcular o Super Poder
double calcular_super_poder(Carta *carta) {
    return carta->densidade_populacional + carta->area_territorial + carta->pib;
}

// Função para comparar as cartas
void comparar_cartas(Carta carta1, Carta carta2) {
    printf("\n--- Comparação entre %s e %s ---\n", carta1.nome, carta2.nome);

    // Comparando Densidade Populacional
    printf("Densidade Populacional: ");
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("%s venceu!\n", carta1.nome);
    } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    // Comparando Área Territorial
    printf("Área Territorial: ");
    if (carta1.area_territorial > carta2.area_territorial) {
        printf("%s venceu!\n", carta1.nome);
    } else if (carta1.area_territorial < carta2.area_territorial) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    // Comparando PIB
    printf("PIB: ");
    if (carta1.pib > carta2.pib) {
        printf("%s venceu!\n", carta1.nome);
    } else if (carta1.pib < carta2.pib) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    // Comparando Super Poder
    printf("Super Poder: ");
    if (carta1.super_poder > carta2.super_poder) {
        printf("%s venceu!\n", carta1.nome);
    } else if (carta1.super_poder < carta2.super_poder) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados para a primeira carta
    printf("Insira o nome da primeira carta: ");
    scanf("%s", carta1.nome);
    printf("Densidade Populacional: ");
    scanf("%lf", &carta1.densidade_populacional);
    printf("Área Territorial: ");
    scanf("%lf", &carta1.area_territorial);
    printf("PIB: ");
    scanf("%lf", &carta1.pib);
    carta1.super_poder = calcular_super_poder(&carta1);

    // Entrada de dados para a segunda carta
    printf("\nInsira o nome da segunda carta: ");
    scanf("%s", carta2.nome);
    printf("Densidade Populacional: ");
    scanf("%lf", &carta2.densidade_populacional);
    printf("Área Territorial: ");
    scanf("%lf", &carta2.area_territorial);
    printf("PIB: ");
    scanf("%lf", &carta2.pib);
    carta2.super_poder = calcular_super_poder(&carta2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}