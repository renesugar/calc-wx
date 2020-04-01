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

#ifndef headerfilecalcmodel
#define headerfilecalcmodel

#include <ttmath/ttmath.h>

typedef ttmath::Big<TTMATH_BITS(64), TTMATH_BITS(128)> MyBig;

typedef enum CalcFunction {
  FN_NOP = 0,
  FN_MODULO,
  FN_DIVIDE,
  FN_TIMES,
  FN_MINUS,
  FN_PLUS
} CalcFunction;

class CalcModel
{
public:
    CalcModel();

    void CalculateResult(const char* value);
    void StoreResult(const char* value);
    std::wstring GetResult();
    void ClearAll();
    void OnModulo();
    void OnDivide();
    void OnTimes();
    void OnMinus();
    void OnPlus();

    bool IsDivideByZero();
    bool IsResult();
    void SetResultFalse();
    void SetResultTrue();

private:    
    MyBig m_result;
    bool  m_isResult;
    bool  m_DivByZero;
    bool  m_Carry;
    bool  m_InvalidArgument;
    CalcFunction   m_func;
};

#endif