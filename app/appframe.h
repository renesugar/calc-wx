#include "panels.h"
#include <wx/wxprec.h>

#ifndef headerfileappframe
#define headerfileappframe

class AppFrame : public wxFrame
{
public:
    AppFrame(const wxString& title);

    KeypadControl *m_keypad;
    DisplayControl *m_display;
    wxPanel *m_parent;
private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnKeyDown(wxKeyEvent &event);
    wxDECLARE_EVENT_TABLE();
};

#endif