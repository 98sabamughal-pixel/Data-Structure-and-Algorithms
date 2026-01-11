#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string title, artist, album;
    float duration;
    Node *next, *prev;

    Node(int i, string t, string ar, string al, float d) {
        id = i;
        title = t;
        artist = ar;
        album = al;
        duration = d;
        next = prev = this;
    }
};
class Playlist {
    Node *head;
    Node *current;

public:
    Playlist() {
        head = current = NULL;
    }

    void insertBeginning() {
        int id;
        string title, artist, album;
        float duration;

        cout << "Enter Track ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Artist: ";
        getline(cin, artist);
        cout << "Enter Album: ";
        getline(cin, album);
        cout << "Enter Duration: ";
        cin >> duration;

        Node *newNode = new Node(id, title, artist, album, duration);

        if (head == NULL) {
            head = current = newNode;
        } else {
            Node *last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd() {
        int id;
        string title, artist, album;
        float duration;

        cout << "Enter Track ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Artist: ";
        getline(cin, artist);
        cout << "Enter Album: ";
        getline(cin, album);
        cout << "Enter Duration: ";
        cin >> duration;

        Node *newNode = new Node(id, title, artist, album, duration);

        if (head == NULL) {
            head = current = newNode;
        } else {
            Node *last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node *temp = head;
        do {
            cout << "[" << temp->id << "] "
                 << temp->title << " | "
                 << temp->artist << " | "
                 << temp->album << " | "
                 << temp->duration << " min\n";
            temp = temp->next;
        } while (temp != head);
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node *temp = head->prev;
        Node *last = temp;

        do {
            cout << "[" << temp->id << "] "
                 << temp->title << " | "
                 << temp->artist << " | "
                 << temp->album << " | "
                 << temp->duration << " min\n";
            temp = temp->prev;
        } while (temp != last);
    }
    void deleteFirst() {
        if (head == NULL) return;

        if (head->next == head) {
            delete head;
            head = current = NULL;
        } else {
            Node *last = head->prev;
            Node *temp = head;
            head = head->next;
            head->prev = last;
            last->next = head;
            delete temp;
        }
    }

    void deleteLast() {
        if (head == NULL) return;

        if (head->next == head) {
            delete head;
            head = current = NULL;
        } else {
            Node *last = head->prev;
            Node *secondLast = last->prev;
            secondLast->next = head;
            head->prev = secondLast;
            delete last;
        }
    }
    void playNext() {
        if (current == NULL) return;
        current = current->next;
        cout << "Now Playing: " << current->title << endl;
    }

    
    void playPrevious() {
        if (current == NULL) return;
        current = current->prev;
        cout << "Now Playing: " << current->title << endl;
    }
};
int main() {
    Playlist p;
    int choice;

    while (true) {
        cout << "\n--- Premium Playlist Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete First Track\n";
        cout << "4. Delete Last Track\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Reverse\n";
        cout << "7. Play Next Song\n";
        cout << "8. Play Previous Song\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: p.insertBeginning(); break;
            case 2: p.insertEnd(); break;
            case 3: p.deleteFirst(); break;
            case 4: p.deleteLast(); break;
            case 5: p.displayForward(); break;
            case 6: p.displayReverse(); break;
            case 7: p.playNext(); break;
            case 8: p.playPrevious(); break;
            case 9: return 0;
            default: cout << "Invalid Choice\n";
        }
    }
}
