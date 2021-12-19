#pragma once
#ifndef PROJECTIONMANAGER_H
#define PROJECTIONMANAGER_H

#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

class ProjectionManager
{
private:

	unsigned int const QUIT_KEY = 7;

	 double m_initialInvestment;
	 double m_openingAmount;
	 double m_monthlyDeposit;
	 double m_annualInterestRate;
	 unsigned int m_numYears;

	enum MENU_LINES {
		INIT_INVEST_AMT = 1,
		MONTHLY_DEPOSIT = 2,
		ANNUAL_INTEREST = 3,
		NUM_YEARS = 4,
		PRINT_REPORTS = 5,
		RESET = 6
	};

	void PrintReportNoDeposits();			
	void PrintReportWithDeposits();
public:
	ProjectionManager() {
		this->m_initialInvestment = 0;
		this->m_openingAmount = 0;
		this->m_monthlyDeposit = 0;
		this->m_annualInterestRate = 0;
		this->m_numYears = 0;
	}
	ProjectionManager(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears) {
		this->m_initialInvestment = t_initialInvestment;
		this->m_openingAmount = 0;
		this->m_monthlyDeposit = t_monthlyDeposit;
		this->m_annualInterestRate = t_annualInterestRate;
		this->m_numYears = t_numYears;
	}
	// Get and Set methods for private menber variables (denoted by m_)
	void SetInitialInvestment(const double& t_initialInvestment);
	double GetInitialInvestment() const;
	void SetOpeningAmount(const double& t_openingAmount);
	double GetOpeningAmount() const;
	void SetMonthlyDeposit(const double& t_monthlyDeposit);
	double GetMonthlyDeposit() const;
	void SetAnnualInterestRate(const double& t_annualInterestRate);
	double GetAnnualInterestRate() const;
	void SetNumYears(const int& t_numYears);
	unsigned int GetNumYears() const;
	unsigned int GetMonths() const;

	// Method functions for displaying the menu and reports
	void UpdateMenu();						// Display menu and manage menu selection
	void GetMenuInput(MENU_LINES t_line);	// Process input
	void DisplayReports();					// Display interest reports and hold for input
};


#endif // !PROJECTIONMANAGER_H