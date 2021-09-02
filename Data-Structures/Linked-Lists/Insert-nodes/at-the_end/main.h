#include <stdlib.h>
#include <stdio.h>
typedef struct node node;
struct node
{
    int value;
    node *next; 
};
void print(node *ptr);
void insert_end(node **root, int x);
void deallocate(node **root);