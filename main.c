#include "FilaDin.h"
#include <stdio.h>
#include <stdlib.h>
//imprimindo ao usuario o menu de opções
void menu() {
  printf("\n1-Adicionar elemento\n2-Consultar Elemento\n3-Apagar Elemento\n4-"
         "Apagar Fila\n5-Quantidade de itens\n6-Exibe a fila\n0-Sair\n");
}
int main(void) {
  //criando as variaveis do tipo inteiro e ponteiro
  int op;  int t;
  int Alunoi, Alunoj;
  int op2;
  Fila* aux;
  Elem* aux_elem;

  Fila *fi = cria_Fila(); // o ponteiro fi está recebendo a função cria_Fila.

  int x; //criando a variavel 
  do { // usando o laço de repetição do while para mostrar o menu
    
    menu(); //chamando a função menu
    scanf("%i", &op); //pedindo uma opção para o usuario e amarzenado em op.
    
    switch (op) {
      case 1: // caso a opção digitada for 1
        do {
          printf("Digite a matricula: ");//pedindo o numero de matricula ao usuario
          scanf("%i", &Alunoi); // armazenando
          x = insere_Fila(fi, Alunoi);// x está recebendo a função de inserir o elemento na fila (insere_Fila)
          if (x == 1) { //verificando se foi adicionado corretamente
            printf("\nSucesso!\n");
          } else {//senão foi irá apresentar a mensagem de erro a baixo
            printf("\nErro ao adicinar!\n");
          }
          printf("Deseja continuar? -3 para sair ");
          scanf("%i", &op2);
  
        } while (op2 != -3);// enquanto a op2 for diferente de -3 irá ficar no laço
  
        break;
  
      case 2: //caso para o usuario consultar 
        printf("Informe a matricula a ser consultada:");//mensagem mostrada na tela
        scanf("%i", &Alunoj);//armazenando oque o usuario digitou
        aux_elem = consulta_Elemento(fi, Alunoj); //aux_elem está recebendo a função de consultar elementos
        if (aux_elem  == NULL) { //se for igual a NULL a matricula não foi encontrar, e se for diferente ela foi encontrada 
          printf("\nMatrícula não encontrada!\n");
        } else {
          printf("\nMatricula encontrada em: %p !\n", &aux_elem);
        }
        break;
  
      case 3://opçao para o usuario remover
        printf("\nRemove matricula do inicio\n");
        x = remove_Fila(fi); //x está recebendo a função de remover
        if (x == 0) {//se for igual aparecera a menssagem de erro
          printf("\nErro ao remover ou fila vazia!\n");
  
        } else {
          printf("\nSucesso!\n");
        }
        break;
  
      case 4: // opção para apagar a fila
        libera_Fila(fi); // chamando a função de liberar
        printf("\nFILA APAGADA\n"); //menssagem mostrada ao usuario
        //depois que voce apaga a fila, tu nao cria uma nova mas volta pro loop, vai ter um erro de memoria
        //adicionar cria fila 
        fi = cria_Fila();
        break;
        
      case 5: //opção para informar o tamanho da fila
        t = tamanho_Fila(fi); // t está recebendo a função que calcula o tamanho
        printf ("\nTamanho da fila: %i\n", t);//mostrando o tamanho para o usuario
        break;
        
      case 6://opção para imprimir a fila
        ExibeFila(fi);//chamando a função de imprimir
        break;
        
      default:
        //opc'ao invalida.
        break;
    }
   
  } while (op != 0);//enquanto op for diferente de  irá ficar no laço
  libera_Fila(fi); //seja responsavel e libere seus lixo no fim do programa
  return 0;
}
