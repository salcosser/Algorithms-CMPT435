#include <string>
#include "Greedy.h"
#include "Sort.h"
#include <fstream>
#include <vector>
using namespace std;

void Greedy::setupSpices(std::string fileName)
{

    fstream newfile;

    string ln;

    bool sorted = false;
    newfile.open(fileName, ios::in);
    if (newfile.is_open())
    {
        while (getline(newfile, ln)) //read each line of the file
        {

            if (ln.find("knapsack capacity") != string::npos)
            {

                if (!sorted)
                {
                    //sort the stuff
                    Sort::mergeSort(spices, 0, spices.size() - 1);
                    sorted = true;
                }
                int cap = stoi(ln.substr(19, 3));

                cout << "**********************************" << endl;
                greedyAlgo(cap);
                cout << "**********************************" << endl;
            }
            else if (ln.find("spice name") != string::npos)
            {
                vector<string> parts;               //keeps the data points from the line

                for (int i = 0; i < ln.size(); i++)
                {
                    if (ln[i] == ';')
                    {
                        for (int j = (i - 1); j > 0; j--)
                        {
                            if (ln[j] == '=')
                            {

                                string sub = ln.substr(j + 2, (i - j) - 2);     // found the bounds of a value, so push it on

                                parts.push_back(sub);
                              
                                break;
                            }
                        }
                    }
                }

                Spice *nSpice = new Spice();            //make and push the spice
                nSpice->color = parts[0];
                nSpice->setPrice(stod(parts[1]), stod(parts[2]));
                spices.push_back(nSpice);

               
            }
        }
    }
    newfile.close();

    return;
};
void Greedy::greedyAlgo(int capacity)
{

    struct Portion
    {
        double qty;
        Spice *spice;
    };

    int cTotal = 0;
    vector<Portion *> ks;       //stores the portions
    double earnings = 0;        //stores the earnings
    while (cTotal != capacity)
    {
        // this process assumes that the items have been sorted before
       for (int i = spices.size() - 1; i > 0; i--)
        {
            if ((cTotal + spices[i]->qty) <= capacity)      //if the whole lot of the spice can fit, add it all to the knapsack
            {

                Portion *p = new Portion();
                p->qty = spices[i]->qty;
                p->spice = spices[i];
                cTotal += spices[i]->qty;
                ks.push_back(p);
                earnings += p->spice->tPrice;
            }
            else if (((capacity - cTotal) > 0) && ((cTotal + spices[i]->qty) > capacity))       //if only some can fit in the knapsack, add however much will fit
            {

                Portion *part = new Portion();
                part->qty = capacity - cTotal;
                part->spice = spices[i];
                cTotal += part->qty;
                ks.push_back(part);
                earnings += ((part->spice->uPrice) * (part->qty));
                break;
            }
        }
    }

    cout << "Knapsack of capacity " << capacity << " is worth " << earnings << " quatloos and" << endl;             //print out the earnings followed by a gramatically correct statement about the contents of the knapsack
    cout << "contains ";
    for (int n = 0; n < ks.size(); n++)
    {

        if (n == 0)
        {
            if (ks[n]->qty == 1)
            {
                cout << ks[n]->qty << " scoop of " << ks[n]->spice->color;
            }
            else
            {
                cout << ks[n]->qty << " scoops of " << ks[n]->spice->color;
            }
        }
        else
        {
            if (ks[n]->qty == 1)
            {
                cout << ", " << ks[n]->qty << " scoop of " << ks[n]->spice->color;
            }
            else
            {
                cout << ", " << ks[n]->qty << " scoops of " << ks[n]->spice->color;
            }
        }
    }
    cout << "." << endl;
}