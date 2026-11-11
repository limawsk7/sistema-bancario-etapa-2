# sistema de Registro e Gestão de Contas Bancárias - Etapa 2

trabalho da disciplina INF101 - programação de Computadores I (UNIVIÇOSA).

## sobre o projeto

continuação da Etapa 1,agor o sistema aceita até 100 contas e guarda o histórico de movimentações(até 500)na memória,tudo foi feito dentro do `main()`, usando arrays, `switch`, `do while` e `for`.

como o histórico fica só na memória, ao fechar o programa as contas e as movimentações são perdidas,a persistência em arquivo fica para a Etapa 3.

## menu

Cadastrar conta
Listar contas
Consultar conta
Depositar
Sacar
Transferir
Extrato
Sair

## como funcionam as movimentações

| Código | Movimentação  | Efeito no saldo |
|--------|---------------|-----------------|
| D      | Depósito      | + valor         |
| S      | Saque         | - valor         |

a transferência gera dois registros no histórico: um `S` na conta de origem e um `D` na conta de destino.

##validações

o número da conta precisa ser maior que zero e não pode se repetir.
o saldo inicial não pode ser negativo.
o tipo da conta só pode ser 1 (Corrente) ou 2 (Poupança).
depósito, saque e transferência só funcionam em conta ativa e com valor positivo.
o saque e a transferência verificam se tem saldo suficiente.
a transferência confere se as duas contas existem e se há espaço para os 2 registros no histórico.


##autor

alice lima
