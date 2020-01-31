//Solution by Srihari Vishnu
//CCC 2015 J3
//Implementation Problem

#include <iostream>
#include <string>

using namespace std;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool isVowel (char a) {
    string vowels = "aeiou";
    size_t found = vowels.find(a);
    if (found == string::npos) return false;
    return true;
}
char closestVowel(char c) {
    size_t index = alphabet.find(c);
    int i = 0, k = 0;
    while (index-i >= 0 && !isVowel(alphabet[index-i])) i++;
    while (index+k < alphabet.length() && !isVowel(alphabet[index+k])) k++;

    if ((i <= k && index-i >= 0) || (index+k >= alphabet.length())) return alphabet[index-i];
    else return alphabet[index+k];
}
char nextConsonant(char c) {
    if (c == 'z') return 'z';

    size_t index = alphabet.find(c);
    if (isVowel(alphabet[index+1])) return alphabet[index+2];
    else return alphabet[index+1];
}

int main() {
    string word;
    cin >> word;
    string newword = "";
    for (int i = 0; i < word.length(); i++) {
        newword += word[i];
        if (!isVowel(word[i])) {
            newword += closestVowel(word[i]);
            newword += nextConsonant(word[i]);
        }
    }

    cout << newword << endl;
    
}