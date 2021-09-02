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
        front_insert(&head,x);
    }
    print(head);
    deallocate(&head);
    return 0;
}

void print(node *root)
{
    for(node *curr = root ; curr != NULL ; curr = curr->next)
    {
        printf("%d ", curr->value);
    }
    printf("\n");
}
void front_insert(node **root, int n)
{
    node *temp = malloc(sizeof(node));
    temp->value = n;
    temp->next = *root;
    *root = temp;
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