# Inventory Management System (C++)

This project implements a simple command-line inventory management system in C++. It supports basic admin and customer workflows for managing and purchasing products.

## Features

- **Admin Login:** Secure access via password
- **Add Products:** Store product name, price, and quantity
- **Edit Products:** Update product price and quantity
- **Customer Purchase:** Search and buy products by name
- **Billing:** Includes automatic discounts and sales tax calculation

## How to Use

1. **Run the program**
2. **Choose User Type**
   - Admin (`A`): Add/edit products (password: `2468`)
   - Customer (`C`): Purchase products
3. **Follow on-screen instructions** to manage inventory or complete purchases

## Notes

- Product names are case-insensitive and stored in uppercase
- Only positive prices and quantities are accepted
- Discount tiers:
  - > Rs. 10,000: 10% off
  - > Rs. 5,000: 5% off
- Sales tax: 16% applied to discounted price
- Admin and customer can return to main menu after every action

---
Developed for educational purposes to demonstrate basic data handling in C++
