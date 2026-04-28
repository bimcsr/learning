#include <ctype.h>
#include <stdio.h>
#include <string.h>

void meminfo() {

  int memT;
  FILE *f = fopen("/proc/meminfo", "r");
  char line[256];
  while (fgets(line, sizeof(line), f)) {
    if (strncmp(line, "MemTotal:", strlen("MemTotal:")) == 0) {

      char *value = strchr(line, ':');
      value++;
      while (*value && isspace(*value)) {
        value++;
      }
      sscanf(value, "%d", &memT);
      double mem = memT / 1000000.0;
      printf("%.1fGB\n", mem);
    }
  }
  fclose(f);
}
