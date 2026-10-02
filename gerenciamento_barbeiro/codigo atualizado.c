#include <stdio.h>
#include <string.h>

int main() {

    // SERVICOS
    char nomeServico[20][50];
    float valorServico[20];

    int quantidadeServicos = 0;
    int opcao = 0;

    while (opcao != 5) {

        printf("\n===== AREA GERENCIAL =====\n");
        printf("1 - Cadastrar servico\n");
        printf("2 - Exibir servicos\n");
        printf("3 - Editar servico\n");
        printf("4 - Excluir servico\n");
        printf("5 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        // ==========================================
        // CADASTRAR SERVICO
        // ==========================================

        if (opcao == 1) {

            if (quantidadeServicos >= 20) {

                printf("\nLimite de servicos atingido!\n");

            } else {

                printf("\n===== CADASTRO DE SERVICO =====\n");

                printf("Digite o nome do servico:\n");
                scanf(" %49[^\n]", nomeServico[quantidadeServicos]);

                printf("Digite o valor do servico:\n");
                scanf("%f", &valorServico[quantidadeServicos]);

                quantidadeServicos++;

                printf("\nServico cadastrado com sucesso!\n");
            }
        }


        // ==========================================
        // EXIBIR SERVICOS
        // ==========================================

        else if (opcao == 2) {

            printf("\n===== SERVICOS CADASTRADOS =====\n");

            if (quantidadeServicos == 0) {

                printf("Nenhum servico cadastrado.\n");

            } else {

                for (int i = 0; i < quantidadeServicos; i++) {

                    printf("\nID: %d\n", i + 1);
                    printf("Servico: %s\n", nomeServico[i]);
                    printf("Valor: R$ %.2f\n", valorServico[i]);
                }
            }
        }


        // ==========================================
        // EDITAR SERVICO
        // ==========================================

        else if (opcao == 3) {

            int id;

            printf("\n===== EDITAR SERVICO =====\n");

            if (quantidadeServicos == 0) {

                printf("Nenhum servico cadastrado.\n");

            } else {

                printf("Digite o ID do servico que deseja editar:\n");
                scanf("%d", &id);

                if (id < 1 || id > quantidadeServicos) {

                    printf("ID invalido!\n");

                } else {

                    int posicao = id - 1;

                    printf("\nServico atual:\n");
                    printf("Nome: %s\n", nomeServico[posicao]);
                    printf("Valor: R$ %.2f\n", valorServico[posicao]);

                    printf("\nDigite o novo nome do servico:\n");
                    scanf(" %49[^\n]", nomeServico[posicao]);

                    printf("Digite o novo valor do servico:\n");
                    scanf("%f", &valorServico[posicao]);

                    printf("\nServico editado com sucesso!\n");
                }
            }
        }


        // ==========================================
        // EXCLUIR SERVICO
        // ==========================================

        else if (opcao == 4) {

            int id;

            printf("\n===== EXCLUIR SERVICO =====\n");

            if (quantidadeServicos == 0) {

                printf("Nenhum servico cadastrado.\n");

            } else {

                printf("Digite o ID do servico que deseja excluir:\n");
                scanf("%d", &id);

                if (id < 1 || id > quantidadeServicos) {

                    printf("ID invalido!\n");

                } else {

                    int posicao = id - 1;

                    // Move os servicos seguintes uma posicao para tras
                    for (int i = posicao; i < quantidadeServicos - 1; i++) {

                        strcpy(nomeServico[i], nomeServico[i + 1]);
                        valorServico[i] = valorServico[i + 1];
                    }

                    quantidadeServicos--;

                    printf("\nServico excluido com sucesso!\n");
                }
            }
        }


        // ==========================================
        // SAIR
        // ==========================================

        else if (opcao == 5) {

            printf("\nSaindo da area gerencial...\n");

        }


        // ==========================================
        // OPCAO INVALIDA
        // ==========================================

        else {

            printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}
