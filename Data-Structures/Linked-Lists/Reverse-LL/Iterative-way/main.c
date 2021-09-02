#include "main.h"
int main(int argc, char const *argv[])
{
    node *head = NULL;
    int n,x;
    printf("how many numbers : ");
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the Value-%d: ", i+1);
        scanf("%d", &x);
        insert(&head,x);
    }
    print(head); // before
    reverse(&head);
    print(head); // after reverse
    deallocate(&head);

    return 0;
}
 
void reverse(node **root)
{
    node *curr,*prev,*next;
    curr = *root;
    if(curr == NULL)
    {
        printf("Empty list\n");
        return;
    }
    prev = NULL;
    next = curr->next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev; 
}
void insert(node **root, int value)
{
    node *actual_node = malloc(sizeof(node));
    actual_node->value = value;
    actual_node->next = NULL;
    if(*root == NULL)
    {
        *root = actual_node;
        return;
    }
    node *curr = *root;
    for(; curr->next != NULL ; curr = curr->next);
    curr->next = actual_node;
}
void print(node *root)
{
    for(node *curr = root ; curr != NULL ; curr = curr->next)
    {
        printf("%d ", curr->value);
    }
    printf("\n");
}
void deallocate(node **root)
{
    node *curr = *root;
    while(curr != NULL)
    {
        *root = (*root)->next;
        free(curr);
        curr = *root;
    }
}