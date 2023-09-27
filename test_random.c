#include <stdio.h>
#include <stdlib.h>

#include "random.h"

int main() {
  int seed = 0xdeadbeef;

  srand(seed);
  my_srandom(seed);

  for (int i = 0; i < 10; i++) {
    int glibc = rand();
    int my_lib = my_random();

    printf("%d, %d\n", glibc, my_lib);
    if(glibc != my_lib) {
      printf("[%d] expected %x, but got %x", i, glibc, my_lib);
    }
  }
}
