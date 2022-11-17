//
// Created by Denni on 2022-11-17.
//

#include <cstdio>
#include <stdexcept>
#include "ch5.h"

using namespace std;


struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};


struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld -> %ld: %f\n", from, to, amount);
    }
};


struct ConsoleLogger : Logger {

    explicit ConsoleLogger(const char* name) : name{ name } {

    }

    void log_transfer(long from, long to, double amount) override {
        printf("%s [cons] %ld -> %ld: %f\n", name, from, to, amount);
    }

private:
    const char* name;
};


struct Account {
    long id;
    double amount;
};


struct AccountDatabase {
    virtual ~AccountDatabase() = default;

    virtual double get_amount(long id) = 0;
    virtual void set_amount(long id, double amount) = 0;
};


struct InMemoryDatabase : AccountDatabase {

    explicit InMemoryDatabase(size_t accounts_max)
        : accounts_max{ accounts_max },
        accounts {} {}

    double get_amount(const long id) override {
        Account& account = find_account(id);
        return account.amount;
    }

    void set_amount(const long id, const double amount) override {
        Account& account = find_account(id);
        account.amount = amount;
    }

    void set_accounts(const Account new_accounts[], size_t new_accounts_len) {
        if (accounts_max < new_accounts_len) {
            throw invalid_argument("Error: new_accounts_len cannot be smaller than accounts_max");
        }

        accounts = new Account[accounts_max];
        for (size_t i = 0; i < new_accounts_len; i++) {
            accounts[i] = new_accounts[i];
        }
    }

private:
    Account* accounts;
    size_t accounts_max;

    Account& find_account(long id) {
        for (size_t i = 0; i < accounts_max; i++) {
            if (&accounts[i] == nullptr) {
                break;
            }
            if (accounts[i].id == id) {
                return accounts[i];
            }
        }
    }
};


struct Bank {

    explicit Bank(Logger& logger, AccountDatabase& accountDatabase)
        : logger { logger },
        accountDatabase{ accountDatabase } {}

    void make_transfer(long from, long to, double amount) {
        auto from_balance = accountDatabase.get_amount(from);
        auto to_balance = accountDatabase.get_amount(to);
        if (from_balance < amount) {
            throw invalid_argument("Error: not enough balance");
        }

        accountDatabase.set_amount(from, from_balance - amount);
        accountDatabase.set_amount(to, to_balance + amount);

        logger.log_transfer(from, to, amount);
    }

private:
    Logger& logger;
    AccountDatabase& accountDatabase;
};


int ch5::main()
{
    // Run-time polymorphism
    ConsoleLogger logger{ "Bank" };
    InMemoryDatabase database{ 10 };
    Bank bank{ logger, database };

    auto accounts = new Account[] {
        Account{ 1000, 1000 },
        Account{ 2000, 10 },
        Account{ 4000, 5 }
    };
    database.set_accounts(accounts, 3);

    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    return 0;
}
