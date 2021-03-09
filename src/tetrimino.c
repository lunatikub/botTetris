#include <stdlib.h>
#include <assert.h>

#include "tetrimino.h"

#include "tetrimino_I.h"
#include "tetrimino_L.h"
#include "tetrimino_J.h"
#include "tetrimino_O.h"
#include "tetrimino_T.h"
#include "tetrimino_S.h"
#include "tetrimino_Z.h"

const struct tetrimino* tetrimino_get(tetrimino_t t)
{
  switch (t) {
    case TETRIMINO_I:
      return &tetrimino_I;
    case TETRIMINO_J:
      return &tetrimino_J;
    case TETRIMINO_L:
      return &tetrimino_L;
    case TETRIMINO_O:
      return &tetrimino_O;
    case TETRIMINO_T:
      return &tetrimino_T;
    case TETRIMINO_S:
      return &tetrimino_S;
    case TETRIMINO_Z:
      return &tetrimino_Z;
  };
  assert(!"tetrimino unknown...");
}

const struct rotation* rotation_get(tetrimino_t t, uint8_t rotation)
{
  const struct tetrimino *tetri = tetrimino_get(t);
  assert(rotation < tetri->nr_rotation);
  return tetri->rotations[rotation];
}
