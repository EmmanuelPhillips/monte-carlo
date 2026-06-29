#include <iostream>
#include <random>

int main() {

  std::random_device rd{};
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> randPos{-1, 1};

  double x{};
  double y{};

  int insideC{0};
  int outsideC{0};

  for (int i{0}; i < 1000; ++i) {
    x = randPos(gen);
    y = randPos(gen);
    if ((x * x) + (y * y) <= 1) {
      ++insideC;
    } else {
      ++outsideC;
    }
  }

  std::cout << insideC / outsideC;

  return 0;
}
