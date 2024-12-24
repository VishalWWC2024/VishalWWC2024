#include <iostream>
#include <vector>
#include <algorithm>

struct Patient {
    std::string name;       // Patient's name
    int triagePriority;     // Triage priority (1: highest, 5: lowest)
    int severity;           // Severity of condition (higher is worse)
    int arrivalTime;        // Arrival time (earlier is prioritized)
};

int main() {
    // Sample list of patients
    std::vector<Patient> patients = {
        {"Alice", 3, 70, 5},
        {"Bob", 1, 90, 2},
        {"Charlie", 2, 80, 3},
        {"Diana", 1, 95, 1},
        {"Eve", 4, 60, 4}
    };

    // Sort patients based on triage priority, severity, and arrival time
    std::sort(patients.begin(), patients.end(), [](const Patient& a, const Patient& b) {
        if (a.triagePriority != b.triagePriority) 
            return a.triagePriority < b.triagePriority; // Higher priority comes first
        if (a.severity != b.severity) 
            return a.severity > b.severity;           // More severe comes first
        return a.arrivalTime < b.arrivalTime;         // Earlier arrival comes first
    });

    // Display sorted patient list
    std::cout << "Sorted Patients List:\n";
    for (const auto& patient : patients) {
        std::cout << "Name: " << patient.name 
                  << ", Priority: " << patient.triagePriority 
                  << ", Severity: " << patient.severity 
                  << ", Arrival Time: " << patient.arrivalTime << "\n";
    }

    return 0;
}
