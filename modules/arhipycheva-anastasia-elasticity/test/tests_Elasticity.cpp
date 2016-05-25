// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "TElasticity.h"
using TElasticity::CODE_ERROR;
using TElasticity::ElasticityByPricePointDo;
using TElasticity::ElasticityByPriceArcDo;
using TElasticity::ElasticityByIncomeDo;
using TElasticity::ElasticityCrossDo;
using TElasticity::ElasticityByPricePoint;
using TElasticity::ElasticityByPriceArc;
using TElasticity::ElasticityByIncome;
using TElasticity::ElasticityCross;



TEST(TElasticity, ElasticityByPricePointDo_When_Null_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 0;
  const float P1 = 10, P0 = 5;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_2_var) {
  // Arrange
  const int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_3_var) {
  // Arrange
  const int Q1 = 10, Q0 = 0, P1 = 10, P0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_1_var) {
  // Arrange
  const int Q1 = 0, Q0 = 0, P1 = 10, P0 = 5;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_2_var) {
  // Arrange
  const int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_3_var) {
  // Arrange
  const int Q1 = 0, Q0 = 0, P1 = 10, P0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 0, I1 = 10, I0 = 5;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_2_var) {
  // Arrange
  const int Q1 = 10, Q0 = 5, I1 = 10, I0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_3_var) {
  // Arrange
  const int Q1 = 10, Q0 = 0, I1 = 10, I0 = 10;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_1_var) {
  // Arrange
  const int QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 5;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_2_var) {
  // Arrange
  const int  QA1 = 10, QA0 = 5, PB1 = 10, PB0 = 0;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_3_var) {
  // Arrange
  const int  QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 0;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10, P0 = 5;
  float rezult;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 100, P0 = 100;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  EXPECT_EQ(-2, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_4_var) {
  // Arrange
  const int Q1 = 100, Q0 = 100;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  EXPECT_EQ(0, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_5_var) {
  // Arrange
  const int Q1 = 0, Q0 = 10;
  const float P1 = 2, P0 = 1;

  // Act & Assert
  EXPECT_EQ(-1, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10, P0 = 5;
  float rezult;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 100, P0 = 100;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 90, P0 = 100;
  float rezult;

  // Act & Assert
  rezult = -19 / 11;
  EXPECT_EQ(rezult, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_4_var) {
  // Arrange
  const int Q1 = 100, Q0 = 100;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  EXPECT_EQ(0, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_5_var) {
  // Arrange
  const int Q1 = 20, Q0 = 10;
  const float P1 = 20, P0 = 10;

  // Act & Assert
  EXPECT_EQ(1, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_6_var) {
  // Arrange
  const int Q1 = 20, Q0 = 10;
  const float P1 = 30, P0 = 20;
  float rezult;

  // Act & Assert
  rezult = 5 / 3;
  EXPECT_EQ(rezult, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float I1 = 10, I0 = 5;
  float rezult;

  // Act & Assert
  rezult = -1 / 2;
  EXPECT_EQ(rezult, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 100, I0 = 100;

  // Act & Assert
  EXPECT_EQ(CODE_ERROR, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 90, I0 = 100;
  float rezult;

  // Act & Assert
  rezult = -2;
  EXPECT_EQ(rezult, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_4_var) {
  // Arrange
  const int Q1 = 10, Q0 = 10;
  const float I1 = 90, I0 = 100;

  // Act & Assert
  EXPECT_EQ(0, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_5_var) {
  // Arrange
  const int Q1 = 15, Q0 = 10;
  const float I1 = 10, I0 = 5;
  float rezult;

  // Act & Assert
  rezult = 1 / 2;
  EXPECT_EQ(rezult, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_6_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 100, I0 = 90;
  float rezult;

  // Act & Assert
  rezult = 9 / 5;
  EXPECT_EQ(rezult, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_1_var) {
  // Arrange
  const int QA1 = 10, QA0 = 15;
  const float PB1 = 10, PB0 = 5;
  float rezult;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_2_var) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 100, PB0 = 100;

  // Act & Assert
  EXPECT_EQ(0, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_3_var) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 90, PB0 = 100;
  float rezult;

  // Act & Assert
  rezult = -1 / 50;
  EXPECT_EQ(rezult, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePointDo_With_float_P) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10.5, P0 = 5.25;
  float rezult;

  // Act & Assert
  rezult = -1 / 2;
  EXPECT_EQ(rezult, ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_With_float_P) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10.5, P0 = 5.25;
  float rezult;

  // Act & Assert
  rezult = -3 / 5;
  EXPECT_EQ(rezult, ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_With_float_P) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float I1 = 10.25, I0 = 20.50;
  float rezult;

  // Act & Assert
  rezult = 2 / 3;
  EXPECT_EQ(rezult, ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_With_float_P) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 100.5, PB0 = 75.25;
  float rezult;

  // Act & Assert
  rezult = 101 / 1505;
  EXPECT_EQ(rezult, ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10, P0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 100, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_4_var) {
  // Arrange
  const int Q1 = 100, Q0 = 100;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_5_var) {
  // Arrange
  const int Q1 = 0, Q0 = 10;
  const float P1 = 2, P0 = 1;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePoint_IsThatFunctionWorks_6_var) {
  // Arrange
  const int Q1 = 75, Q0 = 50;
  const float P1 = 0, P0 = 10;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPricePoint(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float P1 = 10, P0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 100, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_4_var) {
  // Arrange
  const int Q1 = 100, Q0 = 100;
  const float P1 = 90, P0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_5_var) {
  // Arrange
  const int Q1 = 20, Q0 = 10;
  const float P1 = 20, P0 = 10;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArc_IsThatFunctionWorks_6_var) {
  // Arrange
  const int Q1 = 20, Q0 = 10;
  const float P1 = 30, P0 = 20;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByPriceArc(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_1_var) {
  // Arrange
  const int Q1 = 10, Q0 = 15;
  const float I1 = 10, I0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_2_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 100, I0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_3_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 90, I0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_4_var) {
  // Arrange
  const int Q1 = 10, Q0 = 10;
  const float I1 = 90, I0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_5_var) {
  // Arrange
  const int Q1 = 15, Q0 = 10;
  const float I1 = 10, I0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_6_var) {
  // Arrange
  const int Q1 = 3000, Q0 = 2500;
  const float I1 = 100, I0 = 90;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncome_IsThatFunctionWorks_7_var) {
  // Arrange
  const int Q1 = 100, Q0 = 50;
  const float I1 = 30, I0 = 10;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityByIncome(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_1_var) {
  // Arrange
  const int QA1 = 10, QA0 = 15;
  const float PB1 = 10, PB0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_2_var) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 100, PB0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_3_var) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 90, PB0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_4_var) {
  // Arrange
  const int QA1 = 3000, QA0 = 2500;
  const float PB1 = 100.5, PB0 = 75.25;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_5_var) {
  // Arrange
  const int QA1 = 50, QA0 = 25;
  const float PB1 = 0, PB0 = 5;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_6_var) {
  // Arrange
  const int QA1 = 110, QA0 = 10;
  const float PB1 = 20, PB0 = 10;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCross_IsThatFunctionWorks_7_var) {
  // Arrange
  const int QA1 = 1000, QA0 = 250;
  const float PB1 = 200, PB0 = 100;

  // Act & Assert
  ASSERT_NO_THROW(ElasticityCross(QA1, QA0, PB1, PB0));
}
