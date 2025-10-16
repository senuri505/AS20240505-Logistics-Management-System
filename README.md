# AS20240505-Logistics-Management-System

**Logistics Management System**

University of Sri Jayewardenepura (Faculty of Applied Sciences)
First Year-first semester  (CSC 1012: Introduction to Computer Programming)

**Project Overview**
The Logistics Management System is a menu-driven C program designed to simulate a simple logistics and delivery management system. The system allows users to manage cities, delivery routes, vehicle types, fuel consumption, and delivery costs. This project demonstrates key programming concepts including arrays, functions, loops, and conditionals.

**Features**

1. City Management
    Store up to 30 unique cities.
    Add, rename, or remove cities.
    Ensure city names are unique.

2. Distance Management
    Maintain intercity distances in a 2D array.
    Input or edit distances between cities.
    Prevent self-distances (distance from a city to itself is always 0).
    Distance is symmetrical (distance[i][j] = distance[j][i]).
    Display the distance table neatly.

3. Vehicle Management
    Three vehicle types: Van, Truck, and Lorry.
    Store vehicle capacity, rate per km, average speed, and fuel efficiency.
    Vehicle selection is required for delivery cost estimation.

    Vehicle	  Capacity (kg)	  Rate per km (LKR)	  Avg Speed (km/h)	  Fuel Efficiency (km/l)
    Van	        1000	            30	                60	                12
    Truck	    5000	            40	                100             	6
    Lorry	    10000	            50              	80              	4

4. Delivery Request Handling
    Input delivery order with source city, destination city, weight, and vehicle type.
    Validates:
    Weight does not exceed vehicle capacity.
    Source and destination are not the same.

5. Cost, Time, and Fuel Calculations
    Delivery Cost: DeliveryCost = D * R * (1 + W/10000)
    Estimated Delivery Time: Time = D / S
    Fuel Consumption: FuelUsed = D / E
    Fuel Cost: FuelCost = FuelUsed * FuelPrice
    Operational Cost: TotalCost = DeliveryCost + FuelCost
    Profit: Profit = DeliveryCost * 0.25
    Customer Charge: CustomerCharge = TotalCost + Profit

6. Delivery Records
    Maintain up to 50 deliveries in memory.

7. Least-Cost Route
    Find the least-cost (least-distance) route between cities.
    Example: Exhaustive search for <= 4 cities or another suitable algorithm.

8. Performance Reports
    Total deliveries completed.
    Total distance covered.
    Average delivery time.
    Total revenue and profit.
    Longest and shortest routes completed.

**How to Run**
    Clone or download the repository.
    Open the CodeBlocks project or compile .c files using any C compiler.
    Run the program and use the menu-driven interface to manage logistics operations.

**Assumptions**
    Maximum of 30 cities and 50 deliveries.
    Fuel price is fixed .
    Delivery weights must not exceed vehicle capacity.
    Users provide valid inputs (basic validation included).

**Example Output**
======================================================
DELIVERY COST ESTIMATION
------------------------------------------------------
From: Colombo
To: Jaffna
Minimum Distance: 400 km
Vehicle: Truck
Weight: 2000 kg
------------------------------------------------------
Base Cost: 19200.00 LKR
Fuel Used: 66.67 L
Fuel Cost: 20666.67 LKR
Operational Cost: 39866.67 LKR
Profit: 9966.67 LKR
Customer Charge: 49833.34 LKR
Estimated Time: 8.00 hours
======================================================
