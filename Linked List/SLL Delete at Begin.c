#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i;

    // Read number of nodes
    printf("Enter the No of Nodes: ");
    scanf("%d", &n);

    // Create linked list
    for(i = 1; i <= n; i++)
    {
        // Create new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        // Read data
        printf("Enter the Data: ");
        scanf("%d", &newNode->data);

        // Insert at beginning
        newNode->next = head;
        head = newNode;
    }

    // Display before deletion
    printf("\nBefore Deletion: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    // Delete at beginning
    if(head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        // Store first node
        temp = head;

        // Move head to second node
        head = head->next;

        // Delete old first node
        free(temp);
    }

    // Display after deletion
    printf("\nAfter Deletion: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
