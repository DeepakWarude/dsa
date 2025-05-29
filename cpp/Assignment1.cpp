#include<iostream>

using namespace std;

class Set
{
private:
    string s[20];
    int n;

public:
    void read();
    void display();
    Set intersect(Set);
    Set Union(Set);
    Set Difference(Set);

};

void Set::read() //Read the Elements if Set 
{
    cout << "Enter number of Students : ";
    cin >> n;
    cout << "Enter Name of Students : \n";
    string element;

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        bool duplicate = false;
        for (int j = 0; j < i; j++)
        {
            if (s[j] == element)
            {
                duplicate = true;
                break;

            }
        }
        if (!duplicate)
        {
            s[i] = element;
        }
        else {
            cout << "the element cannot be added";
            i--;
        }
    }
}

void Set::display() //Display the elements of Set
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
        for (int j = 1; i < n - 1; j++) {
            cout << ","; break;
        }

    }
    cout << "}";
}

Set Set::intersect(Set B) //Intersection of set A and set B
{
    Set T;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < B.n; j++)
        {
            if (s[i] == B.s[j])
            {
                T.s[k] = s[i];
                k++;
                break;
            }
        }
    }
    T.n = k;
    return T;
}

Set Set::Union(Set B) // Union of set A and set B
{
    Set u;
    int k = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
        u.s[k] = s[i];
        k++;
    }

    for (int j = 0; j < B.n; j++) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == B.s[j]) {
                found = 1;  // Element already exists in set A
                break;
            }
        }
        if (found == 0) {  // If the element is not found in set A
            u.s[k] = B.s[j];
            k++;
        }
    }
    u.n = k;
    return u;
}
Set Set::Difference(Set B) //Difference of Set A and Set B 
{
    Set d;
    int k = 0;
    int h = 0;
    for (int j = 0; j < n; j++) {
        int found = 0;
        for (int i = 0; i < B.n; i++) {
            if (s[i] == B.s[j]) {
                found = 1;  // Element already exists in set A
                break;
            }
        }
        if (found == 0) {  // If the element is not found in set A
            d.s[k] = s[j];
            k++;
        }
    }
    d.n = k;
    return d;
}


int main() {
    Set A, B, A1, B1, C, D, E, F, g, h, i;//Object of class Set
    cout << "Input Coding contest information\n";
    A.read();
    cout << "Coding contest : ";
    A.display();
    cout << " \n\n";

    cout << "Input Project competition information\n";
    B.read();
    cout << "Project competition : ";
    B.display();
    cout << " \n\n";

    cout << "Input Paper Presentation information\n";
    A1.read();
    cout << "Paper presentation : ";
    A1.display();
    cout << "\n\n";
    
    cout << "Input Mastermind information\n";
    B1.read();
    cout << "Mastermind : ";
    B1.display();
    cout << " \n\n";
    int ch;
do{
    cout << "Enter Your Choice\n1.Coding and Project Both.\n2.Coding or Project or Mastermind.\n3.Coding but not Mastermind.\n4.All events.\n";
    
    cin >> ch;

    switch (ch) {
    case 1: cout << "\n" << "Students participated in coding and project :";
        C = A.intersect(B);
        C.display();
        break;

    case 2: cout << "\n" << " Students participated in coding or Project or mastermind :";
        D = A.Union(B);
        E = D.Union(B1);
        E.display();
        break;

    case 3:  F = A.Difference(B1);
        cout << "\n" << "Students Participated in coding but not mastermind: ";
        F.display();

    case 4: cout << "\n" << "Students participated in all events :";
        g = A.intersect(B);
        h = g.intersect(A1);
        i = h.intersect(B1);
        i.display();
        break;

    default:cout << "Invalid Choice";

    }
}while(ch != 4);
    return 0;

}