#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
  int randI, sumP, numP = atoi(argv[2]);
  int pid, i, status;
  for(i = 0; i < numP; i++){
    pid = fork();
    if (pid != 0) wait(&status);
    else{
      srand(time(NULL)+getpid());
      randI = (rand() % 201);
      printf("%d\n", (randI - 100));
      exit(randI);
    }
    sumP += ((status >> 8) - 100);
  }
  printf("%d\n", sumP);
  return 0;
}
