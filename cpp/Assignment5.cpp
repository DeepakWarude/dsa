#include<iostream>
using namespace std;

void addpoly(int poly1[][2], int terms1, int poly2[][2], int terms2, int result[][2], int &resultTerms) {
    int i = 0, j = 0;
    resultTerms = 0;
    while (i < terms1 && j < terms2) {
        if (poly1[i][1] == poly2[j][1]) {
            result[resultTerms][0] = poly1[i][0] + poly2[j][0];
            result[resultTerms][1] = poly1[i][1];
            i++; j++; resultTerms++;
        }
        else if (poly1[i][1] > poly2[j][1]) {
            result[resultTerms][0] = poly1[i][0];
            result[resultTerms][1] = poly1[i][1];
            resultTerms++; i++;
        }
        else {
            result[resultTerms][0] = poly2[j][0];
            result[resultTerms][1] = poly2[j][1];
            resultTerms++; j++;
        }
    }
    while (i < terms1) {
        result[resultTerms][0] = poly1[i][0];
        result[resultTerms][1] = poly1[i][1];
        resultTerms++; i++;
    }
    while (j < terms2) {
        result[resultTerms][0] = poly2[j][0];
        result[resultTerms][1] = poly2[j][1];
        resultTerms++; j++;
    }
}

void printPolynomial(int poly[][2], int terms) {
    for (int i = 0; i < terms; i++) {
        if (i > 0 && poly[i][0] > 0)
            cout << "+";
        cout << poly[i][0] << "x^" << poly[i][1] << " ";
    }
    cout << endl;
}

void readPolynomial(int poly[][2], int &terms) {
    cout << "Enter number of terms: ";
    cin >> terms;
    cout << "Enter terms in the format (coefficient exponent), in descending order of exponent:\n";
    for (int i = 0; i < terms; i++) {
        cout << "Term " << i + 1 << ": ";
        cin >> poly[i][0] >> poly[i][1];
    }
}

int main() {
    int poly1[20][2], poly2[20][2], result[40][2];
    int terms1 = 0, terms2 = 0, resultTerms = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Read Polynomial 1\n";
        cout << "2. Read Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readPolynomial(poly1, terms1);
                break;
            case 2:
                readPolynomial(poly2, terms2);
                break;
            case 3:
                cout << "Polynomial 1: ";
                printPolynomial(poly1, terms1);
                break;
            case 4:
                cout << "Polynomial 2: ";
                printPolynomial(poly2, terms2);
                break;
            case 5:
                addpoly(poly1, terms1, poly2, terms2, result, resultTerms);
                cout << "Resultant Polynomial after Addition: ";
                printPolynomial(result, resultTerms);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
