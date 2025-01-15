#include<bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    // Count frequency of each letter
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c - 'a']++;
    }
    
    
    // Find max and min frequencies (excluding zeros)
    int maxFreq = 0, minFreq = INT_MAX;
    for(int f : freq) {
        if(f > 0) {
            maxFreq = max(maxFreq, f);
            minFreq = min(minFreq, f);
        }
    }
    
    // Calculate difference and check if prime
    int diff = maxFreq - minFreq;
    if(isPrime(diff)) {
        cout << "Lucky Word\n" << diff;
    } else {
        cout << "No Answer\n" << 0;
    }
    
    return 0;
}
