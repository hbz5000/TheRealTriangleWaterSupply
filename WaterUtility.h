#ifndef WaterUtility_h
#define WaterUtility_h

#include "global.h"
#include "TimeSeriesData.h"
#include "InsuranceFund.h"

class WaterUtility
{
	public:
	
	WaterUtility();
	~WaterUtility();
	
	string name;
	
	data_t UnitDemand;
	data_t FutureDemand;
	data_t FutureBreakdown;
	data_t usePatterns, useFractions, useFractions_Restrictions;
	double riskOfFailure, probReach;
	double *storageRisk, *riskVolume;
	double *inflows1DIrr , *inflows1DNon, *demand1DIrr, *demand1DNon;
	double **inflows2DIrr, **inflows2DNon, **demand2DIrr, **demand2DNon;
	double **actualPDF;
	
	TimeSeriesData UD; // unit demand
	InsuranceFund Fund;
	
	// Objective Values to Minimize
	double maxFailures, totalLosses, peakDebt, expectedNPC;
	
	// Running sum of restrictions implemented each year
	double annualRevenue;
		
	// Restriction triggers on/off. Row: 0/1 for Irrigation/Non-Irrigation. Column: Restriction tier (0-stages) 
	double **restrictionsOnTemplate, **restrictionsOffTemplate;
	double *restrictionsOnTemplateROF, *restrictionsOffTemplateROF;
	
	// Transfer trigger decision variables
	double TTriggerI, TTriggerN, insuranceUse;
	// Transfer trigger, translated into reservoir storage volume
	double TTrigger;
	
	// Storage amount (fraction of full)
	double storageFraction;
	
	// Restriction stage (0 means no restrictions)
	int restrictionStage;
	double restrictionReduction;
	
	// Usage tier info. Cost per million gallons. Usage reductions during restrictions.
	double **reductions;
	double **costPerMG, **consumerSurplusPerMG;
	
	double insurancePayment;
	double *restrictionsOn, *restrictionsOff;
	double **data2, **data3, **data31, **data32, **data4;
	double **fractionPricing;
	double *totalFailures;
	double **individualReductions;
	
	// Demand PDF (fixed number of discrete buckets)
	int **PDFIrr, **PDFNon, **CDFIrr, **CDFNon;
	
	int numMonths, numYears, numTypes, numTiers, numStages, numAnnualDecisionPeriods, numFutureYears, terminateYear, numRealizations;
	int *elasticityIndex;
	
	// Give user the option of a single price list, or both for irrigation/non-irrigation seasons
	double *waterPrice, *waterPrice_Irr, *waterPrice_NonIrr;
	double **droughtSurcharges;
	double **demandBaseline, **demandVariation;
	double weeklyTransferTriggers;
	double averageUse;
	double futureDemand[51];
	double futureDemandBreakdown[5][51];
	
	double jordanLakeAlloc, annualPayment, failurePoint;
	double yearlyFailure;
	vector <double> annualCosts;
	
	double weeklyDemand, restrictedDemand,demandDeficit, weeklyTransferVolume;
	double ROF_resIns;	
	double insurancePremium;
	bool shouldAllocate;
	double infRisk, infTrigger;
	double westernWakeTreatmentFrac;
	double **infMatrix;
	int infrastructureCount;
	double **annualPayments;
	double **annualInsurance;
	double *netPresentCostInfrastructure;
	int thisYearRestrictions;
	double *restrictionFreq;
	double maxRestrictions;
	double peakInsurance;
	double insuranceRevenue;
	double infBuffer;
	
	//~~~~~~~~~~~~~~~~ Public functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void calcWaterPrice(double elasticity_Of_Demand[]);
	void calcSurchargePrice(double elasticity_Of_Demand[], int constant);
	void configure(int nmonths, int nyears, int ntypes, int ntiers, int nstages, int nfutureyears, double failure, int nannualdecisionperiods, int terminateYear,
		int volumeInc, int numRealizations, int formulation, int infCount);
	void clearVariablesForSimulation();
	void clearVariablesForRealization(int year);
	void fillRestrictionsArray(int season);
	int getPDFIndex(double inflow);
	void annualUpdate(int year, int realization);
	void weeklyUpdate();
	void calculateObjectives();
	void writeInflowDemandPDF(int InflowR, int UDr, int rows_PDF, int cols_PDF, double size1, double size2, int irrC, int nonC1, int nonC2, TimeSeriesData* Inflows);
	void generateDemandVariation(int numWeeks, TimeSeriesData *Inflows, double demand_variation_multiplier);
	void calculateRestrictions(int year, int week, int numdays, int month, int realization);
    void setCapacity(double cap);
	void addCapacity(double cap);
	void setInsurancePayment(double dB, double inflw, int wk);
	void calculateDemand(int realizations, int week, int numdays, int year);
	int startNewInfrastructure(int year);
	int buildInfrastructure(int index);
	void addDebt(int yr, int rlztn, double amt, int repayYears, double rt);
	void addInsStorage(double add);
	void priceInsurance(int yr, int rlztn);
	void payForTransfers(double tC);
	
	//~~~~~~~~~~~~~~~~ Private class members ~~~~~~~~~~~~~~~~~~~~~~~
	private:
	
	int currentPDFIndex;
	bool usesROF;
	int volumeIncrements;
	bool anyThresholdExceeded(double threshold, double **ssq);
	bool tierIsResidential(int tier);
	void getCurrentUtilityPrices(int month, int tier, int stage, double &currentPrice, double &currentSewerPrice, double &currentSewerFraction, double &droughtMultiplier);
};

#endif
