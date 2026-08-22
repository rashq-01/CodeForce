#include<bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

long long getMinRedistributionCost(vector<int>& products){
    int n = products.size();

    long long totalSum = 0;

    for(auto& prod:products)totalSum+=prod;

    long long avg = totalSum/n;

    long long clockwiseAns = 0;
    long long counterClockwiseAns = 0;

    int i=0,j=0;

    //Clockwise
    while(i<n && j<n){
        while(i<n && products[i]<=avg)i++;
        while(j<n && products[j]>=avg)j++;

        if(i<n && j<n){
            long long extra = products[i]-avg;
            long long remaining = avg - products[j];
            
            if(extra>remaining){
                if(i>j){
                    int clockwiseSteps = abs((n-1-i) + (j+1));
                    clockwiseAns += ((clockwiseSteps)*remaining);

                    int counterClockwiseSteps = abs(i-j);
                    counterClockwiseAns += ((counterClockwiseSteps)*remaining);
                }
                else{
                    int steps = abs(i-j);
                    clockwiseAns += (steps * remaining);

                    int counterClockwiseSteps = abs((n-1-j) + (i+1));
                    counterClockwiseAns += ((counterClockwiseSteps)*remaining);
                }
                products[i] -= remaining;
                products[j] += remaining;
            }
            else{
                if(i>j){
                    int steps = abs((n-1-i) + (j+1));
                    clockwiseAns += ((steps)*extra);

                    int counterClockwiseSteps = abs(i-j);
                    counterClockwiseAns += ((counterClockwiseSteps)*extra);
                }
                else{
                    int steps = abs(i-j);
                    clockwiseAns += (steps * extra);

                    int counterClockwiseSteps = abs((n-1-j) + (i+1));
                    counterClockwiseAns += ((counterClockwiseSteps)*extra);
                }
                products[i] -= extra;
                products[j] += extra;
            }
        }
    }

    return min(counterClockwiseAns,clockwiseAns);
}

// ==========================================
// GROUND TRUTH CALCULATOR FOR VERIFICATION
// ==========================================
// Directional flow calculation in O(N) time and O(1) extra space
long long computeOneDirectionCost(const vector<int>& products) {
    int n = products.size();
    if (n <= 1) return 0;

    long long sum = 0;
    for (int x : products) sum += x;
    long long k = sum / n;

    long long minP = 0;
    long long currentP = 0;
    long long sumP = 0;

    for (int i = 0; i < n; i++) {
        currentP += ((long long)products[i] - k);
        minP = min(minP, currentP);
        sumP += currentP;
    }

    long long f_last = -minP;
    return (long long)n * f_last + sumP;
}

long long computeExpected(vector<int> products) {
    int n = products.size();
    if (n <= 1) return 0;

    // 1. Clockwise cost
    long long cwCost = computeOneDirectionCost(products);

    // 2. Counter-Clockwise cost (Clockwise on reversed array)
    vector<int> revProducts = products;
    reverse(revProducts.begin(), revProducts.end());
    long long ccwCost = computeOneDirectionCost(revProducts);

    return min(cwCost, ccwCost);
}

// ==========================================
// TEST FRAMEWORK
// ==========================================
struct TestCase {
    string name;
    vector<int> products;
    long long expected;
};

void runTest(int testNum, const TestCase& tc) {
    cout << "Test " << testNum << " [" << tc.name << "]... ";
    
    vector<int> prods = tc.products;
    
    auto start = high_resolution_clock::now();
    long long result = getMinRedistributionCost(prods);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    
    if (result == tc.expected) {
        cout << "\033[1;32mPASSED\033[0m (" << duration.count() << " ms)\n";
    } else {
        cout << "\033[1;31mFAILED\033[0m\n";
        cout << "  Expected: " << tc.expected << " | Output: " << result << "\n";
    }
}

int main() {
    cout << "=================================================\n";
    cout << "  BRUTAL TEST SUITE - MIN REDISTRIBUTION COST   \n";
    cout << "=================================================\n\n";

    vector<TestCase> tests;

    // ---------------------------------------------------------
    // 1. SAMPLE CASE 1 (From Problem Description)
    // ---------------------------------------------------------
    {
        vector<int> p = {3, 4, 6, 6, 6};
        tests.push_back({"Sample Case 1 (CW Cheaper)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 2. 64-BIT INTEGER OVERFLOW TRAP (N = 10^5, Max Products)
    // Total cost = ~5 * 10^13, which easily overflows a 32-bit signed int (2 * 10^9).
    // ---------------------------------------------------------
    {
        int N = 100000;
        vector<int> p(N, 0);
        p[0] = 1000000000; // 1 Billion in position 0, rest 0
        tests.push_back({"64-Bit Int Overflow Trap (N=10^5)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 3. DIRECTIONAL ASYMMETRY TRAP (CW vs CCW Vastly Different)
    // Moving CW costs way less than CCW due to cluster positioning.
    // ---------------------------------------------------------
    {
        vector<int> p = {0, 0, 0, 0, 0, 0, 0, 0, 0, 100};
        tests.push_back({"Directional Asymmetry (CW vs CCW)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 4. ALREADY EQUAL CONTAINERS (N = 10^5)
    // Every container already has k products. Expected cost: 0.
    // ---------------------------------------------------------
    {
        int N = 100000;
        vector<int> p(N, 500000);
        tests.push_back({"Already Equal Containers (N=10^5)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 5. SINGLE CONTAINER EDGE CASE (N = 1)
    // No transfers possible or required. Expected cost: 0.
    // ---------------------------------------------------------
    {
        vector<int> p = {999999999};
        tests.push_back({"Single Container Edge Case (N=1)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 6. TWO CONTAINERS EDGE CASE (N = 2)
    // CW and CCW costs are identical in a 2-node ring.
    // ---------------------------------------------------------
    {
        vector<int> p = {1000000000, 0};
        tests.push_back({"Two Containers Edge Case (N=2)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 7. ALTERNATING HIGH/LOW SPIKES (N = 10^5)
    // Tests accumulator stability across rapid oscillations.
    // ---------------------------------------------------------
    {
        int N = 100000;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            p[i] = (i % 2 == 0) ? 1000000 : 0;
        }
        tests.push_back({"Alternating High/Low Spikes (N=10^5)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 8. STRICTLY DECREASING RING (N = 10,000)
    // Gradient distribution testing cyclic flow boundary conditions.
    // ---------------------------------------------------------
    {
        int N = 10000;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            p[i] = N - i;
        }
        tests.push_back({"Strictly Decreasing Gradient (N=10k)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 9. LARGE INVENTORY WITH SINGLE DEFICIT (N = 10^5)
    // Container 0 needs everything, all other containers have 1 extra.
    // ---------------------------------------------------------
    {
        int N = 100000;
        vector<int> p(N, 2);
        p[0] = 2 - N; // Wait, products[i] >= 0, so let's adjust:
        // Set all to 10, and container 0 to 10 - (N - 1) + (N - 1) = 10
        for (int i = 0; i < N; i++) p[i] = 10;
        p[0] = 10 + N; 
        p[N - 1] = 0;
        tests.push_back({"Single Spike with Offset (N=10^5)", p, computeExpected(p)});
    }

    // ---------------------------------------------------------
    // 10. HEAVY CONSECUTIVE CLUSTERS
    // Clusters of heavy excess followed by empty blocks.
    // ---------------------------------------------------------
    {
        vector<int> p = {50, 50, 0, 0, 0, 0, 50, 50, 0, 0};
        tests.push_back({"Heavy Consecutive Clusters", p, computeExpected(p)});
    }

    // Run all test cases
    for (int i = 0; i < tests.size(); i++) {
        runTest(i + 1, tests[i]);
    }

    cout << "\n=================================================\n";
    cout << "Testing Complete.\n";
    return 0;
}






/*








*/