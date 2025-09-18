#include <iostream>
#include <string>

using namespace std;

// Define the structure for storing food item information
struct FoodItem
{
    string name;
    double price;
    int calories;
};

// Function to find the difference in price between the most expensive and the cheapest food item
double findPriceDifference(FoodItem foodItems[], int size)
{
    if (size == 0)
    {
        return 0.0;
    }

    double maxPrice = foodItems[0].price;
    double minPrice = foodItems[0].price;

    for (int i = 1; i < size; i++) {
        if (foodItems[i].price > maxPrice)
        {
            maxPrice = foodItems[i].price;
        }
        if (foodItems[i].price < minPrice)
        {
            minPrice = foodItems[i].price;
        }
    }

    return maxPrice - minPrice;
}

// Function to calculate the average calories of food items that cost more than $5
double calculateAverageCalories(FoodItem foodItems[], int size)
{
    double totalCalories = 0.0;
    int count = 0;

    for (int i = 0; i < size; i++)
        {
        if (foodItems[i].price > 5.0)
        {
            totalCalories = totalCalories + foodItems[i].calories;
            count++;
        }
    }

    if (count > 0)
    {
        return totalCalories / count;
    }
    else
    {
        return 0.0;
    }

}

int main()
{
    // Example food items
    const int size = 5; // Fixed size of the array
    FoodItem foodItems[size] = {
        {"Burger", 4.99, 550},
        {"Pizza", 7.99, 800},
        {"Salad", 5.50, 300},
        {"Sushi", 12.00, 400},
        {"Pasta", 6.75, 600}
    };

    // Find the difference in price between the most expensive and the cheapest food item
    double priceDifference = findPriceDifference(foodItems, size);
    cout << "Difference in price between the most expensive and cheapest food item: $"
         << priceDifference << endl;

    // Calculate the average calories of food items that cost more than $5
    double avgCalories = calculateAverageCalories(foodItems, size);
    cout << "Average calories of food items that cost more than $5: "
         << avgCalories << " calories" << endl;

    return 0;
}

