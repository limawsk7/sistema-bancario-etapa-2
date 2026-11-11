# Sistema de Registro e Gestão de Contas Bancárias - Etapa 2

Trabalho da disciplina INF101 - Programação de Computadores I (UNIVIÇOSA).

## Sobre o projeto

Continuação da Etapa 1. Agora o sistema aceita até 100 contas e guarda o histórico de movimentações (até 500) na memória. Tudo foi feito dentro do `main()`, usando arrays, `switch`, `do while` e `for`.

Como o histórico fica só na memória, ao fechar o programa as contas e as movimentações são perdidas. A persistência em arquivo fica para a Etapa 3.

## Menu

1. Cadastrar conta
2. Listar contas
3. Consultar conta
4. Depositar
5. Sacar
6. Transferir
7. Extrato
8. Sair

## Como funcionam as movimentações

| Código | Movimentação  | Efeito no saldo |
|--------|---------------|-----------------|
| D      | Depósito      | + valor         |
| S      | Saque         | - valor         |

A transferência gera dois registros no histórico: um `S` na conta de origem e um `D` na conta de destino.

## Validações

- O número da conta precisa ser maior que zero e não pode se repetir.
- O saldo inicial não pode ser negativo.
- O tipo da conta só pode ser 1 (Corrente) ou 2 (Poupança).
- Depósito, saque e transferência só funcionam em conta ativa e com valor positivo.
- O saque e a transferência verificam se tem saldo suficiente.
- A transferência confere se as duas contas existem e se há espaço para os 2 registros no histórico.

## Como rodar

Pelo terminal:

```
g++ banco.cpp -o banco
./banco
```

Ou é só colar o código do `banco.cpp` no [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler) e clicar em Run.

## Autor

Seu nome aqui
