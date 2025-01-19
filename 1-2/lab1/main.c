#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    int n;
    Node *head = (Node*)malloc(sizeof(Node));
    Node *node = head;
    Node *rec[5001];
    char status[5001][51];

    scanf("%d", &n);
    scanf("%d%d%s", &node->serial, &node->stu_id, node->name);
    scanf("%s", status[node->serial]);
    rec[node->serial] = node;

    for (int i=2; i<=n; i++) {
        node->next = (Node*)malloc(sizeof(Node));
        node = node->next;
        scanf("%d%d%s", &node->serial, &node->stu_id, node->name);
        scanf("%s", status[node->serial]);
        rec[node->serial] = node;
    }
    node->next = NULL;

    eFormSort(head);

    node = head;
    for (int i=1; i<=n; i++) {
        if (node != rec[i]) {
            printf("Fail...\n");
            return 0;
        }
        printf("%d %d %s %s\n", node->serial, node->stu_id, node->name, status[node->serial]);
        if (i < n) node = node->next;
    }
    return 0;
}
