#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class TicketQueue {
private:
    string queueArr[MAX];
    int front, rear;
public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more tickets.\n";
        } else {
            if (front == -1) 
                front = 0;
            queueArr[++rear] = ticket;
            cout << "Ticket '" << ticket << "' added.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No ticket to process.\n";
        } else {
            cout << "Processing ticket: '" << queueArr[front] << "'\n";
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
        } else {
            cout << "\nPending Tickets (Front ? Rear):\n";
            for (int i = front; i <= rear; i++) {
                cout << " - " << queueArr[i] << "\n";
            }
        }
    }

    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to cancel.\n";
            return;
        }

        bool found = false;
        int n = rear - front + 1;
        string temp[MAX];
        int idx = 0;

        for (int i = front; i <= rear; i++) {
            if (queueArr[i] == ticket && !found) {
                found = true;  // skip this one
                continue;
            }
            temp[idx++] = queueArr[i];
        }

        if (!found) {
            cout << "Ticket '" << ticket << "' not found.\n";
            return;
        }

        rear = -1;
        front = -1;
        for (int i = 0; i < idx; i++)
            enqueue(temp[i]);

        cout << "Ticket '" << ticket << "' canceled.\n";
    }
};

int main() {
    TicketQueue tq;
    int choice;
    string ticket;

    do {
        cout << "\n===== Customer Ticketing System =====\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display Tickets\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Cancel Ticket\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter ticket name: ";
                getline(cin, ticket);
                tq.enqueue(ticket);
                break;
            case 2:
                tq.dequeue();
                break;
            case 3:
                tq.display();
                break;
            case 4:
                cout << (tq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5:
                cout << (tq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 6:
                cout << "Enter ticket to cancel: ";
                getline(cin, ticket);
                tq.cancelTicket(ticket);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
