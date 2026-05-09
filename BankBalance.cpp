#include <iostream>
#include <map>
#include <string>
using namespace std;

class Bank {
    map<int, int> accounts;

public:
    bool create(int user, int amount) {
        if (accounts.find(user) == accounts.end()) {
            accounts[user] = amount;
            return true;
        } else {
            accounts[user] += amount;
            return false;
        }
    }

    bool debit(int user, int amount) {
        if (accounts.find(user) == accounts.end()) return false;
        if (accounts[user] < amount) return false;
        accounts[user] -= amount;
        return true;
    }

    bool credit(int user, int amount) {
        if (accounts.find(user) == accounts.end()) return false;
        accounts[user] += amount;
        return true;
    }

    int balance(int user) {
        if (accounts.find(user) == accounts.end()) return -1;
        return accounts[user];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        } else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        } else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        } else if (query == "BALANCE") {
            int X;
            cin >> X;
            int bal = bank.balance(X);
            if (bal == -1)
                cout << "ERROR" << endl;
            else
                cout << bal << endl;
        }
    }
    return 0;
}
