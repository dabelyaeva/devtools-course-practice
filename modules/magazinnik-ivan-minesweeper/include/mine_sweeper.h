// Copyright 2016 Magaziinik Ivan

#ifndef MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_H_
#define MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_H_

#include <cstdlib>
#include <ctime>
#include "./mine_sweeper_field.h"

class MineSweeper{
 public:
    static const int GAME_STATUS_WIN;
    static const int GAME_STATUS_LOSE;
    static const int GAME_STATUS_PLAYING;
    static const int GAME_STATUS_START;
    static const unsigned int MINE;
    static const unsigned int CLOSED_CELL;
    static const unsigned int OPENED_CELL;

    MineSweeper(unsigned int game_size = 10,
                unsigned int mine_count = 10, bool is_static = false);
    ~MineSweeper();
    void OpenCell(unsigned int x, unsigned int y);
    int get_game_status() const;
    unsigned int get_opened_field_cell(unsigned int x, unsigned int y) const;
    Field get_opened_field() const;

 private:
    Field* game_field;
    Field* opened_field;
    int game_status;
    unsigned int mine_count;
    unsigned int random_seed;
    void PlaceMines(unsigned int curr_x, unsigned int curr_y);
    void FillGameFieldWithNumbers();
    void FinalizeGame();
    void clean(int x, int y);
    bool mine(int x, int y);
    bool empty(int x, int y);
    void CheckWin();
};

#endif  // MODULES_MAGAZINNIK_IVAN_MINESWEEPER_INCLUDE_MINE_SWEEPER_H_
