#include <stdio.h>
#include <cs50.h>

int main(void) {
  string name = get_string("hello %s", "you");
  printf("hello, %s\n", name);
}
