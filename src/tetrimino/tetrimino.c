#include <stdlib.h>
#include <assert.h>

#include "tetrimino.h"

#include "tetrimino_I.h"

const struct tetrimino* tetrimino_get(enum tetrimino_type type)
{
  switch (type) {
    case TETRIMINO_I:
      return &tetrimino_I;
  };
  assert(!"tetrimino unknown...");
}

const struct rotation* rotation_get(enum tetrimino_type type, uint8_t rotation)
{
  const struct tetrimino *t = tetrimino_get(type);
  assert(rotation < t->nr_rotation);
  return t->rotations[rotation];
}
