#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
struct node
{
    int value;
    node *next; 
};
void print(node *root);
void deallocate(node **root);
void nth_free(node **root, int n);
void insert_end(node **root, int x);