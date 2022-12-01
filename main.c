#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void processes();

int main(void) {
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

  system(command); // ejecuta el comando "cat /proc/#id/statm >statm.txt".


  FILE *textfile = fopen("./statm.txt", "r"); // se abre el archivo "statm.txt" en modo lectura.
  int n = 0; // variable que se usa para contar las lineas del archivo.
  char line[MAX_LINE_LENGTH]; // array donde se guarda cada linea del archivo.

  if (textfile == NULL)
    return;

  // Para hallar el numero de lineas de un archivo
  while (!feof(textfile)) {
    fscanf(textfile, "%s", line);
    n++;
  }

  //printf("El numero de lineas que tiene el archivo es de: %d\n", n);

  rewind(textfile); // Para volver al inicio del archivo

  if(n ==1){

    char response [1]; // array donde se guarda la respuesta del usuario.

    system("clear");
    printf("The process with the id %s does not exist\n", id);

    printf("Do you want to search for another process? (y/n)\n");
    scanf("\n%s", response);

      if(strcmp(response, "y") == 0){
        //system("clear");
        processes();
      }
      else if(!strcmp(response, "n")){
        printf("The program has finished\n");
        system("sleep 2");
        //system("clear");
        exit(0);
      }
      else{
        printf("Option not valid end of execution\n");
        system("sleep 2");
        exit(0);
      }
    }
    else{
      fscanf(textfile, "%s", line); // se guarda la primera linea del archivo en el array line.

      float lineNum= atoi(line); // se convierte el array line a un entero.
      //printf("%d\n",lineNum);

      float mb = lineNum/1024; // se convierte el entero a Mb.
      float gb = lineNum/(1024*1024); // se convierte el entero a Gb.

      // float operacion = (float)42145/1024;
      // printf("%f", operacion);
      // printf("\n");
      if(lineNum >1024 && lineNum < 1024000){
        printf("The process with the id %s has a size of %.4f MB \n", id, mb);
        exit(0);
      }
      else if (lineNum >1024000){
        printf("The process with the id %s has a size of %.4f GB \n", id, gb);
      }
      else{
        printf("The process with the id %s has a size of %s kB \n", id, line);
        exit(0);
      }
    }
}
