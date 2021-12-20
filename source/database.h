//
//  LambdaDatabase.h
//  lambda
//
//  Created by Andres Delgadillo on 15/09/15.
//
//


#ifndef lambda_database_h
#define lambda_database_h

#include <wx/treectrl.h>
#include <wx/textfile.h>

#include "constants.h"
#include "wxsqlite3.h"

/************************************************************************/
/*						CLASS LambdaDatatables                                */
/************************************************************************/

//! Define the data of each table
class LambdaDatatables : public wxTreeItemData
{
public:
    LambdaDatatables(int pos, bool input);
    ~LambdaDatatables();
    
    //Set the position
    void SetPos(int pos);
    //Get the position
    int GetPos();
    //says if the data is input or output, true - input, false - output
    bool IsInput();
    
private:
    //Position of the table
    int m_pos;
    //Input or Outut table
    bool m_input;
};

/************************************************************************/
/*						CLASS LambdaDatabase                                  */
/************************************************************************/
//! Define a new application type, each program should derive a class from wxApp
class LambdaDatabase
{
public:
    //Constructor
    //m_Frame es el puntero a la ventana que contiene la información de lenguaje, y controles
    LambdaDatabase(wxString file);
    virtual ~LambdaDatabase();
    
    wxSQLite3Database* m_database;
    
    //Array with the tables names
    wxArrayString m_tables;
    //Tipo de la tabla
    wxArrayInt m_tipo;
    //Indica si la tabla es de indices
    /*
     0 - No es indice
     1 - es indice
    */
    wxArrayInt m_tidx;
    //Indica el numero de indices de la tabla
    wxArrayInt m_numberidx;
    
    //Indices de cada tabla
    wxArrayString m_idx1;
    wxArrayString m_idx2;
    wxArrayString m_idx3;
    wxArrayString m_idx4;
    wxArrayString m_idx5;
    
    //Indices de todas las tablas
    wxArrayString m_idxAll;
    
    //Nombre de la columna en las tablas de sql
    wxArrayString m_col_name;
    //Label de la columna en el grid
    wxArrayString m_col_label;
    
    //labels in the tree control
    wxArrayString m_tablesTreeLabels;
    
    //Update the indeces on the tables
    void UpdateTables(wxString new_idx, wxString tipo);
    //Inserta los value en las columnas lb de la tabla
    void SqlInsert(wxString table, wxString lb1, wxString value1);
    void SqlInsert(wxString table, wxString lb1, wxString lb2, wxString value1, wxString value2);
    void SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString value1, wxString value2, wxString value3);
    void SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString lb4, wxString value1, wxString value2, wxString value3, wxString value4);
    void SqlInsert(wxString table, wxString lb1, wxString lb2, wxString lb3, wxString lb4, wxString lb5, wxString value1, wxString value2, wxString value3, wxString value4, wxString value5);
    //Devuelve la tabla
    wxSQLite3Table SqlGet(wxString table);
    //Devuelve los labels de la tabla y retorna el tamanio
    int SqlLabels(wxString table, wxArrayString *labels);
    //Ordena toda la tabla
    void SqlSort(wxString table);
    //Guarda la tabla en un fichero de texto
    /*
     dir es la direccion donde se guarda
     tipo
        0   tabla normal
        1   tabla de indices
     */
    void SqlSave(wxString table, wxString dir, int tipo=0);
    //Open the LambdaDatabase
    void Opendb(bool create);
    //Find the column name and return the label
    wxString Label(wxString col);
    //Create the Info of each table
    virtual void InfoTables() {};
    //Create the Info of each colum
    virtual void InfoCols() {};
protected:
    //Compare the labels of the table with all the labels
    /*
     false - No es global
     true - es global
     */
    bool CompareLabels(wxString lbl);
    //Create the tables in the LambdaDatabase
    void CreateTables();
    //Determine the number of indices of the tables
    void NumberIdx();
    //File with the LambdaDatabase
    wxString m_file;
    //Sqlite comands to create the tables
    wxArrayString m_sqlComands;
};

#endif
