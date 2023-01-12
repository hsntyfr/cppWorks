#include "iostream"
#include "fstream"
#include "string"

using namespace std;
ifstream read;
ifstream read2;
ifstream read3;
ofstream write;
ofstream write2;
ofstream write3;
string tampon;
string tampon2;
string tampon4;
string tampon5;
string tampon6;
string tampon7;
string tampon8;
string tampon9;
string c;
string name;
int a;
int b;
int d;
int e;
int f;
int item_status = 0;
int runt = 0;



struct date
{
    int day;
    int month;
    int year;
};


class item
{
public:
    string item_name;
    int stock;
    int price;
    date prod;
    date exp;
    
    item() : item_name("unknown"), stock(0), price(0)
    {};

    item(string _item_name, int _stock, int _price, int _p_d, int _p_m, int _p_y, int _e_d, int _e_m, int _e_y) : item_name(_item_name), stock(_stock), price(_price)
    {
        prod.day = _p_d;
        prod.month = _p_m;
        prod.year = _p_y;
        exp.day = _e_d;
        exp.month = _e_m;
        exp.year = _e_y;
    };
};

using namespace std;

void create_list();

int main()
{
    item i1, i2;
    int slct_act;
    int slct_act_menu;
    char slct_cntn;
    char slct_cntn_menu;
    int find;
    float tampon3;
    string trash;
    string updt_item;
    string dlt_item;
    int slct_strt;
    int k = 0;
    
    cout << "To reach repo press" << setw(24) << "1" << endl
         << "To reach menu and food materials press" << setw(5) << "2" << endl
         << "To reach sell and planning press" << setw(11) << "3" << endl;
    cin >> slct_strt;
    switch (slct_strt)
    {
        case 1:
                cout << "To select add new item press" << setw(4) << "1" << endl
                     << "To select delete item press" << setw(5) << "2" << endl
                     << "To select update item press" << setw(5) << "3" << endl
                     << "To select give a report press" << setw(3) << "4" << endl << endl;
                cout << "Your select is ";
                cin >> slct_act;
                
                switch (slct_act)
                {
                    case 1:
                        read.open("repo.txt");
                        //this used to check if there is any repo
                        if(!read.is_open())
                        {
                            cout << "Repository file is created" << endl;
                            write.open("repo.txt");
                            //this used to write item
                            do
                            {
                                    cout << "Item name: ";
                                    getline(cin >> ws, i1.item_name);
                                    cout << "Stock: ";
                                    cin >> i1.stock;
                                    cout << "Price of one unit: ";
                                    cin >> i1.price;
                                    cout << "Production date" << endl;
                                    cout << "Production day: ";
                                    cin >> i1.prod.day;
                                    cout << "Production month: ";
                                    cin >> i1.prod.month;
                                    cout << "Production year: ";
                                    cin >> i1.prod.year;
                                    cout << "Expiration date" << endl;
                                    cout << "Expiration day: ";
                                    cin >> i1.exp.day;
                                    cout << "Expiration month: ";
                                    cin >> i1.exp.month;
                                    cout << "Expiration year: ";
                                    cin >> i1.exp.year;
                                    cout << endl;
                                    write << "Item name: "<< i1.item_name << endl;
                                    write << "Stock: " << i1.stock << endl;
                                    write << "Price for an unit: " << i1.price << endl;
                                    write << "Production year: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl;
                                    write <<"Expiration year: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl << endl;
                                    cout << "For continue add new item press 'y'" << endl
                                         << "For exit press 'n'" << endl;
                                    cin >> slct_cntn;
                            }
                            while (slct_cntn != 'n');
                            write.close();
                        }
                        else
                        {
                            write.open("repo.txt", ios::app);
                            //this used to add new item with app mode
                            do
                            {
                                cout << "Item name: ";
                                getline(cin >> ws, i1.item_name);
                                write << "Item name: "<< i1.item_name << endl;
                                cout << "Stock: ";
                                cin >> i1.stock;
                                write << "Stock: " << i1.stock << endl;
                                cout << "Price of one unit: ";
                                cin >> i1.price;
                                write << "Price for an unit: " << i1.price << endl;
                                cout << "Production date" << endl;
                                cout << "Production day: ";
                                cin >> i1.prod.day;
                                cout << "Production month: ";
                                cin >> i1.prod.month;
                                cout << "Production year: ";
                                cin >> i1.prod.year;
                                write << "Production year: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl;
                                cout << "Expiration date" << endl;
                                cout << "Expiration day: ";
                                cin >> i1.exp.day;
                                cout << "Expiration month: ";
                                cin >> i1.exp.month;
                                cout << "Expiration year: ";
                                cin >> i1.exp.year;
                                write <<"Expiration year: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl << endl;
                                cout << "For continue add new item press 'y'" << endl
                                << "For exit press 'n'" << endl;
                                cin >> slct_cntn;
                            }
                            while (slct_cntn != 'n');
                            write.close();
            
                        };
                        break;
            
            
                    case 2:
                        read.open("repo.txt");
                        write.open("repo2.txt");
                        cout << "Enter item wanted to delete" << endl;
                        getline(cin >> ws, dlt_item);
                        while(!read.eof())
                        {
                            read.ignore(100, ':') >> i1.item_name;
                            //used for doesnt duplicate last item or if updated item at last as well duplicate becomes cause of eof
                            if(i1.item_name == tampon2 || i2.item_name == tampon2)
                                {
                                    break;
                                };
                            read.ignore(100, ':') >> i1.stock;
                            read.ignore(100, ':') >> i1.price;
                            read.ignore(100, ':') >> tampon4;
                            find = (int) tampon4.find('/');
                            i1.prod.day = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.prod.month = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.prod.year = stoi(tampon4.substr(0 , find));
                            read.ignore(100, ':') >> tampon4;
                            find = (int) tampon4.find('/');
                            i1.exp.day = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.exp.month = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.exp.year = stoi(tampon4.substr(0 , find));
            
                            tampon2 = i1.item_name;
                            //used for delete
                            if(i1.item_name == dlt_item)
                            {
                                cout << "Informations about deleted item" << endl
                                     << "Item name: " << i1.item_name << endl
                                     << "Stock: " << i1.stock << endl
                                     << "Price for an unit: " << i1.price << endl
                                     << "Produciton date: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl
                                     << "Expiration date: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl << endl;
                            }
                            else
                            {
                                write << "Item name: "<< i1.item_name << endl;
                                write << "Stock: " << i1.stock << endl;
                                write << "Price for an unit: " << i1.price << endl;
                                write << "Production date: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl;
                                write << "Expiration date: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl << endl;
                            }
                        }
                        read.close();
                        write.close();
                        remove("repo.txt");
                        rename("repo2.txt", "repo.txt");
            
                        break;
                    case 3:
            
                        read.open("repo.txt");
                        write.open("repo2.txt");
                        cout << "Enter item wanted to update" << endl;
                        getline(cin >> ws, updt_item);
                        while(!read.eof())
                        {
                            read.ignore(100, ':') >> i1.item_name;
                            //used for doesnt duplicate last item or if updated item at last as well duplicate becomes cause of eof
                            if(i1.item_name == tampon2 || i2.item_name == tampon2) ////neden i2 ile işlem var buna bi bak
                                {
                                    break;
                                };
                            read.ignore(100, ':') >> i1.stock;
                            read.ignore(100, ':') >> i1.price;
                            read.ignore(100, ':') >> tampon4;
                            find = (int) tampon4.find('/');
                            i1.prod.day = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.prod.month = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.prod.year = stoi(tampon4.substr(0 , find));
                            read.ignore(100, ':') >> tampon4;
                            find = (int) tampon4.find('/');
                            i1.exp.day = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.exp.month = stoi(tampon4.substr(0 , find));
                            tampon4 = tampon4.erase(0 , find +1);
                            find = (int) tampon4.find('/');
                            i1.exp.year = stoi(tampon4.substr(0 , find));
                            tampon2 = i1.item_name;
                            //used for delete
                            if(i1.item_name == updt_item)
                            {
                                cout << "Informations are already used" << endl
                                     << "Item name: " << i1.item_name << endl
                                     << "Stock: " << i1.stock << endl
                                     << "Price for an unit: " << i1.price << endl
                                     << "Produciton date: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl
                                     << "Expiration date: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl;
                                cout << "Item name: ";
                                getline(cin >> ws, i2.item_name);
                                write << "Item name: "<< i2.item_name << endl;
                                cout << "Stock: ";
                                cin >> i2.stock;
                                write << "Stock: " << i2.stock << endl;
                                cout << "Price of one unit: ";
                                cin >> i2.price;
                                write << "Price for an unit: " << i2.price << endl;
                                cout << "Production date" << endl;
                                cout << "Production day: ";
                                cin >> i2.prod.day;
                                cout << "Production month: ";
                                cin >> i2.prod.month;
                                cout << "Production year: ";
                                cin >> i2.prod.year;
                                write << "Production year: " << i2.prod.day << "/" << i2.prod.month << "/" << i2.prod.year << endl;
                                cout << "Expiration date" << endl;
                                cout << "Expiration day: ";
                                cin >> i2.exp.day;
                                cout << "Expiration month: ";
                                cin >> i2.exp.month;
                                cout << "Expiration year: ";
                                cin >> i2.exp.year;
                                write << "Production year: " << i2.exp.day << "/" << i2.exp.month << "/" << i2.exp.year << endl << endl;
                            }
                            else
                            {
                                write << "Item name: "<< i1.item_name << endl;
                                write << "Stock: " << i1.stock << endl;
                                write << "Price for an unit: " << i1.price << endl;
                                write << "Production date: " << i1.prod.day << "/" << i1.prod.month << "/" << i1.prod.year << endl;
                                write << "Expiration date: " << i1.exp.day << "/" << i1.exp.month << "/" << i1.exp.year << endl << endl;
                            }
                        }
                        read.close();
                        write.close();
                        remove("repo.txt");
                        rename("repo2.txt", "repo.txt");
            
                        break;
                    case 4:
                        break;
            
                    default:
                        break;
                }
            
            break;
            
        case 2:
            cout << "To select add new food press" << setw(4) << "1" << endl
                    << "To select delete item press" << setw(5) << "2" << endl
                    << "To select update item press" << setw(5) << "3" << endl
                    << "To select give a report press" << setw(3) << "4" << endl << endl;
               cout << "Your select is ";
               cin >> slct_act_menu;
               switch (slct_act_menu)
               {
                   case 1:
                       read.open("menu.txt");
                       read2.open("list.txt");
                       if(!read.is_open())
                       {
                           cout << "Menu and list are created" << endl;
                           write.open("menu.txt");
                           write2.open("list.txt");
                           do
                           {
                               cout << "Enter food name: ";
                               getline(cin >> ws, tampon);
                               cout << "Enter price for food: ";
                               cin >> tampon3;
                               write << tampon << "___________________" << tampon3 << endl;
                               cout << "Enter list for food(Press enter to add new material, to stopp press '*' and enter" << endl
                                    << "You have to use this format Material name: Material amount" << endl;
                               write2 << "For " << tampon << " materials" << endl;
                               getline(cin >> ws, tampon2, '*');
                               write2 << tampon2;
                               write2 << endl;
                               cout << "Do you want to add new food" << endl
                               << "For yes press 'y' or not press 'n'" << endl;
                               cin >> slct_cntn_menu;
                           }
                           while (slct_cntn_menu != 'n');
                           write.close();
                           write2.close();
                           read.close();
                           read2.close();
                       }
                       else if(read.is_open() && read2.is_open())
                       {
                           write.open("menu.txt", ios::app);
                           write2.open("list.txt", ios::app);
                           do
                           {
                               cout << "Enter food name: ";
                               getline(cin >> ws, tampon);
                               cout << "Enter price for food: ";
                               cin >> tampon3;
                               write << tampon << "___________________" << tampon3 << endl;
                               cout << "Enter list for food(Press enter to add new material, to stopp press '*' and enter" << endl
                                    << "You have to use this format Material name: Material amount" << endl;
                               write2 << "For " << tampon << " materials" << endl;
                               getline(cin >> ws, tampon2, '*');
                               write2 << tampon2;
                               write2 << endl;
                               cout << "Do you want to add new food" << endl
                               << "For yes press 'y' or not press 'n'" << endl;
                               cin >> slct_cntn_menu;
                           }
                           while (slct_cntn_menu != 'n');
                           write.close();
                           write2.close();
                           read.close();
                           read2.close();
                       }
                       else
                       {
                           cout << "There is a problem that if there are files" << endl;
                       }
                       break;
           
                   case 2:
                       cout << "Enter food name wanted to delete" << endl;
                       getline(cin >> ws, dlt_item);
                       read.open("menu.txt");
                       write2.open("menu2.txt");
                       read3.open("list.txt");
                       write3.open("list2.txt");
                       //this loop used to write updated menu
                       while(!read.eof())
                       {
                           getline(read >> ws, tampon);
                           a = (int)tampon.find('_');
                           b = (int)tampon.find_last_of('_');
                           c = tampon.substr(b + 1 , tampon.length());
                           tampon = tampon.substr(0, a);
                           //used to find deleted item and block duplicate
                           if(tampon == dlt_item && tampon != tampon2)
                           {
                               cout << tampon << " is deleted" << endl << endl;
                               cout << "Details for deleted item" << endl;
                               tampon2 = tampon;
                           }
                           else if(tampon != tampon2)
                           {
                               write2 << tampon << "___________________" << c << endl;
                               tampon2 = tampon;
                           };
                       };
                       //this loop is used to write updated list
                       while (!read3.eof())
                       {
                           getline(read3 >> ws, tampon5);
                           //this condition chech if line is food name or materials
                           if(tampon5[0] == 'F' && tampon5[1] == 'o' && tampon5[2] == 'r')
                           {
                               tampon5 = tampon5.substr(4, tampon5.length() - 14);
                               //it checks read string if equal item wanted to delete
                               if(tampon5 == dlt_item)
                               {
                                   cout << tampon5 << endl;
                                   item_status = 1;
                               }
                               //it checks how many times program ran for deciside if it is necessary give endl
                               else if(runt == 0)
                               {
                                   write3 << "For " << tampon5 << " materials" << endl;
                                   item_status = 2;
                                   runt = 1;
                               }
                               else if (runt == 1)
                               {
                                   write3 << endl << "For " << tampon5 << " materials" << endl;
                                   item_status = 2;
                               }
                           }
                           else
                           {
                               //it checks line belongs to which item wanted to delete or nor
                               if(item_status == 1)
                               {
                                   cout << tampon5 << endl;
                               }
                               else if (item_status == 2 && tampon5 != tampon6)
                               {
                                   write3 << tampon5 << endl;
                                   tampon6 = tampon5;
                               }
                           }
                       };
                       read.close();
                       write2.close();
                       read3.close();
                       write3.close();
                       remove("menu.txt");
                       rename("menu2.txt", "menu.txt");
                       remove("list.txt");
                       rename("list2.txt", "list.txt");
                       break;
           
                   case 3:
                       read.open("menu.txt");
                       read2.open("list.txt");
                       write.open("menu2.txt");
                       write2.open("list2.txt");
                       cout << "Enter item that would updated: ";
                       getline(cin >> ws, dlt_item);
                       while (!read.eof())
                       {
                           getline(read >> ws, tampon2);
                           tampon4 = tampon2;
                           a = (int)tampon4.find('_');
                           tampon4 = tampon4.substr(0, a);
                           //this used to match updated food and already exist food
                           if(dlt_item == tampon4)
                           {
                               cout << "Enter new details for food" << endl;
                               cout << "Food name: ";
                               getline(cin >> ws, tampon5);
                               cout << "Food price: ";
                               cin >> tampon6;
                               write << tampon5 << "___________________" << tampon6 << endl;
                           }
                           else if(tampon2 != tampon7)
                           {
                               write << tampon2 << endl;
                               tampon7 = tampon2;
                           }
                       }
                       while (!read2.eof())
                       {
                           getline(read2 >> ws, tampon);
                           //this condition chech if line is food name or materials
                           if(tampon[0] == 'F' && tampon[1] == 'o' && tampon[2] == 'r')
                           {
                               tampon = tampon.substr(4, tampon.length() - 14);
                               //it checks read string if equal item wanted to delete
                               if(tampon == dlt_item)
                               {
                                   //it checks new item writen if at the top
                                   if(runt == 0)
                                   {
                                       write2 << "For " << tampon5 << " materials" << endl;
                                       cout << "Enter list for food(Press enter to add new material, to stopp press '*' and enter" << endl;
                                       getline(cin >> ws, tampon5, '*');
                                       write2 << tampon5;
                                       write2 << endl;
                                   }
                                   else
                                   {
                                       write2 << endl << "For " << tampon5 << " materials" << endl;
                                       cout << "Enter list for food(Press enter to add new material, to stopp press '*' and enter" << endl;
                                       getline(cin >> ws, tampon5, '*');
                                       write2 << tampon5;
                                   }
                                   item_status = 1;
                               }
                               //it checks how many times program ran for deciside if it is necessary give endl
                               else if(runt == 0)
                               {
                                   write2 << "For " << tampon << " materials" << endl;
                                   item_status = 2;
                                   runt = 1;
                               }
                               else if (runt == 1)
                               {
                                   write2 << endl << "For " << tampon << " materials" << endl;
                                   item_status = 2;
                               }
                           }
                           else
                           {
                               //it checks line belongs to which item wanted to delete or nor
                               if(item_status == 2 && tampon != tampon6)
                               {
                                   write2 << tampon << endl;
                                   tampon6 = tampon;
                               }
                           }
                       };
                       read.close();
                       read2.close();
                       write.close();
                       write2.close();
                       remove("menu.txt");
                       rename("menu2.txt", "menu.txt");
                       remove("list.txt");
                       rename("list2.txt", "list.txt");
                       break;
           
                   case 4:
                       break;
           
           
                   default:
                       break;
               }
            break;
        case 3:
            read.open("menu.txt");
            read2.open("list.txt");
            read3.open("repo.txt");
            cout << "Enter number of every food for today if you dont want to cook it give 0" << endl;
            while (!read.eof() && !read2.eof())
            {

                getline(read >> ws, tampon);
                a = (int)tampon.find('_');
                tampon = tampon.substr(0, a);
                if(tampon != tampon2)
                {
                    cout << tampon << ":";
                    cin >> k;
                    
                    getline(read2 >> ws, tampon4);
                    if(tampon4[0] == 'F' && tampon4[1] == 'o' && tampon4[2] == 'r')
                    {
                        while (!read2.eof())
                        {
                            getline(read2 >> ws, tampon4);
                            if(tampon4[0] == 'F' && tampon4[1] == 'o' && tampon4[2] == 'r')
                            {
                                read2.seekg(b);
                                cout << endl;
                                break;
                            }
                            if(tampon5 != tampon4)
                            {
                                tampon5 = tampon4;
                                d = (int)tampon4.find(':');
                                tampon8 = tampon4.substr(0, d);
                                tampon9 = tampon4.substr(d + 1, tampon4.length());
        //                        cout << tampon8 << endl;
        //                        cout << tampon9 << endl;

                                while (!read3.eof())
                                {
                                    getline(read3, tampon6);
                                    e = (int)tampon6.find(':');
                                    if(tampon6[0] == 'I' && tampon6[1] == 't' && tampon6[2] == 'e' && tampon6[3] == 'm' )
                                    {
                                        tampon6 = tampon6.substr(e + 2, tampon6.length());
                                        if(tampon6 == tampon8)
                                        {
                                            cout << "olumlu" << endl;
                                        }
                                        else
                                        {
                                            cout << "olumsuz" << endl;
                                        }
                                    }


                                }
                                
                                
                            }
                            b = (int)read2.tellg();
                            
                        }
                    }
                    
                    
                    
        //            do
        //            {
        //                getline(read2 >> ws, tampon4);
        //                if(tampon4[0] == 'F' && tampon4[1] == 'o' && tampon4[2] == 'r')
        //                {
        //
        //                }
        //                else
        //                {
        //                    getline(read2 >> ws, tampon4);
        //                    cout << tampon4 << endl;
        //                }
        //
        //            }
        //            while (!read2.eof() && tampon4[0] != 'F' && tampon4[1] != 'o' && tampon4[2] != 'r');
                    
                }

                tampon2 = tampon;
            }
            break;
            
        default:
            break;
    }
    return 0;
}
