// ## Soal 3

// Kebalikan dari soal mencari nilai terkecil, kali ini 
// kamu diminta membuat fungsi untuk menemukan nilai terbesar 
// dalam sebuah Binary Search Tree (BST). Sesuai aturan BST, 
// nilai terbesar selalu berada di ujung paling kanan dari

// Lengkap kode berikut:

#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk mencari nilai terbesar dalam sebuah BST.
 * @param root Pointer ke node root dari tree.
 * @return Nilai integer terbesar. Mengembalikan -1 jika tree kosong.
 * @logic
 * 1. Cek jika tree kosong.
 * 2. Selama masih ada anak kanan (right child), terus telusuri ke kanan.
 * 3. Node paling kanan adalah node dengan nilai terbesar.
 */

int findMaxValue(Node* root) {
    if(root == nullptr){ // pada bagian ini apabila root kosong maka tidak ada nilai maksimum
        return -1;
    }
    Node* current = root; // sesuai dengan bst nilai kanan selalu lebih besar maka akan di cek bagian kanan sampai habis
    while(current -> right != nullptr){
        current = current -> right;
    }

    return current -> data;

}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}
