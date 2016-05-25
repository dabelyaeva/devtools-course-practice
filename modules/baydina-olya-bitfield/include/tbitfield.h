// Copyright 2016 Baydina Olya

#ifndef MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TBITFIELD_H_
#define MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TBITFIELD_H_

#include <iostream>
#include <string>
using std::string;

typedef unsigned int TELEM;

class TBitField {
 public:
    explicit TBitField(int len);
    TBitField(const TBitField &bf);
    ~TBitField();

    int   GetMemIndex(const int n) const;
    TELEM GetMemMask(const int n) const;
    int GetMemLen(void) const;
    int GetLength(void) const;
    void SetBit(const int n);
    void ClrBit(const int n);
    int  GetBit(const int n) const;

    bool operator==(const TBitField &bf) const;
    bool operator!=(const TBitField &bf) const;
    TBitField& operator=(const TBitField &bf);
    TBitField  operator|(const TBitField &bf);
    TBitField  operator&(const TBitField &bf);
    TBitField  operator~(void);
 private:
    int  BitLen;
    TELEM *pMem;
    int  MemLen;
};

#endif  // MODULES_BAYDINA_OLYA_BITFIELD_INCLUDE_TBITFIELD_H_
