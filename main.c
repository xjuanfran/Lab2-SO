#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processes();

int main(void)
{
    processes();
    return 0;
}

void processes() {
  char cat[] = "cat /proc/"; //array que contiene una cadena que se concatena al array command.
  char id[10]; // array donde se guarda el id digitado por el usuario y se concatena al array command.
  char statm[] = "/statm "; //array que contiene una cadena que se concatena al comando.
  char txt[] = ">statm.txt"; // array que contiene una cadena que se concatena al array command; sirve para redireccionar la salida del comando a un archivo.
  char command [40]; // array donde se guarda el comando completo.


  // se pide el id del proceso al usuario.
  printf("Enter the id of the process: \n");
  scanf("\n%s", id);

  // se concatena el comando completo.
  strcpy(command, cat);
  strcat(command, id);
  strcat(command,statm);
  strcat(command, txt);


  // printf("%s", command);
  // printf("\n");

  system(command); // ejecuta el comando "cat /proc/id/statm >statm.txt".

}








