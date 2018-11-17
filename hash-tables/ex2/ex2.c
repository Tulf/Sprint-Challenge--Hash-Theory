#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));

  for (int i = 0; i < length; i++) {
    // check for source
    if (strcmp(tickets[i]->source, "NONE") == 0) {
      // initialize root if there is no source
      route[0] = tickets[i]->destination;
    }
    // else insert
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  for (int j = 1; j < length; j++) {
    if (hash_table_retrieve(ht, route[j-1]) != NULL) {
      route[j] = hash_table_retrieve(ht, route[j-1]);
    } else {
      // if we can't find the route in the original hash table, set to none availble, leave as NONE for consistency
      route[j] = "NONE";
    }
  }

  destroy_hash_table(ht);

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}
