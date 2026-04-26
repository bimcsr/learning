#include <stdio.h>
#include <string.h>

void meminfo() {

  FILE *f = fopen("/proc/meminfo", "r");
  char line[256];

  while (fgets(line, sizeof(line), f)) {
    if (strncmp(line, "MemTotal:", strlen("MemTotal:")) == 0) {

      // rebuild this to use with ram
      // parse first 3 lines in f and then do #quickmaths to convert to gb
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
