#include <iostream>
using namespace std;

#define MAX 5  // Maximum number of orders that can be placed

class PizzaParlor {
private:
    int orders[MAX];
    int front, rear;

public:
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % MAX);
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Sorry! Order limit reached. Cannot take more orders.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving order: " << orders[front] << endl;

        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        int i = front;

        for(i=front; i<=rear; i=(i+1)%MAX){
            cout << orders[i] << " ";
            if (i == rear) break;
        }

        // while (true) {
        //     cout << orders[i] << " ";
        //     if (i == rear) break;
        //     i = (i + 1) % MAX;
        // }
        cout << endl;
    }
};

int main() {
    PizzaParlor p;
    int choice, orderID = 1;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p.placeOrder(orderID++);
            break;
        case 2:
            p.serveOrder();
            break;
        case 3:
            p.displayOrders();
            break;
        case 4:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
