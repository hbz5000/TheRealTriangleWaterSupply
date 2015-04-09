#include "global.h"
#include "ReservoirStorage.h"

using namespace std;

//ReservoirStorage::ReservoirStorage()
//{
//}

void ReservoirStorage::buildULexp()
{
	ULCapacity = 2999.0;
}
void ReservoirStorage::buildCCexp()
{
	CCRCapacity = 5909.0;
}
void ReservoirStorage::buildSQlow()
{
	StQCapacity = 1700.0;
}
void ReservoirStorage::buildSQhigh()
{
	StQCapacity = 2400.0;
}
void ReservoirStorage::buildTeerQuarry()
{
	teerQuarryIntakeCapacity = 15.0;
	teerQuarryOutflowCapacity = 5.2;
}
void ReservoirStorage::buildReclaimedLow()
{
	durhamReclaimedCapacity = 2.2;
}
void ReservoirStorage::buildReclaimedHigh()
{
	durhamReclaimedCapacity = 11.3;
}
void ReservoirStorage::buildMichieLow()
{
	durhamCapacity = 8849.0;
}
void ReservoirStorage::buildMichieHigh()
{
	durhamCapacity = 14049.0;
}
void ReservoirStorage::buildLittleRiverRal()
{
	littleRiverRaleighCapacity = 3700.0;
}
void ReservoirStorage::buildRalQuarry()
{
	raleighQuarryCapacity = 4000.0;
	raleighQuarryIntakeCapacity = 50.0;
	raleighQuarryOutflowCapacity = 18.7;
}
void ReservoirStorage::buildNeuseIntake()
{
	raleighIntakeCapacity = 16.0;
}
void ReservoirStorage::reallocateFallsLake(double fallsLakeReallocation)
{
	fallsLakeSupplyCapacity += fallsLakeReallocation;
	fallsLakeQualityCapacity -= fallsLakeReallocation;
	fallsLakeSupplyStorage += fallsLakeReallocation;
	fallsLakeQualityStorage -= fallsLakeReallocation;
	if(fallsLakeQualityStorage < 0)
	{
		fallsLakeSupplyStorage += fallsLakeQualityStorage;
		fallsLakeQualityStorage = 0;
	}
}
void ReservoirStorage::buildWWWTPlow(double oWTPf, double dWTPf, double rWTPf)
{
	westernTreatmentCapacity = 33.0;
	owasaWWTPcapacity = westernTreatmentCapacity*oWTPf;
	durhamWWTPcapacity = westernTreatmentCapacity*dWTPf;
	raleighWWTPcapacity = westernTreatmentCapacity*rWTPf;
	if(raleighWWTPcapacity>RaleighDurhamCapacity)
	{
		raleighWWTPcapacity = RaleighDurhamCapacity;
	}
}
void ReservoirStorage::buildWWWTPhigh(double oWTPf, double dWTPf, double rWTPf)
{
	westernTreatmentCapacity = 54.0;
	owasaWWTPcapacity = westernTreatmentCapacity*oWTPf;
	durhamWWTPcapacity = westernTreatmentCapacity*dWTPf;
	raleighWWTPcapacity = westernTreatmentCapacity*rWTPf;
	if(raleighWWTPcapacity>RaleighDurhamCapacity)
	{
		raleighWWTPcapacity = RaleighDurhamCapacity;
	}
}
	

void ReservoirStorage::initializeReservoirStorage(double durhamCap, double CCRCap, double StQCap, double ULCap, double lakeWBCap, double fallsLakeSupplyCap, double fallsLakeQualityCap, double jordanSupplyCap, double jordanQualityCap, double CaryTreatmentCap, double DurhamCaryCap, double DurhamOWASACap, double RaleighCaryCap, double RaleighDurhamCap, double raleighJordanAlloc, double durhamJordanAlloc, double owasaJordanAlloc, double caryJordanAlloc, double teerQCap, double tQIc, double tQOc, double littleRiverRaleighCap, double westTrtCap, double durhamRecCap, double rQc, double rQIc, double rQOc, double rIc, double cQc, double cQIc, double cQOc, double owasaWWWTPFrac, double durhamWWWTPFrac, double raleighWWWTPFrac, int sig)
{
	//Set reservoir capacities and initial storage volumes
	//Durham Storage infrastructure
	durhamCapacity=durhamCap;//Durham capacity
	durhamStorage=durhamCap;//Initial storage set to capacity
	durhamReclaimedCapacity = durhamRecCap;///Durham reclaimed water capacity
	teerQuarryCapacity = teerQCap;
	teerQuarryStorage = teerQCap;
	teerQuarryIntakeCapacity = tQIc;
	teerQuarryOutflowCapacity = tQOc;
	
	////OWASA Storage infrastructure
	CCRCapacity = CCRCap;//OWASA Cane Creek reservoir capacity
	CCRStorage = CCRCap;//Initial storage set to capacity
	ULCapacity = ULCap;//OWASA University Lake reservoir capacity
	ULStorage = ULCap;//Initial storage set to capacity
	StQCapacity = StQCap;//OWASA Stone Quarry reservoir capacity
	StQStorage = StQCap;//Initial storage set to capacity
	OWASACapacity = CCRCap+StQCap+ULCap;//OWASA total capacity
	OWASAStorage = OWASACapacity;//Initial storage set to capacity
	
	////Raleigh Storage infrastructure
	lakeWBCapacity = lakeWBCap;//Raleigh Lakes Wheeler and Benson capacity
	lakeWBStorage = lakeWBCap;//Initial storage set to capacity
	fallsLakeSupplyCapacity = fallsLakeSupplyCap;//Capacity of Falls Lake Water Supply allocation
	fallsLakeQualityCapacity = fallsLakeQualityCap;//Capacity of Falls Lake Water Quality allocation
	fallsLakeSupplyStorage = fallsLakeSupplyCap;//Initial storage set to capacity
	fallsLakeQualityStorage = fallsLakeQualityCap;//Initial storage set to capacity
	littleRiverRaleighCapacity = littleRiverRaleighCap;//Little River Reservoir capacity
	littleRiverRaleighStorage = littleRiverRaleighCap;//Initial storage set to capacity
	raleighQuarryCapacity = rQc;
	raleighQuarryStorage = 0.0;//quarry starts empty
	raleighQuarryIntakeCapacity = rQIc;//maximum quarry filling rate
	raleighQuarryOutflowCapacity = rQOc;//maximum withdrawls from quarry
	raleighIntakeCapacity = rIc;//maximum withdrawl from Neuse intake
	
	
	////Cary Storage Infrastructure
	caryQuarryCapacity = cQc;
	caryQuarryStorage = 0.0;//quarry starts empty
	caryQuarryIntakeCapacity = cQIc;//maximum quarry filling rate
	caryQuarryOutflowCapacity = cQOc;//maximum withdrawls from quarry

	
	////Interconnections
	DurhamCaryCapacity = DurhamCaryCap;//Capacity of the Durham Cary interconnection
	DurhamOWASACapacity = DurhamOWASACap;//Capacity of the Durham OWASA interconnection
	RaleighCaryCapacity = RaleighCaryCap;//Capacity of the Raleigh Cary interconnection
	RaleighDurhamCapacity = RaleighDurhamCap;//Capacity of the Raleigh Durham interconnection
	
	////Jordan Lake treatment Plants
	CaryTreatmentCapacity = CaryTreatmentCap;//Cary WTP capacity
	westernTreatmentCapacity =westTrtCap;////Western Wake WTP capacity
	owasaWWTPcapacity = westernTreatmentCapacity*owasaWWWTPFrac;
	durhamWWTPcapacity = westernTreatmentCapacity*durhamWWWTPFrac;
	raleighWWTPcapacity = westernTreatmentCapacity*raleighWWWTPFrac;
	if(raleighWWTPcapacity>RaleighDurhamCapacity)
	{
		raleighWWTPcapacity = RaleighDurhamCapacity;
	}
	
	////Jordan Lake accounting
	jordanLakeSupplyCapacity = jordanSupplyCap;
	jordanLakeQualityCapacity = jordanQualityCap;
	jordanLakeSupplyStorage = jordanSupplyCap;
	jordanLakeQualityStorage = jordanQualityCap;

		///Raleigh
	raleighAllocation = raleighJordanAlloc;//Raleigh allocation to jordan Lake
	raleighJordanCapacity = raleighJordanAlloc*jordanLakeSupplyCapacity;
	raleighJordanStorage = raleighJordanCapacity;
		///Cary
	caryAllocation = caryJordanAlloc;//Cary allocation to jordan lake
	caryJordanCapacity = caryJordanAlloc*jordanLakeSupplyCapacity;
	caryJordanStorage = caryJordanCapacity;
		///Durham
	durhamAllocation = durhamJordanAlloc;//Durham allocation to jordan lake
	durhamJordanCapacity = durhamJordanAlloc*jordanLakeSupplyCapacity;
	durhamJordanStorage = durhamJordanCapacity;
		///OWASA
	owasaAllocation = owasaJordanAlloc;// owasa allocation to jordan lake
	owasaJordanCapacity = owasaJordanAlloc*jordanLakeSupplyCapacity;
	owasaJordanStorage = owasaJordanCapacity;
		///Inflow fractions (how to divide the inflows to respective allocations)
	jordanQualityFraction = 94600.0/(45800.0+94600.0);
	jordanRaleighFraction = raleighAllocation*45800.0/(94600.0+45800.0);
	jordanDurhamFraction = durhamAllocation*45800.0/(94600.0+45800.0);
	jordanCaryFraction = caryAllocation*45800.0/(94600.0+45800.0);
	jordanOWASAFraction = owasaAllocation*45800.0/(94600.0+45800.0);

	durhamRequest = 0;//Durham intial transfer request
	owasaRequest = 0;//OWASA initial transfer request
	raleighRequest = 0;//Raleigh initial transfer request
	
	thingCounter = sig;
	
	return;
}
void ReservoirStorage::initializeReservoirStorageROF(double durhamCap, double CCRCap, double StQCap, double ULCap, double lakeWBCap, double fallsLakeSupplyCap, double fallsLakeQualityCap, double jordanSupplyCap, double jordanQualityCap, double CaryTreatmentCap, double DurhamCaryCap, double DurhamOWASACap, double RaleighCaryCap, double RaleighDurhamCap, double raleighJordanAlloc, double durhamJordanAlloc, double owasaJordanAlloc, double caryJordanAlloc, double teerQCap, double tQIc, double tQOc,  double littleRiverRaleighCap, double westTrtCap, double durhamRecCap, double rQc, double rQIc, double rQOc, double rIc, double cQc, double cQIc, double cQOc, double owasaWWWTPFrac, double durhamWWWTPFrac, double raleighWWWTPFrac, int sig)
{
	//Set reservoir capacities and initial storage volumes
	//Durham Storage infrastructure
	durhamCapacity=durhamCap;//Durham capacity
	durhamReclaimedCapacity = durhamRecCap;///Durham reclaimed water capacity
	teerQuarryCapacity = teerQCap;
	teerQuarryIntakeCapacity = tQIc;
	teerQuarryOutflowCapacity = tQOc;
	
	////OWASA Storage infrastructure
	CCRCapacity = CCRCap;//OWASA Cane Creek reservoir capacity
	ULCapacity = ULCap;//OWASA University Lake reservoir capacity
	StQCapacity = StQCap;//OWASA Stone Quarry reservoir capacity
	OWASACapacity = CCRCap+StQCap+ULCap;//OWASA total capacity
	
	////Raleigh Storage infrastructure
	lakeWBCapacity = lakeWBCap;//Raleigh Lakes Wheeler and Benson capacity
	fallsLakeSupplyCapacity = fallsLakeSupplyCap;//Capacity of Falls Lake Water Supply allocation
	fallsLakeQualityCapacity = fallsLakeQualityCap;//Capacity of Falls Lake Water Quality allocation
	littleRiverRaleighCapacity = littleRiverRaleighCap;//Little River Reservoir capacity
	raleighQuarryCapacity = rQc;
	raleighQuarryIntakeCapacity = rQIc;//maximum quarry filling rate
	raleighQuarryOutflowCapacity = rQOc;//maximum withdrawls from quarry
	raleighIntakeCapacity = rIc;//maximum withdrawl from Neuse intake
	
	
	////Cary Storage Infrastructure
	caryQuarryCapacity = cQc;
	caryQuarryIntakeCapacity = cQIc;//maximum quarry filling rate
	caryQuarryOutflowCapacity = cQOc;//maximum withdrawls from quarry
	
	////Interconnections
	DurhamCaryCapacity = DurhamCaryCap;//Capacity of the Durham Cary interconnection
	DurhamOWASACapacity = DurhamOWASACap;//Capacity of the Durham OWASA interconnection
	RaleighCaryCapacity = RaleighCaryCap;//Capacity of the Raleigh Cary interconnection
	RaleighDurhamCapacity = RaleighDurhamCap;//Capacity of the Raleigh Durham interconnection
	
	////Jordan Lake treatment Plants
	CaryTreatmentCapacity = CaryTreatmentCap;//Cary WTP capacity
	westernTreatmentCapacity =westTrtCap;
	owasaWWTPcapacity = westernTreatmentCapacity*owasaWWWTPFrac;
	durhamWWTPcapacity = westernTreatmentCapacity*durhamWWWTPFrac;
	raleighWWTPcapacity = westernTreatmentCapacity*raleighWWWTPFrac;
	if(raleighWWTPcapacity>RaleighDurhamCapacity)
	{
		raleighWWTPcapacity = RaleighDurhamCapacity;
	}


	////Jordan Lake accounting
	jordanLakeSupplyCapacity = jordanSupplyCap;
	jordanLakeQualityCapacity = jordanQualityCap;

		///Raleigh
	raleighAllocation = raleighJordanAlloc;//Raleigh allocation to jordan Lake
	raleighJordanCapacity = raleighJordanAlloc*jordanLakeSupplyCapacity;
		///Cary
	caryAllocation = caryJordanAlloc;//Cary allocation to jordan lake
	caryJordanCapacity = caryJordanAlloc*jordanLakeSupplyCapacity;
		///Durham
	durhamAllocation = durhamJordanAlloc;//Durham allocation to jordan lake
	durhamJordanCapacity = durhamJordanAlloc*jordanLakeSupplyCapacity;
		///OWASA
	owasaAllocation = owasaJordanAlloc;// owasa allocation to jordan lake
	owasaJordanCapacity = owasaJordanAlloc*jordanLakeSupplyCapacity;
		///Inflow fractions (how to divide the inflows to respective allocations)
	jordanQualityFraction = 94600.0/(45800.0+94600.0);
	jordanRaleighFraction = raleighAllocation*45800.0/(94600.0+45800.0);
	jordanDurhamFraction = durhamAllocation*45800.0/(94600.0+45800.0);
	jordanCaryFraction = caryAllocation*45800.0/(94600.0+45800.0);
	jordanOWASAFraction = owasaAllocation*45800.0/(94600.0+45800.0);

	durhamRequest = 0;//Durham intial transfer request
	owasaRequest = 0;//OWASA initial transfer request
	raleighRequest = 0;//Raleigh initial transfer request
	thingCounter = sig;
	
	return;
}

void ReservoirStorage::updateReservoirStorageROF(double durhamS, double teerS, double CCRS, double ULS, double STQS, double owasaS, double lakeWBS, double flSS, double flQS, double jlSS, double jlQS, double caryJordanS, double raleighJordanS, double durhamJordanS, double owasaJordanS, double littleRiverRalS, double raleighQS)
{
	//Same as above, allowing for variable initial reservoir storage
	durhamStorage=durhamS;
	teerQuarryStorage = teerS;
	CCRStorage = CCRS;
	ULStorage = ULS;
	StQStorage = STQS;
	OWASAStorage = owasaS;
	lakeWBStorage = lakeWBS;
	fallsLakeSupplyStorage = flSS;
	fallsLakeQualityStorage = flQS;
	jordanLakeSupplyStorage = jlSS;
	jordanLakeQualityStorage = jlQS;
	durhamRequest = 0;//Durham intial transfer request
	owasaRequest = 0;//OWASA initial transfer request
	raleighRequest = 0;//Raleigh initial transfer request
	caryJordanStorage = caryJordanS;
	raleighJordanStorage = raleighJordanS;
	durhamJordanStorage = durhamJordanS;
	owasaJordanStorage = owasaJordanS;
	littleRiverRaleighStorage = littleRiverRalS;
	raleighQuarryStorage = raleighQS;
	caryQuarryStorage = 0;
	return;
}
void ReservoirStorage::updateReservoirStorageROF()
{
	//Same as above, allowing for variable initial reservoir storage
	durhamStorage=durhamCapacity;
	teerQuarryStorage = teerQuarryCapacity;
	CCRStorage = CCRCapacity;
	ULStorage = ULCapacity;
	StQStorage = StQCapacity;
	OWASAStorage = OWASACapacity;
	lakeWBStorage = lakeWBCapacity;
	fallsLakeSupplyStorage = fallsLakeSupplyCapacity;
	fallsLakeQualityStorage = fallsLakeQualityCapacity;
	jordanLakeSupplyStorage = jordanLakeSupplyCapacity;
	jordanLakeQualityStorage = jordanLakeQualityCapacity;
	durhamRequest = 0;//Durham intial transfer request
	owasaRequest = 0;//OWASA initial transfer request
	raleighRequest = 0;//Raleigh initial transfer request
	caryJordanStorage = caryJordanCapacity;
	raleighJordanStorage = raleighJordanCapacity;
	durhamJordanStorage = durhamJordanCapacity;
	owasaJordanStorage = owasaJordanCapacity;
	littleRiverRaleighStorage = littleRiverRaleighCapacity;
	raleighQuarryStorage = raleighQuarryCapacity;
	caryQuarryStorage = 0;
	return;
}
void ReservoirStorage::openResFiles()
{
	openFile(out2, "reservoirOutput2.csv");
	return;
}

void ReservoirStorage::setDemands(double durham, double owasa, double raleigh, double cary, int numberOfDaysInTheWeek)
{
	durhamUse = durham - durhamReclaimedCapacity;
	OWASAUse = owasa;
	CaryUse = cary;
	raleighUse = raleigh;
	numdays = numberOfDaysInTheWeek;
	return;
}

void ReservoirStorage::getReturnRatios(double raleighR, double durhamR)
{
	raleighReturn = raleighR;
	durhamReturn = durhamR;
	return;
}

void ReservoirStorage::calcTransfers(double transferDurham, double durhamRisk, double transferOWASA, double owasaRisk, double transferRaleigh, double raleighRisk, double OWASAD)
{
	double durhamRequestO;
	double owasaRequestO;
	double raleighRequestO;
	//Determines how much water each utility needs to request to reach an acceptable risk-of-failure
	if (owasaRisk>transferOWASA)
		owasaRequestO = 1.0;
	else
		owasaRequestO = 0.0;
			
	if (durhamRisk>transferDurham)
		durhamRequestO = 1.0;
	else
		durhamRequestO = 0.0;
	
	if (raleighRisk>transferRaleigh)
		raleighRequestO = 1.0;
	else
		raleighRequestO = 0.0;
		
	////Cary wants at least a 5 MGD buffer of unused capacity in its treatment plant
	caryTreatmentBuffer = 5.0*numdays;
	
	////Peaking factor at the Cary WTP used to move from daily capacity to average weekly capacity
	caryPeakingFactor = .85;
	
	//Total spare capacity to sell transfers at the Cary WTP
	caryExtraCapacity = (CaryTreatmentCapacity*numdays - caryTreatmentBuffer)*caryPeakingFactor - CaryUse;
	
	////Capacity of the Durham/OWASA interconnection is 7 MGD
	DurhamOWASACapacity = 7*numdays;
	
	//Weekly capacity of the Durham-Cary interconnection
	double DCCap = DurhamCaryCapacity*numdays;
	
	//Weekly capacity of the Raleigh-Cary interconnection
	double RCCap = RaleighCaryCapacity*numdays;
	double raleighExtra = 0.0;
	double raleighExtraToDurham = 0.0;
	double raleighExtraToOWASA = 0.0;
	double durhamExtra = 0.0;
	
	/////OWASA must maintain at least 3 MGD production in its own treatment plant
	/////Transfers to OWASA cannot reduce OWASA domestic production below  3 MGD
	double OWASAminimumUse = 3.0*numdays;
	if (OWASAD-DurhamOWASACapacity<OWASAminimumUse)
	{
		DurhamOWASACapacity = OWASAD-OWASAminimumUse;
	}
	if (DurhamOWASACapacity<0.0)
	{
		DurhamOWASACapacity = 0.0;
	}
	
	//No transfers if Cary does not have the extra treatment capacity
	if (caryExtraCapacity<0.0)
	{
		caryExtraCapacity=0.0;
		durhamRequest = 0.0;
		owasaRequest = 0.0;
		raleighRequest = 0.0;
	}
	else///////////////check infrastructure constraints
	{
		////////Check Cary WTP (through line 480)
		/////Figure out transfers as if the Cary WTP is the limiting factor
		durhamRequest = (caryExtraCapacity*durhamRisk*durhamRequestO)/(raleighRisk*raleighRequestO+owasaRisk*owasaRequestO+durhamRisk*durhamRequestO+.00001);
		
		owasaRequest = (caryExtraCapacity*owasaRisk*owasaRequestO)/(raleighRisk*raleighRequestO+owasaRisk*owasaRequestO+durhamRisk*durhamRequestO+.00001);
		
		raleighRequest = (caryExtraCapacity*raleighRisk*raleighRequestO)/(raleighRisk*raleighRequestO+owasaRisk*owasaRequestO+durhamRisk*durhamRequestO+.00001);
		
		////Make sure each utility gets at least 25% of cary capacity
		double transferFloor = .25;
		if(durhamRequest < transferFloor*caryExtraCapacity*durhamRequestO)
		{
			durhamRequest = transferFloor*caryExtraCapacity*durhamRequestO;
			
			owasaRequest = ((caryExtraCapacity-durhamRequest)*owasaRisk*owasaRequestO)/(raleighRisk*raleighRequestO+owasaRisk*owasaRequestO+.00001);
			
			raleighRequest = ((caryExtraCapacity-durhamRequest)*raleighRisk*raleighRequestO)/(raleighRisk*raleighRequestO+owasaRisk*owasaRequestO+.00001);
			
			if(owasaRequest < transferFloor*caryExtraCapacity*owasaRequestO)
			{
				owasaRequest = transferFloor*caryExtraCapacity*owasaRequestO;
				
				raleighRequest = (caryExtraCapacity-durhamRequest-owasaRequest)*raleighRequestO;
			}
			if(raleighRequest < transferFloor*caryExtraCapacity*raleighRequestO)
			{
				raleighRequest = transferFloor*caryExtraCapacity*raleighRequestO;
				
				owasaRequest = (caryExtraCapacity - durhamRequest - raleighRequest)*owasaRequestO;
			}
		}
		if(owasaRequest < transferFloor*caryExtraCapacity*owasaRequestO)
		{
			owasaRequest = transferFloor*caryExtraCapacity*owasaRequestO;
			
			durhamRequest = ((caryExtraCapacity-owasaRequest)*durhamRisk*durhamRequestO)/(raleighRisk*raleighRequestO+durhamRisk*durhamRequestO+.00001);
			
			raleighRequest = ((caryExtraCapacity-owasaRequest)*raleighRisk*raleighRequestO)/(raleighRisk*raleighRequestO+durhamRisk*durhamRequestO+.00001);
			
			if(durhamRequest < transferFloor*caryExtraCapacity*durhamRequestO)
			{
				durhamRequest = transferFloor*caryExtraCapacity*durhamRequestO;
				
				raleighRequest = (caryExtraCapacity-durhamRequest-owasaRequest)*raleighRequestO;
			}
			if(raleighRequest < transferFloor*caryExtraCapacity*raleighRequestO)
			{
				raleighRequest = transferFloor*caryExtraCapacity*raleighRequestO;
				
				durhamRequest = (caryExtraCapacity - owasaRequest - raleighRequest)*durhamRequestO;
			}
		}
		if(raleighRequest < transferFloor*caryExtraCapacity*raleighRequestO)
		{
			raleighRequest = transferFloor*caryExtraCapacity*raleighRequestO;
			
			durhamRequest = ((caryExtraCapacity-raleighRequest)*durhamRisk*durhamRequestO)/(owasaRisk*owasaRequestO+durhamRisk*durhamRequestO+.00001);
			
			owasaRequest = ((caryExtraCapacity-raleighRequest)*owasaRisk*owasaRequestO)/(owasaRisk*owasaRequestO+durhamRisk*durhamRequestO+.00001);
			
			if(durhamRequest < transferFloor*caryExtraCapacity*durhamRequestO)
			{
				durhamRequest = transferFloor*caryExtraCapacity*durhamRequestO;
				
				owasaRequest = (caryExtraCapacity-durhamRequest-raleighRequest)*owasaRequestO;
			}
			if(owasaRequest < transferFloor*caryExtraCapacity*owasaRequestO)
			{
				owasaRequest = transferFloor*caryExtraCapacity*owasaRequestO;
				
				durhamRequest = (caryExtraCapacity - owasaRequest - raleighRequest)*durhamRequestO;
			}
		}
		
	
		///////////Check for conveyence constraints
		///////Raleigh capacity constraint
		if (raleighRequest>RCCap)//Make sure Raleigh's request does not exceed its interconnection capacity
		{
			raleighExtra = raleighRequest - RCCap;//If Raleigh can not take all of the water allotted to it, the extra water is available to Durham and OWASA
			raleighRequest = RCCap;
			if ((durhamRequest+owasaRequest+raleighExtra) > DCCap)//Make sure Durham can take all the additional water (all water to Durham and OWASA must go through Durham)
			{
				raleighExtra = DCCap - durhamRequest - owasaRequest;
			}
			
			/////If Durham-Cary interconnection is limiting, available water is divided between urham & OWASA based on relative risk of failure
					
			raleighExtraToDurham = raleighExtra*durhamRisk*durhamRequestO/(durhamRisk*durhamRequestO+owasaRisk*owasaRequestO+.00001);
				
			raleighExtraToOWASA = raleighExtra*owasaRisk*owasaRequestO/(durhamRisk*durhamRequestO+owasaRisk*owasaRequestO+.00001);
				
			durhamRequest += raleighExtraToDurham;
			owasaRequest += raleighExtraToOWASA;
			/////make sure owasa doesnt take more than its connection between durham & owasa
			if(owasaRequest>DurhamOWASACapacity)
			{
				durhamRequest += owasaRequest - DurhamOWASACapacity;
				owasaRequest = DurhamOWASACapacity;
			}
		}
		if ((durhamRequest+owasaRequest) > DCCap)//Make sure Durham/OWASA's request does not exceed ints interconnection capacity
		{	
			/////If Durham-Cary interconnection is limiting, available water is divided between Durham & OWASA based on relative risk of failure
			durhamExtra = durhamRequest + owasaRequest - DCCap;
			durhamRequest = DCCap*durhamRisk*durhamRequestO/(durhamRisk*durhamRequestO+owasaRisk*owasaRequestO+.00001);
			
			owasaRequest = DCCap*owasaRisk*owasaRequestO/(durhamRisk*durhamRequestO+owasaRisk*owasaRequestO+.00001);
			if(owasaRequest>DurhamOWASACapacity)
			{
				durhamRequest += owasaRequest - DurhamOWASACapacity;
				owasaRequest = DurhamOWASACapacity;
			}
			raleighRequest += durhamExtra;
			if (raleighRequest>RCCap)//Make sure Raleigh can take all the additional water
			{
				raleighRequest = RCCap;
			}
		}
	}
	
	durhamUse -= durhamRequest;
	
	OWASAUse -= owasaRequest;
	raleighUse -= raleighRequest;
	
	return;
}

void ReservoirStorage::setInflow(double durham, double ccr, double ul, double stq, double falls, double wb, double clayton, double crabtree, double jordan, double lillington,
									double ralRet, double durRet, double durRet2, double owasaRet, double evaporationf, double evaporationwb, double evaporation, double ltlRvrRal)
{
	durhamInflow = durham;//Inflows to Durham Reservoirs
	CCRInflow = ccr;//Inflows to Cane Creek Reservoir
	ULInflow = ul;//Infow to University Lake
	StQInflow = stq;//Inflow to Stone Quarry
	fallsInflow = falls;//Inflow to Falls Lake
	wbInflow = wb;//Inflow to Wheeler Benson
	claytonInflow = clayton;//Inflow to clayton gauge
	crabtreeInflow = crabtree;//Inflow to Crabtree Creek
	jordanInflow = jordan;//Inflow to Jordan Lake
	lillingtonInflow = lillington;//Inflows to lillington Gauge
	raleighReturn = ralRet;//Raleigh WW Returns downstream of Falls Lake
	durhamReturn = durRet;//Durham WW Returns to the Neuse Basin
	durhamReturn2 = durRet2;//Durham WW Returns to the Cape Fear Basin
	owasaReturn = owasaRet;//OWASA WW Returns to Cape Fear Basin
	evapF = evaporationf;//Evaporation from Falls Lake
	evapWB = evaporationwb;//Evaporation from Wheeler and Benson
	evap = evaporation;//Evaporation from Durham and OWASA
	littleRiverRaleighInflow = ltlRvrRal;//Inflows to Raleigh's little river reservoir
	return;
}

void ReservoirStorage::setSpillover(int week)
{
	if (week <21 || week>47)//Spillage rules for Durham Reservoir at Little River
	{
		durhamSpillage = 3.877*numdays;
		raleighLittleRiverSpillage = 3.877*numdays;
	}
	else
	{
		durhamSpillage = 9.05;
		raleighLittleRiverSpillage = 9.05;
	}
	
	if (week>7&&week<16)
	{
		enoSpillage = numdays*30/1.54;
	}
	else
	{
		enoSpillage = numdays*10.0/1.54;
	}
	
	if(lakeWBStorage <0.3*lakeWBCapacity)
	{
		lakeWBSpillage = numdays/1.547;
	}
	else if(lakeWBStorage < 0.6*lakeWBCapacity)
	{
		lakeWBSpillage = 2.0*numdays/1.547;
	}
	else
	{
		lakeWBSpillage = 3.0*numdays/1.547;
	}
	/////Determining Jordan Lake environmental releases - from Jordan Lake Water Quality Pool
	/////Jordan Lake environmental flows must hit minimum reservoir releases and minimum downstream flow targets
	if (jordanLakeQualityStorage/jordanLakeQualityCapacity>.4)
	{
		jordanLakeMinRelease = 25.8527*numdays;
		////releases at reservoir must be at least 25.8 MGD
		
		/////downstream flow requirements are based on current storage in Jordan Lake Quality Pool
		if (jordanLakeQualityStorage/jordanLakeQualityCapacity>.8)
		{
			if(jordanLakeMinRelease+lillingtonInflow<387.7901*numdays)
			{
				jordanLakeMinRelease = 387.7901*numdays-lillingtonInflow;
				//////flows at downstream gauge must be at least 387.8 MGD
			}
		}
		else if(jordanLakeQualityStorage/jordanLakeQualityCapacity>.6)
		{
			if(jordanLakeMinRelease+lillingtonInflow<290.8426*numdays)
			{
				jordanLakeMinRelease = 290.8426*numdays-lillingtonInflow;
				//////flows at downstream gauge must be at least 387.8 MGD
			}
		}
		else
		{
			if(jordanLakeMinRelease+lillingtonInflow<193.8951*numdays)
			{
				jordanLakeMinRelease = 193.8951*numdays-lillingtonInflow;
				//////flows at downstream gauge must be at least 387.8 MGD
			}
		}
	}
	////during extremely low storage conditions, downstream flow requirements are abandoned and 
	////minimum releases are decreased
	else if (jordanLakeQualityStorage/jordanLakeQualityCapacity>.2)
	{
		jordanLakeMinRelease = 129.2634*numdays;
	}
	else
	{
		jordanLakeMinRelease = 64.6317*numdays;
	}

	
	return;
}
double ReservoirStorage::updateOWASAStorage()
{

	////OWASA transfers are added to Cane Creek Reservoir Storage
	CCRStorage+=owasaRequest;
	double OWASADemand1 = 0.0;////OWASA demands from Western Wake WTP
	double OWASADemand2 = 0.0;////OWASA demands from Jones Ferry WTP
	if(owasaJordanStorage + OWASAStorage > 0.0)
	{
		OWASADemand1 = OWASAUse*(owasaJordanStorage/(owasaJordanStorage+OWASAStorage));
		OWASADemand2 = OWASAUse*(OWASAStorage/(owasaJordanStorage+OWASAStorage));
		if(OWASADemand2 < 3.0*numdays)
		{
			OWASADemand1 += OWASADemand2 - 3.0*numdays;
			OWASADemand2 = 3.0*numdays;
		}
		if(OWASADemand1>owasaWWTPcapacity)
		{
			OWASADemand2 += OWASADemand1 - owasaWWTPcapacity;
			OWASADemand1 = owasaWWTPcapacity;
		}
	}
	else
	{
		OWASADemand1 = 0.0;
		OWASADemand2 = OWASAUse;
	}
	
	//Spillage calculated from Cane Creek Reservoir - based on inflow to CCR
	if (CCRInflow > 1.797*7)
		OWASASpillage = 1.797*7;
	else if (CCRInflow < .1422*7)
		OWASASpillage = .1422*7;
	else
		OWASASpillage = CCRInflow;
		
	//No environmental flow requirements for Stone Quarry, spillage is based on capacity constraints
	if (StQStorage +StQInflow - 10*evap>StQCapacity)
	////Stone quarry has a surface area of 10 acres
	{
		StQSpillage = StQStorage + StQInflow -10*evap - StQCapacity;
		StQStorage = StQCapacity;
	}
	else
	{
		StQStorage = StQStorage + StQInflow - 10*evap;
		StQSpillage = 0;
	}
	owasaExcess = 0.0;
	//OWASA has three reservoirs, and they use water from their different reservoirs depending on storage levels
	if ((ULStorage + ULInflow + StQSpillage - 212*evap - OWASADemand2) > .75*ULCapacity)
	/////University Lake Inflows include Stone Quarry Spillage
	/////Surface area of University Lake is 212 acres
	{
		////All use comes from University Lake
		ULStorage = ULStorage + ULInflow + StQSpillage - 212*evap - OWASADemand2;
		if (ULStorage > ULCapacity)
		{
			OWASASpillage += ULStorage - ULCapacity;
			owasaExcess += ULStorage - ULCapacity;
			ULStorage = ULCapacity;
		}
		////No use from Cane Creek Reservoir (Cane Creek Reservoir surface area is 500 acres)
		CCRStorage = CCRStorage +CCRInflow - 500*evap - OWASASpillage;
		if (CCRStorage > CCRCapacity)
		{
			OWASASpillage += CCRStorage - CCRCapacity;
			owasaExcess += CCRStorage - CCRCapacity;
			CCRStorage = CCRCapacity;
		}
	}
	else if ((ULStorage + ULInflow + StQSpillage - 212*evap)< .25*ULCapacity)
	{
		if (OWASADemand2<70)
		{
			////No water use comes from University Lake
			ULStorage = ULStorage + ULInflow + StQSpillage - 212*evap;
			if (ULStorage > ULCapacity)
			{
				OWASASpillage += ULStorage - ULCapacity;
				owasaExcess += ULStorage - ULCapacity;
				ULStorage = ULCapacity;
			}
		
			////All water use come from Cane Creek Reservoir
			CCRStorage = CCRStorage +CCRInflow - 500*evap - OWASASpillage - OWASADemand2;
			if (CCRStorage > CCRCapacity)
			{
				OWASASpillage += CCRStorage - CCRCapacity;
				owasaExcess += CCRStorage - CCRCapacity;
				CCRStorage = CCRCapacity;
			}
		}
		else
		{
			////First 70 MG comes from Cane Creek Reservoir, remainder comes from University Lake
			ULStorage = ULStorage + ULInflow + StQSpillage - 212*evap - (OWASADemand2 - 70);
			if (ULStorage > ULCapacity)
			{
				OWASASpillage += ULStorage - ULCapacity;
				owasaExcess += ULStorage - ULCapacity;
				ULStorage = ULCapacity;
			}
		
			CCRStorage = CCRStorage +CCRInflow - 500*evap - OWASASpillage - 70;
			if (CCRStorage > CCRCapacity)
			{
				OWASASpillage += CCRStorage - CCRCapacity;
				owasaExcess += CCRStorage - CCRCapacity;
				CCRStorage = CCRCapacity;
			}
		}
	}
	else if ((ULStorage + ULInflow + StQSpillage - evap*212)> .5*OWASADemand2)
	{
		////half of the water use comes from University Lake
		ULStorage = ULStorage + ULInflow + StQSpillage - 212*evap - .5*OWASADemand2;
		if (ULStorage > ULCapacity)
		{
			OWASASpillage += ULStorage - ULCapacity;
			owasaExcess += ULStorage - ULCapacity;
			ULStorage = ULCapacity;
		}
		
		////half of the water use comes from cane Creek Reservoir
		CCRStorage = CCRStorage +CCRInflow - 500*evap - OWASASpillage - .5*OWASADemand2;
		if (CCRStorage > CCRCapacity)
		{
			OWASASpillage += CCRStorage - CCRCapacity;
			owasaExcess += CCRStorage - CCRCapacity;
			CCRStorage = CCRCapacity;
		}
	}
	else if ((CCRStorage + CCRInflow -evap*500 - OWASASpillage)>OWASADemand2)
	{
		ULStorage = ULStorage + ULInflow + StQSpillage - 212*evap;
		if (ULStorage > ULCapacity)
		{
			OWASASpillage += ULStorage - ULCapacity;
			owasaExcess += ULStorage - ULCapacity;
			ULStorage = ULCapacity;
		}
		////all water use comes from Cane Creek Reservoir
		CCRStorage = CCRStorage +CCRInflow - 500*evap - OWASASpillage - OWASADemand2;
		if (CCRStorage > CCRCapacity)
		{
			OWASASpillage += CCRStorage - CCRCapacity;
			owasaExcess += CCRStorage - CCRCapacity;
			CCRStorage = CCRCapacity;	
		}
	}
	else
	{
		////water needs not met, Stone Quarry emptied into Cane Creek
		ULStorage = ULStorage + ULInflow + StQSpillage - evap*212;
		CCRStorage = CCRStorage + CCRInflow - 500*evap - OWASASpillage;
		CCRStorage = CCRStorage + StQStorage + ULStorage;
		ULStorage = 0;
		StQStorage = 0;
		CCRStorage = CCRStorage - OWASADemand2;
	}
	////non-negativity
	if (CCRStorage<0)
	{
		CCRStorage = 0;
	}
	if (ULStorage<0)
	{
		ULStorage = 0;
	}
	if (StQStorage<0)
	{
		StQStorage = 0;
	}
	//////aggregating OWASA Storage
	OWASAStorage = CCRStorage + ULStorage + StQStorage;
	return OWASADemand1;
}
double ReservoirStorage::updateDurhamStorage()
{
	double durhamDemand1 = 0.0;
	double durhamDemand2 = 0.0;
	double durhamDemand3 = 0.0;
	if(teerQuarryStorage == 0.0)
	{
		teerQuarryStorage = .001;
	}
	if(durhamJordanStorage == 0.0)
	{
		durhamJordanStorage = .001;
	}
	if(durhamStorage == 0.0)
	{
		durhamStorage = .001;
	}
	durhamDemand1 = durhamUse*(teerQuarryStorage/(teerQuarryStorage+durhamJordanStorage+durhamStorage));
	
	durhamDemand2 = durhamUse*(durhamJordanStorage/(teerQuarryStorage+durhamJordanStorage+durhamStorage));
	
	durhamDemand3 = durhamUse*(durhamStorage/(teerQuarryStorage+durhamJordanStorage+durhamStorage));
	if(durhamDemand1>teerQuarryOutflowCapacity*numdays)
	{
		durhamDemand1 = teerQuarryOutflowCapacity*numdays;
		
		durhamDemand2 = (durhamUse-durhamDemand1)*(durhamJordanStorage/(durhamJordanStorage+durhamStorage));
		
		durhamDemand3 = (durhamUse-durhamDemand1)*(durhamStorage/(durhamJordanStorage+durhamStorage));
	}
	if(durhamDemand2>durhamWWTPcapacity*numdays)
	{
		durhamDemand2 = durhamWWTPcapacity*numdays;
	
		durhamDemand1 = (durhamUse-durhamDemand2)*(teerQuarryStorage/(teerQuarryStorage+durhamStorage));
		if(durhamDemand1>teerQuarryOutflowCapacity*numdays)
		{
			durhamDemand1 = teerQuarryOutflowCapacity*numdays;
			durhamDemand3 = durhamUse - durhamWWTPcapacity*numdays - teerQuarryOutflowCapacity*numdays;
		}
		else
		{
			durhamDemand3 = (durhamUse-durhamDemand2)*(durhamStorage/(teerQuarryStorage+durhamStorage));
		}
	}
	
	double teerDiversionInt = 0.0;
	/////////Eno River Diversions////////////////////////////	
	if((fallsInflow - enoSpillage)>numdays*teerQuarryIntakeCapacity)
	{
		teerDiversionInt = numdays*teerQuarryIntakeCapacity;
	}
	else if((fallsInflow - enoSpillage)>0)
	{
		teerDiversionInt = fallsInflow - enoSpillage;
	}
	else
	{
		teerDiversionInt = 0.0;
	}
	if((teerDiversionInt + teerQuarryStorage - durhamDemand1)>teerQuarryCapacity)
	{
		teerDiversion = teerQuarryCapacity - teerQuarryStorage + durhamDemand1;
	}
	else
	{
		teerDiversion = teerDiversionInt;
	}
	///////////////////////////////////////////////////////////
	
	
	/////Teer Quarry Water Balance
	teerQuarryStorage = teerQuarryStorage + teerDiversion - evap*(20 + 30*(teerQuarryStorage/(teerQuarryCapacity+.001))) - durhamDemand1;
	/////boundry conditions
	if(teerQuarryStorage>teerQuarryCapacity)
	{
		teerDiversion += teerQuarryCapacity - teerQuarryStorage;
		teerQuarryStorage = teerQuarryCapacity;
	}
	if(teerQuarryStorage<0.0)
	{
		durhamDemand3 -= teerQuarryStorage;
		teerQuarryStorage = 0.0;
	}
	
	////Little River Reservoir/Lake Michie Water Balance
	durhamStorage = durhamStorage + durhamInflow + durhamRequest - durhamDemand3 - evap*1069.0 - durhamSpillage;
	//Boundry conditions
	if (durhamStorage>durhamCapacity)
	{
		durhamSpillage+=durhamStorage - durhamCapacity;
		durhamExcess = durhamStorage - durhamCapacity;
		durhamStorage=durhamCapacity;
		//water greater than combined reservoir capacity is added to the releases for environmental flows
	}
	else
	{
		durhamExcess = 0.0;
	}
	
	if (durhamStorage<0)
	{
		durhamStorage = 0;
	}
		//non negativity constraint
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return durhamDemand2;
}
double ReservoirStorage::updateRaleighStorage(int week)
{
	double intakeDemand;
	if((fallsLakeSupplyStorage+fallsLakeQualityStorage)<(fallsLakeSupplyCapacity+fallsLakeQualityCapacity))
	{
		intakeDemand = raleighIntakeCapacity*numdays;
		
	}
	else
	{
		intakeDemand = 0.0;
	}
	double raleighDemand1 = 0.0;
	double raleighDemand2 = 0.0;
	double raleighDemand3 = 0.0;
	double raleighDemand4 = 0.0;
	double raleighDemand5 = 0.0;
	if(fallsLakeSupplyStorage == 0.0)
	{
		fallsLakeSupplyStorage = 0.001;
	}
	if(lakeWBStorage == 0.0)
	{
		lakeWBStorage = 0.001;
	}
	if(littleRiverRaleighStorage == 0.0)
	{
		littleRiverRaleighStorage = 0.001;
	}
	if(raleighJordanStorage == 0.0)
	{
		raleighJordanStorage = 0.001;
	}
	if(raleighQuarryStorage == 0.0)
	{
		raleighQuarryStorage = 0.001;
	}
	double firmDemand = intakeDemand;
	double totalStorageRaleigh = fallsLakeSupplyStorage + lakeWBStorage + littleRiverRaleighStorage + raleighJordanStorage + raleighQuarryStorage;
	
	//////Raleigh demands from different sources are dependent on the storage available in that source.  However, Jordan Lake and the quarry
	//////have constraints on how much can be taken out, and the WTP at Falls Lake has a minimum constraint.  It is assumed the WTP at LRR and Lake Wheeler/Benson
	//////are big enough to meet demands that occur
	//////Note: a few more sources/constraints and this might be better solved with a LP
	raleighDemand4 = (raleighUse - firmDemand)*(raleighJordanStorage/totalStorageRaleigh);
	if(raleighDemand4>raleighWWTPcapacity*numdays)
	{
		raleighDemand4 = raleighWWTPcapacity*numdays;
		firmDemand += raleighDemand4;
		totalStorageRaleigh -= raleighJordanStorage;
		
		raleighDemand5 = (raleighUse - firmDemand)*(raleighQuarryStorage/totalStorageRaleigh);
		if(raleighDemand5 > raleighQuarryOutflowCapacity*numdays)
		{
			raleighDemand5 = raleighQuarryOutflowCapacity*numdays;
			firmDemand += raleighDemand5;
			totalStorageRaleigh -= raleighQuarryStorage;
		}
	}
	else
	{
		raleighDemand5 = (raleighUse - firmDemand)*(raleighQuarryStorage/totalStorageRaleigh);
		if(raleighDemand5 > raleighQuarryOutflowCapacity*numdays)
		{
			raleighDemand5 = raleighQuarryOutflowCapacity*numdays;
			firmDemand += raleighDemand5;
			totalStorageRaleigh -= raleighQuarryStorage;
			
			raleighDemand4 = (raleighUse - firmDemand)*(raleighJordanStorage/totalStorageRaleigh);
			if(raleighDemand4<(raleighWWTPcapacity*numdays - .01))
			{
				raleighDemand4 = raleighWWTPcapacity*numdays;
				firmDemand += raleighDemand4;
				totalStorageRaleigh -= raleighJordanStorage;
			}
		}
	}
	
	raleighDemand1 = (raleighUse - firmDemand)*(fallsLakeSupplyStorage/totalStorageRaleigh);
	if(raleighDemand1< 36.0*numdays)
	{
		raleighDemand1 = 36.0*numdays;
		firmDemand = intakeDemand + raleighDemand1;
		totalStorageRaleigh = lakeWBStorage + littleRiverRaleighStorage + raleighJordanStorage + raleighQuarryStorage;
		
		raleighDemand4 = (raleighUse - firmDemand)*(raleighJordanStorage/totalStorageRaleigh);
		if(raleighDemand4>raleighWWTPcapacity*numdays)
		{
			raleighDemand4 = raleighWWTPcapacity*numdays;
			firmDemand += raleighDemand4;
			totalStorageRaleigh -= raleighJordanStorage;
		
			raleighDemand5 = (raleighUse - firmDemand)*(raleighQuarryStorage/totalStorageRaleigh);
			if(raleighDemand5 > raleighQuarryOutflowCapacity*numdays)
			{
				raleighDemand5 = raleighQuarryOutflowCapacity*numdays;
				firmDemand += raleighDemand5;
				totalStorageRaleigh -= raleighQuarryStorage;
			}
		}
		else
		{
			raleighDemand5 = (raleighUse - firmDemand)*(raleighQuarryStorage/totalStorageRaleigh);
			if(raleighDemand5 > raleighQuarryOutflowCapacity*numdays)
			{
				raleighDemand5 = raleighQuarryOutflowCapacity*numdays;
				firmDemand += raleighDemand5;
				totalStorageRaleigh -= raleighQuarryStorage;
			
				raleighDemand4 = (raleighUse - firmDemand)*(raleighJordanStorage/totalStorageRaleigh);
				if(raleighDemand4>(raleighWWTPcapacity*numdays - .01))
				{
					raleighDemand4 = raleighWWTPcapacity*numdays;
					firmDemand += raleighDemand4;
					totalStorageRaleigh -= raleighJordanStorage;
				}
			}
		}
	}
	
	raleighDemand2 = (raleighUse - firmDemand)*(lakeWBStorage/totalStorageRaleigh);
	
	raleighDemand3 = (raleighUse - firmDemand)*(littleRiverRaleighStorage/totalStorageRaleigh);
			
		
	if(week<13||week>43)
	{
		fallsSpillage = numdays*60.0/1.547;///minimum spillage from reservoir
		if(fallsSpillage + raleighReturn + claytonInflow + crabtreeInflow - intakeDemand <130.0*numdays)
		{
			fallsSpillage = 130.0*numdays + intakeDemand - raleighReturn - claytonInflow - crabtreeInflow;////minimum flow target at downstream gauge
		}
	}
	else
	{
		fallsSpillage = 100.0*numdays/1.547;///minimum spillage from reservoir
		if(fallsSpillage + raleighReturn + claytonInflow + crabtreeInflow - intakeDemand <180.0*numdays)
		{
			fallsSpillage = 180.0*numdays + intakeDemand - raleighReturn - claytonInflow - crabtreeInflow;
		}
	}

	claytonGage = fallsSpillage + raleighReturn + claytonInflow + crabtreeInflow - intakeDemand;
	if(week<13||week>43)
	{
		if((claytonGage - 130.0*numdays) > numdays*raleighQuarryIntakeCapacity)
		{
			raleighQuarryDiversion = numdays*teerQuarryIntakeCapacity;
		}
		else if((claytonGage - 130.0*numdays) > 0 )
		{
			raleighQuarryDiversion = claytonGage - 130.0*numdays;
		}
		else
		{
			raleighQuarryDiversion = 0.0;
		}
	}
	else
	{
		if((claytonGage - 180.0*numdays) > numdays*raleighQuarryIntakeCapacity)
		{
			raleighQuarryDiversion = numdays*teerQuarryIntakeCapacity;
		}
		else if((claytonGage - 180.0*numdays) > 0 )
		{
			raleighQuarryDiversion = claytonGage - 180.0*numdays;
		}
		else
		{
			raleighQuarryDiversion = 0.0;
		}
	}
	
	
	if((raleighQuarryDiversion + raleighQuarryStorage - raleighDemand5)>raleighQuarryCapacity)
	{
		raleighQuarryDiversion = raleighQuarryCapacity - raleighQuarryStorage + raleighDemand5;
	}
	
	///////////Falls Lake Water Balance////////////////////
	//area calculation for evaporation
	if ((fallsLakeSupplyStorage+fallsLakeQualityStorage+5734)<29000)
	{
		fallsArea = .32*(fallsLakeSupplyStorage+fallsLakeQualityStorage+5734);
	}
	else
	{
		fallsArea = .28*(fallsLakeSupplyStorage+fallsLakeQualityStorage+5734);
	}
	////Inflows are divided between the water storage supply and water quality supply proportionatly (14.7BG supply storage, 20 BG quality storage)
	////Durham reservoir releases and wastewater returns are added to Falls Lake inflows
	fallsSupplyInflow = (fallsInflow + durhamSpillage - fallsArea*evapF + durhamReturn - teerDiversion)*(14.7/34.7);
	fallsQualityInflow = (fallsInflow + durhamSpillage - fallsArea*evapF + durhamReturn -teerDiversion)*(20/34.7);

	////Environmental Releases come from the water quality storage portion of Falls Lake
	fallsLakeQualityStorage += fallsQualityInflow - fallsSpillage;
	
	//boundry conditions on the water quality storage in Falls Lake
	if (fallsLakeQualityStorage > fallsLakeQualityCapacity)
	{
		////If excess water quality storage exists, it is allocated to the water supply storage portion of Falls Lake
		
		fallsSupplyInflow += fallsLakeQualityStorage - fallsLakeQualityCapacity;
		fallsQualityInflow += fallsLakeQualityCapacity - fallsLakeQualityStorage;
		fallsLakeQualityStorage = fallsLakeQualityCapacity;
	}
	if (fallsLakeQualityStorage<0)
	{
		fallsLakeQualityStorage = 0;
	}
	
	////Municipal water demand comes from the water suply storage portion of Falls Lake
	fallsLakeSupplyStorage += fallsSupplyInflow - raleighDemand1;
	/////boundry conditions on water supply storage in Falls Lake (don't need to keep track of excess spillage from Falls Lake)
	if (fallsLakeSupplyStorage>fallsLakeSupplyCapacity)
	{
		fallsLakeSupplyStorage = fallsLakeSupplyCapacity;
	}
	if (fallsLakeSupplyStorage<0)
	{
		fallsLakeSupplyStorage = 0;
	}


	/////Water balance on other three raleigh storage sources
	lakeWBStorage += wbInflow - raleighDemand2 - lakeWBSpillage - (lakeWBStorage*0.3675*evapWB);
	
	littleRiverRaleighStorage +=littleRiverRaleighInflow - raleighDemand3 - raleighLittleRiverSpillage + evapF*(320.0+826.0*(littleRiverRaleighStorage/(.001+littleRiverRaleighCapacity)));
	
	raleighQuarryStorage += raleighQuarryDiversion - evap*(20 + 30*(raleighQuarryStorage/(raleighQuarryCapacity+.001))) - raleighDemand5;
	raleighExcess = 0.0;	
	if(lakeWBStorage>lakeWBCapacity)
	{
		lakeWBSpillage+=lakeWBStorage - lakeWBCapacity;
		raleighExcess += lakeWBStorage - lakeWBCapacity;
		lakeWBStorage = lakeWBCapacity;
	}
	if(littleRiverRaleighStorage>littleRiverRaleighCapacity)
	{
		raleighLittleRiverSpillage +=littleRiverRaleighStorage - littleRiverRaleighCapacity;
		if(littleRiverRaleighCapacity > 100.0)
		{
			raleighExcess+=littleRiverRaleighStorage - littleRiverRaleighCapacity;
		}
		littleRiverRaleighStorage = littleRiverRaleighCapacity;
	}
	if (fallsLakeSupplyStorage>fallsLakeSupplyCapacity)
	{
		fallsSpillage+=fallsLakeSupplyStorage - fallsLakeSupplyCapacity;
		raleighExcess += fallsLakeSupplyStorage - fallsLakeSupplyCapacity;
		fallsLakeSupplyStorage = fallsLakeSupplyCapacity;
	}
	if(raleighQuarryStorage>raleighQuarryCapacity)
	{
		raleighQuarryStorage = raleighQuarryCapacity;
	}
	if(lakeWBStorage<0)
	{
		lakeWBStorage = 0;
	}
	if (fallsLakeSupplyStorage<0)
	{
		fallsLakeSupplyStorage = 0;
	}
	if(raleighQuarryStorage<0)
	{
		raleighQuarryStorage = 0;
	}
	if(littleRiverRaleighStorage<0)
	{
		littleRiverRaleighStorage = 0;
	}
	return raleighDemand4;
}
void ReservoirStorage::updateJordanLakeStorage(double owasaJordanDemand, double durhamJordanDemand, double raleighJordanDemand)
{
///////Jordan Lake//////////////////////////////////////////////////////////////////////////////////
	
	//////apportioning inflows to each Jordan Lake pool (water quality and individual utility supply storage)
	/////surface area of Jordan Lake is 13940 acres
	jordanLakeQualityStorage += (jordanInflow+durhamReturn2+owasaReturn+OWASASpillage-evap*13940)*jordanQualityFraction-jordanLakeMinRelease;
	raleighJordanStorage += (jordanInflow+durhamReturn2+owasaReturn+OWASASpillage-evap*13940)*jordanRaleighFraction - raleighRequest - raleighJordanDemand;
	durhamJordanStorage += (jordanInflow+durhamReturn2+owasaReturn+OWASASpillage-evap*13940)*jordanDurhamFraction - durhamRequest - durhamJordanDemand;
	owasaJordanStorage += (jordanInflow+durhamReturn2+owasaReturn+OWASASpillage-evap*13940)*jordanOWASAFraction - owasaRequest - owasaJordanDemand;
	caryJordanStorage += (jordanInflow+durhamReturn2+owasaReturn+OWASASpillage-evap*13940)*jordanCaryFraction - CaryUse;
	/////if water quality storage exceeds quality pool capacity, excess water is apportioned to the individual supply storage pools
	if (jordanLakeQualityStorage>jordanLakeQualityCapacity)
	{
		raleighJordanStorage+=raleighAllocation*(jordanLakeQualityStorage-jordanLakeQualityCapacity);
		durhamJordanStorage+=durhamAllocation*(jordanLakeQualityStorage-jordanLakeQualityCapacity);
		owasaJordanStorage+=owasaAllocation*(jordanLakeQualityStorage-jordanLakeQualityCapacity);
		caryJordanStorage+=caryAllocation*(jordanLakeQualityStorage-jordanLakeQualityCapacity);
		jordanLakeQualityStorage=jordanLakeQualityCapacity;
	}
	if (jordanLakeQualityStorage<0)
	{
		jordanLakeQualityStorage = 0;
	}
	
	////if an individual utility's supply storage is below zero, they cannot withdraw water for transfers
	if(raleighJordanStorage<0)
	{
		fallsLakeSupplyStorage+=raleighJordanStorage;
		raleighRequest+=raleighJordanStorage;
		if (fallsLakeSupplyStorage<0)
		{
			fallsLakeSupplyStorage = 0;
		}
		if (raleighRequest<0)
		{
			raleighRequest = 0;
		}
		raleighJordanStorage = 0;
	}
	////no need to calculate Jordan lake spillage
	if(raleighJordanStorage>raleighJordanCapacity)
	{
		raleighJordanStorage = raleighJordanCapacity;
	}
	if(durhamJordanStorage<0)
	{
		durhamStorage+=durhamJordanStorage;
		durhamRequest+=durhamJordanStorage;
		if (durhamRequest<0)
		{
			durhamRequest = 0;
		}
		if (durhamStorage<0)
		{
			durhamStorage = 0;
		}
		durhamJordanStorage = 0;
	}
	if(durhamJordanStorage>durhamJordanCapacity)
	{
		durhamJordanStorage = durhamJordanCapacity;
	}
	if(owasaJordanStorage<0)
	{
		CCRStorage+=owasaJordanStorage;
		OWASAStorage+=owasaJordanStorage;
		owasaRequest+=owasaJordanStorage;
		if (owasaRequest<0)
		{
			owasaRequest = 0;
		}
		if (CCRStorage<0)
		{
			CCRStorage = 0;
		}
		if (OWASAStorage <0)
		{
			OWASAStorage = 0;
		}
		owasaJordanStorage = 0;
	}
	if(owasaJordanStorage>owasaJordanCapacity)
	{
		owasaJordanStorage = owasaJordanCapacity;
	}
	if(caryJordanStorage<0)
	{
		caryJordanStorage = 0;
	}
	if(caryJordanStorage>caryJordanCapacity)
	{
		caryExcess = caryJordanStorage - caryJordanCapacity;
		caryJordanStorage = caryJordanCapacity;
	}
}
void ReservoirStorage::updateStorage(int week)
{
	double oJD = 0.0;
	double dJD = 0.0;
	double rJD = 0.0;
	setSpillover(week);
	oJD = updateOWASAStorage();
	dJD = updateDurhamStorage();
	rJD = updateRaleighStorage(week);
	updateJordanLakeStorage(oJD, dJD, rJD);
	
	
	return;
}

double ReservoirStorage::getDurhamStorage()
{
	return durhamStorage/durhamCapacity;
}
double ReservoirStorage::getOWASAStorage()
{
	return OWASAStorage/OWASACapacity;
}
double ReservoirStorage::getRaleighStorage()
{
	return (fallsLakeSupplyStorage+lakeWBStorage+littleRiverRaleighStorage)/(fallsLakeSupplyCapacity+lakeWBCapacity+littleRiverRaleighCapacity);
}
double ReservoirStorage::getCaryStorage()
{
	return (caryJordanStorage)/(caryJordanCapacity);
}
double ReservoirStorage::getDurhamTransfers()
{
	return durhamRequest;
}
double ReservoirStorage::getOWASATransfers()
{
	return owasaRequest;
}
double ReservoirStorage::getRaleighTransfers()
{
	return raleighRequest;
}
double ReservoirStorage::getOWASASpillage()
{
	return OWASASpillage;
}
double ReservoirStorage::getDurhamSpillage()
{
	return durhamSpillage;
}
double ReservoirStorage::getDurhamReclaimedCap()
{
	return durhamReclaimedCapacity;
}
double ReservoirStorage::getDurhamTreatment()
{
	return durhamWWTPcapacity;
}
double ReservoirStorage::getOWASATreatment()
{
	return owasaWWTPcapacity;
}
double ReservoirStorage::getRaleighTreatment()
{
	return raleighWWTPcapacity;
}
double ReservoirStorage::getRaleighIntake()
{
	return raleighIntakeCapacity;
}
double ReservoirStorage::getFallsQuality()
{
	return fallsLakeQualityStorage/fallsLakeQualityCapacity;
}
double ReservoirStorage::getExcessO()
{
	return owasaExcess/OWASACapacity;
}
double ReservoirStorage::getExcessD()
{
	return durhamExcess/durhamCapacity;
}
double ReservoirStorage::getExcessR()
{
	return raleighExcess/(fallsLakeSupplyCapacity+lakeWBCapacity+littleRiverRaleighCapacity);
}
double ReservoirStorage::getExcessC()
{
	return caryExcess/caryJordanCapacity;
}
double ReservoirStorage::getDurhamStorageVol()
{
	return durhamStorage;
}
double ReservoirStorage::getTeerStorageVol()
{
	return teerQuarryStorage;
}
double ReservoirStorage::getCCRStorageVol()
{
	return CCRStorage;
}
double ReservoirStorage::getULStorageVol()
{
	return ULStorage;
}
double ReservoirStorage::getSTQStorageVol()
{
	return StQStorage;
}
double ReservoirStorage::getOWASAStorageVol()
{
	return OWASAStorage;
}
double ReservoirStorage::getLakeWBStorageVol()
{
	return lakeWBStorage;
}
double ReservoirStorage::getFallsSupplyStorageVol()
{
	return fallsLakeSupplyStorage;
}
double ReservoirStorage::getFallsQualityStorageVol()
{
	return fallsLakeQualityStorage;
}
double ReservoirStorage::getJordanSupplyStorageVol()
{
	return jordanLakeSupplyStorage;
}
double ReservoirStorage::getJordanQualityStorageVol()
{
	return jordanLakeQualityStorage;
}
double ReservoirStorage::getCaryJordanStorageVol()
{
	return caryJordanStorage;
}
double ReservoirStorage::getRaleighJordanStorageVol()
{
	return raleighJordanStorage;
}
double ReservoirStorage::getDurhamJordanStorageVol()
{
	return durhamJordanStorage;
}
double ReservoirStorage::getOWASAJordanStorageVol()
{
	return owasaJordanStorage;
}
double ReservoirStorage::getLittleRiverRalStorageVol()
{
	return littleRiverRaleighStorage;
}
double ReservoirStorage::getRaleighQuarryStorageVol()
{
	return raleighQuarryStorage;
}
void ReservoirStorage::upgradeCaryTreatmentPlant(int counter)
{
	if(counter == 0)
	{
		CaryTreatmentCapacity = 64;
	}
	else if(counter == 1)
	{
		CaryTreatmentCapacity = 72;
	}
	else
	{
		
		CaryTreatmentCapacity = 80;
	}
}
void ReservoirStorage::upgradeCaryTreatmentPlant2()
{
	CaryTreatmentCapacity = 64;
}
void ReservoirStorage::upgradeDurhamCaryConnection()
{
	DurhamCaryCapacity = 23;
}
void ReservoirStorage::upgradeDurhamOWASAConnection()
{
	DurhamOWASACapacity = 16;
}
