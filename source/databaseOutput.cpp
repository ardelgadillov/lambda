//
//  databaseOutput.cpp
//  lambda
//
//  Created by Andres Delgadillo on 10/27/15.
//
//

#ifndef databaseOutput_cpp
#define databaseOutput_cpp

#include "databaseOutput.h"

/************************************************************************/
/*						LambdaDatabaseOutput Implementation                   */
/************************************************************************/

LambdaDatabaseOutput::LambdaDatabaseOutput(wxString file) : LambdaDatabase(file)
{
    //open the LambdaDatabase
    Opendb(false);
};

LambdaDatabaseOutput::~LambdaDatabaseOutput()
{
};

/************************************************************************/
/*						Informacion de las columnas                     */
/************************************************************************/

void LambdaDatabaseOutput::InfoCols()
{
    m_col_name.Add("pe");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Periods");
    
    m_col_name.Add("st");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Estado del\nsistema");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("System\nstate");
    
    m_col_name.Add("st2");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Estado del\nsistema");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("System\nstate");
    
    m_col_name.Add("em");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Empresa");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Company");
    
    m_col_name.Add("gt");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Grupo\nTérmico");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Thermal\nGroup");
    
    m_col_name.Add("gh");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Grupo\nHidráulico");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Hydro\nGroup");
    
    m_col_name.Add("gh2");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Grupo\nHidráulico\nInferior");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Below\nHydro\nGroup");
    
    m_col_name.Add("amv");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Agente\nmarginalista");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Marginalist\nagent");
    
    m_col_name.Add("amc");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Agente\nmarginalista");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Marginalist\nagent");
    
    m_col_name.Add("nd");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Node");
    
    m_col_name.Add("nd2");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Node");
    
    m_col_name.Add("S_DEM_POT_NPS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("S_DEM_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("S_DEM_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("S_DEM_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("S_DNS_POT_NPS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MW]");
    
    m_col_name.Add("S_DNS_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MW]");
    
    m_col_name.Add("S_DNS_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MW]");
    
    m_col_name.Add("S_DNS_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MW]");
    
    m_col_name.Add("S_DEM_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MWh]");
    
    m_col_name.Add("S_DEM_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MWh]");
    
    m_col_name.Add("S_DEM_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MWh]");
    
    m_col_name.Add("S_DNS_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MWh]");
    
    m_col_name.Add("S_DNS_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MWh]");
    
    m_col_name.Add("S_DNS_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\nno suministrada\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Not supplied\ndemand\n[MWh]");
    
    m_col_name.Add("S_PCIO_NPS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_PCIO_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_PCIO_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_PCIO");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_PCIOPOND_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_FLUJO_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Flujo de\npotencia[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\nflow[MW]");
    
    m_col_name.Add("S_PCIOPOND");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("S_EM_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_POTPOS_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_POTPOS_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_POS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_EM_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_ENEPOS_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_ENEPOS_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_ENEPOS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_EM_BEN_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Beneficios\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Profits\n[$]");
    
    m_col_name.Add("S_EM_BEN_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Beneficios\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Profits\n[$]");
    
    m_col_name.Add("S_EM_BEN");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Beneficios\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Profits\n[$]");
    
    m_col_name.Add("S_EM_ING_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Ingreso\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Income\n[$]");
    
    m_col_name.Add("S_EM_ING_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Ingreso\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Income\n[$]");
    
    m_col_name.Add("S_EM_ING");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Ingreso\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Income\n[$]");
    
    m_col_name.Add("S_EM_CARR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CARR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CARR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CPAR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Sthut-down\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CPAR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Sthut-down\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CPAR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Sthut-down\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVCIO_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVCIO_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVCIO");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVAR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVAR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CVAR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CTOT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CTOT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_EM_CTOT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_GT_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GT_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GT_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GT_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GT_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GT_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GT_ARR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up");
    
    m_col_name.Add("S_GT_ARR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up");
    
    m_col_name.Add("S_GT_ARR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up");
    
    m_col_name.Add("S_GT_PAR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down");
    
    m_col_name.Add("S_GT_PAR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down");
    
    m_col_name.Add("S_GT_PAR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down");
    
    m_col_name.Add("S_GT_CARR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CARR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CARR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CPAR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CPAR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CPAR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVCIO_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVCIO_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVCIO");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos de\nvacío\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVAR_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVAR_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CVAR");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\nvariables\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CTOT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CTOT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_GT_CTOT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costos\ntotales\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Total\ncosts\n[$]");
    
    m_col_name.Add("S_GH_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GH_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GH_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_GH_POTBOM_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia de\nbombeo\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\npower\n[MW]");
    
    m_col_name.Add("S_GH_POTBOM_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia de\nbombeo\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\npower\n[MW]");
    
    m_col_name.Add("S_GH_POTBOM");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia de\nbombeo\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\npower\n[MW]");
    
    m_col_name.Add("S_GH_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GH_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GH_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GH_ENEBOM_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía de\nbombeo\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\nenergy\n[MWh]");
    
    m_col_name.Add("S_GH_ENEBOM_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía de\nbombeo\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\nenergy\n[MWh]");
    
    m_col_name.Add("S_GH_ENEBOM");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía de\nbombeo\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Pumping\nenergy\n[MWh]");
    
    m_col_name.Add("S_GH_VE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\nvertida\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Spilled\nenergy\n[MWh]");
    
    m_col_name.Add("S_GH_RES_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reservas\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Reserves\n[MWh]");
    
    m_col_name.Add("S_GH_APOSINF_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MWh]");
    
    m_col_name.Add("S_GH_VAGUA_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Valor\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Value\n[$/MWh]");
    
    m_col_name.Add("S_GH_VAGUA");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Valor\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Value\n[$/MWh]");
    
    m_col_name.Add("S_AMV_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMV_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMV_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMC_POT_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMC_POT_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMC_POT");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("S_AMV_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
    
    m_col_name.Add("S_AMV_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
    
    m_col_name.Add("S_AMV_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
    
    m_col_name.Add("S_AMC_ENE_PS");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
    
    m_col_name.Add("S_AMC_ENE_P");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
    
    m_col_name.Add("S_AMC_ENE");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Energía\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Energy\n[MW]");
}

/************************************************************************/
/*						Informacion de las tablas                       */
/************************************************************************/

//It has all the information of each table
void LambdaDatabaseOutput::InfoTables()
{
    //System
    m_tables.Add("S_DEM_POT_NPS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de potencia en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power demand in each node");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda media de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda media de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_POT_NPS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de potencia No suministrada en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Not supplied power demand at each node");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de potencia No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Not supplied power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda media de potencia No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average not supplied power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda media de potencia No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average not supplied power demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DEM_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Not supplied energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Not supplied energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_DNS_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda de Energía No suministrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Not supplied energy demand");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_FLUJO_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Flujo de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power flow");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("nd2");
    m_idx3.Add("pe");
    m_idx4.Add("st");
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIO_NPS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio marginal en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Marginal price in each node");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIO_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio marginal");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Marginal price");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIO_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio medio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average price");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIO");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio medio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average price");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIOPOND_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio medio ponderado por la Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average price weighted by Energy");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_PCIOPOND");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio medio ponderado por la Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average price weighted by Energy");
    m_tipo.Add(ID_SYSTEM);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Companies
    m_tables.Add("S_EM_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average total power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average total power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_POTPOS_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_POTPOS_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_POS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Power");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENEPOS_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENEPOS_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ENEPOS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Posición - Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Position - Energy");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_BEN_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Beneficio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Profit");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_BEN_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Beneficio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Profit");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_BEN");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Beneficio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Profit");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ING_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Ingresos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Income");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ING_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Ingresos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Income");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_ING");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Ingresos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Income");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CARR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CARR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CARR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CPAR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CPAR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CPAR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVCIO_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacío");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVCIO_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacío");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVCIO");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacío");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVAR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Varianble costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVAR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Varianble costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CVAR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Varianble costs");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CTOT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CTOT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_EM_CTOT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_COMPANIES);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ARR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Start-up");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ARR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Start-up");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_ARR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Arranques");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Start-up");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_PAR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Shut-down");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_PAR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Shut-down");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_PAR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Paradas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Number of Shut-down");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CARR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CARR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CARR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de arranque");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Start-up costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CPAR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CPAR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CPAR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de parada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Shut-down costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVCIO_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVCIO_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVCIO");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos de vacio");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Commitment costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVAR_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Variable costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVAR_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Variable costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CVAR");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos variables");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Variable costs");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CTOT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CTOT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GT_CTOT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos totales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total cost");
    m_tipo.Add(ID_THERMAL);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POTBOM_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Pumping power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POTBOM_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average pumping power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_POTBOM");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia media de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average pumping power");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENEBOM_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Pumping energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENEBOM_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Pumping energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_ENEBOM");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía total de bombeo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total pumping energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_VE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Energía vertida");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Discharged energy");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_RES_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Reservas");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Reserves");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_APOSINF_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Aportaciones al sistema inferior");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Contributions to the lower system");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("gh2");
    m_idx3.Add("pe");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_VAGUA_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Valor del agua");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Value of water");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_GH_VAGUA");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Valor del agua");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Value of water");
    m_tipo.Add(ID_HYDRO);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta media de Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta media de Potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_POT_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_POT_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra media de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_POT");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra media de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average power purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta media de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average energy sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMV_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Venta media de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average energy sold");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_ENE_PS");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Energy purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE_ST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_ENE_P");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra media de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average energy purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_PE);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("S_AMC_ENE");
    m_sqlComands.Add(wxEmptyString);
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Compra media de Energía");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Average energy purchased");
    m_tipo.Add(ID_MARGINALIST);
    m_horizonte.Add(ID_GENERAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
};

#endif