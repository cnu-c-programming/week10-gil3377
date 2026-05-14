#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    int score;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    char input[100];

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char name[100];
            int score;
            scanf("%s %d", name, &score);
            
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            strcpy(newNode->name, name);
            newNode->score = score;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        } 
        else if (strcmp(input, "delete") == 0) {
            char name[100];
            scanf("%s", name);

            struct Node* curr = head;
            struct Node* prev = NULL;

            while (curr != NULL) {
                if (strcmp(curr->name, name) == 0) {
                    if (prev == NULL) {
                        head = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        } 
        else if (strcmp(input, "print") == 0) {
            for (struct Node* p = head; p != NULL; p = p->next) {
                printf("%s %d\n", p->name, p->score);
            }
        } 
        else if (strcmp(input, "quit") == 0) {
            struct Node* curr = head;
            while (curr != NULL) {
                struct Node* next = curr->next;
                free(curr);
                curr = next;
            }
            break;
        }
    }

    return 0;
}
