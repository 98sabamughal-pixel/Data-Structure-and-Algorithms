#include <iostream>
#include <string>
using namespace std;

#define MAX 100   

class BookStack {
private:
    string books[MAX];
    int top;

public:
    BookStack() {
        top = -1;
    }
    void push(string bookName) {
        if (top == MAX - 1) {
            cout << "Stack is full. Cannot add more books.\n";
        } else {
            top++;
            books[top] = bookName;
            cout << "Book added successfully.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No book to remove.\n";
        } else {
            cout << "Removed Book: " << books[top] << endl;
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top Book: " << books[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No books in stack.\n";
        } else {
            cout << "Books in Stack (Top to Bottom):\n";
            for (int i = top; i >= 0; i--) {
                cout << "- " << books[i] << endl;
            }
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    BookStack stack;
    int choice;
    string bookName;

    do {
        cout << "\n--- Book Management System ---\n";
        cout << "1. Add Book (Push)\n";
        cout << "2. Remove Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter book name: ";
            getline(cin, bookName);
            stack.push(bookName);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.peek();
            break;

        case 4:
            stack.display();
            break;

        case 5:
            if (stack.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
