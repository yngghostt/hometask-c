#include <iostream>
#include <unistd.h>
#define sat_number 4

using namespace std;

class satellite {
private:
  float pos = 0.0;
  int num = -1;

public:
  void set_number(int n) { num = n; }
  int get_number() { return num; }
  float update_position() {
    pos = (float)(rand() % 100) / 10;
    cout << "СЃРїСѓС‚РЅРёРє " << num << ": " << pos << "\n";
    return pos;
  }
  float get_position() { return pos; }
};

int main() {
  satellite *sat_array = new satellite[sat_number];
  for (int i = 0; i < sat_number; i++) {
    sat_array[i].set_number(i + 1);
  }
  srand(time(0));
  int i = 0;
  while (true) {

    cout << 5 * i << " СЃРµРєСѓРЅРґ: \n";
    float res = 0;
    for (int j = 0; j < sat_number; j++) {
      res += sat_array[j].update_position();
    }
    cout << "РЎСЂРµРґРЅРµРµ: " << res / sat_number << "\n";
    sleep(5);
    i += 1;
  }
}
