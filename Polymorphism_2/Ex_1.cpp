#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void print(ostream& out) const = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
    int x1, y1, x2, y2, x3, y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
    double area() const override {
        return 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    }
    void print(ostream& out) const override {
        out << "t " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
    }
};

class Rectangle : public Shape {
    int x1, y1, x2, y2;
public:
    Rectangle(int x1, int y1, int x2, int y2) 
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
    double area() const override {
        return abs((x2 - x1) * (y2 - y1));
    }
    void print(ostream& out) const override {
        out << "r " << x1 << " " << y1 << " " << x2 << " " << y2;
    }
};

class Square : public Shape {
    int x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
    double area() const override {
        return 0.5 * abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1));
    }
    void print(ostream& out) const override {
        out << "s " << x1 << " " << y1 << " " << x2 << " " << y2 << " " 
            << x3 << " " << y3 << " " << x4 << " " << y4;
    }
};

class Parallelogram : public Shape {
    int x1, y1, y2, x2, y3, y4;
public:
    Parallelogram(int x1, int y1, int y2, int x2, int y3, int y4) 
        : x1(x1), y1(y1), y2(y2), x2(x2), y3(y3), y4(y4) {}
    double area() const override {
        return abs((y2 - y1) * (x2 - x1));
    }
    void print(ostream& out) const override {
        out << "p " << x1 << " " << y1 << " " << y2 << " " << x2 << " " << y3 << " " << y4;
    }
};

int main() {
    ifstream infile("E:/Programming-2/Polymorphism_2/input.txt");
    if (!infile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n;
    infile >> n;
    infile.ignore();
    Shape* shapes[100];
    int shape_count = 0;

    for (int i = 0; i < n && shape_count < 100; ++i) {
        string line;
        if (!getline(infile, line)) {
            cerr << "Error reading line for shape " << i << endl;
            break;
        }

        stringstream ss(line);
        char type;
        ss >> type;

        Shape* shape = nullptr;
        switch (type) {
            case 't': {
                int x1, y1, x2, y2, x3, y3;
                if (ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
                    shape = new Triangle(x1, y1, x2, y2, x3, y3);
                } else {
                    cerr << "Invalid triangle coordinates." << endl;
                }
                break;
            }
            case 'r': {
                int x1, y1, x2, y2;
                if (ss >> x1 >> y1 >> x2 >> y2) {
                    shape = new Rectangle(x1, y1, x2, y2);
                } else {
                    cerr << "Invalid rectangle coordinates." << endl;
                }
                break;
            }
            case 's': {
                int x1, y1, x2, y2, x3, y3, x4, y4;
                if (ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
                    shape = new Square(x1, y1, x2, y2, x3, y3, x4, y4);
                } else {
                    cerr << "Invalid square coordinates." << endl;
                }
                break;
            }
            case 'p': {
                int x1, y1, y2, x2, y3, y4;
                if (ss >> x1 >> y1 >> y2 >> x2 >> y3 >> y4) {
                    shape = new Parallelogram(x1, y1, y2, x2, y3, y4);
                } else {
                    cerr << "Invalid parallelogram coordinates." << endl;
                }
                break;
            }
            default: {
                cerr << "Unknown shape type: " << type << endl;
                break;
            }
        }

        if (shape != nullptr) {
            shapes[shape_count++] = shape;
        }
    }

    sort(shapes, shapes + shape_count, [](Shape* a, Shape* b) {
        return a->area() > b->area();
    });

    // Write to output file
    ofstream outfile("output.txt");
    if (!outfile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outfile << shape_count << endl;
    for (int i = 0; i < shape_count; ++i) {
        shapes[i]->print(outfile);
        outfile << " -> " << shapes[i]->area() << endl;
    }

    for (int i = 0; i < shape_count; ++i) {
        delete shapes[i];
    }

    return 0;
}