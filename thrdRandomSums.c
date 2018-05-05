#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int sumT;
unsigned int seed;

void* randHund(void *id){
  int rInt = ((rand_r(&seed) % 201) - 100);
  printf("%d\n", rInt);
  sumT += rInt;
  pthread_exit(0);
}

int main(int argc, char* argv[]){
  int numT = atoi(argv[2]);
  int ret, i;
  pthread_t thread[numT];
  for(i = 0; i < numT; i++){
    seed = time(0) + i;
    ret = pthread_create(thread+i, NULL, randHund, &i);
    if(ret) printf("Error: Creating randHund pthread; return code: %d\n", ret);
  }
  for(i = 0; i < numT; i++){
    ret = pthread_join(thread[i], NULL);
    if(ret)
      printf("Error: Joining main thread to randHund thread; return code: %d\n", ret);
  }
  printf("%d\n", sumT);
  return 0;
}
