#include <iostream>

void printans(void* data, bool flag) {
  if (flag) {
    char* s = (char*)data;
    for (int i = 0; s[i] != '\0'; ++i) {
      std::cout << s[i];
    }
    std::cout << "\n";
  } else {
    int* p = (int*)(data);
    std::cout << *p << "\n";
  }
}

int main() {
  // Задача: на вход принимается трехмерный массив символов a(int***) требуется
  // проверить, правда ли, что a[i][j][k]=a[k][j][i] для любых i, j, k Если это
  // верно, нужно вывести строку correct и первую строку в массиве без пробелов,
  // иначе самое первое i для котрого это неверно(для этого используем void*)

  int n;
  std::cin >> n;

  char*** a = new char**[n];
  for (int i = 0; i < n; ++i) {
    a[i] = new char*[n];
    for (int j = 0; j < n; ++j) {
      a[i][j] = new char[n];
    }
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k) std::cin >> a[i][j][k];

  int badIndex = -1;
  for (int i = 0; i < n && badIndex == -1; ++i) {
    for (int j = 0; j < n && badIndex == -1; ++j) {
      for (int k = 0; k < n; ++k) {
        if (a[i][j][k] != a[k][j][i]) {
          badIndex = i;
          break;
        }
      }
    }
  }

  if (badIndex == -1) {
    const char word[] = "correct";
    int wlen = 7;
    char* buf = new char[wlen + n + 1];
    for (int i = 0; i < wlen; ++i) {
      buf[i] = word[i];
    }
    for (int k = 0; k < n; ++k) {
      buf[wlen + k] = a[0][0][k];
    }
    buf[wlen + n] = '\0';
    printans(buf, true);
    delete[] buf;
  } else {
    printans(&badIndex, false);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      delete[] a[i][j];
    }
    delete[] a[i];
  }
  delete[] a;
}