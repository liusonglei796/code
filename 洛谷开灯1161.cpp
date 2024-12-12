   #include <iostream>
   #include <cmath>
   using namespace std;

   const int MAX_T = 2000000;

   int main() {
       int n;
       cin >> n;
       int lights[MAX_T + 1] = {0};
       for (int i = 0; i < n; ++i) {
           double a;
           int t;
           cin >> a >> t;
           for (int j = 1; j <= t; ++j) {
               int index = floor(j * a);
               lights[index] = 1-lights[index] ;
           }
       }
       for (int i = 1; i <= MAX_T; ++i) {
           if (lights[i] == 1) {
               cout << i << endl;
               break;
           }
       }
       return 0;
   }