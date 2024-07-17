/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:27:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/17 10:27:32 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit)
{
	static int	i = 0;

	_nbAccounts++;
	_totalNbWithdrawals = 0;
	_accountIndex = i;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalNbDeposits = 0;
	_totalAmount += _amount;
	i++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal < checkAmount())
	{
		_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t currenttime = std::time(0);
	std::tm* localtime = std::localtime(&currenttime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localtime);
	std::cout << buffer;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

int	Account::getNbAccounts(void){return _nbAccounts;}

int	Account::getTotalAmount( void ){return (_totalAmount);}

int	Account::getNbDeposits( void ){return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;