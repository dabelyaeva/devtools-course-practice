// Copyright 2016 Magaziinik Ivan

#include <gtest/gtest.h>

#include "include/mine_sweeper.h"

TEST(MINEsweeper, can_create) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();

    // Assert
    EXPECT_NE(nullptr, game);
    delete game;
}

TEST(MINEsweeper, throwing_when_initialise_with_wrong_mine_count) {
    // Arrange & Act & Assert
    EXPECT_THROW(MineSweeper(10, 100), std::invalid_argument);
}

TEST(MINEsweeper, can_get_status) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_START, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_finalise_game) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;
    // Act
    game = new MineSweeper(10, 10, 1);
    game->OpenCell(0, 0);
    game->OpenCell(mine_x_pos, mine_y_pos);
    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_LOSE, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_get_opened_field_cell) {
    // Arrange
    MineSweeper* game;
    unsigned int x = 0;
    unsigned int y = 0;

    // Act
    game = new MineSweeper();
    game->OpenCell(x, y);
    unsigned int value = game->get_opened_field_cell(x, y);

    // Assert
    EXPECT_NE(MineSweeper::CLOSED_CELL, value);
    delete game;
}

TEST(MINEsweeper, throw_when_continue_game_after_ends) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;

    // Act
    game = new MineSweeper(10, 10, 1);
    game->OpenCell(0, 0);
    game->OpenCell(mine_x_pos, mine_y_pos);

    // Assert
    EXPECT_THROW(game->OpenCell(1, 1), std::invalid_argument);
    delete game;
}

TEST(MINEsweeper, throws_when_try_to_open_opened_cell) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();
    game->OpenCell(0, 0);
    // Assert
    EXPECT_THROW(game->OpenCell(0, 0), std::invalid_argument);
    delete game;
}

bool is_in_massive(int x, int y, int size) {
    int x_mine_poses[10] = {7, 2, 4, 3, 2, 4, 4, 6, 1, 9};
    int y_mine_poses[10] = {1, 2, 2, 3, 4, 3, 9, 7, 6, 1};
    for (int i = 0; i < size; ++i) {
        if (x == x_mine_poses[i] && y == y_mine_poses[i]) {
            return true;
        }
    }
    return false;
}

void win_game(MineSweeper* game, int size) {
    game->OpenCell(0, 0);
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            if (is_in_massive(x, y, size)) {
                continue;
            } else {
                if (x == 0 && y == 0) {
                    continue;
                } else {
                    try {
                        game->OpenCell(x, y);
                    }
                    catch (std::invalid_argument) {
                        continue;
                    }
                }
            }
        }
    }
}

TEST(MINEsweeper, can_win_game) {
    // Arrange
    MineSweeper* game;
    int size = 10;

    // Act
    game = new MineSweeper(size, size, 1);
    win_game(game, size);

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_WIN, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_get_played_status) {
    // Arrange
    MineSweeper* game;

    // Act
    game = new MineSweeper();
    game->OpenCell(1, 1);

    // Assert
    EXPECT_EQ(MineSweeper::GAME_STATUS_PLAYING, game->get_game_status());
    delete game;
}

TEST(MINEsweeper, can_get_opened_fild_fill) {
    // Arrange
    MineSweeper* game;
    unsigned int x = 1;
    unsigned int y = 1;
    unsigned int expected_val = 0;
    // Act
    game = new MineSweeper();
    game->OpenCell(x, y);

    // Assert
    EXPECT_NE(expected_val, game->get_opened_field_cell(x, y));
    delete game;
}

TEST(MINEsweeper, can_get_opened_field) {
    // Arrange
    MineSweeper* game;
    unsigned int x = 1;
    unsigned int y = 1;

    // Act
    game = new MineSweeper();
    game->OpenCell(x, y);
    Field opened_field = game->get_opened_field();
    delete game;

    // Assert
    EXPECT_NE(MineSweeper::CLOSED_CELL, opened_field.get_cell(x, y));
}

TEST(MINEsweeper, is_field_open_correctly_after_mine) {
    // Arrange
    MineSweeper* game;
    unsigned int mine_x_pos = 1;
    unsigned int mine_y_pos = 6;
    unsigned int game_mine_count = 10;
    unsigned int mine_count = 0;
    // Act
    game = new MineSweeper(10, game_mine_count, 1);
    game->OpenCell(0, 0);
    game->OpenCell(mine_x_pos, mine_y_pos);
    Field opened_field = game->get_opened_field();

    for (unsigned int i = 0; i < opened_field.get_field_size(); ++i) {
        for (unsigned int j = 0; j < opened_field.get_field_size(); ++j) {
            if (opened_field.get_cell(i, j) == MineSweeper::MINE) {
                if (is_in_massive(i, j, opened_field.get_field_size())) {
                    mine_count++;
                }
            }
        }
    }
    // Assert
    EXPECT_EQ(game_mine_count, mine_count);
    delete game;
}

TEST(MINEsweeper, is_field_cells_open_correctly_if_empty_is_near) {
    // Arrange
    MineSweeper* game;
    unsigned int expected_val = 2;
    unsigned int expected_val_x_pos = 3;
    unsigned int expected_val_y_pos = 1;

    // Act
    game = new MineSweeper(10, 10, 1);
    game->OpenCell(0, 0);

    // Assert
    EXPECT_EQ(expected_val,
              game->get_opened_field_cell(expected_val_x_pos,
                                          expected_val_y_pos));
}
