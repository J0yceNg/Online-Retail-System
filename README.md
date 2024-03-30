# Online Retail System

Welcome to the GitHub repository for my Online Retail System, a simple backend system designed to emulate a streamlined online shopping experience akin to major retailers like Amazon.

## Overview

This project focuses on creating a flexible and scalable backend system capable of managing a vast array of products and user data. Through a parsing system, the system reads and incorporates product information and user details into a live online marketplace.
## Features

- **Interactive Product Search:** Users can search for products using specific keywords. The system then retrieves and displays matching products, allowing for an intuitive shopping experience.
- **Cart Management:** Shoppers have the ability to add products to their shopping cart, view their cart's contents, and proceed to purchase their selected items. Post-purchase, the system updates the product database and user information accordingly.
- **Dynamic Product Categories:** The system is built on a product class system, enabling the representation of various product categories. Currently supported categories include:
  - **Books:** With unique fields such as ISBN numbers and author name.
  - **Clothing:** Categorized by brand information.
  - **Movies:** Featuring specific attributes like genre.
- **Extensible Product Hierarchy:** The system is designed for expandability, allowing new product categories to be easily integrated by extending the abstract product class. This ensures our system can adapt to new market trends and product types.

## Technical Structure

- `amazon.cpp`: Contains the `main()` function and orchestrates the core logic of the system.
- `mydatastore.cpp`: Acts as the central hub for storing and managing crucial data, including the implementation of the search and transaction functionalities.
- `product.h/cpp`, `user.h/cpp`, `cart.h/cpp`: These files define the structure and operations of products, users, and shopping carts within the system.

## Getting Started

To get started with this project:
1. Clone the repository to your local machine.
2. Ensure you have a C++ compiler installed and configured.
3. Navigate to the project directory and compile the source files.
4. Run the executable to start the online retail system.

## Contribution

We welcome contributions from the community, whether it's in the form of feature requests, bug reports, or pull requests.
