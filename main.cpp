#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class ChangePlan{
    public:
        int totalBills; //holds total num of bills of current plan
        vector<int> plan; //contains num of bills needed for solution in the following order:
                            // $1, $101, $701, $5001, $32001, $95000
        vector<int> bills; //holds bill values in an array to be used in algorithms
        ChangePlan(){totalBills = 0;bills.push_back(1);bills.push_back(101);bills.push_back(701);bills.push_back(5001);bills.push_back(32001);bills.push_back(95000);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);}

        vector<int> greedyPlan(int tax);
        vector<int> dynamicPlan(int tax);
};

vector<int> ChangePlan::greedyPlan(int tax){
    // Reset plan vector, back to zero
    for (int i = 0; i < 6; i++)
        plan[i] = 0;
    
    
    int combo = 0;
    int index = 5; //end of bills array, greedy starts with largest
    while (combo <= tax){
        if (combo > tax - bills[index]){
            // can't use this denomination
            index--;
        }
        else if (combo + bills[index] < tax){
            combo += bills[index];
            plan[index] += 1;
            totalBills += 1;
        }
        else{ 
            // if they are equal
            plan[index] += 1;
            totalBills += 1;
            return plan;
        }
    }
    return plan; 
}

vector<int> ChangePlan::dynamicPlan(int tax) {
    // Reset plan vector, back to zero
    for (int i = 0; i < 6; i++)
        plan[i] = 0;

    vector<vector<int> > dp(tax + 1, vector<int>(6, INT_MAX)); // 2D table for dynamic programming
    vector<vector<int> > selectedBills(tax + 1, vector<int>(6, 0)); // To store the selected bills
    
    // Base case: No bills needed for zero tax
    for (int i = 0; i < 6; i++)
        dp[0][i] = 0;
    
    // Bottom-up approach to fill dp table
    for (int t = 1; t <= tax; t++) {
        for (int i = 0; i < 6; i++) {
            if (t - bills[i] >= 0 && dp[t - bills[i]][i] != INT_MAX) {
                dp[t][i] = dp[t - bills[i]][i] + 1;
                selectedBills[t][i] = 1; // Marking the bill selected
            }
            if (i > 0 && dp[t][i - 1] < dp[t][i]) {
                dp[t][i] = dp[t][i - 1]; // Selecting fewer bills from previous denomination
                selectedBills[t][i] = 0; // Not selecting current denomination
            }
        }
    }
    
    // Now, trace back to find the bills used
    int t = tax;
    for (int i = 5; i >= 0; i--) {
        while (t >= bills[i] && selectedBills[t][i]) {
            plan[i]++; // Increment the count of bills used
            totalBills++; // Increment total bills used
            t -= bills[i]; // Deduct the value of the bill used
        }
    }
    
    return plan;
}





int main(){

    string name;
    int tax;
    cout << "Welcome to the IR$ of Banana Republic!" << endl;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "What is your tax $$$ due?: ";
    cin >> tax;

    ChangePlan obj;
    obj.greedyPlan(tax);
    
    cout << endl;
    cout << "Plan 1: The Greedy Approach" << endl;
    cout << "Tax Due: $" << tax << endl;
    cout << endl;   

    // largest test case is largest possible int length

    //need to put headers here
    int total = obj.bills[5] * obj.plan[5];
    int overall_total = total;
    cout << right <<  setw(6) << "$95000" << "\tx " << obj.plan[5] << "\t= $" << setw(10) << left << total << "\t" << "$" << setw(11) << overall_total << endl;
    
    total = obj.bills[4] * obj.plan[4];
    overall_total += total;
    cout << right <<  setw(6)  << "$32001" << "\tx " << obj.plan[4] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;
    
    total = obj.bills[3] * obj.plan[3];
    overall_total += total;
    cout << right <<  setw(6)  << "$5001" << "\tx " << obj.plan[3] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = obj.bills[2] * obj.plan[2];
    overall_total += total;
    cout << right <<  setw(6)  << "$701" << "\tx " << obj.plan[2] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = obj.bills[1] * obj.plan[1];
    overall_total += total;
    cout << right <<  setw(6)  << "$101" << "\tx " << obj.plan[1] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = obj.bills[0] * obj.plan[0];
    overall_total += total;
    cout << right << setw(6)  << "$1" << "\tx " << obj.plan[0] << "\t= $" << setw(10) << left << total << "\t" << "$" << setw(11) << overall_total << endl;

    cout << endl;
    cout << "Total number of bills needed: " << obj.plan[5] << " + " << obj.plan[4] << " + " << obj.plan[3] << " + " << obj.plan[2] << " + " << obj.plan[1] << " + " << obj.plan[0] << " = " << obj.totalBills << endl;
    
    cout << "—-----------------------------------------------------------------" << endl;
    
    obj.dynamicPlan(tax);

    for (int i = 0; i < obj.plan.size(); i++){
        cout << obj.plan[i] << "<-{" << obj.bills[i] << "} ";
    }

    return 0;
}