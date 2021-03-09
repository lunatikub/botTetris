#ifndef __TETRIMINO__
#define __TETRIMINO__

#define ROTATION 4
#define TETRIMINO_SZ 4

#include <stdbool.h>
#include <stdint.h>

typedef enum {
  TETRIMINO_I = 1,
  TETRIMINO_J,
  TETRIMINO_L,
  TETRIMINO_O,
  TETRIMINO_T,
  TETRIMINO_S,
  TETRIMINO_Z,
} tetrimino_t;

struct rotation {
  uint8_t blocks[TETRIMINO_SZ][TETRIMINO_SZ]; /* Rotation's blocks. */
  uint8_t holes[TETRIMINO_SZ]; /* Holes of each column. */
  uint8_t height_col[TETRIMINO_SZ]; /* Height of each column. */
  uint8_t block_line[TETRIMINO_SZ]; /* Number of blocks by line. */
  uint8_t height; /* Height of the roration. */
  uint8_t width; /* Width of the rotation. */
};

struct tetrimino {
  const struct rotation *rotations[ROTATION];
  uint8_t nr_rotation;
};

/**
 * Return the tetrimino instance from the type.
 */
const struct tetrimino* tetrimino_get(tetrimino_t t);

/**
 * Return the rotation instance from the type and the rotation number.
 */
const struct rotation* rotation_get(tetrimino_t t, uint8_t rotation);

#endif /* !__TETRIMINO__ */
