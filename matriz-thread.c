/* Autor: Carlos Alberto de Araujo Barreto
   Disciplina: Sistemas operacionais
   Descrição: Programa com uso de threads implementadas na soma de 2 arrays atribuindo para outro array
     Ao longo do programa é desenvolvida uma técnica de validação do término das threads através de variáveis flags
     para poder verificar se a soma terminou antes da impressão em tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LIN 10
#define COL 10

// Variáveis globais para serem visíveis as threads da aplicação
int m1[LIN][COL];
int m2[LIN][COL];
int m3[LIN][COL];
int flag1 = 0;
int flag2 = 0;

// Thread de soma da metade da matriz, onde é somada todas as colunas da linha 0 até a linha 4
void *threadSoma1()
{
  int i, j;
  for(i = 0; i < (LIN/2); i++)
    for(j = 0; j < COL; j++)
    {
      m3[i][j] = m1[i][j] + m2[i][j];
      printf(" t1 ");
    }
  // Flag de controle do término da thread
  flag1 = 1;
}

// Thread de soma da metade da matriz, onde é somada todas as colunas da linha 0 até a linha 4
void *threadSoma2()
{
  int i, j;
  for(i = (LIN/2); i < LIN; i++)
    for(j = 0; j < COL; j++)
    {
      m3[i][j] = m1[i][j] + m2[i][j];
      printf(" t2 ");
    }
  // Flag de controle do término da thread
  flag2= 1;
}


int main()
{
  int i, j, execute;
  pthread_t thread1, thread2;

  srand(getpid());

  for(i = 0; i < COL; i++)
    for(j = 0; j < COL; j++)
    {
      m1[i][j] = rand() % 9;
      m2[i][j] = rand() % 9;
      m3[i][j] = 0;
    }
  
  // A soma é dividida em 2 threads, cada um soma uma metade da matriz
  execute = pthread_create(&thread1, NULL, threadSoma1, NULL);
  execute = pthread_create(&thread2, NULL, threadSoma2, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // A impressão em tela depende de todas as threads serem sincronizadas para poder exibir os valores somados antes
  printf("\n");

  // Neste loop temos o controle das flags de encerramento das threads
  // Enquanto não terminar as duas threads o código vai ficar preso neste loop antes de imprimir os dados em tela
  while(!flag1 && !flag2);

  for(i = 0; i < LIN; i++)
  {
    for(j = 0; j < COL; j++)
      printf("%d ", m1[i][j]);
    printf("\t");

    for(j = 0; j < COL; j++)
      printf("%d ", m2[i][j]);
    printf("\t"); 
 
    for(j = 0; j < COL; j++)
      printf("%2d ", m3[i][j]);
    printf("\n"); 

  }
  printf("\n");

  return 0;
}
