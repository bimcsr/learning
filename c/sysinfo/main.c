#include "header.h"
#include <stdio.h>

void uptime() {

  FILE *f = fopen("/proc/uptime", "r");
  double uptime;
  fscanf(f, "%lf", &uptime);
  fclose(f);

  // test
  int minutes = uptime / 60;
  int hours = minutes / 60;

  printf("System has been up for %d hours (or %d minutes (or %.0f seconds))\n",
         hours, minutes, uptime);
}

int main() {

  //  uptime();
  cpumodel();
}
