#include <iomanip>
#include <iostream>
#include <random>

int main() {
  std::cout << std::setprecision(17);

  std::random_device rd{};
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> randPos{-1, 1};

  double x{};
  double y{};

  int insideC{0};
  int outsideC{0};

  for (int i{0}; i < 5; ++i) {
    for (int j{0}; j < 1000; ++j) {
      x = randPos(gen);
      y = randPos(gen);
      if ((x * x) + (y * y) <= 1) {
        ++insideC;
      } else {
        ++outsideC;
      }
    }

    double pi = 4.0 * insideC / (insideC + outsideC);
    std::cout << pi << '\n';
  }

  return 0;
}
