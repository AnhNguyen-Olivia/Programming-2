/*
Assignment:
Write a program to read a list of complex numbers from a file and output the 5 numbers with the largest magnitude. 
The structure of the file containing complex numbers (In.txt) is as follows:
    - The first line is the number of complex numbers
    - From the second line, each line contains the real part and imaginary part of a complex number.
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class ComplexNum {
    private:
        double real;
        double imagine;
    public:
        //default constructor
        ComplexNum(){}
        //constructor with para
        ComplexNum(double r, double imag){
            real = r;
            imagine = imag;
        }

        ~ComplexNum(){}
        void setReal(double r){
            real = r;
        }
        void setImag(double imag){
            imagine = imag;
        }
        double getReal(){
            return real;
        }
        double getImag(){
            return imagine;
        }
        double calMag(){
            return sqrt(real * real + imagine * imagine);
        }
};

int main(){
    ifstream fin("E:/Programming-2/Practice_all/In.txt");
    if (!fin){
        cout << "File not found" << endl;
        return 1;
    }

    int n;
    fin >> n;
    if (n <= 0){
        cout << "No complex number/ invalid first number" << endl;
        return 2;
    }
    
    ComplexNum* nums = new ComplexNum[n]; //Need default constructor and not constructor with para
    for(int i = 0; i < n; i++){
        double real, imag;
        fin >> real >> imag;
        nums[i] = ComplexNum(real, imag); // Need constructor with para
    }
    fin.close();

    //selection sort :(
    for(int i = 0; i < n; i++){
        int maxIdx = i;
        for (int j = i + 1; j < n; j++){
            if(nums[j].calMag() > nums[maxIdx].calMag()){
                maxIdx = j;
            }
        }
        if(maxIdx != i){
            ComplexNum temp = nums[i];
            nums[i] = nums[maxIdx];
            nums[maxIdx] = temp;
        }
    }

    cout << "Top 5 compflex numbers with largest magnitude are: \n"; 
    for (int i = 0; i < n; i++){
        cout << nums[i].getReal() << " + " << nums[i].getImag() << "i = " << nums[i].calMag() << endl;
    }

    delete[] nums;
    return 0;
}