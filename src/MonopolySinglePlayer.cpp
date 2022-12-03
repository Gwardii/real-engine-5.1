#include "MonopolySinglePlayer.hpp"

std::string win_message = "CONGRATULATIONS, YOU HAVE WON!";
std::string lose_message = "Unluckily, you have lost. :(";

bool sanitizeInput() {
  if (!std::cin.good()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Wrong input!" << std::endl;
    return true;
  }
  return false;
}

MonopolySinglePlayer::MonopolySinglePlayer() {}

void MonopolySinglePlayer::launch() {
  std::cout << "\n\nWelcome to Monopoly Single Player! Let's build the best "
               "company the world has ever seen!"
            << std::endl;
  printHelp();
  while (status) {
    printCompanyStatus();
    while (playerAction()) {
    }
    company->getIncome();
    company->paySalaries();
    company->payOffCredits();
    if (company->getCompanyValue() > statutorily::WIN_CONDITION) {
      status = false;
      std::cout << win_message << std::endl;
    } else if (company->getAccountBalance() < 0.) {
      status = false;
      std::cout << lose_message << std::endl;
    }
  }
}

bool MonopolySinglePlayer::playerAction() {
  std::cout << "Manage your company: ";
  std::string input;
  std::cin >> input;
  if (sanitizeInput()) {
    return true;
  }

  if (input == "help") {
    printHelp();
    return true;
  }
  if (input == "instruction") {
    printInstruction();
    return true;
  }
  if (input == "lp") {
    company->printEmployees();
    return true;
  }
  if (input == "zinz") {
    company->hireEmployee<Engineer>();
    return true;
  }
  if (input == "zmag") {
    company->hireEmployee<Storeman>();
    return true;
  }
  if (input == "zmkt") {
    company->hireEmployee<Marketer>();
    return true;
  }
  if (input == "zrob") {
    company->hireEmployee<Worker>();
    return true;
  }
  if (input == "kred") {
    std::cout << std::endl << "How much money do you want? ";
    double value;
    std::cin >> value;
    if (sanitizeInput()) {
      return true;
    }
    double max_credit{statutorily::M * company->getCompanyValue()};
    double actual_credit{company->getSumOfAllCredits()};
    double reserve_credit{max_credit - actual_credit};
    if (value > reserve_credit) {
      std::cout << std::endl
                << "You can take out at most $" << reserve_credit
                << " in credit at the moment." << std::endl
                << "Value of all of your credits cannot be greater than $"
                << max_credit << ", while you have taken out $" << actual_credit
                << " already." << std::endl;
      return true;
    }

    std::cout << std::endl << "For what period of time? ";
    unsigned int deadline;
    std::cin >> deadline;
    if (sanitizeInput()) {
      return true;
    }
    if (deadline > statutorily::X) {
      std::cout << std::endl
                << "You can take out a credit for a maximum of "
                << statutorily::X << " months." << std::endl;
      return true;
    }
    company->takeOutCredit(value, deadline);
    return true;
  }
  if (input == "status") {
    printCompanyStatus();
    return true;
  }
  if (input == "kt") {
    return false;
  }
  std::cout << "Unknown command! Nothing has happend." << std::endl;
  return true;
}

void MonopolySinglePlayer::printHelp() {
  std::cout
      << "List of available commands :\n"
      << "+ lp\t - list employees\n"
      << "+ zinz\t - hire an engineer\n"
      << "+ zmag\t - hire a storeman\n"
      << "+ zmkt\t - hire a marketer\n"
      << "+ zrob\t - hire a worker\n"
      << "+ kred\t - take a credit\n"
      << "+ kt\t - go to next month and print the status of your company\n"
      << "+ status - print current status\n"
      << "+ help\t - print availabe commands\n"
      << "+ instruction\t - print rules of the game\n\n";
}

void MonopolySinglePlayer::printCompanyStatus() {
  std::cout << "Account Balance: \t\t$" << company->getAccountBalance()
            << std::endl
            << "Value of the company: \t\t$" << company->getCompanyValue()
            << std::endl
            << "Total value of all credits: \t$"
            << company->getSumOfAllCredits() << std::endl
            << "Total value of salaries to pay: $"
            << company->calculateSalaries() << std::endl
            << "Expected income: \t\t$" << company->calculateIncome()
            << std::endl;
}

void MonopolySinglePlayer::printInstruction() {}