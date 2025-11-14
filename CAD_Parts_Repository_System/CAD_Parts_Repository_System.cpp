// CAD_Parts_Repository_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<stack>
#include <memory>
#include<utility>
#include<algorithm>
#include<exception>
#include"part.h"
#include"pipe.h"
#include"valve.h"
#include"elbow.h"
#include"flange.h"
#include"display_template.h"
using namespace std;

bool compare(unique_ptr<part>& p1, unique_ptr<part>& p2)    //Compare function to compare two parts through operator overloading
{
    bool is_smaller = false;
    if (*p1 < *p2)
    {
        is_smaller = true;
    }
    return is_smaller;
}

int main()
{
    int choice;
    vector<unique_ptr<part>>vec;    //Vector to store unique pointers pointing to objects of part

    while (true)
    {
        cout << "<============= CAD Parts Repository System =============>";
        cout << endl;
        cout << "Press 1 to add a part" << endl;
        cout << "Press 2 to view all parts" << endl;
        cout << "Press 3 to search for a part" << endl;
        cout << "Press 4 to delete a part" << endl;
        cout << "Press 5 to sort parts based on diameters" << endl;
        cout << "Press 6 to exit" << endl << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int choice2;
            cout << endl;
            cout << "Press 1 to add a Pipe" << endl;
            cout << "Press 2 to add a Valve" << endl;
            cout << "Press 3 to add an Elbow" << endl;
            cout << "Press 4 to add a flange" << endl << endl;

            cout << "Enter your choice: ";
            cin >> choice2;
            cout << endl << endl;
            if (choice2 == 1)
            {
                string id;
                string name = "Pipe";
                string material;
                double diameter;
                double length;
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter material: ";
                cin >> material;
                cout << "Enter diameter: ";
                cin >> diameter;
                cout << "Enter length: ";
                cin >> length;
                cout << endl << endl;

                try            // Implementation of the exception handling
                {
                    unique_ptr<part> pp1 = make_unique<pipe>(id, name, material, diameter, length);
                    vec.push_back(move(pp1));
                    cout << "Pipe added successfully" << endl << endl;
                }
                catch (const exception& e)
                {
                    cout << "Message = " << e.what() << endl << endl;
                }
            }

            else if (choice2 == 2)
            {
                string id;
                string name = "Valve";
                string material;
                double diameter;
                double thickness;
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter material: ";
                cin >> material;
                cout << "Enter diameter: ";
                cin >> diameter;
                cout << "Enter thickness: ";
                cin >> thickness;
                cout << endl << endl;

                try                 // Implementation of the exception handling
                {
                    unique_ptr<part> pv1 = make_unique<valve>(id, name, material, diameter, thickness);
                    vec.push_back(move(pv1));
                    cout << "Valve added successfully" << endl << endl;
                }
                catch (const exception& e)
                {
                    cout << "Message = " << e.what() << endl << endl;
                }
            }

            else if (choice2 == 3)
            {
                string id;
                string name = "Elbow";
                string material;
                double diameter;
                double angle;
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter material: ";
                cin >> material;
                cout << "Enter diameter: ";
                cin >> diameter;
                cout << "Enter angle: ";
                cin >> angle;
                cout << endl << endl;


                try                 // Implementation of the exception handling
                {
                    unique_ptr<part> pe1 = make_unique<elbow>(id, name, material, diameter, angle);
                    vec.push_back(move(pe1));
                    cout << "Elbow added successfully" << endl << endl;
                }
                catch (const exception& e)
                {
                    cout << "Message = " << e.what() << endl << endl;
                }
            }

            else if (choice2 == 4)
            {
                string id;
                string name = "Flange";
                string material;
                double diameter;
                double height;
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter material: ";
                cin >> material;
                cout << "Enter diameter: ";
                cin >> diameter;
                cout << "Enter height: ";
                cin >> height;
                cout << endl << endl;

                try                 // Implementation of the exception handling
                {
                    unique_ptr<part> pf1 = make_unique<flange>(id, name, material, diameter, height);
                    vec.push_back(move(pf1));
                    cout << endl;
                }
                catch (const exception& e)
                {
                    cout << "Message = " << e.what() << endl << endl;
                }
            }

            else
            {
                cout << "Invalid choice!" << endl << endl;
            }

            break;
        }
            

            case 2: 
            {
                try
                {
                    display<unique_ptr<part>>(vec);     //Calling display function where T is unique pointers pointing to objects of part
                }
                catch (const exception& e)
                {
                    cout << "Message = " << e.what() << endl << endl;
                }
                
                break;
            }

            case 3:                                   // Searching feature
            {
                if (vec.empty())
                {
                    cout << "No shapes to search!" << endl << endl;
                    break;
                }
                string id;
                cout << "Enter id to search: ";
                cin >> id;
                cout << endl;
                bool found = false;
                for (auto& p : vec)
                {
                    found = (*p = id);
                    if (found)
                    {
                        cout << "Part found with id: " << id << endl << endl;
                        break;
                    }
                }
                if (found == false)
                {
                    cout << "Part not found with id: " << id << endl << endl;
                }
                break;
            }

            case 4:                                     // Delete feature
            {
                if (vec.empty())
                {
                    cout << "No shapes to delete!" << endl << endl;
                    break;
                }
                string id;
                cout << "Enter id of the part to delete: ";
                cin >> id;
                cout << endl << endl;
                bool found = false;
                int count = 0;
                for (auto& p : vec)
                {
                    if (id == p->get_id())
                    {
                        found = true;
                        break;
                    }
                    count++;
                }
                if (found)
                {
                    vec.erase(vec.begin() + count);
                    cout << "Part deleted successfully" << endl << endl;
                }
                if (found == false)
                {
                    cout << "Part not found with id: " << id << endl << endl;
                }
                break;
            }

            case 5:                             // Sort by diameter feature
            {
                if (vec.empty())
                {
                    cout << "No shapes to sort!" << endl << endl;
                    break;
                }
                sort(vec.begin(), vec.end(), compare);
                cout << "Parts have been sorted successfully" << endl << endl;
                break;
            }

            case 6:                             // Exit
            {
                cout << "Program exited successfully" << endl << endl;
                return 0;
            }

        default:                                // For invalid selection
        {
            cout << "Invalid choice" << endl << endl;
            break;
        }
        }
    }

    // Implementation of shared pointers
    string id = "1IA023";
    string name = "Pipe";
    string material = "Iron";
    double diameter = 56.4;
    double length = 172.5;
    shared_ptr<part> pp2 = make_shared<pipe>(id, name, material, diameter, length);    
    shared_ptr<part> pp3 = pp2;                                                         // These pointers will get deleted automatically

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
