// Copyright 2016 Magaziinik Ivan

#ifndef MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_FIELD_H_
#define MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_FIELD_H_

class Field {
 public:
    static const int MAX_FIELD_LEN;
    static const int MAX_FIELD_VALUE;

    explicit Field(unsigned int size = 10);
    Field(const Field &obj);
    ~Field();
    unsigned int get_field_size() const;
    unsigned int get_cell(unsigned int x, unsigned int y) const;
    void set_cell(unsigned int x, unsigned int y, unsigned int value);

 private:
    unsigned int **field;
    unsigned int field_size;
    void FillFieldWithZeroVal();
};


#endif  // MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_FIELD_H_
