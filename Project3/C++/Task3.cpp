/* Project3 Task3
 * Tracy Quan
 *
 *
 * C++
 * Task3:Write an example program in each language that demonstrates all of the
 * basic built-in types and how to construct aggregate types
 */
 #include <iostream>

//built-in types of C++
int test_types(){
  bool boolean = (8==8);
  char character = 'Q';
  int integer = 24;
  float floa = 24.888;
  wchar_t w = L'A';
  std::cout << "Boolean value::" << boolean << '\n';
  std::cout << "Character value::" << character << '\n';
  std::cout << "Integer value::" << integer << '\n';
  std::cout << "Float value::" << floa << '\n';
  std::cout << "Wide character value::" << w << '\n';
  std::cout << "------------------------------------------\n" ;
  return 0;
}

//How to build class in C++
class Rectangle{
    int width, height;
  public:
    void setWidth(int);
    void setHeight(int);
    int area();
};

void Rectangle::setWidth(int w){
    width = w;
}

void Rectangle::setHeight(int h){
    height = h;
}

int Rectangle::area(){
    return width*height;
}

// Main function
int main(){
  test_types();

  Rectangle rect; //build a new object
  rect.setWidth(24);
  rect.setHeight(8);
  std::cout << "Area of the Rectangle: " << rect.area() << "\n";
  return 0;
}
