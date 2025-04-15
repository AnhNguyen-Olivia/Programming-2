#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class studentVgu {
private:
    // Personal information
    string name;
    string studentID;
    string major;
    string nationality;
    int age;
    int enrollmentYear;
    int currentSemester;

    // Academic information
    double gpa;
    string currentCourses[100];
    int courseCount = 0;
    int creditsCompleted;
    bool academicWarning;
    bool onScholarship;
    string scholarshipName;

    // Resources
    double mealCardBalance;
    int printingCredits;
    string borrowedBooks[100];
    int borrowedBookCount = 0;
    string dormRoom;

    // Mental/Physical
    int stressLevel;
    double sleepHours;
    int caffeineIntake;

    // Social
    string friends[20];
    int friendCount = 0;
    string clubMemberships[10];
    int clubCount = 0;
    double socialMediaHours;

    // Activity Log
    string recentActivities[100];
    int activityCount = 0;

public:
    // Parameterized Constructor
    studentVgu(string name, string studentID, string major, int enrollYear, 
        string nationality = "", int age = 0): name(name), studentID(studentID), major(major), nationality(nationality),age(age), enrollmentYear(enrollYear){
        currentSemester = 1;
        gpa = 1.5;
        mealCardBalance = 100.0;
        stressLevel = 30;
        sleepHours = 7.0;
        dormRoom = "Not assigned";
        academicWarning = false;
        onScholarship = true;
        scholarshipName = "DAAD";
        creditsCompleted = 30;
        printingCredits = 0;
        caffeineIntake = 0;
        socialMediaHours = 0;
    }

    // Default Constructor
    studentVgu() {
        name = "Unknown";
        studentID = "000000";
        major = "Undeclared";
        enrollmentYear = 0;
        currentSemester = 1;
        gpa = 5.0;
        mealCardBalance = 100.0;
        stressLevel = 30;
        sleepHours = 7.0;
        dormRoom = "Not assigned";
        academicWarning = false;
        onScholarship = false;
        scholarshipName = "None";
        creditsCompleted = 0;
        nationality = "";
        age = 0;
        printingCredits = 0;
        caffeineIntake = 0;
        socialMediaHours = 0;
    }

    // Getters and Setters
    void setName(string name) { this->name = name; }
    string getName() { return name; }

    void setStudentID(string studentID) { this->studentID = studentID; }
    string getStudentID() { return studentID; }

    void setMajor(string major) { this->major = major; }
    string getMajor() { return major; }

    void setEnrollmentYear(int year) { enrollmentYear = year; }
    int getEnrollmentYear() { return enrollmentYear; }

    void setGPA(double gpa) { 
        this->gpa = gpa; 
        checkScholarshipEligibility();
    }
    double getGPA() { return gpa; }

    int getCurrentSemester() { return currentSemester; }
    int getCreditsCompleted() { return creditsCompleted; }
    double getMealCardBalance() { return mealCardBalance; }
    int getStressLevel() { return stressLevel; }
    bool isOnScholarship() { return onScholarship; }
    string getScholarshipName() { return scholarshipName; }

    void setNationality(string nationality) { this->nationality = nationality; }
    string getNationality() { return nationality; }

    void setAge(int age) { this->age = age; }
    int getAge() { return age; }

    // Scholarship Check
    void checkScholarshipEligibility() {
        onScholarship = (gpa < 2.0);
        scholarshipName = onScholarship ? "DAAD" : "None";}

    // Academic Methods
    void attendClass(string course, int hours) {
        if (courseCount < 100) {
            currentCourses[courseCount++] = course;
            logActivity("Attended " + course + " for " + to_string(hours) + " hours");
        } else {
            cerr << "Cannot add more courses. Limit reached.\n";
        }
        stressLevel += hours * 2;
        sleepHours = max(0.0, sleepHours - 0.5 * hours);
    }

    void takeExam(string course) {
        double performance = (rand() % 100 + stressLevel) / 200.0;
        gpa = (gpa + performance) / 2.0;
        academicWarning = (gpa >= 2.0);

        logActivity("Took exam: " + course + ". GPA updated to " + to_string(gpa));
        if (academicWarning) cout << "ACADEMIC WARNING!\n";
    }

    // Campus Life
    void rechargeMealCard(double amount) {
        mealCardBalance += amount;
        logActivity("Recharged meal card: +" + to_string(amount) + "k VND");
    }

    void rain(bool hasUmbrella) {
        if (hasUmbrella) {
            logActivity("Used umbrella during rain");
        } else {
            stressLevel = min(100, stressLevel + 40);
            logActivity("Got soaked in rain! Stress +40");
        }
    }

    // Social Activities
    void joinClub(string club) {
        if (clubCount < 10) {
            clubMemberships[clubCount++] = club;
            logActivity("Joined club: " + club);
        } else {
            cerr << "Cannot join more clubs. Limit reached.\n";
        }
        socialMediaHours += 2;
    }

    void vguFestEvent() {
        stressLevel = max(0, stressLevel - 25);
        mealCardBalance = max(0.0, mealCardBalance - 50);
        logActivity("Attended VGU Fest! Stress -25, Meal balance -50k");
    }

    // Status Display
    void displayStatus() {
        cout << "\n=== VGU Student Status ==="
             << "\nName: " << name
             << "\nMajor: " << major
             << "\nGPA: " << gpa
             << "\nStress: " << stressLevel << "/100"
             << "\nMeal Balance: " << mealCardBalance << "k"
             << "\nDorm: " << dormRoom
             << "\nClubs: ";

        for (int i = 0; i < clubCount; ++i) {
            cout << clubMemberships[i] << (i < clubCount-1 ? ", " : "");
        }
        cout << "\n==========================\n";
    }

    // Utilities
    void complainAboutDeadline() {
        stressLevel = min(100, stressLevel + 15);
        logActivity("Complained about deadlines. Stress +15");
    }

    void useVGUBus(string from, string to) {
        logActivity("Took bus from " + from + " to " + to);
        sleepHours += 0.25;
    }

    void displayRecentActivities() {
        cout << "\n=== Recent Activities ===\n";
        for (int i = 0; i < activityCount; ++i) {
            cout << "- " << recentActivities[i] << endl;
        }
    }

private:
    void logActivity(string message) {
        if (activityCount < 100) {
            recentActivities[activityCount++] = message;
        }
    }
};

int main() {
    srand(time(0));

    studentVgu student("Jiafei", "10423200", "Computer Science", 2023);
    student.setGPA(1.8);

    cout << "\n=== Student Overview ==="
         << "\nName: " << student.getName()
         << "\nID: " << student.getStudentID()
         << "\nMajor: " << student.getMajor()
         << "\nEnrollment Year: " << student.getEnrollmentYear()
         << "\nGPA: " << student.getGPA() << "\n"
         << "Scholarship " << (student.isOnScholarship() ? "granted: " + student.getScholarshipName() : "not granted") << endl;

    student.checkScholarshipEligibility();

    cout << "\n=== Academic Progress ==="
         << "\nSemester: " << student.getCurrentSemester()
         << "\nCredits: " << student.getCreditsCompleted() << "\n";

    // Campus activities
    student.rechargeMealCard(500);
    student.joinClub("Pink Pony Club");
    student.attendClass("OOP Lab", 3);
    student.rain(false);
    student.takeExam("Data Structures");
    student.vguFestEvent();
    student.complainAboutDeadline();
    student.useVGUBus("VGU", "Binh Duong");
    student.rain(true);

    // Display status and activities
    student.displayStatus();
    student.displayRecentActivities();

    return 0;
}