// Davis Ha
// dha5536@csu.fullerton.edu

// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
public:
  // Create a product with a given code, name, and price.
  //
  // code is intended to be a UPC code (bar code) or PLU code in a
  // string.
  //
  // name may be any string.
  //
  // price is in units of dollars. It must be positive, or else this
  // function throws invalid_argument.
  Product(){
    throw logic_error("no default constructor implemented");
  }

  Product( string newCode, string newName, double newPrice ) {
     if(newPrice > 0){
      code = newCode;
      name = newName;
      price = newPrice;
      } else {
        throw invalid_argument("price is not positive");
      }
   }
  
  ~Product() {}

  // Accessors.
  const string& getCode() const { return code; }
  const string& getName() const { return name; }
  double getPrice() const { return price; }
  
private:
  string code, name;
  double price;
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
public:
  // Create a new catalog.
  //
  // maxProducts is the maximum number of products that can be
  // stored. It must be positive, or else this function throws
  // invalid_argument.
  Catalog(int newMaxProducts) {
    // TODO: implement this function properly(done)
    if(newMaxProducts > 0){
      maxProducts = newMaxProducts;
      numProducts = 0;
      vector<Product> catalogOfProducts;
    } else {
          throw invalid_argument("max products is not positive");
    }
  }
  
  ~Catalog() {
    // TODO: implement this function properly
  }

  // Accessors.
  int getMaxProducts() const { return maxProducts; }
  
  int getNumProducts() const { return numProducts; }

  // Return true when the catalog cannot fit any more products.
  bool isFull() const { 
      if ( numProducts < maxProducts){
        return false;
      } else {
        return true;
      }
   }

  // Add a new product to the catalog with a given code and name.
  //
  // code, name, and price have the same meaning as in a Product. If
  // price is invalid, throw invalid_argument.
  //
  // If this catalog is already full, throw overflow_error.
  //
  // Code must be different from all the product codes already in the
  // database. If it's not, throw invalid_argument.
  void addProduct(const string& code,
                  const string& name,
                  double price) {
    if ( price < 0 ){
      throw invalid_argument("Price is not positive");
    } else if ( numProducts >= maxProducts ){
      throw overflow_error("The catalog is full");
    } else {
      bool duplicate = false;

      for(int iter = 0; iter < catalogOfProducts.size(); iter++){
        if(catalogOfProducts[iter].getCode() == code){
         duplicate = true;
        }
      }

      if (!duplicate){
        Product newProduct(code, name, price);
        catalogOfProducts.push_back(newProduct);
        numProducts++;
      } else {
        throw invalid_argument("duplicate code found.");
      }
    }
  }

  // Find a product by its code.
  //
  // code is a product code.
  //
  // Returns a const reference to the product with the matching code.
  //
  // Throw invalid_argument if no product with that code exists
  // in the catalog.
  const Product& findCode(const string& code) const {
    // TODO: implement this function properly(done)
    for(int iter = 0; iter < catalogOfProducts.size(); iter++){
      if(catalogOfProducts[iter].getCode() == code){
        return catalogOfProducts[iter];
      }
    }

    throw invalid_argument("code does not exist in catalog");
  }

private:
  // TODO: add data members(done)
  int maxProducts, numProducts;
  vector<Product> catalogOfProducts;
};
