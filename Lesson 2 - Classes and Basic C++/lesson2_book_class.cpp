#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string Author;
    string Title;
    string Genre;
    double Price;
    string Date;
    string Publisher;
    string Description;

public:
    // Constructor using initialization list
    Book(const string& author, const string& title, const string& genre, double price, const string& date, const string& publisher, const string& description)
        : Author(author), Title(title), Genre(genre), Price(price), Date(date), Publisher(publisher), Description(description) {}

    // Setters
    void setAuthor(const string& author) { Author = author; }
    void setTitle(const string& title) { Title = title; }
    void setGenre(const string& genre) { Genre = genre; }
    void setPrice(double price) { Price = price; }
    void setDate(const string& date) { Date = date; }
    void setPublisher(const string& publisher) { Publisher = publisher; }
    void setDescription(const string& description) { Description = description; }

    // Getters
    string getAuthor() const { return Author; }
    string getTitle() const { return Title; }
    string getGenre() const { return Genre; }
    double getPrice() const { return Price; }
    string getDate() const { return Date; }
    string getPublisher() const { return Publisher; }
    string getDescription() const { return Description; }

    // Method to update multiple attributes
    void updateBookDetails(const string& author, const string& title, const string& genre, double price, const string& date, const string& publisher, const string& description) {
        setAuthor(author);
        setTitle(title);
        setGenre(genre);
        setPrice(price);
        setDate(date);
        setPublisher(publisher);
        setDescription(description);
    }

    // Method to print book details
    void printBookDetails() const {
        cout << "Author: " << getAuthor() << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Genre: " << getGenre() << endl;
        cout << "Price: " << getPrice() << endl;
        cout << "Date: " << getDate() << endl;
        cout << "Publisher: " << getPublisher() << endl;
        cout << "Description: " << getDescription() << endl;
    }
};

int main() {
    Book book1("Surbhi Kakar", "Java Programming", "Computer", 30.0, "2010-08-01", "Dream Tech Press", "A description here.");
    book1.printBookDetails();

    // Using the updateBookDetails method
    book1.updateBookDetails("Le Chat", "Meow Meow", "Cat", 40.0, "2037-01-01", "The Cat", "Meow meow meow meow.");

    // Using the printBookDetails method
    cout << "\nUpdated Book Details:" << endl;
    book1.printBookDetails();

    return 0;
}