/* CS333
 * Project 6
 * Part2: File I/O in selected Language
 *
 * Task2: Exploring functions in C++
 * Override functions using inheritance
 */

#include <iostream>
using namespace std;

class Shape {
public:
  void setWidth(int w){
    width = w;
  }
  void setHeight(int h){
    height = h;
  }
  int area(){
    return 0;
  }

protected:
  int width;
  int height;
};

class Rectangle: public Shape{
public:
  int area(){
    return (width*height);
  }
};

class Triangle: public Shape{
public:
  int area(){
    return (0.5*width*height);
  }
};

int main(void){
  Rectangle Rect;
  Rect.setWidth(8);
  Rect.setHeight(24);
  std::cout<<"Area of Rectangle Rect: " <<Rect.area()<<endl;
  Triangle Tri;
  Tri.setWidth(8);
  Tri.setHeight(24);
  std::cout<<"Area of Triangle Tri: " << Tri.area()<<endl;

  return 0;

}
