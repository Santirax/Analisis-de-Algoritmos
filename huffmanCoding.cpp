/*
    Developed by Erick Ignacio Santillan Zaragoza (Santirax)
    Implementacion de los codigos de Huffman
*/

#include <bits/stdc++.h> 
using namespace std; 
  
struct nodoHuffman { 
    
    char datos;
    long long frec;
    
    nodoHuffman *izq, *der; 
    
    nodoHuffman(char datos, long long frec){ 
        izq = der = nullptr; 
        this->datos = datos; 
        this->frec = frec; 
    } 
}; 
  

struct funcComparacion { 
  
    bool operator()(nodoHuffman* izq, nodoHuffman* der) { 
        return (izq->frec > der->frec); 
    } 
}; 
  
void imprimirCodigos(nodoHuffman* raiz, string cad) { 
  
    if (!raiz) 
        return; 
  
    if (raiz->datos != '$') 
        cout << raiz->datos << " -> " << cad << "\n"; 
  
    imprimirCodigos(raiz->izq, cad + "0"); 
    imprimirCodigos(raiz->der, cad + "1");
} 

void codigosHuffman(vector < pair<char, int> > char_frec) { 
    
    nodoHuffman *izq, *der, *top; 

    priority_queue<nodoHuffman*, vector<nodoHuffman*>, funcComparacion> heap_min; 
  
    for (int i = 0; i < char_frec.size(); ++i) 
        heap_min.push(new nodoHuffman(char_frec[i].first, char_frec[i].second)); 
    
    while (heap_min.size() != 1) { 
        
        izq = heap_min.top(); 
        heap_min.pop(); 
        
        der = heap_min.top(); 
        heap_min.pop(); 
        
        top = new nodoHuffman('$', izq->frec + der->frec); 
  
        top->izq = izq; 
        top->der = der; 
  
        heap_min.push(top); 
    } 
  
    imprimirCodigos(heap_min.top(), ""); 
} 

int main() { 
    
    vector < pair<char, int> > char_frec;
    
    char c = 'a';
    for(int i = 0; i < 7; i++, c++){
        char_frec.push_back ({c, random()%100});
    }
    
    for(auto [x, y]: char_frec){
        cout << x << " " << y << endl;
    }
    cout << endl;
    
    codigosHuffman(char_frec);
  
    return 0; 
} 
