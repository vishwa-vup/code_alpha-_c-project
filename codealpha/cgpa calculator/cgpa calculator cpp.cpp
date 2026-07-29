#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Course
{
private:
    string courseName;
    char grade;
    int creditHours;

public:
    Course(string name, char g, int credits)
    {
        courseName = name;
        grade = toupper(g);
        creditHours = credits;
    }

    double getGradePoint() const
    {
        switch (grade)
        {
        case 'A':
            return 10.0;
        case 'B':
            return 8.0;
        case 'C':
            return 6.0;
        case 'D':
            return 4.0;
        case 'F':
            return 0.0;
        default:
            return 0.0;
        }
    }

    int getCredits() const
    {
        return creditHours;
    }

    double getQualityPoints() const
    {
        return getGradePoint() * creditHours;
    }

    void display() const
    {
        cout << left << setw(25) << courseName
             << setw(10) << grade
             << setw(10) << creditHours
             << setw(10) << fixed << setprecision(2)
             << getGradePoint() << endl;
    }
};

class CGPACalculator
{
private:
    vector<Course> courses;

public:
    void inputCourses()
    {
        int n;

        cout << "\nEnter Number of Courses: ";
        cin >> n;

        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            string name;
            char grade;
            int credits;

            cout << "\nCourse " << i + 1 << endl;

            cout << "Course Name : ";
            getline(cin, name);

            do
            {
                cout << "Grade (A/B/C/D/F): ";
                cin >> grade;
                grade = toupper(grade);

            } while (grade != 'A' &&
                     grade != 'B' &&
                     grade != 'C' &&
                     grade != 'D' &&
                     grade != 'F');

            do
            {
                cout << "Credit Hours: ";
                cin >> credits;

            } while (credits <= 0);

            cin.ignore();

            courses.push_back(Course(name, grade, credits));
        }
    }

    void calculateCGPA()
    {
        double totalQualityPoints = 0;
        int totalCredits = 0;

        cout << "\n-----------------------------------------------\n";
        cout << "                 COURSE REPORT\n";
        cout << "-----------------------------------------------\n";

        cout << left
             << setw(25) << "Course"
             << setw(10) << "Grade"
             << setw(10) << "Credits"
             << setw(10) << "Point"
             << endl;

        cout << "-----------------------------------------------\n";

        for (const auto &course : courses)
        {
            course.display();

            totalCredits += course.getCredits();
            totalQualityPoints += course.getQualityPoints();
        }

        double cgpa = totalQualityPoints / totalCredits;

        cout << "\n-----------------------------------------------\n";

        cout << "Total Credits : " << totalCredits << endl;
        cout << "CGPA          : " << fixed << setprecision(2)
             << cgpa << endl;

        cout << "-----------------------------------------------\n";
    }
};

int main()
{
    cout << "=========================================\n";
    cout << "        CGPA CALCULATOR SYSTEM\n";
    cout << "          CodeAlpha Project\n";
    cout << "=========================================\n";

    CGPACalculator calculator;

    calculator.inputCourses();

    calculator.calculateCGPA();

    cout << "\nThank you for using the system.\n";

    return 0;
}

