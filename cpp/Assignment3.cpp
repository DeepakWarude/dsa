/* 
String Operations: Write a menu driven C++ program with a class for
CO1,CO2
String. Write functions
1. To determine the frequency of occurrence of a particular character
in the string.
2. Extract a new string from original string by accepting starting
position and length
3. To accept any character and return the string with by removing all
occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the
string x. Note that w may not be of same size that of x
5. To check whether given string is palindrome or not */

#include <iostream>
#include <string>
using namespace std;

class String {
    string str; 
public: 
    void read();
    void display(); 
    void occurrence();
    void newstr();
    void remove();
    void replaceChar(); 
    void replace_substr();
    void whitespace();
    void palindrome(); 
};

void String::read() {
    cout << "Enter String: "; 
    getline(cin, str); 
}

void String::display() {
    cout << str << endl; 
}

void String::occurrence() {
    int count = 0; 
    char ch;
    cout << "Enter the character to find its frequency of occurrence: "; 
    cin >> ch; 
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ch) {
            count++; 
        }
    }
    if (count != 0) {
        cout << "The character " << ch << " occurs " << count << " times." << endl; 
    } else {
        cout << "The character is not present in the string" << endl; 
    }
}

void String::newstr() {
    int pos, end;
    cout << "Enter the start and end positions for new string: ";
    cin >> pos >> end;

    if (pos < 0 || end < 0 || pos >= str.length() || end >= str.length() || pos > end) {
        cout << "Invalid positions!" << endl;
    }
    string result;

    for (int i = pos-1; i <= end-pos+1; i++) {
        result += str[i];  
    }

    cout << "New string is: " << result << endl;
}

void String::remove() {
    string result;
    char ch; 
    cout << "Enter the character to be deleted in the string: ";
    cin >> ch; 
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ch) {
            result += str[i]; 
        }
    }
    cout << "Updated string is: " << result << endl; 
}

void String::replaceChar() {
    char oldChar, newChar; 
    cout << "Enter the character you want to replace and the character to replace it with: ";
    cin >> oldChar >> newChar; 
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar; 
        }
    }
    cout << "Updated string after replacing a character is: " << str << endl;
}

void String::replace_substr() {
    string w, x;
    cout << "Enter the substring to replace: ";
    cin >> w;
    cout << "Enter the new substring: ";
    cin >> x;

    int w_len = w.length();
    int x_len = x.length();
    int str_len = str.length();

    for (int i = 0; i <= str_len - w_len; i++) {
        bool match = true;
        for (int j = 0; j < w_len; j++) {
            if (str[i + j] != w[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            if (x_len > w_len) {
                for (int j = str_len - 1; j >= i + w_len; j--) {
                    str[j + x_len - w_len] = str[j];
                }
            }

            for (int j = 0; j < x_len; j++) {
                str[i + j] = x[j];
            }

            if (x_len < w_len) {
                for (int j = i + x_len; j < str_len; j++) {
                    str[j] = str[j + (w_len - x_len)];
                }
                str[str_len - (w_len - x_len)] = '\0';
            }

            i += x_len - 1;
            str_len = str.length();
        }
    }
    cout << "Updated string after replacing substring: " << str << endl;
}


void String::palindrome() {
    bool ispal = true; 
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            ispal = false; 
            break; 
        }
    }
    if (ispal) {
        cout << "String is palindrome" << endl;
    } else {
        cout << "String is not a palindrome" << endl; 
    }
}

void String::whitespace() {
    string result;
    bool firstSpace = false; // To track if the first whitespace has been added
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (!firstSpace) {
                result += str[i];  // Add the first whitespace
                firstSpace = true; // Set the flag to true after the first space
            }
        } else {
            result += str[i];  // Add non-whitespace characters
        }
    } 
    cout << "Updated string after removing whitespaces: " << result << endl;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Find frequency of occurrences of a particular character." << endl;
    cout << "2. Extract a new string from the original string." << endl;
    cout << "3. Input any character and return string without it." << endl;
    cout << "4. Replace a character." << endl;
    cout << "5. Replace substring." << endl;
    cout << "6. Check for palindrome." << endl;
    cout << "7. Remove whitespaces in a string" << endl; 
    cout << "8. Exit." << endl; 
    cout << "Enter your choice: "; 
}

int main() {
    String s; 
    int choice; 
    s.read(); 
    s.display(); 
    do {
        displayMenu(); 
        cin >> choice; 
        switch(choice) {
            case 1: 
                s.occurrence(); 
                break; 
            case 2 : 
                s.newstr(); 
                break; 
            case 3 : 
                s.remove(); 
                break; 
            case 4 : 
                s.replaceChar(); 
                break; 
            case 5: 
                s.replace_substr();
                break; 
            case 6 : 
                s.palindrome();
                break; 
            case 7: 
            	s.whitespace();
            	break; 
            case 8 : 
                cout << "Exiting..." << endl;
                break; 
            default :
                cout << "Invalid choice!" << endl; 
                break; 
        }
    } while (choice != 8); 
    return 0; 
}

