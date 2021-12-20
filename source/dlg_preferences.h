//
//  dlg_preferences.hpp
//  lambda
//
//  Created by Andres Delgadillo on 10/24/15.
//
//

#ifndef dlg_preferences_h
#define dlg_preferences_h

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/dir.h>
#include <wx/filepicker.h>
#include <wx/notebook.h>

/************************************************************************/
/*						CLASS Dialog_Preferences                        */
/************************************************************************/
class Dialog_Preferences : public wxDialog
{
public:
    
//    Dialog_Preferences( LambdaFrame* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,300 ), long style = wxDEFAULT_DIALOG_STYLE|wxNO_BORDER );
    Dialog_Preferences( wxWindow* parent = NULL, wxString GamsPath = wxEmptyString, wxString ExePath = wxEmptyString, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,300 ), long style = wxDEFAULT_DIALOG_STYLE|wxNO_BORDER);
    ~Dialog_Preferences();
    //Gams Path
    wxDirPickerCtrl* m_dirGamsPath;
    //Execution Path
    wxDirPickerCtrl* m_dirExePath;
    
protected:
    wxNotebook* m_notebookPreferences;
    wxPanel* m_panelGeneral;
    wxStaticText* m_stGamsPath;
    wxStaticText* m_stExePath;
    
    void SetLanguage();
    
private:
    wxString LabelGamsPath;
    wxString LabelExePath;
    //LambdaFrame *m_parent;
};

#endif /* dlg_preferences_hpp */
