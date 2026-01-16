#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode* AddNode(struct studentNode **start, struct studentNode **now, char n[], int a, char s, float g);
struct studentNode* InsNode(struct studentNode **start, struct studentNode **now, char n[], int a, char s, float g);
struct studentNode* DelNode(struct studentNode **start, struct studentNode **now);
void GoBack(struct studentNode **now);

int main() {
    struct studentNode *start = NULL, *now = NULL;
    
    now = AddNode(&start, &now, "one", 6, 'M', 3.11);
    ShowAll(start);
    
    now = AddNode(&start, &now, "two", 8, 'F', 3.22);
    ShowAll(start);
    
    InsNode(&start, &now, "three", 10, 'M', 3.33);
    ShowAll(start);
    
    InsNode(&start, &now, "four", 12, 'F', 3.44);
    ShowAll(start);
    
    GoBack(&now);
    
    now = DelNode(&start, &now);
    ShowAll(start);
    now = DelNode(&start, &now);
    ShowAll(start);
    now = DelNode(&start, &now);
    ShowAll(start);
    
    return 0;
}

void ShowAll(struct studentNode *walk) {
    printf("\n--- Student List ---\n");
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode* AddNode(struct studentNode **start, struct studentNode **now, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;
    newNode->back = *now;
    
    if (*start == NULL) {
        *start = newNode;
    } else {

        (*now)->next = newNode;
    }
    
    return newNode;
}

struct studentNode* InsNode(struct studentNode **start, struct studentNode **now, char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    
    if (*now == NULL || *now == *start) {
        newNode->next = *start;
        newNode->back = NULL;
        
        if (*start != NULL) {
            (*start)->back = newNode;
        }
        
        *start = newNode;
        return newNode;
    }
    
    newNode->next = *now;
    newNode->back = (*now)->back;
    
    if ((*now)->back != NULL) {
        (*now)->back->next = newNode;
    }
    
    (*now)->back = newNode;
    
    return newNode;
}

struct studentNode* DelNode(struct studentNode **start, struct studentNode **now) {
    if (*now == NULL) {
        return NULL;
    }
    
    struct studentNode *temp = *now;
    struct studentNode *nextNode = (*now)->next;
    struct studentNode *backNode = (*now)->back;
    
    if (*now == *start) {
        *start = nextNode;
        if (nextNode != NULL) {
            nextNode->back = NULL;
        }
    } else {

        if (backNode != NULL) {
            backNode->next = nextNode;
        }
        if (nextNode != NULL) {
            nextNode->back = backNode;
        }
    }
    
    free(temp);
    
    if (nextNode != NULL) {
        return nextNode;
    } else {
        return backNode;
    }
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}