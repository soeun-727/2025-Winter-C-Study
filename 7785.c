#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 500000

typedef struct Node {
    char name[6];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hashFunction(char* str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + (*str++);
    }
    return hash % TABLE_SIZE;
}

void insert(char* name) {
    unsigned int index = hashFunction(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void removeNode(char* name) {
    unsigned int index = hashFunction(name);
    Node* prev = NULL;
    Node* curr = hashTable[index];

    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            if (prev) prev->next = curr->next;
            else hashTable[index] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int exists(char* name) {
    unsigned int index = hashFunction(name);
    Node* curr = hashTable[index];

    while (curr) {
        if (strcmp(curr->name, name) == 0) return 1;
        curr = curr->next;
    }
    return 0;
}

char* names[TABLE_SIZE];
int nameCount = 0;

void collectNames() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            names[nameCount++] = curr->name;
            curr = curr->next;
        }
    }
}

int compare(const void* a, const void* b) {
    return strcmp(*(char**)b, *(char**)a);
}

int main() {
    int n;
    char name[6], action[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, action);
        if (strcmp(action, "enter") == 0) {
            if (!exists(name)) insert(name);
        } else {
            removeNode(name);
        }
    }

    collectNames();
    qsort(names, nameCount, sizeof(char*), compare);

    for (int i = 0; i < nameCount; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
