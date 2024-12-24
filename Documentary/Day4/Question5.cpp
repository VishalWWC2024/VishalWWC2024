#include <iostream>
#include <vector>
#include <algorithm>

struct Ad {
    std::string advertiserName; // Advertiser name
    double bidAmount;           // Bid amount for the ad
    double engagementRate;      // Engagement rate of the ad
    double remainingBudget;     // Remaining budget of the advertiser
};

// Function to calculate ad score based on bid, engagement, and budget
double calculateAdScore(const Ad& ad) {
    return ad.bidAmount * 0.5 + ad.engagementRate * 0.3 + ad.remainingBudget * 0.2;
}

int main() {
    // Sample list of ads
    std::vector<Ad> ads = {
        {"Advertiser A", 1000.0, 0.8, 5000.0},
        {"Advertiser B", 1500.0, 0.7, 2000.0},
        {"Advertiser C", 1200.0, 0.9, 3000.0},
        {"Advertiser D", 800.0, 0.75, 4000.0},
        {"Advertiser E", 2000.0, 0.85, 6000.0}
    };

    // Sort ads by calculated score (higher score means higher priority)
    std::sort(ads.begin(), ads.end(), [](const Ad& a, const Ad& b) {
        return calculateAdScore(a) > calculateAdScore(b);
    });

    // Display sorted ads
    std::cout << "Ad Scheduling (Sorted by Priority):\n";
    for (const auto& ad : ads) {
        std::cout << "Advertiser: " << ad.advertiserName 
                  << ", Bid: " << ad.bidAmount 
                  << ", Engagement Rate: " << ad.engagementRate 
                  << ", Remaining Budget: " << ad.remainingBudget << "\n";
    }

    return 0;
}
