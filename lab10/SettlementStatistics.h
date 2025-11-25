//
// Created by Lehel on 2025-11-25.
//

#ifndef SETTLEMENTSTATISTICS_H
#define SETTLEMENTSTATISTICS_H
#include "Settlement.h"
#include <vector>
#include <string>



struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const std::string& county) const = 0;
    virtual std::vector<Settlement> findSettlementsByCounty(
    const std::string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
    const std::string& name, const std::string& county) const = 0;
    virtual Settlement maxPopulationBySettlement() const = 0;
    virtual Settlement minPopulationBySettlement() const = 0;
    virtual std::vector<Settlement> findSettlementsByName(
    const std::string& name) = 0;
};


#endif //SETTLEMENTSTATISTICS_H
