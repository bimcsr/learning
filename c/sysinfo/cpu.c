#include <stdio.h>
#include <string.h>

void cpumodel() {

  FILE *f = fopen("/proc/cpuinfo", "r");
  char line[256];

  while (fgets(line, sizeof(line), f)) {
    if (strncmp(line, "model name", strlen("model name")) == 0) {

      char *value = strchr(line, ':');
      value++;
      while (*value == ' ' || *value == '\t') {
        value++;
      }
      printf("CPU manufacturer: ");
      while (*value != ' ') {
        printf("%c", *value);
        value++;
      }
      printf("\n");
      value++;
      printf("CPU model: %s", value);
      break;
    }
  }
  fclose(f);
}
