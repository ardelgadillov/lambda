//
//  dlg_preferences.cpp
//  lambda
//
//  Created by Andres Delgadillo on 10/24/15.
//
//

#ifndef dlg_preferences_cpp
#define dlg_preferences_cpp

#include "dlg_preferences.h"
#include "constants.h"

/************************************************************************/
/*						Dialog Preferences                              */
/************************************************************************/

//Creates the preferences dialog
Dialog_Preferences::Dialog_Preferences( wxWindow* parent, wxString GamsPath, wxString ExePath, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog( parent, id, title, pos, size, style )
{
    //Se pasa el padre de la ventana
    m_parent = parent;
    //Se escoge el lenguaje
    SetLanguage();
    
    SetSizeHints( wxDefaultSize, wxDefaultSize );
    
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );
    
    m_notebookPreferences = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
    m_panelGeneral = new wxPanel( m_notebookPreferences, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxFlexGridSizer* fgSizer1;
    fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    m_stGamsPath = new wxStaticText( m_panelGeneral, wxID_ANY, LabelGamsPath, wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_dirGamsPath = new wxDirPickerCtrl( m_panelGeneral, wxID_ANY, GamsPath, wxT("Select a folder"), wxDefaultPosition, wxSize( 420,-1 ), wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_SMALL|wxDIRP_USE_TEXTCTRL );
    fgSizer1->Add( m_stGamsPath, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_dirGamsPath, 0, wxALIGN_LEFT|wxALL, 8 );
    
    m_stExePath = new wxStaticText( m_panelGeneral, wxID_ANY, LabelExePath, wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_dirExePath = new wxDirPickerCtrl( m_panelGeneral, wxID_ANY, ExePath, wxT("Select a folder"), wxDefaultPosition, wxSize( 420,-1 ), wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_SMALL|wxDIRP_USE_TEXTCTRL );
    fgSizer1->Add( m_stExePath, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_dirExePath, 0, wxALIGN_LEFT|wxALL, 8 );
    
    m_panelGeneral->SetSizer( fgSizer1 );
    m_panelGeneral->Layout();
    fgSizer1->Fit( m_panelGeneral );
    m_notebookPreferences->AddPage( m_panelGeneral, wxT("General"), false );
    
    bSizer1->Add( m_notebookPreferences, 1, wxEXPAND, 0 );
    
    
    this->SetSizer( bSizer1 );
    this->Layout();
    
    this->Centre( wxBOTH );
}

//Destructor
Dialog_Preferences::~Dialog_Preferences()
{
}

//Save the Language of the labels
void Dialog_Preferences::SetLanguage()
{
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
            LabelGamsPath = "Ruta de Gams";
            LabelExePath = "Ruta de Ejecución";
            break;
            
        default:
            LabelGamsPath = "Gams Path";
            LabelExePath = "Execution Path";
            break;
    }
}

#endif
