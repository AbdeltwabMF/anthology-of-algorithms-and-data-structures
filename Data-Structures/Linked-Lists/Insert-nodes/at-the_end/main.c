#include "main.h"
int main(int argc, char const *argv[])
{
    node *head = NULL;
    int n,x;
    printf("How many numbers in the list : ");
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the %d-Number: ", i+1);
        scanf("%d", &x);
        insert_end(&head,x);
    }
    print(head);
    deallocate(&head);
    return 0;
}
void insert_end(node **root, int x)
{
    node *new = (node*)malloc(sizeof(node));
    if(new == NULL)
    {
        exit(1);
    }
    new->next = NULL; // our last node point to NULL
    new->value = x;
    if(*root == NULL)
    {
        *root = new;
        return;
    }
    node *curr = *root;
    for(; curr->next != NULL ; curr = curr->next);
    curr->next = new;
    
}
void print(node *ptr1)
{
    for(node *ptr = ptr1; ptr != NULL ; ptr = ptr->next)
    {
        printf("%d ", ptr->value);
    }
    printf("\n");
}
void deallocate(node **root)
{
    for(node *curr = *root; curr->next != NULL ; )
    {
        node *aux = curr;
        curr = curr->next;
        free(aux);

    }
}