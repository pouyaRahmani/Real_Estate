#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct u {
    char name[20];
    char estates[3];
    struct u *next;
} user;

user *temp;

user *swap(user *usr1, user *usr2)
{
    temp = usr2->next;
    usr2->next = usr1;
    usr1->next = temp;

    return usr2;
}
 
// Function to sort the linked list 
void bubbleSort(user **head, int count)
{
    user **current;
 
    for (int i = 0; i <= count; i++) {
 
        current = head;
 
        for (int j = 0; j < count - i - 1; j++) {
 
            user *user1 = *current;
            user *user2 = user1->next;
 
            if (atoi(user1->estates) < atoi(user2->estates))
                // update the link after swapping
                *current = swap(user1, user2);
 
            current = &((*current)->next);
        }
    }
}

int main()
{
    user *start, *end, *node;

    start = malloc(sizeof(user));
    strcpy(start->estates, "3");
    strcpy(start->name, "John");
    end = start;
    start->next = NULL;

    node = malloc(sizeof(user));
    strcpy(node->estates, "2");
    strcpy(node->name, "Joe");
    end->next = node;
    end = node;
    end->next = NULL;
    
    node = malloc(sizeof(user));
    strcpy(node->estates, "5");
    strcpy(node->name, "Nick");
    end->next = node;
    end = node;
    end->next = NULL;

    node = malloc(sizeof(user));
    strcpy(node->estates, "1");
    strcpy(node->name, "Ali");
    end->next = node;
    end = node;
    end->next = NULL;

    bubbleSort(&start, 4);

    for (node = start; node; node = node->next) {
        puts(node->name);
        puts(node->estates);
    }
}