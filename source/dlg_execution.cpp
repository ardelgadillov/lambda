//
//  dlg_execution.cpp
//  lambda
//
//  Created by Andres Delgadillo on 10/24/15.
//
//

#ifndef dlg_execution_cpp
#define dlg_execution_cpp

#include "dlg_execution.h"
#include "constants.h"

/************************************************************************/
/*						Dialog Execution                                */
/************************************************************************/

//Creates the execution dialog
Dialog_Execution::Dialog_Execution( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    int i;
    //Se escoge el lenguaje
    SetLanguage();
    
    SetSizeHints( wxDefaultSize, wxDefaultSize );
    //SetBackgroundColour( wxColour( 255, 127, 0 ) );
    
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );
    
    m_notebookExecution = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
    //m_notebookExecution->SetBackgroundColour( wxColour( 255, 127, 0 ) );
    
    m_panelGeneral = new wxPanel( m_notebookExecution, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    //m_panelGeneral->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
    
    wxFlexGridSizer* fgSizer1;
    fgSizer1 = new wxFlexGridSizer( 5, 2, 0, 0 );
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    //Equilibrium option
    m_stEquilibrio = new wxStaticText( m_panelGeneral, wxID_ANY, LabelcBox.Item(1), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_cBoxEquilibrio = new wxComboBox( m_panelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, wxCB_READONLY );
    for (i=0; i<LabelEquilibrio.GetCount(); i++)
        m_cBoxEquilibrio->Append(LabelEquilibrio.Item(i));
    m_cBoxEquilibrio->SetSelection( 0 );
    fgSizer1->Add( m_stEquilibrio, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_cBoxEquilibrio, 0, wxALL, 10 );
    
    //Demand option
    m_stDemand = new wxStaticText( m_panelGeneral, wxID_ANY, LabelcBox.Item(2), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_cBoxDemand = new wxComboBox( m_panelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, wxCB_READONLY );
    for (i=0; i<LabelDemand.GetCount(); i++)
        m_cBoxDemand->Append(LabelDemand.Item(i));
    m_cBoxDemand->SetSelection( 0 );
    fgSizer1->Add( m_stDemand, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_cBoxDemand, 0, wxALL, 10 );
    
    //Type of variables option
    m_stVariables = new wxStaticText( m_panelGeneral, wxID_ANY, LabelcBox.Item(3), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_cBoxVariables = new wxComboBox( m_panelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, wxCB_READONLY );
    for (i=0; i<LabelVariables.GetCount(); i++)
        m_cBoxVariables->Append(LabelVariables.Item(i));
    m_cBoxVariables->SetSelection( 0 );
    fgSizer1->Add( m_stVariables, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_cBoxVariables, 0, wxALL, 10 );
    
    //Network option
    m_stNetwork = new wxStaticText( m_panelGeneral, wxID_ANY, LabelcBox.Item(4), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    m_cBoxNetwork = new wxComboBox( m_panelGeneral, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0, NULL, wxCB_READONLY );
    for (i=0; i<LabelNetwork.GetCount(); i++)
        m_cBoxNetwork->Append(LabelNetwork.Item(i));
    m_cBoxNetwork->SetSelection( 0 );
    fgSizer1->Add( m_stNetwork, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 15 );
    fgSizer1->Add( m_cBoxNetwork, 0, wxALL, 10 );
    
    //Ok button
    m_OK = new wxButton( m_panelGeneral, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
    fgSizer1->Add( m_OK, 0, wxALL, 20 );
    
    m_panelGeneral->SetSizer( fgSizer1 );
    m_panelGeneral->Layout();
    fgSizer1->Fit( m_panelGeneral );
    m_notebookExecution->AddPage( m_panelGeneral, LabelcBox.Item(0), false );
    
    bSizer1->Add( m_notebookExecution, 1, wxEXPAND, 0 );
    
    this->SetSizer( bSizer1 );
    this->Layout();
    
    this->Centre( wxBOTH );
    
    // Connect Events
    Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Dialog_Execution::EventClose ) );
    
}

//Destructor
Dialog_Execution::~Dialog_Execution()
{
    // Disconnect Events
    Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Dialog_Execution::EventClose ) );
}

//Set the language of the labels
void Dialog_Execution::SetLanguage()
{
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
            LabelEquilibrio.Add("Competencia perfecta");
            LabelEquilibrio.Add("Variación conjetural");
            
            LabelDemand.Add("Demanda inelástica");
            LabelDemand.Add("Demanda elástica");
            
            LabelVariables.Add("Variables relajadas");
            LabelVariables.Add("Variables enteras");
            
            LabelNetwork.Add("Sin red");
            LabelNetwork.Add("Con red");
            
            LabelcBox.Add("Opciones de ejecución");
            LabelcBox.Add("Equilibrio");
            LabelcBox.Add("Demanda");
            LabelcBox.Add("Variables");
            LabelcBox.Add("Red");
            break;
            
        case ID_ENGLISH:
            LabelEquilibrio.Add("Perfect competition");
            LabelEquilibrio.Add("Conjectural variation");
            
            LabelDemand.Add("Inelastic demand");
            LabelDemand.Add("Elastic demand");
            
            LabelVariables.Add("Relaxed variables");
            LabelVariables.Add("Integer variables");
            
            LabelNetwork.Add("Without network");
            LabelNetwork.Add("With network");
            
            LabelcBox.Add("Execution options");
            LabelcBox.Add("Equilibrium");
            LabelcBox.Add("Demand");
            LabelcBox.Add("Variables");
            LabelcBox.Add("Network");
            break;
    }
}

//When the dialog is canceled
void Dialog_Execution::EventClose(wxCloseEvent &event)
{
    wxDialog::EndModal(wxID_CANCEL);
}


#endif
