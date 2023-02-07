#include <iostream>
#include <vector>

// Define a basic point structure
struct Point {
  int x;
  int y;
};

// Define a basic color structure
struct Color {
  int r;
  int g;
  int b;
};

// Define a basic shape class
class Shape {
  public:
    Shape(Point point, Color color) : point_(point), color_(color) {}
    virtual void Draw() = 0;

  protected:
    Point point_;
    Color color_;
};

// Define a class for a circle shape
class Circle : public Shape {
  public:
    Circle(Point point, Color color, int radius) : Shape(point, color), radius_(radius) {}
    void Draw() {
      std::cout << "Drawing a circle at (" << point_.x << ", " << point_.y << ") with color RGB(" << color_.r << ", " << color_.g << ", " << color_.b << ") and radius " << radius_ << std::endl;
    }

  private:
    int radius_;
};

// Define a class for a rectangle shape
class Rectangle : public Shape {
  public:
    Rectangle(Point point, Color color, int width, int height) : Shape(point, color), width_(width), height_(height) {}
    void Draw() {
      std::cout << "Drawing a rectangle at (" << point_.x << ", " << point_.y << ") with color RGB(" << color_.r << ", " << color_.g << ", " << color_.b << ") and width " << width_ << " and height " << height_ << std::endl;
    }

  private:
    int width_;
    int height_;
};

int main() {
  // Create some shapes
  Circle circle1(Point{100, 100}, Color{255, 0, 0}, 50);
  Rectangle rectangle1(Point{200, 200}, Color{0, 255, 0}, 100, 50);

  // Store the shapes in a vector
  std::vector<Shape*> shapes = {&circle1, &rectangle1};

  // Draw the shapes
  for (Shape* shape : shapes) {
    shape->Draw();
  }

  return 0;
}

