#ifndef InsuranceFund_h
#define InsuranceFund_h

class InsuranceFund
{
public:
	
	void subtract(double losses);
	void add(double payment);
	void initializeRealization();
	double calcAnnualLosses(double annualRevenue, bool addInterest);
	void getInsuranceStage(double demandBaseline, double inflows);
	void setInsurancePayment(double payment);

	double capacity;
	double fundSize, totalDebit;
	double insuranceStorage, insurancePayment, percentLoss, annualLosses;
	int numDebit, insuranceStage;

private:
	double thing;
	
};	

#endif
