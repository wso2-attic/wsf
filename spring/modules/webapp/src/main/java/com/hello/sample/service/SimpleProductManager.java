package com.hello.sample.service;

import java.util.List;

public class SimpleProductManager implements ProductManager {

    private List<Product> products;

    public List<Product> getProducts() {
        return products;
    }

    public Product[] getAllProducts() {
        Product[] allProducts = new Product[this.products.size()];
        for (int i = 0; i < this.products.size(); i++) {
            allProducts[i] = this.products.get(i);
        }
        return allProducts;
    }

    public void increasePrice(int percentage) {
        if (products != null) {
            for (Product product : products) {
                double newPrice = product.getPrice().doubleValue() *
                        (100 + percentage) / 100;
                product.setPrice(newPrice);
            }
        }
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

}