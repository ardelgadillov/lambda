//
//  grid.hpp
//  lambda
//
//  Created by Andres Delgadillo on 10/23/15.
//
//

#ifndef lambda_grid_h
#define lambda_grid_h

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/grid.h>
#include <wx/numformatter.h>

#include "wxsqlite3.h"

/************************************************************************/
/*						CLASS LambdaGridCellAttr                        */
/************************************************************************/

//Sets the attributes of the cells
class LambdaGridCellAttr : public wxGridCellAttrProvider
{
public:
    LambdaGridCellAttr();
    virtual ~LambdaGridCellAttr();
    //Return the attribute of the cell
    wxGridCellAttr *GetAttr(int row, int col, wxGridCellAttr::wxAttrKind  kind) const;
    
private:
    wxGridCellAttr *m_attrForOddRows;
};

/************************************************************************/
/*						CLASS LambdaGridTable                           */
/************************************************************************/

 // A specialization of wxGridTableBase to show big tables
class LambdaGridTable : public wxGridTableBase
{
public:
    LambdaGridTable();
    virtual ~LambdaGridTable();
    
    //Return the number of rows and cols
    int GetNumberRows();
    int GetNumberCols();
    //Delete rows and cols
    bool DeleteRows(size_t pos=0, size_t numRows=1);
    bool DeleteCols(size_t pos=0, size_t numCols=1);
    //Append new rows and cols
    bool AppendRows(size_t numRows=1);
    bool AppendCols(size_t numCols=1);
    
    //Get the value in the cells and labels
    wxString GetValue(int row, int col);
    wxString GetRowLabelValue(int row);
    wxString GetColLabelValue(int col);
    
    //Set the value of the cells and labels
    void SetValue(int row, int col, const wxString& value);
    void SetRowLabelValue(int row, const wxString &label);
    void SetColLabelValue(int col, const wxString &label);
    
    //Set data
    void SetData(wxSQLite3Table* table);
    
private:
    //Number of rows and cols
    int m_rows;
    int m_cols;
    //Arrays with the information of the table
    wxArrayString m_data;
    //wxArrayString m_labelRow;
    wxArrayString m_labelCol;
};

#endif
