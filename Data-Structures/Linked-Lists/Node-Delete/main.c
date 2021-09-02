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
    printf("Which Node you want to delete : ");
    scanf("%d", &n);
    nth_free(&head, n);
    print(head);
    deallocate(&head);
    return 0;
}

void nth_free(node **root, int n)
{
    node *actual_node = *root;
    if(n == 1)
    {
        *root = actual_node->next;
        free(actual_node);
        return;
    }
    node *previous_node = *root;
    for(int i = 1 ; i < n-1 ; i++)
    {
        previous_node = previous_node->next;
    }
    actual_node = previous_node->next;
    previous_node->next = actual_node->next;
    free(actual_node);
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