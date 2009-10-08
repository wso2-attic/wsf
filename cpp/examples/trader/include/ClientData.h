#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>


namespace org_wso2_www
{
	class ClientData
	{

	private:
		std::map <std::string,int> stockHoldings;
		std::string _ssn;
		std::string _name;
		std::string _password;
		double  creditAmount;

	public:
		ClientData(){};

		ClientData(std::string ssn, std::string name, std::string password);
		/**
		* Returns social security number                                                   
		*/
		std::string getSSN();
		/**
		* Sets the social security number                                                   
		*/
		void setSSN(std::string ssn);
		/**
		* Returns the current password                                                   
		*/
		std::string getPassword();
		/**
		* Resets the existing password                                                   
		*/
		void setPassword(std::string password);
		/**
		* Resets the name                                                   
		*/
		void setName(std::string name);
		/**
		*	Gets the name                                                   
		*/
		std::string getName();
		/**
		* Sets Credit                                                   
		*/
		void setCredit(double credit);
		/**
		* Gets the credit amount                                                   
		*/
		double getCredit();
		/**
		*                                                    
		* Sets stock holdings
		*/
		void setStock(std::string symbol, int value);
		/**
		*                                                    
		* Get Stock Holding
		*/
		int getStock(std::string symbol);

		~ClientData(void);
	};
}

#endif /* CLIENTDATA_H */
