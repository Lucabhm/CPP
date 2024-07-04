// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include <iostream>

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ){return (_nbAccounts);}
	static int	getTotalAmount( void ){return (_totalAmount);}
	static int	getNbDeposits( void ){return (_totalNbDeposits);}
	static int	getNbWithdrawals( void ){return (_totalNbWithdrawals);}
	static void	displayAccountsInfos( void )
	{
		std::cout << "index:" << _nbAccounts << ";";
		std::cout << "total:" << _totalAmount << ";";
		std::cout << "deposits:" << _totalNbDeposits << ";";
		std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
	}

	Account( int initial_deposit )
	{
		_nbAccounts = 0;
		_totalAmount = 0;
		_totalNbWithdrawals = 0;
		_accountIndex = 0;
		_amount = 0;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_totalNbDeposits = initial_deposit;
	}
	~Account( void );

	void	makeDeposit( int deposit )
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "deposit:" << deposit << ";";
		_amount += deposit;
		std::cout << "amount:" << _amount << ";";
		_nbDeposits++;
		std::cout << "nb_deposits:" << _nbDeposits << std::endl;
		_totalNbDeposits++;
	}
	bool	makeWithdrawal( int withdrawal )
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		if (withdrawal < _amount)
		{
			_amount -= withdrawal;
			std::cout << "amount:" << _amount << ";";
			_nbWithdrawals++;
			std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
			_totalNbWithdrawals++;
			return (true);
		}
		else
		{
			std::cout << "withdrawal:refused" << std::endl;
			return (false);
		}
	}
	// int		checkAmount( void ) const;
	void	displayStatus( void ) const
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "deposits:" << _nbDeposits << ";";
		std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
	}


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	// static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
