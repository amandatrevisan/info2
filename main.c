#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 20
#define COLUMN 40

int matrix[LINE][COLUMN];

//https://en.wikipedia.org/wiki/Box-drawing_character#Unicode
void printElement(int line, int column) {
  //Borda superior esquerda
  if(line == 0 && column == 0 && matrix[line][column] == 1) {
    printf("\u250C");
  //Borda inferior direita
  } else if (line == LINE - 1 && column == COLUMN - 1 && matrix[line][column] == 1) {
    printf("\u2518\n");
  //Borda inferior esquerda
  } else if (line == LINE - 1 && column == 0 && matrix[line][column] == 1) {
    printf("\u2514");
  //Borda superior direita
  } else if (line == 0 && column == COLUMN - 1 && matrix[line][column] == 1) {
    printf("\u2510\n");
  //Borda superior intermediaria com barreira
  } else if (line == 0 && matrix[line + 1][column] == 1 && matrix[line][column] == 1) {
    printf("\u252C");
  //Borda superior intermediaria sem barreira
  } else if (line == 0 && matrix[line + 1][column] != 1 && matrix[line][column] == 1) {
    printf("\u2500");
  //Borda inferior intermediaria com barreira
  } else if (line == LINE - 1 && matrix[line - 1][column] == 1 && matrix[line][column] == 1) {
    printf("\u2534");
  //Borda inferior intermediaria sem barreira
  } else if (line == LINE - 1 && matrix[line - 1][column] != 1 && matrix[line][column] == 1) {
    printf("\u2500");
  //Borda intermediaria da esquerda com barreira
  } else if (column == 0 && matrix[line][column + 1] == 1 && matrix[line][column] == 1) {
    printf("\u251C");
  //Borda intermediaria da esquerda sem barreira
  } else if (column == 0 && matrix[line][column + 1] != 1 && matrix[line][column] == 1) {
    printf("\u2502");
  //Borda intermediaria da direita com barreira
  } else if (column == COLUMN - 1 && matrix[line][column - 1] == 1 && matrix[line][column] == 1) {
    printf("\u2524\n");
  //Borda intermediaria da direita sem barreira
  } else if (column == COLUMN - 1 && matrix[line][column - 1] != 0 && matrix[line][column] == 1) {
    printf("\u2502\n");
  } else if (matrix[line][column] == 1) {
    if (matrix[line - 1][column] == 1 && matrix[line + 1][column] == 1 && matrix[line][column - 1] == 1  && matrix[line][column + 1] == 1) {
      printf("\u253C");
    } else if (matrix[line + 1][column] == 1 && matrix[line][column - 1] == 1 && matrix[line][column + 1] == 1) {
      printf("\u252C");
    } else if (matrix[line - 1][column] == 1 && matrix[line][column - 1] == 1 && matrix[line][column + 1] == 1) {
      printf("\u2534");
    } else if (matrix[line - 1][column] == 1 && matrix[line + 1][column] == 1 && matrix[line][column + 1] == 1) {
      printf("\u251C");
    } else if (matrix[line - 1][column] == 1 && matrix[line + 1][column] == 1 && matrix[line][column - 1] == 1) {
      printf("\u2524");
    } else if (matrix[line + 1][column] == 1 && matrix[line][column + 1] == 1) {
      printf("\u250C");
    } else if (matrix[line - 1][column] == 1 && matrix[line][column + 1] == 1) {
      printf("\u2514");
    } else if (matrix[line + 1][column] == 1 && matrix[line][column - 1] == 1) {
      printf("\u2510");
    } else if (matrix[line][column - 1] == 1 && matrix[line][column + 1] == 1) {
      printf("\u2500");
    } else if (matrix[line - 1][column] == 1 && matrix[line + 1][column] == 1) {
      printf("\u2502");
    } else if (matrix[line - 1][column] == 1 && matrix[line][column - 1] == 1) {
      printf("\u2519");
    }
  } else {
      printf(" ");
  }
}

//imprimir matrix do jogo
void printMatrix () {
  for (int line = 0; line < LINE; line++) {  //vare toda as linhas (vai do 0 até LINE -1)
    for (int column = 0; column < COLUMN; column++) { //vare toda as colunas (vai do 0 até COLUMN -1)
      //printf("%d", matrix[line][column]); //debug
      printElement(line, column); //formatar com os caracteres especiais definidos lá em cima
    }
    //printf("\n"); //debug
  }
}

void generateMaze (int line, int column) { //https://en.wikipedia.org/wiki/Maze_generation_algorithm#Python_code_examples
  int destinations[4] = {0,0,0,0};
  int sum = 0;
  if (line - 1 >= 0 && matrix[line - 1][column] == 10) {
    destinations[0] = 1;
    sum++;
  }
  if (line + 1 < LINE && matrix[line + 1][column] == 10) {
    destinations[1] = 1;
    sum++;
  }
  if (column - 1 >= 0 && matrix[line][column - 1] == 10) {
    destinations[2] = 1;
    sum++;
  }
  if (column + 1 < COLUMN && matrix[line][column + 1] == 10) {
    destinations[3] = 1;
    sum++;
  }
}

int main () {
  int random = 0; //random é uma variavel que será sorteada para definir a entrada
  srand(time(NULL)); //essa é a "semente" de gerador aleatorio, (semente é o numero para geração dos proximos aleatórios.)
  for (int line = 0; line < LINE; line++) {  //Zerando a matriz
    for (int column = 0; column < COLUMN; column++) {
      if (line == 0 || column == 0 || line == LINE - 1 || column == COLUMN - 1) { //isso é o que gera todas as bordas, desenhando.
	matrix[line][column] = 1;
      } else {
	matrix[line][column] = 10; //é o que deixa tudo dentro do labirinto vazio, 10 espaçõ não inicializado
      }
    }
  }
  random = (rand() % (LINE - 2)) + 1; //Gera um numero aleatorio para a entrada entre 1 e LINE - 1

  matrix[random][0] = 0; //abrir entrada, pois 0 é campo vazio.
  printMatrix(); //imprimir o labirinto
  return 0;
}
