$title LAMBDA Modelo de optimizacion de mercados de energia electrica

$offlisting
$offsymxref offsymlist
** Opciones
OPTION SYSOUT = OFF;
*OPTION SOLPRINT = SILENT;
OPTION SOLPRINT = OFF;
OPTION LIMROW = 0;
OPTION LIMCOL = 0;
OPTION MIQCP = CPLEX ;
OPTION MIP = CPLEX ;
OPTION LP = CPLEX ;
OPTION rMIQCP = CPLEX ;
OPTION rMIP = CPLEX ;
OPTION SOLVELINK = 2;
OPTION THREADS = 4;

** Opciones cplex
FILE opt cplex OPTION FILE /cplex.opt/;
PUT opt;
PUT 'lpmethod 6'/;
PUT 'startalg 6'/;
PUT 'threads 4'/;
PUT 'epgap 1e-20'/;
PUTCLOSE;

** Elemento fantasma
$PHANTOM NULL   

** Declaracion de los indices
SETS
    pe      periodos
    st      estados
    gt      grupos termico
    gh      grupos hidraulico
    em      empresas
    amv     agentes marginalistas de venta
    amc     agentes marginalistas de compra
    nd      nodos
;

ALIAS (st2,st) ;
ALIAS (gh2,gh) ;
ALIAS (nd2,nd) ;

** Declaracion de los conjuntos
SETS
*    Parametros temporales
    d_st1   caracteristicas de los estados
            / st_ini, st_fin /
*    Empresa
    d_em1   cuotas minimas de produccion de las empresa
            / em_cuotamin, em_pmin /
*    Grupos termicos
    d_gt1   caracteristicas de los grupos termicos
            / gt_pmax, gt_pmin, gt_aco_ini /
    d_gt2   costes de los grupos termicos
            / gt_cvacio, gt_carr, gt_cpar /
    d_gt3   energia maxima y minima de los  grupos termicos
            / gt_emin, gt_emax /
*    Grupos hidraulicos
    d_gh1   caracteristicas de los grupos hidraulicos
            / gh_upmaxres, gh_vpamxres, gh_rendturbom, gh_rini, gh_rfin /
*    Otros
    aux     auxiliar para salidas escalares
            / 1 /
;

** Opciones de ejecucion
SCALARS
*   Opcion de demanda
*       0   Demanda Inelastica
*       1   Demanda Elastica
    OPT_DEM

*   Opcion de tipo de equilibrio
*       0   Competencia perfecta
*       1   Variacion conjetural
    OPT_EQUI

*   Opcion de tipos de variables
*       0   Relajadas
*       1   Enteras
    OPT_ENT

*   Opcion de red
*       0   Sin red
*       1   Con red
    OPT_RED
;

** Parametros de entrada
PARAMETERS
*    Parametros temporales
    DUR_PS(pe,st)                   Duracion de los estados
    TRAN_PSS(pe,st,st2)             Transicion entre estado st y st2
    CARAC_PS(pe,st,d_st1)           Caracteristicas de los estados

*    Parametros de red
    RED_REAC(nd,nd2)                Reactancia de la linea entre los nodos nd y nd2
    RED_CAPLIN(nd,nd2)              Capacidad maxima de la linea

*    Parametros de las empresa
    EM_THETA_PS(em,pe,st)           Variacion conjetural del precio del sistema respecto a la produccion de la empresa en el periodo y estado
    EM_CBILPCIO_PS(em,pe,st)        Precio de los contratos bilaterales firmados por el empresa en el periodo y estado
    EM_CBILPOT_PS(em,pe,st)         Potencia de los contratos bilaterales de la empresa en el periodo y estado
    EM_CDIFPCIO_PS(em,pe,st)        Precio de los contratos por diferencias firmados por el empresa en el periodo y estado
    EM_CDIFPOT_PS(em,pe,st)         Potencia de los contratos por diferencias de la empresa en el periodo y estado
    EM_CUOTA(em,d_em1)              Cuota minima de produccion de la empresa

*    Parametros de los grupos termicos
    GT_CARAC(gt,d_gt1)              Caracteristicas del grupo termico
    GT_COSTOS(gt,d_gt2)             Costos del grupo termico
    GT_CVAR_P(gt,pe)                Costo variable del grupo termico por periodo
    GT_COEFDISP_P(gt,pe)            Coeficiente de disponibilidad del grupo termico por periodo
    GT_EMAX_P(gt,pe)                Energia maxima que debe producir el grupo por periodo
    GT_EMIN_P(gt,pe)                Energia minima que debe producir el grupo por periodo
    GT_ENER(gt,d_gt3)               Energia maxima y minima que debe producir el grupo a lo largo de todo el horizonte
    GT_PERT_EM(gt,em)               Pertencia del grupo termico a la empresa
    GT_LOCA_ND(gt,nd)               Localizacion del grupo (1 si esta en el nodo nd 0 en otro caso)

*    Parametros de los grupos hidraulicos
    GH_CARAC(gh,d_gh1)              Caracteristicas del grupo termico
    GH_APOR_P(gh,pe)                Aportaciones hidricas del grupo hidraulico recibidas por periodo
    GH_BMAX_P(gh,pe)                Potencia maxima de bombeo del grupo hidraulico por periodo
    GH_PFLU_PS(gh,pe,st)            Potencia fluyente del grupo hidraulico por periodo y estado
    GH_POBLI_P(gh,pe)               Produccion minima obligada del grupo hidraulico por periodo
    GH_RMAX_P(gh,pe)                Reserva maxima del grupo hidraulico por periodo
    GH_RMIN_P(gh,pe)                Reserva minima del grupo hidraulico por periodo
    GH_PERT_EM(gh,em)               Pertencia del grupo hidraulico a la empresa
    GH_SUP_GH(gh,gh2)               Sistemas hidraulicos inmediatamente superiores
    GH_LOCA_ND(gh,nd)               Localizacion del grupo (1 si esta en el nodo nd 0 en otro caso)

*    Parametros de los agentes marginalistas
    AMV_OFERPCIO_PS(amv,pe,st)      Precio de generacion ofertado por el amv por periodo y estado
    AMV_OFERPOT_PS(amv,pe,st)       Generacion ofertada por el amv por periodo y estado
    AMC_OFERPCIO_PS(amc,pe,st)      Precio de demanda ofertado por el amc por periodo y estado
    AMC_OFERPOT_PS(amc,pe,st)       Demanda ofertada por el amc por periodo y estado
    AMV_LOCA_ND(amv,nd)             Localizacion del agente marginalista (1 si esta en el nodo nd 0 en otro caso)
    AMC_LOCA_ND(amc,nd)             Localizacion del agente marginalista (1 si esta en el nodo nd 0 en otro caso)

*    Parametros de la demanda
    DEM_COSTOENENOSUM               Costo de la energia no sumnistrada
    DEM_ORD_PS(pe,st)               Ordenada en el origen de la potencia demandada en el periodo y estado
    DEM_PEN_PS(pe,st)               Pendiente de la potencia demandada en el periodo y estado
    DEM_INE_PS(pe,st)               Demanda inelastica
    DEM_ORD_NPS(nd,pe,st)           Ordenada en el origen de la potencia demandada en el periodo y estado por nodo
    DEM_PEN_NPS(nd,pe,st)           Pendiente de la potencia demandada en el periodo y estado por nodo
    DEM_INE_NPS(nd,pe,st)           Demanda inelastica por nodo
;

* Parametros auxiliares calculados para la ejecucion del modelo
PARAMETERS
    X_DUR_P(pe)                     Suma de las duraciones de los subperiodos
    X_DUR                           Suma de las duraciones de los periodos
;

* Parametros de salida para la ejecucion del modelo
PARAMETERS
* Sistema
*   Potencia demandada
    S_DEM_POT_PS(pe,st)             Demanda de potencia por periodo y estado
    S_DEM_POT_P(pe)                 Demanda media de potencia por periodo
    S_DEM_POT(aux)                  Demanda media de potencia
    S_DNS_POT_PS(pe,st)             Demanda No sumnistrada de potencia por periodo y estado
    S_DNS_POT_P(pe)                 Demanda No suministrada media de potencia por periodo
    S_DNS_POT(aux)                  Demanda No suministrada media de potencia
    S_DEM_POT_NPS(nd,pe,st)         Demanda de potencia en el nodo por periodo y estado
    S_DNS_POT_NPS(nd,pe,st)         Demanda No sumnistrada de potencia en el nodo por periodo y estado
*   Energia demandada
    S_DEM_ENE_PS(pe,st)             Demanda de Energia por periodo y estado
    S_DEM_ENE_P(pe)                 Demanda de Energia por periodo
    S_DEM_ENE(aux)                  Demanda de Energia
    S_DNS_ENE_PS(pe,st)             Demanda No sumnistrada de Energia por periodo y estado
    S_DNS_ENE_P(pe)                 Demanda No suministrada de Energia por periodo
    S_DNS_ENE(aux)                  Demanda No suministrada de Energia
*   Precios marginales
    S_PCIO_NPS(nd,pe,st)            Precio marginal por nodo por periodo y estado
    S_PCIO_PS(pe,st)                Precio marginal por periodo y estado
    S_PCIO_P(pe)                    Precio medio por periodo
    S_PCIOPOND_P(pe)                Precio medio ponderado por la energia
    S_PCIO(aux)                     Precio medio total
    S_PCIOPOND(aux)                 Precio medio total ponderado por la energia
*   Red
    S_FLUJO_PS(nd,nd2,pe,st)        Flujo entre los nodos nd y nd2 por periodo y estado

* Empresa
*   Potencia producida
    S_EM_POT_PS(em,pe,st)           Potencia total de la empresa por periodo y estado
    S_EM_POT_P(em,pe)               Potencia media total de la empresa por periodo
    S_EM_POT(em)                    Potencia media total de la empresa
    S_EM_POTPOS_PS(em,pe,st)        Posicion de la empresa por periodo y estado (potencia contratos)
    S_EM_POTPOS_P(em,pe)            Posicion de la empresa por periodo (potencia contratos)
    S_EM_POS(em)                    Posicion de la empresa (potencia contratos)
*   Energia producida
    S_EM_ENE_PS(em,pe,st)           Energia total de la empresa por periodo y estado
    S_EM_ENE_P(em,pe)               Energia total de la empresa por periodo
    S_EM_ENE(em)                    Energia total de la empresa
    S_EM_ENEPOS_PS(em,pe,st)        Posicion de la empresa por periodo y estado (Energia contratos)
    S_EM_ENEPOS_P(em,pe)            Posicion de la empresa por periodo (Energia contratos)
    S_EM_ENEPOS(em)                 Posicion de la empresa (Energia contratos)
*   Ingresos y Costos
    S_EM_BEN_PS(em,pe,st)           Beneficios de la empresa por periodo y estado
    S_EM_BEN_P(em,pe)               Beneficios de la empresa por periodo
    S_EM_BEN(em)                    Beneficios totales de la empresa
    S_EM_ING_PS(em,pe,st)           Ingresos de la empresa por periodo y estado
    S_EM_ING_P(em,pe)               Ingresos de la empresa por periodo
    S_EM_ING(em)                    Ingresos totales de la empresa
    S_EM_CARR_PS(em,pe,st)          Costos de arranque de la empresa por periodo y estado
    S_EM_CARR_P(em,pe)              Costos de arranque de la empresa por periodo
    S_EM_CARR(em)                   Costos de arranque totales de la empresa
    S_EM_CPAR_PS(em,pe,st)          Costos de parada de la empresa por periodo y estado
    S_EM_CPAR_P(em,pe)              Costos de parada de la empresa por periodo
    S_EM_CPAR(em)                   Costos de parada totales de la empresa
    S_EM_CVCIO_PS(em,pe,st)         Costos de vacio de la empresa por periodo y estado
    S_EM_CVCIO_P(em,pe)             Costos de vacio de la empresa por periodo
    S_EM_CVCIO(em)                  Costos de vacio totales de la empresa
    S_EM_CVAR_PS(em,pe,st)          Costos variables de la empresa por periodo y estado
    S_EM_CVAR_P(em,pe)              Costos variables de la empresa por periodo
    S_EM_CVAR(em)                   Costos variables totales de la empresa
    S_EM_CTOT_PS(em,pe,st)          Costos totales de la empresa por periodo y estado
    S_EM_CTOT_P(em,pe)              Costos totales de la empresa por periodo
    S_EM_CTOT(em)                   Costos totales totales de la empresa

* Grupo Termico
*   Potencia producida
    S_GT_POT_PS(gt,pe,st)           Potencia del grupo termico por periodo y estado
    S_GT_POT_P(gt,pe)               Potencia media del grupo termico por periodo
    S_GT_POT(gt)                    Potencia media total del grupo termico
*   Energia producida
    S_GT_ENE_PS(gt,pe,st)           Energia del grupo termico por periodo y estado
    S_GT_ENE_P(gt,pe)               Energia del grupo termico por periodo
    S_GT_ENE(gt)                    Energia total del grupo termico
*   Arranques y paradas de los grupos termicos
    S_GT_ARR_PS(gt,pe,st)           Arranques del grupo termico por periodo y estado
    S_GT_ARR_P(gt,pe)               Arranques del grupo termico por periodo
    S_GT_ARR(gt)                    Arranques totales del grupo termico
    S_GT_PAR_PS(gt,pe,st)           Paradas del grupo termico por periodo y estado
    S_GT_PAR_P(gt,pe)               Paradas del grupo termico por periodo
    S_GT_PAR(gt)                    Paradas totales del grupo termico
*   Costos
    S_GT_CARR_PS(gt,pe,st)          Costos de arranque del grupo termico por periodo y estado
    S_GT_CARR_P(gt,pe)              Costos de arranque del grupo termico por periodo
    S_GT_CARR(gt)                   Costos de arranque totales del grupo termico
    S_GT_CPAR_PS(gt,pe,st)          Costos de parada del grupo termico por periodo y estado
    S_GT_CPAR_P(gt,pe)              Costos de parada del grupo termico por periodo
    S_GT_CPAR(gt)                   Costos de parada totales del grupo termico
    S_GT_CVCIO_PS(gt,pe,st)         Costos de vacio del grupo termico por periodo y estado
    S_GT_CVCIO_P(gt,pe)             Costos de vacio del grupo termico por periodo
    S_GT_CVCIO(gt)                  Costos de vacio totales del grupo termico
    S_GT_CVAR_PS(gt,pe,st)          Costos variables del grupo termico por periodo y estado
    S_GT_CVAR_P(gt,pe)              Costos variables del grupo termico por periodo
    S_GT_CVAR(gt)                   Costos variables totales del grupo termico
    S_GT_CTOT_PS(gt,pe,st)          Costos totales del grupo termico por periodo y estado
    S_GT_CTOT_P(gt,pe)              Costos totales del grupo termico por periodo
    S_GT_CTOT(gt)                   Costos totales totales del grupo termico

* Grupo Hidraulico
*   Potencia producida
    S_GH_POT_PS(gh,pe,st)           Potencia del grupo hidraulico por periodo y estado
    S_GH_POT_P(gh,pe)               Potencia media del grupo hidraulico por periodo
    S_GH_POT(gh)                    Potencia media total del grupo hidraulico
    S_GH_POTBOM_PS(gh,pe,st)        Potencia de bombeo del grupo hidraulico por periodo y estado
    S_GH_POTBOM_P(gh,pe)            Potencia media de bombeo del grupo hidraulico por periodo
    S_GH_POTBOM(gh)                 Potencia media de bombeo del grupo hidraulico
*   Energia producida
    S_GH_ENE_PS(gh,pe,st)           Energia del grupo hidraulico por periodo y estado
    S_GH_ENE_P(gh,pe)               Energia del grupo hidraulico por periodo
    S_GH_ENE(gh)                    Energia total del grupo hidraulico
    S_GH_ENEBOM_PS(gh,pe,st)        Energia de bombeo del grupo hidraulico por periodo y estado
    S_GH_ENEBOM_P(gh,pe)            Energia de bombeo del grupo hidraulico por periodo
    S_GH_ENEBOM(gh)                 Energia de bombeo del grupo hidraulico
    S_GH_VE_P(gh,pe)                Energia vertida por el grupo hidraulico en el p
    S_GH_RES_P(gh,pe)               Reservas del grupo hidraulico al final del p
    S_GH_APOSINF_P(gh,gh2,pe)       Aportaciones al sistema inferior gh2 por p
* Valor del agua por grupo hidraulico
    S_GH_VAGUA_P(gh,pe)             Valor del agua del grupo hidraulico por periodo
    S_GH_VAGUA(gh)                  Valor del agua del grupo hidraulico

* Agentes Marginalistas
*   Potencia producida
    S_AMV_POT_PS(amv,pe,st)         Potencia del agente marginalista de venta por periodo y estado
    S_AMV_POT_P(amv,pe)             Potencia media del agente marginalista de venta por periodo
    S_AMV_POT(amv)                  Potencia media del agente marginalista
    S_AMC_POT_PS(amc,pe,st)         Potencia del agente marginalista de compra por periodo y estado
    S_AMC_POT_P(amc,pe)             Potencia media del agente marginalista de compra por periodo
    S_AMC_POT(amc)                  Potencia media del agente marginalista de compra
*   Energia producida
    S_AMV_ENE_PS(amv,pe,st)         Energia del agente marginalista de venta por periodo y estado
    S_AMV_ENE_P(amv,pe)             Energia del agente marginalista de venta por periodo
    S_AMV_ENE(amv)                  Energia del agente marginalista
    S_AMC_ENE_PS(amc,pe,st)         Energia del agente marginalista de compra por periodo y estado
    S_AMC_ENE_P(amc,pe)             Energia del agente marginalista de compra por periodo
    S_AMC_ENE(amc)                  Energia del agente marginalista de compra
;

* Variables de decision del modelo
VARIABLES
*    Variable de optimizacion
    C_FO_TOT                    Costo total
    C_FO_CARR                   Costos totales de arranque
    C_FO_CPAR                   Costos totales de parada
    C_FO_CVACIO                 Costos totales de vacio
    C_FO_CVAR                   Costos totales variables
    C_FO_AM                     Ingresos y costos totales de los agentes marginalistas
    C_FO_CENS                   Costo total de la energia no suministrada

*    Variables de las empresa
    EM_POT_PS(em,pe,st)         Potencia producida por la empresa en el periodo y estado
    
*    Variables de los grupos termicos
    GT_POT_PS(gt,pe,st)         Potencia producida por el grupo termico en el periodo y estado
    GT_ARR_PSS(gt,pe,st,st2)    Decision de arranque del grupo termico del estado st al estado st2
    GT_PAR_PSS(gt,pe,st,st2)    Decision de parada del grupo termico del estado st al estado st2
    GT_ARR_P(gt,pe)             Decision de arranque del grupo termico al inicio del periodo
    GT_PAR_P(gt,pe)             Decision de parada del grupo termico al inicio del periodo
    GT_ACO_PS(gt,pe,st)         Estado de acoplamiento del grupo en periodo y estado

*    Variables de los grupos hidraulicos
    GH_POT_PS(gh,pe,st)         Potencia turbinada por el grupo hidraulico en el periodo y estado
    GH_BOM_PS(gh,pe,st)         Potencia bombeada por el grupo hidraulico en el periodo y estado
    GH_VE_P(gh,pe)              Energia vertida por el grupo hidraulico en el p
    GH_RES_P(gh,pe)             Reservas del grupo hidraulico al final del p
    GH_EQUI_P(gh,pe)            Equivalente de la energia total del grupo hidraulico

*    Variables de los agentes marginalistas
    AMV_POT_PS(amv,pe,st)      Potencia de generacion aceptada a un amv en el periodo y estado
    AMC_POT_PS(amc,pe,st)      Demanda aceptada a un amc en el periodo y estado

*    Variables de la demanda
    DEM_PS(pe,st)              Demanda de potencia en el periodo y estado
    DNS_PS(pe,st)              Potencia no suministrada por periodo y estado
    DEM_NPS(nd,pe,st)          Demanda de potencia en el periodo y estado por nodo
    DEM_CBILPOT_NPS(nd,pe,st)  Potencia de los contratos bilaterales en cada nodo
    DNS_NPS(nd,pe,st)          Potencia no suministrada por periodo y estado por nodo

*    Variables de la red
    RED_ANG(nd,pe,st)          Angulo en el nodo por periodo y estado
    RED_FLX(nd,nd2,pe,st)      Flujo entre nodos nd y nd2 por periodo y estado
;

POSITIVE VARIABLES  C_FO_CARR, C_FO_CPAR, C_FO_CVACIO, C_FO_CVAR, C_FO_AM, C_FO_CENS ;
POSITIVE VARIABLES  EM_POT_PS ;
POSITIVE VARIABLES  GT_POT_PS, GT_ACO_PS ;
POSITIVE VARIABLES  GH_POT_PS, GH_BOM_PS, GH_VE_P, GH_RES_P ;
POSITIVE VARIABLES  AMV_POT_PS, AMC_POT_PS ;
POSITIVE VARIABLES  DEM_PS, DNS_PS, DEM_NPS, DNS_NPS, DEM_CBILPOT_NPS ;

BINARY VARIABLES    GT_ARR_PSS, GT_PAR_PSS, GT_ARR_P, GT_PAR_P ;

* Restricciones del modelo
EQUATIONS
*    Terminos de la funcion objetivo
    R_FO_TOT                        Funcion objetivo
    R_FO_CARR                       Costos de arranque
    R_FO_CPAR                       Costos de parada
    R_FO_CVACIO                     Costos de vacio
    R_FO_CVAR                       Costos variables
    R_FO_AM                         Ingresos y costos de los agentes marginalistas
    R_FO_CENS                       Costo de la energia no sumnistrada

*    Restricciones de demanda
    R_DEM_BALPOT_PS(pe,st)          Balance de porencia en cada ps
    R_DEM_BALPOT_NPS(nd,pe,st)      Balance de porencia en cada ps por nodo
    R_DEM_CBILPOT_PS(pe,st)         Balance de los contratos bilaterales
    
*    Restricciones de la red
    R_RED_FLUJO(nd,nd2,pe,st)       Flujo entre los nodos nd y nd2
    
*    Restricciones de las empresas
    R_EM_CUOTA(em)                  Restriccion de cuota de la empresa
    R_EM_POT_PS(em,pe,st)           Potencia de la empresa

*    Restricciones de los grupos termicos
    R_GT_PMIN_PS(gt,pe,st)          Potencia minima del grupo termico
    R_GT_PMAX_PS(gt,pe,st)          Potencia maxima del grupo termico
    R_GT_EMIN_P(gt,pe)              Energia minima del grupo termico en el p
    R_GT_EMAX_P(gt,pe)              Energia maxima del grupo termico en el p
    R_GT_ARRPAR_PSS(gt,pe,st,st2)   Restriccion de arranque y parada del grupo termico entre estados del p
    R_GT_ARRPAR_P(gt,pe)            Restriccion de arranque y parada al inicio del p
    R_GT_ETMIN(gt)                  Energia minima total producida por el grupo
    R_GT_ETMAX(gt)                  Energia maxima total producida por el grupo

*    Restricciones de los grupos hidrualicos
    R_GH_BALHID_P(gh,pe)            Balance hidraulico por p
    R_GH_EQUI_P(gh,pe)              Energia total equivalente del grupo por p
    R_GH_PMAX_PS(gh,pe,st)          Potencia maxima de turbinacion del grupo hidraulico
    R_GH_BMAX_PS(gh,pe,st)          Potencia maxima de bombeo del grupo hidraulico
    R_GH_EMIN_P(gh,pe)              Energia minima producida por el grupo hidraulico en el p
    R_GH_RMIM_P(gh,pe)              Reserva minima de los embalses
    R_GH_RMAX_P(gh,pe)              Reserva maxima de los embalses
    R_GH_RFIN_P(gh)                 Reserva final del embalse al final del horizonte de ejecucion

*    Restricciones de los agentes marginalistas
    R_AMV_PMAX_PS(amv,pe,st)        Potencia maxima generada por los amv
    R_AMC_PMAX_PS(amc,pe,st)        Demanda maxima suministrada a los amc
;

* Declaracion de las ecuaciones
*    Terminos de la funcion objetivo
R_FO_TOT..
    C_FO_TOT
    =E=
    C_FO_CARR + C_FO_CPAR + C_FO_CVACIO + C_FO_CVAR + C_FO_AM + C_FO_CENS 
    + SUM((em,pe,st), 0.5*DUR_PS(pe,st)*EM_THETA_PS(em,pe,st)*
                       (EM_POT_PS(em,pe,st)-EM_CBILPOT_PS(em,pe,st)-EM_CDIFPOT_PS(em,pe,st))*
                       (EM_POT_PS(em,pe,st)-EM_CBILPOT_PS(em,pe,st)-EM_CDIFPOT_PS(em,pe,st)))$(OPT_EQUI EQ 1)
    - SUM((pe,st)$(DEM_PEN_PS(pe,st)), DUR_PS(pe,st)*(1/DEM_PEN_PS(pe,st))*
                    (DEM_PS(pe,st)*DEM_ORD_PS(pe,st) - 0.5*DEM_PS(pe,st)*DEM_PS(pe,st)))$((OPT_DEM EQ 1) AND (OPT_RED EQ 0))
    - SUM((nd,pe,st)$(DEM_PEN_NPS(nd,pe,st)), DUR_PS(pe,st)*(1/DEM_PEN_NPS(nd,pe,st))*
                    (DEM_NPS(nd,pe,st)*DEM_ORD_NPS(nd,pe,st) 
                    - 0.5*DEM_NPS(nd,pe,st)*DEM_NPS(nd,pe,st)))$((OPT_DEM EQ 1) AND (OPT_RED EQ 1)) ;
                    
R_FO_CARR..
    C_FO_CARR
    =E=
    SUM(gt, GT_COSTOS(gt,'gt_carr') * 
            (SUM((pe,st,st2)$(ORD(st) NE ORD(st2)), TRAN_PSS(pe,st,st2)*GT_ARR_PSS(gt,pe,st,st2))
             + SUM(pe, GT_ARR_P(gt,pe)))) ;

R_FO_CPAR..
    C_FO_CPAR
    =E=
    SUM(gt, GT_COSTOS(gt,'gt_cpar') * 
            (SUM((pe,st,st2)$(ORD(st) NE ORD(st2)), TRAN_PSS(pe,st,st2)*GT_PAR_PSS(gt,pe,st,st2))
             + SUM(pe, GT_PAR_P(gt,pe)))) ;

R_FO_CVACIO..
    C_FO_CVACIO
    =E=
    SUM((gt,pe,st), GT_COSTOS(gt,'gt_cvacio')*DUR_PS(pe,st)*GT_ACO_PS(gt,pe,st)) ;

R_FO_CVAR..
    C_FO_CVAR
    =E=
    SUM((gt,pe,st), GT_CVAR_P(gt,pe)*DUR_PS(pe,st)*GT_POT_PS(gt,pe,st)) ;

R_FO_AM..
    C_FO_AM
    =E=
    SUM((amv,pe,st), DUR_PS(pe,st)*(AMV_POT_PS(amv,pe,st)*AMV_OFERPCIO_PS(amv,pe,st)))
    - SUM((amc,pe,st), DUR_PS(pe,st)*(AMC_POT_PS(amc,pe,st)*AMC_OFERPCIO_PS(amc,pe,st))) ;

R_FO_CENS..
    C_FO_CENS
    =E=
    SUM((pe,st), DUR_PS(pe,st)*DEM_COSTOENENOSUM*DNS_PS(pe,st)) ;

*    Restricciones de demanda
R_DEM_BALPOT_PS(pe,st)$(OPT_RED EQ 0)..
    SUM(gt, GT_POT_PS(gt,pe,st)) + SUM(gh, GH_POT_PS(gh,pe,st)) + SUM(amv, AMV_POT_PS(amv,pe,st))
    =E=
    DEM_PS(pe,st) + SUM(em, EM_CBILPOT_PS(em,pe,st)) + SUM(gh, GH_BOM_PS(gh,pe,st))
    + SUM(amc, AMC_POT_PS(amc,pe,st)) + DNS_PS(pe,st) ;

R_DEM_BALPOT_NPS(nd,pe,st)$(OPT_RED EQ 1)..
    SUM(gt$(GT_LOCA_ND(gt,nd)), GT_POT_PS(gt,pe,st)) + SUM(gh$(GH_LOCA_ND(gh,nd)), GH_POT_PS(gh,pe,st)) 
    + SUM(amv$(AMV_LOCA_ND(amv,nd)), AMV_POT_PS(amv,pe,st))
    - SUM(nd2$(ORD(nd) NE ORD(nd2)), RED_FLX(nd,nd2,pe,st)) 
    =E=
    DEM_NPS(nd,pe,st) + DEM_CBILPOT_NPS(nd,pe,st) + SUM(gh$(GH_LOCA_ND(gh,nd)), GH_BOM_PS(gh,pe,st))
    + SUM(amc$(AMC_LOCA_ND(amc,nd)), AMC_POT_PS(amc,pe,st)) + DNS_NPS(nd,pe,st) ;
    
R_DEM_CBILPOT_PS(pe,st)$(OPT_RED EQ 1)..
    SUM(nd, DEM_CBILPOT_NPS(nd,pe,st))
    =E=
    SUM(em, EM_CBILPOT_PS(em,pe,st)) ;
    
*    Restricciones de la red
R_RED_FLUJO(nd,nd2,pe,st)$((OPT_RED EQ 1) AND (ORD(nd) NE ORD(nd2)))..
    RED_FLX(nd,nd2,pe,st)
    =E=
    RED_REAC(nd,nd2)*(RED_ANG(nd,pe,st) - RED_ANG(nd2,pe,st)) ;
    
*    Restricciones de las empresas
R_EM_CUOTA(em)$(EM_CUOTA(em,'em_cuotamin'))..
    SUM((pe,st), DUR_PS(pe,st)*EM_POT_PS(em,pe,st))
    =G=
    EM_CUOTA(em,'em_cuotamin')*SUM((pe,st), DUR_PS(pe,st)*DEM_PS(pe,st)) ;

R_EM_POT_PS(em,pe,st)..
    EM_POT_PS(em,pe,st)
    =E=
    SUM(gt, GT_PERT_EM(gt,em)*GT_POT_PS(gt,pe,st))
    + SUM(gh, GH_PERT_EM(gh,em)*(GH_POT_PS(gh,pe,st)-GH_BOM_PS(gh,pe,st))) ;

*    Restricciones de los grupos termicos
R_GT_PMIN_PS(gt,pe,st)..
    GT_POT_PS(gt,pe,st)
    =G=
    GT_CARAC(gt,'gt_pmin')*GT_ACO_PS(gt,pe,st)*GT_COEFDISP_P(gt,pe) ;

R_GT_PMAX_PS(gt,pe,st)..
    GT_POT_PS(gt,pe,st)
    =L=
    GT_CARAC(gt,'gt_pmax')*GT_ACO_PS(gt,pe,st)*GT_COEFDISP_P(gt,pe) ;

R_GT_EMIN_P(gt,pe)$(GT_EMIN_P(gt,pe))..
    SUM(st, GT_POT_PS(gt,pe,st)*DUR_PS(pe,st))
    =G=
    GT_EMIN_P(gt,pe) ;

R_GT_EMAX_P(gt,pe)$(GT_EMAX_P(gt,pe))..
    SUM(st, GT_POT_PS(gt,pe,st)*DUR_PS(pe,st))
    =L=
    GT_EMAX_P(gt,pe) ;

R_GT_ARRPAR_PSS(gt,pe,st,st2)$(ORD(st) NE ORD(st2))..
    GT_ARR_PSS(gt,pe,st,st2) - GT_PAR_PSS(gt,pe,st,st2)
    =E=
    GT_ACO_PS(gt,pe,st2) - GT_ACO_PS(gt,pe,st) ;

R_GT_ARRPAR_P(gt,pe)..
    GT_ARR_P(gt,pe) - GT_PAR_P(gt,pe)
    =E=
    SUM(st$CARAC_PS(pe,st,'st_ini'), GT_ACO_PS(gt,pe,st))
    - SUM(st$CARAC_PS(pe-1,st,'st_fin'), GT_ACO_PS(gt,pe-1,st))$(ORD(pe) GT 1)
    - GT_CARAC(gt,'gt_aco_ini')$(ORD(pe) EQ 1) ;

R_GT_ETMIN(gt)$(GT_ENER(gt,'gt_emin'))..
    SUM((pe,st), DUR_PS(pe,st)*GT_POT_PS(gt,pe,st))
    =G=
    GT_ENER(gt,'gt_emin') ;

R_GT_ETMAX(gt)$(GT_ENER(gt,'gt_emax'))..
    SUM((pe,st), DUR_PS(pe,st)*GT_POT_PS(gt,pe,st))
    =L=
    GT_ENER(gt,'gt_emax') ;

*    Restricciones de los grupos hidrualicos
R_GH_BALHID_P(gh,pe)..
    GH_RES_P(gh,pe) - GH_RES_P(gh,pe-1)$(ORD(pe) GT 1) - GH_CARAC(gh,'gh_rini')$(ORD(pe) EQ 1)
    =E=
    GH_APOR_P(gh,pe) + SUM(gh2$(GH_SUP_GH(gh2,gh)), GH_SUP_GH(gh2,gh)*GH_EQUI_P(gh2,pe))
    - GH_EQUI_P(gh,pe) ;
    
R_GH_EQUI_P(gh,pe)..
    GH_EQUI_P(gh,pe)
    =E=
    SUM(st, DUR_PS(pe,st)*(GH_POT_PS(gh,pe,st) - GH_CARAC(gh,'gh_rendturbom')*GH_BOM_PS(gh,pe,st)))
    + GH_VE_P(gh,pe) ;

R_GH_PMAX_PS(gh,pe,st)..
    GH_POT_PS(gh,pe,st)
    =L=
    GH_CARAC(gh,'gh_upmaxres') + GH_CARAC(gh,'gh_vpamxres')*GH_RES_P(gh,pe) ;

R_GH_BMAX_PS(gh,pe,st)..
    GH_BOM_PS(gh,pe,st)
    =L=
    GH_BMAX_P(gh,pe) ;

R_GH_EMIN_P(gh,pe)$(GH_POBLI_P(gh,pe))..
    SUM(st, DUR_PS(pe,st)*GH_POT_PS(gh,pe,st))
    =G=
    GH_POBLI_P(gh,pe) ;

R_GH_RMIM_P(gh,pe)$(GH_RMIN_P(gh,pe))..
    GH_RES_P(gh,pe)
    =G=
    GH_RMIN_P(gh,pe) ;

R_GH_RMAX_P(gh,pe)$(GH_RMAX_P(gh,pe))..
    GH_RES_P(gh,pe)
    =L=
    GH_RMAX_P(gh,pe) ;

R_GH_RFIN_P(gh)$(GH_CARAC(gh,'gh_rfin'))..
    SUM(pe$(ORD(pe) EQ CARD(pe)), GH_RES_P(gh,pe))
    =E=
    GH_CARAC(gh,'gh_rfin') ;

*    Restricciones de los agentes marginalistas
R_AMV_PMAX_PS(amv,pe,st)..
    AMV_POT_PS(amv,pe,st)
    =L=
    AMV_OFERPOT_PS(amv,pe,st) ;

R_AMC_PMAX_PS(amc,pe,st)..
    AMC_POT_PS(amc,pe,st)
    =L=
    AMC_OFERPOT_PS(amc,pe,st) ;

** Defincion del Modelo
*   LAMBDA   
MODEL LAMBDA_INE_CP
      / R_FO_TOT, R_FO_CARR, R_FO_CPAR, R_FO_CVACIO, R_FO_CVAR, R_FO_AM, R_FO_CENS,
        R_DEM_BALPOT_PS, R_DEM_BALPOT_NPS, R_DEM_CBILPOT_PS,
        R_RED_FLUJO,  
        R_EM_CUOTA, R_EM_POT_PS,
        R_GT_PMIN_PS, R_GT_PMAX_PS, R_GT_EMIN_P, R_GT_EMAX_P,
        R_GT_ARRPAR_PSS, R_GT_ARRPAR_P, R_GT_ETMIN, R_GT_ETMAX,
        R_GH_BALHID_P, R_GH_EQUI_P, R_GH_PMAX_PS, R_GH_BMAX_PS, R_GH_EMIN_P, R_GH_RMIM_P,
        R_GH_RMAX_P, R_GH_RFIN_P,
        R_AMV_PMAX_PS, R_AMC_PMAX_PS
      / ;

** Datos de entrada
$include lambdadatos.cod
** Pre_solve
$include lambdapresolve.cod
** Solucion del modelo
$include lambdasolve.cod
** Datos de salida
$include lambdasalidas.cod
** Salva los datos de salida
$include lambdagms2sql.cod

