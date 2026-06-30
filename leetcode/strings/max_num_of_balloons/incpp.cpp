#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string text = "loonbalxballpoon";
  unordered_map<char, int> actual = {
      {'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}};
  unordered_map<char, int> map;
  for (int i = 0; i < text.size(); i++) {
    map[text[i]] = map[text[i]] + 1;
  }
  for (auto letter : map) {
    cout << letter.first << " " << letter.second << endl;
  }
  char mini = 'b';
  for (pair<char, int> letter : map) {
    if ((map[letter.first] == 'o') || (map[letter.first] == 'l')) {
      if ((map[letter.first] / 2) < map[mini]) {
        mini = letter.first;
      }
    }
    if ((map[letter.first] == 'b') || (map[letter.first] == 'a') ||
        (map[letter.first] == 'n')) {
      if ((map[letter.first]) < map[mini]) {
        mini = letter.first;
      }
    }
  }
  if ((mini == 'l') || (mini == 'o')) {
    return map[mini] / 2;
  }
  return map[mini];

  return 0;
}
