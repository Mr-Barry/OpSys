#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Implementation have addition functions addFirst, addLast for user,
//checkValid, createNode for inner use. Also it uses 2 structs for list itself and list_node inside.

struct List {
	struct list_node *first;
	struct list_node *last;
	int size;
};

struct list_node {
    int value;
    struct list_node *next;
};

typedef struct list_node Node;
typedef struct List List;

Node * createNode(int i) { // create node with value i
    Node * node = (Node*)malloc(sizeof(Node));
    node -> value = i;
    node -> next = NULL;
    return node;
}

void print_list(List *list) { // print list
    Node * temp = list -> first;
    do {
        printf("%d ",temp -> value);
        temp = temp -> next;
    } while (temp != NULL);
    printf("\n");
}

void addLast(List * list, int i) {  // add node at the end
    if (list -> first == NULL) {
        list -> first =  createNode(i);
        list -> last = list -> first;
    }
    else {
		Node * temp = createNode(i);
        list -> last -> next = temp;
        list -> last = list -> last -> next;
    }
    list -> size = list -> size + 1;
}

void addFirst(List * list, int i) {
    if (list -> first == NULL) {
        list -> first =  createNode(i);
        list -> last = list -> first;
    }
    else {
        Node * temp = createNode(i);
        temp -> next = list->first;
        list -> first = temp;
    }
    list -> size = list -> size + 1;
}

int checkValid(List * list, int index) { // check if index of list is valid
    if ( (list->first == NULL) || ( index > list -> size ) || (index < 0) ) {
        return 0;
    }
    return 1;
}

void insert_node(List * list, int prevIndex, int value) {
    Node * temp, *nextNode, *newNode;
    if (checkValid(list, prevIndex) == 0) return;
    else {
		if (prevIndex == 0) addFirst(list, value);
		else if (prevIndex == list -> size) addLast (list, value);
		else {
			temp = list -> first;
			int i = 0;
			while ((temp -> next != NULL) & (i < prevIndex - 1)) {
				i++;
				temp = temp -> next;
			}
			nextNode = temp -> next;
			newNode = createNode(value);
			//printf("B ");
			(temp -> next) = newNode; //drop
			//printf("C ");
			newNode -> next = nextNode;
			//printf("D ");
		}
		list -> size = list -> size + 1;
		//printf("E ");
    }
}

void delete_node(List * list, int index) { //delete a node
	Node * tmpNode;
    if (checkValid(list, index) == 0) return;
    else {
        if (index == 0) {
            list -> first = list -> first -> next;
        }
        else {
            tmpNode = list->first;
            int i = 0;
            while ((tmpNode -> next != NULL) & (i < index - 1)) {
                i++;
                tmpNode = tmpNode -> next;
            }
            tmpNode -> next = tmpNode -> next -> next;
        }
    }
    return;
}

int main() {
    List * list = (List*) malloc(sizeof(List));
    addFirst(list, 5);
    addFirst(list, 3);
    addLast(list, 20);
    addLast(list, 721);
    print_list(list);

    insert_node (list, 2, 9);
    insert_node (list, 4, 500);
    print_list(list);
    return 0;

}
