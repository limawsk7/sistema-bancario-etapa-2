#include <iostream>
#include <string>
using namespace std;

int main() {
    // dados das contas
    const int MAX_CONTAS = 100; // limite maximo de contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];
    int quantidadeContas = 0;

    // historico de movimentacoes
    const int MAX_MOVIMENTACOES = 500;
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;

    int opcao;
    int numero, indice, indiceOrigem, indiceDestino;
    double valor;

    do {
        cout << "\n********************************" << endl;
        cout << "**        BANCO INF101        **" << endl;
        cout << "********************************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Listar contas" << endl;
        cout << "3 - Consultar conta" << endl;
        cout << "4 - Depositar" << endl;
        cout << "5 - Sacar" << endl;
        cout << "6 - Transferir" << endl;
        cout << "7 - Extrato" << endl;
        cout << "8 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: // cadastrar conta
                if (quantidadeContas == MAX_CONTAS) {
                    cout << "limite de contas atingido." << endl;
                    break;
                }

                cout << "Numero da conta: ";
                cin >> numero;
                while (numero <= 0) {
                    cout << "numero invalido, digite maior que zero: ";
                    cin >> numero;
                }

                // ve se ja existe uma conta com esse numero
                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }
                if (indice != -1) {
                    cout << "ja existe uma conta com esse numero." << endl;
                    break;
                }

                numeroConta[quantidadeContas] = numero;

                cin.ignore();
                cout << "nome do titular: ";
                getline(cin, nomeCliente[quantidadeContas]);

                cout << "CPF: ";
                getline(cin, cpf[quantidadeContas]);

                cout << "tipo da conta (1 = Corrente, 2 = Poupanca): ";
                cin >> tipoConta[quantidadeContas];
                while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                    cout << "tipo invalido, digite 1 ou 2: ";
                    cin >> tipoConta[quantidadeContas];
                }

                cout << "saldo inicial: ";
                cin >> saldo[quantidadeContas];
                while (saldo[quantidadeContas] < 0) {
                    cout << "saldo nao pode ser negativo: ";
                    cin >> saldo[quantidadeContas];
                }

                contaAtiva[quantidadeContas] = true;
                quantidadeContas++;
                cout << "conta cadastrada!" << endl;
                break;

            case 2: // listar contas
                if (quantidadeContas == 0) {
                    cout << "nenhuma conta cadastrada." << endl;
                } else {
                    for (int i = 0; i < quantidadeContas; i++) {
                        cout << "\nconta: " << numeroConta[i] << endl;
                        cout << "titular: " << nomeCliente[i] << endl;
                        cout << "saldo: R$ " << saldo[i] << endl;
                    }
                }
                break;

            case 3: // consultar conta pelo numero
                cout << "numero da conta: ";
                cin >> numero;

                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "conta nao encontrada." << endl;
                } else {
                    cout << "numero: " << numeroConta[indice] << endl;
                    cout << "titular: " << nomeCliente[indice] << endl;
                    cout << "CPF: " << cpf[indice] << endl;
                    if (tipoConta[indice] == 1) {
                        cout << "tipo: Corrente" << endl;
                    } else {
                        cout << "tipo: Poupanca" << endl;
                    }
                    cout << "saldo: R$ " << saldo[indice] << endl;
                    if (contaAtiva[indice]) {
                        cout << "situacao: Ativa" << endl;
                    } else {
                        cout << "situacao: Inativa" << endl;
                    }
                }
                break;

            case 4: // deposito
                cout << "numero da conta: ";
                cin >> numero;

                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "conta nao encontrada." << endl;
                } else if (!contaAtiva[indice]) {
                    cout << "conta inativa." << endl;
                } else if (quantidadeMovimentacoes == MAX_MOVIMENTACOES) {
                    cout << "historico cheio." << endl;
                } else {
                    cout << "valor do deposito: ";
                    cin >> valor;
                    if (valor <= 0) {
                        cout << "valor invalido." << endl;
                    } else {
                        saldo[indice] = saldo[indice] + valor;
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        cout << "deposito realizado!" << endl;
                    }
                }
                break;

            case 5: // saque
                cout << "numero da conta: ";
                cin >> numero;

                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "conta nao encontrada." << endl;
                } else if (!contaAtiva[indice]) {
                    cout << "conta inativa." << endl;
                } else if (quantidadeMovimentacoes == MAX_MOVIMENTACOES) {
                    cout << "historico cheio." << endl;
                } else {
                    cout << "valor do saque: ";
                    cin >> valor;
                    if (valor <= 0) {
                        cout << "valor invalido." << endl;
                    } else if (valor > saldo[indice]) {
                        cout << "saldo insuficiente." << endl;
                    } else {
                        saldo[indice] = saldo[indice] - valor;
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        cout << "saque realizado!" << endl;
                    }
                }
                break;

            case 6: // transferencia
                cout << "numero da conta de origem: ";
                cin >> numero;
                indiceOrigem = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indiceOrigem = i;
                    }
                }

                cout << "numero da conta de destino: ";
                cin >> numero;
                indiceDestino = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indiceDestino = i;
                    }
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "conta nao encontrada." << endl;
                } else if (indiceOrigem == indiceDestino) {
                    cout << "as contas precisam ser diferentes." << endl;
                } else if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                    cout << "uma das contas esta inativa." << endl;
                } else if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                    cout << "historico sem espaco." << endl;
                } else {
                    cout << "valor da transferencia: ";
                    cin >> valor;
                    if (valor <= 0) {
                        cout << "valor invalido." << endl;
                    } else if (valor > saldo[indiceOrigem]) {
                        cout << "saldo insuficiente." << endl;
                    } else {
                        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
                        saldo[indiceDestino] = saldo[indiceDestino] + valor;

                        // saida na origem
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;

                        // entrada no destino
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;

                        cout << "transferencia realizada!" << endl;
                    }
                }
                break;

            case 7: // extrato
                cout << "numero da conta: ";
                cin >> numero;

                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "conta nao encontrada." << endl;
                } else {
                    cout << "\n--- extrato da conta " << numero << " ---" << endl;
                    for (int i = 0; i < quantidadeMovimentacoes; i++) {
                        if (contaMovimentacao[i] == numero) {
                            if (tipoMovimentacao[i] == 'D') {
                                cout << "deposito: R$ " << valorMovimentacao[i] << endl;
                            } else if (tipoMovimentacao[i] == 'S') {
                                cout << "saque: R$ " << valorMovimentacao[i] << endl;
                            }
                        }
                    }
                    cout << "saldo atual: R$ " << saldo[indice] << endl;
                }
                break;

            case 8:
                cout << "saindo..." << endl;
                break;

            default:
                cout << "opcao invalida." << endl;
        }

    } while (opcao != 8);

    return 0;
}
