// #include <iostream>
// #include <string>
// using namespace std;

// bool isNumber(const string& s) {
//     if (s.empty()) return false;
//     for (char c : s) {
//         if (!isdigit(c)) return false;
//     }
//     return true;
// }

// string fizzbuzz(long long x) {
//     if (x % 15 == 0) return "FizzBuzz";
//     if (x % 3 == 0) return "Fizz";
//     if (x % 5 == 0) return "Buzz";
//     return to_string(x);
// }

// int main() {
//     string s1, s2, s3;
//     cin >> s1 >> s2 >> s3;

//     long long target = 0;

//     if (isNumber(s1)) {
//         long long x = stoll(s1);   // s1 = i
//         target = x + 3;
//     }
//     else if (isNumber(s2)) {
//         long long x = stoll(s2);   // s2 = i+1
//         target = (x - 1) + 3;       // = x + 2
//     }
//     else { 
//         long long x = stoll(s3);   // s3 = i+2
//         target = (x - 2) + 3;       // = x + 1
//     }

//     cout << fizzbuzz(target) << "\n";
//     return 0;
// }
