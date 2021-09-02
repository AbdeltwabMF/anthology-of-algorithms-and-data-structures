#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
struct node
{
    int value;
    node *next; 
};
void print(node *root);
void front_insert(node **root, int n);
void deallocate(node **root);