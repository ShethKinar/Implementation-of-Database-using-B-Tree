# Implementation of Database using B+ Tree

This repository contains an implementation of a database using the B+ tree data structure. The B+ tree is a self-balancing tree data structure commonly used in database systems to organize and efficiently access large amounts of data.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Inserting Data](#inserting-data)
  - [Deleting Data](#deleting-data)
  - [Searching Data](#searching-data)
  - [Displaying Data](#displaying-data)


## Introduction

The goal of this project is to provide an implementation of a database using the B+ tree data structure. The B+ tree is particularly well-suited for storing and retrieving large amounts of data efficiently. It offers fast search and retrieval operations, as well as efficient insertion and deletion of records.

This project serves as a learning resource for understanding the inner workings of a B+ tree and its application in database systems. It provides a clear and concise implementation, along with examples and documentation to facilitate understanding and usage.

## Features

- Insertion, deletion, and retrieval of records in the B+ tree.
- Support for different data types and customizable key-value pairs.
- Efficient search operations using the B+ tree's balanced structure.
- Easy-to-understand code with comments and documentation.

## Installation

To use this project, follow these steps:

1. Clone the repository:

   ```shell
   git clone https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree.git

2. Change into the project directory:

   ```shell
   cd Implementation-of-Database-using-B-plus-Tree
3. Compile and build the code. (Specify the appropriate compiler command based on your system):


   ```shell
   gcc -o bplus_tree main.c bplus_tree.c
4. Run the executable:


   ```shell
   ./bplus_tree

   
# Usage
To use the database implementation, you can follow the code examples provided in the repository. The code demonstrates how to perform basic operations such as inserting records, deleting records, searching for records, and displaying the data using the B+ tree.

# Inserting Data
To insert data into the B+ tree, you need to use the bplus_tree_insert function. Here's an example:
```
#include "bplus_tree.h"

int main() {
    // Create and initialize the B+ tree
    bplus_tree_t* tree = bplus_tree_create();

    // Insert records into the tree
    bplus_tree_insert(tree, key1, value1);
    bplus_tree_insert(tree, key2, value2);

    // ...

    return 0;
}
```
Replace key1 and value1 with the appropriate key-value pair you want to insert. You can insert as many records as needed.
![in1](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/ec78e02d-2c37-4730-b361-7e2754d8618c)



![in2](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/3e2467c6-c200-4e6a-91a8-c3552d64c2b5)
➢Data in form of Roll No., Name and SPI will be stored on insertion.

➢ Roll No. will be the primary key and it will be inserted into the node.

➢ If the root node is full, then it will split into two nodes, distributing the keys and if it is empty, the key will insert into the same node.

# Deleting Data
To delete data from the B+ tree, you need to use the bplus_tree_delete function. Here's an example:

```
#include "bplus_tree.h"

int main() {
    // Create and initialize the B+ tree
    bplus_tree_t* tree = bplus_tree_create();

    // ...

    // Delete a record from the tree
    bplus_tree_delete(tree, key1);

    // ...

    return 0;
}
```
Replace key1 with the key of the record you want to delete. You can delete multiple records by calling the bplus_tree_delete function with different keys.
![del1](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/fa59a24e-d46f-4558-9701-55be2511f824)
➢ Firstly, the key which is to be deleted will be searched in the tree.

➢ Then using the remove key function, the key will be deleted from the data.

![del2](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/8ba42452-10b0-4f2e-b9f2-bf9c0532d2e5)

➢ The key entered will be deleted from the database, hence from the b+ tree.

# Searching Data
To search for data in the B+ tree, you need to use the bplus_tree_search function. Here's an example:

```
#include "bplus_tree.h"

int main() {
    // Create and initialize the B+ tree
    bplus_tree_t* tree = bplus_tree_create();

    // ...

    // Search for a record in the tree
    bplus_tree_node_t* result = bplus_tree_search(tree, key1);

    if (result != NULL) {
        // Record found, process the result
        // ...
    } else {
        // Record not found
        // ...
    }

    // ...

    return 0;
}
```
Replace key1 with the key you want to search for. The bplus_tree_search function returns a pointer to the node containing the record if it exists, or NULL if the record is not found.
![search1](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/6a567f47-0dbe-4b88-92a6-ba20abdb385a)
➢ Using binary search algorithm, the key will be searched where first it will check the root node.

➢ If the key is smaller than the root node, it will decrease its search to left tree otherwise it will point towards the right sided tree.

# Displaying Data
To display the data stored in the B+ tree, you can use the provided functions to traverse the tree and print the records. Here's an example:
```
#include "bplus_tree.h"

void display_records(bplus_tree_node_t* node) {
    if (node != NULL) {
        // Traverse the node and display the records
        // ...

        // Recursively traverse the child nodes
        for (int i = 0; i < node->num_children; i++) {
            display_records(node->children[i]);
        }
    }
}

int main() {
    // Create and initialize the B+ tree
    bplus_tree_t* tree = bplus_tree_create();

    // ...

    // Display all records in the tree
    display_records(tree->root);

    // ...

    return 0;
}
```
You can customize the display_records function to suit your needs and print the records in the desired format.


![display1](https://github.com/ShethKinar/Implementation-of-Database-using-B-plus-Tree/assets/137672635/de601ed9-87ce-4dce-9f51-ec4e02e34f2f)

