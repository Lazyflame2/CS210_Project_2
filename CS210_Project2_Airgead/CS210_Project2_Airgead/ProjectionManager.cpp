#include "ProjectionManager.h"

// Get and Set methods for private menber variables (denoted by m_)
void ProjectionManager::SetInitialInvestment(const double& t_initialInvestment) { m_initialInvestment = t_initialInvestment; }
double ProjectionManager::GetInitialInvestment() const { return m_initialInvestment; }
void ProjectionManager::SetOpeningAmount(const double& t_openingAmount) { m_openingAmount = t_openingAmount; }
double ProjectionManager::GetOpeningAmount() const { return m_openingAmount; }
void ProjectionManager::SetMonthlyDeposit(const double& t_monthlyDeposit) { m_monthlyDeposit = t_monthlyDeposit; }
double ProjectionManager::GetMonthlyDeposit() const { return m_monthlyDeposit; }
void ProjectionManager::SetAnnualInterestRate(const double& t_annualInterestRate) { m_annualInterestRate = t_annualInterestRate; }
double ProjectionManager::GetAnnualInterestRate() const { return m_annualInterestRate; }
void ProjectionManager::SetNumYears(const int& t_numYears) { m_numYears = t_numYears; }
unsigned int ProjectionManager::GetNumYears() const { return m_numYears; }
unsigned int ProjectionManager::GetMonths() const { return m_numYears * 12; }

// Display menu and manage menu selection
void ProjectionManager::UpdateMenu() {
	int userIn = -1;
	while (userIn != QUIT_KEY)
	{
		system("cls");								// clear screen and print menu

		cout << ">>>           AIRGEAD BANKING Interest Calculator           <<<" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "After entering requisite data, enter \"5\" to print projections" << endl;
		cout << "---------------------------------------------------------------" << endl;
		cout << "1: Initial Investment Amount: " << GetInitialInvestment() << endl;
		cout << "2: Monthy Deposit Amount: " << GetMonthlyDeposit() << endl;
		cout << "3: Annual Interest Rate: " << GetAnnualInterestRate() << endl;
		cout << "4: Number of Years: " << GetNumYears() << endl;
		cout << "5: Print Reports" << endl;
		cout << "6: Reset" << endl;
		cout << "7: Exit" << endl;
		cout << "Please make a selection 1-7: ";
		cin >> userIn;								// get user input	
		cout << endl;
		if (userIn > 7 || userIn < 0){
			cout << "Invalid Selection, please select enter a number 1-7" << endl;
			Sleep(3000);
		}
		if (userIn == INIT_INVEST_AMT) {
			GetMenuInput(INIT_INVEST_AMT);
		}

		if (userIn == MONTHLY_DEPOSIT) {
			GetMenuInput(MONTHLY_DEPOSIT);

		}

		if (userIn == ANNUAL_INTEREST) {
			GetMenuInput(ANNUAL_INTEREST);
		}

		if (userIn == NUM_YEARS) {
			GetMenuInput(NUM_YEARS);
		}

		if (userIn == PRINT_REPORTS) {
			DisplayReports();

		}
		if (userIn == RESET) {
			// reset data members to 0
			SetInitialInvestment(0);
			SetAnnualInterestRate(0);
			SetMonthlyDeposit(0);
			SetNumYears(0);
		}
		if (userIn == QUIT_KEY) {
			// exit the loop and close the application
			break;
		}
		UpdateMenu();
	}
	exit(0);										// exit the application normally
}

// Display interest reports and hold for input
void ProjectionManager::DisplayReports() {
	system("cls");									// clear screen
	PrintReportNoDeposits();
	PrintReportWithDeposits();
	cout << "Press any key to continue...";
	Sleep(500);
	for (;;) {										// endless loop
		for (unsigned int i = 1; i < 180; ++i) {	// return to menu if a key is pressed
			if (GetAsyncKeyState(i) & 0x8000) {
				UpdateMenu();
				break;
			}
		}
	}
	
}
void ProjectionManager::PrintReportWithDeposits() {
	double l_totalAmount = GetInitialInvestment();
	double l_interestAmount = 0;
	double l_totalYearlyInterest = 0;
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (unsigned int y = 0; y < GetNumYears(); y++)
	{
		l_totalYearlyInterest = 0;
		for (unsigned int m = 0; m < 12; m++) {

			// calc monthly interest
			l_interestAmount = (l_totalAmount + GetMonthlyDeposit()) * ((GetAnnualInterestRate() / 100) / 12);

			// calculate year end interest
			l_totalYearlyInterest = l_totalYearlyInterest + l_interestAmount;

			
			// calculate month end total
			l_totalAmount = l_totalAmount + GetMonthlyDeposit() + l_interestAmount;
			
		}
		// output results
		cout << fixed << setprecision(2) << setw(7) << " " << setw(2) << y+1 << "\t" << setw(10) << "$" << l_totalAmount << "\t" << setw(10) << "$" << l_totalYearlyInterest << endl;
	}
}
void ProjectionManager::PrintReportNoDeposits() {
	double l_totalAmount = GetInitialInvestment();
	double l_interestAmount = 0;
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (unsigned int y = 0; y < GetNumYears(); y++)
	{
		// calculate yearly interest
		l_interestAmount = (l_totalAmount) * ((GetAnnualInterestRate() / 100));


		// calculate year end total
		l_totalAmount = l_totalAmount + l_interestAmount;

		
		// output results
		cout << fixed << setprecision(2) << setw(7) << " " << setw(2) << y + 1 << "\t$" << setw(10) << "$" << l_totalAmount << "\t" << setw(10) << "$" << l_interestAmount << endl;
	}
}

// Handles user input setting appropriate data members
void ProjectionManager::GetMenuInput(MENU_LINES t_line) {
	double tempVal;
	double epsilon = 0.0001;

	switch (t_line)
	{
	case INIT_INVEST_AMT:
		cout << "Initial Investment Amount: ";
		cin >> tempVal;
		cout << endl;
		if ((tempVal - epsilon ) >= 0) {
			SetInitialInvestment(tempVal);
		}
		break;
	case MONTHLY_DEPOSIT:
		cout << "Monthly Deposit: ";
		cin >> tempVal;
		cout << endl;
		if ((tempVal - epsilon) >= 0) {
			SetMonthlyDeposit(tempVal);
		}
		break;
	case ANNUAL_INTEREST:
		cout << "Annual Interest Rate: ";
		cin >> tempVal;
		cout << endl;
		if ((tempVal - epsilon) >= 0) {
			SetAnnualInterestRate(tempVal);
		}
		break;
	case NUM_YEARS:
		cout << "Number Of Years: ";
		cin >> tempVal;
		cout << endl;
		if ((tempVal - epsilon) >= 0) {
			SetNumYears(tempVal);
		}
		break;
	default:
		break;
	}

}
