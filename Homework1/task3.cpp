#include <cstring>
#include <iostream>
void clear(char** a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = ' ';
    }
  }
}
bool put(char** a, int n, int m, int x, int y, char c) {
  if (x < m && x >= 0 && y < n && y >= 0) {
    a[y][x] = c;
    return true;
  } else {
    return false;
  }
}
bool text(char** a, int n, int m, int x, int y, char* s, int len) {
  if (x >= 0 && y >= 0 && y < n && x + len - 1 < m) {
    for (int i = 0; i < len; i++) {
      a[y][x + i] = s[i];
    }
    return true;
  } else {
    return false;
  }
}
void print(char** a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << a[i][j];
    }
    std::cout << "\n";
  }
}
int main() {
  char** a = new char*[5];
  for (int i = 0; i < 5; i++) {
    a[i] = new char[10];
  }
  clear(a, 5, 10);
  char cmd[15];
  while (1) {
    std::cin >> cmd;
    if (strcmp(cmd, "quit") == 0) {
      break;
    }
    if (strcmp(cmd, "clear") == 0) {
      clear(a, 5, 10);
    }
    if (strcmp(cmd, "put") == 0) {
      int x, y;
      char c;
      std::cin >> x >> y >> c;
      if (!put(a, 5, 10, x, y, c)) {
        std::cout << "error\n";
      }
    }
    if (strcmp(cmd, "text") == 0) {
      int x, y;
      char* c = new char[15];
      std::cin >> x >> y >> c;
      if (!text(a, 5, 10, x, y, c, strlen(c))) {
        std::cout << "error\n";
      }
      delete[] c;
    }
    if (strcmp(cmd, "print") == 0) {
      print(a, 5, 10);
    }
  }
  for (int i = 0; i < 5; i++) {
    delete[] a[i];
  }
  delete[] a;
}
