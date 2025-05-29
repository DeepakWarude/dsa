#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char stack[50];
    int max;
    int top;

public:
    Stack() {
        max = 50;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max - 1;
    }

    void push(char element) {
        if (!isFull()) {
            stack[++top] = element;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return stack[top--];
        }
        return '\0';
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << stack[i];
        }
        cout << endl;
    }
};

class Pall {
private:
    string a;
    Stack s;

public:
void read() {
        cout << "Enter the sentence: ";
        getline(cin>>ws, a);
       
    }

void checkPall() ;
};

       void Pall :: checkPall(){
        for (char ch : a) {
            if (isalpha(ch)) {
                s.push(tolower(ch));
            }
        }

     
        bool isPalindrome = true;
        for (char ch : a) {
            if (isalpha(ch)) {
                if (tolower(ch) != s.pop()) {
                    isPalindrome = false;
                    break;
                }
            }
        }

        if (isPalindrome) {
            cout << "The sentence is a palindrome." << endl;
        } else {
            cout << "The sentence is not a palindrome." << endl;
        }
    }


int main() {
    Pall p;
    int c,a;
    do{
    cout<<"1.Enter A Sentence : \n2.check It is Pallindrome : \n3.Exit\nEnter your choice : ";
    cin>>c;
    switch(c){
    case 1:
    p.read();
    break;
    case 2:
    p.checkPall();
    break;
    case 3:
    cout<<"Exit.........!\n";
    break;
    default:
    cout<<"Entered A wrong Choice \n";
    }
    if(c!=3){
    cout<<"Do you want to Continue : 1 for yes 2 for No\n";
    cin>>a;
   
    }
    else{
    a=2;
    }
    }while(a==1);
   
    return 0;
}
