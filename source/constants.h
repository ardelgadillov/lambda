//
//  constants.h
//  lambda
//
//  Created by Andres Delgadillo on 17/09/15.
//
//

#ifndef lambda_constants_h
#define lambda_constants_h

/************************************************************************/
/*                    Constants                                         */
/************************************************************************/

//! IDs of the languages
enum Languages
{
    ID_ENGLISH = 1,
    ID_SPANISH
};

enum type_tables
{
    ID_TIME = 0,
    ID_COMPANIES,
    ID_THERMAL,
    ID_HYDRO,
    ID_MARGINALIST,
    ID_DEMAND,
    ID_SYSTEM
};

enum type_horizon
{
    ID_GENERAL = 0,
    ID_PE,
    ID_PE_ST
};

enum type_idx
{
    ID_NO_IDX = 0,
    ID_IDX
};


const int LAMBDA_LANGUAGE(ID_ENGLISH);

#endif
