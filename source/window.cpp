//
//
//  window.cpp
//  lambda
//
//  Created by Andres Delgadillo on 12/09/15.
//
//

#ifndef lambda_window_cpp
#define lambda_window_cpp

#include "window.h"

/************************************************************************/
/*						LambdaApp Implementation						*/
/************************************************************************/

//! 'Main program' equivalent: the program execution "starts" here
bool LambdaApp::OnInit()
{
    //Format numbers and dates
    //SetCLocale();
    wxLocale locale;
    locale.Init();
    //wxString a = locale.GetInfo(wxLOCALE_THOUSANDS_SEP);

    // call the base class initialization method
    if ( !wxApp::OnInit() )
        return false;
    
    //Find the absolute path of the app is running
    m_direxe = FindExePath();
    m_dirapp = FindAppPath();
    
    wxInitAllImageHandlers();
    
    // create the main application window
    LambdaFrame *p_frame = new LambdaFrame(NULL, wxID_ANY, "Lambda", wxDefaultPosition, wxSize(1280,710), wxDEFAULT_FRAME_STYLE, m_dirapp);
    SetTopWindow(p_frame);
    // and show it (the frames, unlike simple controls, are not shown when created initially)
    p_frame->Show(true);
    
    // success: wxApp::OnRun() will be called which will enter the main message
    // loop and the application will run. If we returned false here, the
    // application would exit immediately.
    return true;
}

//! Find the absolute path where this application has been run from
wxString LambdaApp::FindExePath()
{
    wxString str;
    wxString cwd = wxGetCwd();
    wxString argv0 = this->argv[0];
    
    if (wxIsAbsolutePath(argv0))
        return wxPathOnly(argv0);
    else
    {
        // Is it a relative path?
        if (cwd.Last() != wxFILE_SEP_PATH)
            cwd += wxFILE_SEP_PATH;
        
        str = cwd + argv0;
        if (wxFileExists(str))
            return wxPathOnly(str);
    }
    
    // OK, it's neither an absolute path nor a relative path.
    // Search PATH.
    wxPathList pathList;
    pathList.AddEnvList(wxT("PATH"));
    str = pathList.FindAbsoluteValidPath(argv0);
    if (!str.IsEmpty())
        return wxPathOnly(str);
    
    // Failed
    return wxEmptyString;
}

//Determine the path of the app
wxString LambdaApp::FindAppPath()
{
    wxString cwd = wxGetCwd();
    
#if defined(__WXMAC__)
    // On Mac, the current directory is the relevant one when
    // the application starts.
    cwd += "/Lambda.app/Contents";
#endif
    return cwd;
}

//Return the execution path
wxString LambdaApp::GetDirExe()
{
    return m_direxe;
}

//Return the application path
wxString LambdaApp::GetDirApp()
{
    return m_dirapp;
}

/************************************************************************/
/*						PipedProcess Implementation						*/
/************************************************************************/

//Constructor, it activates redirect
PipedProcess::PipedProcess(LambdaFrame *parent): wxProcess(parent)
{
    m_parent = parent;
    Redirect();
}

//It is activated when the process ends
void PipedProcess::OnTerminate(int pid, int status)
{
    // show the rest of the output
    while ( HasOutput() );
    m_parent->EventProcessTerminated(this);
}

//Save the output of the process in the text control
bool PipedProcess::HasOutput()
{
    bool hasout = false;
    
    if ( IsInputAvailable() )
    {
        wxTextInputStream tis(*GetInputStream());
        m_parent->m_textInfo->AppendText(tis.ReadLine() + wxT("\n"));
        hasout = true;
    }
    if ( IsErrorAvailable() )
    {
        wxTextInputStream tis(*GetErrorStream());
        m_parent->m_textInfo->AppendText(wxT(" (stderr): ") + tis.ReadLine() + wxT("\n"));
        hasout = true;
    }
    return hasout;
}

/************************************************************************/
/*						LambdaFrame Implementation						*/
/************************************************************************/

//! frame constructor
LambdaFrame::LambdaFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, wxString appPath) : wxFrame( parent, id, title, pos, size, style )
{
    //Background Color
    SetBackgroundColour(wxColour(36,48,110));
    
#if defined(__WXMSW__)
    // set frame icon
	//wxBitmap lambda_bmp = wxBITMAP_PNG(LAMBDA);
	//wxIcon lambda_icon;
	//lambda_icon.CopyFromBitmap(lambda_bmp);
	wxIcon lambda_icon(wxICON(LAMBDA_ICON));
	SetIcon(lambda_icon);
#endif
    
    // notify wxAUI which frame to use
    m_mgr.SetManagedWindow(this);
    m_auiart = new LambdaAuiDockArt();
    m_mgr.SetArtProvider(m_auiart);
    
    //Paths
    s_GamsPath = wxEmptyString; //Gams and Exe paths are set in the preference dialog
    s_ExePath = wxEmptyString;
    s_AppPath = appPath;
    
    //Set Default size
    SetSizeHints( wxDefaultSize, wxDefaultSize );
    
    //Menu Bar
    m_menubar = new wxMenuBar();
    //Menus
    m_menuFile = new wxMenu();
    m_menuEdit = new wxMenu();
    m_menuTools = new wxMenu();
    m_menuHelp = new wxMenu();
	//Menu Items
	m_menuFile->Append(wxID_NEW);
	m_menuFile->Append(wxID_OPEN);
	m_menuFile->Append(wxID_EXIT);
	m_menuEdit->Append(wxID_COPY);
	m_menuEdit->Append(wxID_PASTE);
	m_menuEdit->Append(wxID_PREFERENCES);
	m_menuTools->Append(wxID_EXECUTE);
	m_menuTools->Append(wxID_SORT_ASCENDING);
	m_menuHelp->Append(wxID_ABOUT);

	//Append the Menu on the Menu Bar
    m_menubar->Append( m_menuFile, wxT("File") );
    m_menubar->Append( m_menuEdit, wxT("Edit") );
    m_menubar->Append( m_menuTools, wxT("Tools") );
    m_menubar->Append( m_menuHelp, wxT("Help") );
    
    //Set the Menu Bar
    SetMenuBar(m_menubar);
    
	//Set the Language of the Menu
	LanguageMenu();
    
    //Tree Control for the Variables
    m_ViewTreeVariables = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT );
    //m_ViewTreeVariables->SetBackgroundColour(wxColour(240, 240, 240));
    CreateRootNodes();
        
    //Grid and Table for the data
    m_gridData = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxVSCROLL );
    /*m_gridData->CreateGrid( 1, 1 );
    wxGridTableBase *table = m_gridData->GetTable();
    table->SetAttrProvider(new LambdaGridCellAttr);*/
    m_gridTable = new LambdaGridTable();
    m_gridTable->SetAttrProvider(new LambdaGridCellAttr);
    m_gridData->SetTable(m_gridTable,true);
    
    //m_gridData->EnableEditing( true );
    m_gridData->EnableGridLines( true );
    m_gridData->EnableDragGridSize( false );
    m_gridData->SetMargins(0,0);
    // Columns
    m_gridData->EnableDragColMove( false );
    m_gridData->EnableDragColSize( true );
    m_gridData->SetColLabelSize(60);
    m_gridData->SetDefaultColSize(150);
    m_gridData->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    // Rows
    m_gridData->EnableDragRowSize( true );
    m_gridData->SetRowLabelSize(80);
    m_gridData->SetDefaultRowSize(25);
    m_gridData->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    // Label Appearance
    // Cell Defaults
    m_gridData->SetDefaultRenderer(new wxGridCellFloatRenderer(-1,2));
    m_gridData->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
    //m_gridData->Hide();
    
    //Toolbar
    /*m_toolBarGrid = new wxToolBar( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL );
    m_toolAdd = m_toolBarGrid->AddTool( wxID_ANY, wxT("tool"), plus_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );
    m_toolOK = m_toolBarGrid->AddTool( wxID_ANY, wxT("tool"), ok_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );
    m_toolBarGrid->Realize();*/
    
    //TextInfoControl
    m_textInfo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxALWAYS_SHOW_SB); //|wxNO_BORDER );
    
    // add the panes to the manager
    SetPanes();
    m_mgr.AddPane(m_ViewTreeVariables, pane1);
    m_mgr.AddPane(m_gridData, pane2);
    m_mgr.AddPane(m_textInfo, pane3);
    // tell the manager to "commit" all the changes just made
    m_mgr.Update();
    
    //Center the window
    Centre( wxBOTH );
    Maximize();
    
    //Initialize the clipboard
    m_clipboard = new wxClipboard();
    
    //Initialize the databases
    m_databaseInput = NULL;
    m_databaseOutput = NULL;
    
    // Connect Events
    //Frame
    Connect(wxEVT_IDLE, wxIdleEventHandler( LambdaFrame::EventIdle ) );
    //Menu
    Connect(wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(  LambdaFrame::EventNew ));
	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventOpen ));
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventQuit ));
	Connect(wxID_COPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventCopy ));
	Connect(wxID_PASTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventPaste ));
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventAbout ));
	Connect(wxID_PREFERENCES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventPreferences ));
	Connect(wxID_EXECUTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventExecute ));
	Connect(wxID_SORT_ASCENDING, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventSort ));
    //Tree
	Connect(wxID_ANY, wxEVT_TREE_ITEM_ACTIVATED, wxDataViewEventHandler( LambdaFrame::EventVarActivated ) );
    //Toolbar
    //Connect(m_toolAdd->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( LambdaFrame::EventAddTool ) );
    //Connect(m_toolOK->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( LambdaFrame::EventOkTool ) );
    //Grid
    m_gridData->Connect(wxEVT_GRID_CELL_CHANGING, wxGridEventHandler( LambdaFrame::EventCellChange ), NULL, this );
    //wxEVT_GRID_CELL_CHANGE
    m_gridData->Connect(wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LambdaFrame::EventLabelDClick ), NULL, this );
    m_gridData->Connect(wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( LambdaFrame::EventCellRightClick ), NULL, this );
}


//!frame destructor
LambdaFrame::~LambdaFrame()
{
    // Disconnect Events
    //Frame
    Disconnect( wxEVT_IDLE, wxIdleEventHandler( LambdaFrame::EventIdle ) );
    //Menu
    Disconnect( wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventNew ) );
    Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventOpen ) );
    Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventQuit ) );
    Disconnect( wxID_COPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventCopy ) );
    Disconnect( wxID_PASTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventPaste ) );
    Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventAbout ) );
    Disconnect( wxID_PREFERENCES, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventPreferences ) );
    Disconnect( wxID_EXECUTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventExecute ) );
    Disconnect( wxID_SORT_ASCENDING, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LambdaFrame::EventSort ) );
    //Tree
    Disconnect( wxID_ANY, wxEVT_TREE_ITEM_ACTIVATED, wxDataViewEventHandler( LambdaFrame::EventVarActivated ) );
    //Disconnect( m_toolAdd->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( LambdaFrame::EventAddTool ) );
    //Disconnect( m_toolOK->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( LambdaFrame::EventOkTool ) );
    //Grid
    m_gridData->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( LambdaFrame::EventCellChange ), NULL, this );
    m_gridData->Disconnect( wxEVT_GRID_LABEL_LEFT_DCLICK, wxGridEventHandler( LambdaFrame::EventLabelDClick ), NULL, this );

    //delete de LambdaDatabase
    delete m_databaseInput;
    delete m_databaseOutput;
    
    // any processes left until now must be deleted manually: normally this is
    // done when the associated process terminates but it must be still running
    // if this didn't happen until now
    for ( size_t n = 0; n < m_running.size(); n++ )
    {
        delete m_running[n];
    }
    
    // deinitialize the frame manager
    m_mgr.UnInit();
}

// Event Handlers

//! event handler EventIdle, get the output of the gams process
void LambdaFrame::EventIdle(wxIdleEvent& event)
{
    size_t count = m_running.GetCount();
    for ( size_t n = 0; n < count; n++ )
    {
        if ( m_running[n]->HasOutput() )
        {
            event.RequestMore();
        }
    }
}

//! event handler New
void LambdaFrame::EventNew( wxCommandEvent& event )
{
    wxMessageBox("Nuevo");
}

//! event handler Open
void LambdaFrame::EventOpen( wxCommandEvent& event )
{
    wxMessageBox("Open");
}

//! event handler Quit
void LambdaFrame::EventQuit( wxCommandEvent& event )
{
    Close(TRUE);
}

//! event handler Copy Data
void LambdaFrame::EventCopy( wxCommandEvent& event )
{
    int i,j;
    //Informacion copiada
    wxString copy_data;
    bool something_in_this_line;
    //Data con la informacion copiada
    wxTextDataObject *data;
    
    //Limpia la cadena
    copy_data.Clear();
    
    //Copia la informacion de la seleccion
    if (m_gridData->IsSelection())
    {
        for (i=0; i<m_gridData->GetRows();i++)
        {
            //Determina las celdas seleecionada
            something_in_this_line = false;
            for (j=0; j<m_gridData->GetCols(); j++)
            {
                if (m_gridData->IsInSelection(i,j))
                {
                    if (something_in_this_line == false)
                    {
                        if (copy_data.IsEmpty() == false)
                            copy_data.Append(wxT("\n"));
                        something_in_this_line = true;
                    }
                    else
                        copy_data.Append(wxT("\t"));
                    //Agrega lo que se encuentra en la celda
                    copy_data += m_gridData->GetCellValue(i,j);
                }
            }
        }
    }
    //Si no hay seleccion copia el valor d ela celda actual
    else
        copy_data = m_gridData->GetCellValue(m_gridData->GetGridCursorRow(), m_gridData->GetGridCursorCol());
    
    //Copia la informacion en el clipboard
    data = new wxTextDataObject(copy_data);
    m_clipboard->Open();
    m_clipboard->SetData(data);
    m_clipboard->Close();
}

//! event handler Paste Data
void LambdaFrame::EventPaste( wxCommandEvent& event )
{
    //Solo se puede copiar en las tablas de entrada
    if (m_Input)
    {
        int i,j,k;
        wxString copy_data;
        wxString cur_field;
        wxString cur_line;
        wxTextDataObject *data = new wxTextDataObject();
        
        //Abre el clipboard para pegar la informacion
        m_clipboard->Open();
        m_clipboard->GetData(*data);
        copy_data = data->GetText();
        m_clipboard->Close();
        
        //Si el cambio de retorno es \r o \r\n lo cambia a \n
        copy_data.Replace("\r\n", "\n");
        copy_data.Replace("\r", "\n");
        //Elimina los primeros cambios de retorno
        while (copy_data.Find("\n")==0)
            copy_data = copy_data.AfterFirst('\n');
        
        //Si hay seleccion copia el primer valor
        if (m_gridData->IsSelection())
        {
            //Recupera la informacion a copiar
            cur_line = copy_data.BeforeFirst('\n');
            cur_field = cur_line.BeforeFirst('\t');
            
            //Para la seleccion de bloques
            wxGridCellCoordsArray TopLeft = m_gridData->GetSelectionBlockTopLeft();
            wxGridCellCoordsArray BottomRight = m_gridData->GetSelectionBlockBottomRight();
            //Para cada bloque seleccionado
            for (i=0; i<TopLeft.GetCount(); i++)
            {
                //Si no es una tabla de indices y la columna es de indices no se puede copiar
                if ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX) || ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_NO_IDX) && (TopLeft[i].GetCol()>=m_databaseInput->m_numberidx.Item(m_lastposInput))))
                {
                    //Para cada fila y columna del bloque
                    for (j=0; j<BottomRight[i].GetRow()-TopLeft[i].GetRow()+1; j++)
                        for (k=0; k<BottomRight[i].GetCol()-TopLeft[i].GetCol()+1; k++)
                        {
                            //Guarda la informacion del clipboard en la celda
                            m_gridData->SetCellValue(TopLeft[i].GetRow() + j, TopLeft[i].GetCol() + k,cur_field);
                            //Actualiza la base de datos
                            CellChange(TopLeft[i].GetRow() + j, TopLeft[i].GetCol() + k, cur_field);
                        }
                }
            }
            //Para un conjunto de celdas selecionadas
            wxGridCellCoordsArray cells = m_gridData->GetSelectedCells();
            for(i=0; i<cells.GetCount(); i++ )
            {
                //Si no es una tabla de indices y la columna es de indices no se puede copiar
                if ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX) || ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_NO_IDX) && (cells[i].GetCol()>=m_databaseInput->m_numberidx.Item(m_lastposInput))))
                {
                    //Guarda la informacion del clipboard en la celda
                    m_gridData->SetCellValue(cells[i].GetRow(),cells[i].GetCol(),cur_field);
                    //Actualiza la base de datos
                    CellChange(cells[i].GetRow(), cells[i].GetCol(), cur_field);
                }
            }
        }
        else
        {
            //Determina la posicion actual en el grid
            i = m_gridData->GetGridCursorRow();
            j = m_gridData->GetGridCursorCol();
            //Si no es una tabla de indices y la columna es de indices no se puede copiar
            if ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX) || ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_NO_IDX) && (j>=m_databaseInput->m_numberidx.Item(m_lastposInput))))
            {
                k = j;
                //Si hay informacion para copiar
                while(!copy_data.IsEmpty())
                {
                    cur_line = copy_data.BeforeFirst('\n');
                    while( (!cur_line.IsEmpty()) && (i<m_gridData->GetRows()) && (j<m_gridData->GetCols()))
                    {
                        cur_field = cur_line.BeforeFirst('\t');
                        //Guarda la informacion del clipboard en la celda
                        m_gridData->SetCellValue(i,j,cur_field);
                        //Actualiza la base de datos
                        CellChange(i, j, cur_field);
                        j++;
                        cur_line  = cur_line.AfterFirst ('\t');
                    }
                    i++;
                    j=k;
                    copy_data = copy_data.AfterFirst('\n');
                }
            }
        }
    }
}

//! event handler About
void LambdaFrame::EventAbout( wxCommandEvent& event )
{
    wxMessageBox("About");
}

//! event handler Preferences, show the preferences dialog and save the paths
void LambdaFrame::EventPreferences(wxCommandEvent &event)
{
    bool cambio = false;  //indica si hay un cambio en la ruta de ejecucion
    
    Dialog_Preferences *m_dialog = new Dialog_Preferences(this, s_GamsPath, s_ExePath);
    m_dialog->ShowModal();
    //Hay un cambio en la ruta
    if (s_GamsPath != m_dialog->m_dirGamsPath->GetPath())
    {
        s_GamsPath = m_dialog->m_dirGamsPath->GetPath();
        cambio = true;
    }
    //Hay un cambio en la ruta
    if (s_ExePath != m_dialog->m_dirExePath->GetPath())
    {
        s_ExePath = m_dialog->m_dirExePath->GetPath();
        cambio = true;
    }
    delete m_dialog;
    
    //Si el usuario selecciono las rutas y hay cambio
    if (!s_GamsPath.IsEmpty() && !s_ExePath.IsEmpty() && cambio)
    {
        //Fija el directorio de trabajo
        wxSetWorkingDirectory(s_ExePath);

        //Crea el fichero para la ejecucion de gms2sqlite
        wxString file_name = s_AppPath + "/Resources/lambdagms2sql.cod";
        //borra el fichero si existe
        if (wxFileExists(file_name)) wxRemoveFile(file_name);
        //crea un nuevo fichero
        wxTextFile *file = new wxTextFile(file_name);
        file->Create();
        file->AddLine("execute \"" + s_GamsPath + "/gdx2sqlite -i salidas.gdx -o salidas.db -fast\";");
        //salva y cierra el archivo de texto
        file->Write();
        file->Close();
        
        //delete the previous database
        delete m_databaseInput;
        //Create the LambdaDatabase
        m_databaseInput = new LambdaDatabaseInput(s_ExePath + "/lambda_input.db");
        //Create the tree
        CreateTreeInput();
    }
}

//! event handler Execute, execute gams
void LambdaFrame::EventExecute( wxCommandEvent& event )
{
    int i;
    
    //Si no hay rutas de ejecucion
    if (s_ExePath.IsEmpty() || s_GamsPath.IsEmpty())
    {
        switch (LAMBDA_LANGUAGE)
        {
            case ID_SPANISH:
                wxMessageBox("Se deben seleccionar las rutas en el Menú de preferencias");
                break;
            case ID_ENGLISH:
                wxMessageBox("Please select first the paths in the Preferences Menu");
                break;
        }
        return;
    }
    
    //Dialogo de opciones de ejecucion
    Dialog_Execution dialog(this);
    
    //Si se ejecuta gams
    if (dialog.ShowModal() == wxID_OK)
    {
        //si borrar el contenido de la carpeta de Datos fue correcto
        if (EmptyDatosFolder())
        {
            //Crea el archivo de opciones
            wxArrayInt cbOpt;
            cbOpt.Add(dialog.m_cBoxEquilibrio->GetSelection());
            cbOpt.Add(dialog.m_cBoxDemand->GetSelection());
            cbOpt.Add(dialog.m_cBoxVariables->GetSelection());
            cbOpt.Add(dialog.m_cBoxNetwork->GetSelection());
            CreateOpt(&cbOpt);
        
            //directorio de carpeta de datos
            wxString dir_data = s_AppPath + "/Resources/Datos";
            //guarda los datos en ficheros de texto
            for (i=0; i<m_databaseInput->m_tables.GetCount(); i++)
            {
                m_databaseInput->SqlSave(m_databaseInput->m_tables.Item(i), dir_data, m_databaseInput->m_tidx.Item(i));
            }
            
            /*wxArrayString output;
             wxArrayString errors;
             wxString output2 = wxEmptyString;
             wxExecute("/Applications/GAMS/gams23.8_osx_x64_64_sfx/gams", output, errors);
             int line;
             for (line=0; line<output.GetCount(); line++)
             {
             output2 += wxT("\n") + output.Item(line);
             }
             wxMessageBox(output2);*/
            
            //directorio de trabajo
            wxSetWorkingDirectory(s_AppPath + "/Resources");
            
            //ruta de gams
            //wxString cmd = s_GamsPath + "/gams lambda.gms lo=0 ps=0";
            wxString cmd = s_GamsPath + "/gams lambda.gms lo=1 ps=0";
            PipedProcess *process = new PipedProcess(this);
            if ( !wxExecute(cmd, wxEXEC_ASYNC, process) )
            {
                wxLogError(wxT("Execution of '%s' failed."), cmd.c_str());
                
                delete process;
            }
            else
            {
                AddPipedProcess(process);
            }
        }
        else
        {
            wxMessageBox("Error en la carpeta de datos");
        }
    }
}

//! event handler Sort, sort the tables of the db
void LambdaFrame::EventSort(wxCommandEvent &event)
{
    SortTables();
}

//! event handler Toolbar plus
void LambdaFrame::EventAddTool(wxCommandEvent &event)
{
    wxMessageBox("plus");
}

//! event handler Toolbar Ok
void LambdaFrame::EventOkTool(wxCommandEvent &event)
{
    wxMessageBox("ok");
}

//! event handler Item Activated, the user activate a table and show the data of the table
void LambdaFrame::EventVarActivated( wxDataViewEvent& event )
{
    bool cambio = false;
    wxTreeItemId item_selected = m_ViewTreeVariables->GetSelection();
    LambdaDatatables* data = (LambdaDatatables*)m_ViewTreeVariables->GetItemData(item_selected);
    //Determina si hay un cambio de tabla
    if (m_Input!=data->IsInput())
    {
        m_Input = data->IsInput();
        cambio = true;
    }
    if ((m_Input) && (m_lastposInput!=data->GetPos()))
    {
        m_lastposInput = data->GetPos();
        cambio = true;
    }
    else if (m_lastposOutput!=data->GetPos())
    {
        m_lastposOutput = data->GetPos();
        cambio = true;
    }
    //Si hay cambio de tabla muestra la tabla
    if (cambio)
        ReadTable();
}

//! event cell change, a value of the table change
void LambdaFrame::EventCellChange( wxGridEvent &event )
{
    //Si es una tabla de indices y es la ultima fila actualiza
    //if ((m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX) && (event.GetRow()==(m_gridData->GetRows()-1)))
    if (m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX)
        CellChange(event.GetRow(), event.GetCol(), event.GetString());
    //si no es una tabla de indices y la columna no es de indices actualiza, sino veta el evento
    else if (event.GetCol()>=m_databaseInput->m_numberidx.Item(m_lastposInput))
        CellChange(event.GetRow(), event.GetCol(), event.GetString());
    else
        event.Veto();
}

//Creates a new row on the grid
void LambdaFrame::EventLabelDClick(wxGridEvent& event)
{
    int row = event.GetRow();
    if ( (m_Input) && (row!=-1) && (m_gridData->GetNumberRows()>=0) && (m_gridData->GetRowLabelValue(row)=="+") && (m_databaseInput->m_tables.Item(m_lastposInput)!="id_pe") )
        //Se agrega una nueva fila
        m_gridData->AppendRows(1);
}

void LambdaFrame::EventCellRightClick(wxGridEvent &event)
{
    wxMenu *pmenuPopUp = new wxMenu;
    wxMenuItem* pItem;
    pItem = new wxMenuItem(pmenuPopUp,wxID_COPY, wxT("Copy"));
    pmenuPopUp->Append(pItem);
    
    pItem = new wxMenuItem(pmenuPopUp,wxID_PASTE, wxT("Paste"));
    pmenuPopUp->Append(pItem);
    if(!m_gridData->CanEnableCellControl())
        pItem->Enable(false);
    
    PopupMenu(pmenuPopUp,event.GetPosition());
    delete pmenuPopUp;
}

//piped Process, the gams process has terminated, save the output in a db
void LambdaFrame::EventProcessTerminated(PipedProcess *process)
{
    m_running.Remove(process);
    //Finaliza la ejecucion de gams
    //Copia la base de datos de salida en el directorio de ejecucion
    wxCopyFile(s_AppPath + "/Resources/salidas.db", s_ExePath + "/lambda_output.db");
    //delete the previous database
    delete m_databaseOutput;
    //Create the LambdaDatabase
    m_databaseOutput = new LambdaDatabaseOutput(s_ExePath + "/lambda_output.db");
    //Create the tree
    CreateTreeOutput();
}

//add a new gams process
void LambdaFrame::AddPipedProcess(PipedProcess *process)
{
    m_running.Add(process);
}

//Set the language of the menu
void LambdaFrame::LanguageMenu()
{
    switch (LAMBDA_LANGUAGE)
	{
        case ID_SPANISH:
        {
            m_menubar->SetMenuLabel(0, "Archivo");
			m_menubar->SetMenuLabel(1, "Editar");
			m_menubar->SetMenuLabel(2, "Herramientas");
			m_menubar->SetMenuLabel(3, "Ayuda");

			m_menuFile->SetLabel(wxID_NEW, wxString("Nuevo") + wxT('\t') + wxT("CTRL+N"));
			m_menuFile->SetLabel(wxID_OPEN, wxString("Abrir") + wxT('\t') + wxT("CTRL+O"));
			m_menuFile->SetLabel(wxID_EXIT, wxString("Salir") + wxT('\t') + wxT("CTRL+Q"));
			m_menuEdit->SetLabel(wxID_COPY, wxString("Copiar") + wxT('\t') + wxT("CTRL+C"));
			m_menuEdit->SetLabel(wxID_PASTE, wxString("Pegar") + wxT('\t') + wxT("CTRL+V"));
			m_menuEdit->SetLabel(wxID_PREFERENCES, wxString("Preferencias") + wxT('\t') + wxT("CTRL+,"));
			m_menuTools->SetLabel(wxID_EXECUTE, wxString("Ejecutar") + wxT('\t') + wxT("CTRL+E"));
			m_menuTools->SetLabel(wxID_SORT_ASCENDING, wxString("Ordenar tablas"));
			m_menuHelp->SetLabel(wxID_ABOUT, wxString("Acerca de"));

            break;
        }
        case ID_ENGLISH:
        {
			m_menubar->SetMenuLabel(0, "File");
			m_menubar->SetMenuLabel(1, "Edit");
			m_menubar->SetMenuLabel(2, "Tools");
			m_menubar->SetMenuLabel(3, "Help");

			m_menuFile->SetLabel(wxID_NEW, wxString("New") + wxT('\t') + wxT("CTRL+N"));
			m_menuFile->SetLabel(wxID_OPEN, wxString("Open") + wxT('\t') + wxT("CTRL+O"));
			m_menuFile->SetLabel(wxID_EXIT, wxString("Quit") + wxT('\t') + wxT("CTRL+Q"));
			m_menuEdit->SetLabel(wxID_COPY, wxString("Copy") + wxT('\t') + wxT("CTRL+C"));
			m_menuEdit->SetLabel(wxID_PASTE, wxString("Paste") + wxT('\t') + wxT("CTRL+V"));
			m_menuEdit->SetLabel(wxID_PREFERENCES, wxString("Preferences") + wxT('\t') + wxT("CTRL+,"));
			m_menuTools->SetLabel(wxID_EXECUTE, wxString("Execute") + wxT('\t') + wxT("CTRL+E"));
			m_menuTools->SetLabel(wxID_SORT_ASCENDING, wxString("Sort tables"));
			m_menuHelp->SetLabel(wxID_ABOUT, wxString("About"));
            break;
        }
    }
}

//return the Gams Path
wxString LambdaFrame::GetGamsPath()
{
    return s_GamsPath;
}

//return the Execution Path
wxString LambdaFrame::GetExePath()
{
    return s_ExePath;
}

//Create the root nodes on the variable tree
void LambdaFrame::CreateRootNodes()
{
    LambdaDatatables *m_data;
    m_ViewTreeVariables->AddRoot("");
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
        {
            m_data = new LambdaDatatables(-1,true);
            tree_input = m_ViewTreeVariables->AppendItem(m_ViewTreeVariables->GetRootItem(), "Datos de entrada",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_output = m_ViewTreeVariables->AppendItem(m_ViewTreeVariables->GetRootItem(), "Datos de salida",-1,-1,m_data);
            break;
        }
        case ID_ENGLISH:
        {
            m_data = new LambdaDatatables(-1,true);
            tree_input = m_ViewTreeVariables->AppendItem(m_ViewTreeVariables->GetRootItem(), "Input data",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_output = m_ViewTreeVariables->AppendItem(m_ViewTreeVariables->GetRootItem(), "Output data",-1,-1,m_data);
            break;
        }
    }
    m_ViewTreeVariables->SetItemBold(tree_input);
    m_ViewTreeVariables->SetItemBold(tree_output);
}

//Create the tree menu with the tables visible for the user from the Input LambdaDatabase
void LambdaFrame::CreateTreeInput()
{
    int k;
    int n_tables = m_databaseInput->m_tipo.GetCount();
    wxTreeItemId tree_periods;
    wxTreeItemId tree_companies;
    wxTreeItemId tree_thermal;
    wxTreeItemId tree_hydro;
    wxTreeItemId tree_am;
    wxTreeItemId tree_demand;
    wxTreeItemId tree_network;
    
    LambdaDatatables *m_data;
    
    //Borra los hijos
    m_ViewTreeVariables->DeleteChildren(tree_input);
    
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
        {
            m_data = new LambdaDatatables(-1,true);
            tree_periods = m_ViewTreeVariables->AppendItem(tree_input, "Características temporales",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_network = m_ViewTreeVariables->AppendItem(tree_input, "Red",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_companies = m_ViewTreeVariables->AppendItem(tree_input, "Empresas",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_thermal = m_ViewTreeVariables->AppendItem(tree_input, "Grupos térmicos",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_hydro = m_ViewTreeVariables->AppendItem(tree_input, "Grupos hidraúlicos",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_am = m_ViewTreeVariables->AppendItem(tree_input, "Agentes marginalistas",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_demand = m_ViewTreeVariables->AppendItem(tree_input, "Demanda",-1,-1,m_data);
            break;
        }
        case ID_ENGLISH:
        {
            m_data = new LambdaDatatables(-1,true);
            tree_periods = m_ViewTreeVariables->AppendItem(tree_input, "Time characteristics",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_network = m_ViewTreeVariables->AppendItem(tree_input, "Network",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_companies = m_ViewTreeVariables->AppendItem(tree_input, "Companies",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_thermal = m_ViewTreeVariables->AppendItem(tree_input, "Thermal groups",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_hydro = m_ViewTreeVariables->AppendItem(tree_input, "Hydro groups",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_am = m_ViewTreeVariables->AppendItem(tree_input, "Marginalist agents",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,true);
            tree_demand = m_ViewTreeVariables->AppendItem(tree_input, "Demand",-1,-1,m_data);
            break;
        }
    }
    for (k=0; k<n_tables; k++)
    {
        //Guarda la posicion de la tabla correspondiente en m_data
        m_data = new LambdaDatatables(k,true);
        switch (m_databaseInput->m_tipo.Item(k))
        {
            case ID_TIME:
                m_ViewTreeVariables->AppendItem(tree_periods, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_COMPANIES:
                m_ViewTreeVariables->AppendItem(tree_companies, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_THERMAL:
                m_ViewTreeVariables->AppendItem(tree_thermal, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_HYDRO:
                m_ViewTreeVariables->AppendItem(tree_hydro, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_MARGINALIST:
                m_ViewTreeVariables->AppendItem(tree_am, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_DEMAND:
                m_ViewTreeVariables->AppendItem(tree_demand, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
            case ID_SYSTEM:
                m_ViewTreeVariables->AppendItem(tree_network, m_databaseInput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                break;
        }
    }
}

//Create the tree menu with the tables visible for the user from the output LambdaDatabase
void LambdaFrame::CreateTreeOutput()
{
    int k;
    int n_tables = m_databaseOutput->m_tipo.GetCount();
    wxTreeItemId tree_periods;
    wxTreeItemId tree_companies;
    wxTreeItemId tree_thermal;
    wxTreeItemId tree_hydro;
    wxTreeItemId tree_am;
    
    wxTreeItemId tp0;
    wxTreeItemId tp1;
    wxTreeItemId tp2;
    wxTreeItemId tc0;
    wxTreeItemId tc1;
    wxTreeItemId tc2;
    wxTreeItemId tt0;
    wxTreeItemId tt1;
    wxTreeItemId tt2;
    wxTreeItemId th0;
    wxTreeItemId th1;
    wxTreeItemId th2;
    wxTreeItemId ta0;
    wxTreeItemId ta1;
    wxTreeItemId ta2;
    LambdaDatatables *m_data;
    
    //Borra los hijos
    m_ViewTreeVariables->DeleteChildren(tree_output);
    
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
        {
            m_data = new LambdaDatatables(-1,false);
            tree_periods = m_ViewTreeVariables->AppendItem(tree_output, "Sistema",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp0 = m_ViewTreeVariables->AppendItem(tree_periods, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp1 = m_ViewTreeVariables->AppendItem(tree_periods, "Por periodo",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp2 = m_ViewTreeVariables->AppendItem(tree_periods, "Por periodo y estado",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_companies = m_ViewTreeVariables->AppendItem(tree_output, "Empresas",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc0 = m_ViewTreeVariables->AppendItem(tree_companies, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc1 = m_ViewTreeVariables->AppendItem(tree_companies, "Por periodo",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc2 = m_ViewTreeVariables->AppendItem(tree_companies, "Por periodo y estado",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_thermal = m_ViewTreeVariables->AppendItem(tree_output, "Grupos térmicos",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt0 = m_ViewTreeVariables->AppendItem(tree_thermal, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt1 = m_ViewTreeVariables->AppendItem(tree_thermal, "Por periodo",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt2 = m_ViewTreeVariables->AppendItem(tree_thermal, "Por periodo y estado",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_hydro = m_ViewTreeVariables->AppendItem(tree_output, "Grupos hidraúlicos",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th0 = m_ViewTreeVariables->AppendItem(tree_hydro, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th1 = m_ViewTreeVariables->AppendItem(tree_hydro, "Por periodo",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th2 = m_ViewTreeVariables->AppendItem(tree_hydro, "Por periodo y estado",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_am = m_ViewTreeVariables->AppendItem(tree_output, "Agentes marginalistas",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta0 = m_ViewTreeVariables->AppendItem(tree_am, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta1 = m_ViewTreeVariables->AppendItem(tree_am, "Por periodo",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta2 = m_ViewTreeVariables->AppendItem(tree_am, "Por periodo y estado",-1,-1,m_data);
            break;
        }
        case ID_ENGLISH:
        {
            m_data = new LambdaDatatables(-1,false);
            tree_periods = m_ViewTreeVariables->AppendItem(tree_output, "System",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp0 = m_ViewTreeVariables->AppendItem(tree_periods, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp1 = m_ViewTreeVariables->AppendItem(tree_periods, "By period",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tp2 = m_ViewTreeVariables->AppendItem(tree_periods, "By Period and state",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_companies = m_ViewTreeVariables->AppendItem(tree_output, "Companies",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc0 = m_ViewTreeVariables->AppendItem(tree_companies, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc1 = m_ViewTreeVariables->AppendItem(tree_companies, "By period",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tc2 = m_ViewTreeVariables->AppendItem(tree_companies, "By Period and state",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_thermal = m_ViewTreeVariables->AppendItem(tree_output, "Thermal groups",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt0 = m_ViewTreeVariables->AppendItem(tree_thermal, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt1 = m_ViewTreeVariables->AppendItem(tree_thermal, "By period",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tt2 = m_ViewTreeVariables->AppendItem(tree_thermal, "By Period and state",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_hydro = m_ViewTreeVariables->AppendItem(tree_output, "Hydro groups",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th0 = m_ViewTreeVariables->AppendItem(tree_hydro, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th1 = m_ViewTreeVariables->AppendItem(tree_hydro, "By period",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            th2 = m_ViewTreeVariables->AppendItem(tree_hydro, "By Period and state",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            tree_am = m_ViewTreeVariables->AppendItem(tree_output, "Marginalist agents",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta0 = m_ViewTreeVariables->AppendItem(tree_am, "General",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta1 = m_ViewTreeVariables->AppendItem(tree_am, "By period",-1,-1,m_data);
            m_data = new LambdaDatatables(-1,false);
            ta2 = m_ViewTreeVariables->AppendItem(tree_am, "By Period and state",-1,-1,m_data);
            break;
        }
    }
    
    for (k=0; k<n_tables; k++)
    {
        //Guarda la posicion de la tabla correspondiente en m_data
        m_data = new LambdaDatatables(k,false);
        switch(m_databaseOutput->m_tipo.Item(k))
        {
            case ID_SYSTEM:
            {
                switch (m_databaseOutput->m_horizonte.Item(k))
                {
                    case ID_GENERAL:
                        m_ViewTreeVariables->AppendItem(tp0, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE:
                        m_ViewTreeVariables->AppendItem(tp1, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE_ST:
                        m_ViewTreeVariables->AppendItem(tp2, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                }
                break;
            }
            case ID_COMPANIES:
            {
                switch (m_databaseOutput->m_horizonte.Item(k))
                {
                    case ID_GENERAL:
                        m_ViewTreeVariables->AppendItem(tc0, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE:
                        m_ViewTreeVariables->AppendItem(tc1, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE_ST:
                        m_ViewTreeVariables->AppendItem(tc2, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                }
                break;
            }
            case ID_THERMAL:
            {
                switch (m_databaseOutput->m_horizonte.Item(k))
                {
                    case ID_GENERAL:
                        m_ViewTreeVariables->AppendItem(tt0, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE:
                        m_ViewTreeVariables->AppendItem(tt1, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE_ST:
                        m_ViewTreeVariables->AppendItem(tt2, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                }
                break;
            }
            case ID_HYDRO:
            {
                switch (m_databaseOutput->m_horizonte.Item(k))
                {
                    case ID_GENERAL:
                        m_ViewTreeVariables->AppendItem(th0, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE:
                        m_ViewTreeVariables->AppendItem(th1, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE_ST:
                        m_ViewTreeVariables->AppendItem(th2, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                }
                break;
            }
            case ID_MARGINALIST:
            {
                switch (m_databaseOutput->m_horizonte.Item(k))
                {
                    case ID_GENERAL:
                        m_ViewTreeVariables->AppendItem(ta0, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE:
                        m_ViewTreeVariables->AppendItem(ta1, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                    case ID_PE_ST:
                        m_ViewTreeVariables->AppendItem(ta2, m_databaseOutput->m_tablesTreeLabels.Item(k),-1,-1,m_data);
                        break;
                }
                break;
            }
        }
    }
}

//Modify the Grid depending the table
void LambdaFrame::ReadTable()
{
    int i;
    
    //table with the data
    wxSQLite3Table table;
    wxString table_name;
    wxString sql_com;
    
    //Number of rows and cols of the table
    int rows = m_gridData->GetNumberRows();
    int cols = m_gridData->GetNumberCols();
    
    //Si es una tabla de entrada
    if (m_Input)
    {
        //La posicion debe ser diferente de -1
        if (m_lastposInput != -1)
        {
			m_gridData->EnableEditing( true );
            
            wxSQLite3Transaction transaction(m_databaseInput->m_database);
			//Elimina la tabla anterior
            if (rows > 0) m_gridData->DeleteRows(0,m_gridData->GetNumberRows(),true);
            if (cols > 0) m_gridData->DeleteCols(0,m_gridData->GetNumberCols(),true);
    
            //Nombre de la tabla
            table_name = m_databaseInput->m_tables.Item(m_lastposInput);
            //Lee la tabla
            if (table_name == "id_pe") sql_com = "SELECT COUNT(*) FROM id_pe;";
            else sql_com = "SELECT * FROM " + table_name + ";";
            //Lee la tabla
            table = m_databaseInput->m_database->GetTable(sql_com);
            //numero de datos de la tabla
            rows = table.GetRowCount();
            cols = table.GetColumnCount();
            
            //Crea el grid para la tabla
            m_gridData->AppendRows(rows);
            m_gridData->AppendCols(cols);
            
            //Pasa la tabla al grid
            m_gridTable->SetData(&table);
            
            //Pone los titulos de las columnas, //tambien se puede utilizar PRAGMA table_info('table_name');"
            //Tabla del número de periodos
            if (table_name == "id_pe")
            {
                switch (LAMBDA_LANGUAGE)
                {
                    case ID_SPANISH:
                        m_gridData->SetColLabelValue(0, "Número de\nperíodos");
                        break;
                    case ID_ENGLISH:
                        m_gridData->SetColLabelValue(0, "Number of\nperiods");
                        break;
                }
            }
            //Otras tablas
            else
            {
                //Set the label of the column
                for (i=0; i<cols; i++)
                    m_gridData->SetColLabelValue(i, m_databaseInput->Label(table.GetColumnName(i)));
                                
                //Si es una tabla de indices
                if (m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX)
                {
                    m_gridData->AppendRows(1);
                    //Si es una tabla de indices y esta vacia pone el titulo de la columa
                    if (cols==0)
                    {
                        m_gridData->AppendCols(1);
                        m_gridData->SetColLabelValue(0, m_databaseInput->Label(m_databaseInput->m_idx1.Item(m_lastposInput)));
                    }
                }
            }
            transaction.Commit();
            //Muestra el grid
            m_gridData->Show();
        }
    }
    else
    {
        //La posicion debe ser diferente de -1
        if (m_lastposOutput != -1)
        {
			m_gridData->EnableEditing( false );
            
            wxSQLite3Transaction transaction(m_databaseOutput->m_database);
			//Elimina la tabla anterior
            if (rows > 0) m_gridData->DeleteRows(0,m_gridData->GetNumberRows());
            if (cols > 0) m_gridData->DeleteCols(0,m_gridData->GetNumberCols());
    
            //Nombre de la tabla
            table_name = m_databaseOutput->m_tables.Item(m_lastposOutput);
            //si la tabla tiene indices
            if (m_databaseOutput->m_numberidx.Item(m_lastposOutput)>0)
                sql_com = "SELECT * FROM " + table_name + ";";
            else
                sql_com = "SELECT VALUE FROM " + table_name + ";";
            
            //Lee la tabla
            table = m_databaseOutput->m_database->GetTable(sql_com);
            //numero de datos de la tabla
            rows = table.GetRowCount();
            cols = table.GetColumnCount();
            
            //Crea el grid para la tabla
            m_gridData->AppendRows(rows);
            m_gridData->AppendCols(cols);
            
            //Pasa la tabla al grid
            m_gridTable->SetData(&table);
            
            //Pone los titulos de las columnas
            for (i=0; i<cols; i++)
                //Si es una columna de indice
                if (i<m_databaseOutput->m_numberidx.Item(m_lastposOutput))
                    m_gridData->SetColLabelValue(i, m_databaseOutput->Label(table.GetColumnName(i)));
                else
                    m_gridData->SetColLabelValue(i, m_databaseOutput->Label(table_name));
        
            transaction.Commit();
            //Dibuja y muestra la tabla
            m_gridData->Show();
        }
    }
}

//Copy the gams files from the resources dir to the execution dir
void LambdaFrame::CopyGamsFiles()
{
    int i;
    wxArrayString gamsFiles;
    gamsFiles.Add("cplex.opt");
    gamsFiles.Add("lambda.gms");
    gamsFiles.Add("lambdadatos.cod");
    gamsFiles.Add("lambdapresolve.cod");
    gamsFiles.Add("lambdasalidas.cod");
    gamsFiles.Add("lambdasolve.cod");
    
    for (i=0; i<gamsFiles.GetCount(); i++)
    {
        wxCopyFile(s_AppPath + "/Resources/" + gamsFiles.Item(i), s_ExePath + "/" + gamsFiles.Item(i));
    }
}

//Delete all files from the Datos folder
bool LambdaFrame::EmptyDatosFolder()
{
    wxDir *dir;
    wxString dir_name;
    wxArrayString files;
    int i;
    bool correcto;
    dir_name = s_AppPath + "/Resources/Datos";
    
    //Si no existe el directorio de datos lo crea
    if (!wxDirExists(dir_name))
    {
        wxMkdir(dir_name);
        return true;
    }
    //Borra todos los ficheros del directorio
    else
    {
        dir = new wxDir(dir_name);
        dir->GetAllFiles(dir_name, &files);
        for (i=0; i<files.GetCount(); i++)
        {
            correcto = wxRemoveFile(files.Item(i));
            if (!correcto) return false;
        }
    }
    return true;
}

//Create the option file used by gams
void LambdaFrame::CreateOpt(wxArrayInt* opt)
{
    wxTextFile opt_gams;
    //Crea el fichero de opciones
    opt_gams.Create(s_AppPath + "/Resources/Datos/opt_lambda.dat");
    opt_gams.AddLine("OPT_EQUI = " + wxString::Format(wxT("%i"),opt->Item(0)) + ";");
    opt_gams.AddLine("OPT_DEM = " + wxString::Format(wxT("%i"),opt->Item(1)) + ";");
    opt_gams.AddLine("OPT_ENT = " + wxString::Format(wxT("%i"),opt->Item(2)) + ";");
    opt_gams.AddLine("OPT_RED = " + wxString::Format(wxT("%i"),opt->Item(3)) + ";");
    opt_gams.Write();
    opt_gams.Close();
}

//Update the labels of the grid
void LambdaFrame::UpdateLabelsGrid(int mas)
{
    int i;
    int rows = m_gridData->GetNumberRows();
    for (i=0; i<rows; i++)
    {
        m_gridData->SetRowLabelValue(i, wxString::Format(wxT("%i"),i+1));
    }
    //se pone el mas al final de la tabla
    if(mas==1)
    {
        m_gridData->SetRowLabelValue(rows-1, "+");
    }
}

//The value of the cell changes, the LambdaDatabase must be updated
void LambdaFrame::CellChange(int row, int col, wxString newValue)
{
    wxString table_name; //Nombre de la tabla
    wxArrayString labels; //Labels de la tabla
    
    int size_old;
    long size_new;
    int i;
    
    //wxString valor = m_gridData->GetCellValue(row, col);
    wxString valor = newValue;
    valor.Trim(true);
    valor.Trim(false);
    wxString sqlcom;
    
    wxString new_id;
    
    if (m_lastposInput != -1)
    {
        //Nombre de la tabla
        table_name = m_databaseInput->m_tables.Item(m_lastposInput);
        
        //Tabla del número de periodos
        if (table_name == "id_pe")
        {
            //Convierte el valor en entero
            valor.ToLong(&size_new);
            //Cuenta el numero de filas que hay en la tabla
            size_old = m_databaseInput->m_database->ExecuteScalar("SELECT COUNT(*) FROM ID_PE;");
            //si el nuevo tamano es mayor que el anterior agrega nuevas filas
            if(size_new >= size_old)
                for (i=1; i<=size_new-size_old; i++)
                {
                    new_id = wxString::Format(wxT("pe%03i"),size_old+i);
                    m_databaseInput->UpdateTables(new_id, "pe");
                }
            //si el nuevo tamano es menor que el anterior elimina filas
            else
            {
                m_databaseInput->m_database->ExecuteQuery("PRAGMA foreign_keys = ON;");
                //wxSQLite3Transaction transaction(m_databaseInput->m_database);
                for (i=0; i<size_old-size_new; i++)
                {
                    new_id = wxString::Format(wxT("%03i"),size_old-i);
                    sqlcom = "DELETE FROM ID_PE WHERE pe = 'pe" + new_id + "';";
                    m_databaseInput->m_database->ExecuteQuery(sqlcom);
                }
                m_databaseInput->m_database->ExecuteQuery("PRAGMA foreign_keys = OFF;");
                //transaction.Commit();
            }
        }
        //Otras tablas
        else
        {
            //Recupera los labels
            m_databaseInput->SqlLabels(table_name, &labels);
            //Si la tabla es de indices actualiza en las demas tablas
            if (m_databaseInput->m_tidx.Item(m_lastposInput)==ID_IDX)
                m_databaseInput->UpdateTables(valor, m_databaseInput->m_idx1.Item(m_lastposInput));
            else
            {
                //Si la columna no es de indices actuliza el dato de la tabla
                if (col>=m_databaseInput->m_numberidx.Item(m_lastposInput))
                {
                    sqlcom = "UPDATE " + table_name + " SET " + labels.Item(col) + " = " + valor;
                    if (m_databaseInput->m_numberidx.Item(m_lastposInput)>0)
                        sqlcom += " WHERE ";
                    
                    for (i=0; i<m_databaseInput->m_numberidx.Item(m_lastposInput); i++)
                    {
                        valor = m_gridData->GetCellValue(row, i);
                        valor.Trim(true);
                        valor.Trim(false);
                        sqlcom += labels.Item(i) + " = '" + valor + "'" ;
                        if (i==m_databaseInput->m_numberidx.Item(m_lastposInput)-1) sqlcom += " ; ";
                        else sqlcom += " AND ";
                    }
                    m_databaseInput->m_database->ExecuteUpdate(sqlcom);
                }
            }
        }
    }
}

void LambdaFrame::SortTables()
{
    int i;
    if (!s_ExePath.IsEmpty())
    {
        wxSQLite3Transaction transaction(m_databaseInput->m_database);
        //Ordena todas las tablas
        for (i=0; i<m_databaseInput->m_tables.GetCount(); i++)
            m_databaseInput->SqlSort(m_databaseInput->m_tables.Item(i));
        transaction.Commit();
    }
}

void LambdaFrame::SetPanes()
{
    //Panes
    pane1.CaptionVisible(true);
    pane1.CloseButton(false);
    pane1.Left();
    pane1.Layer(1);
    pane1.Dock();
    pane1.FloatingSize(wxSize(250,400));
    pane1.MinSize(wxSize(250,400));
    pane1.PaneBorder(false);
    pane1.PinButton(true);
    pane1.MinimizeButton(true);
    pane1.MaximizeButton(true);
    
    pane2.CaptionVisible(true);
    pane2.CloseButton(false);
    pane2.Center();
    //pane2.Right();
    pane2.Dock();
    pane2.DockFixed();
    pane2.FloatingSize(wxSize(700,700));
    pane2.MinSize(wxSize(700,700));
    pane2.PaneBorder(false);
    //pane2.PinButton(true);
    pane2.MinimizeButton(true);
    pane2.MaximizeButton(true);
    
    pane3.CaptionVisible(true);
    pane3.CloseButton(false);
    pane3.Layer(0);
    pane3.Bottom();
    pane3.Dock();
    pane3.FloatingSize(wxSize(300,150));
    pane3.MinSize(wxSize(300,150));
    pane3.PaneBorder(false);
    pane3.PinButton(true);
    pane3.MinimizeButton(true);
    pane3.MaximizeButton(true);
    
    switch (LAMBDA_LANGUAGE)
    {
        case ID_SPANISH:
            pane1.Caption("Datos");
            pane2.Caption("Tablas");
            pane3.Caption("GAMS Log");
            break;
        case ID_ENGLISH:
            pane1.Caption("Data");
            pane2.Caption("Tables");
            pane3.Caption("GAMS Log");
            break;
    }
}

#endif
