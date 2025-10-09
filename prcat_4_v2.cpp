#include <iostream>
using namespace std;

struct DNode {
    int info;
    DNode* next;
    DNode* prev;
};

typedef struct DNode DND;

DND* LP = NULL;
DND* RP = NULL;

int DV_Check_Null(DND* ptr) {
    if (ptr == NULL) {
        cout << "List is Empty" << endl;
        return 1;
    } else {
        return 0;
    }
}

void DV_Insert_Node(int value) {
    DND* newNode = new DND;
    newNode->info = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (LP == NULL) {
        LP = RP = newNode;
    } else {
        RP->next = newNode;
        newNode->prev = RP;
        RP = newNode;
    }
}

void getInfoAt(int position) {
    if (DV_Check_Null(LP)) return;

    DND* temp = LP;
    int index = 0;

    while (temp != NULL) {
        if (index == position) {
            cout << "Data at position " << position << ": " << temp->info << endl;
            return;
        }
        temp = temp->next;
        index++;
    }

    cout << "Position out of bounds." << endl;
}

void updateInfoAt(int position, int newValue) {
    if (DV_Check_Null(LP)) return;

    DND* temp = LP;
    int index = 0;

    while (temp != NULL) {
        if (index == position) {
            temp->info = newValue;
            cout << "Updated node at position " << position << " to " << newValue << endl;
            return;
        }
        temp = temp->next;
        index++;
    }

    cout << "Position out of bounds." << endl;
}

void searchValue(int value) {
    if (DV_Check_Null(LP)) return;

    DND* temp = LP;
    int position = 0;

    while (temp != NULL) {
        if (temp->info == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Value " << value << " not found in list." << endl;
}

void displayList() {
    if (DV_Check_Null(LP)) return;

    DND* temp = LP;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->info << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, value, position;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Check if list is empty\n";
        cout << "2. Insert node\n";
        cout << "3. Get information at position\n";
        cout << "4. Update information at position\n";
        cout << "5. Search for value\n";
        cout << "6. Display list\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                DV_Check_Null(LP);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                DV_Insert_Node(value);
                break;
            case 3:
                cout << "Enter position to retrieve info: ";
                cin >> position;
                getInfoAt(position);
                break;
            case 4:
                cout << "Enter position to update: ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> value;
                updateInfoAt(position, value);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;
            case 6:
                displayList();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
