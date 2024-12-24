#include <iostream>
#include <vector>
#include <algorithm>

struct Content {
    std::string title;     // Title of the content
    int views;             // Number of views
    double rating;         // User rating
    int releaseYear;       // Release year
};

// Function to calculate a popularity score based on views and recency
double calculateScore(int views, int releaseYear) {
    int currentYear = 2024; // Current year
    return views * 0.7 + (currentYear - releaseYear) * 0.3; // Weighted score formula
}

int main() {
    // Sample catalog of movies and shows
    std::vector<Content> catalog = {
        {"Movie A", 5000, 4.5, 2020},
        {"Movie B", 10000, 4.8, 2023},
        {"Show C", 7000, 4.3, 2022},
        {"Show D", 3000, 4.7, 2019},
        {"Movie E", 9000, 4.6, 2021}
    };

    // Sort catalog based on calculated score
    std::sort(catalog.begin(), catalog.end(), [](const Content& a, const Content& b) {
        return calculateScore(a.views, a.releaseYear) > calculateScore(b.views, b.releaseYear);
    });

    // Display sorted catalog
    std::cout << "Recommended Content:\n";
    for (const auto& item : catalog) {
        std::cout << "Title: " << item.title 
                  << ", Views: " << item.views 
                  << ", Rating: " << item.rating 
                  << ", Release Year: " << item.releaseYear << "\n";
    }

    return 0;
}

