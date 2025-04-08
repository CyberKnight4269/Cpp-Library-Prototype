#include <iostream>
#include <fstream>
#include "mzqc.hpp"

int main() {
    // Create sample data
    MzQC mzqc {
        "1.0", "2025-04-08", "Your Name", {
            {"QC:12345", "Total Ion Current", "1500000"},
            {"QC:67890", "Peak Count", "302"}
        }
    };

    // Serialize and write to file
    std::ofstream out("test/sample_out.mzQC");
    out << mzqc.to_json().dump(4);
    out.close();

    // Read from file
    std::ifstream in("test/sample_out.mzQC");
    nlohmann::json j;
    in >> j;
    MzQC loaded = MzQC::from_json(j);

    // Output to confirm
    std::cout << "Loaded mzQC version: " << loaded.version << std::endl;
    for (const auto& metric : loaded.metrics) {
        std::cout << metric.name << " -> " << metric.value << std::endl;
    }

    return 0;
}
