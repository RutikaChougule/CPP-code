#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode* left, *right;
    MinHeapNode(char data, int freq){
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(struct MinHeapNode* root, string str){
    if(root == nullptr){
        return;
    }
    if(root->data != '$'){
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare{
    bool operator()(MinHeapNode* a, MinHeapNode* b){
        return (a->freq > b->freq);
    }
};

void HuffmanCode() {
    int size;
    cout << "Enter the number of characters: ";
    cin >> size;
    char data[size];
    int freq[size];
    
    for (int i = 0; i < size; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> data[i];
        cout << "Enter frequency for character " << data[i] << ": ";
        cin >> freq[i];
    }
    
    struct MinHeapNode *left, *right, *temp;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for(int i = 0; i < size; i++){
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    
    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    
    cout << "Huffman Codes:" << endl;
    printCodes(minHeap.top(), "");
}

int main(){
    int choice;
    
    while (true) {
        cout << "Huffman Encoding Menu" << endl;
        cout << "1. Encode a Message" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                HuffmanCode();
                break;
            case 2:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
}
}
}