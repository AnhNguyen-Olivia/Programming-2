#include <iostream>
using namespace std;

class Quadrilateral{
    private:
        double width;
        double height;
    public:
    //constructor
    Quadrilateral(double w, double h){
        width = w;
        height = h;
    }

    Quadrilateral() : width(1), height(1){}
    
    ~Quadrilateral(){}

    void setHeight(double h){
        height = h;
    }

    double getWidth(){
        return width; 
    }
    void setWidth(double w){
        width = w;
    }
    double getHeight(){
        return height;
    }

    virtual double area (){
        return 0;
    }

    virtual void printArea(){
        cout << "Area: " << area();
    }

};

class Rectangle: public Quadrilateral{
    public:
        Rectangle(double w, double h): Quadrilateral (w, h){}
        double area(){
            return getWidth() * getHeight(); 
        }
};


class Parallelograms: public Quadrilateral{
    public:
        Parallelograms(double w, double h): Quadrilateral (w, h){}
        double area(){
            return getWidth() * getHeight(); 
        }
};

class Trapeziums: public Quadrilateral{
    private:
        double base;
    public:
        Trapeziums(double w, double h, double b): Quadrilateral (w, h){base = b;}
        double area(){
            return (getWidth() + base) / 2 * getHeight(); 
        }
};


int main(){
    Quadrilateral* quads[3];
    quads[0]= new Rectangle(3,4);
    quads[1]= new Parallelograms(5,6);
    quads[2] = new Trapeziums(2,3,4);

    for (int i = 0; i < 3; i++) {
        quads[i]->printArea();
        cout << endl;
    }
    return 0;
};