#include <algorithm>
#include <iostream>
#include <vector>

bool contains(std::vector<std::string> fruits);
bool even(std::vector<int> numbers);
std::vector<int> foreach(std::vector<int> &numbers);
int fiveLetMont(const std::vector<std::string>& months,int len);
void sortArray(std::vector<double> &realnumbers);
void sortArray2(std::vector<double> &realnumbers);
void sortbytemp(std::vector<std::pair<std::string,double>> parok);
void sortbyabs();

int main() {
    std::cout << "Hello, Lab_07" << std::endl;

    std::vector<std::string> fruits {
    "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };

    std::vector<std::string> months {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
    };

    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10,-1,-2,-3,-4,-7};

    std::vector<double> realnumbers {1.2,2,3,4,5,6,7,8,9,10,-1.4,-2,-3,-4,-7};

    std::vector<std::pair<std::string,double>> parok{{"a",1},{"b",2},{"c",3},{"d",4}};

    std::vector<char> abc = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };

    std::cout << contains(fruits) <<std::endl;

    std::cout << even(numbers) << std::endl;

    foreach(numbers);
    for (auto a:numbers) {
        std::cout<< a <<" ";
    }
    std::cout << std::endl;

    std::cout << fiveLetMont(months,5) << std::endl;

    sortArray(realnumbers);
    for (auto a:numbers) {
        std::cout<< a <<" ";
    }
    std::cout << std::endl;

    sortArray2(realnumbers);
    for (auto a:numbers) {
        std::cout<< a <<" ";
    }
    std::cout << std::endl;

    return 0;
}

bool contains(std::vector<std::string> fruits) {
    const auto k =  std::find_if(fruits.begin(),fruits.end(),[](const std::string& fruit) {
        if(fruit.find("berry") != std::string::npos) {
            return true;
        }
        return false;
    });

    if (k == fruits.end()) {
        return false;
        //nem volt benne
    }
    return true;
}

bool even(std::vector<int> numbers) {
    return std::all_of(numbers.begin(),numbers.end(),[](const int& num) {
        return (num%2 == 0);
    });
}

std::vector<int> foreach(std::vector<int> &numbers) {
    auto n = numbers.begin();
    std::for_each(numbers.begin(),numbers.end(),[&n](const int num) {
       *(n++) = num*2;
    });

    return numbers;
}

int fiveLetMont(const std::vector<std::string>& months,int len) {
    return static_cast<int>( std::count_if(months.begin(),months.end(),[len](const std::string& m) {
       if(m.length() == len) {
           return true;
       }
        return false;
    }));
}

void sortArray(std::vector<double> &realnumbers) {
    std::sort(realnumbers.begin(),realnumbers.end(),[](const double a,const double b) {
        return b<a;
    });
}

void sortArray2(std::vector<double> &realnumbers) {
    std::sort(realnumbers.begin(),realnumbers.end(),std::greater<>());
}

void sortbytemp(std::vector<std::pair<std::string,double>> parok) {
    std::sort(parok.begin(),parok.end(),[](const std::pair<std::string,double> &a,const std::pair<std::string,double> &b) {
        return a.second < b.second;
    });
}

// void toLower(std::vector<std::string>& months) {
//     std::for_each(months.begin(), months.end(),[](std::string &m) {
//        std::transform(m.begin(), m.end(),[](char ch) {
//            return std::tolower(ch);
//        }) ;
//     });
// }
