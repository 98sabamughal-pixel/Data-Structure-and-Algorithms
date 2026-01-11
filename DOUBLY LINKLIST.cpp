#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int semester;
    float gpa;
    Student* next;
    Student* prev;
};

Student* head = NULL;


void insertAtBeginning() {
    Student* s = new Student();
    cout << "Enter ID: ";
    cin >> s->id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s->name);
    cout << "Enter Semester: ";
    cin >> s->semester;
    cout << "Enter GPA: ";
    cin >> s->gpa;

    s->prev = NULL;
    s->next = head;

    if (head != NULL)
        head->prev = s;

    head = s;
    cout << "Student added at beginning!"<<endl;
}


void insertAtEnd() {
    Student* s = new Student();
    cout << "Enter ID: ";
    cin >> s->id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s->name);
    cout << "Enter Semester: ";
    cin >> s->semester;
    cout << "Enter GPA: ";
    cin >> s->gpa;

    s->next = NULL;

    if (head == NULL) {
        s->prev = NULL;
        head = s;
        cout << "Student added at end!"<<endl;
        return;
    }

    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = s;
    s->prev = temp;
    cout << "Student added at end!"<<endl;
}


void insertAtPosition() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    Student* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!"<<endl;
        return;
    }

    Student* s = new Student();
    cout << "Enter ID: ";
    cin >> s->id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s->name);
    cout << "Enter Semester: ";
    cin >> s->semester;
    cout << "Enter GPA: ";
    cin >> s->gpa;

    s->next = temp->next;
    s->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = s;

    temp->next = s;
    cout << "Student added at position!"<<endl;
}


void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty!"<<endl;
        return;
    }

    Student* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "Student deleted from beginning!"<<endl;
}


void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!"<<endl;
        return;
    }

    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;
    cout << "Student deleted from end!"<<endl;
}


void deletePosition() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    Student* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position!"<<endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Student deleted from position!"<<endl;
}


void displayForward() {
    if (head == NULL) {
        cout << "No records found!"<<endl;
        return;
    }

    Student* temp = head;
    cout << "\nStudents (Start to End):"<<endl;
    while (temp != NULL) {
        cout << temp->id << " | " << temp->name
             << " | Sem " << temp->semester
             << " | GPA " << temp->gpa << endl;
        temp = temp->next;
    }
}


void displayReverse() {
    if (head == NULL) {
        cout << "No records found!"<<endl;
        return;
    }

    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "\nStudents (End to Start):"<<endl;
    while (temp != NULL) {
        cout << temp->id << " | " << temp->name
             << " | Sem " << temp->semester
             << " | GPA " << temp->gpa << endl;
        temp = temp->prev;
    }
}

int main() {
    int choice;

    do {
        cout << "        Student Enrollment System "<<endl;
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete from Beginning"<<endl;
        cout << "5. Delete from End"<<endl;
        cout << "6. Delete from Position"<<endl;
        cout << "7. Display Forward"<<endl;
        cout << "8. Display Reverse"<<endl;
        cout << "9. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: displayForward(); break;
            case 8: displayReverse(); break;
            case 9: cout << "Program Ended!"<<endl; break;
            default: cout << "Invalid Choice!"<<endl;
        }
    } while (choice != 9);

    return 0;
}
