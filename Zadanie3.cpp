#include <cmath>
#include <iostream>

/*
 * Opis:Program obliczający zawieranie się danego punktu tym razem podejcie prawie obiektowe w środku trójkata
 * Author:Daniel Postołowicz
 * Date: 06.03.2024
 * */

class point {
private:
  int x;
  int y;
public:
    int getx(){
        return x;
    }
    int gety(){
        return y;
    }
    void setx(int x_temp){
    x=x_temp;
    }
    void sety(int y_temp){
    y=y_temp;
    }
} ;

class trojkat {
private:
  point p1, p2, p3;
public:
    point getp1(){
        return p1;
    }
    point getp2(){
        return p2;
    }
    point getp3(){
        return p3;
    }
    void setp1(point p){
      p1 = p; 
    }
    void setp2(point p){
      p2 = p; 
    }
    void setp3(point p){
      p3 = p; 
    }
};

float dlugosc(point p1, point p2) {
  return sqrt((p2.getx() - p1.getx()) * (p2.getx() - p1.getx()) + (p2.gety() - p1.gety()) * (p2.gety() - p1.gety()));
}

float obwod(trojkat t) {
  float ob;
  ob = dlugosc(t.getp1(), t.getp2()) + dlugosc(t.getp2(), t.getp3()) + dlugosc(t.getp3(), t.getp1());
  return ob;
}

float pole(trojkat t) {
  float p = obwod(t) / 2;
  return sqrt(p * (p - dlugosc(t.getp1(), t.getp2())) * (p - dlugosc(t.getp2(), t.getp3())) *
              (p - dlugosc(t.getp3(), t.getp1())));
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
  t1.setp1(t.getp1());
  t1.setp2(t.getp2());
  t1.setp3(p);
  // 2trojkat
  t2.setp1(t.getp2());
  t2.setp2(t.getp3());
  t2.setp3(p);
  // 3trojkat
  t3.setp1(t.getp1());
  t3.setp2(t.getp3());
  t3.setp3(p);
  //
  A = pole(t);
  A1 = pole(t1);
  A2 = pole(t2);
  A3 = pole(t3);
  std::cout << "Pole trojkata A = " << A << "\n";
  std::cout << "Pole trojkata A1 = " << A1 << "\n";
  std::cout << "Pole trojkata A2 = " << A2 << "\n";
  std::cout << "Pole trojkata A3 = " << A3 << "\n";
  sum_pol = A1 + A2 + A3;
  if (modul(A - sum_pol) < 0.001) {
    return true;
  } else
    return false;
}

int main() {
  trojkat t;
  point p;
  // Punkt A
  std::cout << "Podawaj wierzcholki kazda współrzędna musi być oddzielona spacją. \n";
  std::cout << "Podaj wierzcholek A\n";
  int xtemp,ytemp;
  point ptemp;


  std::cin >> xtemp >> ytemp;
  ptemp.setx(xtemp);
  ptemp.sety(ytemp);
  t.setp1(ptemp);


  std::cout << "Podaj wierzcholek B\n";
  std::cin >> xtemp >> ytemp;
  ptemp.setx(xtemp);
  ptemp.sety(ytemp);
  t.setp2(ptemp);

  std::cout << "Podaj wierzcholek C\n";
  std::cin >> xtemp >> ytemp;
  ptemp.setx(xtemp);
  ptemp.sety(ytemp);
  t.setp3(ptemp);

  std::cout << "Podaj punkt \n";
  std::cin >> xtemp >> ytemp;
  p.setx(xtemp);
  p.sety(ytemp);


  if (is_Inside(p, t)) {
    std::cout << "Tak punkt p jest w trojkacie";
  } else {
    std::cout << "Punkt p nie jest w trojkacie";
  }

  return 0;
}
