#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;
using tup = tuple<double, double, int, int>; // <ratio, val, weight, index>
using Table = vector<tup>;

void print_info();
void prompt(Table&, double&);
void prompt_for_list(Table&, int);
double knapsack(Table&, double, map<int, double>&);
ostream& operator<<(ostream&, map<int, double>&);

int main()
{
    print_info();

    double size;
    Table inp;
    map<int, double> out;

    prompt(inp, size);
    cout << "\nMaximum Profit: " << knapsack(inp, size, out) << out;// << inp;
}

void prompt(Table& t, double& sz)
{
    cout << "Enter Capacity of Knapsack: ";
    cin >> sz;

    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;

    prompt_for_list(t, n);
}

void prompt_for_list(Table& t, int n)
{
    cout << "\nEnter " << n << " (val, weight) pairs. "
         <<    "\nSeparated by space.:\n\n";

    int i, wt;
    double val;
    t.resize(n);
    for (i = 0; i < n; i++)
    {
        printf("\tEnter the pair #%i: ", i + 1);
        cin >> val >> wt;
        t[i] = {val / wt, val, wt, i + 1};
    }
}

double knapsack(Table& t, double cap, map<int, double>& m)
{
    int i, n = t.size();
    double prof = 0;

    sort(t.begin(), t.end(),
            [](tup& i, tup& j) -> bool {return get<0>(i) > get<0>(j);}
            );
    for (i = 0; i < n; i++)
    {
        if (get<2>(t[i]) <= cap)
        {
            m.insert({get<3>(t[i]), 1});
            cap -= get<2>(t[i]);
            prof += get<1>(t[i]);
        }
        else
        {
            double frac_wt =  cap / get<2>(t[i]);
            double frac_val = get<0>(t[i]) * cap;
            m.insert({get<3>(t[i]), frac_wt});
            prof += frac_val;
            break;
        }
    }
    return prof;
}

ostream& operator<<(ostream& os, map<int, double>& m)
{
    os << "\n\nItem Number:\tFraction\n";
    for (auto& i : m)
        os << "Item #" << i.first << ":\t" << i.second << '\n';
    return os;
}

void print_info()
{
    cout << "\n\tFractional-Knapsack program written by"
         <<    "\n\tRISHABH SONI,SCHOLAR NO.-(20U02013)\n\n";
}
