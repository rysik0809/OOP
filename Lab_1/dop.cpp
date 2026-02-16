#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Rectangle{
    private:
        int width;
        int height;
        int x, y;

    public:
        Rectangle():width(10),height(10),x(0),y(0){}
        Rectangle(int _w, int _h, int _x, int _y){
            width = _w;
            height = _h;
            x = _x;
            y = _y;
        }

        int Square();
        void Move(int _x, int _y);

        void getRectangle(){
            cout<<"Ширина: "<<width<<endl<<"Высота: "<<height<<endl
                <<"По X: "<<x<<endl<<"По Y: "<<y<<endl;
        };
        ~Rectangle(){};
};

int Rectangle::Square(){
   return width*height;
}
void Rectangle::Move(int _x, int _y){
    x = _x;
    y = _y;
    cout<<"Прямоугольник переместился на координаты: "<<x<<" | "<<y<<endl;
}

int main(){
    Rectangle one(12, 22, -4, 4);
    one.getRectangle();
    int sq = one.Square();
    one.Move(100, -100);

    cout<<"Площадь: "<<sq<<endl;
    return 0;
}