#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct sysinfo_data {
  uint64 free_mem_mb;
  uint64 used_pages;
  uint64 avail_pages;
  uint64 runnable_procs;
};

int main(int argc, char *argv[]) {
  struct sysinfo_data info;

  if (sysinfo(&info) < 0) {
    fprintf(2, "sysinfo: error al obtener la informacion del sistema\n");
    exit(1);
  }

  printf("Free Memory: %d MB\n", (int)info.free_mem_mb);
  printf("Used Pages: %d\n", (int)info.used_pages);
  printf("Available Pages: %d\n", (int)info.avail_pages);
  printf("Runnable Processes: %d\n", (int)info.runnable_procs);

  exit(0);
}