#include <stdio.h>
#include <string.h>



void uptime(){

    FILE *f = fopen("/proc/uptime", "r");
    double uptime;
    fscanf(f, "%lf", &uptime);
    fclose(f);

    //test
    int minutes = uptime/60;
    int hours = minutes/60;

    printf("System has been up for %d hours (or %d minutes (or %.0f seconds))\n", hours, minutes, uptime);

}

void cpumodel(){

    FILE *f = fopen("/proc/cpuinfo", "r");
    char line[256];

    while (fgets(line, sizeof(line), f)){
        if (strncmp(line, "model name", 10) == 0){
            char *value = strchr(line, ':');
            value += 2;   
            printf("CPU manufacturer: ");
            while (*value != ' '){
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

int main() {

    uptime();
    cpumodel();

}





/**
  while (fgets(line, sizeof(line), f)) {
  if(strncmp(line, "model name", 10) == 0) {
  printf("CPU %s", line);
  break;
  }
  }
 **/   
