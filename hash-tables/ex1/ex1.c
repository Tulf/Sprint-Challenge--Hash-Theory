#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for (int i = 0; i < length; i++) {
    int comp = hash_table_retrieve(ht, limit - weights[i]);
    if (comp != -1) {
      Answer *answer = malloc(sizeof(Answer));
      // higher to 1
      answer->index_1 = i;
      // lower to 2
      answer->index_2 = comp;
      destroy_hash_table(ht);  // remove allocated memory, avoid leakage
      return answer;
    } else {
      //
      hash_table_insert(ht, weights[i], i);
    }
  }

  destroy_hash_table(ht);  // remove allocated memory, avoid leakage
  // if we dont' find the mactching pair after iterating return Null
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}
