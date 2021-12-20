//
//  dlg_execution.hpp
//  lambda
//
//  Created by Andres Delgadillo on 10/24/15.
//
//

#ifndef dlg_execution_h
#define dlg_execution_h

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/notebook.h>

/************************************************************************/
/*						CLASS Dialog_Execution                          */
/************************************************************************/
class Dialog_Execution : public wxDialog
{
public:
    
    Dialog_Execution( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 380,330 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~Dialog_Execution();
    
    wxComboBox* m_cBoxEquilibrio;
    wxComboBox* m_cBoxDemand;
    wxComboBox* m_cBoxVariables;
    wxComboBox* m_cBoxNetwork;
    
protected:
    wxNotebook* m_notebookExecution;
    wxPanel* m_panelGeneral;
    wxStaticText* m_stEquilibrio;
    wxStaticText* m_stDemand;
    wxStaticText* m_stVariables;
    wxStaticText* m_stNetwork;
    wxButton* m_OK;
    
    void SetLanguage();
    
    // Virtual event handlers, overide them in your derived class
    void EventClose( wxCloseEvent& event );
    
private:
    wxArrayString LabelEquilibrio;
    wxArrayString LabelDemand;
    wxArrayString LabelVariables;
    wxArrayString LabelNetwork;
    wxArrayString LabelcBox;
};

#endif /* dlg_execution_hpp */
