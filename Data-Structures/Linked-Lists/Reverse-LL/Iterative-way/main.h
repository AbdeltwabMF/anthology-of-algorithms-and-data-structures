#include <stdlib.h>
#include <stdio.h>
typedef struct node node;

struct node {
    int value;
    node *next;
};
void print(node *ptr);
void deallocate(node **root);
void insert(node **root, int value);
void reverse(node **root);
