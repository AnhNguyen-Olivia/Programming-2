#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string format;
    double price;
    int yearOfPublication;
    std::string publisher;

public:
    // Constructor
    Book(std::string author, 
        std::string title, 
        std::string format, 
        double price, 
        int yearOfPublication, 
        std::string publisher)
        : author(author), 
        title(title), 
        format(format), 
        price(price), 
        yearOfPublication(yearOfPublication), 
        publisher(publisher) {}

    // Getters
    std::string getAuthor() const { return author; }
    std::string getTitle() const { return title; }
    std::string getFormat() const { return format; }
    double getPrice() const { return price; }
    int getYearOfPublication() const { return yearOfPublication; }
    std::string getPublisher() const { return publisher; }

    // Setters
    void setAuthor(const std::string& newAuthor) { author = newAuthor; }
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setFormat(const std::string& newFormat) { format = newFormat; }
    void setPrice(double newPrice) { price = newPrice; }
    void setYearOfPublication(int newYear) { yearOfPublication = newYear; }
    void setPublisher(const std::string& newPublisher) { publisher = newPublisher; }

    // Display book details
    void displayDetails() const {
        std::cout << "Author: " << author << "\n"
                  << "Title: " << title << "\n"
                  << "Format: " << format << "\n"
                  << "Price: $" << price << "\n"
                  << "Year of Publication: " << yearOfPublication << "\n"
                  << "Publisher: " << publisher << "\n";
    }
};

int main() {
    // Example usage
    Book book("J.K. Rowling", "Harry Potter", "Hardcover", 29.99, 1997, "Bloomsbury");
    book.displayDetails();

    return 0;
}