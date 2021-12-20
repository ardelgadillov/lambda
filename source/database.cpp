//
//  LambdaDatabase.cpp
//  lambda
//
//  Created by Andres Delgadillo on 15/09/15.
//
//

#ifndef lambda_database_cpp
#define lambda_database_cpp

#include "database.h"

/************************************************************************/
/*						LambdaDatatables Implementation						*/
/************************************************************************/

LambdaDatatables::LambdaDatatables(int pos, bool input) : wxTreeItemData()
{
    m_pos = pos;
    m_input = input;
};

LambdaDatatables::~LambdaDatatables()
{
};

void LambdaDatatables::SetPos(int pos)
{
    m_pos = pos;
};

int LambdaDatatables::GetPos()
{
    return m_pos;
};

bool LambdaDatatables::IsInput()
{
    return m_input;
};

/************************************************************************/
/*						LambdaDatabase Implementation                         */
/************************************************************************/
LambdaDatabase::LambdaDatabase(wxString file)
{
    m_file = file;
    //Database
    m_database = new wxSQLite3Database();
	
    //Todos los indices
    m_idxAll.Add("pe");
    m_idxAll.Add("st");
    m_idxAll.Add("em");
    m_idxAll.Add("gt");
    m_idxAll.Add("gh");
    m_idxAll.Add("amv");
    m_idxAll.Add("amc");
    m_idxAll.Add("nd");
};

LambdaDatabase::~LambdaDatabase()
{
    m_database->ExecuteQuery("PRAGMA main.locking_mode=NORMAL;");
    delete m_database;
};

//Si create es true crea las tablas
void LambdaDatabase::Opendb(bool create)
{
    //Open the LambdaDatabase
	m_database->Open(m_file);
	m_database->ExecuteQuery("PRAGMA main.locking_mode=EXCLUSIVE;");
	m_database->ExecuteQuery("PRAGMA synchronous = OFF;");
	//Set journal mode WAL
	//m_database->SetJournalMode(WXSQLITE_JOURNALMODE_WAL);
	m_database->SetJournalMode(WXSQLITE_JOURNALMODE_OFF);
    //Create the info of the tables
    InfoTables();
    InfoCols();
    NumberIdx();
    if (create) CreateTables();
};

/*  new_idx: Nuevo dato en la tabla
    tipo: Tipo de indice 
        "pe" - Periods
        "st" - States
        "em" - Companies
        "gt" - Thermal groups
        "gh" - Hydro groups
        "amv" - Agente marginalista de venta
        "amc" - Agente marginalista de compra; */
void LambdaDatabase::UpdateTables(wxString new_idx, wxString tipo)
{
    int i, j, j1;
    int k0, k1, k2, k3;
    wxArrayString tabla_idx; //Nombres de las tablas con los indices
    wxArrayString label_tabla_idx;  //Nombres de las columnas con los indices
    wxArrayInt size_idx; //Tamano de los indices
    wxArrayString valores_idx; //Valores con los indices de las tablas
    wxArrayInt b_tabla_idx; //Indica si la tabla de indices existe
    bool b_idx_table;   //indica si el indice esta en la tabla
    
    wxSQLite3Table valores_t0; //Valores de los indices de la tabla 1
    wxSQLite3Table valores_t1; //Valores de los indices de la tabla 2
    wxSQLite3Table valores_t2; //Valores de los indices de la tabla 3
    wxSQLite3Table valores_t3; //Valores de los indices de la tabla 4
    
    int size = 4;   //Hay 4 indices
    tabla_idx.Alloc(size);
    label_tabla_idx.Alloc(size);
    size_idx.Alloc(size);
    valores_idx.Alloc(size);
    b_tabla_idx.Alloc(size);
    
    //Inicializa los vectores
    for(j=0; j<size; j++)
    {
        tabla_idx.Add(wxEmptyString);
        label_tabla_idx.Add(wxEmptyString);
        valores_idx.Add(wxEmptyString);
        size_idx.Add(0);
        b_tabla_idx.Add(0);
    }
    
    wxSQLite3Transaction transaction(m_database);
    
    //para las tablas de la base de datos
    for (i=0; i<m_tables.GetCount(); i++)
    {
        //por defecto el indice esta en la tabla
        b_idx_table = true;
        
        //Borra el valor de los elementos
        for(j=0; j<size; j++)
        {
            tabla_idx.Item(j) = wxEmptyString;
            label_tabla_idx.Item(j) = wxEmptyString;
            valores_idx.Item(j) = wxEmptyString;
            size_idx.Item(j) = 0;
            b_tabla_idx.Item(j) = 0; //Por defecto la tabla no existe
        }
        
        //Determina las tablas con los indices de la tabla
        if (m_idx1.Item(i) == tipo)
        {
            tabla_idx.Item(0) = "id_" + m_idx2.Item(i);
            tabla_idx.Item(1) = "id_" + m_idx3.Item(i);
            tabla_idx.Item(2) = "id_" + m_idx4.Item(i);
            tabla_idx.Item(3) = "id_" + m_idx5.Item(i);
            label_tabla_idx.Item(0) = m_idx2.Item(i);
            label_tabla_idx.Item(1) = m_idx3.Item(i);
            label_tabla_idx.Item(2) = m_idx4.Item(i);
            label_tabla_idx.Item(3) = m_idx5.Item(i);
        }
        else if (m_idx2.Item(i) == tipo)
        {
            tabla_idx.Item(0) = "id_" + m_idx1.Item(i);
            tabla_idx.Item(1) = "id_" + m_idx3.Item(i);
            tabla_idx.Item(2) = "id_" + m_idx4.Item(i);
            tabla_idx.Item(3) = "id_" + m_idx5.Item(i);
            label_tabla_idx.Item(0) = m_idx1.Item(i);
            label_tabla_idx.Item(1) = m_idx3.Item(i);
            label_tabla_idx.Item(2) = m_idx4.Item(i);
            label_tabla_idx.Item(3) = m_idx5.Item(i);
        }
        else if (m_idx3.Item(i) == tipo)
        {
            tabla_idx.Item(0) = "id_" + m_idx1.Item(i);
            tabla_idx.Item(1) = "id_" + m_idx2.Item(i);
            tabla_idx.Item(2) = "id_" + m_idx4.Item(i);
            tabla_idx.Item(3) = "id_" + m_idx5.Item(i);
            label_tabla_idx.Item(0) = m_idx1.Item(i);
            label_tabla_idx.Item(1) = m_idx2.Item(i);
            label_tabla_idx.Item(2) = m_idx4.Item(i);
            label_tabla_idx.Item(3) = m_idx5.Item(i);
        }
        else if (m_idx4.Item(i) == tipo)
        {
            tabla_idx.Item(0) = "id_" + m_idx1.Item(i);
            tabla_idx.Item(1) = "id_" + m_idx2.Item(i);
            tabla_idx.Item(2) = "id_" + m_idx3.Item(i);
            tabla_idx.Item(3) = "id_" + m_idx5.Item(i);
            label_tabla_idx.Item(0) = m_idx1.Item(i);
            label_tabla_idx.Item(1) = m_idx2.Item(i);
            label_tabla_idx.Item(2) = m_idx3.Item(i);
            label_tabla_idx.Item(3) = m_idx5.Item(i);
        }
        else if (m_idx5.Item(i) == tipo)
        {
            tabla_idx.Item(0) = "id_" + m_idx1.Item(i);
            tabla_idx.Item(1) = "id_" + m_idx2.Item(i);
            tabla_idx.Item(2) = "id_" + m_idx3.Item(i);
            tabla_idx.Item(3) = "id_" + m_idx4.Item(i);
            label_tabla_idx.Item(0) = m_idx1.Item(i);
            label_tabla_idx.Item(1) = m_idx2.Item(i);
            label_tabla_idx.Item(2) = m_idx3.Item(i);
            label_tabla_idx.Item(3) = m_idx4.Item(i);
        }
        else
        {
            //Si el indice no esta en la tabla
            b_idx_table = false;
        }
        
        //Si el indice esta repetido en la tabla
        for (j=0; j<size; j++)
        {
            if (tipo==label_tabla_idx.Item(j)) label_tabla_idx.Item(j) = tipo + "2";
            for (j1=j+1; j1<size; j1++)
                if (tabla_idx.Item(j)==tabla_idx.Item(j1)) label_tabla_idx.Item(j1) = label_tabla_idx.Item(j) + "2";
        }
        
        //si el indice esta en la tabla
        if (b_idx_table)
        {
            //Para cada indice si la tabla de indices existe recupera los valores
            if (m_database->TableExists(tabla_idx.Item(0)))
            {
                valores_t0 = SqlGet(tabla_idx.Item(0));
                size_idx.Item(0) = valores_t0.GetRowCount();
                b_tabla_idx.Item(0) = 1;
            }
            if (m_database->TableExists(tabla_idx.Item(1)))
            {
                valores_t1 = SqlGet(tabla_idx.Item(1));
                size_idx.Item(1) = valores_t1.GetRowCount();
                b_tabla_idx.Item(1) = 1;
            }
            if (m_database->TableExists(tabla_idx.Item(2)))
            {
                valores_t2 = SqlGet(tabla_idx.Item(2));
                size_idx.Item(2) = valores_t2.GetRowCount();
                b_tabla_idx.Item(2) = 1;
            }
            if (m_database->TableExists(tabla_idx.Item(3)))
            {
                valores_t3 = SqlGet(tabla_idx.Item(3));
                size_idx.Item(3) = valores_t3.GetRowCount();
                b_tabla_idx.Item(3) = 1;
            }
            
            //Ya se tienen los valores de los indices de la tabla
            //Para la tabla 0 de indices
            for (k0=-1; k0<size_idx.Item(0); k0++)
            {
                //Se recupera el valor del indice de la tabla 0
                if (k0>=0) valores_idx.Item(0) = valores_t0.ReturnDataString(k0, 0);
                //Para la tabla 1 de indices
                for (k1=-1; k1<size_idx.Item(1); k1++)
                {
                    //Se recupera el valor del indice de la tabla 1
                    if (k1>=0) valores_idx.Item(1) = valores_t1.ReturnDataString(k1, 0);
                    //Para la tabla 2 de indices
                    for (k2=-1; k2<size_idx.Item(2); k2++)
                    {
                        //Se recupera el valor del indice de la tabla 2
                        if (k2>=0) valores_idx.Item(2) = valores_t2.ReturnDataString(k2, 0);
                        //Para la tabla 3 de indices
                        for (k3=-1; k3<size_idx.Item(3); k3++)
                        {
                            //Se recupera el valor del indice de la tabla 3
                            if (k3>=0) valores_idx.Item(3) = valores_t3.ReturnDataString(k3, 0);
                            
                            //Entonces el unico indice es new_idx
                            if (b_tabla_idx.Item(0)==0) SqlInsert(m_tables.Item(i), tipo, new_idx); //Se agrega la nueva fila a la tabla
                            //Entonces los indices son new_idx y valores_idx.Item(0)
                            else if (b_tabla_idx.Item(1)==0)
                            {
                                //si la tabla de indices tiene datos
                                if ((size_idx.Item(0) > 0) & (k0>=0))
                                {
                                    //Se agrega la nueva fila a la tabla
                                    SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), new_idx, valores_idx.Item(0));
                                    //Si son indices repetidos en la tabla Y si son valores diferentes
                                    if ((label_tabla_idx.Item(0) == tipo + "2") & (valores_idx.Item(0) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), valores_idx.Item(0), new_idx); //Se agrega la nueva fila a la tabla
                                }
                            }
                            //Entonces los indices son new_idx, valores_idx.Item(0), valores_idx.Item(1)
                            else if (b_tabla_idx.Item(2)==0)
                            {
                                //si las tablas de indices tiene datos
                                if ((size_idx.Item(0) > 0) & (size_idx.Item(1) > 0) & (k0>=0) & (k1>=0))
                                {
                                    //Se agrega la nueva fila a la tabla
                                    SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), new_idx, valores_idx.Item(0), valores_idx.Item(1));
                                    //Si son indices repetidos en la tabla Y si son valores diferentes
                                    if ((label_tabla_idx.Item(0) == tipo + "2") & (valores_idx.Item(0) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), valores_idx.Item(0), new_idx, valores_idx.Item(1)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(1) == tipo + "2") & (valores_idx.Item(1) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), valores_idx.Item(1), valores_idx.Item(0), new_idx); //Se agrega la nueva fila a la tabla
                                }
                            }
                            //Entonces los indices son new_idx, valores_idx.Item(0), valores_idx.Item(1), valores_idx.Item(2)
                            else if (b_tabla_idx.Item(3)==0)
                            {
                                //si las tablas de indices tiene datos
                                if ((size_idx.Item(0) > 0) & (size_idx.Item(1) > 0) & (size_idx.Item(2) > 0) & (k0>=0) & (k1>=0) & (k2>=0))
                                {
                                    //Se agrega la nueva fila a la tabla
                                    SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), new_idx, valores_idx.Item(0), valores_idx.Item(1), valores_idx.Item(2));
                                    //Si son indices repetidos en la tabla Y si son valores diferentes
                                    if ((label_tabla_idx.Item(0) == tipo + "2") & (valores_idx.Item(0) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), valores_idx.Item(0), new_idx, valores_idx.Item(1), valores_idx.Item(2)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(1) == tipo + "2") & (valores_idx.Item(1) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), valores_idx.Item(1), valores_idx.Item(0), new_idx, valores_idx.Item(2)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(2) == tipo + "2") & (valores_idx.Item(2) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), valores_idx.Item(2), valores_idx.Item(0), valores_idx.Item(1), new_idx); //Se agrega la nueva fila a la tabla
                                }
                            }
                            //Entonces los indices son new_idx, valores_idx.Item(0), valores_idx.Item(1), valores_idx.Item(2), valores_idx.Item(3)
                            else
                            {
                                //si las tablas de indices tiene datos
                                if ((size_idx.Item(0) > 0) & (size_idx.Item(1) > 0) & (size_idx.Item(2) > 0) & (size_idx.Item(3) > 0) & (k0>=0) & (k1>=0) & (k2>=0) & (k3>=0))
                                {
                                    //Se agrega la nueva fila a la tabla
                                    SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), label_tabla_idx.Item(3), new_idx, valores_idx.Item(0), valores_idx.Item(1), valores_idx.Item(2), valores_idx.Item(3));
                                    //Si son indices repetidos en la tabla Y si son valores diferentes
                                    if ((label_tabla_idx.Item(0) == tipo + "2") & (valores_idx.Item(0) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), label_tabla_idx.Item(3), valores_idx.Item(0), new_idx, valores_idx.Item(1), valores_idx.Item(2), valores_idx.Item(3)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(1) == tipo + "2") & (valores_idx.Item(1) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), label_tabla_idx.Item(3),valores_idx.Item(1), valores_idx.Item(0), new_idx, valores_idx.Item(2), valores_idx.Item(3)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(2) == tipo + "2") & (valores_idx.Item(2) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), label_tabla_idx.Item(3), valores_idx.Item(2), valores_idx.Item(0), valores_idx.Item(1), new_idx, valores_idx.Item(3)); //Se agrega la nueva fila a la tabla
                                    if ((label_tabla_idx.Item(3) == tipo + "2") & (valores_idx.Item(3) != new_idx))
                                        SqlInsert(m_tables.Item(i), tipo, label_tabla_idx.Item(0), label_tabla_idx.Item(1), label_tabla_idx.Item(2), label_tabla_idx.Item(3), valores_idx.Item(3), valores_idx.Item(0), valores_idx.Item(1), valores_idx.Item(2), new_idx); //Se agrega la nueva fila a la tabla
                                }
                            }
                        }
                    }
                }
            }
            //ordena la tabla
            SqlSort(m_tables.Item(i));
        }
    }
    transaction.Commit();
//    m_database->WriteAheadLogCheckpoint("main");
};

wxString LambdaDatabase::Label(wxString col)
{
    wxString lab = wxEmptyString;
    int i=0;
    //busca la columna
    while ((i<m_col_name.GetCount()) && (m_col_name.Item(i)!=col))
        i++;
    
    if (m_col_name.Item(i)==col)
        //recupera el label
        lab = m_col_label.Item(i);
    
    return lab;
};

void LambdaDatabase::SqlInsert(wxString table, wxString lb1, wxString value1)
{
    //Se agrega la nueva fila a la tabla
    m_database->ExecuteQuery("INSERT INTO " + table + " (" + lb1 + ") VALUES ('" + value1 + "');");
};

void LambdaDatabase::SqlInsert(wxString table, wxString lb1, wxString lb2, wxString value1, wxString value2)
{
    //Se agrega la nueva fila a la tabla
    m_database->ExecuteQuery("INSERT INTO " + table + " (" + lb1 + ", " + lb2 + ") VALUES ('" + value1 + "', '" + value2 + "');");
};

void LambdaDatabase::SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString value1, wxString value2, wxString value3)
{
    //Se agrega la nueva fila a la tabla
    m_database->ExecuteQuery("INSERT INTO " + table + " (" + lb1 + ", " + lb2 + ", " + lb3 + ") VALUES ('" + value1 + "', '" + value2 + "', '" + value3 + "');");
};

void LambdaDatabase::SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString lb4, wxString value1, wxString value2, wxString value3, wxString value4)
{
    //Se agrega la nueva fila a la tabla
    m_database->ExecuteQuery("INSERT INTO " + table + " (" + lb1 + ", " + lb2 + ", " + lb3 + ", " + lb4 + ") VALUES ('" + value1 + "', '" + value2 + "', '" + value3 + "', '" + value4 + "');");
};

void LambdaDatabase::SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString lb4, wxString lb5, wxString value1, wxString value2, wxString value3, wxString value4, wxString value5)
{
    //Se agrega la nueva fila a la tabla
    m_database->ExecuteQuery("INSERT INTO " + table + " (" + lb1 + ", " + lb2 + ", " + lb3 + ", " + lb4 + ", " + lb5 + ") VALUES ('" + value1 + "', '" + value2 + "', '" + value3+ "', '" + value4 + "', '" + value5 + "');");
};

wxSQLite3Table LambdaDatabase::SqlGet(wxString table)
{
    return m_database->GetTable("SELECT * FROM " + table + ";");
};

int LambdaDatabase::SqlLabels(wxString table, wxArrayString *labels)
{
    int i, rows;
    //devuelve la informacion de la tabla
    wxSQLite3Table pragma = m_database->GetTable("PRAGMA table_info('" + table + "');");
    rows = pragma.GetRowCount();
    //limpia el arreglo de los labels
    labels->Empty();
    //inserta en labels el label
    for (i=0; i<rows; i++) labels->Add(pragma.ReturnDataString(i, 1));
    return rows;
};

void LambdaDatabase::SqlSort(wxString table)
{
    wxString sqlcom;
    wxString sqlschema;
    wxArrayString labelcom;
    int rowscom,j;
    
    //wxSQLite3Transaction transaction(m_database);
    
    //Crea una tabla auxiliar
    sqlschema = m_database->GetTable("SELECT sql FROM\
                                        (SELECT * FROM sqlite_master UNION ALL\
                                         SELECT * FROM sqlite_temp_master)\
                                      WHERE tbl_name LIKE '" + table + "'\
                                        AND type!='meta' AND sql NOT NULL AND name NOT LIKE 'sqlite_%'\
                                      ORDER BY substr(type,2,1), name").ReturnDataString(0, 0);
    sqlschema.Replace(table, table + "_aux", false);
    m_database->ExecuteUpdate(sqlschema);
    
    //ordena la tabla
    rowscom = SqlLabels(table, &labelcom);
    sqlcom = "INSERT INTO " + table + "_aux SELECT * FROM " + table + " ORDER BY ";
    for (j=0; j<rowscom-1; j++)
    {
        sqlcom += labelcom.Item(j) + ",";
    }
    sqlcom += labelcom.Item(rowscom-1) + ";";
    m_database->ExecuteQuery(sqlcom);
    
    //borra la tabla anterior
    m_database->ExecuteQuery("DROP TABLE " + table + ";");
    //copia la tabla ordenada
    m_database->ExecuteQuery("ALTER TABLE " + table + "_aux RENAME TO " + table + ";");
    
    //transaction.Commit();
}

//Guarda la base de datos en un fichero de texto
void LambdaDatabase::SqlSave(wxString table, wxString dir, int tipo)
{
    int i,j;
    int rows, cols;
    wxArrayString labels; //labels de la tabla
    wxArrayInt global_labels;  //indica los labels globales de la tabla
    int n_global;   //Numero de labels globales
    int n_local;    //Numero de labels locales
    wxString str_linea;     //texto con la linea de la tabla
    wxString str_linea2;    //texto con la linea de la tabla
    wxString file_name = dir + "/" + table + ".dat";
    
    //recupera la tabla
    wxSQLite3Table sqltabla = SqlGet(table);
    rows = sqltabla.GetRowCount();
    cols = sqltabla.GetColumnCount();
    
    //borra el fichero si existe
    if (wxFileExists(file_name)) wxRemoveFile(file_name);

    //Si la tabla no esta vacia
    if ((rows>0) && (cols>0))
    {
        //crea un nuevo fichero
        wxTextFile *file_tabla = new wxTextFile(file_name);  //fichero con los datos de la tabla
        file_tabla->Create();
        file_tabla->AddLine("/");
        
        //recupera los titulos de la tabla
        labels.Alloc(cols);
        global_labels.Alloc(cols);
        n_global = 0;
        for (i=0; i<cols; i++)
        {
            //agrega el label de la columa
            labels.Add(sqltabla.GetColumnName(i));
            global_labels.Add(0);
            //compara si el label es global
            if (CompareLabels(labels.Item(i)))
            {
                global_labels.Item(i)=1;
                n_global++;
            }
        }
        n_local = cols-n_global;
        
        //Para cada linea de la tabla
        for (i=0; i<rows; i++)
        {
            str_linea = wxEmptyString;
            //fila la linea i
            sqltabla.SetRow(i);
            //si es una tabla normal
            if (tipo==ID_NO_IDX)
            {
                //para los labels globales
                for (j=0; j<n_global-1; j++)
                {
                    str_linea += sqltabla.GetString(j) + ".";
                }
                if (n_global>0) str_linea += sqltabla.GetString(n_global-1);
                
                //si n_local es uno escribe el dato
                if (n_local==1)
                {
                    str_linea +=  "    " + wxString::Format(wxT("%10.4f"), sqltabla.GetDouble(n_global));
                    //escribe la linea en el fichero de texto
                    file_tabla->AddLine(str_linea);
                }
                //si n_local es mayor que uno debe escribir los labels en varias lineas
                else
                {
                    for (j=0; j<n_local; j++)
                    {
                        str_linea2 = str_linea + "." + labels.Item(n_global+j) + "    " + wxString::Format(wxT("%10.4f"), sqltabla.GetDouble(n_global+j));
                        //escribe la linea en el fichero de texto
                        file_tabla->AddLine(str_linea2);
                    }
                }
            }
            else
            {
                if(i<rows-1) str_linea = sqltabla.GetString(0) + ",";
                else str_linea = sqltabla.GetString(0);
                file_tabla->AddLine(str_linea);
            }
        }
        file_tabla->AddLine("/;");
        //salva y cierra el archivo de texto
        file_tabla->Write();
        file_tabla->Close();
    }
};

bool LambdaDatabase::CompareLabels(wxString lbl)
{
    bool exist = false; //por defecto el label no existe
    int i=0;
    while ((!exist) & (i<m_idxAll.GetCount()))
    {
        //compara si el label existe
        if ((lbl==m_idxAll.Item(i)) || (lbl==(m_idxAll.Item(i)+"2"))) exist = true;
        i++;
    }
    return exist;
};

void LambdaDatabase::CreateTables()
{
    int i,j;
    wxString sqlcom;
    wxSQLite3Transaction transaction(m_database);
    //Crea todas las tablas a partir del comando sql
    for(i=0; i<m_tables.GetCount(); i++)
    {
        m_database->ExecuteUpdate(m_sqlComands.Item(i));
    }
    //Para las tablas que no tienen indices las inicializa a cero si no tiene datos
    for (i=0; i<m_tables.GetCount(); i++)
    {
        if (m_numberidx.Item(i)==0)
        {
            //Numero de filas de la tabla
            sqlcom = "SELECT COUNT(*) FROM " + m_tables.Item(i);
            j = m_database->GetTable(sqlcom).ReturnDataInt(0, 0);
            //si el numero de filas es 0
            if (j==0)
            {
                sqlcom = "INSERT INTO " + m_tables.Item(i) + " (" + m_tables.Item(i) + ") VALUES (0);";
                m_database->ExecuteUpdate(sqlcom);
            }
        }
    }
    transaction.Commit();
    /*//Tamanos
    m_database->ExecuteUpdate("CREATE TABLE IF NOT EXISTS lambda_tam (\
                              var   STRING  PRIMARY KEY ASC ON CONFLICT ROLLBACK NOT NULL,\
                              valor INTEGER DEFAULT (0)  NOT NULL);");
    
    //Tabla con el nombre de las tablas
    m_database->ExecuteUpdate("CREATE TABLE IF NOT EXISTS lambda_tablas (\
                              Nombre STRING NOT NULL PRIMARY KEY);");
    m_database->ExecuteUpdate("DELETE FROM lambda_tablas");
    //Obtiene el nombre de todas las tablas
    m_database->ExecuteUpdate("INSERT INTO lambda_tablas SELECT name FROM sqlite_master\
                              WHERE type IN ('table','view') AND name NOT LIKE 'sqlite_%' AND name NOT LIKE 'lambda_%'\
                              UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table','view') ORDER BY 1");*/
};

void LambdaDatabase::NumberIdx()
{
    int i, n_idx;
    for (i=0; i<m_idx5.GetCount(); i++)
    {
        //numero de indices de la tabla
        if (!m_idx5.Item(i).IsEmpty()) n_idx=5;
        else if (!m_idx4.Item(i).IsEmpty()) n_idx=4;
        else if (!m_idx3.Item(i).IsEmpty()) n_idx=3;
        else if (!m_idx2.Item(i).IsEmpty()) n_idx=2;
        else if (!m_idx1.Item(i).IsEmpty()) n_idx=1;
        else n_idx=0;
        m_numberidx.Add(n_idx);
    }
};
#endif