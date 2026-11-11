#! /usr/bin/env python3
"""Write a Python program that checks expenses for the month, 
    calculates the total for each category (category_totals), 
    and flags high-value spending (>=75). 
    Finally, compare the total for each category with the budget_limits and 
    display the appropriate message"""

# 1. Set up a baseline budget and transaction history
budget_limits = {"Food": 200, "Utilities": 150, "Entertainment": 100}

# A list of dictionaries representing the user's spending profile
expenses = [
    {"item": "Weekly Groceries", "amount": 125.50, "category": "Food"},
    {"item": "Streaming Service", "amount": 15.99, "category": "Entertainment"},
    {"item": "Electricity Bill", "amount": 110.00, "category": "Utilities"},
    {"item": "Restaurant Dinner", "amount": 85.00, "category": "Food"},
    {"item": "Video Game purchase", "amount": 70.00, "category": "Entertainment"}
]

# Dictionary to track running totals per category
category_totals = {"Food": 0, "Utilities": 0, "Entertainment": 0}

print("--- Processing Daily Financial Records ---")
# 2. Loop through the transaction history
for  record in expenses:   
    # Update the running total for the category
    category_totals[record['category']]+=record['amount']
    # Flag individual high-value "luxury" purchases
    if record['amount'] >= 75.00:
        print(f"⚠️ High Expense Flagged: '{record['item']}' cost ${record['amount']:.2f}")
# print(category_totals)
print("\n--- Final Monthly Budget Review ---")

# # 3. Compare totals against budget limits
for category in category_totals:
    # print(category)
    total_spent=category_totals[category]
    limit = budget_limits[category]
    print(category+" Total: $" + str(total_spent)+" / Limit: $"+str(limit))    
    if total_spent > limit:
        overage = total_spent - limit
        print(f"🚨 BUDGET ALARM: You went over your {category} budget by ${overage:.2f}!")
    else:
        remaining = limit - total_spent
        print(f"✅ Safe: You have ${remaining:.2f} remaining in {category}.")
