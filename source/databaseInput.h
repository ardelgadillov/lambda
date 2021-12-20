//
//  databaseInput.hpp
//  lambda
//
//  Created by Andres Delgadillo on 10/27/15.
//
//

#ifndef databaseInput_hpp
#define databaseInput_hpp

#include "database.h"

//Clase derivada para la base de datos de entrada
class LambdaDatabaseInput : public LambdaDatabase
{
public:
    LambdaDatabaseInput(wxString file);
    ~LambdaDatabaseInput();
    void InfoTables();
    void InfoCols();
};

#endif /* databaseInput_hpp */
