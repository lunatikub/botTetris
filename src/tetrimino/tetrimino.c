#include <stdlib.h>
#include <assert.h>

#include "tetrimino.h"

#include "tetrimino_I.h"
#include "tetrimino_J.h"
#include "tetrimino_O.h"
#include "tetrimino_T.h"
#include "tetrimino_Z.h"

const struct tetrimino* tetrimino_get(enum tetrimino_type type)
{
  switch (type) {
    case TETRIMINO_I:
      return &tetrimino_I;
    case TETRIMINO_J:
      return &tetrimino_J;
    case TETRIMINO_O:
      return &tetrimino_O;
    case TETRIMINO_T:
      return &tetrimino_T;
    case TETRIMINO_Z:
      return &tetrimino_Z;
  };
  assert(!"tetrimino unknown...");
}

const struct rotation* rotation_get(enum tetrimino_type type, uint8_t rotation)
{
  const struct tetrimino *t = tetrimino_get(type);
  assert(rotation < t->nr_rotation);
  return t->rotations[rotation];
}
