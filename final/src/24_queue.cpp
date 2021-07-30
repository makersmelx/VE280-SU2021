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
class queueEmpty {
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

    void insertBack(const T& x)
    {
        node* index = head;
        while (index->next != NULL) {
            index = index->next;
        }
        node* tmp = new node(x);
        tmp->next = NULL;
        index->next = tmp;
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
class emptyQueue {
};

template <class T>
class myQueue {
public:
    int size() { return _storage.size(); }
    T top() { return _storage.top(); }
    void pop()
    {
        try {
            _storage.remove();
        } catch (const emptylist& e) {
            throw emptyQueue();
        }
    }
    bool isEmpty() { return _storage.isEmpty(); }
    void push(T x) { _storage.insertBack(x); }
    void transverse() { _storage.transverse(); }

private:
    slinkList<T> _storage;
};

class BoundsError {
};

template <class T>
class seqList {
private:
    T* data;
    int curLength;
    int maxSize;

public:
    seqList(int initSize = 10)
    {
        maxSize = initSize;
        data = new T[maxSize];
        curLength = 0;
    }
    seqList(const seqList<T>& l)
    {
        data = NULL;
        curLength = 0;
        maxSize = 0;
        copyFrom(l);
    }
    ~seqList() { delete[] data; }
    void insertBack(const T& x)
    {
        if (curLength == maxSize) {
            doubleSpace();
        }
        data[curLength] = x;
        curLength++;
    }
    void insert(int i, const T& x)
    {
        if (i < 0 || i > curLength) {
            throw BoundsError();
        } else {
            if (curLength == maxSize) {
                doubleSpace();
            }
            curLength++;
            for (int j = curLength; j > i; j--) {
                data[j] = data[j - 1];
            }
            data[i] = x;
        }
    }
    void removeBack() { curLength--; }
    bool isEmpty() { return curLength == 0; }
    void remove(int i)
    {
        if (i < 0 || i > curLength) {
            throw BoundsError();
        } else {
            for (int j = i; j < curLength; j++) {
                data[j] = data[j + 1];
            }
            curLength--;
        }
    }
    T back() { return data[curLength - 1]; }
    int length() { return curLength; }
    seqList& operator=(const seqList& is)
    {
        if (this != &is) {
            copyFrom(is);
        }
        return *this;
    }
    void transverse()
    {
        for (int i = 0; i < curLength; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    const T& operator[](int i) const
    {
        if (i >= 0 && i < curLength) {
            return data[i];
        } else
            throw -1;
    }

    int& operator[](int i)
    {
        if (i >= 0 && i < curLength) {
            return data[i];
        } else
            throw -1;
    }

private:
    void copyFrom(const seqList& l)
    {
        if (l.maxSize != maxSize) {
            delete[] data;
            maxSize = l.maxSize;
            data = new T[maxSize];
        }
        for (int i = 0; i < l.curLength; i++) {
            data[i] = l.data[i];
        }
        curLength = l.curLength;
    }
    void doubleSpace()
    {
        maxSize = maxSize * 2;
        int* tmp = new int[maxSize];
        for (int i = 0; i < curLength; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }
};

template <class T>
class cirQueue {
public:
    cirQueue(int max = 10)
    {
        front = 0;
        back = 1;
        maxSize = max;
        elem = new T[max];
        curLength = 0;
    }
    ~cirQueue() { delete[] elem; }
    int size() { return curLength; }
    T top() { return elem[front + 1]; }
    bool isEmpty() { return curLength == 0; }
    void pop()
    {
        if (isEmpty()) {
            throw emptyQueue();
        }
        front = (front + 1) % maxSize;
        curLength--;
    }
    void push(T x)
    {
        if (curLength == maxSize) {
            doubleSpace();
        }
        elem[back] = x;
        back = (back + 1) % maxSize;
        curLength++;
    }
    void transverse()
    {
        for (int i = 1; i <= curLength; i++) {
            cout << elem[(front + i) % maxSize] << " ";
        }
        cout << endl;
    }

    void inOrder()
    {
        for (int i = 0; i < maxSize; i++) {
            cout << elem[i] << " ";
        }
        cout << endl;
    }

private:
    int front;
    int back;
    int maxSize;
    int curLength;
    T* elem;
    void doubleSpace()
    {
        T* tmp = elem;
        elem = new T[maxSize * 2];
        for (int i = 1; i <= maxSize; i++) {
            elem[i] = tmp[(front + i) % maxSize];
        }
        front = 0;
        back = maxSize - 1;
        maxSize *= 2;
        delete tmp;
    }
};

int main()
{
    cirQueue<int> Fuuka(4);
    Fuuka.push(1);
    Fuuka.push(2);
    Fuuka.push(3);
    Fuuka.transverse();
    cout << Fuuka.top() << endl;
    Fuuka.pop();
    Fuuka.transverse();
    Fuuka.push(4);
    Fuuka.transverse();
    Fuuka.inOrder();
    return 0;
}