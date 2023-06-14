#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int getRand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max + 1 - min) + min;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void experiment6(){
  char words[200000][8];
  FILE *inp;
  inp = fopen("words.txt", "r");
  int i = 0;
  while (1) {
    char r = (char)fgetc(inp);
    int k = 0;
    while (r != '\n' && !feof(inp)) {
      words[i][k++] = r;
      r = (char)fgetc(inp);
    }
    words[i][k] = 0;
    if (feof(inp)) {
      break;
    }
    i++;
  }

  for(int size = 10000; size <= 200000; size += 10000) {
    listnode *KR_hashtab[1];
    /*listnode *JEN_hashtab[size];*/
    hashtab_init(KR_hashtab, 1);
    /* hashtab_init(JEN_hashtab, size);*/
    int KR_collisions = 0, JEN_collisions = 0;
    for(int i = 0; i < size; i++) {
      hashtab_add(KR_hashtab, words[i], i, KR, 1, &KR_collisions);
      /*hashtab_add(JEN_hashtab, words[i], i, JEN, size, &JEN_collisions);*/
    }
    double t = wtime();
    listnode *node = hashtab_lookup(KR_hashtab, words[size-1], KR, 1);
    t = wtime() - t;
    printf(" n: %d t: %.6f collisions: %d\n", size, t, KR_collisions);
    /*t = wtime();
    node = hashtab_lookup(JEN_hashtab, words[getRand(0, size-1)], JEN, size);
    t = wtime() - t;
    printf("[JEN] n: %d t: %.6f collisions: %d\n", size, t, JEN_collisions);
    */
    /*if(size == 200000) {
      for(int i = 0; i < size; i++) {
        listnode *nodee = JEN_hashtab[i];
        if(nodee != NULL) {
          printf("%d. key: %s value: %d\n", i, nodee->key, nodee->value);
          listnode *nodeee = nodee->next;
          if(nodeee != NULL) {
            printf("\tnext in it: key: %s value: %d\n", nodeee->key, nodeee->value);
            listnode *nodeeee = nodeee->next;
            if(nodeeee != NULL) {
              printf("\t\tnext in it: key: %s value: %d\n", nodeeee->key, nodeeee->value);
              listnode *nodeeeee = nodeeee->next;
              if(nodeeeee != NULL) {
                printf("\t\t\tnext in it: key: %s value: %d\n", nodeeeee->key, nodeeeee->value);
              }
            }
          }
        }
      }
    }
    
    listnode *finding = hashtab_lookup(JEN_hashtab, "bbfbadf", JEN, size);
    if(finding != NULL) {
      printf("Found the node that is in linked list!\n");
      }*/
  }
}

int main() {
  experiment6();
  return 0;
}
