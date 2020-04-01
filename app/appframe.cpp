#include "appframe.h"

#include <wx/clipbrd.h>
#include <wx/dataobj.h>

const int frameWidth  = 210;
const int frameHeight = 360;

AppFrame::AppFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(frameWidth, frameHeight)
        , wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
        //, wxDEFAULT_FRAME_STYLE)        
{
  SetBackgroundColour(wxColour(57, 57, 57));

  m_parent = new wxPanel(this, wxID_ANY);

  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  m_keypad  = new KeypadControl(m_parent);
  m_display = new DisplayControl(m_parent);

  vbox->Add(m_display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
  vbox->Add(m_keypad, 1, wxEXPAND | wxALL, 4);

  m_parent->SetSizer(vbox);

  // https://wiki.wxwidgets.org/Catching_key_events_globally
  m_keypad->Bind(wxEVT_CHAR_HOOK, &AppFrame::OnKeyDown, this);

  wxMenu *menuFile = new wxMenu;
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append( menuFile, "&File" );
  menuBar->Append( menuHelp, "&Help" );
  SetMenuBar( menuBar );
  CreateStatusBar();
  SetStatusText( "" );

  this->Centre();
}

wxBEGIN_EVENT_TABLE(AppFrame, wxFrame)
  EVT_MENU(wxID_EXIT,  AppFrame::OnExit)
  EVT_MENU(wxID_ABOUT, AppFrame::OnAbout)
wxEND_EVENT_TABLE()

void AppFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void AppFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox( "This is a wxWidgets' calculator sample",
                "About Calculator", wxOK | wxICON_INFORMATION );
}

void AppFrame::OnKeyDown(wxKeyEvent &event)
{
  if (event.GetModifiers() == wxMOD_CONTROL) {
    int code = event.GetKeyCode();
    if( code == _T('X') || code == _T('x') ||
        code == _T('V') || code == _T('v') ) {
      wxTextDataObject clipboard;
      wxString origText;
      wxString filteredText;
      wxUniChar ch;
      MyBig num;

      wxTheClipboard->Open();

      if (wxTheClipboard->IsSupported(wxDF_UNICODETEXT)) {
        wxTheClipboard->GetData(clipboard);
      }

      wxTheClipboard->Close();
      
      origText = clipboard.GetText();

      // Filter non-numeric characters from clipboard text

      for (int i = 0; i < origText.Length(); i++) {
        ch = origText.GetChar(i);

        if ((ch >= L'0' && ch <= L'9') || (ch == L'.') || (ch == L'-')  || (ch == L'+')  || (ch == L'e')) {
          filteredText.Append(ch);
        }
      }

      if (filteredText.Length() == 0) {
        filteredText.Append(L'0');
      }

      // Convert to a number and back to a string

      num.FromString(filteredText.ToAscii());

      if (num.IsNan()) {
        // Not a number
        filteredText.Clear();
        filteredText.Append(L'0');
      } else {
        filteredText.Clear();
        filteredText.Append(num.ToWString());
      }

      m_display->Clear();
      m_display->UpdateValue(filteredText);
      m_display->SetInsertionPointEnd();

      m_keypad->m_calculator.SetResultFalse();
    }
    else if( code == _T('C') || code == _T('c')) {
      if (wxTheClipboard->Open())
      {
        wxTheClipboard->Clear();
        wxTheClipboard->SetData(new wxTextDataObject(m_display->GetValue()));
        wxTheClipboard->Flush();
        wxTheClipboard->Close();
      }
    }
  }

  event.Skip();
}