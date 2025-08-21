#include <stdio.h>
#include <string.h> // Para manipulação de strings, se necessário

// Define a estrutura para armazenar os dados de uma carta
typedef struct {
    char nome[50];
    char estado[3]; // Ex: "SP", "RJ" + caractere nulo '\0'
    char codigo[10];
    unsigned long int populacao; // MUDANÇA: unsigned long int para acomodar números maiores
    float area;
    double pib;
    int pontos_turisticos;

    // Campos calculados
    float densidade_populacional;
    double pib_per_capita;
    float super_poder;
} Carta;

// Protótipo da função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Declara duas variáveis do tipo Carta
    Carta carta1, carta2;

    // --- LEITURA DOS DADOS DA CARTA 1 ---
    printf("--- Inserir dados da Carta 1 ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", carta1.nome); // Lê strings com espaços
    limpar_buffer();

    printf("Estado (sigla, ex: SP): ");
    scanf(" %[^\n]", carta1.estado);
    limpar_buffer();

    printf("Código: ");
    scanf(" %[^\n]", carta1.codigo);
    limpar_buffer();

    printf("População: ");
    scanf("%lu", &carta1.populacao); // %lu para unsigned long int

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &carta1.pib); // %lf para double

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    limpar_buffer(); // Limpa o buffer para a próxima leitura de string

    printf("\n");

    // --- LEITURA DOS DADOS DA CARTA 2 ---
    printf("--- Inserir dados da Carta 2 ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", carta2.nome);
    limpar_buffer();

    printf("Estado (sigla, ex: RJ): ");
    scanf(" %[^\n]", carta2.estado);
    limpar_buffer();

    printf("Código: ");
    scanf(" %[^\n]", carta2.codigo);
    limpar_buffer();

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // --- CÁLCULOS PARA A CARTA 1 ---
    // Evita divisão por zero se a área for 0
    if (carta1.area > 0) {
        carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidade_populacional = 0;
    }

    // Evita divisão por zero se a população for 0
    if (carta1.populacao > 0) {
        carta1.pib_per_capita = carta1.pib / carta1.populacao;
    } else {
        carta1.pib_per_capita = 0;
    }
    
    // Cálculo do Super Poder (atenção aos tipos)
    // O C promove os tipos para o maior tipo na expressão (double) durante o cálculo
    carta1.super_poder = (float)(
        (double)carta1.populacao +
        carta1.area +
        carta1.pib +
        carta1.pontos_turisticos +
        carta1.pib_per_capita +
        (1.0f / carta1.densidade_populacional) // Inverso da densidade
    );


    // --- CÁLCULOS PARA A CARTA 2 ---
    if (carta2.area > 0) {
        carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidade_populacional = 0;
    }

    if (carta2.populacao > 0) {
        carta2.pib_per_capita = carta2.pib / carta2.populacao;
    } else {
        carta2.pib_per_capita = 0;
    }

    carta2.super_poder = (float)(
        (double)carta2.populacao +
        carta2.area +
        carta2.pib +
        carta2.pontos_turisticos +
        carta2.pib_per_capita +
        (1.0f / carta2.densidade_populacional)
    );

    // --- EXIBIÇÃO DOS RESULTADOS E COMPARAÇÕES ---
    printf("\n----------------------------------------\n");
    printf("       DADOS CALCULADOS\n");
    printf("----------------------------------------\n");
    printf("Carta 1 (%s):\n", carta1.nome);
    printf("  - Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("  - PIB per Capita: %.2f\n", carta1.pib_per_capita);
    printf("  - Super Poder: %.2f\n\n", carta1.super_poder);

    printf("Carta 2 (%s):\n", carta2.nome);
    printf("  - Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("  - PIB per Capita: %.2f\n", carta2.pib_per_capita);
    printf("  - Super Poder: %.2f\n", carta2.super_poder);
    printf("----------------------------------------\n\n");

    printf("Comparação de Cartas:\n");

    // A comparação (ex: carta1.populacao > carta2.populacao) resulta em 1 (verdadeiro) ou 0 (falso).
    // Usamos o operador ternário (condição ? valor_se_verdadeiro : valor_se_falso) para imprimir qual carta venceu.
    
    int c1_vence; // Variável para armazenar o resultado da comparação (1 ou 0)

    // População: maior vence
    c1_vence = carta1.populacao > carta2.populacao;
    printf("População: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // Área: maior vence
    c1_vence = carta1.area > carta2.area;
    printf("Área: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // PIB: maior vence
    c1_vence = carta1.pib > carta2.pib;
    printf("PIB: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // Pontos Turísticos: maior vence
    c1_vence = carta1.pontos_turisticos > carta2.pontos_turisticos;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // Densidade Populacional: MENOR vence
    c1_vence = carta1.densidade_populacional < carta2.densidade_populacional;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // PIB per Capita: maior vence
    c1_vence = carta1.pib_per_capita > carta2.pib_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    // Super Poder: maior vence
    c1_vence = carta1.super_poder > carta2.super_poder;
    printf("Super Poder: Carta %d venceu (%d)\n", c1_vence ? 1 : 2, c1_vence);

    return 0;
}