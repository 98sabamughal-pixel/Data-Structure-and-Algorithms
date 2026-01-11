#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* head = NULL;

void insert(int id) {
    Node* n = new Node();
    n->id = id;

    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node* t = head;
        while (t->next != head)
            t = t->next;
        t->next = n;
        n->next = head;
    }
    cout << "Inserted: " << id << endl;
}
void del(int id) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node *cur = head, *prev = NULL;
    do {
        if (cur->id == id) {
            if (cur == head) {
                Node* t = head;
                while (t->next != head)
                    t = t->next;
                head = head->next;
                t->next = head;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            cout << "Deleted: " << id << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != head);

    cout << "ID not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node* t = head;
    cout << "Playlist: ";
    do {
        cout << t->id << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

int main() {
    int ch, id;
    do {
        cout << "\n1.Insert  2.Delete  3.Display  4.Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            insert(id);
            break;
        case 2:
            cout << "Enter ID: ";
            cin >> id;
            del(id);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit\n";
        }
    } while (ch != 4);

    return 0;
}
