#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *current = NULL;
/* Insert a new page at the end */
void insertPage(char page[]) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        current = newNode;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    current = newNode;
}
/* Move forward */
void moveForward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last page.\n");
    }
    else {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}
/* Move backward */
void moveBackward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first page.\n");
    }
    else {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}
/* Delete a specified page */
void deletePage(char page[]) {
    struct Node *temp = head;
    while (temp != NULL && strcmp(temp->page, page) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Page not found.\n");
        return;
    }
    /* Update previous node */
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    /* Update next node */
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    /* Update current page */
    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }
    free(temp);
    printf("Page deleted successfully.\n");
}
/* Display first to last */
void displayForward() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }
    printf("Pages from first to last:\n");
    while (temp != NULL) {
        printf("%s", temp->page);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
/* Display last to first */
void displayBackward() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("No pages available.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Pages from last to first:\n");
    while (temp != NULL) {
        printf("%s", temp->page);
        if (temp->prev != NULL)
            printf(" <-> ");
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    int choice;
    char page[50];
    while (1) {
        printf("\n--- WEB PAGE NAVIGATION ---\n");
        printf("1. Insert New Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Display Current Page\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter page name/URL: ");
                scanf("%s", page);
                insertPage(page);
                printf("Page inserted successfully.\n");
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
                break;
            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);
                deletePage(page);
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                if (current == NULL)
                    printf("No current page.\n");
                else
                    printf("Current page: %s\n", current->page);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}