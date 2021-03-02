#include "field.h"

int main(void)
{
  struct field *f = field_new(20, 10);

  field_destroy(f);

  return 0;
}
