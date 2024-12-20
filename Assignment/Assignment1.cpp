#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

class Item {
public:
    int id;
    std::string name;
    std::string category;
    int quantity;
    int reorderLevel;

    Item(int id, const std::string& name, const std::string& category, int quantity, int reorderLevel)
        : id(id), name(name), category(category), quantity(quantity), reorderLevel(reorderLevel) {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name 
                  << ", Category: " << category 
                  << ", Quantity: " << quantity 
                  << ", Reorder Level: " << reorderLevel << std::endl;
    }
};

class WarehouseInventorySystem {
private:
    std::vector<Item> inventory;
    int nextId = 1;

    void alertIfBelowReorder(const Item& item) const {
        if (item.quantity < item.reorderLevel) {
            std::cout << "ALERT: Stock for " << item.name << " is below reorder level!" << std::endl;
        }
    }

public:
    void addItem(const std::string& name, const std::string& category, int quantity, int reorderLevel) {
        if (name.empty() || category.empty() || quantity < 0 || reorderLevel < 0) {
            std::cout << "Error: Invalid input. Please try again.\n";
            return;
        }
        inventory.emplace_back(nextId++, name, category, quantity, reorderLevel);
        std::cout << "Item added successfully!" << std::endl;
    }

    void updateStock(int id, int quantity) {
        for (auto& item : inventory) {
            if (item.id == id) {
                item.quantity += quantity;
                std::cout << "Stock updated successfully!" << std::endl;
                alertIfBelowReorder(item);
                return;
            }
        }
        std::cout << "Error: Item not found!" << std::endl;
    }

    void viewInventory() const {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }
        std::cout << "Current Inventory:" << std::endl;
        for (const auto& item : inventory) {
            item.display();
            alertIfBelowReorder(item);
        }
    }

    void searchByName(const std::string& name) const {
        bool found = false;
        for (const auto& item : inventory) {
            if (item.name == name) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found with the name: " << name << std::endl;
        }
    }

    void searchByCategory(const std::string& category) const {
        bool found = false;
        for (const auto& item : inventory) {
            if (item.category == category) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found in the category: " << category << std::endl;
        }
    }

    void exportInventory(const std::string& filename) const {
        if (inventory.empty()) {
            std::cout << "Error: Inventory is empty. Nothing to export.\n";
            return;
        }

        std::ofstream file(filename);
        if (!file) {
            std::cout << "Error: Could not open file for writing.\n";
            return;
        }

        for (const auto& item : inventory) {
            file << item.id << "," << item.name << "," << item.category 
                 << "," << item.quantity << "," << item.reorderLevel << "\n";
        }
        std::cout << "Inventory exported successfully to " << filename << "!" << std::endl;
    }
};

int main() {
    WarehouseInventorySystem system;
    int choice;

    do {
        std::cout << "\n1. Add Item\n2. Update Stock\n3. View Inventory\n4. Search by Name\n"
                  << "5. Search by Category\n6. Export Inventory\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name, category;
                int quantity, reorderLevel;
                std::cout << "Enter item name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter item category: ";
                std::getline(std::cin, category);
                std::cout << "Enter item quantity: ";
                std::cin >> quantity;
                std::cout << "Enter reorder level: ";
                std::cin >> reorderLevel;
                system.addItem(name, category, quantity, reorderLevel);
                break;
            }
            case 2: {
                int id, quantity;
                std::cout << "Enter item ID to update: ";
                std::cin >> id;
                std::cout << "Enter quantity to add (negative to subtract): ";
                std::cin >> quantity;
                system.updateStock(id, quantity);
                break;
            }
            case 3:
                system.viewInventory();
                break;
            case 4: {
                std::string name;
                std::cout << "Enter item name to search: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                system.searchByName(name);
                break;
            }
            case 5: {
                std::string category;
                std::cout << "Enter category to search: ";
                std::cin.ignore();
                std::getline(std::cin, category);
                system.searchByCategory(category);
                break;
            }
            case 6: {
                std::string filename;
                std::cout << "Enter filename to export: ";
                std::cin >> filename;
                system.exportInventory(filename);
                break;
            }
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}
