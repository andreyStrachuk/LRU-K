#ifndef DOUBLY_CONNECTED_LIST_H_INCLUDED
#define DOUBLY_CONNECTED_LIST_H_INCLUDED

struct list_elem {

    int data;

    struct list_elem *next;
    struct list_elem *prev;

};

struct List {

    struct list_elem *head;
    struct list_elem *tail;

    int size;
};

int create_list(struct List *list);

struct list_elem *create_elem(int data);

struct list_elem *first_push(struct List *list, int data);

struct list_elem *push_head(struct List *list, int data);

struct list_elem *push_tail(struct List *list, int data);

struct list_elem *push_after(struct List *list, struct list_elem *elem, int data);

struct list_elem *push_before(struct List *list, struct list_elem *elem, int data);


#endif // DOUBLY_CONNECTED_LIST_H_INCLUDED
