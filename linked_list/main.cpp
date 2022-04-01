#include <iostream>

using namespace std;

struct Node {
    int value = -1;
    Node *next;
};

struct List {
    unsigned size = 0;
    Node *tail;
    Node *head;
};

void new_node(Node *pri, int value, Node *next) {
    Node *n = new Node{};
    pri->next = n;
    n->value = value;
    n->next = next;

}

void new_tail(int value, List *l) {
    Node *n = new Node;
    l->tail->next = n;
    n->value = value;
    l->tail = n;
}

void push_front(List *l, int val) {
    new_node(l->head, val, l->head->next);
    l->size++;
}

void push_back(List *l, int val) {
    l->tail->value = val;
    new_tail(-1, l);
    l->size++;
}

void print(List *l) {
    Node *n = l->head->next;
    for (int i = 0; i < l->size; i++) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
    ///cout << l->head->value << " " << l->tail->value << endl;
}

int pop_front(List *l) {
    /// if l->size > 0
    int n = l->head->next->value;
    Node *n1 = l->head;
    l->head = l->head->next;
    l->head->value = -1;
    delete n1;
    l->size--;
    return n;
}

int pop_back(List *l) {
    /// if l->size > 0
    Node *n1 = l->head;
    for (int i = 0; i < (l->size) - 1; i++) {
        n1 = n1->next;
    }
    int n = n1->next->value;
    delete l->tail;
    l->tail = n1->next;
    l->tail->value = -1;
    l->size--;
    return n;
}

void insert(List *l, int val, int ind) {
    Node *n = l->head;
    if ((ind <= l->size) and (ind >= 0)) {
        for (int i = 0; i < ind; i++) {
            n = n->next;
        }
        new_node(n, val, n->next);
        l->size++;
    }
}

int get(List *l, int ind){
    Node *n = l->head;
    int a = 0;
    if (ind < l->size){
        for (int i = 0; i < ind; i++){
            n = n->next;
        }
        a = n->next->value;
    }
    return a;
}

void clear(List *l) {
    int c  =l->size;
    for (int i = 0; i < c; i++) {
        pop_front(l);
    }
}

int remove(List *l, int ind) {
    Node *n = l->head;
    int a = 0;
    if (ind < l->size) {
        for (int i = 0; i < ind; i++) {
            n = n->next;
        }
        Node *n1 = n->next;
        a = n->next->value;
        n->next = n->next->next;
        delete n1;
        l->size--;
    }
    return a;
}

unsigned length(List *l) {
    return l->size;
}

List get_List() {
    Node *n = new Node{.value = -1};
    auto *l = new List{.size = 0, .tail = n, .head = new Node{.value = -1, .next = n}};
    return *l;
}

void to_array(List *l, int array[], int n){
    Node *w = l->head;
    for (int i = 0; i < n; i++){
        array[i] = w->next->value;
        w = w->next;
    }
}

void from_array(List *l, int array[], int n){
    clear(l);                  /// FIXED
    for (int i = 0; i < n; i++){
        push_back(l, array[i]);
    }
}

/// ! ! !

struct node{
    int value;
    node *next;
    node *prev;
};

struct DoubleList{
    unsigned size = 0;
    node *head;
    node *tail;
};

DoubleList get_DoubleList() {
    node *n1 = new node{.value = -1};
    node *n2 = new node{.value = -1, .prev = n1};
    n1->next = n2;
    auto *l = new DoubleList{.size = 0, .head = n1, .tail = n2};
    return *l;
}

void new_node(node *pri, int value, node *next) {
    node *n = new node{};
    pri->next = n;
    n->value = value;
    n->next = next;
    n->prev = pri;
    next->prev = n;
}

void push_front(DoubleList *l, int val) {
    new_node(l->head, val, l->head->next);
    l->size++;
}

void push_back(DoubleList *l, int val) {
    new_node(l->tail->prev, val, l->tail);
    l->size++;
}

int pop_front(DoubleList *l) {
    /// if l->size > 0
    int n = l->head->next->value;
    node *n1 = l->head;
    l->head = l->head->next;
    l->head->value = -1;
    delete n1;
    l->size--;
    return n;
}

int pop_back(DoubleList *l) {
    /// if l->size > 0
    node *n1 = l->tail;
    int n = n1->prev->value;
    l->tail = l->tail->prev;
    delete n1;
    l->tail->value = -1;
    l->size--;
    return n;
}

/// improved to O(n/2)
void insert(DoubleList *l, int val, int ind) {
    if (ind <= l->size/2) {
        node *n = l->head;
        if  (ind >= 0) {
            for (unsigned i = 0; i < ind; i++) {
                n = n->next;
            }
            new_node(n, val, n->next);
            l->size++;
        }
    }
    else{
        node *n = l->tail;
        if (ind <= l->size) {
            for (unsigned i = l->size; i > ind; i--) {
                n = n->prev;
            }
            new_node(n->prev, val, n);
            l->size++;
        }
    }
}

unsigned length(DoubleList *l) {
    return l->size;
}

int get(DoubleList *l, int ind){
    node *n = l->head;
    int a = 0;
    if (ind < l->size){
        for (int i = 0; i < ind; i++){
            n = n->next;
        }
        a = n->next->value;
    }
    return a;
}

void clear(DoubleList *l) {
    int c = l->size;
    for (int i = 0; i < c; i++) {
        pop_front(l);
    }
}

int remove(DoubleList *l, int ind) {
    node *n = l->head;
    int a = 0;
    if (ind < l->size) {
        for (int i = 0; i < ind; i++) {
            n = n->next;
        }
        node *n1 = n->next;
        a = n->next->value;
        n->next = n->next->next;
        delete n1;
        l->size--;
    }
    return a;
}

void print(DoubleList *l) {
    node *n = l->head->next;
    for (int i = 0; i < l->size; i++) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
    ///cout << l->head->value << " " << l->tail->value << endl;
}

void print_back(DoubleList *l) {
    node *n = l->tail->prev;
    for (int i = l->size; i > 0; i--) {
        cout << n->value << " ";
        n = n->prev;
    }
    cout << endl;
    ///cout << l->head->value << " " << l->tail->value << endl;
}

void to_array(DoubleList *l, int array[], int n){
    node *w = l->head;
    for (int i = 0; i < n; i++){
        array[i] = w->next->value;
        w = w->next;
    }
}

void from_array(DoubleList *l, int array[], int n){
    clear(l);                  /// FIXED
    for (int i = 0; i < n; i++){
        push_back(l, array[i]);
    }
}

/// ! ! !

struct NODE {
    int value = -1;
    NODE *next;
};

struct Stack{
    unsigned size = 0;
    NODE *head;
};

Stack get_Stack() {
    auto *l = new Stack{.size = 0, .head = new NODE{.value = -1, .next = new NODE{.value = -1}}};
    return *l;
}

bool empty(Stack *l){
    return (l->size == 0);
}

void new_node(NODE *pri, int value, NODE *next) {
    NODE *n = new NODE{.value = value};
    pri->next = n;
    n->next = next;
}

void push(Stack *l, int val) {
    new_node(l->head, val, l->head->next);
    l->size++;
}

int pop(Stack *l) {
    if (not(empty(l))){
        int n = l->head->next->value;
        NODE *n1 = l->head;
        l->head = l->head->next;
        l->head->value = -1;
        delete n1;
        l->size--;
        return n;
    }
    else{
        return -1;
    }
}

void print(Stack *l) {
    NODE *n = l->head->next;
    for (int i = 0; i < l->size; i++) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
    ///cout << l->head->value << " " << l->tail->value << endl;
}

int top(Stack *l){
    return not(empty(l)) ? l->head->next->value : -1;
}

void clear(Stack *l) {
    int c = l->size;
    for (int i = 0; i < c; i++) {
        pop(l);
    }
}

void to_array(Stack *l, int array[], int n){
    NODE *w = l->head;
    for (int i = 0; i < n; i++){
        array[i] = w->next->value;
        w = w->next;
    }
}

void from_array(Stack *l, int array[], int n){
    clear(l);                  /// FIXED
    for (int i = n-1; i >= 0; i--){
        push(l, array[i]);
    }
}

/// ! ! !


struct Queue{
    unsigned size = 0;
    Node *tail;
    Node *head;
};

Queue get_Queue(){
    Node *n1 = new Node{.value = -1};
    Node *n2 = new Node{.value = -1, .next = n1};
    n1->next = n2;
    auto *q = new Queue{.size = 0, .tail = n2, .head = n1};
    return *q;
}

void enQueue(Queue *q, int value){  /// Can be wrong
    Node *n = new Node;
    q->tail->next->next = n;
    n->value = value;
    q->size++;
}

void deQueue(Queue *q){
    Node *n1 = q->head;
    q->head = q->head->next;
    q->head->value = -1;
    delete n1;
    q->size--;
}

void test_List(){
    List l = get_List();
    insert(&l, 9, 0);
    print(&l);
    cout << remove(&l, 1) << endl;
    print(&l);
    cout << get(&l, 0) << endl;
    cout << pop_front(&l) << endl;
    clear(&l);
    print(&l);
}

void test_DoubleList(){
    DoubleList L = get_DoubleList();
    print(&L);
    push_front(&L, 10);
    print(&L);
    push_front(&L, 1);
    push_front(&L, 2);
    push_front(&L, 3);
    print(&L);
    cout << pop_front(&L) << " " << pop_front(&L) << endl;
    cout << pop_back(&L) << " " << pop_back(&L) << endl;
    push_front(&L, 3);
    push_front(&L, 2);
    print(&L);
    insert(&L, 100, 1);
    insert(&L, 80, 1);
    insert(&L, 60, 1);
    print(&L);
    insert(&L, 90, 3);
    print(&L);
    print_back(&L);
    cout << get(&L, 3) << endl;
    clear(&L);
    print(&L);
    insert(&L, 100, 0);
    insert(&L, 80, 0);
    insert(&L, 60, 0);
    print(&L);
    remove(&L, 1);
    print(&L);
}

void test_Stack(){
    Stack s = get_Stack();
    push(&s, 10);
    push(&s, 9);
    push(&s, 8);
    print(&s);
    cout << pop(&s) << endl;
    print(&s);
    push(&s, 100);
    push(&s, 11);
    print(&s);
    pop(&s);
    pop(&s);
    print(&s);
    clear(&s);
    print(&s);
    cout << pop(&s) << endl;
}

int main() {
    List l = get_List();
    DoubleList dl = get_DoubleList();
    Stack s = get_Stack();
    int *a = new int[3]{1, 2, 3};
    from_array(&l, a, 3);
    from_array(&dl, a, 3);
    from_array(&s, a, 3);
    print(&l);
    print(&dl);
    print(&s);
    to_array(&s, a, 3);
    cout << a[0] << a[1] << a[2] << endl;
    to_array(&l, a, 3);
    cout << a[0] << a[1] << a[2] << endl;
    to_array(&dl, a, 3);
    cout << a[0] << a[1] << a[2] << endl;
}