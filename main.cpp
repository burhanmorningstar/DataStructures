#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

struct TreeNode {
    int studentNumber;
    std::string firstName;
    std::string lastName;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int num, std::string fname, std::string lname)
        : studentNumber(num), firstName(fname), lastName(lname), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(root); }
    
    void insert(int num, std::string fname, std::string lname) {
        root = insert(root, num, fname, lname);
    }

    void remove(int num) {
        root = remove(root, num);
    }

    void inorder() const {
        inorder(root);
        std::cout << std::endl;
    }

    void preorder() const {
        preorder(root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorder(root);
        std::cout << std::endl;
    }

    void depthFirstSearch(int num) const {
        if (depthFirstSearch(root, num)) {
            std::cout << "Found student with number " << num << std::endl;
        } else {
            std::cout << "Student with number " << num << " not found" << std::endl;
        }
    }

    void breadthFirstSearch(int num) const {
        if (breadthFirstSearch(root, num)) {
            std::cout << "Found student with number " << num << std::endl;
        } else {
            std::cout << "Student with number " << num << " not found" << std::endl;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            saveToFile(root, file);
            file.close();
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int num;
            std::string fname, lname;
            ss >> num >> fname >> lname;
            insert(num, fname, lname);
        }
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int num, std::string fname, std::string lname) {
        if (!node) return new TreeNode(num, fname, lname);
        if (num < node->studentNumber)
            node->left = insert(node->left, num, fname, lname);
        else
            node->right = insert(node->right, num, fname, lname);
        return node;
    }

    TreeNode* remove(TreeNode* node, int num) {
        if (!node) return node;
        if (num < node->studentNumber) {
            node->left = remove(node->left, num);
        } else if (num > node->studentNumber) {
            node->right = remove(node->right, num);
        } else {
            if (!node->left) {
                TreeNode* rightNode = node->right;
                delete node;
                return rightNode;
            } else if (!node->right) {
                TreeNode* leftNode = node->left;
                delete node;
                return leftNode;
            }
            TreeNode* minNode = findMin(node->right);
            node->studentNumber = minNode->studentNumber;
            node->firstName = minNode->firstName;
            node->lastName = minNode->lastName;
            node->right = remove(node->right, minNode->studentNumber);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void inorder(TreeNode* node) const {
        if (node) {
            inorder(node->left);
            std::cout << node->studentNumber << " " << node->firstName << " " << node->lastName << std::endl;
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) const {
        if (node) {
            std::cout << node->studentNumber << " " << node->firstName << " " << node->lastName << std::endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) const {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->studentNumber << " " << node->firstName << " " << node->lastName << std::endl;
        }
    }

    bool depthFirstSearch(TreeNode* node, int num) const {
        std::stack<TreeNode*> stack;
        stack.push(node);
        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();
            if (current) {
                if (current->studentNumber == num) return true;
                stack.push(current->right);
                stack.push(current->left);
            }
        }
        return false;
    }

    bool breadthFirstSearch(TreeNode* node, int num) const {
        std::queue<TreeNode*> queue;
        queue.push(node);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current) {
                if (current->studentNumber == num) return true;
                queue.push(current->left);
                queue.push(current->right);
            }
        }
        return false;
    }

    void saveToFile(TreeNode* node, std::ofstream& file) const {
        if (node) {
            saveToFile(node->left, file);
            file << node->studentNumber << " " << node->firstName << " " << node->lastName << std::endl;
            saveToFile(node->right, file);
        }
    }

    void clear(TreeNode* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

void showMenu() {
    std::cout << "Asagidaki islemlerden birini seciniz...\n"
              << "Arama yapmak icin: A\n"
              << "Listeye ekrana yazdirmak icin: L\n"
              << "Ogrenci silmek icin: S\n"
              << "Dosyaya yazmak icin: Y\n"
              << "Cikis icin: C\n";
}

void showTraversalMenu() {
    std::cout << "Preorder listeleme yapmak icin: R\n"
              << "Inorder listeleme yapmak icin: I\n"
              << "Postorder listeleme yapmak icin: O\n";
}

void showFileMenu() {
    std::cout << "Hangi dosya icin islem yapmak istiyorsunuz?\n"
              << "data1.txt icin: 1\n"
              << "data2.txt icin: 2\n"
              << "data3.txt icin: 3\n";
}

void loadStudentData(BinaryTree trees[]) {
    std::ifstream file1("data1.txt");
    std::ifstream file2("data2.txt");
    std::ifstream file3("data3.txt");

    std::string line;
    while (std::getline(file1, line)) {
        std::stringstream ss(line);
        int num;
        std::string fname, lname;
        ss >> num >> fname >> lname;
        trees[0].insert(num, fname, lname);
    }

    while (std::getline(file2, line)) {
        std::stringstream ss(line);
        int num;
        std::string fname, lname;
        ss >> num >> fname >> lname;
        trees[1].insert(num, fname, lname);
    }

    while (std::getline(file3, line)) {
        std::stringstream ss(line);
        int num;
        std::string fname, lname;
        ss >> num >> fname >> lname;
        trees[2].insert(num, fname, lname);
    }
}

int main() {
    BinaryTree trees[3];
    loadStudentData(trees);

    char choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 'C') break;

        int fileChoice;
        if (choice != 'Y') {
            showFileMenu();
            std::cin >> fileChoice;
            if (fileChoice < 1 || fileChoice > 3) continue;
        }

        switch (choice) {
            case 'A': {
                int searchType, studentNumber;
                std::cout << "Derinlik oncelikli arama icin: 1\n"
                          << "Genislik oncelikli arama icin: 2\n";
                std::cin >> searchType;
                std::cout << "Ogrenci numarasi giriniz: ";
                std::cin >> studentNumber;
                if (searchType == 1) {
                    trees[fileChoice - 1].depthFirstSearch(studentNumber);
                } else if (searchType == 2) {
                    trees[fileChoice - 1].breadthFirstSearch(studentNumber);
                }
                break;
            }
            case 'L': {
                showTraversalMenu();
                char traversalChoice;
                std::cin >> traversalChoice;
                switch (traversalChoice) {
                    case 'R':
                        trees[fileChoice - 1].preorder();
                        break;
                    case 'I':
                        trees[fileChoice - 1].inorder();
                        break;
                    case 'O':
                        trees[fileChoice - 1].postorder();
                        break;
                }
                break;
            }
            case 'S': {
                int studentNumber;
                std::cout << "Silmek istediginiz ogrenci numarasini giriniz: ";
                std::cin >> studentNumber;
                trees[fileChoice - 1].remove(studentNumber);
                break;
            }
            case 'Y': {
                std::cout << "Dosya yazilacak, lutfen bekleyiniz...\n";
                trees[0].saveToFile("output1.txt");
                trees[1].saveToFile("output2.txt");
                trees[2].saveToFile("output3.txt");
                std::cout << "Dosyalar yazildi.\n";
                break;
            }
        }
    }

    return 0;
}
