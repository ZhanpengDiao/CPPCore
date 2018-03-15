// stack with runtime controllable ownership
#ifndef OWNERSTACK_H
#define OWNERSTACK_H

template<class T>
class Stack {
    struct Link {
        T* data;
        Link* next;
        Link(T* data, Link* next): data(data), next(next) {}
    }* head;
    bool own;
public:
    Stack(bool own = true): head(0), own(own) {}
    ~Stack();
    void push(T* data) {
        head = new Link(data, head);
    }
    T* peek() const {
        return head ? head->data : 0;
    }
    T* pop();
    bool owns() const { return own; }
    void owns(bool ifOwn) { own = ifOwn; }
    // auto-conversion: true if not empty
    operator bool() const { return head != 0; }
};

template<class T>
T* Stack<T>::pop() {
    if(head == 0) return 0;
    T* res = head -> data;
    Link* oldHead = head;
    head = head -> next;
    delete oldHead; // delete the Link
    return res;
}

template<class T>
Stack<T>::~Stack() {
    if(!own) return;
    while(head) delete pop(); // delete the Data
}

#endif
