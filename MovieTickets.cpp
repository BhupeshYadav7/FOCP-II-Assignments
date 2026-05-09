#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class MovieTicket {
    map<int, int> available;                 
    map<int, set<int>> booked;               

public:
    // BOOK query
    bool book(int customer, int movie) {
        if (booked[customer].count(movie)) return false; 
        if (available[movie] == 0) return false;         

        booked[customer].insert(movie);
        available[movie]--; 
        return true;
    }

    bool cancel(int customer, int movie) {
        if (!booked[customer].count(movie)) return false; 

        booked[customer].erase(movie);
        available[movie]++; 
        return true;
    }

    bool isBooked(int customer, int movie) {
        return booked[customer].count(movie) > 0;
    }
    int availableTickets(int movie) {
        if (available.find(movie) == available.end()) available[movie] = 100; 
        return available[movie];
    }
};

int main() {
    int Q;
    cin >> Q;
    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;
        } else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;
        } else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;
        } else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.availableTickets(Y) << endl;
        }
    }
    return 0;
}
