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
void nth_insert(node **root , int value, int n);