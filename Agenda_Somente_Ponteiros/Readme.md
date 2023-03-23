Igor Gomes Dutra

Algoritimos e Estrutura de Dados 1, Turma M1

• Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
    - Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
        - Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
        - Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
    - Não pode usar struct em todo o programa.
    - Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
    - Implementar a base de dados da agenda usando lista duplamente ligada
        - Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.


contém:
 -> src/main.c: switch dentro de um loop para rodar o código até a opção de sair ser selecionada
 -> src/library.c: todas as funções para rodar o código, comentado o máximo possível para explicar o que aconteçe no código.

Regras de Código: https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf

Video Link: TBD

Organização dos pointeiros void:

Head: int quantidade, void *front, void *back

Node: char[11] nome, char[14] telefone, int idade, void *prev, void *next

pBuffer: int choice, char [11] nameToSearch
