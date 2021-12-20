//
//  databaseInput.cpp
//  lambda
//
//  Created by Andres Delgadillo on 10/27/15.
//
//

#ifndef databaseInput_cpp
#define databaseInput_cpp

#include "databaseInput.h"

/************************************************************************/
/*						LambdaDatabaseInput Implementation              */
/************************************************************************/

LambdaDatabaseInput::LambdaDatabaseInput(wxString file) : LambdaDatabase(file)
{
    //open the LambdaDatabase
    Opendb(true);
};

LambdaDatabaseInput::~LambdaDatabaseInput()
{
};

/************************************************************************/
/*						Informacion de las columnas                     */
/************************************************************************/

void LambdaDatabaseInput::InfoCols()
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
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Grupo\nHidráulico\ninferior");
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
    
    m_col_name.Add("dur_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Duración\n[h]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Duration\n[h]");
    
    m_col_name.Add("tran_pss");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Número de\ntransiciones");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Number of\ntransitions");
    
    m_col_name.Add("st_ini");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Estado\ninicial");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Initial\nstate");
    
    m_col_name.Add("st_fin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Estado\nfinal");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Final\nstate");
    
    m_col_name.Add("em_theta_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Variación\nconjetural\n[($/MWh)/MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Conjectural\nvariation\n[($/MWh)/MW]");
    
    m_col_name.Add("em_cbilpcio_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("em_cbilpot_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("em_cdifpcio_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("em_cdifpot_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("em_cuotamin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Cuota\nmínima\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nquota\n[p.u.]");
    
    m_col_name.Add("em_pmin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmínima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nproduction\n[MWh]");
    
    m_col_name.Add("gt_pmax");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\nmáxima\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum\npower\n[MW]");
    
    m_col_name.Add("gt_pmin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\nmínima\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\npower\n[MW]");
    
    m_col_name.Add("gt_cvacio");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costo de\nvacío\n[$/MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Commitment\ncost\n[$/MW]");
    
    m_col_name.Add("gt_carr");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costo de\narranque\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Start-up\ncost\n[$]");
    
    m_col_name.Add("gt_cpar");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costo de\nparada\n[$]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Shut-down\ncost\n[$]");
    
    m_col_name.Add("gt_cvar_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costo\nvariable\n[$/Mwh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Variable\ncost\n[$/MWh]");
    
    m_col_name.Add("gt_coefdisp_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Coeficiente\nde disponibilidad\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Availability\ncoeficient\n[p.u.]");
    
    m_col_name.Add("gt_emin_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmínima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nproduction\n[MWh]");
    
    m_col_name.Add("gt_emax_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmáxima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum\nproduction\n[MWh]");
    
    m_col_name.Add("gt_emin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmínima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nproduction\n[MWh]");
    
    m_col_name.Add("gt_emax");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmáxima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum\nproduction\n[MWh]");
    
    m_col_name.Add("gt_pert_em");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Pertenencia\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Ownership\n[p.u.]");
    
    m_col_name.Add("gt_loca_nd");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Location");
    
    m_col_name.Add("gh_upmaxres");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Término\nconstante U\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Constant\nterm U\n[MW]");
    
    m_col_name.Add("gh_vpamxres");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Término\nlineal V\n[MW/Mwh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Linear\nterm V\n[MW/MWh]");
    
    m_col_name.Add("gh_rendturbom");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Rendimiento del ciclo\nturbinación-bombeo\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Efficiency of the\nturbine-pumping cycle\n[p.u.]");
    
    m_col_name.Add("gh_rini");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reservas\niniciales\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Initial\nreserves\n[MWh]");
    
    m_col_name.Add("gh_rfin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reservas\nfinales\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Final\nreserves\n[MWh]");
    
    m_col_name.Add("gh_rmin_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reservas\nmínimas\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nreserves\n[MWh]");
    
    m_col_name.Add("gh_rmax_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reservas\nmáximas\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum\nreserves\n[MWh]");
    
    m_col_name.Add("gh_bmax_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia máxima\nde bombeo\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum\npumping power\n[MW]");
    
    m_col_name.Add("gh_pflu_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\nfluyente\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Flowing\npower\n[MW]");
    
    m_col_name.Add("gh_apor_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Aportaciones\nhídricas\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Water\ninput\n[MWh]");
    
    m_col_name.Add("gh_pobli_p");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Producción\nmínima\n[MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Minimum\nproduction\n[MWh]");
    
    m_col_name.Add("gh_pert_em");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Pertenencia\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Ownership\n[p.u.]");
    
    m_col_name.Add("gh_sup_gh");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Rendimiento de aportaciones\nal sistema inferior\nde gh a gh2\n[p.u.]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Efficiency of contributions\nto below systems\nfrom gh to gh2\n[p.u.]");
    
    m_col_name.Add("gh_loca_nd");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Location");
    
    m_col_name.Add("amv_oferpot_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("amv_oferpcio_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("amv_loca_nd");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Location");
    
    m_col_name.Add("amc_oferpot_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Potencia\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Power\n[MW]");
    
    m_col_name.Add("amc_oferpcio_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Precio\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Price\n[$/MWh]");
    
    m_col_name.Add("amc_loca_nd");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Location");
    
    m_col_name.Add("dem_ine_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("dem_ord_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Ordenada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Intercept\n[MW]");
    
    m_col_name.Add("dem_pen_ps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Pendiente\n[($/MWh)/MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Slope\n[($/MWh)/MW]");
    
    m_col_name.Add("dem_ine_nps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Demanda\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Demand\n[MW]");
    
    m_col_name.Add("dem_ord_nps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Ordenada\n[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Intercept\n[MW]");
    
    m_col_name.Add("dem_pen_nps");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Pendiente\n[($/MWh)/MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Slope\n[($/MWh)/MW]");
    
    m_col_name.Add("dem_costoenenosum");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Costo\n[$/MWh]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Cost\n[$/MWh]");
    
    m_col_name.Add("red_reac");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Reactancia de\nla línea[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Reactance of\nthe line[MW]");
    
    m_col_name.Add("red_caplin");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_col_label.Add("Capacidad máxima\nde la línea[MW]");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_col_label.Add("Maximum capacity\nof the line[MW]");
}

/************************************************************************/
/*						Informacion de las tablas                       */
/************************************************************************/

//It has all the information of each table
void LambdaDatabaseInput::InfoTables()
{
    //Time parameters
    m_tables.Add("id_pe");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_pe (\
                     pe     STRING PRIMARY KEY ASC ON CONFLICT ROLLBACK NOT NULL DEFAULT pe);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Períodos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Periods");
    m_tipo.Add(ID_TIME);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("pe");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("id_st");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_st (\
                     st     STRING PRIMARY KEY ASC ON CONFLICT ROLLBACK NOT NULL DEFAULT st);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Estados del sistema");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("System states");
    m_tipo.Add(ID_TIME);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("st");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dur_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dur_ps (\
                     pe     STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st     STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dur_ps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Duración de los estados");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Duration of the states");
    m_tipo.Add(ID_TIME);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("tran_pss");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS tran_pss (\
                     pe       STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st       STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st2      STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     tran_pss REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Matriz de transición entre estados");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Transition matrix of the states");
    m_tipo.Add(ID_TIME);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("carac_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS carac_ps (\
                     pe     STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st     STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st_ini REAL   NOT NULL DEFAULT (0),\
                     st_fin REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Estado inicial y final del período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Initial and final state of the period");
    m_tipo.Add(ID_TIME);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Network
    m_tables.Add("id_nd");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_nd (\
                     nd     STRING PRIMARY KEY ASC ON CONFLICT ROLLBACK NOT NULL DEFAULT nd);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Nodos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Nodes");
    m_tipo.Add(ID_SYSTEM);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("nd");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("red_reac");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS red_reac (\
                     nd          STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     nd2         STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     red_reac    REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Reactancia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Reactance");
    m_tipo.Add(ID_SYSTEM);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("red_caplin");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS red_caplin (\
                     nd          STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     nd2         STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     red_caplin  REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Capacidad máxima");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Maximum capacity");
    m_tipo.Add(ID_SYSTEM);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Companies
    m_tables.Add("id_em");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_em (\
                     em STRING NOT NULL DEFAULT em PRIMARY KEY ASC);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Nombres");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Names");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_theta_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_theta_ps (\
                     em          STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     pe          STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st          STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     em_theta_ps REAL    NOT NULL DEFAULT (0));");
    
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Variación conjetural por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Conjectural variation per period");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_cbilpcio_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_cbilpcio_ps (\
                     em             STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     pe             STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st             STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     em_cbilpcio_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio de los contratos bilaterales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Price of the bilateral contracts");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_cbilpot_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_cbilpot_ps (\
                     em            STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     pe            STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st            STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     em_cbilpot_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Cantidad de los contratos bilaterales");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Quantity of the bilateral contracs");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_cdifpcio_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_cdifpcio_ps (\
                     em             STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     pe             STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st             STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     em_cdifpcio_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio de los contratos por diferencias");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Price of the contracts for differences");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_cdifpot_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_cdifpot_ps (\
                     em            STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     pe            STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st            STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     em_cdifpot_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Cantidad de los contratos por diferencias");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Quantity of the contracts for differences");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("em_cuota");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS em_cuota (\
                     em          STRING REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     em_cuotamin REAL   NOT NULL DEFAULT (0),\
                     em_pmin     REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Cuota y producción mínima");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Minimum production and quota");
    m_tipo.Add(ID_COMPANIES);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("em");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Thermal groups
    m_tables.Add("id_gt");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_gt (\
                     gt STRING NOT NULL DEFAULT gt PRIMARY KEY ASC);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Nombres");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Names");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_carac");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_carac (\
                     gt      STRING NOT NULL DEFAULT gt REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE,\
                     gt_pmax REAL   DEFAULT (0) NOT NULL,\
                     gt_pmin REAL   DEFAULT (0) NOT NULL);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Características");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Characteristics");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_costos");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_costos (\
                     gt        STRING NOT NULL DEFAULT gt REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE,\
                     gt_cvacio REAL   NOT NULL DEFAULT (0),\
                     gt_carr   REAL   NOT NULL DEFAULT (0),\
                     gt_cpar   REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costos");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Costs");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_cvar_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_cvar_p (\
                     gt        STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gt_cvar_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costo variable por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Variable cost per period");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_coefdisp_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_coefdisp_p (\
                     gt            STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     pe            STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gt_coefdisp_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Coeficiente de disponibilidad por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Available ratio per period");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_emin_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_emin_p (\
                     gt        STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gt_emin_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Producción mínima por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Minimum production per period");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_emax_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_emax_p (\
                     gt        STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gt_emax_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Producción máxima por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Maximum production per period");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_ener");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_ener (\
                     gt      STRING NOT NULL DEFAULT gt REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE,\
                     gt_emin REAL   NOT NULL DEFAULT (0),\
                     gt_emax REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Producción mínima y máxima total");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Total minimum and maximum production");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_pert_em");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_pert_em (\
                     gt         STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     em         STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     gt_pert_em REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Pertenencia del grupo a la empresa");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Group belonging to the company");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("em");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gt_loca_nd");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gt_loca_nd (\
                     gt         STRING  REFERENCES id_gt (gt) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gt,\
                     nd         STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     gt_loca_nd REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Location");
    m_tipo.Add(ID_THERMAL);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gt");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Hydro groups
    m_tables.Add("id_gh");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_gh (\
                     gh STRING NOT NULL DEFAULT gh PRIMARY KEY ASC);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Nombres");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Names");
    //m_contador_tipos[tipo]++; //Se suma 1 al contador de las tablas del tipo 3
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_carac");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_carac (\
                     gh            STRING REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     gh_upmaxres   REAL   NOT NULL DEFAULT (0),\
                     gh_vpamxres   REAL   NOT NULL DEFAULT (0),\
                     gh_rendturbom REAL   NOT NULL DEFAULT (0),\
                     gh_rini       REAL   NOT NULL DEFAULT (0),\
                     gh_rfin       REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Características");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Characteristics");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_rmin_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_rmin_p (\
                     gh        STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_rmin_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Reservas mínimas por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Minimum reserves per period");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_rmax_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_rmax_p (\
                     gh        STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_rmax_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Reservas máximas por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Maximum reserves per period");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_bmax_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_bmax_p (\
                     gh        STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_bmax_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia máxima de bombeo por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Maximum pumping power per period");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_pflu_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_pflu_ps (\
                     gh         STRING REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe         STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st         STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_pflu_ps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Potencia fluyente por período y estado");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Power flowing per period and state");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_apor_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_apor_p (\
                     gh        STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe        STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_apor_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Aportaciones por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Contributions per period");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_pobli_p");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_pobli_p (\
                     gh         STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     pe         STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     gh_pobli_p REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Producción mínima obligada por período");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Required minimum production per period");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("pe");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_pert_em");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_pert_em (\
                     gh         STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     em         STRING  REFERENCES id_em (em) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT em,\
                     gh_pert_em REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Pertenencia del grupo a la empresa");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Group belonging to the company");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("em");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_sup_gh");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_sup_gh (\
                     gh        STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     gh2       STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh2,\
                     gh_sup_gh REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Rendimiento de aportaciones a los sistemas inferiores");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Efficiency of contributions to below systems");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("gh");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("gh_loca_nd");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS gh_loca_nd (\
                     gh         STRING  REFERENCES id_gh (gh) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT gh,\
                     nd         STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     gh_loca_nd REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Localización");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Location");
    m_tipo.Add(ID_HYDRO);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("gh");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Marginalist agents
    m_tables.Add("id_amv");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_amv (\
                     amv STRING NOT NULL DEFAULT amv PRIMARY KEY ASC);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Agentes marginalistas de venta");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Selling marginalist agents");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("amv");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("id_amc");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS id_amc (\
                     amc STRING NOT NULL DEFAULT amc PRIMARY KEY ASC);");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Agentes marginalistas de compra");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Buying marginalist agents");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_IDX);
    m_idx1.Add("amc");
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amv_oferpot_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amv_oferpot_ps (\
                     amv            STRING  REFERENCES id_amv (amv) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amv,\
                     pe             STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st             STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     amv_oferpot_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Generación ofertada por el AMV");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Generation offered by the SMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amv_oferpcio_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amv_oferpcio_ps (\
                     amv             STRING  REFERENCES id_amv (amv) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amv,\
                     pe              STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st              STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     amv_oferpcio_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio de generación ofertado por el AMV");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Generation price offered by the SMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amv_loca_nd");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amv_loca_nd (\
                     amv         STRING  REFERENCES id_amv (amv) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amv,\
                     nd          STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     amv_loca_nd REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Localización del AMV");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Location of the SMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amv");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amc_oferpot_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amc_oferpot_ps (\
                     amc            STRING  REFERENCES id_amc (amc) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amc,\
                     pe             STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st             STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     amc_oferpot_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda ofertada por el AMC");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Demand bidded by the BMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amc_oferpcio_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amc_oferpcio_ps (\
                     amc             STRING  REFERENCES id_amc (amc) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amc,\
                     pe              STRING  REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st              STRING  REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     amc_oferpcio_ps REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Precio de demanda ofertado por el AMC");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Demand price offered by the BMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("amc_loca_nd");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS amc_loca_nd (\
                     amc         STRING  REFERENCES id_amc (amc) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT amc,\
                     nd          STRING  REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL DEFAULT nd,\
                     amc_loca_nd REAL    NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Localización del AMC");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Location of the BMA");
    m_tipo.Add(ID_MARGINALIST);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("amc");
    m_idx2.Add("nd");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    //Demand
    m_tables.Add("dem_ine_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_ine_ps (\
                     pe         STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st         STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_ine_ps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda inelastica de potencia");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Inelastic power demand");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_ord_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_ord_ps (\
                     pe         STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st         STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_ord_ps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Ordenada en el origen de la potencia demandada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Intercept of the power demand");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_pen_ps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_pen_ps (\
                     pe         STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st         STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_pen_ps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Pendiente de la potencia demandada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Slope of the power demand");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("pe");
    m_idx2.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_ine_nps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_ine_nps (\
                     nd          STRING REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     pe          STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st          STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_ine_nps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Demanda inelastica de potencia en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Inelastic power demand in each node");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_ord_nps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_ord_nps (\
                     nd          STRING REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     pe          STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st          STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_ord_nps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Ordenada en el origen de la potencia demandada en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Intercept of the power demand in each node");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_pen_nps");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_pen_nps (\
                     nd          STRING REFERENCES id_nd (nd) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     pe          STRING REFERENCES id_pe (pe) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     st          STRING REFERENCES id_st (st) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,\
                     dem_pen_nps REAL   NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Pendiente de la potencia demandada en cada nodo");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Slope of the power demand in each node");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add("nd");
    m_idx2.Add("pe");
    m_idx3.Add("st");
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
    
    m_tables.Add("dem_costoenenosum");
    m_sqlComands.Add("CREATE TABLE IF NOT EXISTS dem_costoenenosum (\
                     dem_costoenenosum REAL NOT NULL DEFAULT (0));");
    if (LAMBDA_LANGUAGE==ID_SPANISH) m_tablesTreeLabels.Add("Costo de la energía no sumnistrada");
    if (LAMBDA_LANGUAGE==ID_ENGLISH) m_tablesTreeLabels.Add("Cost of the non supplied energy");
    m_tipo.Add(ID_DEMAND);
    m_tidx.Add(ID_NO_IDX);
    m_idx1.Add(wxEmptyString);
    m_idx2.Add(wxEmptyString);
    m_idx3.Add(wxEmptyString);
    m_idx4.Add(wxEmptyString);
    m_idx5.Add(wxEmptyString);
};

#endif