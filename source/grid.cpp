//
//  grid.cpp
//  lambda
//
//  Created by Andres Delgadillo on 10/23/15.
//
//

#ifndef lambda_grid_cpp
#define lambda_grid_cpp

#include "grid.h"

/************************************************************************/
/*						LambdaGridCellAttr Implementation               */
/************************************************************************/

LambdaGridCellAttr::LambdaGridCellAttr()
{
    //Change the colors of the odd rows
    m_attrForOddRows = new wxGridCellAttr;
    m_attrForOddRows->SetBackgroundColour(wxColour(240, 240, 240));
    m_attrForOddRows->SetAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
}

LambdaGridCellAttr::~LambdaGridCellAttr()
{
    m_attrForOddRows->DecRef();
}

wxGridCellAttr *LambdaGridCellAttr::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind  kind) const
{
    //Return the attribute of the cell
    wxGridCellAttr *attr = wxGridCellAttrProvider::GetAttr(row, col, kind);
    
    //If the row is odd
    if ( row % 2 )
    {
        //If the row doesn't have attribute, it creates a new one
        if ( !attr )
        {
            attr = m_attrForOddRows;
            attr->IncRef();
        }
        else
        {
            //if the row has attribute but it doesn't have background color create a new attribute for the cell
            if ( !attr->HasBackgroundColour() )
            {
                wxGridCellAttr *attrNew = attr->Clone();
                attr->DecRef();
                attr = attrNew;
                attr->SetBackgroundColour(wxColour(240, 240, 240));
                attr->SetAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
            }
        }
    }
    return attr;
}

/************************************************************************/
/*						LambdaGridTable Implementation                  */
/************************************************************************/

LambdaGridTable::LambdaGridTable()
{
    //Initialize the rows and cols
    m_rows = 0;
    m_cols = 0;
}

LambdaGridTable::~LambdaGridTable()
{
}

int LambdaGridTable::GetNumberRows()
{
    return m_rows;
}

int LambdaGridTable::GetNumberCols()
{
    return m_cols;
}

bool LambdaGridTable::DeleteRows(size_t pos, size_t numRows)
{
    //Decrease the number of rows
    m_rows -= numRows;
    //Inform to the grid that the rows were deleted
    wxGridTableMessage msg( this,wxGRIDTABLE_NOTIFY_ROWS_DELETED,pos,numRows);
    return GetView()->ProcessTableMessage( msg );
}

bool LambdaGridTable::DeleteCols(size_t pos, size_t numCols)
{
    //Decrease the number of cols and remove them from the data arrays
    m_cols -= numCols;
    m_labelCol.RemoveAt(0,numCols);
    m_labelCol.Shrink();
    //Inform to the grid that the cols were deleted
    wxGridTableMessage msg( this,wxGRIDTABLE_NOTIFY_COLS_DELETED,pos,numCols);
    return GetView()->ProcessTableMessage( msg );
}

bool LambdaGridTable::AppendRows(size_t numRows)
{
    //Increase the number of rows and add the to the data arrays
    m_rows += numRows;
    //Inform to the grid that the rows were added
    wxGridTableMessage msg( this,wxGRIDTABLE_NOTIFY_ROWS_APPENDED,numRows);
    return GetView()->ProcessTableMessage( msg );
}

bool LambdaGridTable::AppendCols(size_t numCols)
{
    //Increase the number of cols and add the to the data arrays
    m_cols += numCols;
    m_labelCol.Add(wxEmptyString,numCols);
    //Inform to the grid that the cols were added
    wxGridTableMessage msg( this,wxGRIDTABLE_NOTIFY_COLS_APPENDED,numCols);
    return GetView()->ProcessTableMessage( msg );
}

wxString LambdaGridTable::GetValue(int row, int col)
{
    wxString output = wxEmptyString;
    //return the value of the cell
    if ((row+1)*(col+1)<=m_data.GetCount()) output = m_data.Item(col + row*m_cols);
    return output;
}

wxString LambdaGridTable::GetRowLabelValue(int row)
{
    //return the label of the row
    wxString output = wxString::Format(wxT("%i"),row+1);
    if ((row==m_rows-1) && (m_cols==1)) output="+";
    return output;
}

wxString LambdaGridTable::GetColLabelValue(int col)
{
    //return the label of the col
    return m_labelCol.Item(col);
}

void LambdaGridTable::SetValue(int row, int col, const wxString& value)
{
    //Set the value of the cell
    if ((row+1)*(col+1)<=m_data.GetCount())
        m_data.Item(col+row*m_cols) = value;
    else
        m_data.Add(value);
}

void LambdaGridTable::SetRowLabelValue(int row, const wxString &label)
{
}

void LambdaGridTable::SetColLabelValue(int col, const wxString &label)
{
    //Set the label of the row
    m_labelCol.Item(col) = label;
}

void LambdaGridTable::SetData(wxSQLite3Table* table)
{
    int rows = table->GetRowCount();
    int cols = table->GetColumnCount();
    m_data.Clear();
    m_data.Alloc(rows*cols);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            m_data.Add(table->ReturnDataString(i, j));
        }
    }
    //Inform to the grid that the cols were added
    wxGridTableMessage msg( this,wxGRIDTABLE_REQUEST_VIEW_GET_VALUES);
    GetView()->ProcessTableMessage( msg );
}

#endif

