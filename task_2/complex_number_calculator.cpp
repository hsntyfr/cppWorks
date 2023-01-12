#include "iostream"
#include "iomanip"
#include "cmath"

using namespace std;

class complex_number
{
private:
    float reel;
    float imaginer;
    float tampon;
    float tampon2;
    
public:
    complex_number() : reel(0.0), imaginer(0.0)
    {};
    
    complex_number(float _reel, float _imaginer) : reel(_reel), imaginer(_imaginer)
    {};
    
    void set_numb()
    {
        cout << "Reel part of complex number is ";
        cin >> reel;
        cout << "İmaginer part of complex number is ";
        cin >> imaginer;
    };
    
    void get_numb()
    {
        //this if used to chech whether imaginer minus or not
        if(imaginer > 0)
        {
            cout << "Complex number is " << reel << "+" << imaginer << "i" << endl;
        }
        else if (imaginer < 0)
        {
            cout << "Complex number is " << reel << imaginer << "i" << endl;
        }
        else
        {
            cout << "Complex number is " << reel << endl;
        };
    };
    
    void print_numb()
    {
        //this if used to chech whether imaginer minus or not
        if(imaginer > 0)
        {
            cout << "(" << reel << "+" << imaginer << "i" << ")";
        }
        else if (imaginer < 0)
        {
            cout << "(" << reel << imaginer << "i" << ")";
        }
        else
        {
            cout << "(" <<reel << ")";
        };
    };
    
    float get_reel()
    {
        return reel;
    };
    
    float get_imaginer()
    {
        return imaginer;
    };
    
    complex_number operator+ (complex_number c1)
    {
        complex_number c3;
        c3.reel = reel + c1.reel;
        c3.imaginer = imaginer + c1.imaginer;
        return c3;
    };
    
    complex_number operator- (complex_number c1)
    {
        complex_number c3;
        c3.reel = reel - c1.reel;
        c3.imaginer = imaginer - c1.imaginer;
        return c3;
    };
    
    complex_number operator* (complex_number c1)
    {
        complex_number c3;
        c3.reel = (reel * c1.reel) - (imaginer * c1.imaginer);
        c3.imaginer = (reel * c1.imaginer) + (imaginer * c1.reel);
        return c3;
    };
    
    complex_number operator/ (complex_number c1)
    {
        complex_number c3;
        //this if used to check complex number that in position dividing whether zero
        if(c1.reel != 0 || c1.imaginer != 0)
        {
            c3.reel = ((reel * c1.reel) + (imaginer * c1.imaginer)) / (pow(c1.reel, 2) + pow(c1.imaginer, 2));
            c3.imaginer = ((c1.reel * imaginer) - (reel * c1.imaginer)) / (pow(c1.reel, 2) + pow(c1.imaginer, 2));
        }
        else
        {
            cout << "Second complex number is 0 so division is not possible" << endl;
        };
        return c3;
    };
    
    complex_number operator+= (complex_number c1)
    {
        reel = reel + c1.reel;
        imaginer = imaginer + c1.imaginer;
        return complex_number(reel, imaginer);
    };
    
    complex_number operator-= (complex_number c1)
    {
        reel = reel - c1.reel;
        imaginer = imaginer - c1.imaginer;
        return complex_number(reel, imaginer);
    };
    
    complex_number operator*= (complex_number c1)
    {
        
        tampon = (reel * c1.reel) - (imaginer * c1.imaginer);
        tampon2 = (reel * c1.imaginer) + (imaginer * c1.reel);
        return complex_number(tampon, tampon2);
    };
    
    complex_number operator/= (complex_number c1)
    {
        
        //this if used to check complex number that in position dividing whether zero
        if(c1.reel != 0 || c1.imaginer != 0)
        {
            tampon = ((reel * c1.reel) + (imaginer * c1.imaginer)) / (pow(c1.reel, 2) + pow(c1.imaginer, 2));
            tampon2 = ((c1.reel * imaginer) - (reel * c1.imaginer)) / (pow(c1.reel, 2) + pow(c1.imaginer, 2));
        }
        else
        {
            cout << "Second complex number is 0 so division is not possible" << endl;
        };
        return complex_number(tampon, tampon2);
    };
    
};

int main()
{
    int act_in_calc;
    char subs_rev;
    int action;
    float r;
    float angle;
    char cont_calc = 'y';
    complex_number c1;
    complex_number c2;
    complex_number c3;
    cout << "To reach standard calculator press " << setw(3) << "1" << endl
         << "To reach polar notation press " << setw(8) << "2" << endl;
    cin >> action;
    switch (action)
    {
        case 1:
            //this loop is used to do calculate continuously
            do
            {
                cout << "For first complex number" << endl;
                c1.set_numb();
                cout << endl<< "For second complex number" << endl;
                c2.set_numb();
                cout << endl << "Select action" << endl
                << "For addition press" << setw(10) << "1" << endl
                << "For substraction press" << setw(6) << "2" << endl
                << "For multiplication press" << setw(4) << "3" << endl
                << "For division press" << setw(10) << "4" << endl;
                cin >> act_in_calc;
                switch (act_in_calc)
                {
                    case 1:
                        c3 = c1 + c2;
                        c3.get_numb();
                        cout << endl << "Do you want to make new calculation?" << endl
                                     << "For yes press 'y'" << endl
                                     << "For no press 'n'" << endl;
                        cin >> cont_calc;
                        break;
                        
                    case 2:
                        cout << "Now substraction will run like ";
                        c1.print_numb();
                        cout << " - ";
                        c2.print_numb();
                        cout << ", ";
                        cout << "if you want to do like ";
                        c2.print_numb();
                        cout << " - ";
                        c1.print_numb();
                        cout << " press 'y', if you continue with default press 'n'" << endl;
                        cin >> subs_rev;
                        //this if used to check if reverse subtraction calculate is wanted
                        if(subs_rev == 'y')
                        {
                            c3 = c2 - c1;
                            c3.get_numb();
                        }
                        else
                        {
                            c3 = c1 - c2;
                            c3.get_numb();
                        }
                        cout << endl << "Do you want to make new calculation?" << endl
                                     << "For yes press 'y'" << endl
                                     << "For no press 'n'" << endl;
                        cin >> cont_calc;
                        break;
                        
                    case 3:
                        c3 = c1 * c2;
                        c3.get_numb();
                        cout << endl << "Do you want to make new calculation?" << endl
                                     << "For yes press 'y'" << endl
                                     << "For no press 'n'" << endl;
                        cin >> cont_calc;
                        break;
                        
                    case 4:
                        cout << "Now divison will run like ";
                        c1.print_numb();
                        cout << " / ";
                        c2.print_numb();
                        cout << ", ";
                        cout << "if you want to do like ";
                        c2.print_numb();
                        cout << " / ";
                        c1.print_numb();
                        cout << " press 'y', if you continue with default press 'n'" << endl;
                        cin >> subs_rev;
                        //this if used to check if reverse division calculate is wanted
                        if(subs_rev == 'y')
                        {
                            //this if used to check complex number that in position dividing whether zero
                            if(c2.get_imaginer() != 0 || c2.get_reel() != 0)
                            {
                                c3 = c2 / c1;
                                c3.get_numb();
                            }
                            else
                            {
                                cout << "Dividing is not equal 0" << endl;
                            }
                        }
                        else
                        {
                            //this if used to check complex number that in position dividing whether zero
                            if(c2.get_imaginer() != 0 || c2.get_reel() != 0)
                            {
                                c3 = c1 / c2;
                                c3.get_numb();
                            }
                            else
                            {
                                cout << "Dividing is not equal 0" << endl;
                            }
                        }
                        cout << endl << "Do you want to make new calculation?" << endl
                                     << "For yes press 'y'" << endl
                                     << "For no press 'n'" << endl;
                        cin >> cont_calc;
                        break;
                        
                    default:
                        break;
                }
            }
                while (cont_calc != 'n');
                break;
            
            case 2:
            //this loop is used to do polar notation continuously
            do
            {
                c1.set_numb();
                r = sqrt (pow(c1.get_reel(), 2) + pow(c1.get_imaginer(), 2));
                angle = c1.get_imaginer() / c1.get_reel();
                cout << "For your complex number polar notation is " << "(" << setprecision(3) << r << "," << atan(angle) * 180 / 3.1415 << ")" << endl;
                cout << endl << "Do you want to make new calculation?" << endl
                             << "For yes press 'y'" << endl
                             << "For no press 'n'" << endl;
                cin >> cont_calc;
            }
            while (cont_calc != 'n');
                break;
                
            default:
                break;
    }
    return 0;
}
