#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/gbsizer.h>

#include "calcmodel.h"

#ifndef headerfilepanels
#define headerfilepanels

class KeypadControl : public wxPanel
{
public:
    KeypadControl(wxWindow* parent);

    wxString GetAccumulator();
    void UpdateDisplay(const wxString &label);
    void SetStatus(const wxString &label);
    void StoreResult();
    void OnDigit(const char* value);
    void OnAC(wxCommandEvent & event);
    void OnSign(wxCommandEvent & event);
    void OnModulo(wxCommandEvent & event);
    void OnDivide(wxCommandEvent & event);
    void OnDigit7(wxCommandEvent & event);
    void OnDigit8(wxCommandEvent & event);
    void OnDigit9(wxCommandEvent & event);
    void OnTimes(wxCommandEvent & event);
    void OnDigit4(wxCommandEvent & event);
    void OnDigit5(wxCommandEvent & event);
    void OnDigit6(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);
    void OnDigit1(wxCommandEvent & event);
    void OnDigit2(wxCommandEvent & event);
    void OnDigit3(wxCommandEvent & event);
    void OnPlus(wxCommandEvent & event);
    void OnDigit0(wxCommandEvent & event);
    void OnDecimal(wxCommandEvent & event);
    void OnEquals(wxCommandEvent & event);

    wxWindow* m_parent;
    wxGridBagSizer* m_sizer;

    wxButton* m_btn_ac;
    wxButton* m_btn_decimal;
    wxButton* m_btn_digit0;
    wxButton* m_btn_digit1;
    wxButton* m_btn_digit2;
    wxButton* m_btn_digit3;
    wxButton* m_btn_digit4;
    wxButton* m_btn_digit5;
    wxButton* m_btn_digit6;
    wxButton* m_btn_digit7;
    wxButton* m_btn_digit8;
    wxButton* m_btn_digit9;
    wxButton* m_btn_divide;
    wxButton* m_btn_equals;
    wxButton* m_btn_minus;
    wxButton* m_btn_modulo;
    wxButton* m_btn_mul;
    wxButton* m_btn_plus;
    wxButton* m_btn_sign;
    wxButton* m_btn_times;

    CalcModel m_calculator;
};

class DisplayControl : public wxTextCtrl
{
public:
    DisplayControl(wxWindow *parent);

    void UpdateValue(wxString str);

    void SetDefault();
};

const int ID_NOP     = wxID_HIGHEST + 100;
const int ID_AC      = wxID_HIGHEST + 101;
const int ID_SIGN    = wxID_HIGHEST + 102;
const int ID_MODULO  = wxID_HIGHEST + 103;
const int ID_DIVIDE  = wxID_HIGHEST + 104;
const int ID_DIGIT7  = wxID_HIGHEST + 105;
const int ID_DIGIT8  = wxID_HIGHEST + 106;
const int ID_DIGIT9  = wxID_HIGHEST + 107;
const int ID_TIMES   = wxID_HIGHEST + 108;
const int ID_DIGIT4  = wxID_HIGHEST + 109;
const int ID_DIGIT5  = wxID_HIGHEST + 110;
const int ID_DIGIT6  = wxID_HIGHEST + 111;
const int ID_MINUS   = wxID_HIGHEST + 112;
const int ID_DIGIT1  = wxID_HIGHEST + 113;
const int ID_DIGIT2  = wxID_HIGHEST + 114;
const int ID_DIGIT3  = wxID_HIGHEST + 115;
const int ID_PLUS    = wxID_HIGHEST + 116;
const int ID_DIGIT0  = wxID_HIGHEST + 117;
const int ID_DECIMAL = wxID_HIGHEST + 118;
const int ID_EQUALS  = wxID_HIGHEST + 119;

#endif