#include <iostream>
using namespace std;
class Node {
public:
    int patientID;
    Node* next;

    Node(int id) {
        patientID = id;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    
    void insertAtEnd(int id) {
        Node* newNode = new Node(id);

        if (head == NULL) {  
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtBeginning(int id) {
        Node* newNode = new Node(id);
        newNode->next = head;
        head = newNode;
    }

    void displayPatients() {
        if (head == NULL) {
            cout << "No patients in the list.\n";
            return;
        }

        Node* temp = head;
        cout << "Current Patients: ";
        while (temp != NULL) {
            cout << temp->patientID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList hospital;
    int choice, id;

    while (true) {
        cout << "\n--- Patient Management System ---\n";
        cout << "1. Add new patient (End)\n";
        cout << "2. Add emergency patient (Beginning)\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                hospital.insertAtEnd(id);
                break;

            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                hospital.insertAtBeginning(id);
                break;

            case 3:
                hospital.displayPatients();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
    }
       }
	     	}
