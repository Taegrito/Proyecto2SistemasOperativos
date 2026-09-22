#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(2, "Uso: trace <nombre_o_id_syscall>\n"); //
    exit(1); //
  }

  if (trace(argv[1]) < 0) {
    fprintf(2, "trace: error al activar rastreo\n"); //[cite: 1]
    exit(1); //[cite: 1]
  }

  kill(999);

  exit(0);
}