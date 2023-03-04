// 2.2.1.1 N tuples (integer age (inc), string last name (descending order),
// string first name (inc)).
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Info {
    int age;
    string first_name, last_name;

    Info(int age, string first_name, string last_name)
        : age(age), first_name(first_name), last_name(last_name) {}
};

void sort_infos(vector<Info> &vec) {
    sort(vec.begin(), vec.end(), [](const Info &fst, const Info &snd) -> bool {
        if (fst.age < snd.age) return true;
        if (fst.last_name > snd.last_name) return true;
        if (fst.first_name < snd.first_name) return true;

        return false;
    });
}

void test_sort_infos() {
    vector<Info> vec = vector<Info>();
    vec.push_back(Info(10, "a", "a"));
    vec.push_back(Info(10, "b", "b"));
    vec.push_back(Info(10, "b", "a"));
    vec.push_back(Info(9, "a", "a"));
    vec.push_back(Info(10, "b", "b"));
    vec.push_back(Info(11, "b", "a"));

    sort_infos(vec);

    for (auto item : vec) {
        cout << "age: " << item.age << " " << item.first_name << " "
             << item.last_name << endl;
    }
}

int main() { test_sort_infos(); }