#include <iostream>
#include <iomanip>
using namespace std;

string names[] = {"Hasan", "Engin", "Türker", "Arzu", "Şamil", "Ertan", "Veysel", "Sümeyye", "Derya", "Zeynep", "Elif", "Duru", "Mehmet", "Fatih", "Esma", "Mahmut", "Omer", "Mustafa", "Selami", "Harun", "Mert"};
string surNames[] = {"Tayfur", "Karatas", "Aydin", "Yilmaz", "Kaya", "Gur", "Lacin", "Bayrak", "Sahin", "İsik", "Gulmez", "Yaman", "Yildiz", "Hidiroglu", "Can", "Koc", "Ozdemir", "Algul", "Kucuk", "Usta", "Ucuran"};
int factors[6];
struct Student
{
    string Name;
    string Surname;
    int MidTerm;
    int Task1;
    int Task2;
    int Quiz1;
    int Quiz2;
    int EndTerm;
    int Average;
    string LetterGrade;
};

void getFactors(int factors[]);
string assignName();
string assignSurname();
int assignMark();
float calculateAverage(Student student);
string calculateLetterGrade(Student student);
void report(Student student);
float letterGradeCount[9];
void countLetterGrade(Student student);
void printLetterGrade(float letterGradeCount[], int size);
float averageClass[1000];
float calculateAverageClass(float averages[], int size);
float calculateStandardDevitation(float averageOfClass, float averages[], int size);

int main()
{
    float sumOfClass = 0;
    float highest = 0;
    float lowest = 100;
    int size;

    cout << "Enter the number of students: ";
    cin >> size;

    getFactors(factors);

    //This for loop is for creating students
    for(int i = 0; i < size; i++)
    {
        Student student;
        student.Name = assignName();
        student.Surname = assignSurname();
        student.MidTerm = assignMark();
        student.Task1 = assignMark();
        student.Task2 = assignMark();
        student.Quiz1 = assignMark();
        student.Quiz2 = assignMark();
        student.EndTerm = assignMark();
        student.Average = calculateAverage(student);
        calculateAverage(student);
        student.LetterGrade = calculateLetterGrade(student);
        averageClass[i] = student.Average;
        report(student);
        countLetterGrade(student);

        //This if statement is for finding highest average
        if (student.Average > highest)
        {
            highest = student.Average;
        }

        //This if statement is for finding lowest average
        if (student.Average < lowest)
        {
            lowest = student.Average;
        }
    }

    float averageOfClass = calculateAverageClass(averageClass, size);
    printLetterGrade(letterGradeCount, size);
    cout << endl << "Average of class: " << averageOfClass << endl;
    cout << "Standard Deviation: " << calculateStandardDevitation(averageOfClass, averageClass, size) << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;

    return 0;
}

void getFactors(int factors[])
{
    int midTermFactor = 20;
    int task1Factor = 20;
    int task2Factor = 20;
    int quiz1Factor = 20;
    int quiz2Factor = 20;

    //This loop is for getting factors
    do
    {
        //This if statement is for warning user if sum of factors is not equal to 100
        if(midTermFactor + task1Factor + task2Factor + quiz1Factor + quiz2Factor != 100)
        {
            cout << "The sum of factors must be equal to 100" << endl;
        }
        cout << "Enter factor of midterm: ";
        cin >> midTermFactor;

        cout << "Enter factor of task1: ";
        cin >> task1Factor;

        cout << "Enter factor of task2: ";
        cin >> task2Factor;

        cout << "Enter factor of Quiz1: ";
        cin >> quiz1Factor;

        cout << "Enter factor of Quiz2: ";
        cin >> quiz2Factor;
    }
    while (midTermFactor + task1Factor + task2Factor + quiz1Factor + quiz2Factor != 100);

    factors[0] = midTermFactor;
    factors[1] = task1Factor;
    factors[2] = task2Factor;
    factors[3] = quiz1Factor;
    factors[4] = quiz2Factor;
    factors[5] = 100 - (midTermFactor + task1Factor + task2Factor + quiz1Factor + quiz2Factor);

    cout << "Enter in terms of percentage" << endl;
    int InTermsOfPercentage;
    cin >> InTermsOfPercentage;

    int endTermFactor = 100 - ((midTermFactor + task1Factor + task2Factor + quiz1Factor + quiz2Factor) * InTermsOfPercentage) / 100;

    factors[0] = midTermFactor * InTermsOfPercentage / 100;
    factors[1] = task1Factor * InTermsOfPercentage / 100;
    factors[2] = task2Factor * InTermsOfPercentage / 100;
    factors[3] = quiz1Factor * InTermsOfPercentage / 100;
    factors[4] = quiz2Factor * InTermsOfPercentage / 100;
    factors[5] = endTermFactor;

    cout << endl << "**********************************" << endl;
    cout << "Midterm factor: " << factors[0] << endl;
    cout << "Task1 factor: " << factors[1] << endl;
    cout << "Task2 factor: " << factors[2] << endl;
    cout << "Quiz1 factor: " << factors[3] << endl;
    cout << "Quiz2 factor: " << factors[4] << endl;
    cout << "Endterm factor: " << factors[5] << endl;
    cout << "**********************************" << endl << endl;
};

string assignName()
{
    return names[rand() % 20];
};

string assignSurname()
{
    return surNames[rand() % 20];
};

int assignMark()
{
    int random = rand() % 100 + 1;

    //This if statement is for assigning mark according to random number
    if (random <= 20)
    {
        return rand() % 21 + 80;
    }
    else if (random <= 70)
    {
        return rand() % 31 + 50;
    }
    else
    {
        return rand() % 51;
    }
};

float calculateAverage(Student student)
{
    return (student.MidTerm * factors[0] + student.Task1 * factors[1] + student.Task2 * factors[2] + student.Quiz1 * factors[3] + student.Quiz2 * factors[4] + student.EndTerm * factors[5]) / 100;
};

string calculateLetterGrade(Student student)
{
    //This if statement is for assigning letter grade according to average
    if(student.Average >= 90)
    {
        return "AA";
    }
    else if(student.Average >= 85)
    {
        return "BA";
    }
    else if(student.Average >= 80)
    {
        return "BB";
    }
    else if(student.Average >= 75)
    {
        return "CB";
    }
    else if(student.Average >= 65)
    {
        return "CC";
    }
    else if(student.Average >= 58)
    {
        return "DC";
    }
    else if(student.Average >= 50)
    {
        return "DD";
    }
    else if(student.Average >= 40)
    {
        return "FD";
    }
    else
    {
        return "FF";
    }
};

void report(Student student)
{
    cout << "Name: " << student.Name << endl;
    cout << "Surname: " << student.Surname << endl;
    cout << "Midterm: " << student.MidTerm << endl;
    cout << "Task1: " << student.Task1 << endl;
    cout << "Task2: " << student.Task2 << endl;
    cout << "Quiz1: " << student.Quiz1 << endl;
    cout << "Quiz2: " << student.Quiz2 << endl;
    cout << "Endterm: " << student.EndTerm << endl;
    cout << "Average: " << student.Average << endl;
    cout << "Letter Grade: " << student.LetterGrade << endl;
    cout << "**********************************" << endl;
};

void countLetterGrade(Student student)
{
    //This if statement is for counting letter grade
    if (student.LetterGrade == "AA")
    {
        letterGradeCount[0]++;
    }
    else if (student.LetterGrade == "BA")
    {
        letterGradeCount[1]++;
    }
    else if (student.LetterGrade == "BB")
    {
        letterGradeCount[2]++;
    }
    else if (student.LetterGrade == "CB")
    {
        letterGradeCount[3]++;
    }
    else if (student.LetterGrade == "CC")
    {
        letterGradeCount[4]++;
    }
    else if (student.LetterGrade == "DC")
    {
        letterGradeCount[5]++;
    }
    else if (student.LetterGrade == "DD")
    {
        letterGradeCount[6]++;
    }
    else if (student.LetterGrade == "FD")
    {
        letterGradeCount[7]++;
    }
    else
    {
        letterGradeCount[8]++;
    }
}

void printLetterGrade(float letterGradeCount[], int size)
{
    cout << endl << "Letter Grade" << setw(10) << "Count" << setw(15) << "Percentage" << endl;
    cout << "AA" << setw(18) << letterGradeCount[0] << setw(12) << "% " << letterGradeCount[0] / size * 100 << endl;
    cout << "BA" << setw(18) << letterGradeCount[1] << setw(12) << "% " << letterGradeCount[1] / size * 100 << endl;
    cout << "BB" << setw(18) << letterGradeCount[2] << setw(12) << "% " << letterGradeCount[2] / size * 100 << endl;
    cout << "CB" << setw(18) << letterGradeCount[3] << setw(12) << "% " << letterGradeCount[3] / size * 100 << endl;
    cout << "CC" << setw(18) << letterGradeCount[4] << setw(12) << "% " << letterGradeCount[4] / size * 100 << endl;
    cout << "DC" << setw(18) << letterGradeCount[5] << setw(12) << "% " << letterGradeCount[5] / size * 100 << endl;
    cout << "DD" << setw(18) << letterGradeCount[6] << setw(12) << "% " << letterGradeCount[6] / size * 100 << endl;
    cout << "FD" << setw(18) << letterGradeCount[7] << setw(12) << "% " << letterGradeCount[7] / size * 100 << endl;
    cout << "FF" << setw(18) << letterGradeCount[8] << setw(12) << "% " << letterGradeCount[8] / size * 100 << endl;
}

float calculateAverageClass(float averages[], int size)
{
    float sumClass = 0;
    //This for loop is for calculating average of class
    for(int i = 0; i < size; i++)
    {
        sumClass += averages[i];
    }
    return sumClass / size;
};

float calculateStandardDevitation(float averageOfClass, float averages[], int size)
{
    float sum = 0;
    //This for loop is for calculating standard deviation
    for (int i = 0; i < size; i++)
    {
        sum += (averageOfClass - averages[i]) * (averageOfClass - averages[i]);
    }


    return sqrt(sum / (size - 1));
};
