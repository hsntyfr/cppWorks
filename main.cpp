#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

string names[30] = {"Hasan" , "Engin" , "Arzu" , "Samil" , "Ertan" , "Veysel", "Umran" , "Sumeyye" , "Veli" , "Baris" ,
                    "Derya" , "Elif" , "Zeynep" , "Mehmet" , "Fatih" , "Mert" , "Bekir" , "Suveyda" , "Bahar" , "Hilal" ,
                    "Polat" , "Ilayda" , "Hacer" , "Ali" , "Duru" , "Yunus" , "Mahmud" , "Humeyra" , "Esad" , "Zuleyha"};
    
string surnames[30] = {"Tayfur" , "Karatas" , "Kaya" , "Yilmaz" , "Onal" , "Yildiz" , "Sahin" , "Atli" , "Kilic" , "Dilli" ,
                       "Aydin" , "Aksoy" , "Lacin" , "Simsek" , "Ipekci" , "Bayram" , "Akyuz" , "Ozdal" , "Saritas","Durukan" ,
                       "Yildirim" , "Toprak" , "Demir" , "Gunes" , "Ozcan" , "Batur" , "Altay" , "Cesur" , "Kahraman" , "Alemdar"};

struct date
{
    int day;
    int month;
    int year;
};

struct student
{
    string name;
    string surname;
    int number;
    int quiz1;
    int quiz2;
    int task1;
    int task2;
    int project;
    int midterm;
    int final;
    date birthday;
};

void mark(int);
student read();
student random_student0_40();
student random_student40_70();
student random_student70_80();
student random_student80_100();
float calculate(student);

int main()
{
    srand( (unsigned int) time(NULL) );
    
    int select_method_stack , select_action ;
    int index_of_array = 0;
    int capacity_of_group = 20;
    int capacity = 1;
    
    float max_mark = 0;
    float min_mark = 100;
    float sum = 0;
    float less_than = 0;
    float high_than = 0;
    float between_first = 0;
    float between_second = 0;
    float average = 0;
    float standard_levitation = 0;
    float standard_levitation_sum = 0;
    
    char select_continue;
    char re_select;
    char select_new_fill;
    
    student stack[100];
    float notes[100];
    
    cout << "If you want to create randomly student press" << setw(11) << "1" << endl
    << "If you want to give a values for uniq student press" << setw(4) << "2" << endl;
    cin >> select_method_stack;

    switch (select_method_stack)
    {
    case 1:
            capacity = 100;
        //this loop is used to create a random student for each member of stack thanks to random_student function
        for (int i = 0 ; i < capacity ; i++)
        {
            //this condition is used to append a mark in selected ratio
            if (i < 10)
            {
                stack[i] = random_student0_40();
            }
            else if (i < 60 && i > 9)
            {
                stack[i] = random_student40_70();
            }
            else if (i < 75 && i > 59)
            {
                stack[i] = random_student70_80();
            }
            else if (i < 100 && i > 74)
            {
                stack[i] = random_student80_100();
            }

        }
            
        break;

    case 2:
         //this loop is used to give student details for each member of stack thanks to read function
         for (int i = 0 ; i < capacity ; i++)
         {
             cout << "Now you are filling " << i + 1 << ". student" << endl;
             stack[i] = read();
             cout << "Do you want to add new students?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
             cin >> select_new_fill;
             if (select_new_fill != 'n' && capacity < 100)
             {
                 capacity++;
             }
             capacity_of_group = capacity;
         }
        break;
            
    default:
            cout << "Your select is wrong." << endl;
            exit(0);
        break;
    }
    //this loop is used to calculate end year mark for each member of stack thanks to calculate function
    for (int i = 0 ; i < capacity ; i++)
    {
        notes[i] = calculate(stack[i]);
    }
    cout << "Students are created" << endl << endl;
    //this loop is used to make re-select
    do
    {
        
        cout << "If you want to see students as a group of 20 press " << setw(14) << "1"<< endl
        << "If you want to see the highest mark between all students press " << setw(2) << "2"  << endl
        << "If you want to see the lowest mark between all students press " << setw(3) << "3" << endl
        << "If you want to see average that all students press " << setw(14) << "4" << endl
        << "If you want to see standard levitation press " << setw(20) << "5" << endl
        << "If you want to see a group of mark that you determine press " << setw(5) << "6" << endl
        << "If you want to see students which have mark less than x press " << setw(3) << "7" << endl
        << "If you want to see students which have mark high than x press " << setw(3) << "8" << endl;
        
        cin >> select_action;
        
        switch (select_action)
        {
            case 1:
                //this loop is used to print students as a group of 20
                do
                {
                    cout << setw(9) << "Name"
                    << setw(10) << "Surname"
                    << setw(10) <<  "Number"
                    << setw(12) <<  "First quiz"
                    << setw(14) <<  "Second quiz"
                    << setw(14) <<  "First task"
                    << setw(14) <<  "Second task"
                    << setw(12) <<  "Project"
                    << setw(10) <<  "Midterm"
                    << setw(9) <<  "Final"
                    << setw(7) <<  "Day"
                    << setw(7) <<  "Month"
                    << setw(7) <<  "Year"
                    << setw(14)<< "Letter mark" << endl;
                    //this loop is used to print all students for groups of 20
                    for (int i = index_of_array ; i < capacity_of_group ; i++)
                    {
                        cout << setw(9) << stack[i].name
                        << setw(10) << stack[i].surname
                        << setw(10) << stack[i].number
                        << setw(12) << stack[i].quiz1
                        << setw(14) << stack[i].quiz2
                        << setw(14) << stack[i].task1
                        << setw(14) << stack[i].task2
                        << setw(12) << stack[i].project
                        << setw(10) << stack[i].midterm
                        << setw(9) << stack[i].final
                        << setw(7) << stack[i].birthday.day
                        << setw(7) << stack[i].birthday.month
                        << setw(7) << stack[i].birthday.year
                        << setw(9);
                        mark(notes[i]);
                        
                    }

                    cout << "Do you want to see another 20 students as a group?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                    cin >> select_continue;
                    index_of_array += 20;
                    capacity_of_group += 20;
                    system("clear");
                    //this condition is used to exit when is reached the last index of the array"
                    if (index_of_array == 100)
                    {

                        break;
                    }

                }
                while (select_continue != 'n' && index_of_array < 100);
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 2:
                //this loop is used firstly to compare all marks in class then announce the highest mark
                for (int i = 0 ; i < capacity ; i++)
                {
                    //this condition is used to compare all marks then attend the highest mark in max_mark value
                    if (notes[i] > max_mark)
                    {
                        max_mark = notes[i];
                    }
                }
                cout << "The highest mark in class is "<< max_mark << endl;
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 3:
                //this loop is used firstly to compare all marks in class then announce the lowest mark
                for (int i = 0 ; i < capacity ; i++)
                {
                    //this condition is used to compare all marks then attend the lowest mark in min_mark value
                    if (notes[i] < min_mark)
                    {
                        min_mark = notes[i];
                    }
                }
                cout << "The lowest mark in class is "<< min_mark << endl;
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 4:
                //this loop is used to calculate average mark for all students then print average mark
                for (int i = 0 ; i < capacity ; i++)
                {
                    sum = sum + notes[i];
                }
                average = sum / 100;
                cout << "The average mark in class is " << average << endl;
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 5:
                //this loop is used to calculate average mark for all students then attend in average value
                for (int i = 0 ; i < capacity ; i++)
                {
                    sum = sum + notes[i];
                }
                average = sum / 100;
                //this loop is used to calculate standard levitation for all students then print standard levitation
                
                for (int i = 0 ; i < capacity ; i++)
                {
                    standard_levitation_sum = standard_levitation_sum + pow(notes[i] - average , 2);
                }
                standard_levitation = sqrt (standard_levitation_sum / 99);
                cout << "Standard levitation is " << standard_levitation << endl;
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 6:
                cout << "To list marks between two value give two value" << endl;
                cout << "Give first value" << endl;
                cin >> between_first;
                cout << "Give second value" << endl;
                cin >> between_second;
                
                //this condition is used to decide which value that between values are given by user is bigger
                if (between_first > between_second)
                {
                    cout << "The marks between " << between_first << " and " << between_second << " are " << endl;
                    //this loop is used to list marks which between first value and second value
                    for (int i = 0 ; i < capacity ; i++)
                    {
                        //this condition is used to list marks that between two values that is given by user
                        if (notes[i] < between_first && notes[i] > between_second)
                        {
                            cout << notes[i] << endl;
                        }
                    }
                }
                else if (between_first == between_second)
                {
                    cout << "Your choice are wrong" << endl;
                }
                else
                {
                    cout << "The marks between " << between_first << " and " << between_second << " are " << endl;
                    //this loop is used to list marks which between first value and second value
                    for (int i = 0 ; i < capacity ; i++)
                    {
                        //this condition is used to list marks that between two values that is given by user
                        if (notes[i] > between_first && notes[i] < between_second)
                        {
                            cout << notes[i] << endl;
                        }
                    }
                }
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 7:
                cout << "To list marks that less than 'x' give a value" << endl;
                cin >> less_than;
                cout << "Marks which less than 'x' are " << endl;
                
                //this loop is used to list marks which less than value that is given by user
                for (int i = 0 ; i < capacity ; i++)
                {
                    //this condition is used to compare marks and value which is given by user
                    if (notes[i] < less_than)
                    {
                        cout << notes[i] << endl;
                    }
                }
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            case 8:
                cout << "To list marks that high than 'x' give a value" << endl;
                cin >> high_than;
                cout << "Marks which high than 'x' are " << endl;
                
                //this loop is used to list marks which high than value that is given by user
                for (int i = 0 ; i < capacity ; i++)
                {
                    //this condition is used to compare marks and value which is given by user
                    if (notes[i] > high_than)
                    {
                        cout << notes[i] << endl;
                    }
                }
                cout << "Do you want to select new action?" << endl << "For yes press 'y'" << endl << "For no press 'n'" << endl;
                cin >> re_select;
                break;
                
            default:
                cout << "Your select is wrong." << endl;
                exit(0);
                break;
        }
    }
    while (re_select != 'n');
    
    return 0;
}

void mark(int mark)
{
    //this condition is used to decide if marks between 100 and 90
    if (mark >= 90 && mark <= 100)
    {
        cout << "AA" << endl << endl;
    }
    //this condition is used to decide if marks between 90 and 85
    else if (mark < 90 && mark >= 85)
    {
        cout << "BA" << endl << endl;
    }
    //this condition is used to decide if marks between 85 and 80
    else if (mark < 85 && mark >= 80)
    {
        cout << "BB" << endl << endl;
    }
    //this condition is used to decide if marks between 80 and 70
    else if (mark < 80 && mark >= 70)
    {
        cout << "CB" << endl << endl;
    }
    //this condition is used to decide if marks between 70 and 60
    else if (mark < 70 && mark >= 60)
    {
        cout << "CC" << endl << endl;
    }
    //this condition is used to decide if marks between 60 and 50
    else if (mark < 60 && mark >= 50)
    {
        cout << "DC" << endl << endl;
    }
    //this condition is used to decide if marks between 50 and 40
    else if (mark < 50 && mark >= 40)
    {
        cout << "FD" << endl << endl;
    }
    //this condition is used to decide if marks less than 40
    else
    {
        cout << "FF" << endl << endl;
    }
};

student read()
{
    student person;
   
    cout << "Write students name" << endl;
    cin >> person.name;
    cout << "Students name is " << person.name << endl << endl;
        
    cout << "Write students surname" << endl;
    cin >> person.surname;
    cout << "Students surname is " << person.surname << endl << endl;
        
    cout << "Write students number" << endl;
    cin >> person.number;
    cout << "Students number is " << person.name << endl << endl;
        
    cout << "Write students first quiz mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.quiz1;
    }
    while (person.quiz1 > 100 || person.quiz1 < 0 );
    cout << "Students first quiz mark is " << person.quiz1 << " and mark equals ";
    mark(person.quiz1);
        
    cout << "Write students second quiz mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.quiz2;
    }
    while (person.quiz2 > 100 || person.quiz2 < 0 );
    cout << "Students second quiz mark is " << person.quiz2 << " and mark equals ";
    mark(person.quiz2);
        
    cout << "Write students first task mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.task1;
    }
    while (person.task1 > 100 || person.task1 < 0 );
    cout << "Students first task mark is " << person.task1 << " and mark equals ";
    mark(person.task1);
        
    cout << "Write students second task mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.task2;
    }
    while (person.task2 > 100 || person.task2 < 0 );
    cout << "Students second task mark is " << person.task2 << " and mark equals ";
    mark(person.task2);
        
    cout << "Write students project mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.project;
    }
    while (person.project > 100 || person.project < 0 );
    cout << "Students project mark is " << person.project << " and mark equals ";
    mark(person.project);
        
    cout << "Write students midterm exams mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.midterm;
    }
    while (person.midterm > 100 || person.midterm < 0 );
    cout << "Students midterm exams mark is " << person.midterm << " and mark equals ";
    mark(person.midterm);
        
    cout << "Write students final mark" << endl;
    do
    //this loop is used to check mark given by user
    {
        cin >> person.final;
    }
    while (person.final > 100 || person.final < 0 );
    cout << "Students final mark is " << person.final << " and mark equals ";
    mark(person.final);
        
    cout << "Write students day of birth" << endl;
    do
    //this loop is used to check date given by user
    {
        cin >> person.birthday.day;
    }
    while (person.birthday.day > 32 || person.birthday.day < 1);
    cout << "Students day of birth is " << person.birthday.day << endl << endl;
    
        
    cout << "Write students month of birth" << endl;
    do
    //this loop is used to check date given by user

    {
        cin >> person.birthday.month;
    }
    while (person.birthday.month > 13 || person.birthday.month < 0);
    cout << "Students month of birth is " << person.birthday.month << endl << endl;
    
    cout << "Write students year of birth" << endl;
    do
    //this loop is used to check date given by user

    {
        
        cin >> person.birthday.year;
    }
    while (person.birthday.year > 2022 || person.birthday.year < 1900);
    cout << "Students year of birth is " << person.birthday.year << endl << endl;
        
    return person;
};

student random_student0_40()
{
    student person;
    
    person.name = names[rand() % 30];
    person.surname = surnames[rand() % 30];
    person.number = rand() % 500 + 750;
    person.quiz1 = rand() % 41;
    person.quiz2 = rand() % 41;
    person.task1 = rand() % 41;
    person.task2 = rand() % 41;
    person.project = rand() % 41;
    person.midterm = rand() % 41;
    person.final = rand() % 41;
    person.birthday.day = rand() % 31 + 1;
    person.birthday.month = rand() % 12 + 1;
    person.birthday.year = rand() % 122 + 1900;
    return person;
};

student random_student40_70()
{
    student person;
    
    person.name = names[rand() % 30];
    person.surname = surnames[rand() % 30];
    person.number = rand() % 500 + 750;
    person.quiz1 = rand() % 31 + 40;
    person.quiz2 = rand() % 31 + 40;
    person.task1 = rand() % 31 + 40;
    person.task2 = rand() % 31 + 40;
    person.project = rand() % 31 + 40;
    person.midterm = rand() % 31 + 40;
    person.final = rand() % 31 + 40;
    person.birthday.day = rand() % 31 + 1;
    person.birthday.month = rand() % 12 + 1;
    person.birthday.year = rand() % 122 + 1900;
    return person;
};

student random_student70_80()
{
    student person;
    
    person.name = names[rand() % 30];
    person.surname = surnames[rand() % 30];
    person.number = rand() % 500 + 750;
    person.quiz1 = rand() % 11 + 70;
    person.quiz2 = rand() % 11 + 70;
    person.task1 = rand() % 11 + 70;
    person.task2 = rand() % 11 + 70;
    person.project = rand() % 11 + 70;
    person.midterm = rand() % 11 + 70;
    person.final = rand() % 11 + 70;
    person.birthday.day = rand() % 31 + 1;
    person.birthday.month = rand() % 12 + 1;
    person.birthday.year = rand() % 122 + 1900;
    return person;
};

student random_student80_100()
{
    student person;
    
    person.name = names[rand() % 30];
    person.surname = surnames[rand() % 30];
    person.number = rand() % 500 + 750;
    person.quiz1 = rand() % 21 + 80;
    person.quiz2 = rand() % 21 + 80;
    person.task1 = rand() % 21 + 80;
    person.task2 = rand() % 21 + 80;
    person.project = rand() % 21 + 80;
    person.midterm = rand() % 21 + 80;
    person.final = rand() % 21 + 80;
    person.birthday.day = rand() % 31 + 1;
    person.birthday.month = rand() % 12 + 1;
    person.birthday.year = rand() % 100 + 1990;
    return person;
};


float calculate(student person)
{
    float in_term , end_term;
    in_term = (person.quiz1 * 7 / 100) +
              (person.quiz2 * 7 / 100) +
              (person.task1 * 10 / 100) +
              (person.task2 * 10 / 100) +
              (person.project * 16 / 100) +
              (person.midterm * 50 / 100);
    
           end_term = (in_term * 55 / 100)+
               (person.final * 45 / 100);
    return end_term;
};
