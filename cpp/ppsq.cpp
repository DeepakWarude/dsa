#include <iostream>
using namespace std;

#define MAX 5  // Maximum number of orders that can be taken

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
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Sorry! Order limit reached. Cannot take more orders.\n";
            return;
        }

        if (front == -1) front = 0;

        rear++;
        orders[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving order: " << orders[front] << endl;
        front++;

        if (front > rear) {
            front = rear = -1; // Reset queue if all orders are served
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        for (int i = front; i <= rear; ++i) {
            cout << orders[i] << " ";
        }
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
