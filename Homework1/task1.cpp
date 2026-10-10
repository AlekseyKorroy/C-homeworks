#include <iomanip>
#include <iostream>

double get_temp(const int* a, const int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum / n;
}
int get_min(const int* a, const int n) {
  int mn = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < mn) mn = a[i];
  }
  return mn;
}
int get_max(const int* a, const int n) {
  int mx = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > mx) mx = a[i];
  }
  return mx;
}
int count_cold(const int* a, const int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) count++;
  }
  return count;
}
int main() {
  int n;
  std::cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cout << std::fixed << std::setprecision(1) << get_temp(a, n) << "\n";
  std::cout << get_min(a, n) << " " << get_max(a, n) << "\n";
  std::cout << count_cold(a, n) << "\n";
  delete[] a;
}
