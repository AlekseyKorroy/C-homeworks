#include <cstring>
#include <iomanip>
#include <iostream>
void deposit(int& s, int k) {
  if (k <= 0) {
    std::cout << "error\n";
  } else {
    s += k;
  }
}
void withdraw(int& s, int k) {
  if (k <= 0 || s < k) {
    std::cout << "error\n";
  } else {
    s -= k;
  }
}
void balance(int& s, int k) { std::cout << s << "\n"; }
void reset(int& s, int k) { s = 0; }
int main() {
  int s = 0;
  char cmd[10];
  const char* names[] = {"deposit", "withdraw", "balance", "reset"};
  void(*functions[])(int&, int) = {deposit, withdraw, balance, reset};
  while (1) {
    std::cin >> cmd;
    if (strcmp(cmd, "stop") == 0) {
      break;
    }
    int k = 0;
    if (strcmp(cmd, "deposit")==0||strcmp(cmd, "withdraw")==0) {
      std::cin>>k;
    }
    bool ok = false;
    for (int i = 0; i<4; i++) {
      if (strcmp(cmd, names[i])==0) {
        functions[i](s, k);
        ok = true;
      }
    }
    if (!ok) {
      std::cout<<"error\n";
    }
  }
}
