#include <iostream>
#include <cmath>
using namespace std;

const int maxsize = 100;

struct Terms {
    int coefficient;
    int exponent;
};

class Polynomial {
private:
    Terms terms[maxsize];
    int total_terms;

public:
    Polynomial() : total_terms(0) {}

    void read_poly();
    void dis_poly();
    double evaluate(double value);
    Polynomial add(Polynomial B);
};

void Polynomial::read_poly() {
    cout << "Read polynomial:" << endl;
    cout << "Enter total number of terms: ";
    cin >> total_terms;
    for (int i = 0; i < total_terms; i++) {
        cout << "Enter exponent of term " << i + 1 << ": ";
        cin >> terms[i].exponent;
        cout << "Enter coefficient of term " << i + 1 << ": ";
        cin >> terms[i].coefficient;
    }
}

void Polynomial::dis_poly() {
    if (total_terms == 0) {
        cout << "The polynomial is: 0" << endl;
        return;
    }

    cout << "The polynomial is: ";
    for (int i = 0; i < total_terms; i++) {
        if (i > 0 && terms[i].coefficient > 0) {
            cout << " + ";
        }
        cout << terms[i].coefficient << "X^" << terms[i].exponent;
    }
    cout << endl;
}

double Polynomial::evaluate(double value) {
    double result = 0;
    for (int i = 0; i < total_terms; i++) {
        result += terms[i].coefficient * pow(value, terms[i].exponent);
    }
    return result;
}
Polynomial Polynomial :: add(Polynomial B){
int i=0;
int j=0;
int k=0;
Polynomial C;
while(i<total_terms && j<B.total_terms){
if(terms[i].exponent==B.terms[j].exponent){
C.terms[k].coefficient=terms[i].coefficient + B.terms[j].coefficient;
C.terms[k].exponent=terms[i].exponent;
i++;
j++;
k++;
}
else if(terms[i].exponent > B.terms[j].exponent){
C.terms[k].coefficient = terms[i].coefficient;
C.terms[k].exponent = terms[i].exponent;
i++;
k++;
}
else {
    C.terms[k].coefficient = B.terms[j].coefficient;
C.terms[k].exponent = B.terms[j].exponent;
j++;
k++;
}
}
while(i<total_terms){
    C.terms[k].coefficient = terms[i].coefficient;
C.terms[k].exponent = terms[i].exponent;
i++;
k++;
}
while(j<B.total_terms){
    C.terms[k].coefficient =B.terms[j].coefficient;
C.terms[k].exponent = B.terms[j].exponent;
j++;
k++;
}
C.total_terms=k-1;
return C;
}




int main() {
    Polynomial A, B, C;
    double evalvalue;

    cout << "Enter polynomial A:" << endl;
    A.read_poly();
    cout << "Enter polynomial B:" << endl;
    B.read_poly();

    cout << "Polynomial A: ";
    A.dis_poly();
    cout << "Polynomial B: ";
    B.dis_poly();

   cout<<"Enter the value of variable for A: "<<endl;
    cin >> evalvalue;
    cout << "Evaluation of A is: " << A.evaluate(evalvalue) << endl;

    cout<<"Enter the value of variable for B: "<<endl;
    cin >> evalvalue;
    cout << "Evaluation of B is: " << B.evaluate(evalvalue) << endl;
    cout<<"Addition of two polynomials is : ";
    C=A.add(B);
    C.dis_poly();

    return 0;
}