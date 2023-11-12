#include <iostream>
#include <conio.h>
#include <sstream>
#include <unistd.h>
#include <algorithm>
using namespace std;

char pilihan;
int key, data;
	
class Node{
	public:
		int key;
		string data;
		Node* next;
		
	Node(){
		key = 0;
		data;
		next = NULL;
	}
	
	Node(int k, string d){
		key = k;
		data = d;
		next = NULL;
	}
};

class Stack{
	public:
		Node* top;
	
	Stack(){
		top = NULL;
	}
	
	bool NodeExists(Node * var){
		Node*temp = top;
		bool exist = false;
		while(temp != NULL){
			if(temp->key == var->key){
				exist =true;
				break;
			}
			temp = temp->next;
		}
		return exist;
	}
	
	bool checker(){
		if(top == NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	void push(Node* var){
		if(NodeExists(var)){
			cout << "Node sudah ada dengan key value ini. Masukkan key value yang berbeda" << endl;	
		}
		else if(top == NULL){
			top = var;
			cout << "Node berhasil di push ke dalam stack" << endl;
		}
		else{
			Node*temp = top;
			top = var;
			var->next = temp;
			cout << "Buku berhasil di masukan ke dalam Tumpukan" << endl;
		}
	}
	
	Node* pop(){
		Node* temp = NULL;
		if(checker()){
			cout << "Tumpukan Kosong" << endl;
			return temp;
		}
		else{
			temp = top;
			top = top->next;
			return temp;
		}
	}
	
	Node* peek(){
		
		Node* temp = NULL;
		if(checker()){
			cout << "Tumpukan Kosong" << endl;
			return temp;
		}
		else{
			return top;
		}
	}
	
	int length(){
		int length = 0;
		Node* temp = top;
		while(temp != NULL){
			length = length+1;
			temp = temp->next;	
		}
		return length;
	}
	
	void display(){
	    cout << "ISI DARI STACK (TUMPUKAN) :" << endl;
     	cout << "[ID|JENIS BUKU" << "\t]" << "->" << endl;
	    Node * temp = top;
	    while (temp != NULL){
	      	cout << "[" << temp->key << " |" << temp -> data << "\t]" << "->" << endl;
	        temp = temp -> next;
	    }
	    cout << endl;
  	}

};

void freeze(){
	system("pause");
}

void clear(){
	system("cls");
}

void garis(){
	for(int i = 0; i < 120; i++){
		cout << "=";
	}
	cout << endl;
}

int konversi(string a){
	int b;
	stringstream c(a);
	c >> b;
	return b;
}

void menu_utama(){
	garis();
	cout << "PILIH MENU" << endl;
	garis();
	cout << "1. Tambahkan Buku ke Tumpukan" << endl;
	cout << "2. Kembalikan Buku dari Tumpukan" << endl;
	cout << "3. Banyak nya Buku pada Tumpukan" << endl;
	cout << "4. Buku Teratas pada Tumpukan" << endl;
	cout << "5. Tampilkan Isi Tumpukan" << endl;
	cout << "6. Tampilkan Daftar Nama " << endl;
	cout << "0. Keluar" << endl;
	garis();
}


int main(){
	Stack tumpukan;
	int key, data, konversi_1, len;
	string title, identifier, id, pass;
	string fullname, newpass;
	char buku,gak_punya;
	bool flag = true;
	string id_store[] = {"Catur Krida Cahya Laksana", "Niken Presna Elvares", "Nazar Doang", "Ahmad Sudarsono", "Muhammad Rezky"};
	string pass_store[] = {"11111","22222","33333","44444","55555"};
	
	start : 
	do{
		clear();
		garis();
		cout << "\nMasukkan ID   : "; getline(cin, id);
		cout << "\nMasukkan PASS : "; getline(cin, pass);
		garis();
		int pjg = sizeof(id_store)/sizeof(id_store[0]);
		for(int i = 0; i < pjg; i++){
			if(id_store[i] == id and pass_store[i] == pass){
			do{
			
				clear();
				menu_utama();
				cout << "Masukkan Pilihan : "; 
				pilihan = getch();
				Node* x = new Node();
				switch(pilihan){						
					case '0':
						flag = false;
						goto start;
						break;
					case '1':
						clear();
						garis();
						cout << "List Buku Yang Tersedia " << endl;
						garis();
						cout << "1. Buku Matematika" << endl;
						cout << "2. Buku Fisika" << endl;
						cout << "3. Buku Kimia" << endl;
						cout << "4. Buku Biologi" << endl; 
						cout << "5. Buku Bahasa Inggris" << endl;
						cout << "6. Buku Bahasa Indonesia" << endl;
						garis();
						cout << "Masukkan Pilihan : ";
		 
						buku = getch();
						if(buku == '1'){
							title = "Matematika";
							identifier = "5";
						}
						else if(buku == '2'){
							title = "Fisika";
							identifier = "2";
						}
						else if(buku == '3'){
							title = "Kimia";
							identifier = "1";
						}
						else if(buku == '4'){
							title = "Biologi";
							identifier = "4";
						}
						else if(buku == '5'){
							title = "Bahasa Inggris";
							identifier = "3";
						}
						else if(buku == '6'){
							title = "Bahasa Indonesia";
							identifier = "6";
						}
						else{
							clear();
							garis();
							cout << "Maaf, Pilihan Tidak Tersedia" << endl;
							garis();
							flag = true;
						}
						system("cls");
						garis();
						konversi_1 = konversi(identifier);
						x->data = title;
						x->key  = konversi_1;
						tumpukan.push(x);
		///				garis();
		//				cout << "Buku " + title << " Berhasil Ditambahkan ke dalam Keranjang "<< endl;
						garis();
						freeze();
						break;
					case '2':
						clear();
						garis();
					    cout << "KEMBALIKAN BUKU DARI TUMPUKAN" << endl;
					    garis();
					    if(tumpukan.checker()){
		        			cout << "Stacknya Kosong" << endl;
		      			}
						else{
						    x = tumpukan.pop();
						    cout << "BUKU TERATAS DENGAN DATA : [" << x -> key << "|" << x -> data << "]" << endl;
						    delete x;
						    cout << "Berhasil Dikembalikan Dari Tumpukan" << endl;
		      			}
					    garis();
					    freeze();
						break;
					case '3':
						clear();
						garis();
						cout << "Fungsi Menghitung Banyaknya Data Pada Stack " << endl;
						garis();
		      			cout << "Jumlah Data pada Stack adalah : " << tumpukan.length() << endl;
		      			freeze();
		      			break;
		 			case '4':
		 				clear();
		 				garis();
		 				cout << "Fungsi Untuk Mengetahui Data Teratas Pada Stack" << endl;
		 				garis();
		 				if(tumpukan.checker()){
		        			cout << "Stacknya Kosong" << endl;
		      			}
						else{
		        			x = tumpukan.peek();
						    cout << "BUKU TERATAS DENGAN DATA : [" << x -> key << "|" << x -> data << "]" << endl;
		      			}
		      			freeze();
		      			break;
					case '5':
						clear();
						garis();
						cout << "Tampilkan Isi Tumpukan" << endl;
						garis();
						tumpukan.display();
						cout << endl;
						freeze();
						break;				
					case '6':
						clear();
//						int len = sizeof(id_store)/sizeof(id_store[0]);
						sort(id_store, id_store+pjg);
						garis();
						cout << "Daftar Nama Pengguna (Ascending): " << endl;
						garis();
						for(int i = 0; i < pjg; ++i){
							cout << "[" << i+1 << "]\t" << id_store[i] << endl;
						}
						freeze();
						break;
					default:
						clear();
						garis();
						cout << "Pilihan Tidak Tersedia " << endl;
						garis();
						freeze();
						break;
					}
				}while(pilihan != '0');
				break;
			}

		}

	
		do{//2
			clear();
			garis();
			cout << "ID dan PASS tidak sesuai" << endl;
			garis();
			cout << "Apakah anda memiliki Akun ?\t[tekan Y untuk Ya]\t[tekan T untuk Tidak]" << endl;
			gak_punya = getch();
			switch(gak_punya){//3
				case 'y':
					clear();
					garis();
					cout << "Anda akan dialihkan ke laman login karena anda memiliki akun" << endl;
					garis();
					cout << endl;
					for(int i = 0; i < 10; i++){//4
						cout << i+1 << "  ";
						sleep(1); 	
					}//4
					goto start;
					break;
				case 't':
					clear();
					garis();
					cout << "HUBUNGI CONTACT PERSON BERIKUT UNTUK MEMBUAT AKUN : " << endl;
					cout << "+62 852-5842-5743 [CATUR]" << endl;
					garis();
					freeze();
					goto start;
					break;
				default:
					clear();
					garis();
					cout << "Input tidak tersedia" << endl;
					garis();
					freeze();
					break;
			}//3
		}while(gak_punya != 'y' or gak_punya != 'Y' or gak_punya != 'T' or gak_punya != 't');//2
	


	}while(flag == true);
	return 0;
};
