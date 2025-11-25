//
// Created by Lehel on 2025-11-25.
//

#ifndef SETTLEMENTSTATISTICSIMPL_H
#define SETTLEMENTSTATISTICSIMPL_H
#include "Settlement.h"
#include <vector>
#include <string>

struct SettlementStatistics {
    virtual int numSettlements() const;
    virtual int numCounties() const;
    virtual int numSettlementsByCounty(const std::string& county) const;
    virtual std::vector<Settlement> findSettlementsByCounty(
    const std::string& county) const;
    virtual Settlement findSettlementsByNameAndCounty(
    const std::string& name, const std::string& county) const;
    virtual Settlement maxPopulationBySettlement() const;
    virtual Settlement minPopulationBySettlement() const;
    virtual std::vector<Settlement> findSettlementsByName(
    const std::string& name);
};

class SettlementStatisticsImpl {

};



#endif //SETTLEMENTSTATISTICSIMPL_H
