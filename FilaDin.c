#include "FilaDin.h"
#include <stdio.h>
#include <stdlib.h>

void ExibeFila(Fila* fi){
  Elem* atual = fi->inicio; //está recebendo o inicio da fila
  int i = 0; //atribuindo 0 a variavel inteira i
  printf("\n********** Comeco da Fila **********"); //mostrando na tela
  
  while (atual!=NULL){ // enquanto for diferente
    printf("\n\t Indice: %i | Matricula: %i",i, atual->dados); //mostrando os dados na tela
    i++; //incrementando mais 1 em i
    atual = atual->prox; //atual está recebendo o proximo elemento
  }
  
  printf("\n********** Final da Fila **********\n");//mostrando na tela
}


Fila *cria_Fila() {
  Fila *fi = (Fila*)malloc(sizeof(Fila)); // Usando a função malloc para alocar memoria do ponteiro fila.
  if (fi != NULL) {  // Verificador para saber se deu certo a alocação. Se o fi for diferente de NULL é por que deu certo a alocação.
    fi->final = NULL; //Se isso ocorrer final e inicio recebem NULL.
    fi->inicio = NULL;
  }
  return fi; //retorna fi
}

void libera_Fila(Fila *fi) {
  if (fi != NULL) {  //Verificando se a fila é diferente de NULL (Nulo), se for igual a NULL deu problema na alocação
    Elem *no; // se a alocação for feita de forma certa, será criado um ponteiro 'no' do tipo Elem. 
    while (fi->inicio != NULL) { //Verificando se o inicio é diferente de NULL.
      no = fi->inicio; // Se inicio for diferente de NULL o 'no' vai receber o inicio
      fi->inicio = fi->inicio->prox; // o inicio vai apontar para o próximo elemento
      free(no); // liberando o 'no', isso será feito enquanto tiver elementos na fila.
    }
    free(fi); // se o inicio está em NULL, o fi será liberado
  }
}

Elem* consulta_Elemento(Fila* fi, int al){
  Elem *no = fi -> inicio; //'no' recebe o inicio da fila
  while (no!=NULL){ //se o 'no' for diferente de NULL
    if (no -> dados == al){ // copio os dados do aluno para o campo de dados do 'no'.
      return no; //returno 'no'
    }
      no = no->prox; //'no' está recebendo o proximo elemento
  }
  return no; // returnando 'no'
}
//Função para saber o tamanho da fila
int tamanho_Fila(Fila *fi) { // recebe parametros do tipo fila ponteiro
  if (fi == NULL) { // Se for valida retorna 0.
    return 0;
  }
  int cont = 0; // A variavel contadora (cont) recebe 0, cont vai contar quantos elementos existem na fila
  Elem *no = fi->inicio; // Criação de um  'no' do tipo Elem que vai auxiliar recebendo o início da fila
  while (no != NULL) { //enquanto 'no' for diferente de NULL
    cont++;  // A variavel cont será somada mais 1.
    no = no->prox; // Movendo o 'no' para frente, atribuindo o proximo elemento a ele
  }
  return cont; // Retorno da função que retorna o número de elementos que eu contei dentro da fila.
}

int insere_Fila(Fila *fi, int al) {
  if (fi == NULL) { //verifica se é igual a NULL, se for igual é que deu problema na alocação
    return 0;//irá retornar 0
  }
  Elem *no = (Elem *)malloc(sizeof(Elem));//aloco um elemento chamado 'no'. Alocando memoria para um novo elemento da fila
  if (no == NULL) { //Verificando se a alocação deu certo, se não deu retornará 0.
    return 0;
  }
  no->dados = al; //Se deu certo a alocação, copio os dados do aluno para o campo de dados do 'no'.
  no->prox = NULL; //prox recebe null, nesse caso o elemento que acabamos de inserir irá apontar para NULL por que ele é o ultimo elemento da fila inserido
  if (fi->final == NULL) {//Se o final da fila for igual a NULL, a fila está vazia.
    fi->inicio = no;//Se não tem nada na fila o inicio vai receber o 'no'
  } else {
    fi->final->prox = no;//senão, o final que aponta para prox irá apontar para o 'no'
  }
  fi->final = no;//final passa a apontar para o 'no'.
  return 1;//returno igual a 1.
}

int remove_Fila(Fila* fi){
  if (fi == NULL){ //verifica fila para ver se está vazia
    return 0; // fila vazia
  }
  if (fi -> inicio == NULL){ //fila vazia
    return 0;
  } 
  Elem *no = fi -> inicio; // Crio um "no" auxiliar que recebe o início da "fila".
  fi -> inicio = fi -> inicio -> prox; //O início da "fila" passa a apontar para o próximo elemento.
  if (fi -> inicio ==NULL){//Verificando se o início é igual a NULL
    fi -> final = NULL;//Se for, a "fila" ficou vazia, e o final passa a ser NULL.
  }
  free (no); // liberando o 'no'
  return 1;
}
