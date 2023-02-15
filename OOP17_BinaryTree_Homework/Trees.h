#pragma once
#include <iostream>
using namespace std;

struct Car {
	char Number[9];
	int count_offenses = 0;
	struct Offenses {
		char offense[120];
	};
	Offenses* offenses = new Offenses[10];
	Car* left, * right, * parent;
};

class Trees {
	Car* root;
public:
	Trees() { root = nullptr; }
	~Trees() { delete_(); }

	void print(Car* node);
	void find(Car* node, char* key);
	Car* min_(Car* node);
	Car* max_(Car* node);
	Car* next(Car* node);
	Car* previous(Car* node);
	void insert(Car* node);
	void delete_(Car* node = 0);
	Car* get_root();
	void print_all(Car* temp);
};

void Trees::print_all(Car* temp) {
	if (temp == nullptr)
		temp = min_(root);

	Car* temp_2 = min_(temp);
	if (temp_2->left != nullptr) {
		print(temp_2->left);
	}
	if (temp_2->right != nullptr) {
		if (temp_2->right->right != nullptr && temp_2->left->left == nullptr)
			print_all(temp_2->right);
		else if (temp_2->left->left != nullptr)
			print_all(temp_2->left);
		print(temp_2->right);
	}
	temp_2 = temp_2->parent;
}



void Trees::print(Car* node) {
	if (node != nullptr) {
		print(node->left);
		cout << "Car number - " << node->Number << endl;
		cout << "Offenses:\n";
		for (int i = 0; i < node->count_offenses; i++) {
			cout << node->offenses[i].offense << endl;
		}
		print(node->right);
	}
}

void Trees::find(Car* node, char* k) {
	while (node != nullptr && strcmp(k,node->Number) != 0) {
		if (strcmp(k, node->Number) < 0) node = node->left;
		else node = node->right;
	}
	print(node);
}

Car* Trees::min_(Car* node) {
	if (node != nullptr)
		while (node->left != nullptr)
			node = node->left;
	return node;
}

Car* Trees::max_(Car* node) {
	if (node != nullptr)
		while (node->right != nullptr)
			node = node->right;
	return node;
}

Car* Trees::next(Car* node) {
	Car* y = nullptr;
	if (node != nullptr) {
		if (node->right != nullptr) return min_(node->right);

		y = node->parent;
		while (y != 0 && node == y->right)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}

Car* Trees::previous(Car* node) {
	Car* y = nullptr;
	if (node != nullptr) {
		if (node->left != nullptr) return min_(node->left);

		y = node->parent;
		while (y != 0 && node == y->left)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}

Car* Trees::get_root() { return root; }

void Trees::insert(Car* node) {
	node->left = nullptr;
	node->right = nullptr;

	Car* y = nullptr;
	Car* z = root;

	while (z != nullptr) {
		y = z;
		if (node->Number < z->Number) z = z->left;
		else z = z->right;
	}
	node->parent = y;
	if (y == nullptr) root = node;
	else if (node->Number < y->Number) y->left = node;
	else y->right = node;
}
void Trees::delete_(Car* node) {
	if (node != nullptr) {
		Car* y, * z;

		if (node->left == nullptr || node->right == nullptr) y = node;
		else y = next(node);

		if (y->left != 0) z = y->left;
		else z = y->right;

		if (z != nullptr) z->parent = y->parent;

		if (y->parent == nullptr) root = z;
		else if (y == y->parent->left) y->parent->left = z;
		else y->parent->right = z;

		if (y != node) {
			strcpy_s(node->Number, y->Number);
			node->count_offenses = y->count_offenses;
			node->offenses = y->offenses;
		}
		delete y;
	}
	else
		while (root != 0)
			delete_(root);
}