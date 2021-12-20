//
//
//  window.h
//  lambda
//
//  Created by Andres Delgadillo on 12/09/15.
//
//

#ifndef lambda_window_h
#define lambda_window_h

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/aui/aui.h>
#include <wx/clipbrd.h>
#include <wx/dataview.h>
#include <wx/dir.h>
#include <wx/filepicker.h>
#include <wx/grid.h>
#include <wx/process.h>
#include <wx/notebook.h>
#include <wx/numformatter.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/txtstrm.h>

#include "constants.h"
#include "database.h"
#include "databaseInput.h"
#include "databaseOutput.h"
#include "dlg_preferences.h"
#include "dlg_execution.h"
#include "grid.h"

//#include "res/plus.png.h"
//#include "res/ok.png.h"

// Define class PipedProcess
class PipedProcess;
WX_DEFINE_ARRAY_PTR(PipedProcess *, PipedProcessesArray);

// Define class LambdaAuiDockArt
class LambdaAuiDockArt;

/************************************************************************/
/*						CLASS LambdaApp                                 */
/************************************************************************/

//! Define a new application type, each program should derive a class from wxApp
class LambdaApp : public wxApp
{
public:
    // override base class virtuals
    // ----------------------------
    
    /*! this one is called on application startup and is a good place for the app
    / initialization (doing it here and not in the ctor allows to have an error
    / return: if OnInit() returns false, the application terminates)*/
    virtual bool OnInit();
    wxString GetDirExe();
    wxString GetDirApp();
    wxString FindExePath();
    wxString FindAppPath();
    
private:
    wxString m_direxe;  //Path of the executable program
    wxString m_dirapp;  //Application folder
};

/************************************************************************/
/*						CLASS LambdaFrame                               */
/************************************************************************/

//! Define a new frame type: this is going to be our main frame
class LambdaFrame : public wxFrame
{
public:
    //! Constructor
    LambdaFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, wxString appPath = wxEmptyString ); //style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL  // wxSYSTEM_MENU|wxBORDER_NONE|wxTAB_TRAVERSAL,
    //! Virtual destructor
    virtual ~LambdaFrame();
    
    //return the GamsPath
    wxString GetGamsPath();
    //return the GamsPath
    wxString GetExePath();
    
    //TextInfo
    wxTextCtrl* m_textInfo;
    // for PipedProcess
    void AddPipedProcess(PipedProcess *process);
    void EventProcessTerminated(PipedProcess *process);
    void EventIdle(wxIdleEvent& event);
    // array of running processes with redirected IO
    PipedProcessesArray m_running;
    
protected:
    //!AUI
    //Aui manager
    wxAuiManager m_mgr;
    //Aui panes
    wxAuiPaneInfo pane1;
    wxAuiPaneInfo pane2;
    wxAuiPaneInfo pane3;
    //Aui dock art
    LambdaAuiDockArt* m_auiart;
    //wxAuiDefaultDockArt* m_auiart;
    
    //! Menu Bar
    wxMenuBar* m_menubar;
    //Menus
    wxMenu* m_menuFile;
    wxMenu* m_menuEdit;
    wxMenu* m_menuTools;
    wxMenu* m_menuHelp;
    //Tree of Variables
    wxTreeCtrl* m_ViewTreeVariables;
    //Data
    wxGrid* m_gridData;
    LambdaGridTable* m_gridTable;
    
    //Toolbar
    wxToolBar* m_toolBarGrid;
    wxToolBarToolBase* m_toolAdd;
    wxToolBarToolBase* m_toolOK;
    
    //Menu Events
    void EventNew( wxCommandEvent& event ) ;
    void EventOpen( wxCommandEvent& event ) ;
    void EventQuit( wxCommandEvent& event ) ;
    void EventCopy( wxCommandEvent& event ) ;
    void EventPaste( wxCommandEvent& event ) ;
    void EventAbout( wxCommandEvent& event ) ;
    void EventPreferences( wxCommandEvent& event ) ;
    void EventExecute( wxCommandEvent& event ) ;
    void EventSort( wxCommandEvent& event ) ;
    //Tree Variable Events
    void EventVarActivated( wxDataViewEvent& event ) ;
    //Grid Events
    void EventCellChange( wxGridEvent& event ) ;
    void EventLabelDClick( wxGridEvent& event ) ;
    void EventCellRightClick( wxGridEvent& event );
    //Toolbar Events
    void EventAddTool( wxCommandEvent& event ) ;
    void EventOkTool( wxCommandEvent& event ) ;
    
    //Base de datos
    LambdaDatabaseInput* m_databaseInput;
    LambdaDatabaseOutput* m_databaseOutput;
    //Create the root nodes of the tree
    void CreateRootNodes();
    //Create the list of the treecontrol
    void CreateTreeInput();
    //Create the list of the treecontrol
    void CreateTreeOutput();
    //Read the table
    void ReadTable();
    //Copy the gams files in the execution folder
    void CopyGamsFiles();
    //Remove files from the Datos folder
    bool EmptyDatosFolder();
    //Create the Option File
    void CreateOpt(wxArrayInt* opt);
  
private:
    //Set the Language Menu
    void LanguageMenu();
    //Modify the labels of the grid
    void UpdateLabelsGrid(int mas);
    //The Value of the cell changed
    void CellChange(int row, int col, wxString newValue);
    //Sort the tables
    void SortTables();
    //Pane Info
    void SetPanes();
    
    //Gams path
    wxString s_GamsPath;
    //Execution path
    wxString s_ExePath;
    //App path
    wxString s_AppPath;
    
    //Position of last table selected
    int m_lastposInput;
    int m_lastposOutput;
    bool m_Input;

    //Containers of the tree control
    wxTreeItemId tree_input;
    wxTreeItemId tree_output;
    
    //Clipboard
    wxClipboard* m_clipboard;
};

/************************************************************************/
/*						CLASS PipedProcess                              */
/************************************************************************/

// A specialization of wxProcess for redirecting the output
class PipedProcess : public wxProcess
{
public:
    PipedProcess(LambdaFrame *parent);
    void OnTerminate(int pid, int status);
    bool HasOutput();
    
protected:
    LambdaFrame *m_parent;
};

/************************************************************************/
/*						CLASS LambdaAuiDockArt				     		*/
/************************************************************************/

class LambdaAuiDockArt : public wxAuiDefaultDockArt
{
public:
    LambdaAuiDockArt()
    {
        SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, wxColour(58,85,159));
        SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, wxColour(58,85,159));
        SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR, wxColour(255,255,255));
        SetMetric(wxAUI_DOCKART_SASH_SIZE, 4);
		//SetColour(wxAUI_DOCKART_SASH_COLOUR, wxColour(36, 48, 110));
    };
#ifndef __WXMSW__
    void DrawSash(wxDC& dc, wxWindow *window, int orientation, const wxRect& rect) {};
#endif
};

/************************************************************************/
/*            Event tables and other macros for wxWidgets               */
/************************************************************************/

/*! Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp) */
IMPLEMENT_APP(LambdaApp)

#endif

