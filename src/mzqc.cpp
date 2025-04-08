#include "mzqc.hpp"

nlohmann::json MzQC::to_json() const {
    nlohmann::json j;
    j["version"] = version;
    j["creationDate"] = creationDate;
    j["contactName"] = contactName;
    j["qualityMetrics"] = nlohmann::json::array();
    for (const auto& m : metrics) {
        j["qualityMetrics"].push_back({
            {"accession", m.accession},
            {"name", m.name},
            {"value", m.value}
        });
    }
    return j;
}

MzQC MzQC::from_json(const nlohmann::json& j) {
    MzQC mz;
    mz.version = j.at("version");
    mz.creationDate = j.at("creationDate");
    mz.contactName = j.at("contactName");
    for (const auto& item : j.at("qualityMetrics")) {
        mz.metrics.push_back({
            item.at("accession"),
            item.at("name"),
            item.at("value")
        });
    }
    return mz;
}
