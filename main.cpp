#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h> // For PrintF, utilized in print method, allows for code reuse
using namespace std;


class ChangePlan{
    public:
        // totalBills: Holds the total number of bills of the current plan.
        int totalBills;

        // plan: Contains the number of bills needed for the solution in the following order:
        // $1, $101, $701, $5001, $32001, $95000
        vector<int> plan;

        // bills: Holds bill values in an array to be used in algorithms.
        vector<int> bills;

        // Constructor: Initializes totalBills, bills, and plan vectors.
        ChangePlan(){totalBills = 0;bills.push_back(1);bills.push_back(101);bills.push_back(701);bills.push_back(5001);bills.push_back(32001);bills.push_back(95000);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);plan.push_back(0);}

        // greedyPlan: Computes the optimal change plan using the greedy algorithm.
        // Input: tax - The amount of tax due.
        // Output: A vector representing the optimal change plan.
        vector<int> greedyPlan(int tax);

        // dynamicPlan: Computes the optimal change plan using dynamic programming.
        // Input: tax - The amount of tax due.
        // Output: A vector representing the optimal change plan.
        vector<int> dynamicPlan(int tax);


        // print_plan: Prints the details of the change plan.
        // Input: plantype - The type of plan (e.g., "Greedy", "Dynamic Programming").
        //        tax - The amount of tax due.
        void print_plan(string plan, int tax);
};

vector<int> ChangePlan::greedyPlan(int tax){
    totalBills = 0;
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
    totalBills = 0;
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


void ChangePlan::print_plan(string plantype, int tax){
    int type = 0;
    if (plantype == "Greedy"){type = 1;}else{type = 2;} //for string outputting, set the type (number)
    cout << endl;
    printf("Plan %i: The %s Approach", type, plantype.c_str());
    cout << endl;
    cout << "Tax Due: $" << tax << endl;
    cout << endl;   

    // largest test case is largest possible int length


    cout << right << setw(6) << "Bills" << "\tNum" << "\tSubtotal" << endl;
    //need to put headers here
    int total = bills[5] * plan[5];
    int overall_total = total;
    cout << right <<  setw(6) << "$95000" << "\tx " << plan[5] << "\t= $" << setw(10) << left << total << "\t" << "$" << setw(11) << overall_total << endl;
    
    total = bills[4] * plan[4];
    overall_total += total;
    cout << right <<  setw(6)  << "$32001" << "\tx " << plan[4] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;
    
    total = bills[3] * plan[3];
    overall_total += total;
    cout << right <<  setw(6)  << "$5001" << "\tx " << plan[3] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = bills[2] * plan[2];
    overall_total += total;
    cout << right <<  setw(6)  << "$701" << "\tx " << plan[2] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = bills[1] * plan[1];
    overall_total += total;
    cout << right <<  setw(6)  << "$101" << "\tx " << plan[1] << "\t= $" << setw(10) << left  << total << "\t" << "$" << setw(11) << overall_total << endl;

    total = bills[0] * plan[0];
    overall_total += total;
    cout << right << setw(6)  << "$1" << "\tx " << plan[0] << "\t= $" << setw(10) << left << total << "\t" << "$" << setw(11) << overall_total << endl;

    cout << endl;
    cout << "Total number of bills needed: " << plan[5] << " + " << plan[4] << " + " << plan[3] << " + " << plan[2] << " + " << plan[1] << " + " << plan[0] << " = " << totalBills << endl;
    
    cout << "—-----------------------------------------------------------------" << endl;
}



int main(){

    bool isValidInput = true;
    string name;
    int tax;
    cout << "Welcome to the IR$ of Banana Republic!" << endl;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "What is your tax $$$ due?: ";
    cin >> tax;

    while (isValidInput){
        if (tax > 0){
            ChangePlan obj;
            obj.greedyPlan(tax);
            obj.print_plan("Greedy", tax);

            obj.dynamicPlan(tax);
            obj.print_plan("Dynamic Programming", tax);

            cout << "Which payment plan do you want to choose (1 or 2)? ";
            int option;
            cin >> option;
            cout << endl;
            printf("Dear %s, thank you for paying your tax ON TIME!", name.c_str());
            cout << endl;
            cout << "—-----------------------------------------------------------------" << endl;

            isValidInput = false;
        }
        else{
            printf("You entered %i, which is not a valid tax entry. Please enter a different number.", tax);
            cout << endl; 
            cout << endl;
            cout << "What is your tax $$$ due?: ";
            cin >> tax;
        }
    }

    return 0;
}