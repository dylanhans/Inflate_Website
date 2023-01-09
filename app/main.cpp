#include "crow.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "User.cpp"
#include "productData.cpp"

using namespace crow;
using namespace crow::mustache;
using namespace std;

void sendFile(response &res, string filename, string contentType){
  ifstream in("./assets/" + filename, ifstream::in);
  if(in){
    ostringstream contents;
    contents << in.rdbuf();
    in.close();
    res.set_header("Content-Type", contentType);
    res.write(contents.str());
  } else {
    res.code = 404;
    res.write("Not found");
  }
  res.end();
}


void sendStyle(response &res, string filename){
  sendFile(res, "css/" + filename, "text/css");
}

int main() {
  crow::SimpleApp app;
  crow::mustache::set_base(".");
  std::unordered_map<std::string, std::vector<std::string>> userFavourites;
  std::unordered_map<std::string, int> bestPriceMap;
  std::unordered_map<std::string, User> users;
  std::vector<productData> products;

  CROW_ROUTE(app, "/")([](){
    auto page= crow::mustache::load("index.html");
    return page.render();
  });

  CROW_ROUTE(app, "/css/<string>")([](const request &req, response &res, string filename){
    sendStyle(res, filename);
  });


  CROW_ROUTE(app, "/favourites/<string>")([&userFavourites](std::string name){
    if(userFavourites.find(name)!= userFavourites.end()){
      crow::json::wvalue products;
      size_t i;
      for (i = 0; i < userFavourites[name].size(); ++i) {
          products[i] = userFavourites[name].at(i);
      }
      return crow::response(std::move(products));
      }
      return crow::response("Not Found");
  });

  CROW_ROUTE(app, "/addFavourites/<string>/<string>")([&userFavourites](std::string name, std::string product){
      userFavourites[name].push_back(product);
      return crow::response("Successfully saved product to user favourites");
  });

  CROW_ROUTE(app, "/addUser/<string>/<string>/<string>/<string>")([&users](std::string firstName, std::string lastName, std::string email, std::string password){
      users[email] = User(firstName, lastName, email, password);
      return crow::response("Successfully saved user");
  });

  CROW_ROUTE(app, "/addProduct/<string>/<string>/<string>")([&products](std::string productType, std::string productPrice, std::string productName){
      products.emplace_back(productData(productType, productPrice, productName));
      return crow::response("Successfully saved product");
  });

  CROW_ROUTE(app, "/getProducts/<string>")([&products](std::string prefix){
    // vector<productData> searches = {};
    crow::json::wvalue searches;
    int count = 0;
    for (auto product: products){
      if (product.getProductName().find(prefix) != -1) {
        searches[count] = product;
        count++;
      }
    }
      return crow::response(std::move(searches));
  });

  CROW_ROUTE(app, "/authenticateUser/<string>/<string>")([&users](std::string email, std::string password){
      if(users.find(email) == users.end()){
          return crow::response("User not found");
        }
        return crow::response(std::to_string((users[email]).getPassword() == password));
  });


  CROW_ROUTE(app, "/getBestPrice/<string>")([&bestPriceMap](std::string product){
    if(bestPriceMap.find(product) == bestPriceMap.end()){
      return crow::response("Product not found");
      }
      return crow::response(std::to_string(bestPriceMap[product]));
  });

  CROW_ROUTE(app, "/updateBestPrice/<string>/<int>")([&bestPriceMap](std::string product, int price){
    if(bestPriceMap.find(product) == bestPriceMap.end()){
      bestPriceMap[product] = price;
      } else {
        bestPriceMap[product] = std::max(bestPriceMap[product], price);
      }
      return crow::response("Updated price successfully");
  });

  app.port(18080).run();
}