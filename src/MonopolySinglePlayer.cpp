#include "MonopolySinglePlayer.hpp"

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
  std::cout << "Welcome to Monopoly Single Player! Let's build the best "
               "company the world has ever seen!"
            << std::endl;
  printHelp();
  while (status == 0U) {
    while (playerAction()) {
    }
    company->getIncome();
    company->paySalaries();
    company->payOffCredits();
    if (company->getCompanyValue() > statutorily::WIN_CONDITION) {
      status = 1U;
    } else if (company->getAccountBalance() < 0.) {
      status = 2U;
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

    std::cout << std::endl << "For what period of time? ";
    unsigned int deadline;
    std::cin >> deadline;
    if (sanitizeInput()) {
      return true;
    }

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
      << "+ help\t - print availabe commands\n"
      << "+ instruction\t - print rules of the game\n\n ";
}

void MonopolySinglePlayer::printInstruction() {}