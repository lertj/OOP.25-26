#include <iostream>
using namespace std;

enum ProductType {
	DAIRY,FRUIT,VEGETABLE, BAKERY, DRINKS
};
class Product {
private:
	const int id = 0;
	string name = "";
	int* priceHistory = nullptr;
	int noPrices = 0;
	bool isExpired = false;
	ProductType type = FRUIT;
	static int NO_PRODUCTS;
public:
	static const int MIN_PRICE;
	Product(): id(NO_PRODUCTS), name("-"), priceHistory(nullptr), isExpired(false){
		NO_PRODUCTS++;
	}
	Product(string _name) : id(NO_PRODUCTS),name(_name){
		NO_PRODUCTS++;
	}
	Product(string _name, int* priceHistory, int _noPrices) : id(NO_PRODUCTS), name(_name), noPrices(_noPrices) {
		this->priceHistory = new int[_noPrices];
		for (int i = 0; i < this->noPrices; i++) {
			this->priceHistory[i] = priceHistory[i];
		}
		NO_PRODUCTS++;
	}
	Product(string _name, int* priceHistory, int _noPrices, ProductType type) : id(NO_PRODUCTS), name(_name), noPrices(_noPrices), type(type) {
		this->priceHistory = new int[_noPrices];
		for (int i = 0; i < this->noPrices; i++) {
			this->priceHistory[i] = priceHistory[i];
		}
		NO_PRODUCTS++;
	}
	void setPrice(int* PriceHistory, int noPrices) {
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
			this->priceHistory = nullptr;
		}
		this->priceHistory = new int[noPrices];
		for (int i = 0; i < noPrices; i++) {
			if (PriceHistory[i] < MIN_PRICE)
				throw "Invalid price";
			this->priceHistory[i] = PriceHistory[i];
		}
		this->noPrices = noPrices;
	}
	void display() {
		cout << endl << "id: " << this->id;
		cout << endl << "name: " << this->name;
		cout << endl << this->noPrices << " prices: ";
		for (int i = 0; i < this->noPrices; i++) {
			cout << " " << this->priceHistory[i];
		}
		cout <<endl<<( (isExpired == 0) ? "Not expired" : "expired");
		cout << endl << "Product type: ";
		switch(this->type){
		case DRINKS:
			cout << "drinks";
			break;
		case BAKERY:
			cout << "bakery";
			break;
		case DAIRY:
			cout << "dairy";
			break;
		case VEGETABLE:
			cout << "vegetable";
			break;
		case FRUIT:
			cout << "fruit";
			break;
		}
	}

	~Product() {
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
			this->priceHistory = nullptr;
		}
		NO_PRODUCTS--;
	}
};

const int Product::MIN_PRICE = 1;
int Product::NO_PRODUCTS = 1;
int main() {
	/*Product::MIN_PRICE = 999;//no longer works*/
	Product product1;
	product1.display();
	Product product2("tea", new int[5] {21, 12, 31, 44, 55}, 5);
	product2.display();
	Product product3("tea", new int[5] {21, 12, 31, 44, 55}, 5, DRINKS);
	product3.setPrice(new int[3] {5, 6, 8}, 3);
	product3.display();

	Product* productP = new Product("bread", new int[2] {5, 7}, 2, BAKERY);
	productP->display();

	delete productP;

	productP = new Product[5];

	/*for (int i = 0; i < 5; i++) {
		productP[i] = Product("bread", new int[2] {5, 7}, 2, BAKERY)
	}*/
}