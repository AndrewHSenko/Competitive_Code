/* ACM ICPC Workshop 1 Problem 4 4/12/20 */
/* https://open.kattis.com/contests/s5je2r/problems/toilet */
/* Determines amount of toilet seat adjustments necessary to adhere to always leaving the seat up, always leaving the seat down, or leaving the seat as preferred */

#include <iostream>
using namespace std;

int main() {
    string initial_pos, sequence;
    int always_up = 0, always_down = 0, always_pref = 0;
    getline(cin, sequence);
    initial_pos = sequence.substr(0, 1);
    if (sequence.substr(1, 1).compare(initial_pos) == 0) //Same position of toilet
    {
	if (initial_pos.compare("U") == 0)
	    always_down++;
	else if (initial_pos.compare("D") == 0)
	    always_up++;
    }
    else if (sequence.substr(1, 1).compare(initial_pos) != 0)
    {
	if (initial_pos.compare("U") == 0) //UD
	{
	    always_up += 2;
	    always_down++;
	    always_pref++;
	}
	else if (initial_pos.compare("D") == 0) //DU
	{
	    always_down += 2;
	    always_up++;
	    always_pref++;
	}
    }
    for (int i = 2; i < sequence.length(); i++)
    {
	if (sequence.substr(i - 1, 1).compare(sequence.substr(i, 1)) == 0) //Same position of toilet
	{
	    if (sequence.substr(i - 1, 1).compare("U") == 0) //Both prev and current pos of toilet are U
		always_down += 2;
	    else if (sequence.substr(i - 1, 1).compare("D") == 0) //Both prev and current pos of toilet are D
		always_up += 2;
	}
	else
	{
	    always_pref++;
	    if (sequence.substr(i - 1, 1).compare("U") == 0) //UD
		always_up += 2;
	    else if (sequence.substr(i - 1, 1).compare("D") == 0) //DU
		always_down += 2;
	}
    }
    cout << always_up << endl;
    cout << always_down << endl;
    cout << always_pref << endl;
}
