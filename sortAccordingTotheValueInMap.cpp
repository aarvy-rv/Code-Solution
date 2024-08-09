#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::unordered_map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 2;
    myMap["orange"] = 8;
    myMap["grape"] = 3;

    // Create a vector of pairs from the map
    std::vector<std::pair<std::string, int>> mapVector(myMap.begin(), myMap.end());

    // Sort the vector based on the values
    std::sort(mapVector.begin(), mapVector.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    // Display the sorted vector
    for (const auto &pair : mapVector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout<<mapVector[0].first;

    return 0;
}
