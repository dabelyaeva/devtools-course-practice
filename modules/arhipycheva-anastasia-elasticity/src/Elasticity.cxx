// Copyright 2016 Arhipycheva Anastasia

#include "TElasticity.h"

int TElasticity::ElasticityByPricePointDo(int Q1, int Q0, float P1, float P0) {
  if (((P1 - P0)*Q0) == 0) {
    return CODE_ERROR;  // error kod
  } else {
    float Elasticity = ((Q1 - Q0)*P0) / ((P1 - P0)*Q0);
    return Elasticity;
  }
}
int TElasticity::ElasticityByPriceArcDo(int Q1, int Q0, float P1, float P0) {
  if (((P1 - P0)*(Q1 + Q0)) == 0) {
    return CODE_ERROR;  // error kod
  } else {
    float Elasticity = ((Q1 - Q0)*(P1 + P0)) / ((P1 - P0)*(Q1 + Q0));
    return Elasticity;
  }
}
int TElasticity::ElasticityByIncomeDo(int Q1, int Q0, float I1, float I0) {
  if (((I1 - I0)*Q0) == 0) {
    return CODE_ERROR;  // error kod
  } else {
    float Elasticity = ((Q1 - Q0)*I0) / ((I1 - I0)*Q0);
    return Elasticity;
  }
}
int TElasticity::ElasticityCrossDo(int QA1, int QA0, float PB1, float PB0) {
  if ((PB0*QA0) == 0) {
    return CODE_ERROR;  // error kod
  } else {
    float Elasticity = ((QA1 - QA0)*(PB1 - PB0)) / (PB0*QA0);
    return Elasticity;
  }
}
void TElasticity::ElasticityByPricePoint(int Q1, int Q0, float P1, float P0) {
  float Elasticity = ElasticityByPricePointDo(Q1, Q0, P1, P0);
  cout << "Elasticity By Price Point = ";
  cout << Elasticity << endl;
  if (Elasticity == 0.0) {
    cout << " Perfectly inelastic demand" << endl;
    cout << "D does not change when the P changes: essential goods";
  }
  if (Elasticity == -1.0) {
    cout << "The unit elasticity of demand";
    cout << "D is proportional to the P";
  }
  if (Elasticity < -1.0) {
    cout << "Elastic demand" << endl;
    cout << "D fluctuates more than the P: the goods have a replacement ";
    cout << "or not play an important role for consumers";
  }
  cout << endl;
}
void TElasticity::ElasticityByPriceArc(int Q1, int Q0, float P1, float P0) {
  float Elasticity = ElasticityByPriceArcDo(Q1, Q0, P1, P0);
  cout << "Elasticity By Price Arc = ";
  cout << Elasticity << endl;
  if (Elasticity == 0.0) {
    cout << "It is quite inelastic demand ";
    cout << "- essential commodities (salt, matches); ";
  }
  if (Elasticity > 1.0) {
    cout << "Elastic demand" << endl;
    cout << "When a price change of 1 % the demand changes by more than 1 %. ";
    cout << "Falling prices will lead to increased revenues.";
  }
  if (Elasticity < 1.0) {
    cout << endl;
    cout << " Inelastic demand - when a price change of 1% of the demand";
    cout << " varies by less than 1%. Falling prices lead to lower revenues.";
  }
  if (Elasticity == 1.0) {
    cout << "The unit elasticity" << endl;
    cout << "Revenues maximum. When a price change of 1% of the demand ";
    cout << "for change is also 1%. Maximum revenue.";
  }
  cout << endl;
}
void TElasticity::ElasticityByIncome(int Q1, int Q0, float I1, float I0) {
  float Elasticity = ElasticityByIncomeDo(Q1, Q0, I1, I0);
  cout << "Elasticity By Income = ";
  cout << Elasticity << endl;
  if (Elasticity == 0.0) {
    cout << "Neutral benefit" << endl;
    cout << "There is no direct relationship between the ";
    cout << "consumption of goods and changes in I.";
  }
  if (Elasticity > 0.0) {
    cout << "Normal (full) benefit" << endl;
    cout << "Volume demand increases with the income of the consumer." << endl;
  }
  if (Elasticity > 1.0) {
    cout << "Subject luxury";
    cout << "Volume demand changes by a greater percentage than income";
  }
  if (Elasticity < 0.0) {
    cout << "Defective (lower) the benefit" << endl;
    cout << "Volume demand falls, the higher the income of ";
    cout << "the consumer. An example is the market barley consumption";
  }
  cout << endl;
}
void TElasticity::ElasticityCross(int QA1, int QA0, float PB1, float PB0) {
  float Elasticity = ElasticityCrossDo(QA1, QA0, PB1, PB0);
  cout << "Elasticity Cross = ";
  cout << Elasticity << endl;
  if (Elasticity == 0.0) {
    cout << "Independent of each other goods" << endl;
    cout << "Change in the price of goods B has no effect";
    cout << " on the consumption of goods A.";
  }
  if (Elasticity > 0.0) {
    cout << "Goods substitutes" << endl;
    cout << "Users could theoretically replace the consumption of goods A on ";
    cout << "the consumption of goods B. For example, two brands ";
    cout << "of washing powder";
  }
  if (Elasticity < 0.0) {
    cout << "Complementary benefits" << endl;
    cout << "Theoretically Consumers can not change the product A consumption";
    cout << "without changes in the same direction as the consumption ";
    cout << "of goods B. A good example - a laptop and accessories.";
  }
  cout << endl;
}

