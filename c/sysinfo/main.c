#include "header.h"
#include <stdio.h>

int main() {

  printf("*******************************\n");
  printf("**********SYSTEM INFO**********\n");
  printf("*******************************\n\n");

  uptime();
  printf("\n");
  cpumodel();
  printf("RAM: ");
  meminfo();
}
