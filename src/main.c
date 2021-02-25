#include "tetrimino.h"

#include <stdio.h>

int main(void)
{
  const struct tetrimino *I = tetrimino_get(TETRIMINO_I);


  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%u ", I->rotations[0]->blocks[i][j]);
    }
    printf("\n");
  }

  return 0;
}
