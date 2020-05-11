#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;
    
    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;
        
        x = (x*x)%mod;
        power = power/2;
    }
    
    return result;
}

int main()
{
    int no_of_elements, x;
    cin >> no_of_elements >> x;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    long long sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum += A[i];
    }
    
    set <long long> S;
    map <long long, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[sum - A[i]]++;
        
        S.insert(sum - A[i]);
    }
    
    const int MOD = 1e9 + 7;
    long long answer;
    for(auto it = S.begin(); ; it++)
    {
        while(frequency[*(S.begin())]%x == 0)
        {
            long long exponent = *(S.begin());
            
            long long new_exponent = exponent + 1;
            
            frequency[new_exponent] += frequency[exponent]/x;
            
            S.insert(new_exponent);
            
            S.erase(exponent);
        }
        
        if(frequency[*( S.begin() )] != 0)
        {
            answer = min(sum, *( S.begin() ));
            
            break;
        }
    }
    
    cout << power_mod(x, answer, MOD) << "\n";
    
    return 0;
}
