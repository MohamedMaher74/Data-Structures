#include<bits/stdc++.h>

#define UnLimit() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define fast_cin() std::ios_base::sync_with_stdio (0); cin . tie (NULL);cout . tie (NULL);
#define read(arr, n) for(int i=0;i<n and cin>>arr[i];i++);
#define print(arr, n) for(int i=0;i<n and cout<<arr[i];i++);
#define cin_vec(vec) for(auto& i:vec) cin>>i
#define cout_vec(vec) for(auto&i:vec) cout<<i<<" "; cout<<'\n';
#define PI 3.14159
#define ll long long

using namespace std;

template<class t>
class LinkedList {
    struct Node {
        int info;
        Node *next;
    };
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList() {
        head = tail = NULL;
        length = 0;
    }

    ~LinkedList() {
        Node *p = head;
        while (p != NULL) {
            p = p->next;
            delete head;
            p = head;
        }
    }

    bool IsEmpty() {
        return length == 0;
    }

    void insertFirst(int data) {
        Node *p = new Node;
        p->info = data;
        p->next = head;
        if (IsEmpty()) {
            head = tail = p;
            p->next = NULL;
        } else {
            p->next = head;
            head = p;
        }
        length++;
    }

    void insertLast(int data) {
        Node *p = new Node;
        p->info = data;
        if (IsEmpty()) {
            head = tail = p;
            p->next = NULL;
        } else {
            tail->next = p;
            p->next = NULL;
            tail = p;
        }
        length++;
    }

    void insertAtPos(int pos, int data) {
        if (pos < 0 || pos > length) {
            cout << "out of range";
        } else {
            Node *p = new Node;
            p->info = data;
            if (pos == 0) {
                insertFirst(data);
            } else if (pos == length) {
                insertLast(data);
            } else {
                Node *q = head;
                for (int i = 1; i < pos; i++) {
                    q = q->next;
                }
                p->next = q->next;
                q->next = p;
                length++;
            }
        }
    }

    void printList() {
        Node *p = head;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << '\n';
    }

    int CountList() {
        Node *p = head;
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }

    void removeFirst() {
        if (IsEmpty()) {
            cout << "List is Empty";
        } else if (length == 1) {
            delete head;
            head = tail = NULL;
        } else {
            Node *p = head;
            head = head->next;
            delete p;
        }
        length--;
    }

    void removeLast() {
        if (IsEmpty()) {
            cout << "List is Empty";
        } else if (length == 1) {
            delete head;
            head = tail = NULL;
        } else {
            Node *p = head, *q = head;
            while (p->next != NULL) {
                q = p;
                p = p->next;
            }
            delete p;
            q->next = NULL;
        }
        length--;
    }

    void removeAtPos(int pos) {
        if (pos < 0 || pos > length) {
            cout << "Out of range";
        } else {
            if (pos == 0) {
                removeFirst();
            } else if (pos == length) {
                removeLast();
            } else {
                Node *p = head->next, *q = head;
                for (int i = 1; i < pos; i++) {
                    q = p;
                    p = p->next;
                }
                q->next = p->next;
                delete p;
                length--;
            }
        }
    }

    int findNode(int data) {
        Node *p = head;
        int count = 0;
        while (p != NULL and p->info != data) {
            count++;
            p = p->next;
        }
        return count;
    }

    void sortList() {
        Node *p = head;
        int i = 0, arr[length];
        while (p != NULL) {
            arr[i++] = p->info;
            p = p->next;
        }
        sort(arr, arr + length);
        p = head, i = 0;
        while (p != NULL) {
            p->info = arr[i++];
            p = p->next;
        }
        p = head, i = 0;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << '\n';
    }

    void reverseList() {
        Node *p = head;
        int i = 0, arr[length];
        while (p != NULL) {
            arr[i++] = p->info;
            p = p->next;
        }
        reverse(arr, arr + length);
        i = 0, p = head;
        while (p != NULL) {
            p->info = arr[i++];
            p = p->next;
        }
        i = 0, p = head;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << '\n';
    }

    int get_Min() {
        Node *p = head;
        int min = head->info;
        while (p != NULL) {
            if (min > p->info) {
                min = p->info;
            }
            p = p->next;
        }
        return min;
    }

    int get_Max() {
        Node *p = head;
        int max = p->info;
        while (p != NULL) {
            if (max < p->info) {
                max = p->info;
            }
            p = p->next;
        }
        return max;
    }

    int sum_odd() {
        Node *p = head;
        int sum = 0;
        while (p != NULL) {
            if (p->info % 2) {
                sum += p->info;
            }
            p = p->next;
        }
        return sum;
    }

    int sum_even() {
        Node *p = head;
        int sum = 0;
        while (p != NULL) {
            if (!(p->info % 2)) {
                sum += p->info;
            }
            p = p->next;
        }
        return sum;
    }

    void Increase_by(int n) {
        Node *p = head;
        while (p != NULL) {
            p->info += n;
            cout << p->info << " ";
            p = p->next;
        }
    }

    void print_Even() {
        Node *p = head;
        int i = 0, even[length], a = 0;
        while (p != NULL) {
            if (!(p->info % 2)) {
                even[i++] = p->info;
                a++;
            }
            p = p->next;
        }
        i = 0;
        for (i = 0; i < a; i++) {
            cout << even[i] << " ";
        }
        cout << '\n';
    }

    void print_Odd() {
        Node *p = head;
        int i = 0, odd[length], b = 0;
        while (p != NULL) {
            if (p->info % 2) {
                odd[i++] = p->info;
                b++;
            }
            p = p->next;
        }
        i = 0;
        for (i = 0; i < b; i++) {
            cout << odd[i] << " ";
        }
        cout << '\n';
    }

    void update(int ov, int nv) {
        if (IsEmpty()) {
            return;
        } else {
            Node *p = head;
            while (p != NULL and p->info != ov) {
                p = p->next;
            }
            if (p->info == ov) {
                p->info = nv;
            }
        }
    }

};


int main() {
    LinkedList<int> l;
    l.insertFirst(20);
    l.insertLast(10);
    l.insertFirst(30);
    l.insertLast(13);
    l.printList();
    l.removeLast();
    l.printList();
    l.insertAtPos(2, 50);
    l.printList();
    l.removeFirst();
    l.printList();
    l.removeAtPos(2);
    l.printList();
    cout << (l.IsEmpty() ? "Empty\n" : "Not Empty\n");
    cout << "Number of Elements is: " << l.CountList() << '\n';
    l.Increase_by(10);
    cout << '\n';
    cout << "Searched Node is in: " << l.findNode(60) << " position." << '\n';
    cout << "Minimum value of list is:" << l.get_Min() << '\n';
    cout << "Maximum value of list is:" << l.get_Max() << "\n";
    l.update(30, 5);
    l.printList();
    l.reverseList();
    l.sortList();
    cout << "Sum of even numbers is: " << l.sum_even() << '\n';
    cout << "Sum of odd numbers is: " << l.sum_odd() << '\n';
    l.print_Even();
    l.print_Odd();


    return 0;
}