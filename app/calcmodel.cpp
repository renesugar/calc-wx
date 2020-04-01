/*

Copyright 2019 Rene Sugar

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "calcmodel.h"

CalcModel::CalcModel() {
  m_result.SetZero();
  m_func   = FN_PLUS;
  m_DivByZero = false;
  m_isResult = true;
}

void CalcModel::CalculateResult(const char* value) {
  MyBig accumulator;
  uint status = 0;
  m_DivByZero = false;

  accumulator.SetZero();
  accumulator.FromString(value);

  switch (m_func)
  {
  case FN_PLUS:
    status = m_result.Add(accumulator);

    m_Carry = false;
    m_DivByZero = false;
    m_InvalidArgument = false;

    if (status == 1) {
      m_Carry = true;
    } else if (status == 2) {
      m_InvalidArgument = true;
    }
    break;
  case FN_MINUS:
    m_result = m_result - accumulator;
    break;
  case FN_TIMES:
    m_result = m_result * accumulator;
    break;
  case FN_MODULO:
    if (accumulator != 0) {
      status = m_result.Mod(accumulator);

      m_Carry = false;
      m_DivByZero = false;
      m_InvalidArgument = false;

      if (status == 1) {
        m_Carry = true;
      } else if (status == 2) {
        m_InvalidArgument = true;
      }
    }
    else {
      m_DivByZero = true;
      m_result.SetZero();
    }
    break;
  case FN_DIVIDE:
    if (accumulator != 0) {
      m_result = m_result / accumulator;
    }
    else {
      m_DivByZero = true;
      m_result.SetZero();
    }
    break;
  default:
    break;
  }
}

void CalcModel::StoreResult(const char* value) {
  m_result.SetZero();
  m_result.FromString(value);
}

std::wstring CalcModel::GetResult() {
  return m_result.ToWString();
}

void CalcModel::ClearAll()
{
  m_result.SetZero();
  m_func = FN_PLUS;
  m_isResult = true;
}

void CalcModel::OnModulo()
{
  m_func = FN_MODULO;
  m_isResult = true;
}

void CalcModel::OnDivide()
{
  m_func = FN_DIVIDE;
  m_isResult = true;
}

void CalcModel::OnTimes()
{
  m_func = FN_TIMES;
  m_isResult = true;
}

void CalcModel::OnMinus()
{
  m_func = FN_MINUS;
  m_isResult = true;
}

void CalcModel::OnPlus()
{
  m_func = FN_PLUS;
  m_isResult = true;
}

bool CalcModel::IsDivideByZero() {
  return m_DivByZero;
}

bool CalcModel::IsResult() {
  return m_isResult;
}

void CalcModel::SetResultFalse() {
  m_isResult = false;
}

void CalcModel::SetResultTrue() {
  m_isResult = true;
}