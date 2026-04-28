#include <stdio.h>

void uptime() {

  FILE *f = fopen("/proc/uptime", "r");
  double uptime;
  fscanf(f, "%lf", &uptime);
  fclose(f);

  // test
  int minutes = uptime / 60;
  int hours = minutes / 60;

  printf("System has been up for %d hours (%d minutes)\n", hours, minutes);
}
