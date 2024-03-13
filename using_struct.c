/* Prototype: Needs more revisions and features. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const char allocError[] = "Could not allocate memory";

typedef struct {
    int *members;
    int length;
} Set;

Set *initSet();
bool isEmptySet(Set *);
void printSet(Set *);
void insertSet(Set *, int);
void deleteSet(Set *);
/* FIXME: Prevention of multiple set deletions is still unachieved. It might be
 * included in a future version. More operations such as unions, intersections,
 * etc. are yet missing. */

int main(void) {
    // Enter your code here.

    return 0;
}

Set *initSet() {
    Set *newSet = (Set *)malloc(sizeof(Set));
    newSet->length = 0;
    newSet->members = (int *)malloc(sizeof(int));

    return newSet;
}

bool isEmptySet(Set *set) { return set->length == 0; }

void printSet(Set *set) {
    for (int i = 0; i < set->length; i++) {
        (i == set->length - 1) ? (void)printf("%d\n", set->members[i])
                               : (void)printf("%d, ", set->members[i]);
    }

    return;
}

void deleteSet(Set *set) {
    free(set->members);
    free(set);

    return;
}

void insertSet(Set *set, int member) {
    for (int i = 0; i < set->length; i++) {
        if (member == set->members[i]) {
            return;
        }
    }

    int *temp = (int *)realloc(set->members, sizeof(int) * (set->length + 1));

    if (temp == NULL) {
        perror(allocError);
        printSet(set);

        return;
    }

    set->members = temp;
    set->members[set->length] = member;
    (set->length)++;

    return;
}
