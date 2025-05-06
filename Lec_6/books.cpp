#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string Author;
    string Title;
    string Format;
    double Price;
    int YearOfPublication;
    string Publisher;

public:
    // Constructor using initialization list
    Book(const string& author, const string& title, const string& format, double price, int yearOfPublication, const string& publisher)
        : Author(author), Title(title), Format(format), Price(price), YearOfPublication(yearOfPublication), Publisher(publisher) {}

    // Setters
    void setAuthor(const string& author) { Author = author; }
    void setTitle(const string& title) { Title = title; }
    void setFormat(const string& format) { Format = format; }
    void setPrice(double price) { Price = price; }
    void setYearOfPublication(int year) { YearOfPublication = year; }
    void setPublisher(const string& publisher) { Publisher = publisher; }

    // Getters
    string getAuthor() const { return Author; }
    string getTitle() const { return Title; }
    string getFormat() const { return Format; }
    double getPrice() const { return Price; }
    int getYearOfPublication() const { return YearOfPublication; }
    string getPublisher() const { return Publisher; }

    // Method to update multiple attributes
    void updateBookDetails(const string& author, const string& title, const string& format, double price, int yearOfPublication, const string& publisher) {
        setAuthor(author);
        setTitle(title);
        setFormat(format);
        setPrice(price);
        setYearOfPublication(yearOfPublication);
        setPublisher(publisher);
    }

    // Method to print book details
    void printBookDetails() const {
        cout << "Author: " << getAuthor() << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Format: " << getFormat() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Year of Publication: " << getYearOfPublication() << endl;
        cout << "Publisher: " << getPublisher() << endl;
    }
};

int main() {
    // Create a book object
    Book book1("Surbhi Kakar", "Java Programming", "Hardcover", 30.0, 2010, "Dream Tech Press");
    book1.printBookDetails();

    // Update book details
    book1.updateBookDetails("Le Chat", "Meow Meow", "Paperback", 40.0, 2037, "The Cat");

    // Print updated book details
    cout << "\nUpdated Book Details:" << endl;
    book1.printBookDetails();

    return 0;
}