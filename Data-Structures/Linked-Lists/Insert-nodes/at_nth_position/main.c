#include "main.h"
int main(int argc, char const *argv[])
{
    node *head = NULL;

    nth_insert(&head, 1, 1);
    nth_insert(&head, 2, 2);
    nth_insert(&head, 8, 3);
    print(head);
    deallocate(&head);
    return 0;
}

void nth_insert(node **root , int value, int n)
{
    node *actual_node = malloc(sizeof(node));
    actual_node->value = value;
    actual_node->next = NULL;
    if(n == 1)
    {
        actual_node->next = *root;
        *root = actual_node;
        return;
    }
    node *previous_node = *root;
    for(int i = 1 ; i < n-1 ; i++) // first node n = 1
    {
        previous_node  = previous_node->next;
    }
    actual_node->next = previous_node ->next;
    previous_node ->next = actual_node;

}

void deallocate(node **root)
{
    for(node *curr = *root; curr->next != NULL ;)
    {
        node *aux = curr;
        curr = curr->next;
        free(aux);
    }
}
void print(node *root)
{
    for(node *curr = root ; curr != NULL ; curr = curr->next)
    {
        printf("%d ", curr->value);
    }
    printf("\n");
}