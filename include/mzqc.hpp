#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

struct QualityMetric {
    std::string accession;
    std::string name;
    std::string value;
};

struct MzQC {
    std::string version;
    std::string creationDate;
    std::string contactName;
    std::vector<QualityMetric> metrics;

    nlohmann::json to_json() const;
    static MzQC from_json(const nlohmann::json& j);
};
