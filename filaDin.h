#ifndef LISTA_H
#define LISTA_H
/* Definindo uma estrutura do tipo fila, que carrega dois ponteiros do tipo elemento que irá guardar a posição inicial e final do elemento da fila.
*/
struct fila {
  struct elemento *inicio; 
  struct elemento *final;
};
/*Definindo uma estrutura do tipo elemento, que contém duas variaveis, uma do tipo inteiro dados e outra do tipo ponteiro elemento *prox que armazena o proximo elemento da fila. Essa estrutura é o tipo de dado que representa um elemento da fila*/
struct elemento {
  int dados;
  struct elemento *prox;
};

// struct aluno{
//   int matricula;
// };
typedef struct fila Fila; //atribuindo um "apelido para fila" .
typedef struct elemento Elem; //atribuindo um "apelido" para elemento.

Fila* cria_Fila(); //chamando a função 
//criando o cabeçalho das funções
void libera_Fila(Fila* fi); 
void ExibeFila(Fila* fi);
int tamanho_Fila(Fila* fi);
int insere_Fila(Fila* fi, int al);
int remove_Fila(Fila* fi);
int consulta_Fila(Fila* fi, int al);
Elem* consulta_Elemento(Fila* fi, int al);

#endif
