// Copyright 2016 Baydina Olya

#include "include/tbitfield.h"
#include <string>
using std::string;

int BYTE = 8;

TBitField::TBitField(int len) {
    if (len <= 0) {
        throw 1;
    } else {
        BitLen = len;
        int tmp = len / (sizeof(TELEM) * BYTE);
        if (len % (sizeof(TELEM) * BYTE) == 0) {
            MemLen = tmp;
        } else {
            MemLen = tmp + 1;
        }
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = 0;
            }
        }
}

TBitField::TBitField(const TBitField &bf) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
        }
}

TBitField::~TBitField() {
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const {
    return (n / (sizeof(TELEM)*BYTE));
}

TELEM TBitField::GetMemMask(const int n) const {
    return (1 << n);
}

int TBitField::GetLength(void) const {
    return BitLen;
}

int TBitField::GetMemLen(void) const {
    return MemLen;
}

void TBitField::SetBit(const int n) {
    if (n < 0) {
        throw 1;
    } else {
        if (n > BitLen) {
            throw 2;
            } else {
                pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
                 }
    }
}

void TBitField::ClrBit(const int n) {
    if (n < 0) {
        throw 1;
    } else {
        if (n > BitLen) {
            throw 2;
        } else {
            pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~GetMemMask(n));
             }
    }
}

int TBitField::GetBit(const int n) const {
    if (n < 0) {
        throw 1;
    } else {
        if (n > BitLen) {
            throw 2;
        }
    }
      return((pMem[GetMemIndex(n)] & (GetMemMask(n))) >> n);
}

TBitField& TBitField::operator=(const TBitField &bf) {
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

bool TBitField::operator==(const TBitField &bf) const {
    if (this == &bf) {
        return true;
    } else {
        if (BitLen != bf.BitLen) {
            return false;
        }
    }
    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i) != bf.GetBit(i)) {
            return false;
        }
    }
    return true;
}

bool TBitField::operator!=(const TBitField &bf) const {
    if (this == &bf) {
        return false;
        } else {
            if (BitLen != bf.BitLen) {
                return true;
            }
        }
        for (int i = 0; i < BitLen; i++) {
            if (GetBit(i) != bf.GetBit(i)) {
                return true;
            }
        }
        return false;
}

TBitField TBitField::operator|(const TBitField &bf) {
    TBitField result((BitLen > bf.BitLen) ? BitLen : bf.BitLen);
    for (int i = 0; i < MemLen; i++) {
        result.pMem[i] = bf.pMem[i] | pMem[i];
    }
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) {
    TBitField result((BitLen > bf.BitLen) ? BitLen : bf.BitLen);
    for (int i = 0; i < MemLen; i++) {
        result.pMem[i] = bf.pMem[i] & pMem[i];
    }
    return result;
}

TBitField TBitField::operator~(void) {
    TBitField tempRes(BitLen);
    for (int i = 0; i < tempRes.GetMemLen(); i++) {
        tempRes.pMem[i] = ~pMem[i];
    }
    return tempRes;
}

