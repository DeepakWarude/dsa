#include <iostream>
using namespace std;

struct Appointment {
    int startHour; // in 24-hour format
    int endHour;
    Appointment* next;
};

Appointment* head = nullptr;
const int START_TIME = 9;
const int END_TIME = 17;

// Check if a slot is already booked
bool isBooked(int hour) {
    Appointment* temp = head;
    while (temp != nullptr) {
        if (temp->startHour == hour)
            return true;
        temp = temp->next;
    }
    return false;
}

// 1. Display free slots
void displayFreeSlots() {
    cout << "\nFree Slots:\n";
    for (int hour = START_TIME; hour < END_TIME; hour++) {
        if (!isBooked(hour)) {
            cout << hour << ":00 - " << hour + 1 << ":00\n";
        }
    }
}

// 2. Book appointment
void bookAppointment(int hour) {
    if (hour < START_TIME || hour >= END_TIME) {
        cout << "Invalid time. Working hours are from 9 to 17.\n";
        return;
    }

    if (isBooked(hour)) {
        cout << "Slot already booked.\n";
        return;
    }

    Appointment* newNode = new Appointment{hour, hour + 1, nullptr};

    if (!head || head->startHour > hour) {
        newNode->next = head;
        head = newNode;
    } else {
        Appointment* current = head;
        while (current->next && current->next->startHour < hour)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
    }

    cout << "Appointment booked from " << hour << ":00 to " << hour + 1 << ":00\n";
}

// 3. Cancel appointment
void cancelAppointment(int hour) {
    if (!head) {
        cout << "No appointments to cancel.\n";
        return;
    }

    Appointment* temp = head;
    Appointment* prev = nullptr;

    while (temp && temp->startHour != hour) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Appointment at " << hour << ":00 not found.\n";
        return;
    }

    if (!prev) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Appointment at " << hour << ":00 canceled.\n";
}

// 4. Sort list based on time (data swapping)
void sortAppointmentsDataSwap() {
    if (!head || !head->next)
        return;

    for (Appointment* i = head; i->next; i = i->next) {
        for (Appointment* j = i->next; j; j = j->next) {
            if (i->startHour > j->startHour) {
                swap(i->startHour, j->startHour);
                swap(i->endHour, j->endHour);
            }
        }
    }

    cout << "Appointments sorted by time (data swap).\n";
}

// 5. Sort list using pointer manipulation
void sortAppointmentsPointerSwap() {
    if (!head || !head->next)
        return;

    Appointment* sorted = nullptr;

    while (head) {
        Appointment* curr = head;
        head = head->next;

        if (!sorted || curr->startHour < sorted->startHour) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Appointment* temp = sorted;
            while (temp->next && temp->next->startHour < curr->startHour) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }

    head = sorted;
    cout << "Appointments sorted by time (pointer manipulation).\n";
}

// Display booked appointments
void displayAppointments() {
    if (!head) {
        cout << "No appointments scheduled.\n";
        return;
    }

    cout << "\nBooked Appointments:\n";
    Appointment* temp = head;
    while (temp) {
        cout << temp->startHour << ":00 - " << temp->endHour << ":00\n";
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\n---- Appointment Management System ----\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Booked Appointments\n";
        cout << "5. Sort Appointments (Data Swap)\n";
        cout << "6. Sort Appointments (Pointer Manipulation)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int hour;
        switch (choice) {
            case 1:
                displayFreeSlots();
                break;
            case 2:
                cout << "Enter appointment start time (9 - 16): ";
                cin >> hour;
                bookAppointment(hour);
                break;
            case 3:
                cout << "Enter appointment time to cancel: ";
                cin >> hour;
                cancelAppointment(hour);
                break;
            case 4:
                displayAppointments();
                break;
            case 5:
                sortAppointmentsDataSwap();
                break;
            case 6:
                sortAppointmentsPointerSwap();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
