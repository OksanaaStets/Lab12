#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void inputData(Date &date);
string getDayOfWeek(const Date &date);
void displayResult(const Date &date);

int main() {
    try {
        Date birthDate;
        inputData(birthDate);
        displayResult(birthDate);
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }
    return 0;
}

void inputData(Date &date) {
    cout << "Enter year of birth (>= 1960): ";
    cin >> date.year;
    if (date.year < 1960) {
        throw out_of_range("Year must be 1960 or later.");
    }

    cout << "Enter month of birth (1-12): ";
    cin >> date.month;
    if (date.month < 1 || date.month > 12) {
        throw invalid_argument("Month must be between 1 and 12.");
    }

    cout << "Enter day of birth (1-31): ";
    cin >> date.day;
    if (date.day < 1 || date.day > 31) {
        throw invalid_argument("Day must be between 1 and 31.");
    }
}

string getDayOfWeek(const Date &date) {
    int y = date.year;
    int m = date.month;
    int d = date.day;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int K = y % 100;
    int J = y / 100;

    int f = d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
    int dayOfWeek = f % 7;

    switch (dayOfWeek) {
        case 0: return "Saturday";
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
        default: throw logic_error("Calculated day of the week is out of range.");
    }
}

void displayResult(const Date &date) {
    string dayOfWeek = getDayOfWeek(date);
    cout << "You were born on a " << dayOfWeek << "." << endl;
}