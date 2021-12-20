//
//  databaseOutput.hpp
//  lambda
//
//  Created by Andres Delgadillo on 10/27/15.
//
//

#ifndef databaseOutput_hpp
#define databaseOutput_hpp

#include "database.h"

//Clase derivada para la base de datos de salida
class LambdaDatabaseOutput : public LambdaDatabase
{
public:
    LambdaDatabaseOutput(wxString file);
    ~LambdaDatabaseOutput();
    void InfoTables();
    void InfoCols();
    wxArrayInt m_horizonte;
};

#endif /* databaseOutput_hpp */
