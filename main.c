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
  } else if (line == 0 && matrix[line + 1][column] != 0 && matrix[line][column] == 1) {
    printf("\u252C");
  //Borda superior intermediaria sem barreira
  } else if (line == 0 && matrix[line + 1][column] == 0 && matrix[line][column] == 1) {
    printf("\u2500");
  //Borda inferior intermediaria com barreira
  } else if (line == LINE - 1 && matrix[line - 1][column] != 0 && matrix[line][column] == 1) {
    printf("\u2534");
  //Borda inferior intermediaria sem barreira
  } else if (line == LINE - 1 && matrix[line - 1][column] == 0 && matrix[line][column] == 1) {
    printf("\u2500");
  //Borda intermediaria da esquerda com barreira
  } else if (column == 0 && matrix[line][column + 1] != 0 && matrix[line][column] == 1) {
    printf("\u251C");
  //Borda intermediaria da esquerda sem barreira
  } else if (column == 0 && matrix[line][column + 1] == 0 && matrix[line][column] == 1) {
    printf("\u2502");
  //Borda intermediaria da direita com barreira
  } else if (column == COLUMN - 1 && matrix[line][column - 1] != 0 && matrix[line][column] == 1) {
    printf("\u2524\n");
  //Borda intermediaria da direita sem barreira
  } else if (column == COLUMN - 1 && matrix[line][column - 1] == 0 && matrix[line][column] == 1) {
    printf("\u2502\n");
  } else {
    printf(" ");
  }
  
}

void printMatrix () {
  for (int line = 0; line < LINE; line++) {
    for (int column = 0; column < COLUMN; column++) {
      //printf("%d", matrix[line][column]);
      printElement(line, column);
    }
    //printf("\n");
  }
}

int main () {
  int random = 0;
  srand(time(NULL));
  //Zerando a matriz
  for (int line = 0; line < LINE; line++) {
    for (int column = 0; column < COLUMN; column++) {
      if (line == 0 || column == 0 || line == LINE - 1 || column == COLUMN - 1) {
	matrix[line][column] = 1;
      } else {
	matrix[line][column] = 0;
      }
    }
  }
  //Gera um numero aleatorio para a entrada entre 1 e LINE - 1
  random = (rand() % (LINE - 2)) + 1;

  matrix[random][0] = 0;
  printMatrix();
  return 0;
}
