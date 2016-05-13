// Copyright 2016 Rumyantsev Alexander

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>

#include "include/application.h"

#include "include/currency_pair.h"
#include "include/currency_pair_holder.h"

Application::Application() : message_("") {
  // 13.05.2016
  // http://www.forexpf.ru/quote_show.php
  std::vector<CurrencyPair> currency_pairs{
    CurrencyPair("EUR/AUD", 1.55215, 1.55245),
    CurrencyPair("EUR/USD", 1.12870, 1.12885),
    CurrencyPair("EUR/JPY", 123.020, 123.040),
    CurrencyPair("EUR/RUB", 73.5166, 73.52),
    CurrencyPair("AUD/USD", 0.72710, 0.72725),
    CurrencyPair("AUD/JPY", 79.235, 79.260),
    CurrencyPair("AUD/RUB", 47.3487, 47.35),
    CurrencyPair("USD/JPY", 108.975, 108.990),
    CurrencyPair("USD/RUB", 64.0603, 66.0618),
    CurrencyPair("JPY/RUB", 1.67259, 1.673)
  };

  holder_ = new CurrencyPairHolder(currency_pairs);
}

Application::~Application() {
  delete holder_;
}

void Application::help(const std::string &appname, const std::string &message) {
  message_ = message +
    "This is a currency converter application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <base_currency> <counter_currency> <count>\n\n" +

    "Where <base_currency> and <counter_currency> are currency codes and " +
    "<count> is amount of <base_currency> you want to be converted to " +
    "<counter_currency>.\n\n" +
    "Currently supported currencies: EUR, AUD, USD, JPY, RUB.\n";
}

bool Application::validateNumberOfArguments(const int argc,
                                            const char* argv[]) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }
  return true;
}

double parseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);

  if (end[0]) {
    throw std::invalid_argument("Wrong number format");
  }

  return value;
}

std::string Application::operator()(const int argc, const char* argv[]) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  try {
    args.base_currency = argv[1];
    args.counter_currency = argv[2];
    args.count = parseDouble(argv[3]);
  }
  catch (const std::invalid_argument& ex) {
    return ex.what();
  }

  double cost = 0.0;

  try {
    cost = holder_->exchangeCurrency(args.base_currency,
                                     args.counter_currency,
                                     args.count);
  }
  catch (const std::exception& ex) {
    return ex.what();
  }

  std::ostringstream ss;
  ss << "You will need " << cost << " " << args.counter_currency <<
    " to buy " << args.count << " " << args.base_currency << ".";

  message_ = ss.str();
  return message_;
}
