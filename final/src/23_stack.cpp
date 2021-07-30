#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;
class emptylist {
};
class stackEmpty {
};
template <class T>
class slinkList {
private:
    struct node {
        T val;
        node* next;
        node(const T& x, node* n = NULL)
            : val(x)
            , next(n)
        {
        }
        node()
            : next(0)
        {
        }
        ~node() { }
    };
    node* head;
    int curLength = 0;

public:
    slinkList() { head = new node; }
    slinkList(const slinkList<T>& l)
    {
        head = new node;
        copy(l.head->next);
    }
    ~slinkList()
    {
        clear();
        delete head;
    }
    bool isEmpty() { return head->next == NULL; }
    void remove()
    {
        if (isEmpty()) {
            throw emptylist();
        } else {
            node* p = head->next;
            head->next = p->next;
            delete p;
            curLength--;
        }
    }
    T top()
    {
        if (isEmpty()) {
            throw emptylist();
        } else {
            return head->next->val;
        }
    }

    void insert(const T& x)
    {
        node* tmp = new node(x);
        tmp->next = head->next;
        head->next = tmp;
        curLength++;
    }
    int size() { return curLength; }
    slinkList& operator=(const slinkList& l)
    {
        if (this != &l) {
            clear();
            copy(l.head->next);
        }
        return *this;
    }
    void transverse()
    {
        node* tmp = head->next;
        while (tmp != NULL) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

private:
    void clear()
    {
        node *p = head->next, *q;
        while (p != nullptr) {
            q = p->next;
            delete p;
            p = q;
        }
    }
    void copy(node* source)
    {
        if (!source) {
            return;
        }
        copy(source->next);
        insert(source->val);
    }
};
template <class T>
class myStack {
public:
    int size() { return _storage.size(); }
    T top() { return _storage.top(); }
    void pop()
    {
        try {
            _storage.remove();
        } catch (const emptylist& e) {
            throw stackEmpty();
        }
    }
    void push(T x) { _storage.insert(x); }
    void transverse() { _storage.transverse(); }

private:
    slinkList<T> _storage;
};
int main()
{
    myStack<int> Kukuru;
    Kukuru.push(1);
    Kukuru.push(2);
    Kukuru.push(3);
    Kukuru.transverse();
    cout << Kukuru.top() << endl;
    Kukuru.pop();
    Kukuru.transverse();
    return 0;
}