#include <iostream>
#include <string>
using namespace std;

class Book {
    public: 
    string Author;
    string Title;
    string Genre;
    double Price;
    string Date;
    string Publisher;
    string Description;

    void display() {
        cout << "Author: " << Author << endl;
        cout << "Title: " << Title << endl;
        cout << "Genre: " << Genre << endl;
        cout << "Price: $" << Price << endl;
        cout << "Publish date: " << Date << endl;
        cout << "Publisher: " << Publisher << endl;
        cout << "Description: " << Description << endl;
    }
    Book(string author, string title, string genre, double price, string date, string publisher, string description){
        Author = author;
        Title = title;
        Genre = genre;
        Price = price;
        Date = date;
        Publisher = publisher;
        Description = description;
    }; 
};

int main(){
    Book book1("Surbhi Kakar", "Java Programming", "Computer", 30.0, "2010-08-01", "Dream Tech Press", "A description here.");
    book1.display();
    return 0;
}