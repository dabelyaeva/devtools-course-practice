// Copyright 2016 Baydina Olya

#include "gtest/gtest.h"
#include "include/tbitfield.h"


TEST(TBitField, any_throw_with_negative_length) {
    // Act & Assert
    EXPECT_ANY_THROW(TBitField bf(-1));
}

TEST(TBitField, when_len_is_positive) {
    // Act & Assert
    ASSERT_NO_THROW(TBitField field(5));
}

TEST(TBitField, get_mem_index) {
    // Arrange
    const int n = 32;
    TBitField field(n);

    // Act & Assert
    EXPECT_EQ(1, field.GetMemIndex(32));
}

TEST(TBitField, get_length) {
    // Arrange
    int len = 3;
    TBitField field(len);

    // Act & Assert
    EXPECT_EQ(3, field.GetLength());
}

TEST(TBitField, copy_test) {
    // Arrange
    TBitField field(10);
    field.SetBit(2);
    TBitField bf = field;

    // Act & Assert
    EXPECT_NE(0, bf.GetBit(2));
}

TEST(TBitField, any_throw_2) {
    // Arrange
    TBitField field(10);

    // Act & Assert
    EXPECT_ANY_THROW(field.SetBit(-1));
}

TEST(TBitField, throws_when_set_bit_with_too_large_index) {
    // Arrange
    TBitField bf(10);

    // Act & Assert
    ASSERT_ANY_THROW(bf.SetBit(11));
}

TEST(TBitField, throw1_in_Clr) {
    // Arrange
    TBitField field(10);

    // Act & Assert
    EXPECT_ANY_THROW(field.ClrBit(-1));
}

TEST(TBitField, throw2_in_Clr) {
    // Arrange
    TBitField field(10);

    // Act & Assert
    EXPECT_ANY_THROW(field.ClrBit(11));
}

TEST(TBitField, set_to_zero) {
    // Arrange
    TBitField bf(100);
    int sum = 0;

    // Act
    for (int i = 0; i < bf.GetLength(); i++) {
        sum += bf.GetBit(i);
    }

    // Assert
    EXPECT_EQ(0, sum);
}

TEST(TBitField, any_throw_in_GetBit_with_negative_index) {
    // Arrange
    TBitField field(10);

    // Act & Assert
    EXPECT_ANY_THROW(field.GetBit(-1));
}

TEST(TBitField, throws_when_get_bit_with_too_large_index) {
    // Arrange
    TBitField bf(10);
    // Act & Assert
    ASSERT_ANY_THROW(bf.GetBit(11));
}

TEST(TBitField, is_equally) {
    // Arrange
    TBitField a(8);
    TBitField b(8);

    // Act
    bool result = (a == b);

    // Assert
    EXPECT_TRUE(result);
}

TEST(TBitField, is_not_equally) {
    // Arrange
    TBitField a(8);
    TBitField b(9);

    // Act
    bool result = (a == b);

    // Assert
    EXPECT_FALSE(result);
}

TEST(TBitField, is_equally_Getbit) {
    // Arrange
    TBitField a(3);
    TBitField b(3);

    // Act
    a.SetBit(0);
    a.SetBit(1);
    b.SetBit(0);
    b.SetBit(1);
    b.SetBit(2);
    bool result = (a == b);

    // Assert
    EXPECT_FALSE(result);
}

TEST(TBitField, is_not_equally_true) {
    // Arrange
    TBitField a(8);
    TBitField b(9);

    // Act
    bool result = (a != b);

    // Assert
    EXPECT_TRUE(result);
}

TEST(TBitField, is_not_equally_false) {
    // Arrange
    TBitField a(9);
    TBitField b(9);

    // Act
    bool result = (a != b);

    // Assert
    EXPECT_FALSE(result);
}

TEST(TBitField, is_not_equally_Getbit) {
    // Arrange
    TBitField a(3);
    TBitField b(3);

    // Act
    a.SetBit(0);
    a.SetBit(1);
    b.SetBit(0);
    b.SetBit(1);
    b.SetBit(2);
    bool result = (a != b);

    // Assert
    EXPECT_TRUE(result);
}

TEST(TBitField, is_equally_if_the_same_bf) {
    // Arrange
    TBitField bf(10);

    // Act
    bool result = (bf == bf);

    // Assert
    EXPECT_TRUE(result);
}

TEST(TBitField, is_not_equally_if_the_same_bf) {
    // Arrange
    TBitField bf(10);

    // Act
    bool result = (bf != bf);

    // Assert
    EXPECT_FALSE(result);
}

TEST(TBitField, Disjunction) {
    // Arrange
    const int size = 3;
    TBitField bf1(size), bf2(size), expField(size);
    bf1.SetBit(2);
    bf1.SetBit(3);
    bf2.SetBit(1);
    bf2.SetBit(3);

    // Act
    expField.SetBit(1);
    expField.SetBit(2);
    expField.SetBit(3);

    // Assert
    EXPECT_EQ(expField, bf1 | bf2);
}

TEST(TBitField, can_invert_large_bitfield) {
    // Arrange
    const int size = 30;
    TBitField field(size), negField(size), expNegField(size);
    field.SetBit(27);
    negField = ~field;

    // Act
    for (int i = 0; i < size; i++) {
        expNegField.SetBit(i);
    }
    expNegField.ClrBit(27);

    // Assert
    EXPECT_EQ(expNegField, negField);
}

TEST(TBitField, conjunction) {
    // Arrange
    const int size = 3;
    TBitField bf1(size), bf2(size), expField(size);
    bf1.SetBit(2);
    bf1.SetBit(3);
    bf2.SetBit(1);
    bf2.SetBit(3);

    // Act
    expField.SetBit(3);

    // Assert
    EXPECT_EQ(expField, bf1 & bf2);
}

TEST(TBitField, logical_negation) {
    // Arrange
    const int size = 3;
    TBitField bf(size);
    TBitField result(size);

    // Act
    bf.SetBit(2);
    result.SetBit(0);
    result.SetBit(1);

    // Assert
    EXPECT_EQ(result, ~bf);
}

TEST(TBitField, double_cleaning) {
    // Arrange
    const int size = 3;
    TBitField bf(size);
    bf.SetBit(1);
    bf.ClrBit(1);
    bf.ClrBit(1);

    // Act & Assert
    EXPECT_EQ(0, bf.GetBit(1));
}

TEST(TBitField, can_right_make_2_operation) {
    // Arrange
    TBitField first(3), second(3), third(3);
    TBitField tempSimp1(3), tempSimp2(3), tempNotSimple(3);
    first.SetBit(1);
    second.SetBit(2);
    third.SetBit(3);

    // Act
    tempSimp1 = first | second;
    tempSimp2 = tempSimp1 | third;
    tempNotSimple = first | second | third;

    // Assert
    EXPECT_EQ(tempSimp2, tempNotSimple);
}
