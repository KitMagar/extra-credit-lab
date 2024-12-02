#include <iostream>
#include <iomanip> 
#include <string>  

using namespace std;

double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);
        if (number != -999999.99) {
            cout << fixed << setprecision(4) << "The input is: " << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

// Function to extract a double-precision number from the string
double extractNumeric(const string& str) {
    bool hasDecimal = false;
    bool hasSign = false;
    bool isValid = true;
    size_t len = str.length();

    if (len == 0 || len > 20) {
        return -999999.99;
    }

    for (size_t i = 0; i < len; ++i) {
        char ch = str[i];

        if (isdigit(ch)) {
            continue;
        } else if (ch == '+' || ch == '-') {
            if (i == 0 && !hasSign) {
                hasSign = true;
            } else {
                isValid = false;
                break;
            }
        } else if (ch == '.') {
            if (!hasDecimal) {
                hasDecimal = true;
            } else {
                isValid = false;
                break;
            }
        } else {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        return -999999.99;
    }

    try {
        size_t pos;
        double result = stod(str, &pos);

        if (pos != len) {
            return -999999.99;
        }

        return result;
    } catch (...) {
        return -999999.99;
    }
}
