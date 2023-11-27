#include <iostream>
using namespace std;


class Lesson59 {
  //Explicit data type conversion
public:

  static float cStyleConversion(int i1, int i2) {
    return (float) i1 / i2;
  }

  static float staticCastConversion(int i1, int i2) {
    return static_cast<float>(i1) / i2;
  }
};





int main() {
  cout << Lesson59::cStyleConversion(11, 3) << endl;
  cout << Lesson59::staticCastConversion(11, 3) << endl;
}