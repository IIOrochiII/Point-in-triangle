#include <cmath>
#include <iostream>

/*
 * Opis:Program obliczający zawieranie się danego punktu w środku trójkata
 * Author:Daniel Postołowicz
 * Date: 28.02.2024
 * Za wszelkie ewentualne literówki przepraszam :)
 * */

typedef struct punkt {
  int x;
  int y;
} point;

typedef struct trojkat {
  point p1, p2, p3;
} trojkat;

float dlugosc(punkt p1, punkt p2) {
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

float obwod(trojkat t) {
  float ob;
  ob = dlugosc(t.p1, t.p2) + dlugosc(t.p2, t.p3) + dlugosc(t.p3, t.p1);
  return ob;
}

float pole(trojkat t) {
  float p = obwod(t) / 2;
  return sqrt(p * (p - dlugosc(t.p1, t.p2)) * (p - dlugosc(t.p2, t.p3)) *
              (p - dlugosc(t.p3, t.p1)));
}

float modul(float x) {
  if (x < 0) {
    return (-1.0) * x;
  } else
    return x;
}

bool is_Inside(point p, trojkat t) {
  float A, A1, A2, A3;
  trojkat t1, t2, t3;
  float sum_pol = 0;
  // 1trojkat
  t1.p1 = t.p1;
  t1.p2 = t.p2;
  t1.p3.x = p.x;
  t1.p3.y = p.y;
  // 2trojkat
  t2.p1 = t.p2;
  t2.p2 = t.p3;
  t2.p3.x = p.x;
  t2.p3.y = p.y;
  // 3trojkat
  t3.p1 = t.p1;
  t3.p2 = t.p3;
  t3.p3.x = p.x;
  t3.p3.y = p.y;
  //
  A = pole(t);
  A1 = pole(t1);
  A2 = pole(t2);
  A3 = pole(t3);
  sum_pol = A1 + A2 + A3;
  if (modul(A - sum_pol) < 0.001) {
    return true;
  } else
    return false;
}

int main() {
  trojkat t;
  punkt p;
  // Punkt A
  std::cout << "Podawaj wierzcholki kazda współrzędna musi być oddzielona spacją. \n";
  std::cout << "Podaj wierzcholek A\n";
  std::cin >> t.p1.x >> t.p1.y;

  std::cout << "Podaj wierzcholek B\n";
  std::cin >> t.p2.x >> t.p2.y;

  std::cout << "Podaj wierzcholek C\n";
  std::cin >> t.p3.x >> t.p3.y;

  std::cout << "Podaj punkt \n";
  std::cin >> p.x >> p.y;

  if (is_Inside(p, t)) {
    std::cout << "Tak punkt p jest w trojkacie";
  } else {
    std::cout << "Punkt p nie jest w trojkacie";
  }

  return 0;
}
