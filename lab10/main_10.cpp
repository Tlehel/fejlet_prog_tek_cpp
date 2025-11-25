#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, Lab_10" << std::endl;
    // Multimap feltoltese
    multimap<string, Settlement> settlements;

    settlements.insert({"Budapest", Settlement("Budapest", "Budapest", 1756000)});
    settlements.insert({"Hajdu-Bihar", Settlement("Debrecen", "Hajdu-Bihar", 201000)});
    settlements.insert({"Borsod-Abauj-Zemplen", Settlement("Miskolc", "Borsod-Abauj-Zemplen", 150000)});
    settlements.insert({"Gyor-Moson-Sopron", Settlement("Gyor", "Gyor-Moson-Sopron", 130000)});
    settlements.insert({"Csongrad", Settlement("Szeged", "Csongrad", 160000)});
    settlements.insert({"Csongrad", Settlement("Hodmezovasarhely", "Csongrad", 44000)});
    settlements.insert({"Somogy", Settlement("Debrecen", "Somogy", 2000)});

    // Statisztika objektum
    SettlementStatisticsImpl stats(settlements);

    cout << "=== TESZTEK ===" << endl;

    cout << "Osszes telepules: "
         << stats.numSettlements() << endl;

    cout << "Osszes megye: "
         << stats.numCounties() << endl;

    cout << "Telepulesek szama Csongrad megyeben: "
         << stats.numSettlementsByCounty("Csongrad") << endl;

    cout << "\n--- Telepulesek Csongrad megyeben ---" << endl;
    for (auto& s : stats.findSettlementsByCounty("Csongrad")) {
        cout << s.getName() << " (" << s.getPopulation() << " fo)" << endl;
    }

    cout << "\n--- Telepules keresese nev + megye alapjan ---" << endl;
    try {
        Settlement s = stats.findSettlementsByNameAndCounty("Debrecen", "Hajdu-Bihar");
        cout << s.getName() << " - " << s.getCounty()
             << " - " << s.getPopulation() << " fo" << endl;
    } catch (exception& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    cout << "\nLegnagyobb nepessegu telepules: "
         << stats.maxPopulationBySettlement().getName() << endl;



    cout << "Legkisebb nepessegu telepules: "
         << stats.minPopulationBySettlement().getName() << endl;

    cout << "\n--- Telepulesek keresese nev szerint: Debrecen ---" << endl;
    for (auto& s : stats.findSettlementsByName("Debrecen")) {
        cout << s.getName() << " - " << s.getCounty()
             << " - " << s.getPopulation() << " fo" << endl;
    }

    return 0;
}