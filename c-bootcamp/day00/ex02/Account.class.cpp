
#include <ctime>
#include <iostream>

#include "Account.class.hpp"

int Account::getNbAccounts(void) {    
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {    
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {    
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {    
    return Account::_totalNbDeposits;
}

int Account::checkAmount( void ) const {
    return this->_amount;
}

void Account::_displayTimestamp( void ) {
    time_t curr_time;
    tm * curr_tm;
    char date_str[100];
    
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    
    strftime(date_str, 50, "[%Y%m%d_%H%M%S] \0", curr_tm);
    std::cout << date_str; 
}

void Account::displayAccountsInfos( void ) {
    
    Account::_displayTimestamp();    

    std::cout << "accounts:" << Account::_nbAccounts << ";";    
    std::cout << "total:" << Account::_totalAmount << ";";    
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";    
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << "\n";

}

void Account::displayStatus( void ) const {
    
    Account::_displayTimestamp();    

    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";

}


void Account::makeDeposit( int deposit ) {

    Account::_displayTimestamp();

    this->_amount += deposit;
    this->_nbDeposits++;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal( int withdrawal ) {

    Account::_displayTimestamp();
    
    std::cout << "index:" << this->_accountIndex << ";";
    
    if (withdrawal > this->_amount) {
        std::cout << "withdrawal:refused" << "\n";
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals" << this->_nbWithdrawals << "\n";
    return true;
}

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();

    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << "\n";
}

Account::~Account() {

    Account::_displayTimestamp();
    
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << "\n";
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
