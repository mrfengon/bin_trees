#include <stdio.h>
#include "tree.h"
#include "functions.h"

int main() {
    int temp;
    int inf_root, inf_branch_add, inf_branch_del;
    tree* root;
    printf("enter root info\n");
    scanf("%d", &inf_root);
    tree_init(&root, inf_root);
    while(temp != 5){
        printf("\n1 - add branch, 2 - print tree, 3 - delete branch, 4 - func, 5 - exit\n\n");
        scanf("%d", &temp);
        if (temp == 1) {
            printf("\nenter info: ");
            scanf("%d", &inf_branch_add);
            branch_add(root, inf_branch_add);
        }
        else if (temp == 2) {
            tree_print(root, 0);
        }
        else if (temp == 3) {
            printf("\nenter info of branch u want to delete: ");
            scanf("%d", &inf_branch_del);
            branch_delete(root, inf_branch_del);
        }
        else if(temp == 4) {
            printf("%d\n", leaves_count(root, 0));
        }
        else {
            return 0;
        }
    }
}