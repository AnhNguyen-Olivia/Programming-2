/*
Develop is a class of books. Each book has the following attributes:
    − an author;
    − a title;
    − a format;
    − a price;
    − a year of publication; and
    − a publisher.
*/

#include <iostream>
using namespace std;

class Book{
    private:
        string author;
        string title;
        string format;
        double price;
        int yearOfPublication;
        string publisher;
    public:
        Book(string a, string t, string f, double p, int y, string pub){
            author = a;
            title = t;
            format = f;
            price = p;
            yearOfPublication = y;
            publisher = pub;
        }
        ~Book(){}

        //get & set
        void setAuthor(string a){author = a;}
        void setTitle(string t){title = t;}
        void setFormat(string f){format = f;}
        void setPrice(double p){price = p;}
        void setYear(int y){yearOfPublication = y;}
        void setPub(string pub){publisher = pub;}

        string getAuthor(){return author;}
        string getTitle(){return title;}
        string getFormat(){return format;}
        string getPub(){return publisher;}
        double getPrice(){return price;}
        int getYear(){return yearOfPublication;}

        //func
        void printInfo(){
            cout << "Book title: " << title << "\n"
                 << "Author: " << author << "\n"
                 << "Format: " << format << "\n"
                 << "Year: " << yearOfPublication << "\n"
                 << "Price: " << price << "\n"
                 << "Publisher: " << publisher << endl;
        }
};

int main() {
    Book book1("Surbhi Kakar", "Java Programming", "Hardcover", 30.0, 2010, "Dream Tech Press");
    book1.printInfo();
    return 0;
}



