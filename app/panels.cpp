#include <wx/stattext.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>

#include "appframe.h"

#include "../assets/_5a5c5c.png.h"
#include "../assets/_7b7b7c.png.h"
#include "../assets/_fca00b.png.h"
#include "../assets/btn_ac.png.h"
#include "../assets/btn_decimal.png.h"
#include "../assets/btn_digit0.png.h"
#include "../assets/btn_digit0_span2.png.h"
#include "../assets/btn_digit1.png.h"
#include "../assets/btn_digit2.png.h"
#include "../assets/btn_digit3.png.h"
#include "../assets/btn_digit4.png.h"
#include "../assets/btn_digit5.png.h"
#include "../assets/btn_digit6.png.h"
#include "../assets/btn_digit7.png.h"
#include "../assets/btn_digit8.png.h"
#include "../assets/btn_digit9.png.h"
#include "../assets/btn_divide.png.h"
#include "../assets/btn_equals.png.h"
#include "../assets/btn_minus.png.h"
#include "../assets/btn_modulo.png.h"
#include "../assets/btn_mul.png.h"
#include "../assets/btn_plus.png.h"
#include "../assets/btn_sign.png.h"
#include "../assets/btn_times.png.h"

KeypadControl::KeypadControl(wxWindow * parent)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxNO_BORDER|wxWANTS_CHARS)
{
  m_parent = parent;

  SetBackgroundColour(wxColour(57, 57, 57));

  m_sizer = new wxGridBagSizer(2, 2);

  m_sizer->SetEmptyCellSize(wxSize(50, 50));

  //
  // NOTE:
  //
  // wxGridBagSizer incorrectly positions columns if the size on the buttons is not set explicitly.
  //
  // wxGridSizer positions columns correctly using the default size wxSize(-1, -1).
  //
  m_btn_ac      = new wxButton(this, ID_AC      , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_sign    = new wxButton(this, ID_SIGN    , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_modulo  = new wxButton(this, ID_MODULO  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_divide  = new wxButton(this, ID_DIVIDE  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit7  = new wxButton(this, ID_DIGIT7  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit8  = new wxButton(this, ID_DIGIT8  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit9  = new wxButton(this, ID_DIGIT9  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_times   = new wxButton(this, ID_TIMES   , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit4  = new wxButton(this, ID_DIGIT4  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit5  = new wxButton(this, ID_DIGIT5  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit6  = new wxButton(this, ID_DIGIT6  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_minus   = new wxButton(this, ID_MINUS   , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit1  = new wxButton(this, ID_DIGIT1  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit2  = new wxButton(this, ID_DIGIT2  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit3  = new wxButton(this, ID_DIGIT3  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_plus    = new wxButton(this, ID_PLUS    , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_digit0  = new wxButton(this, ID_DIGIT0  , wxT(""),   wxPoint(-1, -1), wxSize(102, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_decimal = new wxButton(this, ID_DECIMAL , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);
  m_btn_equals  = new wxButton(this, ID_EQUALS  , wxT(""),   wxPoint(-1, -1), wxSize(50, 50), wxTRANSPARENT_WINDOW|wxNO_BORDER|wxBU_NOTEXT);

  wxBitmap bitmap_ac = wxBITMAP_PNG_FROM_DATA(btn_ac);
  m_btn_ac->SetBitmap(bitmap_ac);

  wxBitmap bitmap_sign = wxBITMAP_PNG_FROM_DATA(btn_sign);
  m_btn_sign->SetBitmap(bitmap_sign);

  wxBitmap bitmap_modulo = wxBITMAP_PNG_FROM_DATA(btn_modulo);
  m_btn_modulo->SetBitmap(bitmap_modulo);
  
  wxBitmap bitmap_divide = wxBITMAP_PNG_FROM_DATA(btn_divide);
  m_btn_divide->SetBitmap(bitmap_divide);

  wxBitmap bitmap_digit7 = wxBITMAP_PNG_FROM_DATA(btn_digit7);
  m_btn_digit7->SetBitmap(bitmap_digit7);

  wxBitmap bitmap_digit8 = wxBITMAP_PNG_FROM_DATA(btn_digit8);
  m_btn_digit8->SetBitmap(bitmap_digit8);

  wxBitmap bitmap_digit9 = wxBITMAP_PNG_FROM_DATA(btn_digit9);
  m_btn_digit9->SetBitmap(bitmap_digit9);

  wxBitmap bitmap_times = wxBITMAP_PNG_FROM_DATA(btn_times);
  m_btn_times->SetBitmap(bitmap_times);

  wxBitmap bitmap_digit4 = wxBITMAP_PNG_FROM_DATA(btn_digit4);
  m_btn_digit4->SetBitmap(bitmap_digit4);

  wxBitmap bitmap_digit5 = wxBITMAP_PNG_FROM_DATA(btn_digit5);
  m_btn_digit5->SetBitmap(bitmap_digit5);

  wxBitmap bitmap_digit6 = wxBITMAP_PNG_FROM_DATA(btn_digit6);
  m_btn_digit6->SetBitmap(bitmap_digit6);

  wxBitmap bitmap_minus = wxBITMAP_PNG_FROM_DATA(btn_minus);
  m_btn_minus->SetBitmap(bitmap_minus);

  wxBitmap bitmap_digit1 = wxBITMAP_PNG_FROM_DATA(btn_digit1);
  m_btn_digit1->SetBitmap(bitmap_digit1);

  wxBitmap bitmap_digit2 = wxBITMAP_PNG_FROM_DATA(btn_digit2);
  m_btn_digit2->SetBitmap(bitmap_digit2);

  wxBitmap bitmap_digit3 = wxBITMAP_PNG_FROM_DATA(btn_digit3);
  m_btn_digit3->SetBitmap(bitmap_digit3);

  wxBitmap bitmap_plus = wxBITMAP_PNG_FROM_DATA(btn_plus);
  m_btn_plus->SetBitmap(bitmap_plus);

  wxBitmap bitmap_digit0 = wxBITMAP_PNG_FROM_DATA(btn_digit0_span2);
  m_btn_digit0->SetBitmap(bitmap_digit0);

  wxBitmap bitmap_decimal = wxBITMAP_PNG_FROM_DATA(btn_decimal);
  m_btn_decimal->SetBitmap(bitmap_decimal);

  wxBitmap bitmap_equals = wxBITMAP_PNG_FROM_DATA(btn_equals);
  m_btn_equals->SetBitmap(bitmap_equals);

  int flag = wxEXPAND;
  int border = 0;

  // AC +/- % /

  m_sizer->Add(m_btn_ac,      wxGBPosition(0, 0), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_sign,    wxGBPosition(0, 1), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_modulo,  wxGBPosition(0, 2), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_divide,  wxGBPosition(0, 3), wxGBSpan(1, 1), flag, border);

  // 7 8 9 *

  m_sizer->Add(m_btn_digit7,  wxGBPosition(1, 0), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit8,  wxGBPosition(1, 1), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit9,  wxGBPosition(1, 2), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_times,   wxGBPosition(1, 3), wxGBSpan(1, 1), flag, border);

  // 4 5 6 -

  m_sizer->Add(m_btn_digit4,  wxGBPosition(2, 0), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit5,  wxGBPosition(2, 1), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit6,  wxGBPosition(2, 2), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_minus,   wxGBPosition(2, 3), wxGBSpan(1, 1), flag, border);

  // 1 2 3 +

  m_sizer->Add(m_btn_digit1,  wxGBPosition(3, 0), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit2,  wxGBPosition(3, 1), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_digit3,  wxGBPosition(3, 2), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_plus,    wxGBPosition(3, 3), wxGBSpan(1, 1), flag, border);

  // 0 . =

  m_sizer->Add(m_btn_digit0,  wxGBPosition(4, 0), wxGBSpan(1, 2), flag, border);
  m_sizer->Add(m_btn_decimal, wxGBPosition(4, 2), wxGBSpan(1, 1), flag, border);
  m_sizer->Add(m_btn_equals,  wxGBPosition(4, 3), wxGBSpan(1, 1), flag, border);

  Connect(ID_AC,      wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnAC));
  Connect(ID_SIGN,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnSign));
  Connect(ID_MODULO,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnModulo));
  Connect(ID_DIVIDE,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDivide));
  Connect(ID_DIGIT7,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit7));
  Connect(ID_DIGIT8,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit8));
  Connect(ID_DIGIT9,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit9));
  Connect(ID_TIMES,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnTimes));
  Connect(ID_DIGIT4,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit4));
  Connect(ID_DIGIT5,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit5));
  Connect(ID_DIGIT6,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit6));
  Connect(ID_MINUS,   wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnMinus));
  Connect(ID_DIGIT1,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit1));
  Connect(ID_DIGIT2,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit2));
  Connect(ID_DIGIT3,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit3));
  Connect(ID_PLUS,    wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnPlus));
  Connect(ID_DIGIT0,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDigit0));
  Connect(ID_DECIMAL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnDecimal));
  Connect(ID_EQUALS,  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(KeypadControl::OnEquals));

  SetSizer(m_sizer);
}

wxString KeypadControl::GetAccumulator() {
  AppFrame *appframe = (AppFrame *) m_parent->GetParent();
  return appframe->m_display->GetValue();
}

void KeypadControl::UpdateDisplay(const wxString &label) {
  AppFrame *appframe = (AppFrame *) m_parent->GetParent();

  if (label.IsSameAs(wxT("0"))) {
    appframe->m_display->SetDefault();
  }

  return appframe->m_display->UpdateValue(label);
}

void KeypadControl::SetStatus(const wxString &label) {
  AppFrame *appframe = (AppFrame *) m_parent->GetParent();
  return appframe->SetStatusText(label);
}

void KeypadControl::StoreResult() {
  wxString label = GetAccumulator();

  m_calculator.StoreResult(label.ToAscii());
}

void KeypadControl::OnDigit(const char* value) {
  wxString label = (m_calculator.IsResult() ? wxT("") : GetAccumulator());
  m_calculator.SetResultFalse();
  label.Append(value);
  UpdateDisplay(label);
}

void KeypadControl::OnAC(wxCommandEvent & WXUNUSED(event)) {
  m_calculator.ClearAll();
  UpdateDisplay(wxT("0"));
  SetStatus("");
}

void KeypadControl::OnSign(wxCommandEvent & WXUNUSED(event))
{
  wxString label = GetAccumulator();
  if (label.IsSameAs(wxT("0"))) {
    ; // do nothing
  }
  else if (label.IsSameAs(wxT("0.0"))) {
    ; // do nothing
  }
  else if (label.StartsWith(wxT("-"))) {
    label.Replace(wxT("-"), wxT(""), false);
  }
  else {
    label.Prepend("-");
  }
  UpdateDisplay(label);
}

void KeypadControl::OnModulo(wxCommandEvent & WXUNUSED(event))
{
  StoreResult();
  m_calculator.OnModulo();
}

void KeypadControl::OnDivide(wxCommandEvent & WXUNUSED(event))
{
  StoreResult();
  m_calculator.OnDivide();
}

void KeypadControl::OnDigit7(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("7");
}

void KeypadControl::OnDigit8(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("8");
}

void KeypadControl::OnDigit9(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("9");
}

void KeypadControl::OnTimes(wxCommandEvent & WXUNUSED(event))
{
  StoreResult();
  m_calculator.OnTimes();
}

void KeypadControl::OnDigit4(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("4");
}

void KeypadControl::OnDigit5(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("5");
}

void KeypadControl::OnDigit6(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("6");
}

void KeypadControl::OnMinus(wxCommandEvent & WXUNUSED(event))
{
  StoreResult();
  m_calculator.OnMinus();
}

void KeypadControl::OnDigit1(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("1");
}

void KeypadControl::OnDigit2(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("2");
}

void KeypadControl::OnDigit3(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("3");
}

void KeypadControl::OnPlus(wxCommandEvent & WXUNUSED(event))
{
  StoreResult();
  m_calculator.OnPlus();
}

void KeypadControl::OnDigit0(wxCommandEvent & WXUNUSED(event))
{
  OnDigit("0");
}

void KeypadControl::OnDecimal(wxCommandEvent & WXUNUSED(event))
{
  wxString label = (m_calculator.IsResult() ? wxT("0") : GetAccumulator());
  m_calculator.SetResultFalse();
  label.Append(".");
  UpdateDisplay(label);
}

void KeypadControl::OnEquals(wxCommandEvent & WXUNUSED(event))
{
  wxString label = GetAccumulator();

  m_calculator.CalculateResult(label.ToAscii());
  m_calculator.SetResultTrue();

  if (m_calculator.IsDivideByZero()) {
    UpdateDisplay(wxT(""));
    SetStatus( "Divide by zero!" );
  }
  else {
    UpdateDisplay(wxString(m_calculator.GetResult()));
  }
}

void DisplayControl::SetDefault()
{
  wxFont font(wxFontInfo(50).FaceName("Helvetica"));
  wxTextAttr attr(wxColour(255, 255, 255), wxColour(57, 57, 57), font);

  SetBackgroundColour(wxColour(57, 57, 57));
  SetForegroundColour(wxColour(255, 255, 255));
  SetFont(font);
  SetDefaultStyle(attr);
}

DisplayControl::DisplayControl(wxWindow * parent)
       : wxTextCtrl(parent, -1, wxT("0"), wxPoint(-1, -1), wxSize(-1, 50), wxNO_BORDER|wxTE_RIGHT|wxTE_READONLY|wxTE_RICH)
{
  SetDefault();
}

#define ANTI_CLIPPING_CONSTANT	35
void DisplayControl::UpdateValue(wxString str)
{
  wxSize	strSize;
  int	wX, wY;
  int	strX, strY;
  wxFont	font;
  int	pointSize;
  wxTextAttr	attr;

  font = GetFont();

  GetTextExtent(str, &strX, &strY, NULL, NULL, &font);

  GetClientSize(&wX, &wY);

  if (strX > wX)
  {
    do {
      pointSize = font.GetPointSize() - 1;
      font.SetPointSize(pointSize);
      GetTextExtent(str, &strX, &strY, NULL, NULL, &font);
    } while ((strX+ANTI_CLIPPING_CONSTANT) > wX);

    {
      wxFont font(wxFontInfo(pointSize).FaceName("Helvetica"));
      wxTextAttr attr(wxColour(255, 255, 255), wxColour(57, 57, 57), font);
      SetDefaultStyle(attr);
    }
    SetFont(font);
  }

  SetValue(str);
}