#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree *tree_init (tree *root, int info) { //инициализируем корень древа
    tree *temp = malloc(sizeof(tree)); //выделяем памяттттт
    temp->info = info; // присваиваем значение корню
    temp->parent = NULL; // обнуляем родителя
    temp->right = NULL; // обнуляем детину правую
    temp->left = NULL; // обнуляем детину левую
    root = temp;
    return root;
}

tree *branch_add (tree *root, int info) { // добавим детин
    tree *root_2 = root, *root_3 = NULL; // не забудем адрес родителя.....
    tree *temp = malloc(sizeof(tree)); // выделим память
    temp->info = info; // присваиваем значение
    while(root_2 != NULL) { // ищем позицию для вставки
        root_3 = root_2;
        if(info < root_2->info) {
            root_2 = root_2->left;
        }
        else {
            root_2 = root_2->right;
        }
    }
    temp->parent = root_3; // присвоили указатель на родителя, который нашли выше
    temp->left = NULL; //обнуляем детин
    temp->right = NULL;
    if(info < root_3->info) { //вставляем узел в найденное место
        root_3->left = temp;
    }
    else {
        root_3->right = temp;
    }
    return root;
}

tree *branch_search (tree *root, int info) { //поиск элэмента
    if((root == NULL) || (root->info == info)) {
        return root; //если дерево пусто, либо его данные равны искомым, возвращаем указатель на дерево
    }
    if(info < root->info) {
        return branch_search(root->left, info);
    }
    else {
        return branch_search(root->right, info);
    }
}

tree *branch_min (tree *root) { // поиск минимального элемента
    tree *min = root;
    while(min->left != NULL) {
        min = min->left;
    }
    return min;
}

tree *branch_max (tree *root) { // поиск максимального элемента 
    tree *max = root;
    while(max->right != NULL) {
        max = max->right;
    }
    return max;
}

tree *branch_find_following (tree *root) { // поиск следующего по значению за данным элементом элемента
    return branch_min(root->right);
}

void *branch_delete (tree *root, int info) { // удаление элемента, если одинаковых элементов в дереве нет
    tree  *temp_1 = NULL, *temp_2 = NULL;
    temp_1 = branch_search(root, info); // ищем удаляемый узел
    
    if((temp_1->right == NULL) && (temp_1->left == NULL)) { // если удаляемый элемент - лист
        temp_2 = temp_1->parent;
        if(temp_1 == temp_2->left) {
            temp_2->left = NULL;
        }
        else {
            temp_2->right = NULL;
        }
        free(temp_1);
    }

    else if((temp_1->right != NULL) && (temp_1->left == NULL)) { // если есть только правый детина
        temp_2 = temp_1->parent;
        if(temp_1 == temp_2->right) {
            temp_2->right = temp_1->right;
        }
        else {
            temp_2->left = temp_1->right;
        }
        free(temp_1);
    }

    else if((temp_1->right == NULL) && (temp_1->left != NULL)) { // если есть только левый детина
        temp_2 = temp_1->parent;
        if(temp_1 == temp_2->right) {
            temp_2->right = temp_1->left;
        }
        else {
            temp_2->left = temp_1->left;
        }
        free(temp_1);
    }

    else { // еусли все детины на месте
        temp_2 = branch_find_following(temp_1);
        temp_1->info = temp_2->info;
        if(temp_2->right == NULL) { //пользуемся законами логики
            temp_2->parent->left = NULL;
        }
        else {
            temp_2->parent->left = temp_2->right;
        }
        free(temp_2);
    }
}

void *tree_print (tree *root) { // печать древа
    if(root == NULL) {
        return 0;
    }
    else {
        printf("%c \n", root->info);
    }
    tree_print(root->left);
    tree_print(root->right);
}
